#include "global.h"
#include "structs/str_dungeon.h"
#include "number_util.h"
#include "input.h"
#include "structs/map.h"
#include "code_80521D0.h"
#include "dungeon_action.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "dungeon_music.h"
#include "dungeon_ai_movement.h"
#include "code_8045A00.h"
#include "code_80130A8.h"
#include "code_803E46C.h"
#include "code_801602C.h"
#include "code_800D090.h"
#include "trap.h"
#include "charge_move.h"
#include "dungeon_map_access.h"
#include "status_checks_1.h"
#include "game_options.h"
#include "weather.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "tile_types.h"
#include "dungeon_visibility.h"
#include "dungeon_movement.h"
#include "bg_control.h"
#include "menu_input.h"
#include "music.h"
#include "items.h"
#include "play_time.h"
#include "pokemon_3.h"
#include "text2.h"
#include "text1.h"
#include "code_806CD90.h"
#include "code_8044CC8.h"
#include "code_801B3C0.h"
#include "dungeon_capabilities.h"
#include "constants/dungeon.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/iq_skill.h"
#include "constants/dungeon_action.h"
#include "structs/struct_sub80095e4.h"
#include "structs/str_text.h"

struct UnkMenuBitsStruct {
    u8 a0_8;
    u8 a0_16;
    u8 a0_24;
    u8 a0_32;
};

extern void PrintFieldMessage(u32, const u8 *, u32);
extern void HandleSetItemAction(Entity *,bool8);
extern void HandleUnsetItemAction(Entity *,bool8);
extern bool8 sub_8048A68(Entity *param_1,Item *item);
extern bool8 sub_8048950(Entity *param_1,Item *item);
extern bool8 sub_8048B9C(Entity *param_1,Item *item);
extern Item *sub_8044D90(Entity *, s32, u32);
extern void sub_8083D44(void);
extern void sub_8083D30(void);
extern void sub_8083D08(void);
extern void sub_805239C(Entity *, const u8 *);
extern void sub_806A6E8(Entity *);
extern bool8 sub_8047084(s32 itemFlag);
extern void sub_807FE9C(Entity *pokemon, Position *pos, int param_3, char param_4);
extern void sub_8045DB4(Position *, u32);
extern s32 sub_8052B8C(u32, const u8 *, u32);
bool8 sub_807EF48(void);
void sub_806A2BC(Entity *a0, u8 a1);
bool8 sub_805E874(void);
bool8 sub_80701A4(Entity *a0);
void sub_80647F0(Entity *a0);
void sub_805E738(Entity *a0);
void sub_803E708(s32 a0, s32 a1);
void sub_8040A78(void);
void sub_805E804(void);
void sub_8049ED4(void);
void sub_8064BE0(void);
void sub_8075680(u32);
void sub_8094C88(void);
void sub_8040A84(void);
void sub_8047158(void);
void sub_804AA60(void);
void sub_80532B4(void);
void sub_806A914(u8 a0, u8 a1, u8 a2);
void sub_8044C10(u8 a0);
u16 GetLeaderActionId(void);
void sub_80978C8(s16 a0);
void sub_8044C50(u16 a0);
void sub_805E2C4(Entity *leader);
bool8 sub_8094C48(void);
void sub_8052210(u8 a0);
bool8 sub_805EC4C(Entity *a0, u8 a1);
void sub_803E724(s32 a0);
void HandleTalkFieldAction(Entity *);
bool8 sub_8044B28(void);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
void ShowFieldMenu(u8 a0, bool8 a1);
bool8 sub_805EF60(Entity *a0, EntityInfo *a1);
s32 GetTeamMemberEntityIndex(Entity *pokemon);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
void DrawFieldMenu(u8 a0);
bool8 sub_805FD74(Entity * a0, struct UnkMenuBitsStruct *a1);
bool8 sub_805FD3C(struct UnkMenuBitsStruct *a0);
void sub_8060D24(UNUSED ActionContainer *a0);
bool8 sub_8060E38(Entity *a0);
void sub_8062D8C(ActionContainer *a0);
void sub_80637E8(ActionContainer *a0);
void sub_8063B54(ActionContainer *a0);
void sub_8063BB4(ActionContainer *a0);
void sub_806752C(ActionContainer *a0);
bool8 sub_8061A38(ActionContainer *a0, bool8 a1);
void sub_8063A70(ActionContainer *a0, bool8 a1);
void sub_8063CF0(ActionContainer *a0, bool8 a1);
void sub_8067768(UNUSED ActionContainer *a0);
void ShowTacticsMenu(ActionContainer *a0);
void sub_804A728(Position *pos, s32 a1, u8 a2, u8 a3);
extern bool8 sub_8071A8C(Entity *pokemon);
extern void sub_80643AC(Entity *pokemon);
extern u8 sub_8062F90(Entity *, u32, u32, u32, u32);

extern Entity *gLeaderPointer;

extern u8 gUnknown_202F22D;
extern u8 gUnknown_202F22C;
extern u8 gUnknown_202F230;
extern u8 gUnknown_202F231;
extern u8 gUnknown_202EE00;
extern u16 gUnknown_202F22E;

extern const u8 *gUnknown_80F8A84;
extern const u8 *gUnknown_80F8A6C;
extern const u8 *gUnknown_80F8ADC;
extern const u8 *gUnknown_80F8AB0;
extern const u8 *gUnknown_80F8B0C;
extern const u8 *gUnknown_80FD4B0;
extern const u8 *gUnknown_80F8A4C;
extern const u8 *gUnknown_80F8A28;
extern const u8 *gUnknown_8100208;
extern const u8 *gUnknown_80F9BD8;
extern const u8 *gUnknown_80F9C08;
extern const u8 *gUnknown_80F9C2C;
extern const u8 *gUnknown_80F9BB0;
extern const u8 *gUnknown_80FDE18;
extern const u8 *gUnknown_80F8B24;
extern const u8 *gTeamToolboxAPtr;
extern const u8 *gTeamToolboxBPtr;
extern const u8 *gFieldItemMenuGroundTextPtr;
extern const u8 *gUnknown_80FE940;
extern const u8 *gWhichTextPtr1;

