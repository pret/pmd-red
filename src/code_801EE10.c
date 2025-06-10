#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "code_801EE10.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

EWRAM_INIT unkStruct_203B270 *gUnknown_203B270 = { NULL };

const WindowTemplate gUnknown_80DC240 = {
    0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowHeader gUnkData_80DC258 = {0x01, 0x00, 0x0F, 0x00};

const WindowTemplate gUnknown_80DC25C = {
    0,
    6,
    0x2, 0x2,
    0x12, 0x8,
    0x8, 0,
    &gUnkData_80DC258
};

const WindowTemplate gUnknown_80DC274 = {
    0,
    3,
    0x2, 0xF,
    0x1A, 0x3,
    0x3, 0,
    NULL,
};

ALIGNED(4) const u8 gUnknown_80DC28C[] = _("Moves: {COLOR YELLOW}{POKEMON_0}{RESET} ");
ALIGNED(4) const u8 gUnknown_80DC2A0[] = _("{MOVE_ITEM_0}");

s32 sub_801F3F8(void);

u8 sub_801EE10(u32 param_1, s16 species, Move *moves, u32 param_4, const u8 *text, u32 param_6)
{
    s32 iVar5;
    s32 iVar8;
    s32 species_s32;
    u8 param_4_u8;
    s32 four;

    species_s32 = species;
    param_4_u8 = param_4;
    gUnknown_203B270 = MemoryAlloc(sizeof(unkStruct_203B270), 8);
    gUnknown_203B270->unk4 = param_4_u8;
    gUnknown_203B270->unk5 = 1;
    gUnknown_203B270->unk6 = 1;
    gUnknown_203B270->unk7 = 1;
    gUnknown_203B270->unk0 = param_1;
    switch(param_1)
    {
        case 2:
        case 3:
            gUnknown_203B270->unk5 = 0;
            gUnknown_203B270->unk6 = 0;
            gUnknown_203B270->unk7 = 0;
            break;
        case 0:
        case 1:
            break;
    }
    gUnknown_203B270->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    gUnknown_203B270->isTeamLeader = gUnknown_203B270->pokeStruct->isTeamLeader;
    gUnknown_203B270->moves = moves;
    gUnknown_203B270->text = text;
    iVar8 = iVar5 = sub_801F3F8();
    four = 4;
    if (iVar8 < four) {
        iVar8 = 4;
    }
    RestoreSavedWindows(&gUnknown_203B270->windows);
    gUnknown_203B270->unk50 = param_6;
    gUnknown_203B270->windows.id[param_6] = gUnknown_80DC25C;
    if (gUnknown_203B270->text != NULL) {
        gUnknown_203B270->unk54 = sub_8006544(param_6);
        gUnknown_203B270->windows.id[gUnknown_203B270->unk54] = gUnknown_80DC274;
    }
    sub_8012D08(&gUnknown_203B270->windows.id[gUnknown_203B270->unk50],iVar8);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B270->windows, TRUE, TRUE);
    sub_8013818(&gUnknown_203B270->input,iVar5,iVar5,param_6);
    sub_8013780(&gUnknown_203B270->input,0);
    sub_801F280(TRUE);
    return 1;
}

