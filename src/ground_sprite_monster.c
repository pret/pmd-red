#include "global.h"
#include "globaldata.h"
#include "ground_sprite_monster.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "ground_sprite.h"
#include "sprite.h"
#include "pokemon.h"

extern s32 sub_800E700(s32);

void sub_80A7428(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 monsterId_, s32 a3)
{
    u8 name[12];
    OpenedFile *file;
    struct UnkGroundSpriteSubStructx48 spStruct;
    s32 a1 = (s16) a1_;
    // s16 memes strike again...
    s32 monsterId = (s16) monsterId_;
    s32 monsterIdS16 = (s16) monsterId;

    sprintf(name, "ax%03d", monsterIdS16);
    file = OpenFile(name, &gMonsterFileArchive);
    GetFileDataPtr(file, 0); // Unused return value
    spStruct.unk0 = GetBodySize(monsterId);
    if (monsterId == MONSTER_STATUE) {
        spStruct.unk2 = 0x122;
    }
    else {
        bool32 kecleonShop = (a1 == 71);
        spStruct.unk2 = GetPokemonOverworldPalette(monsterId, kecleonShop);
    }
    spStruct.axmain = (axmain *) file->data;
    sub_80A67CC(ptr, &spStruct, a3);
    ptr->unk54 = file;
    if (ptr->unk52 >= 0) {
        sub_80A6EFC(ptr, 0x300, 0);
    }
}

void sub_80A74E4(struct UnkGroundSpriteStruct *ptr)
{
    sub_80A68A0(ptr);
}

void sub_80A74F0(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_, s32 a3)
{
    s32 a1 = (s16) a1_;
    s32 a2 = (s8) a2_;

    if (a3 < 0) {
        if (a1 != 0x1C0) {
            a3 = sub_800E700(a1);
        }
        else {
            a3 = 0;
        }
    }

    sub_80A7040(ptr, a1, a2, a3);
}

void sub_80A7524(struct UnkGroundSpriteStruct *ptr, s32 monsterId_, PixelPos *pixelPosArg, s32 a3)
{
    PixelPos pixelPosSp;
    DungeonPos pos;

    s32 monsterId = (s16) monsterId_;
    if (sub_80A7094(ptr, &pixelPosSp, pixelPosArg, a3)) {
        if (ptr->unk5C != -1) {
            PixelPos pixelPosSp2;
            switch (ptr->unk60) {
                case 0:
                case 1:
                case 2:
                case 3:
                    sub_800569C(&pos, &ptr->axdata, ptr->unk60);
                    pixelPosSp2.x = pos.x;
                    pixelPosSp2.y = pos.y;
                    sub_80A7310(ptr, pixelPosArg, &pixelPosSp2, a3);
                    break;
                default:
                    sub_80A7310(ptr, pixelPosArg, NULL, a3);
                    break;
            }
        }

        if (ptr->flags_0x50 & 0x100) {
            DungeonPos shadowPos = {pixelPosSp.x, pixelPosSp.y};
            AddShadowSprite(monsterId, &shadowPos, &ptr->axdata);
        }
        sub_80A7310(ptr, pixelPosArg, NULL, a3);
    }
}

