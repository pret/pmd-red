import collections.abc
import dataclasses
import os
import re
import struct
import subprocess
import tempfile
import typing

ROM_VADDR = 0x08000000
ROM_SIZE = 0x2000000


class FromStruct:
    def __init_subclass__(cls, /, spec):
        cls._struct = struct.Struct(spec)

    @classmethod
    def from_io(cls, file: typing.BinaryIO):
        return cls(*cls._struct.unpack(file.read(cls._struct.size)))

    @classmethod
    def iter_io(cls, file: typing.BinaryIO, max_size: int):
        for tup in cls._struct.iter_unpack(file.read(max_size)):
            yield cls(*tup)


@dataclasses.dataclass
class SiroHeader(FromStruct, spec="<4sLLL"):
    magic: bytes
    data_p: int
    unk8: int
    unkC: int


@dataclasses.dataclass
class EfbFileData(FromStruct, spec="<lLlLL"):
    frameCount: int
    frames: int
    tileCount: int
    tiles: int
    pal: int


@dataclasses.dataclass
class ax_pose(FromStruct, spec="<hBbHHH"):
    sprite: int
    unk2_unk0: int
    unk2_unk1: int
    flags1: int
    flags2: int
    flags3: int


@dataclasses.dataclass
class ax_anim(FromStruct, spec="<BBhhhhh"):
    frames: int
    unkFlags: int
    poseId: int
    offset_x: int
    offset_y: int
    shadow_x: int
    shadow_y: int


@dataclasses.dataclass
class ax_sprite(FromStruct, spec="<Ll"):
    gfx: int
    byteCount: int


PositionSets = collections.abc.Sequence[int]


@dataclasses.dataclass
class EfoFileData(FromStruct, spec="<LLLLLLLL"):
    poses: int
    animations: int
    animCount: int
    spriteData: int
    positions: int
    charData: int
    plttData: int
    charCount: int


T = typing.TypeVar("T", bound=FromStruct)


def get_siro_data(
    baserom: typing.BinaryIO, offset: int, typ: type[T]
) -> tuple[SiroHeader, T]:
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
    siro_header, effect_header = get_siro_data(baserom, offset, EfbFileData)

    addrs = {
        offset: siro_header,
        siro_header.data_p: effect_header,
        effect_header.frames: [],
    }
    addrs.pop(0, None)
    if effect_header.frameCount != 0 and effect_header.frames != 0:
        for i in range(effect_header.frameCount):
            baserom.seek(effect_header.frames + 4 * i - ROM_VADDR)
            ptr = int.from_bytes(baserom.read(4), "little")
            addrs[effect_header.frames].append(ptr)
            if ptr == 0:
                continue
            baserom.seek(ptr - ROM_VADDR)
            values = [int.from_bytes(baserom.read(2), "little") for _ in range(10)]
            binfilename = f"{dir}/{prefix}_{i:03d}.bin"
            with open(binfilename, "wb") as ofp:
                ofp.write(baserom.read(values[2] * values[3] * 2))
            values.append(binfilename)
            addrs[ptr] = values

    if effect_header.tileCount != 0 and effect_header.tiles != 0:
        baserom.seek(effect_header.tiles - ROM_VADDR)
        binfilename = f"{dir}/{prefix}.4bpp"
        with open(binfilename, "wb") as ofp:
            ofp.write(baserom.read(32 * (effect_header.tileCount + 1)))
        addrs[effect_header.tiles] = binfilename

    if effect_header.pal != 0:
        baserom.seek(effect_header.pal - ROM_VADDR)
        binfilename = f"{dir}/{prefix}.pmdpal"
        with open(binfilename, "wb") as ofp:
            ofp.write(baserom.read(0x400))
        addrs[effect_header.pal] = binfilename

    print('#include "global.h"', file=outfile)
    print('#include "decompress_sir.h"', file=outfile)
    print('#include "structs/axdata.h"', file=outfile)
    print(
        f"const struct EfbFileData gUnknown_{siro_header.data_p:X};",
        file=outfile,
    )
    for offset, value in sorted(addrs.items()):
        label = f"gUnknown_{offset:X}"
        if isinstance(value, SiroHeader):
            print(
                f'const SiroArchive {label} = {{ "{value.magic.decode()}", &gUnknown_{value.data_p:X} }};',
                file=outfile,
            )
        elif isinstance(value, EfbFileData):
            print(f"const struct EfbFileData {label} = {{", file=outfile)
            # print(f"    {value.unk0},", file=outfile)
            print(
                f"    ARRAY_COUNT(gUnknown_{value.frames:X}), // {value.frameCount}",
                file=outfile,
            )
            print(f"    gUnknown_{value.frames:X},", file=outfile)
            print(
                f"    sizeof(gUnknown_{value.tiles:X}) / 32 - 1, // {value.tileCount}",
                file=outfile,
            )
            print(f"    gUnknown_{value.tiles:X},", file=outfile)
            print(f"    gUnknown_{value.pal:X},", file=outfile)
            print("};", file=outfile)
        elif offset == effect_header.frames:
            print(f"const u16 *{label}[] = {{", file=outfile)
            for ptr in value:
                print(f"    gUnknown_{ptr:X},", file=outfile)
            print("};", file=outfile)
        elif isinstance(value, list):
            print(f"const u16 {label}[] = {{", file=outfile)
            print(f'    {", ".join(str(x) for x in value[:10])},', file=outfile)
            print(f'    INCBIN_U16("{value[10]}"),', file=outfile)
            print("};", file=outfile)
        elif isinstance(value, str):
            if offset == effect_header.tiles:
                incbin = "INCBIN_U32"
                typ = "const u32"
            elif offset == effect_header.pal:
                incbin = "INCBIN_U8"
                typ = "const RGB"
            else:
                raise ValueError("unrecognized data type")
            print(f'{typ} {label}[] = {incbin}("{value}");', file=outfile)
        else:
            raise ValueError("unrecognized data type")