u32 sub_801EF38(char param_1)
{
    bool8 flag;
    s32 index;
    s32 index2;
    s32 moveIndex;
    s32 newIndex;
    struct Move *move;

    flag = FALSE;
    if (param_1 == 0) {
        sub_8013660(&gUnknown_203B270->input);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B270->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        case INPUT_DPAD_DOWN:
            index = gUnknown_203B270->input.menuIndex;
            sub_8013780(&gUnknown_203B270->input, unk_FindMoveEnabledForAIAfter8_v2(gUnknown_203B270->moves, index));
            if (index != gUnknown_203B270->input.menuIndex) {
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_DPAD_UP:
            index = gUnknown_203B270->input.menuIndex;
            sub_8013780(&gUnknown_203B270->input,unk_FindMoveEnabledForAIBefore8_v2(gUnknown_203B270->moves,index));
            if (index != gUnknown_203B270->input.menuIndex) {
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_R_DPAD_DOWN_BUTTONS:
            if (gUnknown_203B270->unk5 == 0) break;
            moveIndex = gUnknown_203B270->input.menuIndex;
            newIndex = gUnknown_203B270->input.menuIndex = unk_SetMoveToLastInLinkedSequence8_v2(gUnknown_203B270->moves, moveIndex);
            if (moveIndex != newIndex) {
                PlayMenuSoundEffect(3);
            }
            else {
                goto _134;
            }
            sub_801F280(TRUE);
            return 1;
        case INPUT_R_DPAD_UP_BUTTONS:
            if (gUnknown_203B270->unk5 == 0) break;
            moveIndex = gUnknown_203B270->input.menuIndex;
            newIndex = gUnknown_203B270->input.menuIndex = unk_SetMoveToFirstInLinkedSequence8_v2(gUnknown_203B270->moves,moveIndex);
            if (moveIndex != newIndex) {
                PlayMenuSoundEffect(3);
            }
            else {
_134:
                    PlayMenuSoundEffect(2);
            }
            sub_801F280(TRUE);
            return 1;
        case INPUT_R_A_BUTTONS:
            if (gUnknown_203B270->unk6 != 0) {
                if ((gTeamInventoryRef->teamMoney > 0x95) && (sub_8093318(gUnknown_203B270->input.menuIndex,gUnknown_203B270->moves)))
                {
                    TryLinkMovesAfter(gUnknown_203B270->input.menuIndex,gUnknown_203B270->moves);
                    PlayMenuSoundEffect(6);
                    flag = TRUE;
                    if (!gUnknown_203B270->unk4) {
                        gUnknown_203B270->unk4 = TRUE;
                        PlaySound(0x14c);
                    }
                    break;
                }
                else if (UnlinkMovesAfter(gUnknown_203B270->input.menuIndex,gUnknown_203B270->moves)) {
                    PlayMenuSoundEffect(6);
                    goto _ret;
                }
                else {
                    PlayMenuSoundEffect(2);
                    break;
                }
            }
            break;
        case INPUT_SELECT_BUTTON:
            if (gUnknown_203B270->unk7 != 0) {
                if (gUnknown_203B270->isTeamLeader) {
                    if (!ToggleSetMove(gUnknown_203B270->input.menuIndex,gUnknown_203B270->moves)) {
                        PlayMenuSoundEffect(2);
                        break;
                    }
                    else {
                        PlayMenuSoundEffect(6);
                        goto _ret;
                    }
                }
                else if (ToggleMoveEnabled(gUnknown_203B270->input.menuIndex,gUnknown_203B270->moves)) {
                    PlayMenuSoundEffect(6);
                    goto _ret;
                }
                else {
                    PlayMenuSoundEffect(2);
                    break;
                }
            }
            break;
    }
    if (!flag) {
        for(index2 = 0; index2 < 8; index2++)
        {
            move =  &gUnknown_203B270->moves[index2];
            if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
                if ((move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
                    gUnknown_203B270->fill14[index2] = 1;
                }
                else {
                    gUnknown_203B270->fill14[index2] = 0;
                }
            }
        }
        AddMenuCursorSprite_(&gUnknown_203B270->input, gUnknown_203B270->fill14);
    }
    if (flag) {
    _ret:
        sub_801F280(TRUE);
        return 1;
    }
    else
{
        return 0;
    }
}

s32 sub_801F194 (void)
{
    return gUnknown_203B270->input.menuIndex;
}

bool8 sub_801F1A4(void)
{
    return gUnknown_203B270->unk4;
}

void sub_801F1B0(bool8 param_1, bool8 param_2)
{
    if(!gUnknown_203B270->unk4)
        gUnknown_203B270->unk4 = param_2;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B270->windows, TRUE, TRUE);
    gUnknown_203B270->input.unk22 = sub_801F3F8();
    sub_8013984(&gUnknown_203B270->input);
    gUnknown_203B270->input.menuIndex = sub_8092F4C(gUnknown_203B270->moves, gUnknown_203B270->input.menuIndex);
    sub_801F280(TRUE);
    if(param_1)
        AddMenuCursorSprite(&gUnknown_203B270->input);
}

void sub_801F214(void)
{
    if(gUnknown_203B270)
    {
        gUnknown_203B270->windows.id[gUnknown_203B270->unk50] = gUnknown_80DC240;
        if(gUnknown_203B270->text)
        {
            gUnknown_203B270->windows.id[gUnknown_203B270->unk54] = gUnknown_80DC240;
        }
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B270->windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B270);
        gUnknown_203B270 = NULL;
    }
}

