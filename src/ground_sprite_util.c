#include "global.h"
#include "globaldata.h"
#include "ground_sprite_util.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "ground_sprite.h"
#include "ground_sprite_data.h"

void sub_80A75CC(struct UnkGroundSpriteStruct *ptr, s32 unused, s32 a2_, s32 a3)
{
    struct UnkGroundSpriteSubStructx48 sp;
    s32 a2 = (s16) a2_;
    const struct GroundObjectKind *objKind = &gGroundObjectKinds[a2];
    OpenedFile *file = NULL;

    sp.unk0 = objKind->unk0;
    sp.unk2 = objKind->unk2;
    if (objKind->fileName != 0) {
        file = OpenFile(objKind->fileName, &gOrnamentFileArchive);
        GetFileDataPtr(file, 0);
        sp.axmain = (axmain *) file->data;
    }
    else {
        sp.axmain = NULL;
    }
    sub_80A67CC(ptr, &sp, a3);
    ptr->unk54 = file;
    if (ptr->unk52 >= 0) {
        sub_80A6EFC(ptr, 0x800, 0);
    }
}

void sub_80A7658(struct UnkGroundSpriteStruct *ptr)
{
    sub_80A68A0(ptr);
}

void sub_80A7664(struct UnkGroundSpriteStruct *ptr, PixelPos *pixelPos, s32 a2)
{
    sub_80A7094(ptr, NULL, pixelPos, a2);
    sub_80A7310(ptr, pixelPos, NULL, a2);
}

// Identical to sub_80A75CC, except uses a different table.
void sub_80A7688(struct UnkGroundSpriteStruct *ptr, s32 unused, s32 a2_, s32 a3)
{
    struct UnkGroundSpriteSubStructx48 sp;
    s32 a2 = (s16) a2_;
    const struct GroundObjectKind *objKind = &gUnknown_8117E8C[a2];
    OpenedFile *file = NULL;

    sp.unk0 = objKind->unk0;
    sp.unk2 = objKind->unk2;
    if (objKind->fileName != 0) {
        file = OpenFile(objKind->fileName, &gOrnamentFileArchive);
        GetFileDataPtr(file, 0);
        sp.axmain = (axmain *) file->data;
    }
    else {
        sp.axmain = NULL;
    }
    sub_80A67CC(ptr, &sp, a3);
    ptr->unk54 = file;
    if (ptr->unk52 >= 0) {
        sub_80A6EFC(ptr, 0x800, 0);
    }
}

void sub_80A7714(struct UnkGroundSpriteStruct *ptr)
{
    sub_80A68A0(ptr);
}

void sub_80A7720(struct UnkGroundSpriteStruct *ptr, PixelPos *pixelPos, s32 a2)
{
    sub_80A7094(ptr, NULL, pixelPos, a2);
    sub_80A7310(ptr, pixelPos, NULL, a2);
}
