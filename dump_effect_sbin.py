import dataclasses
import os
import re
import struct
import typing

ROM_VADDR = 0x08000000
ROM_SIZE = 0x2000000


class FromStruct:
    def __init_subclass__(cls, /, spec):
        cls._struct = struct.Struct(spec)

    @classmethod
    def from_io(cls, file: typing.BinaryIO):
        return cls(*cls._struct.unpack(file.read(cls._struct.size)))


@dataclasses.dataclass
class SiroHeader(FromStruct, spec="<4sLLL"):
    magic: bytes
    data_p: int
    unk8: int
    unkC: int


@dataclasses.dataclass
class Struct_8009A7C(FromStruct, spec="<lLlLL"):
    unk0: int
    unk4: int
    unk8: int
    unkC: int
    unk10: int


@dataclasses.dataclass
class axmain(FromStruct, spec="<LLLLL"):
    poses: int
    animations: int
    animCount: int
    spriteData: int
    positions: int


def get_siro_data(baserom: typing.BinaryIO, offset: int, typ: type[FromStruct]):
    baserom.seek(offset - ROM_VADDR)
    siro_header = SiroHeader.from_io(baserom)
    assert siro_header.magic in {b"SIRO", b"SIR0"}, siro_header.magic
    baserom.seek(siro_header.data_p - ROM_VADDR)
    effect_header = typ.from_io(baserom)
    return siro_header, effect_header


def dump_efbg(
    baserom: typing.BinaryIO,
    offset: int,
    outfile: typing.TextIO,
    dir: str,
    prefix: str,
):
    siro_header, effect_header = get_siro_data(baserom, offset, Struct_8009A7C)

    addrs = {
        offset: siro_header,
        siro_header.data_p: effect_header,
        effect_header.unk4: [],
    }
    for i in range(effect_header.unk0):
        baserom.seek(effect_header.unk4 + 4 * i - ROM_VADDR)
        ptr = int.from_bytes(baserom.read(4), "little")
        if ptr < ROM_VADDR:
            print(siro_header)
        addrs[effect_header.unk4].append(ptr)
        baserom.seek(ptr - ROM_VADDR)
        values = [int.from_bytes(baserom.read(2), "little") for _ in range(10)]
        binfilename = f"{dir}/{prefix}_{i:03d}.bin"
        with open(binfilename, "wb") as ofp:
            ofp.write(baserom.read(values[2] * values[3] * 2))
        values.append(binfilename)
        addrs[ptr] = values

    baserom.seek(effect_header.unkC - ROM_VADDR)
    binfilename = f"{dir}/{prefix}_unkC.bin"
    with open(binfilename, "wb") as ofp:
        ofp.write(baserom.read(2 * effect_header.unk8))
    addrs[effect_header.unkC] = binfilename

    baserom.seek(effect_header.unk10 - ROM_VADDR)
    binfilename = f"{dir}/{prefix}_unk10.bin"
    with open(binfilename, "wb") as ofp:
        ofp.write(baserom.read(0x400))
    addrs[effect_header.unk10] = binfilename

    print('#include "global.h"', file=outfile)
    print('#include "decompress_sir.h"', file=outfile)
    print('#include "structs/str_8009A7C.h"', file=outfile)
    print(
        f"const struct Struct_8009A7C gUnknown_{siro_header.data_p:X};",
        file=outfile,
    )
    for offset, value in sorted(addrs.items()):
        label = f"gUnknown_{offset:X}"
        if isinstance(value, SiroHeader):
            print(
                f'const SiroArchive {label} = {{ "{value.magic.decode()}", &gUnknown_{value.data_p:X} }};',
                file=outfile,
            )
        elif isinstance(value, Struct_8009A7C):
            print(f"const struct Struct_8009A7C {label} = {{", file=outfile)
            # print(f"    {value.unk0},", file=outfile)
            print(f"    ARRAY_COUNT(gUnknown_{value.unk4:X}),", file=outfile)
            print(f"    gUnknown_{value.unk4:X},", file=outfile)
            print(f"    ARRAY_COUNT(gUnknown_{value.unkC:X}),", file=outfile)
            print(f"    gUnknown_{value.unkC:X},", file=outfile)
            print(f"    gUnknown_{value.unk10:X},", file=outfile)
            print("};", file=outfile)
        elif offset == effect_header.unk4:
            print(f"const u16 *{label}[] = {{", file=outfile)
            for ptr in value:
                print(f"    gUnknown_{ptr:X},", file=outfile)
            print("};", file=outfile)
        elif isinstance(value, list):
            print(f"const u16 {label}[] = {{", file=outfile)
            print(f'    {", ".join(str(x) for x in value[:10])},', file=outfile)
            print(f'    INCBIN_U16("{value[10]}"),', file=outfile)
            print("};", file=outfile)
        else:
            print(f'const u16 {label}[] = INCBIN_U16("{value}");', file=outfile)


def dump_efob(
    baserom: typing.BinaryIO, offset: int, outfile: typing.TextIO, dir: str, prefix: str
):
    return NotImplemented


def dump_effect_sbin(
    baserom: typing.BinaryIO,
    offset: int,
    dir: str,
    prefix: str,
):
    os.makedirs(dir, exist_ok=True)

    with open(f"{dir}/{prefix}.h", "w") as outfile:
        if prefix.startswith("efbg"):
            dump_efbg(baserom, offset, outfile, dir, prefix)
        elif prefix.startswith("efob"):
            dump_efob(baserom, offset, outfile, dir, prefix)


def main():
    pat = re.compile(r'\[\d+\] = \{ "(\w+)", &gUnknown_([0-9A-F]{7}), \},')
    addrs = {}
    with open("baserom.gba", "rb") as baserom, open("src/effect_files_table.c") as fp:
        for m in pat.finditer(fp.read()):
            prefix, offset = m.groups()
            offset = int(offset, 16)
            assert ROM_VADDR <= offset < ROM_VADDR + ROM_SIZE
            dump_effect_sbin(baserom, offset, "data/effects", prefix)
            addrs[offset] = f"data/effects/{prefix}.h"
    for offset, header in sorted(addrs.items()):
        print(f'#include "{header}"')


if __name__ == "__main__":
    main()