#ifdef NONMATCHING
void sub_805D8C8(void) // https://decomp.me/scratch/96Sci
{
    struct UnkMenuBitsStruct r6;
    s32 i; //r4
    s32 j; // r3
    u32 r7;
    s32 r9;
    s32 r5;
    Entity *leader; // r10
    EntityInfo *leaderInfo; // r8
    u32 buttonsR1, buttonsR2; // r1 r2
    const u8 *msg; // r3
    bool32 r3;
    s32 r4;
    s32 prevMapOption; // r4

    // Stack
    u8 sp0[5];
    s32 frames;
    s32 var_38;
    unkDungeonGlobal_unk181E8_sub *unkPtr;

    unkPtr = &gDungeon->unk181e8;
    var_38 = 3;
    gDungeon->unk12 = 0;
    sub_806A2BC(GetLeader(), 1);
    if (sub_80701A4(GetLeader())) {
        sub_803E708(60, 16);
        return;
    }

    gDungeon->unk673 = 0;
    sub_8040A78();
    if (gDungeon->unk1 != 0) {
        gDungeon->unk1 = 0;
        if (!ShouldMonsterRunAwayAndShowEffect(GetLeader(), TRUE)) {
            sub_8044C10(1);
            sub_805E804();
            sub_80647F0(GetLeader());
            ResetRepeatTimers();
            ResetUnusedInputStruct();
            if (GetLeaderActionId() != 0) {
                return;
            }
        }
    }

    sub_806A914(1, 1, 1);
    while (1) {

        leader = GetLeader();
        leaderInfo = leader->axObj.info;

        sub_80978C8(leaderInfo->id);
        if (gDungeon->unk66C != 0) {
            if (sub_805E874() != 0) {
                leaderInfo->action.action = 2;
                leaderInfo->action.unk4[0].actionUseIndex = 0;
                break;
            }
            sub_805E804();
        }
        gUnknown_202F22D = 0;
        gUnknown_202F22C = 0;
        if (gDungeon->unk5C0 >= 0) {
            r6.a0_8 = 1;
        }
        else {
            r6.a0_8 = 0;
        }
        r6.a0_16 = 0;
        r6.a0_24 = 0;

        frames = 0;
        sub_8044C50(0);
        gUnknown_202F230 = 0;
        gUnknown_202F231 = 0;
        while (r6.a0_8 == 0) {
            bool32 alwaysFalse = FALSE;

            gUnknown_202F22E++;
            if (unkPtr->unk1821A != 0) {
                frames = 0;
            }
            else {
                frames++;
            }

            if (var_38 != 0 && --var_38 == 0) {
                sub_8075680(0);
            }

            sub_805E2C4(leader);
            r7 = 0;
            {
                s32 i;
                for (i = 0; i < 5; i++) {
                    sp0[i] = 0;
                }
            }

            if (gRealInputs.held & A_BUTTON && gRealInputs.held & B_BUTTON && FixedPointToInt(leaderInfo->belly) != 0) {
                sub_8044C50(1);
                gDungeon->unk673 = 1;
                break;
            }

            r9 = 0;
            if (gRealInputs.pressed & A_BUTTON) {
                if (gRealInputs.held & B_BUTTON) {
                    if (FixedPointToInt(leaderInfo->belly) != 0) {
                        sub_8044C50(1);
                        gDungeon->unk673 = 1;
                        break;
                    }
                }
                else if (ShouldMonsterRunAwayAndShowEffect(leader, TRUE)) {
                    SendMessage(leader, gUnknown_80FD4B0);
                    sub_8044C50(1);
                    gDungeon->unk673 = 1;
                    break;
                }
                else {
                    if (gRealInputs.held & L_BUTTON) {
                        register bool32 r7;

                        for (i = 0; i < MAX_MON_MOVES; i++) {
                            if (!(leaderInfo->moves[i].moveFlags & 1))
                                continue;
                            if (leaderInfo->moves[i].moveFlags & 8)
                                break;
                        }
                        if (i == MAX_MON_MOVES) {
                            SendMessage(leader, gUnknown_80F8A28);
                            break;
                        }

                        for (j = 0; j < MAX_MON_MOVES; j++) {

                            if (!(leaderInfo->moves[j].moveFlags & 1))
                                continue;
                            if (leaderInfo->moves[j].PP != 0)
                                break;
                        }
                        if (j == MAX_MON_MOVES) {
                            SetMonsterActionFields(&leaderInfo->action, 0x17);
                            break;
                        }

                        r7 = 0;
                        for (j = i; j < MAX_MON_MOVES; j++) {
                            if (j != i && !(leaderInfo->moves[j].moveFlags & 2))
                                break;
                            if (leaderInfo->moves[j].PP != 0) {
                                r7 = 1;
                                break;
                            }
                        }
                        if (r7 == 0) {
                            SendMessage(leader, gUnknown_80F8A4C);
                        }
                        else {
                            SetMonsterActionFields(&leaderInfo->action, 0x14);
                            leaderInfo->action.unk4[0].actionUseIndex = GetTeamMemberEntityIndex(leader);
                            leaderInfo->action.unk4[1].actionUseIndex = i;
                        }
                        break;
                    }
                    else {
                        if (!sub_805EF60(leader, leaderInfo)) {
                            SetMonsterActionFields(&leaderInfo->action, 0x32);
                        }
                        break;
                    }
                    break;
                }
            }

            if (gRealInputs.shortPress & B_BUTTON) {
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 0;
                break;
            }
            else if (sp0[1] != 0) { // Opens moves menu
                gDungeon->unk5C0 = 0;
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (sp0[2] != 0) { // Opens item menu
                gDungeon->unk5C0 = 1;
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (sp0[3] != 0) { // Opens pokemon menu
                gDungeon->unk5C0 = 2;
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (sp0[4] != 0) { // Opens regular menu

                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (frames > 0x707) { // Opens simple menu when idling

                r6.a0_8 = 1;
                r6.a0_16 = 1;
                r6.a0_24 = 0;
                break;
            }

            r4 = gGameOptionsRef->unk9;
            if (r4 == 0) {

                // 0 != 0 comparision here...
                if ((gRealInputs.pressed & B_BUTTON || (r7 == 0 && alwaysFalse != FALSE)) && unkPtr->unk1821A != 0) {
                    sub_804AA60();
                    gUnknown_202F22D = r4;
                    ResetRepeatTimers();
                    ResetUnusedInputStruct();
                }
            }
            if (gRealInputs.held & L_BUTTON) {
                if (gRealInputs.pressed & B_BUTTON) {
                    sub_80532B4();
                    ResetRepeatTimers();
                    ResetUnusedInputStruct();
                }
            }
            r4 = 0;
            if (gRealInputs.held & R_BUTTON) {
                if (gUnknown_202F22C == 0) {
                    gUnknown_202F22E = 0;
                }
                gUnknown_202F22C = 1;
            }
            else {
                gUnknown_202F22C = 0;
            }

            r3 = FALSE;
            if (gGameOptionsRef->unk9 == 0) {
                if (gRealInputs.shortPress & R_BUTTON || r9 != 0 || gRealInputs.pressed & START_BUTTON) {
                    r3 = TRUE;
                }
            }
            if (r3) {
                sub_805E738(leader);
                gUnknown_202F22D = 1;
                unkPtr->unk1821B = leaderInfo->action.direction;
                unkPtr->unk1821C = 0xFF;
                ResetRepeatTimers();
            }

            if ((gRealInputs.held & L_BUTTON) == L_BUTTON && (gRealInputs.pressed & R_BUTTON) == R_BUTTON) {
                r4 = 1;
            }
            if (sp0[0] != 0) {
                r4 = 1;
            }
            if (r4) {
                for (i = 0; i < INVENTORY_SIZE; i++) {
                    if (!(gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_EXISTS))
                        continue;
                    if (gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_SET) {
                        sub_8044C50(11);
                        leaderInfo->action.unk4[0].actionUseIndex = i + 1;
                        leaderInfo->action.unk4[0].lastItemThrowPosition.x = 0;
                        leaderInfo->action.unk4[0].lastItemThrowPosition.y = 0;
                        break;
                    }
                }
                if (leaderInfo->action.action != 0) {
                    break;
                }
            }

            // SELECT button
            if (!gDungeon->unk181e8.blinded && gGameOptionsRef->mapOption != 6 && gRealInputs.pressed & SELECT_BUTTON) {
                prevMapOption = gGameOptionsRef->mapOption;
                gUnknown_202EE00 = 1;
                gDungeon->unk181e8.unk18214 = 1;
                if (!sub_8094C48()) {
                    sub_8094C88();
                }
                sub_8052210(1);
                sub_8040A84();
                SetBGOBJEnableFlags(0x1E);
                sub_803E708(0xA, 0x2F);
                while (1) {
                    sub_803E46C(0x2F);
                    if (gRealInputs.pressed & SELECT_BUTTON)
                        break;
                    if (gRealInputs.pressed & B_BUTTON)
                        break;

                    if (gRealInputs.pressed & A_BUTTON) {
                        gUnknown_202EE00 = (gUnknown_202EE00 == 0) ? 1 : 0;
                        sub_8040A84();
                    }
                }
                gDungeon->unk181e8.unk18214 = 0;
                gGameOptionsRef->mapOption = prevMapOption;
                gUnknown_202EE00 = 1;
                sub_8040A84();
                SetBGOBJEnableFlags(0);
                sub_803E46C(0x2F);
                sub_803E46C(0x2F);
            }

            if (gDungeon->unk66D != 0 && gUnknown_202F22C == 0) {
                buttonsR1 = buttonsR2 = gRealInputs.pressed;
            }
            else {
                buttonsR1 = gRealInputs.held;
                buttonsR2 = (unkPtr->unk1821A == 0) ? gRealInputs.held : gRealInputs.pressed;
            }

            buttonsR1 &= DPAD_ANY;
            buttonsR2 &= DPAD_ANY;
            r5 = -1;
            if (buttonsR1 == (DPAD_UP | DPAD_RIGHT))
                r5 = 3;
            if (buttonsR1 == (DPAD_UP | DPAD_LEFT))
                r5 = 5;
            if (buttonsR1 == (DPAD_DOWN | DPAD_RIGHT))
                r5 = 1;
            if (buttonsR1 == (DPAD_DOWN | DPAD_LEFT))
                r5 = 7;

            if (buttonsR2 == DPAD_UP)
                r5 = 4;
            if (buttonsR2 == DPAD_DOWN)
                r5 = 0;
            if (buttonsR2 == DPAD_RIGHT)
                r5 = 2;
            if (buttonsR2 == DPAD_LEFT)
                r5 = 6;

            if (r5 >= 0 && (gUnknown_202F22C == 0 || (r5 & 1))) {
                bool32 aaa = 0;
                bool32 register r7 = (leaderInfo->action.direction != r5);
                leaderInfo->action.direction = r5 & 7;
                if (gUnknown_202F22D != 0) {
                    unkPtr->unk1821B = r5;
                    sub_806CDD4(leader, sub_806CEBC(leader), r5);
                }
                else {

                    r4 = 0;

                    msg = NULL;
                    if (sub_805EC4C(leader, 1))
                        break;

                    if (leaderInfo->immobilize.immobilizeStatus == 2) {
                        msg = gUnknown_80F8A84, r4 = 1;
                    }
                    else if (leaderInfo->immobilize.immobilizeStatus == 7) {
                        msg = gUnknown_80F8A6C, r4 = 1;
                    }
                    else if (leaderInfo->immobilize.immobilizeStatus == 5) {
                        msg = gUnknown_80F8AB0, r4 = 1;
                    }
                    else if (leaderInfo->immobilize.immobilizeStatus == 3) {
                        msg = gUnknown_80F8ADC, r4 = 1;
                    }
                    else if (leaderInfo->immobilize.immobilizeStatus == 4) {
                        msg = gUnknown_80F8B0C, r4 = 1;
                    }
                    if (!CanMoveInDirection(leader, r5))
                        r4 |= 2;

                    if (r7) {
                        sub_806CDD4(leader, sub_806CEBC(leader), r5);
                    }
                    // Note to self: r7 is set to 2, but I guess it's because the variable is not used anymore?
                    //r7 = 2;
                    if (!(r4 & 2)) {

                        //r9 = 1;
                        if (r4 & 1) {
                            if (msg != NULL) {
                                SendMessage(leader, msg);
                            }
                            sub_8044C50(1);
                            gDungeon->unk673 = 1; // or r9?
                            break;
                        }
                        sub_8044C50(2);

                        // mov r0, cmp r0, #0 wtf
                        if ((gRealInputs.held & B_BUTTON || aaa != 0) && FixedPointToInt(leaderInfo->belly) != 0) {
                            if (leader->axObj.info->volatileStatus.volatileStatus != 2) {
                                gDungeon->unk66C = 1; // or r9?
                            }
                            leaderInfo->action.unk4[0].actionUseIndex = 0;
                            break;
                        }
                        leaderInfo->action.unk4[0].actionUseIndex = 1;
                        break;
                    }

                    if (r4 & 1)
                        sub_803E724(0x23);
                }
            }

            sub_803E46C(0xF);
        }

        if (unkPtr->unk1821A != 0) {
            sub_804AA60();
        }

        if (leaderInfo->action.action == 0x2D || leaderInfo->action.action == 0x13) {
            HandleTalkFieldAction(leader);
            if (sub_8044B28())
                break;
            sub_8044C50(0);
        }
        else if ((r6.a0_8) == 0) {
            gDungeon->unk66D = 0;
            if (leaderInfo->action.action != 0) {
                if (!IsNotAttacking(leader, FALSE)) {
                    sub_803E46C(0xF);
                }
                break;
            }
            sub_803E46C(0xF);
        }
        else {
            u8 r2;
            sub_803E46C(0xF);
            sub_8047158();
            r2 = (r6.a0_16 == 0) ? 1 : 0;
            ShowFieldMenu(r2, r6.a0_24);
            ResetRepeatTimers();
            ResetUnusedInputStruct();
            gUnknown_202F22D = 0;
            unkPtr->unk1821A = 0;
            sub_804AA60();
            if (sub_8044B28())
                break;
            if (leaderInfo->action.action != 0) {
                if (leaderInfo->action.action == 0x2B) {
                    gDungeon->unk4 = 1;
                    gDungeon->unk3 = 1;
                }
                if (leaderInfo->action.action == 0x2E) {
                    gDungeon->unk4 = 1;
                    gDungeon->unk3 = 0;
                }
                break;
            }
            sub_803E46C(0xF);
            if (gDungeon->unk4 != 0)
                break;
        }
    }
}

#else
NAKED void sub_805D8C8(void)
{
    asm_unified("push {r4-r7,lr}\n"
"mov r7, r10\n"
"mov r6, r9\n"
"mov r5, r8\n"
"push {r5-r7}\n"
"sub sp, 0x24\n"
"ldr r4, _0805D90C\n"
"ldr r1, [r4]\n"
"ldr r0, _0805D910\n"
"adds r0, r1, r0\n"
"str r0, [sp, 0x10]\n"
"movs r2, 0x3\n"
"str r2, [sp, 0xC]\n"
"movs r5, 0\n"
"movs r0, 0\n"
"strh r0, [r1, 0x12]\n"
"bl GetLeader\n"
"movs r1, 0x1\n"
"bl sub_806A2BC\n"
"bl GetLeader\n"
"bl sub_80701A4\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0805D928\n"
"movs r0, 0x3C\n"
"movs r1, 0x10\n"
"bl sub_803E708\n"
"bl _0805E2B0\n"
".align 2, 0\n"
"_0805D90C: .4byte gDungeon\n"
"_0805D910: .4byte 0x000181e8\n"
"_0805D914:\n"
"mov r1, r8\n"
"adds r1, 0x44\n"
"movs r2, 0\n"
"movs r0, 0x2\n"
"strh r0, [r1]\n"
"mov r0, r8\n"
"adds r0, 0x48\n"
"strb r2, [r0]\n"
"bl _0805E2B0\n"
"_0805D928:\n"
"ldr r0, [r4]\n"
"ldr r3, _0805D9D4\n"
"adds r0, r3\n"
"strb r5, [r0]\n"
"bl sub_8040A78\n"
"ldr r1, [r4]\n"
"ldrb r0, [r1, 0x1]\n"
"cmp r0, 0\n"
"beq _0805D976\n"
"strb r5, [r1, 0x1]\n"
"bl GetLeader\n"
"movs r1, 0x1\n"
"bl ShouldMonsterRunAwayAndShowEffect\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0805D976\n"
"movs r0, 0x1\n"
"bl sub_8044C10\n"
"bl sub_805E804\n"
"bl GetLeader\n"
"bl sub_80647F0\n"
"bl ResetRepeatTimers\n"
"bl ResetUnusedInputStruct\n"
"bl GetLeaderActionId\n"
"lsls r0, 16\n"
"cmp r0, 0\n"
"beq _0805D976\n"
"bl _0805E2B0\n"
"_0805D976:\n"
"movs r0, 0x1\n"
"movs r1, 0x1\n"
"movs r2, 0x1\n"
"bl sub_806A914\n"
"_0805D980:\n"
"bl GetLeader\n"
"mov r10, r0\n"
"ldr r5, [r0, 0x70]\n"
"mov r8, r5\n"
"movs r1, 0x2\n"
"ldrsh r0, [r5, r1]\n"
"bl sub_80978C8\n"
"ldr r2, _0805D9D8\n"
"ldr r0, [r2]\n"
"ldr r3, _0805D9DC\n"
"adds r0, r3\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0805D9AE\n"
"bl sub_805E874\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0805D914\n"
"bl sub_805E804\n"
"_0805D9AE:\n"
"ldr r0, _0805D9E0\n"
"movs r1, 0\n"
"strb r1, [r0]\n"
"ldr r0, _0805D9E4\n"
"strb r1, [r0]\n"
"ldr r5, _0805D9D8\n"
"ldr r0, [r5]\n"
"movs r1, 0xB8\n"
"lsls r1, 3\n"
"adds r0, r1\n"
"ldr r0, [r0]\n"
"cmp r0, 0\n"
"bge _0805D9CA\n"
"b _0805DAE8\n"
"_0805D9CA:\n"
"ldr r0, _0805D9E8\n"
"ands r6, r0\n"
"movs r2, 0x1\n"
"orrs r6, r2\n"
"b _0805DAEC\n"
".align 2, 0\n"
"_0805D9D4: .4byte 0x00000673\n"
"_0805D9D8: .4byte gDungeon\n"
"_0805D9DC: .4byte 0x0000066c\n"
"_0805D9E0: .4byte gUnknown_202F22D\n"
"_0805D9E4: .4byte gUnknown_202F22C\n"
"_0805D9E8: .4byte 0xffffff00\n"
"_0805D9EC:\n"
"movs r0, 0x1\n"
"bl sub_8044C50\n"
"ldr r3, _0805DA00\n"
"ldr r0, [r3]\n"
"ldr r5, _0805DA04\n"
"adds r0, r5\n"
"strb r4, [r0]\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805DA00: .4byte gDungeon\n"
"_0805DA04: .4byte 0x00000673\n"
"_0805DA08:\n"
"ldr r0, _0805DA14\n"
"ldr r1, [r0]\n"
"mov r0, r10\n"
"bl SendMessage\n"
"b _0805DBDA\n"
".align 2, 0\n"
"_0805DA14: .4byte gUnknown_80FD4B0\n"
"_0805DA18:\n"
"ldr r0, _0805DA1C\n"
"b _0805DCBC\n"
".align 2, 0\n"
"_0805DA1C: .4byte gUnknown_80F8A28\n"
"_0805DA20:\n"
"ldr r0, [sp, 0x1C]\n"
"movs r1, 0x17\n"
"bl SetMonsterActionFields\n"
"b _0805E1AE\n"
"_0805DA2A:\n"
"ldr r0, _0805DA38\n"
"ands r6, r0\n"
"movs r3, 0x1\n"
"orrs r6, r3\n"
"ldr r0, _0805DA3C\n"
"ands r6, r0\n"
"b _0805DAD6\n"
".align 2, 0\n"
"_0805DA38: .4byte 0xffffff00\n"
"_0805DA3C: .4byte 0xffff00ff\n"
"_0805DA40:\n"
"ldr r5, _0805DA58\n"
"ldr r0, [r5]\n"
"movs r2, 0xB8\n"
"lsls r2, 3\n"
"adds r0, r2\n"
"str r1, [r0]\n"
"ldr r0, _0805DA5C\n"
"ands r6, r0\n"
"movs r3, 0x1\n"
"orrs r6, r3\n"
"b _0805DAA8\n"
".align 2, 0\n"
"_0805DA58: .4byte gDungeon\n"
"_0805DA5C: .4byte 0xffffff00\n"
"_0805DA60:\n"
"ldr r5, _0805DA78\n"
"ldr r0, [r5]\n"
"movs r1, 0xB8\n"
"lsls r1, 3\n"
"adds r0, r1\n"
"movs r2, 0x1\n"
"str r2, [r0]\n"
"ldr r0, _0805DA7C\n"
"ands r6, r0\n"
"orrs r6, r2\n"
"b _0805DAA8\n"
".align 2, 0\n"
"_0805DA78: .4byte gDungeon\n"
"_0805DA7C: .4byte 0xffffff00\n"
"_0805DA80:\n"
"ldr r3, _0805DA98\n"
"ldr r0, [r3]\n"
"movs r5, 0xB8\n"
"lsls r5, 3\n"
"adds r0, r5\n"
"str r2, [r0]\n"
"ldr r0, _0805DA9C\n"
"ands r6, r0\n"
"movs r0, 0x1\n"
"orrs r6, r0\n"
"b _0805DAA8\n"
".align 2, 0\n"
"_0805DA98: .4byte gDungeon\n"
"_0805DA9C: .4byte 0xffffff00\n"
"_0805DAA0:\n"
"ldr r0, _0805DAB8\n"
"ands r6, r0\n"
"movs r1, 0x1\n"
"orrs r6, r1\n"
"_0805DAA8:\n"
"ldr r0, _0805DABC\n"
"ands r6, r0\n"
"ldr r0, _0805DAC0\n"
"ands r6, r0\n"
"movs r0, 0x80\n"
"lsls r0, 9\n"
"orrs r6, r0\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805DAB8: .4byte 0xffffff00\n"
"_0805DABC: .4byte 0xffff00ff\n"
"_0805DAC0: .4byte 0xff00ffff\n"
"_0805DAC4:\n"
"ldr r0, _0805DADC\n"
"ands r6, r0\n"
"movs r2, 0x1\n"
"orrs r6, r2\n"
"ldr r0, _0805DAE0\n"
"ands r6, r0\n"
"movs r0, 0x80\n"
"lsls r0, 1\n"
"orrs r6, r0\n"
"_0805DAD6:\n"
"ldr r0, _0805DAE4\n"
"ands r6, r0\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805DADC: .4byte 0xffffff00\n"
"_0805DAE0: .4byte 0xffff00ff\n"
"_0805DAE4: .4byte 0xff00ffff\n"
"_0805DAE8:\n"
"ldr r0, _0805DB3C\n"
"ands r6, r0\n"
"_0805DAEC:\n"
"ldr r0, _0805DB40\n"
"ands r6, r0\n"
"ldr r0, _0805DB44\n"
"ands r6, r0\n"
"movs r3, 0\n"
"str r3, [sp, 0x8]\n"
"movs r0, 0\n"
"bl sub_8044C50\n"
"ldr r0, _0805DB48\n"
"mov r5, sp\n"
"ldrb r5, [r5, 0x8]\n"
"strb r5, [r0]\n"
"ldr r0, _0805DB4C\n"
"mov r1, sp\n"
"ldrb r1, [r1, 0x8]\n"
"strb r1, [r0]\n"
"lsls r0, r6, 24\n"
"mov r2, r8\n"
"adds r2, 0x44\n"
"str r2, [sp, 0x1C]\n"
"str r0, [sp, 0x14]\n"
"ldr r3, [sp, 0x10]\n"
"adds r3, 0x32\n"
"str r3, [sp, 0x18]\n"
"cmp r0, 0\n"
"beq _0805DB24\n"
"b _0805E1AE\n"
"_0805DB24:\n"
"ldr r0, _0805DB50\n"
"ldrh r1, [r0]\n"
"adds r1, 0x1\n"
"strh r1, [r0]\n"
"ldr r5, [sp, 0x18]\n"
"ldrb r0, [r5]\n"
"cmp r0, 0\n"
"beq _0805DB54\n"
"movs r0, 0\n"
"str r0, [sp, 0x8]\n"
"b _0805DB5A\n"
".align 2, 0\n"
"_0805DB3C: .4byte 0xffffff00\n"
"_0805DB40: .4byte 0xffff00ff\n"
"_0805DB44: .4byte 0xff00ffff\n"
"_0805DB48: .4byte gUnknown_202F230\n"
"_0805DB4C: .4byte gUnknown_202F231\n"
"_0805DB50: .4byte gUnknown_202F22E\n"
"_0805DB54:\n"
"ldr r1, [sp, 0x8]\n"
"adds r1, 0x1\n"
"str r1, [sp, 0x8]\n"
"_0805DB5A:\n"
"ldr r2, [sp, 0xC]\n"
"cmp r2, 0\n"
"beq _0805DB6E\n"
"subs r2, 0x1\n"
"str r2, [sp, 0xC]\n"
"cmp r2, 0\n"
"bne _0805DB6E\n"
"movs r0, 0\n"
"bl sub_8075680\n"
"_0805DB6E:\n"
"mov r0, r10\n"
"bl sub_805E2C4\n"
"movs r7, 0\n"
"movs r1, 0\n"
"add r0, sp, 0x4\n"
"_0805DB7A:\n"
"strb r1, [r0]\n"
"subs r0, 0x1\n"
"cmp r0, sp\n"
"bge _0805DB7A\n"
"ldr r0, _0805DBEC\n"
"ldrh r1, [r0]\n"
"movs r4, 0x1\n"
"movs r0, 0x1\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DBAA\n"
"movs r0, 0x2\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DBAA\n"
"movs r0, 0x9E\n"
"lsls r0, 1\n"
"add r0, r8\n"
"ldr r0, [r0]\n"
"bl FixedPointToInt\n"
"cmp r0, 0\n"
"beq _0805DBAA\n"
"b _0805D9EC\n"
"_0805DBAA:\n"
"movs r3, 0\n"
"mov r9, r3\n"
"ldr r4, _0805DBEC\n"
"ldrh r1, [r4, 0x2]\n"
"movs r5, 0x1\n"
"movs r0, 0x1\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DBBE\n"
"b _0805DD02\n"
"_0805DBBE:\n"
"ldrh r1, [r4]\n"
"movs r0, 0x2\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DBF8\n"
"movs r0, 0x9E\n"
"lsls r0, 1\n"
"add r0, r8\n"
"ldr r0, [r0]\n"
"bl FixedPointToInt\n"
"cmp r0, 0\n"
"bne _0805DBDA\n"
"b _0805DD02\n"
"_0805DBDA:\n"
"movs r0, 0x1\n"
"bl sub_8044C50\n"
"ldr r1, _0805DBF0\n"
"ldr r0, [r1]\n"
"ldr r2, _0805DBF4\n"
"adds r0, r2\n"
"strb r5, [r0]\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805DBEC: .4byte gRealInputs\n"
"_0805DBF0: .4byte gDungeon\n"
"_0805DBF4: .4byte 0x00000673\n"
"_0805DBF8:\n"
"mov r0, r10\n"
"movs r1, 0x1\n"
"bl ShouldMonsterRunAwayAndShowEffect\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0805DC08\n"
"b _0805DA08\n"
"_0805DC08:\n"
"ldrh r0, [r4]\n"
"movs r3, 0x80\n"
"lsls r3, 2\n"
"adds r1, r3, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DCE8\n"
"movs r4, 0\n"
"movs r2, 0x8C\n"
"lsls r2, 1\n"
"add r2, r8\n"
"movs r3, 0x8\n"
"_0805DC20:\n"
"ldrb r1, [r2]\n"
"movs r0, 0x1\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DC32\n"
"adds r0, r3, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DC3A\n"
"_0805DC32:\n"
"adds r2, 0x8\n"
"adds r4, 0x1\n"
"cmp r4, 0x3\n"
"ble _0805DC20\n"
"_0805DC3A:\n"
"cmp r4, 0x4\n"
"bne _0805DC40\n"
"b _0805DA18\n"
"_0805DC40:\n"
"movs r3, 0\n"
"movs r5, 0x8C\n"
"lsls r5, 1\n"
"movs r7, 0x1\n"
"mov r2, r8\n"
"_0805DC4A:\n"
"lsls r0, r3, 3\n"
"add r0, r8\n"
"adds r0, r5\n"
"ldrb r1, [r0]\n"
"adds r0, r7, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DC66\n"
"movs r1, 0x8E\n"
"lsls r1, 1\n"
"adds r0, r2, r1\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"bne _0805DC6E\n"
"_0805DC66:\n"
"adds r2, 0x8\n"
"adds r3, 0x1\n"
"cmp r3, 0x3\n"
"ble _0805DC4A\n"
"_0805DC6E:\n"
"cmp r3, 0x4\n"
"bne _0805DC74\n"
"b _0805DA20\n"
"_0805DC74:\n"
"movs r7, 0\n"
"adds r3, r4, 0\n"
"cmp r4, 0x3\n"
"bgt _0805DCB6\n"
"lsls r0, r4, 3\n"
"adds r2, r0, 0\n"
"add r2, r8\n"
"mov r12, r2\n"
"movs r5, 0x8E\n"
"lsls r5, 1\n"
"adds r0, r5\n"
"mov r1, r8\n"
"adds r2, r0, r1\n"
"movs r5, 0x2\n"
"_0805DC90:\n"
"ldrb r0, [r2]\n"
"cmp r0, 0\n"
"bne _0805DCCC\n"
"movs r0, 0x8\n"
"add r12, r0\n"
"adds r2, 0x8\n"
"adds r3, 0x1\n"
"cmp r3, 0x3\n"
"bgt _0805DCB6\n"
"cmp r3, r4\n"
"beq _0805DC90\n"
"movs r0, 0x8C\n"
"lsls r0, 1\n"
"add r0, r12\n"
"ldrb r1, [r0]\n"
"adds r0, r5, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DC90\n"
"_0805DCB6:\n"
"cmp r7, 0\n"
"bne _0805DCCC\n"
"ldr r0, _0805DCC8\n"
"_0805DCBC:\n"
"ldr r1, [r0]\n"
"mov r0, r10\n"
"bl SendMessage\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805DCC8: .4byte gUnknown_80F8A4C\n"
"_0805DCCC:\n"
"ldr r0, [sp, 0x1C]\n"
"movs r1, 0x14\n"
"bl SetMonsterActionFields\n"
"mov r0, r10\n"
"bl GetTeamMemberEntityIndex\n"
"mov r1, r8\n"
"adds r1, 0x48\n"
"strb r0, [r1]\n"
"mov r0, r8\n"
"adds r0, 0x50\n"
"strb r4, [r0]\n"
"b _0805E1AE\n"
"_0805DCE8:\n"
"mov r0, r10\n"
"mov r1, r8\n"
"bl sub_805EF60\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0805DCF8\n"
"b _0805E1AE\n"
"_0805DCF8:\n"
"ldr r0, [sp, 0x1C]\n"
"movs r1, 0x32\n"
"bl SetMonsterActionFields\n"
"b _0805E1AE\n"
"_0805DD02:\n"
"ldr r3, _0805DDC8\n"
"ldrh r1, [r3, 0x6]\n"
"movs r2, 0x2\n"
"adds r0, r2, 0\n"
"ands r0, r1\n"
"lsls r0, 16\n"
"lsrs r1, r0, 16\n"
"cmp r1, 0\n"
"beq _0805DD16\n"
"b _0805DA2A\n"
"_0805DD16:\n"
"mov r0, sp\n"
"ldrb r0, [r0, 0x1]\n"
"cmp r0, 0\n"
"beq _0805DD20\n"
"b _0805DA40\n"
"_0805DD20:\n"
"mov r0, sp\n"
"ldrb r0, [r0, 0x2]\n"
"cmp r0, 0\n"
"beq _0805DD2A\n"
"b _0805DA60\n"
"_0805DD2A:\n"
"mov r0, sp\n"
"ldrb r0, [r0, 0x3]\n"
"cmp r0, 0\n"
"beq _0805DD34\n"
"b _0805DA80\n"
"_0805DD34:\n"
"mov r0, sp\n"
"ldrb r0, [r0, 0x4]\n"
"cmp r0, 0\n"
"beq _0805DD3E\n"
"b _0805DAA0\n"
"_0805DD3E:\n"
"ldr r0, _0805DDCC\n"
"ldr r1, [sp, 0x8]\n"
"cmp r1, r0\n"
"ble _0805DD48\n"
"b _0805DAC4\n"
"_0805DD48:\n"
"ldr r0, _0805DDD0\n"
"ldr r0, [r0]\n"
"ldrb r4, [r0, 0x9]\n"
"cmp r4, 0\n"
"bne _0805DD7E\n"
"ldrh r1, [r3, 0x2]\n"
"adds r0, r2, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DD66\n"
"cmp r7, 0\n"
"bne _0805DD7E\n"
"movs r2, 0\n"
"cmp r2, 0\n"
"beq _0805DD7E\n"
"_0805DD66:\n"
"ldr r3, [sp, 0x18]\n"
"ldrb r0, [r3]\n"
"cmp r0, 0\n"
"beq _0805DD7E\n"
"bl sub_804AA60\n"
"ldr r0, _0805DDD4\n"
"strb r4, [r0]\n"
"bl ResetRepeatTimers\n"
"bl ResetUnusedInputStruct\n"
"_0805DD7E:\n"
"ldr r2, _0805DDC8\n"
"ldrh r0, [r2]\n"
"movs r5, 0x80\n"
"lsls r5, 2\n"
"adds r1, r5, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DDA4\n"
"ldrh r1, [r2, 0x2]\n"
"movs r0, 0x2\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DDA4\n"
"bl sub_80532B4\n"
"bl ResetRepeatTimers\n"
"bl ResetUnusedInputStruct\n"
"_0805DDA4:\n"
"movs r4, 0\n"
"ldr r0, _0805DDC8\n"
"ldrh r0, [r0]\n"
"movs r2, 0x80\n"
"lsls r2, 1\n"
"adds r1, r2, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DDFA\n"
"ldr r1, _0805DDD8\n"
"ldrb r0, [r1]\n"
"cmp r0, 0\n"
"bne _0805DDC2\n"
"ldr r0, _0805DDDC\n"
"strh r4, [r0]\n"
"_0805DDC2:\n"
"movs r3, 0x1\n"
"strb r3, [r1]\n"
"b _0805DDFE\n"
".align 2, 0\n"
"_0805DDC8: .4byte gRealInputs\n"
"_0805DDCC: .4byte 0x00000707\n"
"_0805DDD0: .4byte gGameOptionsRef\n"
"_0805DDD4: .4byte gUnknown_202F22D\n"
"_0805DDD8: .4byte gUnknown_202F22C\n"
"_0805DDDC: .4byte gUnknown_202F22E\n"
"_0805DDE0:\n"
"movs r0, 0xB\n"
"bl sub_8044C50\n"
"adds r2, r4, 0x1\n"
"mov r0, r8\n"
"adds r0, 0x48\n"
"movs r1, 0\n"
"strb r2, [r0]\n"
"adds r0, 0x4\n"
"strh r1, [r0]\n"
"adds r0, 0x2\n"
"strh r1, [r0]\n"
"b _0805DE92\n"
"_0805DDFA:\n"
"ldr r0, _0805DEF8\n"
"strb r4, [r0]\n"
"_0805DDFE:\n"
"movs r3, 0\n"
"ldr r0, _0805DEFC\n"
"ldr r0, [r0]\n"
"ldrb r0, [r0, 0x9]\n"
"cmp r0, 0\n"
"bne _0805DE2C\n"
"ldr r2, _0805DF00\n"
"ldrh r0, [r2, 0x6]\n"
"movs r5, 0x80\n"
"lsls r5, 1\n"
"adds r1, r5, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DE2A\n"
"mov r0, r9\n"
"cmp r0, 0\n"
"bne _0805DE2A\n"
"ldrh r1, [r2, 0x2]\n"
"movs r0, 0x8\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DE2C\n"
"_0805DE2A:\n"
"movs r3, 0x1\n"
"_0805DE2C:\n"
"cmp r3, 0\n"
"beq _0805DE54\n"
"mov r0, r10\n"
"bl sub_805E738\n"
"ldr r0, _0805DF04\n"
"movs r1, 0x1\n"
"strb r1, [r0]\n"
"mov r0, r8\n"
"adds r0, 0x46\n"
"ldrb r0, [r0]\n"
"ldr r1, [sp, 0x10]\n"
"adds r1, 0x33\n"
"strb r0, [r1]\n"
"ldr r1, [sp, 0x10]\n"
"adds r1, 0x34\n"
"movs r0, 0xFF\n"
"strb r0, [r1]\n"
"bl ResetRepeatTimers\n"
"_0805DE54:\n"
"ldr r0, _0805DF00\n"
"ldr r1, [r0]\n"
"ldr r0, _0805DF08\n"
"ands r1, r0\n"
"cmp r1, r0\n"
"bne _0805DE62\n"
"movs r4, 0x1\n"
"_0805DE62:\n"
"mov r0, sp\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0805DE6C\n"
"movs r4, 0x1\n"
"_0805DE6C:\n"
"cmp r4, 0\n"
"beq _0805DE9C\n"
"movs r4, 0\n"
"ldr r0, _0805DF0C\n"
"ldr r2, [r0]\n"
"movs r3, 0x10\n"
"_0805DE78:\n"
"ldrb r1, [r2]\n"
"movs r0, 0x1\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DE8A\n"
"adds r0, r3, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DDE0\n"
"_0805DE8A:\n"
"adds r2, 0x4\n"
"adds r4, 0x1\n"
"cmp r4, 0x13\n"
"ble _0805DE78\n"
"_0805DE92:\n"
"ldr r2, [sp, 0x1C]\n"
"ldrh r0, [r2]\n"
"cmp r0, 0\n"
"beq _0805DE9C\n"
"b _0805E1AE\n"
"_0805DE9C:\n"
"ldr r5, _0805DF10\n"
"ldr r3, [r5]\n"
"ldr r1, _0805DF14\n"
"adds r0, r3, r1\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"bne _0805DF82\n"
"ldr r0, _0805DEFC\n"
"ldr r2, [r0]\n"
"ldrb r0, [r2, 0x4]\n"
"cmp r0, 0x6\n"
"beq _0805DF82\n"
"ldr r0, _0805DF00\n"
"ldrh r1, [r0, 0x2]\n"
"movs r0, 0x4\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DF82\n"
"ldrb r4, [r2, 0x4]\n"
"ldr r0, _0805DF18\n"
"movs r2, 0x1\n"
"strb r2, [r0]\n"
"ldr r5, _0805DF1C\n"
"adds r0, r3, r5\n"
"strb r2, [r0]\n"
"bl sub_8094C48\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0805DEDC\n"
"bl sub_8094C88\n"
"_0805DEDC:\n"
"movs r0, 0x1\n"
"bl sub_8052210\n"
"bl sub_8040A84\n"
"movs r0, 0x1E\n"
"bl SetBGOBJEnableFlags\n"
"movs r0, 0xA\n"
"movs r1, 0x2F\n"
"bl sub_803E708\n"
"b _0805DF3A\n"
".align 2, 0\n"
"_0805DEF8: .4byte gUnknown_202F22C\n"
"_0805DEFC: .4byte gGameOptionsRef\n"
"_0805DF00: .4byte gRealInputs\n"
"_0805DF04: .4byte gUnknown_202F22D\n"
"_0805DF08: .4byte 0x01000200\n"
"_0805DF0C: .4byte gTeamInventoryRef\n"
"_0805DF10: .4byte gDungeon\n"
"_0805DF14: .4byte 0x0001820a\n"
"_0805DF18: .4byte gUnknown_202EE00\n"
"_0805DF1C: .4byte 0x00018214\n"
"_0805DF20:\n"
"movs r0, 0x1\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DF3A\n"
"ldr r2, _0805DFA0\n"
"movs r1, 0\n"
"ldrb r0, [r2]\n"
"cmp r0, 0\n"
"bne _0805DF34\n"
"movs r1, 0x1\n"
"_0805DF34:\n"
"strb r1, [r2]\n"
"bl sub_8040A84\n"
"_0805DF3A:\n"
"movs r0, 0x2F\n"
"bl sub_803E46C\n"
"ldr r0, _0805DFA4\n"
"ldrh r1, [r0, 0x2]\n"
"movs r0, 0x4\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805DF54\n"
"movs r0, 0x2\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0805DF20\n"
"_0805DF54:\n"
"ldr r1, _0805DFA8\n"
"ldr r0, [r1]\n"
"ldr r2, _0805DFAC\n"
"adds r0, r2\n"
"movs r1, 0\n"
"strb r1, [r0]\n"
"ldr r0, _0805DFB0\n"
"ldr r0, [r0]\n"
"strb r4, [r0, 0x4]\n"
"ldr r0, _0805DFA0\n"
"movs r3, 0x1\n"
"strb r3, [r0]\n"
"bl sub_8040A84\n"
"movs r0, 0\n"
"bl SetBGOBJEnableFlags\n"
"movs r0, 0x2F\n"
"bl sub_803E46C\n"
"movs r0, 0x2F\n"
"bl sub_803E46C\n"
"_0805DF82:\n"
"ldr r5, _0805DFA8\n"
"ldr r0, [r5]\n"
"ldr r1, _0805DFB4\n"
"adds r0, r1\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0805DFBC\n"
"ldr r0, _0805DFB8\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"bne _0805DFBC\n"
"ldr r0, _0805DFA4\n"
"ldrh r2, [r0, 0x2]\n"
"adds r1, r2, 0\n"
"b _0805DFCC\n"
".align 2, 0\n"
"_0805DFA0: .4byte gUnknown_202EE00\n"
"_0805DFA4: .4byte gRealInputs\n"
"_0805DFA8: .4byte gDungeon\n"
"_0805DFAC: .4byte 0x00018214\n"
"_0805DFB0: .4byte gGameOptionsRef\n"
"_0805DFB4: .4byte 0x0000066d\n"
"_0805DFB8: .4byte gUnknown_202F22C\n"
"_0805DFBC:\n"
"ldr r3, _0805E05C\n"
"ldrh r1, [r3]\n"
"ldr r2, [sp, 0x18]\n"
"ldrb r0, [r2]\n"
"adds r2, r1, 0\n"
"cmp r0, 0\n"
"beq _0805DFCC\n"
"ldrh r2, [r3, 0x2]\n"
"_0805DFCC:\n"
"movs r0, 0xF0\n"
"ands r1, r0\n"
"ands r2, r0\n"
"movs r5, 0x1\n"
"negs r5, r5\n"
"cmp r1, 0x50\n"
"bne _0805DFDC\n"
"movs r5, 0x3\n"
"_0805DFDC:\n"
"cmp r1, 0x60\n"
"bne _0805DFE2\n"
"movs r5, 0x5\n"
"_0805DFE2:\n"
"cmp r1, 0x90\n"
"bne _0805DFE8\n"
"movs r5, 0x1\n"
"_0805DFE8:\n"
"cmp r1, 0xA0\n"
"bne _0805DFEE\n"
"movs r5, 0x7\n"
"_0805DFEE:\n"
"cmp r2, 0x40\n"
"bne _0805DFF4\n"
"movs r5, 0x4\n"
"_0805DFF4:\n"
"cmp r2, 0x80\n"
"bne _0805DFFA\n"
"movs r5, 0\n"
"_0805DFFA:\n"
"cmp r2, 0x10\n"
"bne _0805E000\n"
"movs r5, 0x2\n"
"_0805E000:\n"
"cmp r2, 0x20\n"
"bne _0805E006\n"
"movs r5, 0x6\n"
"_0805E006:\n"
"cmp r5, 0\n"
"bge _0805E00C\n"
"b _0805E1A0\n"
"_0805E00C:\n"
"ldr r0, _0805E060\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0805E020\n"
"adds r0, r5, 0\n"
"movs r3, 0x1\n"
"ands r0, r3\n"
"cmp r0, 0\n"
"bne _0805E020\n"
"b _0805E1A0\n"
"_0805E020:\n"
"mov r2, r8\n"
"adds r2, 0x46\n"
"ldrb r1, [r2]\n"
"eors r1, r5\n"
"negs r0, r1\n"
"orrs r0, r1\n"
"lsrs r7, r0, 31\n"
"movs r1, 0x7\n"
"adds r0, r5, 0\n"
"ands r0, r1\n"
"strb r0, [r2]\n"
"ldr r0, _0805E064\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"beq _0805E068\n"
"ldr r0, [sp, 0x10]\n"
"adds r0, 0x33\n"
"strb r5, [r0]\n"
"mov r0, r10\n"
"bl sub_806CEBC\n"
"adds r1, r0, 0\n"
"lsls r1, 24\n"
"lsrs r1, 24\n"
"mov r0, r10\n"
"adds r2, r5, 0\n"
"bl sub_806CDD4\n"
"b _0805E1A0\n"
".align 2, 0\n"
"_0805E05C: .4byte gRealInputs\n"
"_0805E060: .4byte gUnknown_202F22C\n"
"_0805E064: .4byte gUnknown_202F22D\n"
"_0805E068:\n"
"movs r4, 0\n"
"movs r3, 0\n"
"mov r0, r10\n"
"movs r1, 0x1\n"
"str r3, [sp, 0x20]\n"
"bl sub_805EC4C\n"
"lsls r0, 24\n"
"ldr r3, [sp, 0x20]\n"
"cmp r0, 0\n"
"beq _0805E080\n"
"b _0805E1AE\n"
"_0805E080:\n"
"mov r0, r8\n"
"adds r0, 0xB0\n"
"ldrb r0, [r0]\n"
"cmp r0, 0x2\n"
"bne _0805E094\n"
"ldr r0, _0805E090\n"
"b _0805E0BE\n"
".align 2, 0\n"
"_0805E090: .4byte gUnknown_80F8A84\n"
"_0805E094:\n"
"cmp r0, 0x7\n"
"bne _0805E0A0\n"
"ldr r0, _0805E09C\n"
"b _0805E0BE\n"
".align 2, 0\n"
"_0805E09C: .4byte gUnknown_80F8A6C\n"
"_0805E0A0:\n"
"cmp r0, 0x5\n"
"bne _0805E0AC\n"
"ldr r0, _0805E0A8\n"
"b _0805E0BE\n"
".align 2, 0\n"
"_0805E0A8: .4byte gUnknown_80F8AB0\n"
"_0805E0AC:\n"
"cmp r0, 0x3\n"
"bne _0805E0B8\n"
"ldr r0, _0805E0B4\n"
"b _0805E0BE\n"
".align 2, 0\n"
"_0805E0B4: .4byte gUnknown_80F8ADC\n"
"_0805E0B8:\n"
"cmp r0, 0x4\n"
"bne _0805E0C2\n"
"ldr r0, _0805E128\n"
"_0805E0BE:\n"
"ldr r3, [r0]\n"
"movs r4, 0x1\n"
"_0805E0C2:\n"
"mov r0, r10\n"
"adds r1, r5, 0\n"
"str r3, [sp, 0x20]\n"
"bl CanMoveInDirection\n"
"lsls r0, 24\n"
"ldr r3, [sp, 0x20]\n"
"cmp r0, 0\n"
"bne _0805E0D8\n"
"movs r0, 0x2\n"
"orrs r4, r0\n"
"_0805E0D8:\n"
"cmp r7, 0\n"
"beq _0805E0F4\n"
"mov r0, r10\n"
"str r3, [sp, 0x20]\n"
"bl sub_806CEBC\n"
"adds r1, r0, 0\n"
"lsls r1, 24\n"
"lsrs r1, 24\n"
"mov r0, r10\n"
"adds r2, r5, 0\n"
"bl sub_806CDD4\n"
"ldr r3, [sp, 0x20]\n"
"_0805E0F4:\n"
"movs r7, 0x2\n"
"adds r0, r4, 0\n"
"ands r0, r7\n"
"cmp r0, 0\n"
"bne _0805E192\n"
"movs r5, 0x1\n"
"mov r9, r5\n"
"ands r5, r4\n"
"cmp r5, 0\n"
"beq _0805E134\n"
"cmp r3, 0\n"
"beq _0805E114\n"
"mov r0, r10\n"
"adds r1, r3, 0\n"
"bl SendMessage\n"
"_0805E114:\n"
"movs r0, 0x1\n"
"bl sub_8044C50\n"
"ldr r1, _0805E12C\n"
"ldr r0, [r1]\n"
"ldr r2, _0805E130\n"
"adds r0, r2\n"
"mov r3, r9\n"
"strb r3, [r0]\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805E128: .4byte gUnknown_80F8B0C\n"
"_0805E12C: .4byte gDungeon\n"
"_0805E130: .4byte 0x00000673\n"
"_0805E134:\n"
"movs r0, 0x2\n"
"bl sub_8044C50\n"
"ldr r0, _0805E17C\n"
"ldrh r1, [r0]\n"
"adds r0, r7, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0805E14C\n"
"movs r0, 0\n"
"cmp r0, 0\n"
"beq _0805E188\n"
"_0805E14C:\n"
"movs r0, 0x9E\n"
"lsls r0, 1\n"
"add r0, r8\n"
"ldr r0, [r0]\n"
"bl FixedPointToInt\n"
"cmp r0, 0\n"
"beq _0805E188\n"
"mov r1, r10\n"
"ldr r0, [r1, 0x70]\n"
"adds r0, 0xBC\n"
"ldrb r0, [r0]\n"
"cmp r0, 0x2\n"
"beq _0805E174\n"
"ldr r2, _0805E180\n"
"ldr r0, [r2]\n"
"ldr r3, _0805E184\n"
"adds r0, r3\n"
"mov r1, r9\n"
"strb r1, [r0]\n"
"_0805E174:\n"
"mov r0, r8\n"
"adds r0, 0x48\n"
"strb r5, [r0]\n"
"b _0805E1AE\n"
".align 2, 0\n"
"_0805E17C: .4byte gRealInputs\n"
"_0805E180: .4byte gDungeon\n"
"_0805E184: .4byte 0x0000066c\n"
"_0805E188:\n"
"mov r0, r8\n"
"adds r0, 0x48\n"
"movs r2, 0x1\n"
"strb r2, [r0]\n"
"b _0805E1AE\n"
"_0805E192:\n"
"movs r3, 0x1\n"
"ands r4, r3\n"
"cmp r4, 0\n"
"beq _0805E1A0\n"
"movs r0, 0x23\n"
"bl sub_803E724\n"
"_0805E1A0:\n"
"movs r0, 0xF\n"
"bl sub_803E46C\n"
"ldr r5, [sp, 0x14]\n"
"cmp r5, 0\n"
"bne _0805E1AE\n"
"b _0805DB24\n"
"_0805E1AE:\n"
"ldr r1, [sp, 0x18]\n"
"ldrb r0, [r1]\n"
"cmp r0, 0\n"
"beq _0805E1BA\n"
"bl sub_804AA60\n"
"_0805E1BA:\n"
"ldr r4, [sp, 0x1C]\n"
"ldrh r0, [r4]\n"
"cmp r0, 0x2D\n"
"beq _0805E1C6\n"
"cmp r0, 0x13\n"
"bne _0805E1E0\n"
"_0805E1C6:\n"
"mov r0, r10\n"
"bl HandleTalkFieldAction\n"
"bl sub_8044B28\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0805E2B0\n"
"movs r0, 0\n"
"bl sub_8044C50\n"
"bl _0805D980\n"
"_0805E1E0:\n"
"lsls r0, r6, 24\n"
"lsrs r1, r0, 24\n"
"cmp r1, 0\n"
"bne _0805E222\n"
"ldr r2, _0805E210\n"
"ldr r0, [r2]\n"
"ldr r3, _0805E214\n"
"adds r0, r3\n"
"strb r1, [r0]\n"
"ldrh r0, [r4]\n"
"cmp r0, 0\n"
"beq _0805E218\n"
"mov r0, r10\n"
"movs r1, 0\n"
"bl IsNotAttacking\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0805E2B0\n"
"movs r0, 0xF\n"
"bl sub_803E46C\n"
"b _0805E2B0\n"
".align 2, 0\n"
"_0805E210: .4byte gDungeon\n"
"_0805E214: .4byte 0x0000066d\n"
"_0805E218:\n"
"movs r0, 0xF\n"
"bl sub_803E46C\n"
"bl _0805D980\n"
"_0805E222:\n"
"movs r0, 0xF\n"
"bl sub_803E46C\n"
"bl sub_8047158\n"
"movs r2, 0\n"
"lsrs r0, r6, 8\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"bne _0805E238\n"
"movs r2, 0x1\n"
"_0805E238:\n"
"lsrs r1, r6, 16\n"
"lsls r1, 24\n"
"lsrs r1, 24\n"
"adds r0, r2, 0\n"
"bl ShowFieldMenu\n"
"bl ResetRepeatTimers\n"
"bl ResetUnusedInputStruct\n"
"ldr r1, _0805E294\n"
"movs r0, 0\n"
"strb r0, [r1]\n"
"movs r0, 0\n"
"ldr r5, [sp, 0x18]\n"
"strb r0, [r5]\n"
"bl sub_804AA60\n"
"bl sub_8044B28\n"
"lsls r0, 24\n"
"lsrs r1, r0, 24\n"
"cmp r1, 0\n"
"bne _0805E2B0\n"
"ldrh r0, [r4]\n"
"cmp r0, 0\n"
"beq _0805E29C\n"
"cmp r0, 0x2B\n"
"bne _0805E27E\n"
"ldr r2, _0805E298\n"
"ldr r0, [r2]\n"
"movs r3, 0x1\n"
"strb r3, [r0, 0x4]\n"
"ldr r0, [r2]\n"
"strb r3, [r0, 0x3]\n"
"_0805E27E:\n"
"ldr r5, [sp, 0x1C]\n"
"ldrh r0, [r5]\n"
"cmp r0, 0x2E\n"
"bne _0805E2B0\n"
"ldr r2, _0805E298\n"
"ldr r0, [r2]\n"
"movs r3, 0x1\n"
"strb r3, [r0, 0x4]\n"
"ldr r0, [r2]\n"
"strb r1, [r0, 0x3]\n"
"b _0805E2B0\n"
".align 2, 0\n"
"_0805E294: .4byte gUnknown_202F22D\n"
"_0805E298: .4byte gDungeon\n"
"_0805E29C:\n"
"movs r0, 0xF\n"
"bl sub_803E46C\n"
"ldr r5, _0805E2C0\n"
"ldr r0, [r5]\n"
"ldrb r0, [r0, 0x4]\n"
"cmp r0, 0\n"
"bne _0805E2B0\n"
"bl _0805D980\n"
"_0805E2B0:\n"
"add sp, 0x24\n"
"pop {r3-r5}\n"
"mov r8, r3\n"
"mov r9, r4\n"
"mov r10, r5\n"
"pop {r4-r7}\n"
"pop {r0}\n"
"bx r0\n"
".align 2, 0\n"
"_0805E2C0: .4byte gDungeon\n");
}

#endif

/* TODO: leaving this for now as it uses weird sprite OAM logic
void sub_805E2C4(Entity *leader)
{
    unkDungeonGlobal_unk181E8_sub *unkPtr;

    unkPtr = &gDungeon->unk181e8;
    if (gUnknown_202F22C == 0) {

    }
}
*/

NAKED void sub_805E2C4(Entity *leader)
{
    asm_unified(	"\n"
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x28\n"
"	str r0, [sp, 0x10]\n"
"	ldr r0, _0805E47C\n"
"	ldr r1, [r0]\n"
"	ldr r0, _0805E480\n"
"	adds r0, r1, r0\n"
"	str r0, [sp, 0x14]\n"
"	ldr r0, _0805E484\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _0805E2E6\n"
"	b _0805E4C4\n"
"_0805E2E6:\n"
"	movs r1, 0\n"
"	str r1, [sp, 0x18]\n"
"	mov r7, sp\n"
"	ldr r2, _0805E488\n"
"	mov r10, r2\n"
"_0805E2F0:\n"
"	ldrh r0, [r7]\n"
"	ldr r3, _0805E48C\n"
"	adds r1, r3, 0\n"
"	ands r1, r0\n"
"	ldr r0, [sp]\n"
"	mov r4, r10\n"
"	ands r0, r4\n"
"	orrs r0, r1\n"
"	str r0, [sp]\n"
"	ldrh r1, [r7]\n"
"	mov r2, r10\n"
"	ands r2, r0\n"
"	orrs r2, r1\n"
"	str r2, [sp]\n"
"	ldrh r0, [r7]\n"
"	ldr r5, _0805E490\n"
"	adds r1, r5, 0\n"
"	ands r1, r0\n"
"	mov r0, r10\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	str r0, [sp]\n"
"	ldrh r2, [r7]\n"
"	mov r1, r10\n"
"	ands r1, r0\n"
"	orrs r1, r2\n"
"	str r1, [sp]\n"
"	ldrh r2, [r7]\n"
"	ldr r0, _0805E494\n"
"	ands r0, r2\n"
"	mov r3, r10\n"
"	ands r3, r1\n"
"	orrs r3, r0\n"
"	str r3, [sp]\n"
"	ldrh r1, [r7]\n"
"	movs r0, 0x80\n"
"	lsls r0, 3\n"
"	orrs r0, r1\n"
"	movs r6, 0\n"
"	orrs r0, r6\n"
"	mov r2, r10\n"
"	ands r2, r3\n"
"	orrs r2, r0\n"
"	str r2, [sp]\n"
"	ldrh r0, [r7]\n"
"	ldr r3, _0805E498\n"
"	adds r1, r3, 0\n"
"	ands r1, r0\n"
"	mov r0, r10\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	str r0, [sp]\n"
"	ldrh r1, [r7]\n"
"	mov r2, r10\n"
"	ands r2, r0\n"
"	orrs r2, r1\n"
"	str r2, [sp]\n"
"	ldrh r0, [r7]\n"
"	ldr r4, _0805E49C\n"
"	adds r1, r4, 0\n"
"	ands r1, r0\n"
"	mov r0, r10\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	str r0, [sp]\n"
"	ldrh r1, [r7]\n"
"	mov r2, r10\n"
"	ands r2, r0\n"
"	orrs r2, r1\n"
"	str r2, [sp]\n"
"	ldrh r1, [r7]\n"
"	ldr r0, _0805E4A0\n"
"	ands r0, r1\n"
"	mov r1, r10\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	str r1, [sp]\n"
"	ldrh r2, [r7]\n"
"	mov r0, r10\n"
"	ands r0, r1\n"
"	orrs r0, r2\n"
"	str r0, [sp]\n"
"	ldr r1, _0805E4A4\n"
"	ldr r5, [sp, 0x18]\n"
"	lsls r0, r5, 3\n"
"	adds r0, r1\n"
"	mov r12, r0\n"
"	ldrb r1, [r0, 0x4]\n"
"	negs r0, r1\n"
"	orrs r0, r1\n"
"	asrs r1, r0, 31\n"
"	movs r0, 0x8\n"
"	ands r1, r0\n"
"	mov r6, r12\n"
"	ldrb r0, [r6, 0x5]\n"
"	cmp r0, 0\n"
"	beq _0805E3B4\n"
"	adds r1, 0x10\n"
"_0805E3B4:\n"
"	movs r0, 0x1F\n"
"	ands r1, r0\n"
"	lsls r1, 9\n"
"	ldrh r3, [r7, 0x2]\n"
"	ldr r2, _0805E4A8\n"
"	adds r0, r2, 0\n"
"	ands r3, r0\n"
"	orrs r3, r1\n"
"	ldr r4, _0805E4A0\n"
"	ands r3, r4\n"
"	strh r3, [r7, 0x2]\n"
"	ldr r2, _0805E4AC\n"
"	ldrh r0, [r7, 0x4]\n"
"	movs r5, 0xFC\n"
"	lsls r5, 8\n"
"	adds r1, r5, 0\n"
"	ands r0, r1\n"
"	orrs r0, r2\n"
"	movs r6, 0\n"
"	orrs r0, r6\n"
"	movs r1, 0x80\n"
"	lsls r1, 4\n"
"	ldr r2, _0805E494\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	orrs r0, r6\n"
"	ldr r4, _0805E4B0\n"
"	mov r9, r4\n"
"	ands r0, r4\n"
"	strh r0, [r7, 0x4]\n"
"	ldrh r4, [r7, 0x6]\n"
"	ldr r5, _0805E4B4\n"
"	adds r0, r5, 0\n"
"	ands r4, r0\n"
"	ldr r6, _0805E4B8\n"
"	adds r0, r6, 0\n"
"	ands r4, r0\n"
"	strh r4, [r7, 0x6]\n"
"	mov r0, r12\n"
"	movs r1, 0\n"
"	ldrsh r5, [r0, r1]\n"
"	lsls r2, r5, 2\n"
"	adds r2, r5\n"
"	lsls r2, 1\n"
"	ldr r6, _0805E4BC\n"
"	mov r8, r6\n"
"	movs r1, 0\n"
"	ldrsh r0, [r6, r1]\n"
"	lsrs r1, r0, 31\n"
"	adds r0, r1\n"
"	asrs r0, 1\n"
"	movs r6, 0x7\n"
"	ands r0, r6\n"
"	muls r0, r5\n"
"	adds r0, r2\n"
"	adds r0, 0x74\n"
"	ldr r1, _0805E4C0\n"
"	ands r0, r1\n"
"	movs r2, 0xFE\n"
"	lsls r2, 8\n"
"	adds r1, r2, 0\n"
"	ands r3, r1\n"
"	orrs r3, r0\n"
"	strh r3, [r7, 0x2]\n"
"	mov r5, r12\n"
"	movs r0, 0x2\n"
"	ldrsh r3, [r5, r0]\n"
"	lsls r2, r3, 2\n"
"	adds r2, r3\n"
"	lsls r2, 1\n"
"	mov r1, r8\n"
"	movs r5, 0\n"
"	ldrsh r0, [r1, r5]\n"
"	lsrs r1, r0, 31\n"
"	adds r0, r1\n"
"	asrs r0, 1\n"
"	ands r0, r6\n"
"	muls r0, r3\n"
"	adds r0, r2\n"
"	adds r0, 0x52\n"
"	mov r6, r9\n"
"	ands r0, r6\n"
"	lsls r0, 4\n"
"	movs r1, 0xF\n"
"	ands r4, r1\n"
"	orrs r4, r0\n"
"	strh r4, [r7, 0x6]\n"
"	mov r0, sp\n"
"	adds r1, 0xF1\n"
"	movs r2, 0\n"
"	movs r3, 0\n"
"	bl AddSprite\n"
"	ldr r2, [sp, 0x18]\n"
"	adds r2, 0x1\n"
"	str r2, [sp, 0x18]\n"
"	cmp r2, 0x3\n"
"	bgt _0805E47A\n"
"	b _0805E2F0\n"
"_0805E47A:\n"
"	b _0805E6AC\n"
"	.align 2, 0\n"
"_0805E47C: .4byte gDungeon\n"
"_0805E480: .4byte 0x000181e8\n"
"_0805E484: .4byte gUnknown_202F22C\n"
"_0805E488: .4byte 0xffff0000\n"
"_0805E48C: .4byte 0x0000feff\n"
"_0805E490: .4byte 0x0000fdff\n"
"_0805E494: .4byte 0x0000f3ff\n"
"_0805E498: .4byte 0x0000efff\n"
"_0805E49C: .4byte 0x0000dfff\n"
"_0805E4A0: .4byte 0x00003fff\n"
"_0805E4A4: .4byte gUnknown_8106AC8\n"
"_0805E4A8: .4byte 0x0000c1ff\n"
"_0805E4AC: .4byte 0x00000213\n"
"_0805E4B0: .4byte 0x00000fff\n"
"_0805E4B4: .4byte 0x0000fffe\n"
"_0805E4B8: .4byte 0x0000fffd\n"
"_0805E4BC: .4byte gUnknown_202F22E\n"
"_0805E4C0: .4byte 0x000001ff\n"
"_0805E4C4:\n"
"	ldr r3, _0805E6E4\n"
"	adds r0, r1, r3\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _0805E4D0\n"
"	b _0805E6AC\n"
"_0805E4D0:\n"
"	ldr r4, _0805E6E8\n"
"	adds r0, r1, r4\n"
"	ldrb r0, [r0]\n"
"	str r0, [sp, 0x1C]\n"
"	cmp r0, 0x7\n"
"	bls _0805E4DE\n"
"	b _0805E6AC\n"
"_0805E4DE:\n"
"	ldr r0, _0805E6EC\n"
"	ldrb r0, [r0]\n"
"	movs r7, 0x1\n"
"	cmp r0, 0\n"
"	beq _0805E4F2\n"
"	ldr r0, _0805E6F0\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	beq _0805E4F2\n"
"	movs r7, 0x3\n"
"_0805E4F2:\n"
"	ldr r5, _0805E6F4\n"
"	mov r12, r5\n"
"	ldr r6, [sp, 0x1C]\n"
"	lsls r5, r6, 1\n"
"	adds r3, r5, r6\n"
"	lsls r3, 2\n"
"	add r3, r12\n"
"	movs r0, 0\n"
"	ldrsh r4, [r3, r0]\n"
"	lsls r1, r4, 2\n"
"	adds r1, r4\n"
"	lsls r1, 1\n"
"	ldr r0, _0805E6F8\n"
"	movs r6, 0\n"
"	ldrsh r2, [r0, r6]\n"
"	lsrs r0, r2, 31\n"
"	adds r2, r0\n"
"	asrs r2, 1\n"
"	movs r0, 0x7\n"
"	ands r2, r0\n"
"	adds r0, r4, 0\n"
"	muls r0, r2\n"
"	adds r0, r1\n"
"	adds r0, 0x74\n"
"	str r0, [sp, 0x20]\n"
"	movs r1, 0x2\n"
"	ldrsh r0, [r3, r1]\n"
"	lsls r1, r0, 2\n"
"	adds r1, r0\n"
"	lsls r1, 1\n"
"	muls r0, r2\n"
"	adds r0, r1\n"
"	adds r0, 0x52\n"
"	mov r10, r0\n"
"	str r5, [sp, 0x24]\n"
"	cmp r7, 0\n"
"	bne _0805E53E\n"
"	b _0805E6AC\n"
"_0805E53E:\n"
"	add r6, sp, 0x8\n"
"	ldr r2, _0805E6FC\n"
"	mov r8, r2\n"
"	mov r9, r7\n"
"_0805E546:\n"
"	ldrh r0, [r6]\n"
"	ldr r3, _0805E700\n"
"	adds r1, r3, 0\n"
"	ands r1, r0\n"
"	ldr r0, [sp, 0x8]\n"
"	mov r4, r8\n"
"	ands r0, r4\n"
"	orrs r0, r1\n"
"	str r0, [sp, 0x8]\n"
"	ldrh r1, [r6]\n"
"	mov r2, r8\n"
"	ands r2, r0\n"
"	orrs r2, r1\n"
"	str r2, [sp, 0x8]\n"
"	ldrh r0, [r6]\n"
"	ldr r5, _0805E704\n"
"	adds r1, r5, 0\n"
"	ands r1, r0\n"
"	mov r0, r8\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	str r0, [sp, 0x8]\n"
"	ldrh r2, [r6]\n"
"	mov r1, r8\n"
"	ands r1, r0\n"
"	orrs r1, r2\n"
"	str r1, [sp, 0x8]\n"
"	ldrh r2, [r6]\n"
"	ldr r0, _0805E708\n"
"	ands r0, r2\n"
"	mov r3, r8\n"
"	ands r3, r1\n"
"	orrs r3, r0\n"
"	str r3, [sp, 0x8]\n"
"	ldrh r1, [r6]\n"
"	movs r0, 0x80\n"
"	lsls r0, 3\n"
"	orrs r0, r1\n"
"	movs r1, 0\n"
"	orrs r0, r1\n"
"	mov r2, r8\n"
"	ands r2, r3\n"
"	orrs r2, r0\n"
"	str r2, [sp, 0x8]\n"
"	ldrh r0, [r6]\n"
"	ldr r3, _0805E70C\n"
"	adds r1, r3, 0\n"
"	ands r1, r0\n"
"	mov r0, r8\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	str r0, [sp, 0x8]\n"
"	ldrh r1, [r6]\n"
"	mov r2, r8\n"
"	ands r2, r0\n"
"	orrs r2, r1\n"
"	str r2, [sp, 0x8]\n"
"	ldrh r0, [r6]\n"
"	ldr r4, _0805E710\n"
"	adds r1, r4, 0\n"
"	ands r1, r0\n"
"	mov r0, r8\n"
"	ands r0, r2\n"
"	orrs r0, r1\n"
"	str r0, [sp, 0x8]\n"
"	ldrh r1, [r6]\n"
"	mov r2, r8\n"
"	ands r2, r0\n"
"	orrs r2, r1\n"
"	str r2, [sp, 0x8]\n"
"	ldrh r1, [r6]\n"
"	ldr r0, _0805E714\n"
"	ands r0, r1\n"
"	mov r1, r8\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	str r1, [sp, 0x8]\n"
"	ldrh r2, [r6]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	orrs r0, r2\n"
"	str r0, [sp, 0x8]\n"
"	ldr r5, [sp, 0x24]\n"
"	ldr r1, [sp, 0x1C]\n"
"	adds r0, r5, r1\n"
"	lsls r2, r0, 2\n"
"	ldr r3, _0805E6F4\n"
"	adds r7, r2, r3\n"
"	ldrb r1, [r7, 0x8]\n"
"	negs r0, r1\n"
"	orrs r0, r1\n"
"	asrs r1, r0, 31\n"
"	movs r0, 0x8\n"
"	ands r1, r0\n"
"	ldrb r0, [r7, 0x9]\n"
"	cmp r0, 0\n"
"	beq _0805E60A\n"
"	adds r1, 0x10\n"
"_0805E60A:\n"
"	movs r0, 0x1F\n"
"	ands r1, r0\n"
"	lsls r1, 9\n"
"	ldrh r3, [r6, 0x2]\n"
"	ldr r4, _0805E718\n"
"	adds r0, r4, 0\n"
"	ands r3, r0\n"
"	orrs r3, r1\n"
"	ldr r5, _0805E714\n"
"	ands r3, r5\n"
"	strh r3, [r6, 0x2]\n"
"	ldr r1, _0805E71C\n"
"	adds r0, r2, r1\n"
"	ldr r2, [r0]\n"
"	ldr r0, _0805E720\n"
"	ands r2, r0\n"
"	ldrh r0, [r6, 0x4]\n"
"	movs r4, 0xFC\n"
"	lsls r4, 8\n"
"	adds r1, r4, 0\n"
"	ands r0, r1\n"
"	orrs r0, r2\n"
"	movs r1, 0x80\n"
"	lsls r1, 4\n"
"	ldr r5, _0805E708\n"
"	ands r0, r5\n"
"	orrs r0, r1\n"
"	movs r1, 0\n"
"	orrs r0, r1\n"
"	movs r2, 0xF\n"
"	mov r12, r2\n"
"	ldr r4, _0805E724\n"
"	ands r0, r4\n"
"	strh r0, [r6, 0x4]\n"
"	ldrh r1, [r6, 0x6]\n"
"	ldr r5, _0805E728\n"
"	adds r0, r5, 0\n"
"	ands r1, r0\n"
"	ldr r2, _0805E72C\n"
"	adds r0, r2, 0\n"
"	ands r1, r0\n"
"	ldr r0, _0805E730\n"
"	ldr r5, [sp, 0x20]\n"
"	ands r0, r5\n"
"	movs r5, 0xFE\n"
"	lsls r5, 8\n"
"	adds r2, r5, 0\n"
"	ands r3, r2\n"
"	orrs r3, r0\n"
"	strh r3, [r6, 0x2]\n"
"	mov r0, r10\n"
"	ands r0, r4\n"
"	lsls r0, 4\n"
"	mov r2, r12\n"
"	ands r1, r2\n"
"	orrs r1, r0\n"
"	strh r1, [r6, 0x6]\n"
"	adds r0, r6, 0\n"
"	movs r1, 0x80\n"
"	lsls r1, 1\n"
"	movs r2, 0\n"
"	movs r3, 0\n"
"	bl AddSprite\n"
"	movs r3, 0\n"
"	ldrsh r0, [r7, r3]\n"
"	lsls r0, 2\n"
"	ldr r4, [sp, 0x20]\n"
"	adds r4, r0\n"
"	str r4, [sp, 0x20]\n"
"	movs r5, 0x2\n"
"	ldrsh r0, [r7, r5]\n"
"	lsls r0, 2\n"
"	add r10, r0\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	add r9, r0\n"
"	mov r1, r9\n"
"	cmp r1, 0\n"
"	beq _0805E6AC\n"
"	b _0805E546\n"
"_0805E6AC:\n"
"	ldr r4, _0805E734\n"
"	ldrb r0, [r4]\n"
"	cmp r0, 0\n"
"	beq _0805E6D4\n"
"	ldr r2, [sp, 0x14]\n"
"	adds r2, 0x34\n"
"	ldr r3, [sp, 0x14]\n"
"	adds r3, 0x33\n"
"	ldrb r1, [r3]\n"
"	ldrb r0, [r2]\n"
"	cmp r0, r1\n"
"	beq _0805E6D4\n"
"	strb r1, [r2]\n"
"	ldr r0, [sp, 0x10]\n"
"	adds r0, 0x4\n"
"	ldrb r1, [r3]\n"
"	ldrb r3, [r4]\n"
"	movs r2, 0\n"
"	bl sub_804A728\n"
"_0805E6D4:\n"
"	add sp, 0x28\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0805E6E4: .4byte 0x0001821a\n"
"_0805E6E8: .4byte 0x0001821b\n"
"_0805E6EC: .4byte gUnknown_202F231\n"
"_0805E6F0: .4byte gUnknown_202F230\n"
"_0805E6F4: .4byte gUnknown_8106AE8\n"
"_0805E6F8: .4byte gUnknown_202F22E\n"
"_0805E6FC: .4byte 0xffff0000\n"
"_0805E700: .4byte 0x0000feff\n"
"_0805E704: .4byte 0x0000fdff\n"
"_0805E708: .4byte 0x0000f3ff\n"
"_0805E70C: .4byte 0x0000efff\n"
"_0805E710: .4byte 0x0000dfff\n"
"_0805E714: .4byte 0x00003fff\n"
"_0805E718: .4byte 0x0000c1ff\n"
"_0805E71C: .4byte gUnknown_8106AEC\n"
"_0805E720: .4byte 0x000003ff\n"
"_0805E724: .4byte 0x00000fff\n"
"_0805E728: .4byte 0x0000fffe\n"
"_0805E72C: .4byte 0x0000fffd\n"
"_0805E730: .4byte 0x000001ff\n"
"_0805E734: .4byte gUnknown_202F22D"
);
}

void sub_805E738(Entity *a0)
{
    Tile *tile;
    s32 i, j;
    EntityInfo *entityInfo = a0->axObj.info;
    if (entityInfo->eyesightStatus.eyesightStatus != 1 && entityInfo->eyesightStatus.eyesightStatus != 2) {
        // What???
        for (i = 0; i < 1; i++) {
            bool8 r9 = FALSE;
            u32 direction = entityInfo->action.direction;
            direction++;
            for (j = 1; j < 8; j++, direction++) {
                direction &= DIRECTION_MASK;
                tile = GetTile(a0->pos.x + gAdjacentTileOffsets[direction].x, a0->pos.y + gAdjacentTileOffsets[direction].y);
                if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER) {
                    EntityInfo *tileMonsterInfo = tile->monster->axObj.info;
                    if (CanSeeTarget(a0, tile->monster)) {
                        if (i != 0 || tileMonsterInfo->isNotTeamMember) {
                            r9 = TRUE;
                            break;
                        }
                    }
                }
            }
            if (r9) {
                a0->axObj.info->action.direction = direction & DIRECTION_MASK;
                sub_806CDD4(a0, sub_806CEBC(a0), direction);
                break;
            }
        }
    }
}

void sub_805E804(void)
{
    gDungeon->unk66D |= gDungeon->unk66C;
    gDungeon->unk66C = 0;
    while (gDungeon->unk66D != 0 && gRealInputs.held & R_BUTTON) {
        sub_803E46C(0x54);
    }
}

extern bool8 sub_8070F14(Entity * pokemon, s32 direction);
bool8 sub_805EC2C(Entity *a0, s32 x, s32 y);

bool8 sub_805E874(void)
{
    u8 r7, r8, r0;
    s32 i, j, k;
    s32 xArray[3];
    s32 yArray[3];
    Dungeon *dungeon = gDungeon;
    Entity *leader = GetLeader();
    s32 direction = leader->axObj.info->action.direction;
    s32 x = leader->pos.x;
    s32 y = leader->pos.y;
    Tile *leaderTile = GetTile(x, y);
    s32 xAdjacent = x + gAdjacentTileOffsets[direction].x;
    s32 yAdjacent = y + gAdjacentTileOffsets[direction].y;
    s32 room;

    if (dungeon->unk66C == 0)
        return FALSE;
    if (leaderTile->object != NULL)
        return FALSE;
    if (sub_805EC2C(leader, x, y))
        return FALSE;
    if (!sub_8070F14(leader, direction))
        return FALSE;

    room = leaderTile->room;
    if (room == 0xFF) {
        if (GetTile(xAdjacent, yAdjacent)->room != 0xFF)
            return FALSE;
    }
    else {
        if (leaderTile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
            return FALSE;
    }

    for (j = -1; j < 2; j++) {
        Tile *tile = GetTile(x + gAdjacentTileOffsets[(direction + j) & 7].x, y + gAdjacentTileOffsets[(direction + j) & 7].y);
        if (tile->monster != NULL)
            return FALSE;
        if (tile->terrainType & TERRAIN_TYPE_STAIRS)
            return FALSE;
    }

    xArray[0] = x + gAdjacentTileOffsets[(direction + 3) & 7].x;
    xArray[1] = x + gAdjacentTileOffsets[(direction + 4) & 7].x;
    xArray[2] = x + gAdjacentTileOffsets[(direction + 5) & 7].x;

    yArray[0] = y + gAdjacentTileOffsets[(direction + 3) & 7].y;
    yArray[1] = y + gAdjacentTileOffsets[(direction + 4) & 7].y;
    yArray[2] = y + gAdjacentTileOffsets[(direction + 5) & 7].y;

    for (i = -1; i < 2; i++) {
        for (j = -1; j < 2; j++) {
            Tile *tile = GetTile(x + i, y + j);
            if (tile->object != NULL) {
                for (k = 0; k < 3; k++) {
                    if (x + i == xArray[k] && y + j == yArray[k])
                        break;
                }
                if (k == 3 && GetEntityType(tile->object) == ENTITY_ITEM)
                    return FALSE;
            }

            if (direction & 1) {
                // This doesn't really have to be called two times...
                if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP && GetEntityType(tile->object) == ENTITY_TRAP) {
                    if (tile->object->isVisible)
                        return FALSE;
                    if (gDungeon->unk181e8.unk1820F)
                        return FALSE;
                }
            }
            else if (i == 0 || j == 0) {
                if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP) {
                    if (tile->object->isVisible)
                        return FALSE;
                    if (gDungeon->unk181e8.unk1820F)
                        return FALSE;
                }
            }

            if (i != 0 && j != 0) continue;
            if (i == 0 && j == 0) continue;

            if ((xArray[1] != x + i || yArray[1] != y + j) && !sub_805EC2C(leader, x + i, y + j) && room != 0xFF && room != tile->room)
                return FALSE;
        }
    }

    if (!(direction & 1)) {
        if (direction == 0 || direction == 4) {
            r8 = sub_805EC2C(leader, x - 1, y - 1);
            r7 = sub_805EC2C(leader, x - 1, y);
            r0 = sub_805EC2C(leader, x - 1, y + 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }

            r8 = sub_805EC2C(leader, x + 1, y - 1);
            r7 = sub_805EC2C(leader, x + 1, y);
            r0 = sub_805EC2C(leader, x + 1, y + 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }
        }
        else {
            r8 = sub_805EC2C(leader, x - 1, y - 1);
            r7 = sub_805EC2C(leader, x, y - 1);
            r0 = sub_805EC2C(leader, x + 1, y - 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }

            r8 = sub_805EC2C(leader, x - 1, y + 1);
            r7 = sub_805EC2C(leader, x, y + 1);
            r0 = sub_805EC2C(leader, x + 1, y + 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }
        }
    }

    return TRUE;
}

bool8 sub_805EC2C(Entity *a0, s32 x, s32 y)
{
    Position pos = {.x = x, .y = y};
    return sub_8070564(a0, &pos);
}

bool8 sub_805EC4C(Entity *a0, u8 a1)
{
    Position pos;
    Tile *tile;
    EntityInfo *tileMonsterInfo;
    Entity *tileMonster;
    EntityInfo *entityInfo = a0->axObj.info;

    pos.x = a0->pos.x + gAdjacentTileOffsets[entityInfo->action.direction].x;
    pos.y = a0->pos.y + gAdjacentTileOffsets[entityInfo->action.direction].y;
    tile = GetTile(pos.x, pos.y);
    tileMonster = tile->monster;

    if (tileMonster == NULL) return FALSE;
    if (GetEntityType(tileMonster) != ENTITY_MONSTER) return FALSE;

    tileMonsterInfo = tileMonster->axObj.info;
    if (tileMonsterInfo->isNotTeamMember
        && (tileMonsterInfo->shopkeeper != 1 && tileMonsterInfo->shopkeeper != 2)
        && !IsClientOrTeamBase(tileMonsterInfo->joinedAt.joinedAt)
        && tileMonsterInfo->clientType != 1) {
        return FALSE;
    }

    if (entityInfo->immobilize.immobilizeStatus == STATUS_SHADOW_HOLD) return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_FROZEN) return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_CONSTRICTION) return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_INGRAIN) return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAP) return FALSE;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAPPED) return FALSE;

    if (tileMonsterInfo->immobilize.immobilizeStatus == STATUS_SHADOW_HOLD) return FALSE;
    if (tileMonsterInfo->immobilize.immobilizeStatus == STATUS_FROZEN) return FALSE;
    if (tileMonsterInfo->immobilize.immobilizeStatus == STATUS_CONSTRICTION) return FALSE;
    if (tileMonsterInfo->immobilize.immobilizeStatus == STATUS_INGRAIN) return FALSE;
    if (tileMonsterInfo->immobilize.immobilizeStatus == STATUS_WRAP) return FALSE;
    if (tileMonsterInfo->immobilize.immobilizeStatus == STATUS_WRAPPED) return FALSE;

    if (entityInfo->volatileStatus.volatileStatus == STATUS_CONFUSED) return FALSE;
    if (tileMonsterInfo->volatileStatus.volatileStatus == STATUS_CONFUSED) return FALSE;

    if (tileMonsterInfo->sleep.sleep != STATUS_NONE && tileMonsterInfo->sleep.sleep != STATUS_SLEEPLESS && tileMonsterInfo->sleep.sleep != STATUS_YAWNING)  return FALSE;
    if (entityInfo->sleep.sleep != STATUS_NONE      && entityInfo->sleep.sleep != STATUS_SLEEPLESS      && entityInfo->sleep.sleep != STATUS_YAWNING)       return FALSE;

    if (IsChargingAnyTwoTurnMove(tileMonster, FALSE)) return FALSE;
    if (!sub_8070F80(a0, entityInfo->action.direction)) return FALSE;

    if (a1 != 0 && sub_807049C(tileMonster, &a0->pos) && !sub_8052B8C(0, gUnknown_8100208, 0)) return FALSE;

    SetMonsterActionFields(&entityInfo->action, ACTION_WALK);
    if (gRealInputs.held & B_BUTTON) {
        entityInfo->action.unk4[0].actionUseIndex = 0;
    }
    else {
        entityInfo->action.unk4[0].actionUseIndex = 1;
    }
    entityInfo->flags |= 0x8000;

    SetMonsterActionFields(&tileMonsterInfo->action, ACTION_WALK);
    tileMonsterInfo->action.unk4[0].actionUseIndex = 0;
    tileMonsterInfo->action.direction = (entityInfo->action.direction + 4) & 7;
    tileMonsterInfo->flags |= 0x8000;
    tileMonsterInfo->targetPos.x = tileMonster->pos.x;
    tileMonsterInfo->targetPos.y = tileMonster->pos.y;
    gDungeon->unkE = 1;
    return TRUE;
}

