#include "global.h"
#include "constants/communication_error_codes.h"
#include "save.h"
#include "pokemon.h"
#include "file_system.h"
#include "item.h"
#include "input.h"
#include "wonder_mail.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "team_inventory.h"
#include "rescue_password_menu.h"

extern struct WonderMailStruct_203B2C0 *gUnknown_203B2C0;

extern u32 sub_80144A4(s32 *r0);
extern void sub_8011C28(u32);
extern void sub_8095240(u8);

extern void sub_809927C(u8);
extern bool8 HasNoWonderMailType(u32);
extern u32 sub_8031050();
extern void sub_80310B4();
extern u32 sub_8095350();
extern u8 sub_80A2824(u8);

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern s32 FindOpenMailSlot(void);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void nullsub_130(void);
extern void sub_8028348(void);
extern void sub_803084C();
extern u32 sub_8030768(u32);
extern s8 sub_80307EC();
extern void sub_8030D40(u8, u32);
extern u8 sub_8012FD8(struct MenuStruct *r0);
extern void sub_8030810(u32);
extern void sub_8035CC0(struct UnkTextStruct2 *r0, u32);
extern void sub_8035CF4(struct MenuStruct *r0, u32, u32);
extern u32 sub_8030DA0(void);
extern void sub_8030DE4(void);
extern void sub_803092C(void);

extern u32 sub_80154F0();
extern u32 sub_8039068(u32, u8 *r1, struct unkStruct_203B480 *r0);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, void *r5, u32);
extern void sub_8095274(u32);
extern void sub_80155F0();
extern void sub_80951BC(struct unkStruct_203B480 *r0);
extern void sub_8013114(struct MenuStruct *r0, s32 *r1);
extern void sub_8023C60();
extern u32 sub_8023A94(u32);
extern void sub_8024458(s16, u32);
extern u16 sub_8023B44();
extern void sub_8023B7C(u32);
extern u32 sub_80244E4();
extern void sub_802452C();
extern void sub_802453C();
extern u8 sub_8024108(u32);
extern u32 sub_8031DCC();
extern void sub_8031E10();
extern void sub_8031E00();
extern s32 sub_8001658(u32, u32);
extern u8 sub_8099B94();
extern void sub_8099A5C(u32, u32, u32*);
extern void sub_8099AFC(u32, u32, u32*);
extern void sub_8099690(u32);
extern void sub_8031E10(void);
extern void sub_803084C(void);
extern void sub_8030DE4();
extern void nullsub_23(u32);
extern s32 sub_8037D64(u32, void *, void *);
extern s32 sub_80381F4(u32, void *, void *);
extern void sub_8023868(u32, u32, u32, u32);
extern void sub_80306A8(u32, u32, u32, u32);
extern s32 sub_8037B28(u32);
extern void sub_8011830(void);
extern u32 sub_8095350();
extern void sub_8031D70(u8, u32);
extern void sub_80151C0(u32, u8 *);
extern void xxx_call_start_bg_music(void);
extern u32 sub_8023CE8(void);
extern u32 sub_8030894(void);
extern void sub_8030F58(u32);
extern void sub_8023DA4(void);
extern void SetMenuItems(struct MenuStruct *, struct UnkTextStruct2 *, u32, const struct UnkTextStruct2 *, const struct MenuItem *, u32, u32, u32);
extern void sub_8029B34(void);
extern void sub_8029AD8(void);
extern void sub_8029AF4(void);
extern void sub_8029A88(void);
extern void sub_8029AB0(void);
extern void sub_80297B8(void);
extern void sub_80297D4(void);
extern void sub_8029884(void);
extern void sub_8029944(void);
extern void sub_80299AC(void);
extern void sub_80299D8(void);
extern void sub_8029A6C(void);
extern void sub_8028CE0(void);
extern void sub_8028BF0(void);
extern void sub_8029A18(void);
extern void sub_80295A8(void);
extern void sub_8029668(void);
extern void sub_8029684(void);
extern void sub_8029740(void);
extern void sub_80295D8(void);
extern void sub_802979C(void);
extern void sub_8029358(void);
extern void sub_8029374(void);
extern void sub_802939C(void);
extern void sub_8028F58(void);
extern void sub_8028F30(void);
extern void sub_8028F04(void);
extern void sub_8028ED4(void);
extern void sub_80293D8(void);
extern void sub_80293F4(void);
extern void sub_8028DE8(u32);
extern void sub_8028EAC(void);
extern void sub_802955C(void);
extern void sub_80292A4(void);
extern void sub_80292EC(void);
extern void sub_802933C(void);
extern void sub_802958C(void);
extern void sub_8029208(void);
extern void sub_8028E84(void);
extern void sub_8028F80(void);
extern void sub_8028FC0(void);
extern void sub_8028FDC(void);
extern void sub_8028E54(void);
extern void sub_8028E24(void);
extern void sub_8028E08(void);
extern void sub_80290D4(void);
extern void sub_80290F0(void);
extern void sub_80291AC(void);
extern void sub_8029044(void);
extern void sub_8028CFC(void);
extern void sub_8028D4C(void);
extern void sub_8031E10(void);
extern void sub_8023C60(void);
extern void sub_803084C(void);
extern void sub_80155F0(void);
extern void sub_80310B4(void);
extern void sub_8030DE4(void);
extern void sub_802453C(void);