def dump_efob(
    baserom: typing.BinaryIO, offset: int, outfile: typing.TextIO, dir: str, prefix: str
):
    siro_header, efo_file_data = get_siro_data(baserom, offset, EfoFileData)

    addrs = {
        offset: siro_header,
        siro_header.data_p: efo_file_data,
        efo_file_data.poses: [],
        efo_file_data.animations: [],
        efo_file_data.spriteData: [],
        efo_file_data.positions: [],
        efo_file_data.charData: [],
        efo_file_data.plttData: [],
    }
    addrs.pop(0, None)

    # Pose pointers are of arbitrary length
    # Pose arrays are of arbitrary length
    # Neither length is stored with the data
    # So instead I assume the pointers are in
    # the same order as the arrays, and that
    # they never overlap.
    # Animations always follow the poses.
    # Animations always consist of 8 cels
    # Strategy: work back to front
    if efo_file_data.animations != 0 and efo_file_data.animCount != 0:
        for i in range(efo_file_data.animCount):
            baserom.seek(efo_file_data.animations + 4 * i - ROM_VADDR)
            anim_ptr = int.from_bytes(baserom.read(4), "little")
            if anim_ptr == 0:
                continue
            addrs[efo_file_data.animations].append(anim_ptr)
            baserom.seek(anim_ptr - ROM_VADDR)
            anim_block = [int.from_bytes(baserom.read(4), "little") for _ in range(8)]
            addrs[anim_ptr] = anim_block
            for ptr in sorted(anim_block, reverse=True):
                if ptr == 0:
                    break
                if ptr in addrs:
                    continue
                baserom.seek(ptr - ROM_VADDR)
                array_end = next(x for x in sorted(addrs) if x > ptr)
                addrs[ptr] = list(ax_anim.iter_io(baserom, array_end - ptr))
    if efo_file_data.poses != 0:
        baserom.seek(efo_file_data.poses - ROM_VADDR)
        array_end = next(x for x in sorted(addrs) if x > efo_file_data.poses)
        pose_ptrs = [
            int.from_bytes(baserom.read(4), "little")
            for _ in range(efo_file_data.poses, array_end, 4)
        ]
        addrs[efo_file_data.poses] = pose_ptrs
        for ptr in sorted(pose_ptrs, reverse=True):
            if ptr == 0:
                break
            if ptr in addrs:
                continue
            baserom.seek(ptr - ROM_VADDR)
            array_end = next(x for x in sorted(addrs) if x > ptr)
            extra_ptr = None
            if (array_end - ptr) % ax_pose._struct.size:
                extra_ptr = array_end - 4
                array_end -= (array_end - ptr) % ax_pose._struct.size
            addrs[ptr] = list(ax_pose.iter_io(baserom, array_end - ptr))
            if extra_ptr:
                baserom.seek(extra_ptr - ROM_VADDR)
                addrs[ptr].append(int.from_bytes(baserom.read(4), "little"))
    if efo_file_data.spriteData != 0:
        raise ValueError(f"{prefix} spriteData unexpectedly not null")
    if efo_file_data.positions != 0:
        raise ValueError(f"{prefix} positions unexpectedly not null")
    if efo_file_data.charData != 0:
        baserom.seek(efo_file_data.charData - ROM_VADDR)
        binfilename = f"{dir}/{prefix}.4bpp"
        with open(binfilename, "wb") as ofp:
            ofp.write(baserom.read(32 * efo_file_data.charCount))
        addrs[efo_file_data.charData] = binfilename
    if efo_file_data.plttData != 0:
        baserom.seek(efo_file_data.plttData - ROM_VADDR)
        binfilename = f"{dir}/{prefix}.pmdpal"
        with open(binfilename, "wb") as ofp:
            ofp.write(baserom.read(64))
        addrs[efo_file_data.plttData] = binfilename

    print('#include "global.h"', file=outfile)
    print('#include "decompress_sir.h"', file=outfile)
    print('#include "structs/axdata.h"', file=outfile)
    print(
        f"const struct EfoFileData gUnknown_{siro_header.data_p:X};",
        file=outfile,
    )
    for offset, value in sorted(addrs.items()):
        label = f"gUnknown_{offset:X}"
        if isinstance(value, SiroHeader):
            print(
                f'const SiroArchive {label} = {{ "{value.magic.decode()}", &gUnknown_{value.data_p:X} }};',
                file=outfile,
            )
        elif isinstance(value, EfoFileData):
            print(f"const EfoFileData {label} = {{", file=outfile)
            print(f"    gUnknown_{value.poses:X},", file=outfile)
            print(f"    gUnknown_{value.animations:X},", file=outfile)
            print(
                f"    ARRAY_COUNT(gUnknown_{value.animations:X}), // {value.animCount}",
                file=outfile,
            )
            print(f"    NULL,", file=outfile)
            print(f"    NULL,", file=outfile)
            print(f"    gUnknown_{value.charData:X},", file=outfile)
            print(f"    gUnknown_{value.plttData:X},", file=outfile)
            print(
                f"    sizeof(gUnknown_{value.charData:X}) / 32, // {value.charCount}",
                file=outfile,
            )
            print("};", file=outfile)
        elif isinstance(value, list) and value:
            if isinstance(value[0], ax_pose):
                print(f"const ax_pose {label}[] = {{", file=outfile)
                for pose in value:
                    if isinstance(pose, int):
                        break
                    print(
                        f"    {{ {pose.sprite}, {{ {pose.unk2_unk0}, {pose.unk2_unk1} }}, {pose.flags1}, {pose.flags2}, {pose.flags3} }},",
                        file=outfile,
                    )
                print("};", file=outfile)
                if isinstance(value[-1], int):
                    padding_addr = offset + ax_pose._struct.size * (len(value) - 1)
                    if padding_addr & 3:
                        padding_addr = (padding_addr + 3) & ~3
                    print(
                        f"UNUSED const u32 gUnknown_{padding_addr:X} = {value[-1]};",
                        file=outfile,
                    )
            elif isinstance(value[0], ax_anim):
                print(f"const ax_anim {label}[] = {{", file=outfile)
                for anim in value:
                    print(
                        f"    {{ {anim.frames},   {anim.unkFlags},   {anim.poseId}, {{ {anim.offset_x}, {anim.offset_y} }}, {{ {anim.shadow_x}, {anim.shadow_y} }} }},",
                        file=outfile,
                    )
                print("};", file=outfile)
            elif isinstance(value[0], int) and value[0] in addrs:
                redirect = addrs[value[0]]
                if isinstance(redirect[0], ax_pose):
                    typ = "const ax_pose *"
                elif isinstance(redirect[0], ax_anim):
                    typ = "const ax_anim *"
                elif isinstance(redirect[0], int):
                    assert (
                        redirect[0] in addrs
                        and isinstance(addrs[redirect[0]], list)
                        and isinstance(addrs[redirect[0]][0], ax_anim)
                    )
                    typ = "const ax_anim *const *"
                else:
                    raise ValueError("unrecognized data type")
                print(f"{typ}{label}[] = {{", file=outfile)
                for x in value:
                    print(f"    gUnknown_{x:X},", file=outfile)
                print("};", file=outfile)
            else:
                raise ValueError("unrecognized data type")
        elif isinstance(value, str):
            if offset == efo_file_data.charData:
                typ = "const u32"
                incbin = "INCBIN_U32"
            elif offset == efo_file_data.plttData:
                typ = "const RGB"
                incbin = "INCBIN_U8"
            else:
                raise ValueError("unrecognized data type")
            print(f'{typ} {label}[] = {incbin}("{value}");', file=outfile)
        else:
            raise ValueError("unrecognized data type")