void sub_805EE30(void)
{
    Entity *tileObject;
    Tile *tile;
    Entity *leader = GetLeader();
    if (leader == NULL)
        return;
    if (sub_8044B28())
        return;

    tile = GetTileAtEntitySafe(leader);
    if (IQSkillIsEnabled(leader, IQ_SUPER_MOBILE) && leader->axObj.info->transformStatus.transformStatus != STATUS_MOBILE && !HasHeldItem(leader, ITEM_MOBILE_SCARF))
        sub_804AE84(&leader->pos);
    if (tile->terrainType & TERRAIN_TYPE_STAIRS)
        gDungeon->unk1 = 1;

    tileObject = tile->object;
    if (tileObject == NULL)
        return;
    switch (GetEntityType(tileObject))
    {
        case ENTITY_TRAP: {
            Trap *trap = GetTrapData(tileObject);
            bool32 r8 = FALSE;
            bool32 r7 = FALSE;
            if (IQSkillIsEnabled(leader, IQ_TRAP_SEER) && !tileObject->isVisible) {
                tileObject->isVisible = TRUE;
                sub_8049ED4();
                r7 = TRUE;
            }
            if (trap->unk1 != 0) {
                if (trap->unk1 == 1)
                    break;
                if (trap->unk1 == 2)
                    r8 = TRUE;
                if (r8 == FALSE)
                    break;
            }
            if (!r7) {
                sub_807FE9C(leader, &leader->pos, 0, 1);
            }
        }
        break;
        case ENTITY_ITEM: {
            Item *item = GetItemData(tileObject);
            if (!(item->flags & ITEM_FLAG_IN_SHOP)) {
                sub_8045DB4(&leader->pos, 1);
            }
            else {
                gDungeon->unk5C0 = 4;
            }
        }
        break;
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
        default:
            break;
    }
}