extern void StrncpyCustom(u8 *buffer, u8 *string, s32 size);

void sub_801F280(bool8 param_1)
{
    int i;
    u8 buffer[20];

    CallPrepareTextbox_8008C54(gUnknown_203B270->unk50);
    sub_80073B8(gUnknown_203B270->unk50);
    StrncpyCustom(buffer,gUnknown_203B270->pokeStruct->name,POKEMON_NAME_LENGTH);
    strcpy(gFormatBuffer_Monsters[0],buffer);
    PrintFormattedStringOnWindow(0xc,0,gUnknown_80DC28C,gUnknown_203B270->unk50,0); // Move: {COLOR_1 YELLOW}{ARG_POKEMON_0){END_COLOR_TEXT_1}

    for (i = 0; i < gUnknown_203B270->input.unk1A; i++) {
        struct Move *move;
        bool8 linkChain;
        s32 x, y;
        struct MoveBufferStruct uStack_30 = {0};

        uStack_30.xPPCoord = X_PP_COORD_DEFAULT;
        move = &gUnknown_203B270->moves[i];
        if (MoveFlagExists(move)) {
            if (gUnknown_203B270->isTeamLeader) {
                uStack_30.style = 2;
            }
            else {
                uStack_30.style = 4;
            }

            if (gUnknown_203B270->unk6) {
                uStack_30.unk9 = 1;
            }
            else {
                uStack_30.unk9 = 0;
            }

            if (i >= MAX_MON_MOVES) {
                uStack_30.unk8 = 1;
            }

            BufferDefaultMoveName(gFormatBuffer_Items[0],move,&uStack_30);
            y = GetMenuEntryYCoord(&gUnknown_203B270->input,i);
            linkChain = MoveFlagLinkChain(move);
            x = !linkChain ? 0x8 : 0xD;
            if (!linkChain && i != 0) {
                AddUnderScoreHighlight(gUnknown_203B270->unk50,0xc,y - 2,0x78,7);
            }
            PrintFormattedStringOnWindow(x,y,gUnknown_80DC2A0,gUnknown_203B270->unk50,0); // {ARG_MOVE_ITEM_0}
        }
    }

    sub_80073E0(gUnknown_203B270->unk50);
    if ((gUnknown_203B270->text != NULL) && (param_1)) {
        CallPrepareTextbox_8008C54(gUnknown_203B270->unk54);
        sub_80073B8(gUnknown_203B270->unk54);
        PrintFormattedStringOnWindow(8,0,gUnknown_203B270->text,gUnknown_203B270->unk54,0);
        sub_80073E0(gUnknown_203B270->unk54);
    }
}

s32 sub_801F3F8(void)
{
  Move *move;
  int index;
  s32 counter;

  counter = 0;
  for(index = 0; index < 8; index++)
  {
    move = &gUnknown_203B270->moves[index];
    if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
      counter++;
    }
  }
  return counter;
}