def dump_effect_sbin(
    baserom: typing.BinaryIO,
    offset: int,
    dir: str,
    prefix: str,
):
    os.makedirs(dir, exist_ok=True)

    try:
        if prefix.startswith("efbg"):
            with open(f"{dir}/{prefix}.h", "w") as outfile:
                dump_efbg(baserom, offset, outfile, dir, prefix)
        elif prefix.startswith("efob"):
            with open(f"{dir}/{prefix}.h", "w") as outfile:
                dump_efob(baserom, offset, outfile, dir, prefix)
    except Exception as e:
        raise ValueError(f"failed to process {prefix}") from e

    subprocess.check_call(
        [
            "tools/gbagfx/gbagfx",
            f"{dir}/{prefix}.pmdpal",
            f"{dir}/{prefix}.pal",
        ]
    )
    with tempfile.NamedTemporaryFile(suffix=".gbapal") as gbapal:
        subprocess.check_call(
            ["tools/gbagfx/gbagfx", f"{dir}/{prefix}.pal", gbapal.name]
        )
        png_args = [
            "tools/gbagfx/gbagfx",
            f"{dir}/{prefix}.4bpp",
            f"{dir}/{prefix}.png",
            "-palette",
            gbapal.name,
        ]
        if prefix.startswith("efob"):
            png_args.append("-object")
        else:
            assert gbapal.truncate(32) == 32
        subprocess.check_call(png_args)


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