extern Entity *sub_80696A8(Entity *a0);
extern u8 sub_806A538(s32);

bool8 sub_805EF60(Entity *a0, EntityInfo *a1)
{
    Entity *r4 = sub_80696A8(a0);

    if (r4 == NULL)
        return FALSE;
    if (GetEntityType(r4) != ENTITY_MONSTER)
        return FALSE;
    if (!sub_8070BC0(a0))
        return FALSE;
    if (r4->axObj.info->isNotTeamMember && r4->axObj.info->clientType != 1 && r4->axObj.info->shopkeeper != 1)
        return FALSE;

    SetMonsterActionFields(&a1->action, ACTION_TALK_FIELD);
    return TRUE;
}

void sub_805EFB4(Entity *a0, bool8 a1)
{
    s32 i;
    EntityInfo *leaderInfo = GetLeaderInfo();
    if (a1 && leaderInfo->volatileStatus.volatileStatus == STATUS_COWERING) {
        leaderInfo->action.direction += 4;
        leaderInfo->action.direction &= 7;
    }
    else if (leaderInfo->volatileStatus.volatileStatus == STATUS_CONFUSED) {
        s32 rnd = DungeonRandInt(8);
        for (i = 0; i < 8; i++) {
            if (a1 || CanMoveInDirection(a0, rnd)) {
                leaderInfo->action.direction = rnd & 7;
                return;
            }
            rnd = (rnd + 1) & 7;
        }
    }
}

