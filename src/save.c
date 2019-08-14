#include "global.h"
#include "flash.h"
#include "memory.h"

struct UnkStruct_203B184 {
    u8 fill000[0x4C];
    u8 *unk04C;
    u32 unk050;
    u32 unk054;
    u32 unk058;
};

struct UnkStruct_sub_8011DAC {
    u8 fill000[0x4];
    u8 unk004[0x400];
    u8 fill404[0x10];
    u32 unk414;
    u32 unk418;
    u32 unk41C;
    u32 unk420;
    u32 unk424;
    u32 unk428;
    u8 fill42C[0x4];
    u32 unk430;
    u32 unk434;
    u32 unk438;
    u32 unk43C;
    u32 unk440;
    u32 unk444;
    u8 fill448[0x538C];
};

extern u32 gUnknown_202DE28;
extern u32 gUnknown_203B17C;
extern u32 gUnknown_203B180;
extern volatile struct UnkStruct_203B184 *gUnknown_203B184;

extern void* MemoryAlloc(u32 a, u32 b);
extern void MemoryFree(void* a);
extern void SetRngState(s32 state);
extern bool8 sub_8002718(u8 *a);
extern bool8 sub_800DAB0(u16, u8*, s32);
extern bool8 sub_800DAB4(u16, u8*, s32);
extern bool8 sub_800DAB8(void);
extern u32 sub_808EE9C(void* a, s32 b);
extern u32 sub_808F2B0(void* a, s32 b);
extern u32 sub_8091D14(void* a, s32 b);
extern u32 sub_809222C(void* a, s32 b);
extern u32 sub_80927F4(void* a, s32 b);
extern u32 sub_80954CC(void* a, s32 b);
extern u32 sub_8096FA0(void* a, s32 b);
extern u32 sub_8097D98(void* a, s32 b);

u32 sub_8011C1C(void)
{
    return gUnknown_203B17C;
}

void sub_8011C28(u32 in)
{
    gUnknown_203B17C = in;
}

u32 sub_8011C34(void)
{
    return gUnknown_202DE28;
}

void sub_8011C40(u32 in)
{
    gUnknown_202DE28 = in;
}

u32 sub_8011C4C(void)
{
    return gUnknown_203B180;
}

void CalculateChecksum(u8 *out, u32 size)
{
    u32 checksum = 0;
    s32 i = size / 4;
    if (i > 1)
    {
        u32 *ptr = (u32 *)&out[4];
        --i;
        do
            checksum += *ptr++;
        while (--i);
    }
    *(u32 *)out = checksum;
}

bool8 ValidateChecksum(u8 *in, u32 size)
{
    u32 checksum = 0;
    s32 i = size / 4;
    if (i > 1)
	{
        u32 *ptr = (u32 *)&in[4];
        --i;
        do
            checksum += *ptr++;
        while (--i);
	}
    if (*(u32 *)in != checksum)
        return TRUE;
    return FALSE;
}

void sub_8011CA8(u32 *out, s32 size)
{
    if (gUnknown_203B184 == NULL) {
        AGB_WARNING("A warning most likely went here.");
        *out += (size + 0xFFF) / 0x1000;
    } else {
        *out += (size + 0xFFF) / 0x1000;
    }
}

u32 WriteSaveSector(s32 *a, u8 *src, s32 size)
{
    u32 r1;
    s32 r6 = *a;
    sub_8011CA8(a, size);
    CalculateChecksum(src, size);
    if (gUnknown_203B184 == NULL) {
        r1 = WriteFlashData(r6, src, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB4(r6, src, size)) {
            r1 = 3;
        }
        else {
            r1 = 0;
        }
    }
    else {
        return 2;
    }
    if (r1 == 4) {
        return 1;
    }
    if (r1) {
        return 2;
    }
    return 0;
}

u32 ReadSaveSector(s32 *a, u8 *dest, s32 size)
{
    u32 r1;
    s32 r6 = *a;
    sub_8011CA8(a, size);
    if (gUnknown_203B184 == NULL) {
        r1 = ReadFlashData(r6, dest, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB0(r6, dest, size)) {
            r1 = 1;
        }
        else {
            r1 = 0;
        }
    }
    else {
        return 1;
    }
    if (r1) {
        return 1;
    }
    if (ValidateChecksum(dest, size)) {
        return 2;
    }
    return 0;    
}

bool8 sub_8011DA8(void)
{
    return TRUE;
}

u32 sub_8011DAC(u32 *a)
{
    struct UnkStruct_sub_8011DAC *r5 = MemoryAlloc(sizeof(struct UnkStruct_sub_8011DAC), 5);
    u8 *r4 = (u8*)r5->fill448;
    u32 r7 = ReadSaveSector(a, (u8*)r5, sizeof(struct UnkStruct_sub_8011DAC));
    u32 r1;
    if (r7)
    {
        r7 = ReadSaveSector(a, (u8*)r5, sizeof(struct UnkStruct_sub_8011DAC));
    }
    else
    {
        sub_8011CA8(a, sizeof(struct UnkStruct_sub_8011DAC));
    }
    if (!r7)
    {
        if (r5->unk414 != 0x5071412) {
            r7 = 4;
        }
    }
    if (!r7)
    {
        if (gUnknown_203B184 == NULL) {
            sub_8011C28(r5->unk41C);
            sub_8011C40(r5->unk418);
            SetRngState(r5->unk420);
        }
        else {
            gUnknown_203B184->unk054 = r5->unk41C;
            gUnknown_203B184->unk050 = r5->unk418;
            gUnknown_203B184->unk058 = r5->unk420;
        }
    }
    if (!r7)
    {
        if (gUnknown_203B184 == NULL) {
            if (!sub_8002718(r5->unk004)) {
                r7 = 4;
            }
        }
        else {                    
            MemoryCopy8(gUnknown_203B184->unk04C, r5->unk004, ARRAY_COUNT(r5->unk004));
        }
    }
    if (!r7)
    {
        r1 = sub_808EE9C(r4, 0x4650);
        if (r1 != r5->unk424) {
            r7 = 3;
        }
        r4 += 0x4650;
        r1 = sub_808F2B0(r4, 0x258);
        if (r1 != r5->unk428) {
            r7 = 3;
        }
        r4 += 0x258;
        r1 = sub_8091D14(r4, 0x1D8);
        if (r1 != r5->unk430) {
            r7 = 3;
        }
        r4 += 0x1d8;
        r1 = sub_809222C(r4, 0x10);
        if (r1 != r5->unk434) {
            r7 = 3;
        }
        r4 += 0x10;
        r1 = sub_80927F4(r4, 0x8);
        if (r1 != r5->unk438) {
            r7 = 3;
        }
        r4 += 0x8;
        r1 = sub_8097D98(r4, 0x100);
        if (r1 != r5->unk43C) {
            r7 = 3;
        }
        r4 += 0x100;
        r1 = sub_80954CC(r4, 0x594);
        if (r1 != r5->unk440) {
            r7 = 3;
        }
        r4 += 0x594;
        r1 = sub_8096FA0(r4, 0x221);
        if (r1 != r5->unk444) {
            r7 = 3;
        }
    }
    MemoryFree(r5);
    return r7;
}
