#ifndef GUARD_WONDER_MAIL_H
#define GUARD_WONDER_MAIL_H

#include "file_system.h"
#include "text.h"
#include "item.h"
#include "sub_8095228.h"

#define PASSWORD_BUFFER_SIZE 54

struct WonderMail
{
    /* 0x0 */ u8 mailType; // mail type
    /* 0x1 */ u8 missionType; // mission type
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 dungeon; // dungeon
    /* 0x5 */ u8 floor; // floor
    /* 0x8 */ u32 unk8;
    /* 0xC */ s16 clientSpecies; // client pokemon
    /* 0xE */ s16 targetSpecies; // target
    /* 0x10 */ u8 targetItem; // item to find/deliver
    /* 0x11 */ u8 rewardType; // reward type
    /* 0x12 */ u8 itemReward; // item reward
    /* 0x13 */ u8 friendAreaReward; // friend area
};


struct WonderMailStruct_203B2C0
{
    // size: 0x548
    u32 unk0;
    u32 state;
    u8 passwordBuffer[PASSWORD_BUFFER_SIZE];
    u8 unk3E;
    u32 unk40;
    u32 linkError;
    u16 unk48[232];
    u8 unk218;
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    struct UnkTextStruct2 unk35C[4];
    struct UnkTextStruct2 unk3BC[4];
    u32 unkfill; // unkStruct_41C?
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u8 padding3[0x534 - 0x430];
    u32 unk534;
    s32 unk538; // A7 << 3
    u32 unk53C;
    u32 unk540; // A8 << 4
    s16 unk544;

};

struct WonderMailStruct_203B2C4
{
    // size: 0x564
    u8 state;
    u32 unk4; // wonder mail link status??
    u8 passwordBuffer[PASSWORD_BUFFER_SIZE]; // Probably a buffer for entry
    u8 unk3E;
    u32 unk40;
    u32 linkError; // another link status
    u8 filler48[0x1B8 - 0x48];
    struct unkStruct_8095228 unk1B8;
    struct unkStruct_8095228 unk1E8;
    s8 unk218;
    u32 unk21C;
    u8 filler220[0x30C - 0x220];
    u32 unk30C;
    u8 filler310[0x35C - 0x310];
    struct UnkTextStruct2 unk35C[4];
    struct UnkTextStruct2 unk3BC[4];
    struct ItemSlot unk41C;
    /* 0x420 */ struct OpenedFile *faceFile;
    /* 0x424 */ u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u32 unk430;
    u8 formattedString[0x100];
    s32 wonderMailMethod;
    u32 wonderMailMode;
    u8 unk53C[0xA];
    u32 unk548;
    u32 unk54C;
    u16 unk550;
    u8 unk552;
    u8 unk553;
    u32 unk554;
    u8 unk558;
    u8 unk559;
    u8 unk55A;
    u8 unk55B;
    u8 unk55C;
    u8 fill55C[0x560 - 0x55D];
    u32 unk560;
};

void sub_8028B04(u32 r0);

enum WonderMailMode {
    WONDER_MAIL_MODE_SEND = 1,
    WONDER_MAIL_MODE_RECEIVE = 2,
};

enum WonderMailMethod {
   WONDER_MAIL_GAME_LINK = 3,
   WONDER_MAIL_PASSWORD = 5, 
};

enum WonderMailTypes {
  WONDER_MAIL_TYPE_SOS = 1,
  WONDER_MAIL_TYPE_AOK = 4,
  WONDER_MAIL_TYPE_THANK_YOU = 5,
  WONDER_MAIL_TYPE_WONDER = 5,
};



#endif