extern void sub_803EAF0(u32, u8 *);
extern void sub_803F508(Entity *);
extern void sub_8041AD0(Entity *pokemon);
extern void sub_8041AE0(Entity *pokemon);
extern void sub_807EC28(bool8);
extern void sub_8083CE0(u8 param_1);

extern u8 gAvailablePokemonNames[];

extern u8 gUnknown_202749A[];
extern s32 gUnknown_202F260;
extern MenuInputStruct gUnknown_202EE10;

void sub_805F02C(void)
{
    s32 i;
    Entity *r7 = gDungeon->unkBC;
    Entity *leader = GetLeader();
    EntityInfo *r8 = r7->axObj.info;
    EntityInfo *leaderInfo = leader->axObj.info;

    if (r8->isTeamLeader) {
        sub_805239C(r7, gUnknown_80F9BD8);
    }
    else if (sub_8047084(ITEM_FLAG_IN_SHOP) || sub_807EF48()) {
        sub_805239C(r7, gUnknown_80F9C08);
    }
    else if (gDungeon->unk66E) {
        sub_805239C(r7, gUnknown_80F9C2C);
    }
    else {
        gDungeon->unk679 = 0;
        r8->isTeamLeader = TRUE;
        leaderInfo->isTeamLeader = FALSE;
        for (i = 0; i < 4; i++) {
            PokemonStruct2 *mon = &gRecruitedPokemonRef->pokemon2[i];
            PokemonStruct1 *r5 = NULL;

            if ((u8)mon->unk0 & 1) {
                if (!sub_806A538(mon->unkA)) {
                    r5 = &gRecruitedPokemonRef->pokemon[mon->unkA];
                }
                if (i == r8->teamIndex) {
                    mon->isTeamLeader = TRUE;
                    if (r5 != NULL) {
                        r5->isTeamLeader = TRUE;
                    }
                }
                else {
                    mon->isTeamLeader = FALSE;
                    if (r5 != NULL) {
                        r5->isTeamLeader = FALSE;
                    }
                }
            }
        }
        gLeaderPointer = NULL;
        r8->action = leaderInfo->action;
        sub_803F508(r7);
        sub_8041AD0(leader);
        sub_8041AE0(GetLeader());
        SetMessageArgument(gAvailablePokemonNames, r7, 0);
        SendMessage(r7, gUnknown_80F9BB0);
        sub_807EC28(FALSE);
        r8->unk64 = 0;
        leaderInfo->unk64 = 0;
        sub_806A6E8(leader);
        sub_806A6E8(r7);
    }
}

ActionContainer *GetLeaderActionContainer(void)
{
    return &GetLeaderInfo()->action;
}

u16 GetLeaderActionId(void)
{
    return GetLeaderInfo()->action.action;
}

