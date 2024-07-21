#include "global.h"
#include "structs/str_dungeon.h"
#include "number_util.h"
#include "input.h"
#include "structs/map.h"
#include "code_80521D0.h"
#include "dungeon_action.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_util.h"
#include "dungeon_map_access.h"
#include "game_options.h"
#include "dungeon_leader.h"
#include "dungeon_visibility.h"
#include "bg_control.h"
#include "items.h"
#include "code_806CD90.h"
#include "dungeon_capabilities.h"

void sub_806A2BC(Entity *a0, u8 a1);
bool8 sub_805E874(void);
bool8 sub_80701A4(Entity *a0);
void sub_80647F0(Entity *a0);
void sub_805E738(Entity *a0);
void sub_803E708(s32 a0, s32 a1);
void sub_8040A78(void);
void sub_805E804(void);
void sub_8075680(u32);
void sub_8094C88(void);
void sub_8040A84(void);
void sub_8047158(void);
void sub_804AA60(void);
void sub_80532B4(void);
void sub_806A914(u8 a0, u8 a1, u8 a2);
void sub_8044C10(u8 a0);
u16 sub_805F1AC(void);
void sub_80978C8(s16 a0);
void sub_8044C50(u16 a0);
void sub_805E2C4(Entity *leader);
bool8 sub_8094C48(void);
void sub_8052210(u8 a0);
void sub_803E46C(s32 a0);
bool8 sub_805EC4C(Entity *a0, u16 a1);
void sub_803E724(s32 a0);
void HandleTalkFieldAction(Entity *);
bool8 sub_8044B28(void);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
void ShowFieldMenu(u8 a0, u8 a1);
bool8 sub_805EF60(Entity *a0, EntityInfo *a1);
s32 GetTeamMemberEntityIndex(Entity *pokemon);

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

#ifdef NONMATCHING

struct UnkR6Struct {
    u8 a0_8;
    u8 a0_16;
    u8 a0_24;
};

void sub_805D8C8(void)
{
    struct UnkR6Struct r6;
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
            if (sub_805F1AC() != 0) {
                return;
            }
        }
    }

    sub_806A914(1, 1, 1);
    while (1) {

        leader = GetLeader();
        leaderInfo = leader->info;

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

            if (gRealInputs.held & A_BUTTON && gRealInputs.held & B_BUTTON && RoundUpFixedPoint(leaderInfo->belly) != 0) {
                sub_8044C50(1);
                gDungeon->unk673 = 1;
                break;
            }

            r9 = 0;
            if (gRealInputs.pressed & A_BUTTON) {
                if (gRealInputs.held & B_BUTTON) {
                    if (RoundUpFixedPoint(leaderInfo->belly) != 0) {
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
                        if ((gRealInputs.held & B_BUTTON || aaa != 0) && RoundUpFixedPoint(leaderInfo->belly) != 0) {
                            if (leader->info->volatileStatus.volatileStatus != 2) {
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
"bl sub_805F1AC\n"
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
"bl RoundUpFixedPoint\n"
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
"bl RoundUpFixedPoint\n"
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
"bl RoundUpFixedPoint\n"
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

/* Nope
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
    EntityInfo *entityInfo = a0->info;
    if (entityInfo->eyesightStatus.eyesightStatus != 1 && entityInfo->eyesightStatus.eyesightStatus != 2) {
        // What???
        for (i = 0; i < 1; i++) {
            bool8 r9 = FALSE;
            u32 r5 = entityInfo->action.direction;
            r5++;
            for (j = 1; j < 8; j++, r5++) {
                r5 &= 7;
                tile = GetTile(a0->pos.x + gAdjacentTileOffsets[r5].x, a0->pos.y + gAdjacentTileOffsets[r5].y);
                if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER) {
                    EntityInfo *tileMonsterInfo = tile->monster->info;
                    if (CanSeeTarget(a0, tile->monster)) {
                        if (i != 0 || tileMonsterInfo->isNotTeamMember) {
                            r9 = TRUE;
                            break;
                        }
                    }
                }
            }
            if (r9) {
                a0->info->action.direction = r5 & 7;
                sub_806CDD4(a0, sub_806CEBC(a0), r5);
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
    s32 direction = leader->info->action.direction;
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