extern const u8 DontSendPokemon_80DDB80[];
extern const u8 SendPokemon_80DDB98[];
extern const u8 SendWOPokemon[];

const struct MenuItem gUnknown_80DD970[] =
{
    {"Receive SOS Mail", 0x0},
    {"Leave for Rescue", 0x1},
    {"Send A-OK Mail", 0x2},
    {"Delete Mail", 0x3},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const struct MenuItem gUnknown_80DD9EC[] =
{
    {"Delete SOS Mail", 0x5},
    {"Delete A-OK Mail", 0x6},
    {"Delete All Mail", 0x7},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const struct MenuItem gUnknown_80DDA48[] =
{
    {"Yes", 0x8},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const struct MenuItem gUnknown_80DDA64[] =
{
    {"Yes", 0x8},
    {"No", 0x9},
    {NULL, 0xA}
};

const struct MenuItem gUnknown_80DDA80[] =
{
    {"Yes", 0x8},
    {"No", 0x9},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const struct MenuItem gUnknown_80DDAA0[] =
{
    {SendWOPokemon, 0x12},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 SendWOPokemon[] = _("Send w/o Pokémon");

const struct UnkTextStruct2 gUnknown_80DDACC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x00, 0x07, 0x00,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DDAE4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x00, 0x06, 0x00,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const struct MenuItem gUnknown_80DDAFC[] =
{
    {"Confirm", 0xB},
    {"Info", 0xC},
    {NULL, 0xA},
};

const struct MenuItem gUnknown_80DDB24[] =
{
    {"Game Link cable", 0xD},
    {"Password", 0xF},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

const struct MenuItem gUnknown_80DDB60[] =
{
    {SendPokemon_80DDB98, 0x11},
    {DontSendPokemon_80DDB80, 0x12},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 DontSendPokemon_80DDB80[] = _("Don{APOSTROPHE}t Send Pokémon");
ALIGNED(4) const u8 SendPokemon_80DDB98[] = _("Send Pokémon");

#include "data/wonder_mail_1.h"


u32 sub_8027F88(void)
{
  char *monName;
  struct OpenedFile *faceFile;
  s32 counter;

  ResetUnusedInputStruct();
  sub_800641C(0, 1, 1);
  gUnknown_203B2C0 = MemoryAlloc(sizeof(struct WonderMailStruct_203B2C0), 8);
  MemoryFill8((u8 *)gUnknown_203B2C0, 0, sizeof(struct WonderMailStruct_203B2C0));
  gUnknown_203B2C0->unk53C = 0;
  gUnknown_203B2C0->mailIndex = -1;
  gUnknown_203B2C0->speciesNum = -1;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
  monName = GetMonSpecies(MONSTER_PELIPPER);
  strcpy(gAvailablePokemonNames, monName);
  faceFile = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);
  gUnknown_203B2C0->faceFile = faceFile;
  gUnknown_203B2C0->faceData = faceFile->data;
  gUnknown_203B2C0->unk42C = 0;
  gUnknown_203B2C0->unk42D = 0;
  gUnknown_203B2C0->unk42E = 0;
  gUnknown_203B2C0->unk428 = 2;
  gUnknown_203B2C0->unk42A = 8;
  for(counter = 0; counter < PASSWORD_BUFFER_SIZE; counter++){
    gUnknown_203B2C0->passwordBuffer[counter] = 0;
  }
  gUnknown_203B2C0->fallbackState = 0x3D;
  sub_8028B04(0); // Set initial state to 0?
  return 1;
}

u32 sub_8028078(void)
{
  
  switch(gUnknown_203B2C0->state) {
    case 0x3c:
        sub_8029B34();
        break;
    case 0x3a:
        sub_8029AD8();
        break;
    case 0x3b:
        sub_8029AF4();
        break;
    case 0x38:
        sub_8029A88();
        break;
    case 0x37:
        sub_8029AB0();
        break;
    case 0x32:
        sub_80297B8();
        break;
    case 0x33:
        sub_80297D4();
        break;
    case 0x34:
        sub_8029884();
        break;
    case 0x35:
        sub_8029944();
        break;
    case 0x31:
        sub_80299AC();
        break;
    case 0x36:
        sub_80299D8();
        break;
    case 0x30:
        sub_8029A6C();
        break;
    case 0x2e:
        sub_8029A18();
        break;
    case 0x2d:
        sub_80295A8();
        break;
    case 0x29:
        sub_8029668();
        break;
    case 0x2b:
        sub_8029684();
        break;
    case 0x2c:
        sub_8029740();
        break;
    case 0x2a:
        sub_80295D8();
        break;
    case 0x2f:
        sub_802979C();
        break;
    case 9:
        sub_8029358();
        break;
    case 0x23:
        sub_8029374();
        break;
    case 0x24:
        sub_802939C();
        break;
    case 0x26:
        sub_80293D8();
        break;
    case 0x27:
        sub_80293F4();
        break;
    case 0x28:
        sub_802955C();
        break;
    case 4:
        sub_80292A4();
        break;
    case 6:
        sub_80292EC();
        break;
    case 7:
        sub_802933C();
        break;
    case 5:
        sub_802958C();
        break;
    case 8:
        sub_8029208();
        break;
    case 0x1a:
        sub_8028DE8(1);
        break;
    case 0x1b:
        sub_8028F80();
        break;
    case 0x1c:
    case 0x1d:
        sub_8028FC0();
        break;
    case 0x22:
        sub_8028FDC();
        break;
    case 0x1e:
        sub_80290D4();
        break;
    case 0x20:
        sub_80290F0();
        break;
    case 0x21:
        sub_80291AC();
        break;
    case 0x1f:
        sub_8029044();
        break;
    case 10:
        sub_8028CFC();
        break;
    case 0xb:
        sub_8028D4C();
        break;
    case 0xd:
    case 0xf:
        sub_8028DE8(10);
        break;
    case 0x11:
        sub_8028E08();
        break;
    case 0xc:
    case 0xe:
    case 0x10:
        sub_8028DE8(0x19);
        break;
    case 0x12:
        sub_8028E24();
        break;
    case 0x13:
        sub_8028E54();
        break;
    case 0x17:
        sub_8028E84();
        break;
    case 0x18:
        sub_8028EAC();
        break;
    case 0x19:
        sub_8028ED4();
        break;
    case 0x14:
        sub_8028F04();
        break;
    case 0x15:
        sub_8028F30();
        break;
    case 0x16:
        sub_8028F58();
        break;
    case 0:
    case 1:
        sub_8028BF0();
        break;
    case 2:
    case 0x25:
    case 0x39:
        sub_8028CE0();
        break;
    case 3:
        return 3;
  }
  return 0;
}

s32 sub_80282DC(u8 *r0)
{
    *r0 = gUnknown_203B2C0->mailIndex;
    return gUnknown_203B2C0->unk53C;
}

void sub_80282FC(void)
{
  if (gUnknown_203B2C0 != NULL) {
    CloseFile(gUnknown_203B2C0->faceFile);
    MemoryFree(gUnknown_203B2C0);
    gUnknown_203B2C0 = NULL;
    sub_8031E10();
    sub_8023C60();
    sub_803084C();
    sub_80155F0();
    sub_80310B4();
    sub_8030DE4();
    sub_802453C();
  }
}

void nullsub_130(void)
{
}

void sub_8028348(void)
{
    s32 linkError;
    switch(gUnknown_203B2C0->state)
    {
        case 0x3B:
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8031D70(gUnknown_203B2C0->mailIndex, 0);
            break;
        case 0x3C:
            sub_80141B4(gUnknown_80DDBA8, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x3A:
            sub_80141B4(gUnknown_80DDBFC, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x38:
            sub_80141B4(gUnknown_80DDC30, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x37:
            switch(gUnknown_203B2C0->unk534)
            {
                // 0x0 - 0x9 included here too...
                case 0x10:
                case 0xF:
                case 0xD:
                    sub_80141B4(gUnknown_80DDC70, 0, &gUnknown_203B2C0->faceFile,0x10d);
                    break;
                case 0xE:
                    break;
            }
            break;
        case 0x39:
            sub_80141B4(gUnknown_80DDC30, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x32:
            sub_80141B4(gUnknown_80DDCBC, 0, 0,0x101);
            break;
        case 0x33:
            if(sub_8023CE8() != 0)
            {
                break;
            }
            else
            {
                ResetUnusedInputStruct();
                sub_800641C(0, 1, 1);
                sub_8023868(3, 0, 0, 9);
            }
            break;
        case 0x34:
            sub_8006518(gUnknown_203B2C0->unk35C);
            SetMenuItems(gUnknown_203B2C0->unk21C, gUnknown_203B2C0->unk35C, 3, &gUnknown_80DDAE4, gUnknown_80DDAFC, 1, 0, 0);
            sub_8023DA4();
            sub_8035CF4(gUnknown_203B2C0->unk21C, 3, 1);
            break;
        case 0x31:
            sub_8014248(gUnknown_80DDD2C, 0, 0xA, gUnknown_80DDAA0, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x36:
            sub_8014248(gUnknown_80DDD88, 0, 8, gUnknown_80DDA80, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x2D:
            sub_8014248(gUnknown_80DDDBC, 0, 8, gUnknown_80DDA64, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x29:
            sub_80141B4(gUnknown_80DDDD8, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x2A:
            if(sub_8030894() != 0)
            {
                break;
            }
            else
            {
                ResetUnusedInputStruct();
                sub_800641C(0, 1, 1);
                sub_80306A8(4, 0, 0, 6);
            }
            break;
        case 0x2F:
            sub_80141B4(gUnknown_80DDE20, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x30:
            sub_80141B4(gUnknown_80DDE58, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x2E:
            sub_8014248(gUnknown_80DDEC0, 0, 0x11, gUnknown_80DDB60, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 9:
            sub_80141B4(gUnknown_80DDF2C, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 4:
            sub_8014248(gUnknown_80DDFB8, 0, 8, gUnknown_80DDA48, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 5:
            nullsub_23(0);
            sub_80141B4(gUnknown_80DE01C, 0 , 0, 0);
            break;
        case 6:
            gUnknown_203B2C0->linkError = COMMS_GOOD;
            sub_8011830();
            linkError = sub_8037B28(gUnknown_203B2C0->unk40);
            gUnknown_203B2C0->linkError = linkError;
            if(linkError == COMMS_GOOD)
            {
                switch(gUnknown_203B2C0->unk40)
                {
                    case 3:
                        MemoryFill8((u8 *)&gUnknown_203B2C0->unk48, 0, sizeof(struct unkStruct_203B480));
                        MemoryFill8((u8 *)&gUnknown_203B2C0->unk78, 0, sizeof(struct unkStruct_203B480));
                        gUnknown_203B2C0->linkError = sub_8037D64(gUnknown_203B2C0->unk40, &gUnknown_203B2C0->unk48, &gUnknown_203B2C0->unk78);
                        break;
                    case 4:
                        MemoryFill8((u8 *)&gUnknown_203B2C0->unkA8, 0, sizeof(struct WonderMailStruct_203B2C0_sub));
                        MemoryFill8((u8 *)&gUnknown_203B2C0->unk130, 0, sizeof(struct WonderMailStruct_203B2C0_sub));
                        gUnknown_203B2C0->unkA8.pokemon.speciesNum = 0;
                        gUnknown_203B2C0->unk130.pokemon.speciesNum = 0;
                        gUnknown_203B2C0->unkA8.mail = *sub_8095228(gUnknown_203B2C0->mailIndex);
                        if(gUnknown_203B2C0->speciesNum != -1)
                        {
                            gUnknown_203B2C0->unkA8.pokemon = gRecruitedPokemonRef->pokemon[gUnknown_203B2C0->speciesNum];
                        }
                        gUnknown_203B2C0->linkError = sub_8037D64(gUnknown_203B2C0->unk40, &gUnknown_203B2C0->unkA8, &gUnknown_203B2C0->unk130);
                        break;
                }
                if(gUnknown_203B2C0->linkError == COMMS_GOOD)
                {   
                    switch(gUnknown_203B2C0->unk40)
                    {
                        case 3:
                            gUnknown_203B2C0->linkError = sub_80381F4(3, &gUnknown_203B2C0->unk48, &gUnknown_203B2C0->unk78);
                            break;
                        case 4:
                            gUnknown_203B2C0->linkError = sub_80381F4(4, &gUnknown_203B2C0->unkA8, &gUnknown_203B2C0->unk130);
                            break;
                    }
                }
                xxx_call_start_bg_music();
            }
            else
            {
                xxx_call_start_bg_music();
            }
            break;
        case 0x23:
            switch(gUnknown_203B2C0->unk534)
            {
                // 0x0 - 0x9 included here too...
                case 0x10:
                case 0xF:
                case 0xD:
                    sub_80141B4(gUnknown_80DE06C, 0, &gUnknown_203B2C0->faceFile,0x10d);
                    break;
                case 0xE:
                    break;
            }
            break;
        case 0x25:
            sub_80141B4(gUnknown_80DE0C0, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x26:
            sub_80141B4(gUnknown_80DE124, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x27:
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_80151C0(4, gUnknown_203B2C0->passwordBuffer);
            break;
        case 8:
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8014248(gUnknown_80DE178, 0, 0xD, gUnknown_80DDB24, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
                    break;
                case 2:
                    sub_8014248(gUnknown_80DE1B4, 0, 0xD, gUnknown_80DDB24, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
                    break;
            }
            break;
        case 0x1A:
            sub_80141B4(gUnknown_80DE1E4, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x1B:
            sub_80141B4(gUnknown_80DE280, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x1C:
            sub_80141B4(gUnknown_80DE2B0, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x1D:
            sub_80141B4(gUnknown_80DE368, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x22:
            sub_8014248(gUnknown_80DDDBC, 0, 8, gUnknown_80DDA64, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x1E:
            sub_80141B4(gUnknown_80DE430, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x1F:
            if(sub_8030894() != 0)
            {
                break;
            }
            else
            {
                ResetUnusedInputStruct();
                sub_800641C(0, 1, 1);
                sub_80306A8(2, 0, 0, 6);
            }
            break;
        case 0x20:
        case 0x2B:
            sub_8006518(gUnknown_203B2C0->unk35C);
            SetMenuItems(gUnknown_203B2C0->unk21C, gUnknown_203B2C0->unk35C, 3, &gUnknown_80DDACC, gUnknown_80DDAFC, 1, 0, 0);
            sub_803092C();
            sub_8035CF4(gUnknown_203B2C0->unk21C, 3, 1);
            break;
        case 0xA:
            gUnknown_203B2C0->unk540 = sub_8095350();
            switch((u32)gUnknown_203B2C0->unk538)
            {
                case 5:
                    sub_8030F58(2);
                    break;
                case 6:
                    sub_8030F58(4);
                    break;
                default:
                case 7:
                    break;
            }
            break;
        case 0xB:
            sub_8014248(gUnknown_80DE48C, 0, 5, gUnknown_80DD9EC, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0xD:
            sub_80141B4(gUnknown_80DE4B8, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0xC:
            sub_80141B4(gUnknown_80DE4F0, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0xF:
            sub_80141B4(gUnknown_80DE524, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0xE:
            sub_80141B4(gUnknown_80DE614, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x11:
            sub_80141B4(gUnknown_80DE648, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x10:
            sub_80141B4(gUnknown_80DE694, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x12:
            sub_8014248(gUnknown_80DE6D4, 0, 8, gUnknown_80DDA48, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x13:
            sub_8014248(gUnknown_80DE754, 0, 8, gUnknown_80DDA48, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x17:
            sub_80141B4(gUnknown_80DE7B8, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x18:
            sub_80141B4(gUnknown_80DE7E8, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x19:
            sub_8014248(gUnknown_80DE808, 0, 8, gUnknown_80DDA64, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x14:
            sub_80141B4(gUnknown_80DE830, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x15:
            sub_80141B4(gUnknown_80DE864, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x16:
            sub_80141B4(gUnknown_80DE7E8, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0:
            sub_8014248(gUnknown_80DE8B4, 0, 0, gUnknown_80DD970, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 1:
            sub_8014248(gUnknown_80DE918, 0, 0, gUnknown_80DD970, 0, 4, 0, &gUnknown_203B2C0->faceFile,0xC);
            break;
        case 2:
            sub_80141B4(gUnknown_80DE93C, 0, &gUnknown_203B2C0->faceFile,0x10d);
            break;
        case 3:
            break;
    }
}


void sub_8028B04(u32 state)
{
    gUnknown_203B2C0->state = state;
    nullsub_130();
    sub_8028348();
}

// Wonder Mail Linking...
void sub_8028B1C(u32 errorCode)
{
    switch(errorCode)
    {
        case COMMS_GOOD:
            break;
        case 1:
        case COMMS_NO_RESPONSE:
            sub_80141B4(gWonderMailErrorText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_INCORRECT_NUM_SYSTEMS:
            sub_80141B4(gWonderMailNumGBAsText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_DIFFERENT_MODES:
            sub_80141B4(gWonderMailWrongModeText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 5:
            sub_80141B4(gWonderMailErrorText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NO_ROOM_STORAGE:
            sub_80141B4(gWonderMailStorageFullText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_DUPLICATE_MAIL:
            sub_80141B4(gWonderMailDuplicateText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NOT_ELIGIBLE_1:
            sub_80141B4(gWonderMailNotEligibleReceiveText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NOT_ELIGIBLE_2:
            sub_80141B4(gWonderMailNotEligibleReceiveText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NO_ROOM_MAIL:
            sub_80141B4(gWonderMailNoRoomText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 14:
            sub_80141B4(gWonderMailErrorText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NOT_READY:
            sub_80141B4(gWonderMailFriendErrorText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
            break;
        default:
            break;
    }
}

void sub_8028BF0(void)
{
    u32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    gUnknown_203B2C0->unk40 = 8;
    gUnknown_203B2C0->speciesNum = -1;
    switch(temp)
    {
        case 0:
            gUnknown_203B2C0->unk40 = 3;
            gUnknown_203B2C0->unk538 = 0;
            if(FindOpenMailSlot() != -1)
            {
                sub_8028B04(8);
            }
            else
            {
                sub_8028B04(9);
            }
            break;
        case 1:
            if(CountMailType(2) != 0)
            {
                sub_8028B04(30);
            }
            else
            {
                sub_8028B04(26);
            }
            break;
        case 2:
            gUnknown_203B2C0->unk40 = 4;
            gUnknown_203B2C0->unk538 = 2;
            if(CountMailType(WONDER_MAIL_TYPE_AOK) != 0)
            {
                sub_8028B04(41);
            }
            else
            {
                sub_8028B04(47);
            }
            break;
        case 3:
            sub_8028B04(11);
            break;
        case 10:
            sub_8028B04(2);
            break;
        default:
            break;
    }
}


void sub_8028CE0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(3);
}

void sub_8028CFC()
{
    s32 temp;
    u32 temp2;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(sub_8031050())
    {
        case 2:
        case 3:
            temp2 = sub_8095350();
            sub_80310B4();
            if(temp2 != gUnknown_203B2C0->unk540)
            {
                sub_8028B04(23);
            }
            else
            {
                sub_8028B04(25);
            }
            break;
        default:
            break;
    }
}

void sub_8028D4C()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    gUnknown_203B2C0->unk538 = temp;
    switch(gUnknown_203B2C0->unk538)
    {
        case 5:
            if(HasNoWonderMailType(2))
            {
                sub_8028B04(12);
            }
            else
            {
                sub_8028B04(13);
            }
            break;
        case 6:
            if(HasNoWonderMailType(WONDER_MAIL_TYPE_AOK))
            {
                sub_8028B04(14);
            }
            else
            {
                sub_8028B04(15);
            }
            break;
        case 7:
            if(HasNoWonderMailType(WONDER_MAIL_TYPE_NONE))
            {
                sub_8028B04(16);
            }
            else
            {
                sub_8028B04(17);
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028DE8(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(r0);
}

void sub_8028E08()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(18);
}

void sub_8028E24()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(19);
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E54()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(20);
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E84()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(24);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
}

void sub_8028EAC()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        FinishWriteSavePak();
        sub_8028B04(25);
    }
}

void sub_8028ED4()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp){
        case 8:
            sub_8028B04(11);
            break;
        case 9:
        case 10:
            sub_8028B04(2);
            break;
        default:
            break;
    }
}

void sub_8028F04()
{
    s32 temp;
    s32 counter;

    if(sub_80144A4(&temp) == 0)
    {
        for(counter = 0; counter <= 31; counter++)
        {
            sub_8095240(counter);
        }
        sub_8028B04(21);
    }
}

void sub_8028F30()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(22);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
}

void sub_8028F58()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        FinishWriteSavePak();
        sub_8028B04(2);
    }
}

void sub_8028F80()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_809927C(gUnknown_203B2C0->mailIndex);
    gUnknown_203B2C0->unk53C = 1;
    sub_8028B04(3);
}

void sub_8028FC0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8028FDC(void)
{
    s32 temp;
    struct unkStruct_203B480 *mail;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            mail = sub_8095228(gUnknown_203B2C0->mailIndex);
            if(sub_80A2824(mail->dungeon.id) == 0)
            {
                sub_8028B04(0x1C);
            }
            else
            {
                if(mail->unk2C <= 0)
                {
                    sub_8028B04(0x1D);
                }
                else
                {
                    sub_8028B04(0x1B);
                }
            }
            break;
        case 9:
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8029044(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            sub_8028B04(1);
            break;
        case 3:
            gUnknown_203B2C0->mailIndex = sub_80307EC();
            sub_8028B04(32);
            break;
        case 4:
            gUnknown_203B2C0->fallbackState = 0x1F;
            gUnknown_203B2C0->mailIndex = sub_80307EC();
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->mailIndex, 0);
            sub_8028B04(33);
            break;
    }
}

void sub_80290D4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(31);
}

void sub_80290F0(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk21C[3])) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk21C[3]), &menuAction);
    }
    switch(menuAction)
    {
        case 11:
            sub_803084C();
            sub_8028B04(34);
            break;
        case 12:
            gUnknown_203B2C0->fallbackState = 0x3D;
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->mailIndex, 0);
            sub_8028B04(33);
            break;
        case 4:
        case 10:
            sub_8035CC0(gUnknown_203B2C0->unk35C, 2);
            sub_8030810(1);
            sub_8028B04(31);
            break;
        default:
            break;
    }
}

void sub_80291AC(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B2C0->fallbackState == 0x3D)
            {
                sub_8035CF4(gUnknown_203B2C0->unk21C, 3, 1);
                sub_8028B04(0x20);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->fallbackState);
            }
        default:
            break;
    }
}

void sub_8029208(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {

        case 13:
        case 14:
            gUnknown_203B2C0->unk534 = 13;
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8028B04(4);
                    break;
                case 2:
                    sub_8028B04(0x30);
                    break;
                default:
                    return;
            }
            break;
        case 15:
            gUnknown_203B2C0->unk534 = 15;
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8028B04(0x26);
                    break;
                case 2:
                    sub_8028B04(0x3A);
                    break;
                default:
                    return;
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_80292A4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                case 2:
                    sub_8028B04(5);
                    break;
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_80292EC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(gUnknown_203B2C0->linkError == COMMS_GOOD)
    {
        switch(gUnknown_203B2C0->unk538)
        {
            case 0:
                sub_8028B04(0x23);
                break;
            case 2:
                sub_8028B04(0x37);
                break;
        }
    }
    else
    {
        sub_8028B1C(gUnknown_203B2C0->linkError);
        sub_8028B04(0x7);
    }
}

void sub_802933C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8029358(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8029374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x24);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
}

void sub_802939C(void)
{
    s32 temp;
    u32 saveStatus;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        saveStatus = GetSavePakStatus();
        FinishWriteSavePak();
        if(saveStatus == SAVE_COMPLETED)
        {
            sub_8028B04(0x25);
        }
        else
        {
            sub_8028B04(0x2);
        }
    }
}

void sub_80293D8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x27);
}

void sub_80293F4(void)
{
    u32 return_var;
    struct unkStruct_203B480 mail;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&mail, 0, sizeof(struct unkStruct_203B480));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(PASSWORD_ENTRY_SOS_MAIL_MODE, (gUnknown_203B2C0->passwordBuffer), &mail))
                {
                    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                        sub_8014248(gWonderMailPasswordIncorrectText, 0, 8, gUnknown_80DDA48, 0, 4, 0, &gUnknown_203B2C0->faceFile, 0xC);
                        sub_8028B04(40);
                        break;
                    case PASSWORD_ENTRY_NOT_SOS_MAIL:
                        sub_80141B4(gWonderMailSOSPasswordIncorrectText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
                        sub_8028B04(7);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
                        sub_80141B4(gWonderMailDuplicateText, 0, &gUnknown_203B2C0->faceFile, 0x10d);
                        sub_8028B04(7);
                        break;
                    case PASSWORD_ENTRY_SOS_MAIL_SUCCESS:
                        sub_8095274(mail.unk10.unk10);
                        mail.mailType = 2;
                        sub_80951BC(&mail);
                        sub_80141B4(gWonderMailAOKMailReceivedText, 0, &gUnknown_203B2C0->faceFile, 0x101);
                        sub_8028B04(35);
                        break;
                    case 23:
                    case 24:
                    default:
                        break;
                }
            sub_80155F0();
            break;
        case 2:
            sub_80155F0();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_802955C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(0x26);
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_802958C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(6);
}

void sub_80295A8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(0x8);
            break;
        case 9:
        case 10:
            sub_8028B04(1);
            break;

    }
}

void sub_80295D8(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            sub_8028B04(1);
            break;
        case 3:
            gUnknown_203B2C0->mailIndex = sub_80307EC();
            sub_8028B04(0x2B);
            break;
        case 4:
            gUnknown_203B2C0->fallbackState = 0x2A;
            gUnknown_203B2C0->mailIndex = sub_80307EC();
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->mailIndex, 0);
            sub_8028B04(0x2C);
            break;
    }
}

void sub_8029668(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x2A);
}

void sub_8029684(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk21C[3])) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk21C[3]), &menuAction);
    }
    switch(menuAction)
    {
        case 0xB:
            sub_803084C();
            sub_8028B04(0x2D);
            break;
        case 0xC:
            gUnknown_203B2C0->fallbackState = 0x3D;
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->mailIndex, 0);
            sub_8028B04(0x2C);
            break;
        case 0x4:
        case 0xA:
            sub_8035CC0(gUnknown_203B2C0->unk35C,2);
            sub_8030810(1);
            sub_8028B04(0x2A);
            break;
    }
}

void sub_8029740(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B2C0->fallbackState == 0x3D)
            {
                sub_8035CF4(gUnknown_203B2C0->unk21C, 3, 1);
                sub_8028B04(0x2B);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->fallbackState);
            }
            break;
    }
}

void sub_802979C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_80297B8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x33);
}

void sub_80297D4(void)
{
    switch(sub_8023A94(1))
    {
        case 2:
            sub_8023C60();
            sub_8028B04(1);
            gUnknown_203B2C0->speciesNum = -1;
            break;
        case 3:
            gUnknown_203B2C0->speciesNum = sub_8023B44();
            sub_8028B04(0x34);
            break;
        case 4:
            gUnknown_203B2C0->fallbackState = 0x33;
            gUnknown_203B2C0->speciesNum = sub_8023B44();
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B2C0->speciesNum, 0);
            sub_8028B04(0x35);
            break;
    }
}

void sub_8029884(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8023A94(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk21C[3])) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk21C[3]), &menuAction);
    }
    switch(menuAction)
    {
        case 0xB:
            sub_8023C60();
            sub_8028B04(4);
            break;
        case 0xC:
            gUnknown_203B2C0->fallbackState = 0x3D;
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B2C0->speciesNum, 0);
            sub_8028B04(0x35);
            break;
        case 0x4:
        case 0xA:
            sub_8035CC0(gUnknown_203B2C0->unk35C, 3);
            sub_8023B7C(1);
            sub_8028B04(0x33);
            break;
    }
}

void sub_8029944(void)
{
    u32 temp;
    temp = sub_80244E4();
    if(temp == 1)
    {
            sub_802452C();
            return;
    }
    switch(temp)
    {
        case 1:
            break;
        case 2:
        case 3:
            sub_802453C();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_8023B7C(1);
            if(gUnknown_203B2C0->fallbackState == 0x3D)
            {
                sub_8035CF4(gUnknown_203B2C0->unk21C, 3, 1);
                sub_8028B04(0x34);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->fallbackState);
            }

    }
}

void sub_80299AC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x12:
            sub_8028B04(4);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_80299D8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {

        case 8:
            sub_8028B04(4);
            break;
        case 9:
            sub_8028B04(0x32);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
    }
}

void sub_8029A18(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x11:
            if(sub_8024108(3) != 0)
            {
                sub_8028B04(0x31);
            }
            else
            {
                sub_8028B04(0x32);
            }
            break;
        case 0x12:
            sub_8028B04(0x4);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
    }
}

void sub_8029A6C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x2E);
}

void sub_8029A88(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        FinishWriteSavePak();
        sub_8028B04(0x39);
    }
}

void sub_8029AB0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x38);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
}

void sub_8029AD8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x3B);
}

void sub_8029AF4(void)
{
    switch(sub_8031DCC())
    {

        case 2:
        case 3:
            sub_8031E10();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_8028B04(0x3C);
            break;
        case 1:
            sub_8031E00();
            break;
    }
}

void sub_8029B34(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(3);
}