void ShowFieldMenu(u8 a0_, bool8 a1)
{
    Item *item;
    s32 r10;
    u8 a0 = a0_; // Needed to match.
    s32 var_28;
    s32 var_24;
    struct UnkMenuBitsStruct var_30;
    struct UnkMenuBitsStruct var_34;

    r10 = gDungeon->unk5C0;
    var_28 = 0;
    var_24 = (gDungeon->unk5C0 > - 1);
    gDungeon->unk5C0 = -1;
    if (r10 >= 0) {
        var_28 = r10;
    }

    if (a1) {
        PlayFanfareSE(0x137, 0x100);
    }
    else {
        sub_8083D44();
    }

    while (1) {
        if (r10 < 0) {
            sub_8044C10(1);
            gUnknown_202F260 = -1;
            DrawFieldMenu(a0);
            sub_806A2BC(GetLeader(), 0);
            while (1) {
                AddMenuCursorSprite(&gUnknown_202EE10);
                sub_803E46C(0x1D);
                if (gRealInputs.repeated & DPAD_DOWN) {
                    sub_8083CE0(1);
                    sub_80136E0(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    sub_8083CE0(1);
                    sub_8013744(&gUnknown_202EE10, 1);
                }
                if ((gRealInputs.pressed & A_BUTTON || gUnknown_202EE10.unk28.a_button)) {
                    if (gUnknown_202749A[gUnknown_202EE10.menuIndex + 1] == 7) {
                        sub_8083D08();
                        var_28 = gUnknown_202EE10.menuIndex;
                        break;
                    }
                    sub_8083D30();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
                    var_28 = -1;
                    break;
                }
            }
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1D);
            a0 = 1;
        }

        r10 = var_28;
        if (var_28 == 1) {
            u16 action;

            sub_8044C10(1);
            var_34.a0_8 = 0;
            var_34.a0_16 = 1;
            var_34.a0_24 = 0;
            var_34.a0_32 = 0;
            if (sub_805FD74(GetLeader(), &var_34)) {
                r10 = -1;
            }
            if (sub_805FD3C(&var_34) && sub_805FD74(GetLeader(), &var_34)) {
                sub_8044C10(1);
            }
            action = GetLeaderActionId();
            if (action == 12) {
                sub_8044D90(GetLeader(), 0, 12)->flags |= ITEM_FLAG_UNPAID;
                sub_8060D24(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (action == 53) {
                item = sub_8044D90(GetLeader(), 0, 13);
                if (!sub_8048A68(GetLeader(), item)) {
                    sub_8044C10(1);
                }
            }
            else if (action == 16) {
                item = sub_8044D90(GetLeader(), 0, 14);
                if (!sub_8048950(GetLeader(), item)) {
                    sub_8044C10(1);
                }
            }
            else if (action == 44) {
                item = sub_8044D90(GetLeader(), 0, 15);
                if (!sub_8048B9C(GetLeader(), item)) {
                    sub_8044C10(1);
                }
            }
            else if (action == 60) {
                HandleSetItemAction(GetLeader(), TRUE);
                sub_8044C10(1);
                sub_803E708(0x50, 0x4D);
                sub_8052210(0);
                break;
            }
            else if (action == 61) {
                HandleUnsetItemAction(GetLeader(), TRUE);
                sub_8044C10(1);
                sub_803E708(0x50, 0x4D);
                sub_8052210(0);
                break;
            }

            if (GetLeaderActionId() != 0)
                break;
        }
        else if (var_28 == 2) {
            sub_8044C10(1);
            if (sub_8060E38(GetLeader())) {
                r10 = -1;
            }

            if (GetLeaderActionId() == 0x1B) {
                sub_8061A38(GetLeaderActionContainer(), FALSE);
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x1C) {
                sub_806752C(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x34) {
                sub_8067768(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x1A) {
                ShowTacticsMenu(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x30) {
                sub_8061A38(GetLeaderActionContainer(), TRUE);
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x19) {
                s32 i, count;

                sub_8062D8C(GetLeaderActionContainer());
                count = 0;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (EntityExists(teamMon)) {
                        if (i == GetLeaderActionContainer()->unk4[0].actionUseIndex) {
                            gUnknown_202F260 = count;
                            if (GetLeaderActionId() != 0) {
                                sub_806A2BC(teamMon, 0);
                            }
                            break;
                        }
                        count++;
                    }
                }
            }

            if (GetLeaderActionId() != 0)
                break;
        }
        else if (var_28 == 0) {
            s32 i, r7, r8, r9, r4;
            Entity *r6;

            r7 = 0;
            sub_8044C10(1);
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                Entity *teamMon = gDungeon->teamPokemon[i];
                if (EntityExists(teamMon)) {
                    if (teamMon->axObj.info->isTeamLeader) {
                        r7 = i;
                        break;
                    }
                }
            }


            while (1) {
                sub_8044C10(0);
            LOOP_START_NO_CALL: // Actions 6 and 7 don't call sub_8044C10
                r6 = NULL;
                r9 = 0;
                r8 = 0;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (sub_8071A8C(teamMon)) {
                        if (i == r7) {
                            r9 = r8;
                            r6 = teamMon;
                        }
                        r8++;
                    }
                }
                if (r6 == NULL) {
                    r6 = GetLeader();
                }

                sub_806A2BC(r6, 0);
                sub_804A728(&r6->pos, 0, 1, 1);
                GetLeaderInfo()->action.unk4[0].actionUseIndex = r7;
                sub_8044C10(0);
                if (sub_8062F90(r6, 0, 1, r9, r8)) {
                    r10 = -1;
                }

                if (GetLeaderActionId() == 6) {
                    r4 = r7;
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        if (++r7 >= MAX_TEAM_MEMBERS) {
                            r7 = 0;
                        }
                        r6 = gDungeon->teamPokemon[r7];
                        if (sub_8071A8C(r6))
                            break;
                    }
                    GetLeaderInfo()->action.unk4[0].actionUseIndex = r7;
                    if (r4 != r7) {
                        sub_8083CE0(0);
                    }
                    goto LOOP_START_NO_CALL;
                }
                else if (GetLeaderActionId() == 7) {
                    r4 = r7;
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        if (--r7 < 0) {
                            r7 = MAX_TEAM_MEMBERS - 1;
                        }
                        r6 = gDungeon->teamPokemon[r7];
                        if (sub_8071A8C(r6))
                            break;
                    }
                    GetLeaderInfo()->action.unk4[0].actionUseIndex = r7;
                    if (r4 != r7) {
                        sub_8083CE0(0);
                    }
                    goto LOOP_START_NO_CALL;
                }
                else if (GetLeaderActionId() == 0x1D) {
                    sub_80637E8(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == 0x1E || GetLeaderActionId() == 0x33) {
                    sub_8063A70(GetLeaderActionContainer(), FALSE);
                }
                else if (GetLeaderActionId() == 0x1F) {
                    sub_8063B54(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == 0x20) {
                    sub_8063BB4(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == 0x21) {
                    sub_8063CF0(GetLeaderActionContainer(), FALSE);
                }
                else {
                    break;
                }
            }
            sub_806A2BC(GetLeader(), 0);
            sub_804A728(&GetLeader()->pos, 0, 1, 1);
            if (GetLeaderActionId() != 0)
                break;
        }
        else if (var_28 == 4) {
            Entity *leader = GetLeader();
            Tile *tile = GetTile(leader->pos.x, leader->pos.y);
            Entity *tileObject = tile->object;
            if (tileObject != NULL) {
                if (GetEntityType(tileObject) == ENTITY_ITEM) {
                    u16 action;

                    sub_8044C10(1);
                    var_30.a0_8 = 0;
                    var_30.a0_16 = 1;
                    var_30.a0_24 = 1;
                    var_30.a0_32 = 1;
                    if (sub_805FD74(GetLeader(), &var_30)) {
                        // This actually doesn't do anything, it's just there to make the code match as the compiler does a `lsl r0, r0, #0x10, mov r0, r4`
                        leader = 0; leader = leader;
                    }
                    if (sub_805FD3C(&var_30) && sub_805FD74(GetLeader(), &var_30)) {
                        sub_8044C10(1);
                    }

                    action = GetLeaderActionId();
                    if (action == 0xC) {
                        sub_8044D90(GetLeader(), 0, 0x10)->flags |= ITEM_FLAG_UNPAID;
                        sub_8060D24(GetLeaderActionContainer());
                        sub_8044C10(1);
                    }
                    else if (action == 0x35) {
                        item = sub_8044D90(GetLeader(), 0, 0x11);
                        if (!sub_8048A68(GetLeader(), item)) {
                            sub_8044C10(1);
                        }
                    }
                    else if (action == 0x10) {
                        item = sub_8044D90(GetLeader(), 0, 0x12);
                        if (!sub_8048950(GetLeader(), item)) {
                            sub_8044C10(1);
                        }
                    }
                    else if (action == 0x2C) {
                        item = sub_8044D90(GetLeader(), 0, 0x13);
                        if (!sub_8048B9C(GetLeader(), item)) {
                            sub_8044C10(1);
                        }
                    }
                    if (GetLeaderActionId() != 0)
                        break;
                }
                else if (GetEntityType(tileObject) == ENTITY_TRAP) {
                    sub_8044C10(1);
                    sub_80643AC(GetLeader());
                    if (GetLeaderActionId() != 0)
                        break;
                }
            }
            else
            {
                if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                    sub_8044C10(1);
                    sub_80647F0(GetLeader());
                    if (GetLeaderActionId() != 0)
                        break;
                }
                else {
                    SetMessageArgument(gAvailablePokemonNames, GetLeader(), 0);
                    PrintFieldMessage(0, gUnknown_80FDE18, 1);
                }
            }
            r10 = -1;
        }
        else if (var_28 == 3) {
            sub_8064BE0();
            if (gDungeon->unk4)
                break;
            if (GetLeaderActionId() != 0)
                break;
            r10 = -1;
        }

        if (var_28 < 0)
            break;

        if (var_24 == 0) {
            ResetRepeatTimers();
            ResetUnusedInputStruct();
        }
        else {
            sub_806A2BC(GetLeader(), 0);
            break;
        }
    }

    sub_803EAF0(0, NULL);
    ResetRepeatTimers();
    ResetUnusedInputStruct();
}

extern const u8 *const gFieldMenuMovesPtr;
extern const u8 *const gFieldMenuItemsPtr;
extern const u8 *const gFieldMenuTeamPtr;
extern const u8 *const gFieldMenuOthersPtr;
extern const u8 *const gFieldMenuGroundPtr;
extern const u8 *const gUnknown_80F9174;
extern const u8 *const gUnknown_80F9190;
extern const u8 *const gUnknown_80F91C8;
extern const u8 *const gUnknown_80F91E0;
extern const u8 *const gUnknown_80F91A8;
extern const u8 *const gUnknown_80FE954;

const u8 *sub_805317C(void);
void GetWeatherName(u8 *dst, u8 weatherId);

extern s32 gFormatData_202DE30[];

void DrawFieldMenu(u8 a0)
{
    s32 i, x, y, yLoop;

    gUnknown_202EE10.menuIndex = 0;
    gUnknown_202EE10.unk1A = 5;
    gUnknown_202EE10.unk1C = 5;
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.unk6 = 2;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk0 = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
    sub_80137B0(&gUnknown_202EE10, 0x38);
    if (a0) {
        sub_803EAF0(7, NULL);
    }
    else {
        sub_803EAF0(6, NULL);
    }

    sub_80073B8(0);
    if (ShouldMonsterRunAwayAndShowEffect(GetLeader(), TRUE)) {
        gUnknown_202749A[1] = 2;
        gUnknown_202749A[2] = 2;
        gUnknown_202749A[3] = 2;
        gUnknown_202749A[4] = 7;
        gUnknown_202749A[5] = 2;
    }
    else
    {
        gUnknown_202749A[1] = 7;
        gUnknown_202749A[2] = 7;
        gUnknown_202749A[3] = 7;
        gUnknown_202749A[4] = 7;
        gUnknown_202749A[5] = 7;
    }

    y = sub_8013800(&gUnknown_202EE10, 0);
    PrintStringOnWindow(8, y, gFieldMenuMovesPtr, 0, 0);

    y = sub_8013800(&gUnknown_202EE10, 1);
    PrintStringOnWindow(8, y, gFieldMenuItemsPtr, 0, 0);

    y = sub_8013800(&gUnknown_202EE10, 2);
    PrintStringOnWindow(8, y, gFieldMenuTeamPtr, 0, 0);

    y = sub_8013800(&gUnknown_202EE10, 3);
    PrintStringOnWindow(8, y, gFieldMenuOthersPtr, 0, 0);

    y = sub_8013800(&gUnknown_202EE10, 4);
    PrintStringOnWindow(8, y, gFieldMenuGroundPtr, 0, 0);

    sub_80073E0(0);
    if (a0) {
        u32 hours, minutes, seconds;
        EntityInfo *leaderInfo = GetLeader()->axObj.info;
        const u8 *dungeonName = sub_805317C();

        x = (136 - sub_8008ED0(dungeonName)) / 2;
        sub_80073B8(1);
        PrintStringOnWindow(x, 2, dungeonName, 1, 0);
        sub_80073E0(1);
        sub_80073B8(2);
        DeconstructPlayTime(gPlayTimeRef, &hours, &minutes, &seconds);

        gFormatData_202DE30[0] = FixedPointToInt(leaderInfo->belly);
        gFormatData_202DE30[1] = FixedPointToInt(leaderInfo->maxBelly);
        PrintFormatStringOnWindow(0x73, 0, gUnknown_80F9174, 2, 0);

        gFormatData_202DE30[0] = gTeamInventoryRef->teamMoney;
        PrintFormatStringOnWindow(0x73, 12, gUnknown_80F9190, 2, 0);

        GetWeatherName(gAvailablePokemonNames, GetApparentWeather(NULL));
        PrintFormatStringOnWindow(0x73, 24, gUnknown_80F91A8, 2, 0);

        gFormatData_202DE30[0] = hours;
        gFormatData_202DE30[1] = minutes;
        gFormatData_202DE30[2] = seconds;
        PrintFormatStringOnWindow(0x73, 36, gUnknown_80F91C8, 2, 0);
        for (yLoop = 0, i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *teamMon = gDungeon->teamPokemon[i];
            if (EntityExists(teamMon)) {
                EntityInfo *monInfo = teamMon->axObj.info;
                SetMessageArgument(gAvailablePokemonNames, teamMon, 0);
                gFormatData_202DE30[0] = monInfo->HP;
                gFormatData_202DE30[1] = monInfo->maxHPStat;
                PrintFormatStringOnWindow(4, yLoop, gUnknown_80F91E0, 2, 0);
                yLoop += 12;
                if (yLoop >= 12 * MAX_TEAM_MEMBERS)
                    break;
            }
        }
        sub_80073E0(2);
    }
}

bool8 sub_805FBE8(u8 *a0)
{
    s32 r4;
    sub_803EAF0(8, a0);
    do
    {
        sub_803E46C(0xE);
        xxx_draw_string_80144C4();
        r4 = sub_8016080();
    } while (r4 == 0);
    CleanConfirmNameMenu();
    sub_803E46C(0xE);
    sub_803EAF0(0, NULL);
    if (r4 == 3 && *a0 != 0)
        return TRUE;

    return FALSE;
}

extern u8 *sub_8044EC8(s32 param_1);
extern bool8 sub_8044F3C(s32 param_1);
extern s32 gUnknown_202EE6C;
extern const u8 gUnknown_8106B50[];

typedef struct UnkTextStruct3 {
    UnkTextStruct2 a0[4];
    // Something ugly, so that sub_805FD74 could match weird compiler memcpy/stack initialization
    #ifndef NONMATCHING
    u8 fakeMatch[0];
    #endif // NONMATCHING
} UnkTextStruct3;

extern void sub_803ECB4(UnkTextStruct3 *a0, u8 a1);
void CreateFieldItemMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, UnkTextStruct3 *a4, UnkTextStruct2_sub2 *a5);

// Inline needed to (fake?)match.
static inline void sub_805FC30_SetUpTxtStruct(UnkTextStruct3 *src)
{
    memset(src, 0, sizeof(*src));
    src->a0[0].unk4 = 3;
    src->a0[1].unk4 = 3;
    src->a0[1].unk8.unk0.separate.unk0 = 0x16;
    src->a0[1].unk8.unk0.separate.unk2 = 4;
    src->a0[1].unkC = 6;
    src->a0[1].unkE = 4;
    src->a0[1].unk10 = 4;
    src->a0[2].unk4 = 3;
    src->a0[3].unk4 = 3;
}

void sub_805FC30(UnkTextStruct3 *a0, s32 a1)
{
    s32 i;
    UnkTextStruct3 sp;

    sub_805FC30_SetUpTxtStruct(&sp);
    sp.a0[0] = a0->a0[0];
    sp.a0[0].unk0 = 0x80;

    gUnknown_202EE10.menuIndex = 0;
    gUnknown_202EE10.unk1C = gUnknown_202EE6C;
    gUnknown_202EE10.unk1A = gUnknown_202EE6C;
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.unk6 = 0;
    gUnknown_202EE10.unk0 = 1;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14 = gUnknown_202EE10.unk8;

    sub_801317C(&gUnknown_202EE10.unk28);

    sp.a0[1].unk8.unk0.separate.unk0 = a1;
    sp.a0[1].unkC = 28 - a1;
    sp.a0[1].unkE = sp.a0[1].unk10 = sub_80095E4(gUnknown_202EE10.unk1C, 0);
    sub_803ECB4(&sp, 0);
    sub_80137B0(&gUnknown_202EE10, sp.a0[1].unkE * 8);
    sub_80073B8(1);

    for (i = 0; i < gUnknown_202EE6C; i++) {
        s32 r4, y;
        u8 text[20];

        r4 = (sub_8044F3C(i) != 0) ? 7 : 2;
        sprintfStatic(text, gUnknown_8106B50, r4, sub_8044EC8(i));
        y = sub_8013800(&gUnknown_202EE10, i);
        PrintStringOnWindow(8, y, text, 1, 0);
    }
    sub_80073E0(1);
}

bool8 sub_805FD3C(struct UnkMenuBitsStruct *a0)
{
    u16 action = GetLeaderActionId();

    a0->a0_8 = 0;
    a0->a0_16 = 0;
    a0->a0_24 = 0;
    a0->a0_32 = 0;
    if (action == 0xA) {
        a0->a0_8 = 1;
        a0->a0_32 = 1;
    }
    if (action == 0x3E) {
        a0->a0_8 = 1;
        a0->a0_16 = 0;
        a0->a0_32 = 1;
    }
    return a0->a0_8;
}

extern unkStruct_8044CC8 gUnknown_202F238;
extern s32 gUnknown_202F240;
extern s16 gUnknown_202F248[];
extern s32 gUnknown_202F258;

s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4);

void sub_8060890(Position *a0);
bool8 sub_8060860(s32 a0);
void sub_8060900(Entity *a0);
s32 sub_8060800(UnkTextStruct2_sub2 *a0, s32 a1);
void sub_8060CE8(ActionContainer *a0);
extern Entity *DrawFieldGiveItemMenu(u8 *a0, s32 a1);

bool8 sub_805FD74(Entity * a0, struct UnkMenuBitsStruct *a1)
{
    s32 i, i_r6;
    s32 r8;
    s32 r9 = 0;

    u8 var_34 = 1;
    u8 var_30 = 0;
    u8 var_2C = 0;
    u8 var_28 = 0;
    EntityInfo *a0Info = a0->axObj.info;
    UnkTextStruct2_sub2 var_3C;

    UnkTextStruct3 var_FC =
    {
        .a0 =
        {
            [0] =
            {
                .unk4 = 6,
                .unk8 = {2, 2},
                .unkC = 0x12,
                .unkE = 0x10,
                .unk10 = 0x10,
                .unk14 = &var_3C,
            },
            {.unk4 = 3}, {.unk4 = 3}, {.unk4 = 3},
        },
    };

    gUnknown_202F238.actionUseIndex = 0;
    gUnknown_202F238.lastItemThrowPosition.x = 0;
    gUnknown_202F238.lastItemThrowPosition.y = 0;
    if (a1 != NULL) {
        var_2C = (a1->a0_8 != 0);
        var_34 = (a1->a0_16 != 0);
        var_30 = (a1->a0_24 != 0);
        var_28 = (a1->a0_32 != 0);
    }

    gUnknown_202F258 = sub_8060D64(gUnknown_202F248, var_30, var_34, var_28, a0);
    if (gUnknown_202F258 == 0) {
        PrintFieldMessage(0, gUnknown_80F8B24, 1);
        return TRUE;
    }

    r8 = 0;
    gUnknown_202F240 = 0;
    while (1)
    {
        s32 id;
        Entity *r4;

        r9 = 0;
        for (i = 0; i < INVENTORY_SIZE; i++) {
            Item *item = &gTeamInventoryRef->teamItems[i];
            if (item->flags & ITEM_FLAG_EXISTS && item->flags & ITEM_FLAG_UNPAID) {
                item->flags &= ~(ITEM_FLAG_UNPAID);
                r8 = i / 10;
                gUnknown_202F240 = i % 10;
            }
        }
        for (i_r6 = 0; i_r6 < MAX_TEAM_MEMBERS; i_r6++) {
            Entity *teamMon = gDungeon->teamPokemon[i_r6];
            if (EntityExists(teamMon)) {
                EntityInfo *monInfo = teamMon->axObj.info;
                if (monInfo->heldItem.flags & ITEM_FLAG_EXISTS && monInfo->heldItem.flags & ITEM_FLAG_UNPAID) {
                    monInfo->heldItem.flags &= ~(ITEM_FLAG_UNPAID);
                    for (i = 0; i < gUnknown_202F258; i++) {
                        if (gUnknown_202F248[i] == i_r6 + 4) {
                            r8 = i;
                            break;
                        }
                    }
                    gUnknown_202F240 = 0;
                }
            }
        }
        CreateFieldItemMenu(r8, a0, var_2C, var_30, &var_FC, &var_3C);

        id = gUnknown_202F248[gUnknown_202EE10.unk1E];
        if (id >= MAX_TEAM_MEMBERS) {
            r4 = gDungeon->teamPokemon[id - MAX_TEAM_MEMBERS];
        }
        else {
            r4 = a0;
        }
        sub_806A2BC(r4, 0);
        sub_804A728(&r4->pos, 0, 1, 1);

        while (1) {
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x14);
            if (!var_30) {
                if (gUnknown_202F258 > 1) {
                    if ((gRealInputs.pressed & DPAD_LEFT) || gUnknown_202EE10.unk28.dpad_left) {
                        sub_8083CE0(0);
                        if (--r8 < 0) {
                            r8 = gUnknown_202F258 - 1;
                        }
                        gUnknown_202F240 = var_30;
                        break;
                    }
                    if ((gRealInputs.pressed & DPAD_RIGHT) || gUnknown_202EE10.unk28.dpad_right) {
                        sub_8083CE0(0);
                        if (++r8 == gUnknown_202F258) {
                            r8 = 0;
                        }
                        gUnknown_202F240 = var_30;
                        break;
                    }
                }
                if (gRealInputs.repeated & DPAD_DOWN && sub_8060860(r8)) {
                    sub_8083CE0(1);
                    sub_80136E0(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.repeated & DPAD_UP && sub_8060860(r8)) {
                    sub_8083CE0(1);
                    sub_8013744(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.pressed & SELECT_BUTTON && gUnknown_202F248[r8] <= 1) {
                    s32 r3;
                    bool32 r7 = TRUE;
                    s16 arr[10];

                    PlaySoundEffect(0x132);
                    sub_8047158();
                    ConvertMoneyItemToMoney();
                    gUnknown_202F240 = 0;
                    r3 = sub_8060D64(arr, var_30, var_34, var_28, a0);
                    if (gUnknown_202F258 == r3) {
                        for (i_r6 = 0; i_r6 < r3; i_r6++) {
                            if (arr[i_r6] != gUnknown_202F248[i_r6]) {
                                break;
                            }
                        }
                        if (i_r6 == r3) {
                            r7 = FALSE;
                        }
                    }
                    if (r7) {
                        r8 = 0;
                        gUnknown_202F240 = 0;
                        gUnknown_202F258 = r3;
                        for (i_r6 = 0; i_r6 < gUnknown_202F258; i_r6++) {
                            gUnknown_202F248[i_r6] = arr[i_r6];
                        }
                    }
                    break;
                }
                if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                    sub_8083D08();
                    sub_8060890(&a0->pos);
                    r9 = 1;
                    break;
                }
                if (gRealInputs.pressed & START_BUTTON) {
                    sub_8083D44();
                    sub_8060890(&a0->pos);
                    r9 = 3;
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
                    r9 = 2;
                    break;
                }
            }
            else {
                sub_8060890(&a0->pos);
                r9 = 1;
                break;
            }
        }
        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x14);
        if (gUnknown_202F248[gUnknown_202EE10.unk1E] <= 1 && !(gTeamInventoryRef->teamItems[0].flags & ITEM_FLAG_EXISTS)) {
            r9 = 2;
        }

        if (r9 == 2) {
            sub_803EAF0(0, NULL);
            r9 = 1;
            break;
        }
        else if (r9 == 0) {
            continue;
        }
        else if (r9 == 3) {
            SetMonsterActionFields(&a0Info->action, 0xC);
            a0Info->action.unk4[0] = gUnknown_202F238;
            sub_803EAF0(0, NULL);
            r9 = 0;
            break;
        }
        else {
            gUnknown_202F240 = gUnknown_202EE10.menuIndex;
            if (var_2C != 0) {
                a0Info->action.unk4[1] = gUnknown_202F238;
                sub_803EAF0(0, NULL);
                r9 = 0;
                break;
            }

            sub_8060900(a0);
            sub_8060800(&var_3C, gUnknown_202EE10.unk1E);
            sub_805FC30(&var_FC, 0x16);
            while (1) {
                AddMenuCursorSprite(&gUnknown_202EE10);
                sub_803E46C(0x14);
                if (gRealInputs.repeated & DPAD_DOWN) {
                    sub_8083CE0(1);
                    sub_80136E0(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    sub_8083CE0(1);
                    sub_8013744(&gUnknown_202EE10, 1);
                }
                if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                    if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                        sub_8083D08();
                        sub_8060CE8(&a0Info->action);
                        r9 = 0;
                        break;
                    }
                    sub_8083D30();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
                    r9 = 1;
                    break;
                }
            }
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x14);
            gDungeon->unk181e8.unk18212 = 0;
            if (r9 != 1 || var_30 != 0) {
                if (a0Info->action.action == 0x37 || a0Info->action.action == 0x38 || a0Info->action.action == 0x3E) {
                    // Hm...
                    int newAction = gUnknown_202F238.actionUseIndex - 0x90;
                    a0Info->action.unk4[0].actionUseIndex = newAction;
                    sub_803EAF0(0, 0);
                    r9 = 0;
                    break;
                }
                else if (a0Info->action.action == 0x36) {
                    u32 var_38;
                    if (DrawFieldGiveItemMenu((void*)&var_38, 2) != NULL) {
                        a0Info->action.unk4[1].actionUseIndex = var_38;
                        sub_803EAF0(0, 0);
                        r9 = 0;
                        break;
                    }
                    sub_803EAF0(0, NULL);
                    sub_8044C10(1);
                }
                else {
                    sub_803EAF0(0, 0);
                    r9 = 0;
                    break;
                }
            }
        }
    }

    gDungeon->unk181e8.unk18212 = 0;
    sub_803E708(2, 0x61);
    sub_804AA60();
    sub_803E708(2, 0x61);
    return r9;
}

extern const struct UnkTextStruct2 gUnknown_8106B6C;
extern const struct unkStruct_8090F58 gUnknown_8106B60;

void CreateFieldItemMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, UnkTextStruct3 *a4, UnkTextStruct2_sub2 *a5)
{
    s32 i, x, y;
    s32 r10;
    UnkTextStruct1 *txtStrPtr;
    UnkTextStruct2 var_94;
    u8 txtBuff[80];
    EntityInfo *a1Info;

    var_94 = gUnknown_8106B6C;
    a1Info = a1->axObj.info;
    r10 = sub_8060800(a5, a0);
    gUnknown_202EE10.menuIndex = gUnknown_202F240;
    gUnknown_202EE10.unk1A = 0;
    gUnknown_202EE10.unk1E = a0;
    gUnknown_202EE10.unk20 = gUnknown_202F258;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.unk0 = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
    gDungeon->unk181e8.unk18212 = 0;
    switch (gUnknown_202F248[a0]) {
        case 0:
        case 1:
            a4->a0[0].unk10 = 0x10;
            a4->a0[0].unkE = 0x10;
            a5->f2 = 0xC;
            gUnknown_202EE10.unk6 = 0x10;
            gUnknown_202EE10.unk1C = 0xA;
            gDungeon->unk181e8.unk18212 = 1;
            break;
        case 2:
            a4->a0[0].unk10 = 4;
            a4->a0[0].unkE = 4;
            a5->f2 = 6;
            gUnknown_202EE10.unk6 = 0x12;
            gUnknown_202EE10.unk1C = 1;
            break;
        case 3:
        default:
            a4->a0[0].unk10 = 4;
            a4->a0[0].unkE = 4;
            a5->f2 = 0xC;
            gUnknown_202EE10.unk6 = 0x12;
            gUnknown_202EE10.unk1C = 1;
            break;
    }

    if (a2) {
        gUnknown_202EE10.unkC += 0x40;
        a4->a0[0].unk8.unk0.separate.unk0 = 0xA;
        a4->a0[1] = var_94;
    }
    else {
        a4->a0[0].unk8.unk0.separate.unk0 = 2;
        a4->a0[1] = a4->a0[3];
    }

    sub_803ECB4(a4, 1);
    txtStrPtr = &gUnknown_2027370[0];
    gUnknown_202EE10.unkC = (txtStrPtr->unk0 + 0x10) * 8;
    gUnknown_202EE10.unkE = ((txtStrPtr->unk2 + 1) * 8) - 2;
    sub_80137B0(&gUnknown_202EE10, 0x70);
    sub_80073B8(0);
    x = ((a0 - r10) * 8) + 0xC;
    switch (gUnknown_202F248[a0])
    {
    case 0:
        PrintFormatStringOnWindow(x, 0, gTeamToolboxAPtr, 0, 0);
        for (i = 0; i < 10; i++) {
            Item *items;
            DUMMY_TEAM_ITEMS_ASM_MATCH(i);

            items = gTeamInventoryRef->teamItems;
            if (items[i].flags & ITEM_FLAG_EXISTS) {
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, &gTeamInventoryRef->teamItems[i], &gUnknown_8106B60);
                y = sub_8013800(&gUnknown_202EE10, i);
                PrintFormatStringOnWindow(8, y, txtBuff, 0, 0);
            }
            else {
                break;
            }
        }
        break;
    case 1:
        PrintFormatStringOnWindow(x, 0, gTeamToolboxBPtr, 0, 0);
        for (i = 0; i < 10; i++) {
            Item *items;
            DUMMY_TEAM_ITEMS_ASM_MATCH(i);

            items = gTeamInventoryRef->teamItems;
            if (items[i + 10].flags & 1) {
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, &gTeamInventoryRef->teamItems[i + 10], &gUnknown_8106B60);
                y = sub_8013800(&gUnknown_202EE10, i);
                PrintFormatStringOnWindow(8, y, txtBuff, 0, 0);
            }
            else {
                break;
            }
        }
        break;
    case 2: {
            Tile *tile = GetTile(a1->pos.x, a1->pos.y);
            Item *item = GetItemData(tile->object);
            PrintFormatStringOnWindow(x, 0, gFieldItemMenuGroundTextPtr, 0, 0);
            if (item->flags & ITEM_FLAG_EXISTS) {
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                y = sub_8013800(&gUnknown_202EE10, 0);
                PrintFormatStringOnWindow(8, y, txtBuff, 0, 0);
            }
            if (a3) {
                gUnknown_202EE10.unk8.x = gUnknown_202EE10.unk8.y = 0;
            }
        }
        break;
    case 3: {
            Item *item = &a1->axObj.info->heldItem;
            SetMessageArgument_2(gAvailablePokemonNames, a1Info, 0);
            PrintFormatStringOnWindow(x, 0, gUnknown_80FE940, 0, 0);
            if (item->flags & ITEM_FLAG_EXISTS) {
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                y = sub_8013800(&gUnknown_202EE10, 0);
                PrintFormatStringOnWindow(8, y, txtBuff, 0, 0);
            }
        }
        break;
    default: {
            Entity *chosenTeamMember = gDungeon->teamPokemon[gUnknown_202F248[a0] - MAX_TEAM_MEMBERS];
            if (EntityExists(chosenTeamMember)) {
                Item *item = &chosenTeamMember->axObj.info->heldItem;
                SetMessageArgument_2(gAvailablePokemonNames,
                                     chosenTeamMember->axObj.info, 0);
                PrintFormatStringOnWindow(x, 0, gUnknown_80FE940, 0, 0);
                if (item->flags & ITEM_FLAG_EXISTS) {
                    gUnknown_202EE10.unk1A++;
                    sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                    y = sub_8013800(&gUnknown_202EE10, 0);
                    PrintFormatStringOnWindow(8, y, txtBuff, 0, 0);
                }
            }
        }
        break;
    }

    if (gUnknown_202EE10.menuIndex >= gUnknown_202EE10.unk1A) {
        gUnknown_202EE10.menuIndex = 0;
    }
    sub_80073E0(0);
    if (a2) {
        sub_80073B8(1);
        PrintFormatStringOnWindow(4, 2, gWhichTextPtr1, 1, 0);
        sub_80073E0(1);
    }
}

s32 sub_8060800(UnkTextStruct2_sub2 *a0, s32 a1)
{
    s32 i, r1, r2, r3;

    r1 = 0;
    for (i = 0; i < gUnknown_202F258; i++) {
        if (gUnknown_202F248[i] <= 1) {
            r1++;
        }
    }

    if (gUnknown_202F248[a1] <= 1) {
        r3 = a1;
        r2 = r1;
        r1 = 0;
    }
    else {
        r3 = a1 - r1;
        r2 = gUnknown_202F258 - r1;
    }

    if (a0 != NULL) {
        a0->f0 = r2;
        a0->f1 = r3;
        a0->f3 = 0;
    }

    return r1;
}

bool8 sub_8060860(s32 a0)
{
    if (gUnknown_202EE10.unk1A <= 1 || gUnknown_202F248[a0] > 1)
        return FALSE;
    else
        return TRUE;
}

void sub_8060890(Position *a0)
{
    s32 var = gUnknown_202F248[gUnknown_202EE10.unk1E];
    switch (var)
    {
    case 0:
        gUnknown_202F238.actionUseIndex = gUnknown_202EE10.menuIndex + 1;
        break;
    case 1:
        gUnknown_202F238.actionUseIndex = gUnknown_202EE10.menuIndex + 11;
        break;
    case 2:
        gUnknown_202F238.actionUseIndex = 128;
        break;
    default:
        gUnknown_202F238.actionUseIndex = var - 116;
        break;
    }

    gUnknown_202F238.lastItemThrowPosition.x = a0->x;
    gUnknown_202F238.lastItemThrowPosition.y = a0->y;
}

extern Item * sub_8044CC8(Entity *param_1, unkStruct_8044CC8 *param_2, UNUSED s32 a3);
extern void sub_8044F5C(u16 param_1, u8 param_2);
extern void sub_8044FF0(u16 param_1);
extern u16 sub_8044DC8(Item *param_1);
extern bool8 sub_8046F00(Item *item);
extern void sub_8045064(void);

void sub_8060900(Entity *a0)
{
    u16 val_sub8044DC8;
    Item *item = sub_8044CC8(a0, &gUnknown_202F238, 0xA);
    EntityInfo *a0Info = a0->axObj.info;

    gUnknown_202EE6C = 0;
    if (gUnknown_202F238.actionUseIndex < 144) {
        if (gUnknown_202F238.actionUseIndex == 128) {
            sub_8044F5C(9, item->id);
            if (GetItemCategory(item->id) != CATEGORY_POKE) {
                bool32 r2 = 0;
                if (gDungeon->unk65B != 0) {
                    if (gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags & ITEM_FLAG_EXISTS) {
                        r2 = TRUE;
                    }
                }
                else if (a0Info->heldItem.flags & ITEM_FLAG_EXISTS) {
                    r2 = TRUE;
                }

                if (r2) {
                    sub_8044FF0(9);
                }
            }
            // Why is it checking actionUseIndex again?
            if (gUnknown_202F238.actionUseIndex == 128 && gDungeon->unk65B != 0) {
                sub_8044F5C(10, item->id);
            }
        }
        val_sub8044DC8 = sub_8044DC8(item);
        if (val_sub8044DC8 != 0) {
            sub_8044F5C(val_sub8044DC8, item->id);
            if (item->flags & ITEM_FLAG_STICKY) {
                sub_8044FF0(val_sub8044DC8);
            }
            if (!sub_8046F00(item)) {
                sub_8044FF0(val_sub8044DC8);
            }
        }

        if (gUnknown_202F238.actionUseIndex <= 20
            && (GetItemCategory(item->id) == CATEGORY_THROWN_LINE || GetItemCategory(item->id) == CATEGORY_THROWN_ARC))
        {
            s32 i;

            if (item->flags & ITEM_FLAG_SET) {
                sub_8044F5C(0x3D, item->id);
            }
            else {
                sub_8044F5C(0x3C, item->id);
            }

            for (i = 0; i < INVENTORY_SIZE; i++) {
                // Compiler uses r5 without the fakematch trick. It's gTeamInventoryRef causing matching issues again...
                #ifndef NONMATCHING
                item++;item--;
                #endif // NONMATCHING
                if (gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_EXISTS
                    && gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_SET
                    && gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_STICKY)
                {
                    sub_8044FF0(0x3C);
                    sub_8044FF0(0x3D);
                    break;
                }
            }
        }

        if (gUnknown_202F238.actionUseIndex != 129) {
            if (gUnknown_202F238.actionUseIndex != 128) {
                s32 i;
                bool32 r8 = FALSE;

                sub_8044F5C(0x36, item->id);
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (EntityExists(teamMon)) {
                        EntityInfo *teamMonInfo = teamMon->axObj.info;
                        teamMonInfo->unk157 = FALSE;
                        if (!CheckVariousConditions(teamMon)) {
                            r8 = TRUE;
                            teamMonInfo->unk157 = TRUE;
                        }
                    }
                }
                if (!r8) {
                    sub_8044FF0(0x36);
                }
            }
        }
        else if (gDungeon->unk65B) {
            if (gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags & ITEM_FLAG_EXISTS) {
                sub_8044F5C(0x3E, item->id);
            }
            else {
                sub_8044F5C(0x37, item->id);
            }

            if (CheckVariousConditions(a0)) {
                sub_8044FF0(0x37);
                sub_8044FF0(0x3E);
            }
        }

        if (gUnknown_202F238.actionUseIndex <= 20) {
            Entity *tileEntity = GetTile(a0->pos.x, a0->pos.y)->object;
            if (tileEntity == NULL) {
                sub_8044F5C(8, item->id);
            }
            else if (GetEntityType(tileEntity) == ENTITY_ITEM) {
                sub_8044F5C(0x3A, item->id);
            }
        }

        if (GetItemCategory(item->id) == CATEGORY_THROWN_LINE) {
            sub_8044F5C(0x27, item->id);
        }
        else if (GetItemCategory(item->id) == CATEGORY_THROWN_ARC) {
            sub_8044F5C(0x41, item->id);
        }
        else {
            sub_8044F5C(0xB, item->id);
        }

        if (!MonsterCanThrowItems(a0Info)) {
            sub_8044FF0(0x27);
            sub_8044FF0(0x41);
            sub_8044FF0(0xB);
        }
    }
    else {
        s32 index = gUnknown_202F238.actionUseIndex - 144;
        Entity *teamMon = gDungeon->teamPokemon[index];
        if (EntityExists(teamMon)) {
            bool32 r5, r6, r4;
            EntityInfo *teamMonInfo = teamMon->axObj.info;

            r5 = FALSE;
            if (CheckVariousConditions(teamMon))
                r6 = TRUE;
            else
                r6 = FALSE;

            if (gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags & ITEM_FLAG_EXISTS)
                r4 = TRUE;
            else
                r4 = FALSE;

            if (GetItemCategory(item->id) == CATEGORY_TMS_HMS) r5 = TRUE;
            if (GetItemCategory(item->id) == CATEGORY_ORBS) r5 = TRUE;

            if (gDungeon->unk65B) {
                if (r4) {
                    sub_8044F5C(0x3E, item->id);
                }
                else {
                    sub_8044F5C(0x37, item->id);
                }

                if (r6) {
                    sub_8044FF0(0x37);
                    sub_8044FF0(0x3E);
                }
            }

            if (teamMonInfo->isTeamLeader) {
                val_sub8044DC8 = sub_8044DC8(item);
                if (val_sub8044DC8 != 0) {
                    sub_8044F5C(val_sub8044DC8, item->id);
                    if (item->flags & ITEM_FLAG_STICKY) {
                        sub_8044FF0(val_sub8044DC8);
                    }
                    if (!sub_8046F00(item)) {
                        sub_8044FF0(val_sub8044DC8);
                    }
                }
            }
            else {
                sub_8044F5C(0x38, item->id);
                if (r5) {
                    sub_8044FF0(0x38);
                }
            }
        }
    }

    sub_8044F5C(0xC, item->id);
    sub_8045064();
}

void sub_8060CE8(ActionContainer *a0)
{
    SetMonsterActionFields(a0, gUnknown_202EE44[gUnknown_202EE10.menuIndex].unk0);
    a0->unk4[0] = gUnknown_202F238;
    a0->unk4[1].actionUseIndex = 0;
    a0->unk4[1].lastItemThrowPosition.x = 0;
    a0->unk4[1].lastItemThrowPosition.y = 0;
}

void sub_8060D24(UNUSED ActionContainer *a0)
{
    Item *item = sub_8044D90(GetLeader(), 0, 0xB);
    sub_803ECB4(NULL, 0);
    sub_801B3C0(item);

    do {
        sub_803E46C(0x16);
    } while (sub_801B410() == 0);

    sub_801B450();
    sub_803EAF0(0, NULL);
}

extern bool8 sub_804ACE4(Position *pos);

s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4)
{
    s32 i;
    s32 count = 0;

    if (gDungeon->unk65B && !a1) {
        if (gTeamInventoryRef->teamItems[0].flags & ITEM_FLAG_EXISTS) {
            a0[count++] = 0;
        }
        if (gTeamInventoryRef->teamItems[INVENTORY_SIZE / 2].flags & ITEM_FLAG_EXISTS) {
            a0[count++] = 1;
        }
    }

    if (a2 && sub_804ACE4(&a4->pos)) {
        a0[count++] = 2;
    }

    if (!a1 && !a3) {
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *teamMon = gDungeon->teamPokemon[i];
            if (EntityExists(teamMon) && teamMon->axObj.info->heldItem.flags & ITEM_FLAG_EXISTS) {
                a0[count++] = i + MAX_TEAM_MEMBERS;
            }
        }
    }

    return count;
}

extern UnkTextStruct2_sub2 gUnknown_202F270;

struct UnkFieldTeamMenuStruct
{
    s32 unk0;
    s32 unk4[MAX_TEAM_MEMBERS];
    u8 unk14[MAX_TEAM_MEMBERS];
};

void DrawFieldTeamMenu(struct UnkFieldTeamMenuStruct *a0, UnkTextStruct3 *a1, bool8 a2);
void sub_806145C(struct UnkFieldTeamMenuStruct *a0);
void sub_80615B4(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1);

extern u8 gUnknown_202EE39;

bool8 sub_8060E38(Entity *a0)
{
    s32 i;
    bool32 r10, ret;

    struct UnkFieldTeamMenuStruct sp;
    UnkTextStruct3 var_84 = {0};

    var_84.a0[0].unk4 = 6;
    var_84.a0[0].unk8.unk0.separate.unk0 = 2;
    var_84.a0[0].unk8.unk0.separate.unk2 = 2;
    var_84.a0[0].unkC = 0xE;
    var_84.a0[0].unkE = 0x10;
    var_84.a0[0].unk10 = 0x10;
    var_84.a0[0].unk14 = &gUnknown_202F270;
    var_84.a0[1].unk4 = 3;
    var_84.a0[2].unk4 = 3;
    var_84.a0[3].unk4 = 3;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityExists(teamMon)) {
            teamMon->axObj.info->unk157 = TRUE;
        }
    }

    if (!gDungeon->unk65B) {
        var_84.a0[0].unk4 = 3;
        var_84.a0[0].unk8.unk0.arr[1]++;
    }

    while (1) {
        s32 id;
        bool32 r4;

        ret = FALSE;
        DrawFieldTeamMenu(&sp, &var_84, TRUE);
        r10 = FALSE;
        while (1) {
            s32 id = sp.unk4[gUnknown_202EE10.menuIndex];
            if (id >= 0) {
                Entity *teamMon = gDungeon->teamPokemon[id];
                sub_806A2BC(teamMon, 0);
                sub_804A728(&teamMon->pos, 0, 1, 1);
            }

            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                sub_80136E0(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                sub_8013744(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                if (sp.unk14[gUnknown_202EE10.menuIndex] != 0) {
                    sub_8083D44();
                    r10 = TRUE;
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button)
            {
                if (sp.unk14[gUnknown_202EE10.menuIndex] != 0) {
                    sub_8083D08();
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                ret = TRUE;
                break;
            }
        }

        id = sp.unk4[gUnknown_202EE10.menuIndex];
        if (id >= 0) {
            Entity *teamMon = gDungeon->teamPokemon[id];
            sub_806A2BC(teamMon, 0);
            sub_804A728(&teamMon->pos, 0, 1, 1);
        }

        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1B);
        sub_804AA60();
        if (ret) {
            break;
        }

        sp.unk0 = gUnknown_202EE10.menuIndex;
        gUnknown_202F260 = gUnknown_202EE10.menuIndex;
        sub_806145C(&sp);
        if (r10) {
            EntityInfo *info = a0->axObj.info;
            SetMonsterActionFields(&info->action, 0x1B);
            info->action.unk4[0].actionUseIndex = sp.unk4[sp.unk0];
            ret = FALSE;
            break;
        }

        sub_805FC30(&var_84, 0x12);
        while (1) {
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                sub_80136E0(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                sub_8013744(&gUnknown_202EE10, 1);
            }
            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                    sub_80615B4(&a0->axObj.info->action, &sp);
                    sub_8083D08();
                    r4 = FALSE;
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                r4 = TRUE;
                break;
            }
        }
        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1B);
        if (r4 != TRUE) {
            ret = FALSE;
            break;
        }
    }

    if (ret) {
        sub_806A2BC(GetLeader(), 0);
    }
    sub_803EAF0(0, NULL);
    return ret;
}

bool32 sub_8069D18(Position *a0, Entity *a1);

extern const u8 gTeamFormat[];
extern const u8 gHeartRedTiny[];
extern const u8 gHeartRedSmall[];
extern const u8 gHeartRedMedium[];
extern const u8 gHeartRedLarge[];
extern const u8 gHeartYellowTiny[];
extern const u8 gHeartYellowSmall[];
extern const u8 gHeartYellowMedium[];
extern const u8 gHeartYellowLarge[];
extern const u8 gUnknown_8106BD4[];
extern const u8 gUnknown_8106BE0[];
extern const u8 gUnknown_8106BEC[];
extern const u8 gUnknown_8106BF4[];

extern void sub_8070968(u8 *buffer, EntityInfo *entityInfo, s32 colorNum);

void DrawFieldTeamMenu(struct UnkFieldTeamMenuStruct *a0, UnkTextStruct3 *a1, bool8 a2)
{
    s32 r0;
    Position pos;
    s32 i;

    s32 count = 0;
    bool8 r10 = (a1->a0[0].unk4 == 6);

    sub_8069D18(&pos, GetLeader());
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        EntityInfo *monInfo;
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityExists(teamMon)) {
            a0->unk4[count] = i;
            monInfo = teamMon->axObj.info;
            a0->unk14[count] = monInfo->unk157;
            if (pos.x == teamMon->pos.x && pos.y == teamMon->pos.y && gUnknown_202F260 < 0) {
                gUnknown_202F260 = count;
            }
            count++;
        }
    }

    if (gUnknown_202F260 >= count) {
        gUnknown_202F260 = count - 1;
    }
    if (gUnknown_202F260 < 0) {
        gUnknown_202F260 = 0;
    }

    for (i = count; i < MAX_TEAM_MEMBERS; i++) {
        a0->unk4[i] = -1;
        a0->unk14[i] = 0;
    }

    gUnknown_202F270.f0 = 1;
    gUnknown_202F270.f1 = 0;
    gUnknown_202F270.f3 = 0;
    gUnknown_202EE10.menuIndex = gUnknown_202F260;
    gUnknown_202EE10.unk1A = count;
    gUnknown_202EE10.unk1C = count;
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.unk6 = (r10 != FALSE) * 16;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14.x = 0;
    gUnknown_202EE10.unk0 = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
    r0 = sub_80095E4(count, 0);
    if (r10) {
        r0 += 2;
    }
    a1->a0[0].unk10 = r0;
    a1->a0[0].unkE = r0;
    gUnknown_202F270.f2 = 8;
    if (a2) {
        a1->a0[1] = a1->a0[3];
    }

    sub_803ECB4(a1, 1);
    sub_80137B0(&gUnknown_202EE10, 0);
    sub_80073B8(0);
    if (r10) {
        PrintFormatStringOnWindow(0xC, 0, gTeamFormat, 0, 0);
    }

    // Print hp/max hp
    for (i = 0; i < count; i++) {
        s32 y;
        s32 id = a0->unk4[i];
        if (id >= 0) {
            Entity *teamMon = gDungeon->teamPokemon[id];
            if (EntityExists(teamMon))
            {
                EntityInfo *monInfo = teamMon->axObj.info;
                s32 color = (a0->unk14[i] != 0) ? 6 : 2;

                sub_8070968(gAvailablePokemonNames, monInfo, color);
                if (sub_806A538(gRecruitedPokemonRef->pokemon2[monInfo->teamIndex].unkA)) {
                    if (monInfo->HP <= monInfo->maxHPStat / 4) {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartRedTiny);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 2) {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartRedSmall);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 3) {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartRedMedium);
                    }
                    else {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartRedLarge);
                    }
                }
                else {
                    if (monInfo->HP <= monInfo->maxHPStat / 4) {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartYellowTiny);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 2) {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartYellowSmall);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 3) {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartYellowMedium);
                    }
                    else {
                        strcpy(gAvailablePokemonNames + 0x50, gHeartYellowLarge);
                    }
                }

                gFormatData_202DE30[0] = monInfo->HP;
                gFormatData_202DE30[1] = monInfo->maxHPStat;
                y = sub_8013800(&gUnknown_202EE10, i);
                if (monInfo->isTeamLeader) {
                    PrintFormatStringOnWindow(9, y, gUnknown_8106BD4, 0, 0);
                }
                else {
                    PrintFormatStringOnWindow(9, y, gUnknown_8106BE0, 0, 0);
                }
            }
        }
    }

    sub_80073E0(0);
}

extern bool8 CanLeaderSwitch(u8 dungeon);

void sub_806145C(struct UnkFieldTeamMenuStruct *a0)
{
    Entity *teamMon;
    EntityInfo *monInfo;

    gUnknown_202EE6C = 0;
    teamMon = gDungeon->teamPokemon[a0->unk4[gUnknown_202EE10.menuIndex]];
    monInfo = teamMon->axObj.info;
    sub_8044F5C(0x1B, 0);
    sub_8044F5C(0x19, 0);
    if (!monInfo->isTeamLeader) {
        if (!gDungeon->unk65D && (monInfo->joinedAt.joinedAt != DUNGEON_JOIN_LOCATION_PARTNER || gDungeon->unk65C)) {
            sub_8044F5C(0x34, 0);
        }
        sub_8044F5C(0x1C, 0);
    }
    sub_8044F5C(0x30, 0);
    if (!monInfo->isTeamLeader) {
        sub_8044F5C(0x1A, 0);
        // Why checking teamLeader again?
        if (!monInfo->isTeamLeader && gDungeon->unk65C && CanLeaderSwitch(gDungeon->dungeonLocation.id)) {
            bool32 r5;

            sub_8044F5C(0x3B, 0);
            r5 = TRUE;
            if (monInfo->teamIndex >= MAX_TEAM_MEMBERS) {
                r5 = FALSE;
            }
            else {
                PokemonStruct2 *mon = &gRecruitedPokemonRef->pokemon2[monInfo->teamIndex];
                if (sub_806A538(mon->unkA)) {
                    r5 = FALSE;
                }
            }

            if (CheckVariousStatuses2(teamMon, FALSE)) {
                r5 = FALSE;
            }
            if (!r5) {
                sub_8044FF0(0x3B);
            }
        }
    }

    if (IsClientOrTeamBase(monInfo->joinedAt.joinedAt)) {
        sub_8044FF0(0x19);
        sub_8044FF0(0x3B);
        sub_8044FF0(0x1A);
        sub_8044FF0(0x30);
        sub_8044FF0(0x34);
    }

    sub_8045064();
}

void sub_80615B4(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1)
{
    SetMonsterActionFields(a0, gUnknown_202EE44[gUnknown_202EE10.menuIndex].unk0);
    a0->unk4[0].actionUseIndex = a1->unk4[a1->unk0];
}

void PrintMonTactics(s32 a0, u8 *tacticIds, EntityInfo *mon, s32 windowId);
void sub_80623B0(void);
void sub_8062D68(void);
void sub_8062230(void);
void sub_8062748(u8 a0);

extern void (*gUnknown_203B080)(s32 a0);
extern void (*gUnknown_203B084)(s32 a0);

static inline void SetTxtStruct(UnkTextStruct3 *sp)
{
    memset(sp, 0, sizeof(*sp));
    sp->a0[0].unk4 = 6;
    sp->a0[0].unk8.unk0.separate.unk0 = 2;
    sp->a0[0].unk8.unk0.separate.unk2 = 2;
    sp->a0[0].unkC = 0x12;
    sp->a0[0].unkE = 0xE;
    sp->a0[0].unk10 = 0x12;
    sp->a0[0].unk12 = 2;
    sp->a0[0].unk14 = &gUnknown_202F270;
    sp->a0[1].unk4 = 3;
    sp->a0[2].unk4 = 3;
    sp->a0[3].unk4 = 3;
}

void ShowTacticsMenu(ActionContainer *a0)
{
    UnkTextStruct3 sp;
    EntityInfo *monInfo;
    u8 tacticIds[NUM_TACTICS];
    s32 scrollFirstId;
    s32 menuIndex;
    Entity *teamMon;

    SetTxtStruct(&sp);
    teamMon = gDungeon->teamPokemon[a0->unk4[0].actionUseIndex];
    monInfo = teamMon->axObj.info;
    menuIndex = 0;
    scrollFirstId = 0;
    while (1) {
        s32 i;
        bool32 addCursor = TRUE;
        bool32 loopBreak = FALSE;

        gUnknown_202F270.f0 = 1;
        gUnknown_202F270.f1 = 0;
        gUnknown_202F270.f2 = 10;
        gUnknown_202F270.f3 = 0;
        sub_803ECB4(&sp, 1);
        PrintMonTactics(scrollFirstId, tacticIds, monInfo, 0);
        for (i = 0; i < 8; i++) {
            if (tacticIds[i] == TACTIC_UNUSED)
                break;
        }
        gUnknown_202EE10.unk1A = i;
        gUnknown_202EE10.unk1C = 8;
        gUnknown_202EE10.unk1E = 0;
        gUnknown_202EE10.unk20 = 0;
        gUnknown_202EE10.unk4 = 0;
        gUnknown_202EE10.unk6 = 16;
        gUnknown_202EE10.unkC = 0;
        gUnknown_202EE10.unkE = 0;
        gUnknown_202EE10.unk14.x = 0;
        gUnknown_202EE10.unk0 = 0;
        sub_801317C(&gUnknown_202EE10.unk28);
        sub_80137B0(&gUnknown_202EE10, 0);
        gUnknown_202EE10.menuIndex = menuIndex;
        while (1) {
            s32 i;

            AddMenuCursorSprite(&gUnknown_202EE10);
            if (tacticIds[8] != TACTIC_UNUSED) {
                sub_80623B0();
            }
            if (scrollFirstId != 0) {
                sub_8062230();
            }
            sub_803E46C(0x3D);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                if (gUnknown_202EE10.menuIndex == 7) {
                    if (tacticIds[8] != TACTIC_UNUSED) {
                        for (i = 0; i < 6; i++) {
                            gUnknown_203B080(0);
                            sub_803E46C(0x3D);
                        }
                        scrollFirstId++;
                    }
                    menuIndex = 7;
                    break;
                }
                sub_80136E0(&gUnknown_202EE10, 0);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                if (gUnknown_202EE10.menuIndex == 0) {
                    if (scrollFirstId != 0) {
                        for (i = 0; i < 6; i++) {
                            gUnknown_203B084(0);
                            sub_803E46C(0x3D);
                        }
                        scrollFirstId--;
                    }
                    menuIndex = 0;
                    break;
                }
                sub_8013744(&gUnknown_202EE10, 0);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                u32 tacticId = tacticIds[gUnknown_202EE10.menuIndex];
                menuIndex = gUnknown_202EE10.menuIndex;
                sub_8083D44();
                sub_8062748(tacticId);
                loopBreak = FALSE;
                break;
            }
            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                bool32 changed;

                u32 tacticId = tacticIds[gUnknown_202EE10.menuIndex];
                menuIndex = gUnknown_202EE10.menuIndex;
                sub_8062D68();
                sub_8083D08();
                gUnknown_202EE6C = 0;
                sub_8044F5C(0x2F, 0);
                sub_8044F5C(0xC, 0);
                if (CheckVariousStatuses2(teamMon, TRUE)) {
                    sub_8044FF0(0x2F);
                }
                sub_805FC30(&sp, 0x16);
                while (1) {
                    changed = FALSE;
                    AddMenuCursorSprite(&gUnknown_202EE10);
                    sub_803E46C(0x3D);
                    if (gRealInputs.repeated & DPAD_DOWN) {
                        sub_8083CE0(1);
                        sub_80136E0(&gUnknown_202EE10, 1);
                    }
                    if (gRealInputs.repeated & DPAD_UP) {
                        sub_8083CE0(1);
                        sub_8013744(&gUnknown_202EE10, 1);
                    }
                    if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                        if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                            changed = TRUE;
                            break;
                        }
                        sub_8083D30();
                    }
                    if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                        sub_8083D30();
                        changed = FALSE;
                        break;
                    }
                }
                if (changed) {
                    sub_8083D08();
                    if (gUnknown_202EE10.menuIndex == 0) {
                        PlaySoundEffect(0x133);
                        monInfo->tactic = tacticId;
                        monInfo->aiTarget.aiObjective = 6;
                        monInfo->aiTarget.aiTarget = NULL;
                        monInfo->aiTarget.unkC = 0;
                        monInfo->aiTarget.aiTargetSpawnGenID = 0;
                        if (!monInfo->isTeamLeader) {
                            MoveIfPossible(teamMon, TRUE);
                        }
                    }
                    else {
                        sub_8062748(tacticId);
                        addCursor = FALSE;
                    }
                }
                loopBreak = FALSE;
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                loopBreak = TRUE;
                break;
            }
        }

        if (addCursor) {
            AddMenuCursorSprite(&gUnknown_202EE10);
        }
        sub_803E46C(0x3D);
        if (loopBreak)
            break;
    }
    sub_803EAF0(0, NULL);
}

extern void GetAvailTacticsforLvl(u8 *tacticsBuffer, s32 pokeLevel);

void PrintMonTactics(s32 firstId, u8 *tacticIds, EntityInfo *mon, s32 windowId)
{
    u8 tacticsBuffer[NUM_TACTICS];
    u32 tactic;
    s32 y, i, j;

    firstId--;
    sub_80073B8(windowId);
    PrintStringOnWindow(0x10, 0, gUnknown_80FE954, windowId, 0);
    y = 0x14;
    for (j = 0; j < 9; j++) {
        tacticIds[j] = TACTIC_UNUSED;
    }
    GetAvailTacticsforLvl(tacticsBuffer, GetLeaderInfo()->level);
    for (i = -1; i < 10; i++, y += 12, firstId++) {
        if (firstId < 0)
            continue;
        if (firstId >= NUM_TACTICS)
            continue;

        tactic = tacticsBuffer[firstId];
        if (i >= 0 && i < 9) {
            tacticIds[i] = tactic;
        }
        if (tactic == TACTIC_UNUSED)
            break;

        CopyTacticsNameToBuffer(gAvailablePokemonNames, tactic);
        if (mon->tactic == tactic) {
            PrintFormatStringOnWindow(0x10, y, gUnknown_8106BEC, windowId, 0);
        }
        else {
            PrintFormatStringOnWindow(0x10, y, gUnknown_8106BF4, windowId, 0);
        }
    }

    sub_80073E0(windowId);
}
