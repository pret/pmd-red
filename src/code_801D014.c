#include "global.h"
#include "globaldata.h"
#include "constants/friend_area.h"
#include "bg_palette_buffer.h"
#include "code_800D090.h"
#include "code_801D014.h"
#include "code_80227B8.h"
#include "friend_list.h"
#include "code_8024458.h"
#include "code_80958E8.h"
#include "common_strings.h"
#include "def_filearchives.h"
#include "event_flag.h"
#include "friend_area.h"
#include "friend_area_action_menu.h"
#include "friend_list_menu.h"
#include "ground_lives.h"
#include "ground_main.h"
#include "ground_map_1.h"
#include "input.h"
#include "iq_skill_menu.h"
#include "memory.h"
#include "menu_input.h"
#include "options_menu1.h"
#include "party_list_menu.h"
#include "rescue_team_info.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "wigglytuff_shop2.h"
#include "wonder_mail_802C4C8.h"
#include "wonder_mail_802C860.h"

static EWRAM_INIT struct unk_203B250 *sUnknown_203B250 = {NULL};
static EWRAM_INIT u32 sUnknown_203B254 = {0};

#include "data/code_801D014.h"

static void LoadTeamRankBadge(u32, u32, u32);

static void sub_801D208(u32 newState);
static void sub_801D220(void);
static void sub_801D3A8(void);
static void sub_801D4C0(void);
static void sub_801D680(void);
static void sub_801D760(void);
static void sub_801D77C(void);
static void sub_801D798(void);
static void sub_801D7CC(void);
static void sub_801D808(void);
static void sub_801D824(void);
static void sub_801D840(void);
static void sub_801D85C(void);
static void sub_801D878(void);
static void sub_801D894(void);

bool8 sub_801D014(PokemonStruct1 *a0)
{
    s32 index;
    PokemonStruct1 *pokemon;
    struct unk_203B250 *preload;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    sUnknown_203B250 = MemoryAlloc(sizeof(struct unk_203B250), 8);
    sUnknown_203B250->menuAction = sUnknown_203B254;
    sUnknown_203B250->pokeStruct = a0;

    if (sUnknown_203B250->pokeStruct != NULL) {
        for (index = 0; index < NUM_MONSTERS; index++) {
            preload = sUnknown_203B250;
            pokemon = &gRecruitedPokemonRef->pokemon[(s16)index]; // cast is needed here

            if (preload->pokeStruct == pokemon) {
                preload->index = index;
                break;
            }
        }
    }
    else
        sUnknown_203B250->index = NUM_MONSTERS;

    sUnknown_203B250->currFriendAreaLocation = sub_8002658(sub_80A5728());
    sUnknown_203B250->unk8 = 0;
    sUnknown_203B250->unk9 = 0;
    sUnknown_203B250->unkC = GetPlayerPokemonStruct();
    sUnknown_203B250->unk7 = 0;

    if (sUnknown_203B250->pokeStruct != NULL)
        sub_801D208(5);
    else
        sub_801D208(0);

    return TRUE;
}

u32 sub_801D0DC(void)
{
    switch (sUnknown_203B250->state) {
        case 0:
        case 1:
            sub_801D680();
            break;
        case 3:
            sub_801D760();
            break;
        case 4:
            sub_801D77C();
            break;
        case 5:
            sub_801D798();
            break;
        case 6:
        case 7:
            sub_801D7CC();
            break;
        case 8:
            sub_801D808();
            break;
        case 9:
            sub_801D824();
            break;
        case 10:
            sub_801D840();
            break;
        case 11:
            sub_801D85C();
            break;
        case 12:
            sub_801D878();
            break;
        default:
            return 3;
    }
    return 0;
}

u32 sub_801D178(void)
{
    PokemonStruct1 *pokeStruct;

    if (sUnknown_203B250->unk9 != 0)
        return 2;

    if (sUnknown_203B250->unk7 != 0)
        return 3;

    if (sUnknown_203B250->unk8 != 0)
        return 1;

    if (sUnknown_203B250->unkC != GetPlayerPokemonStruct())
        goto _ret4;

    if ((s16) sub_80A7AE8(7) < 0)
        return 0;

    pokeStruct = sub_808D3F8();
    if (!(pokeStruct->unk0 >> 1 & 1))
_ret4:
        return 4;

    return 0;
}

u8 sub_801D1D4(void)
{
    return sUnknown_203B250->unk7;
}

void sub_801D1E0(void)
{
    if (sUnknown_203B250 != NULL) {
        sUnknown_203B254 = sUnknown_203B250->menuAction;
        MemoryFree(sUnknown_203B250);
        sUnknown_203B250 = NULL;
    }
}

static void sub_801D208(u32 newState)
{
    sUnknown_203B250->state = newState;
    sub_801D220();
    sub_801D3A8();
}

static void sub_801D220(void)
{
    s32 i;

    RestoreSavedWindows(&sUnknown_203B250->windows);

    switch (sUnknown_203B250->state) {
        case 0:
            sub_801D4C0();

            if (sUnknown_203B250->pokeStruct != NULL) {
                for (i = 0; i < 4; i++)
                    sUnknown_203B250->windows.id[i] = sUnknown_80DBE7C;

                sUnknown_203B250->windows.id[0] = sUnknown_80DBE98;
                sub_8012CAC(&sUnknown_203B250->windows.id[0], sUnknown_203B250->unk68);
                sUnknown_203B250->windows.id[0].width = 9;
            }
            else {
                for (i = 0; i < MAX_WINDOWS; i++)
                    sUnknown_203B250->windows.id[i] = sUnknown_80DBEB0[i];

                sub_8012CAC(&sUnknown_203B250->windows.id[0], sUnknown_203B250->unk68);
                sUnknown_203B250->windows.id[0].width = 8;
            }
            break;
        case 1:
            sub_801D4C0();

            if (sUnknown_203B250->pokeStruct != NULL) {
                for (i = 0; i < MAX_WINDOWS; i++)
                    sUnknown_203B250->windows.id[i] = sUnknown_80DBE7C;

                sUnknown_203B250->windows.id[0] = sUnknown_80DBE98;
                sub_8012CAC(&sUnknown_203B250->windows.id[0], sUnknown_203B250->unk68);
                sUnknown_203B250->windows.id[0].width = 9;
            }
            else {
                for (i = 0; i < MAX_WINDOWS; i++)
                    sUnknown_203B250->windows.id[i] = sUnknown_80DBEB0[i];

                sub_8012CAC(&sUnknown_203B250->windows.id[0], sUnknown_203B250->unk68);
                sUnknown_203B250->windows.id[0].width = 8;
            }
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B250->windows.id[i] = sUnknown_80DBE7C;
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B250->windows, TRUE, TRUE);
}

static void sub_801D3A8(void)
{
    switch (sUnknown_203B250->state) {
        case 0:
        case 1:
            if (sUnknown_203B250->pokeStruct != NULL) {
                PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0], sUnknown_203B250->pokeStruct, 7);
                sUnknown_203B250->unk18.unk0 = gFormatBuffer_Monsters[0];
                sub_8012D60(&sUnknown_203B250->unk18, sUnknown_203B250->unk68, 0, sUnknown_203B250->unkA8, sUnknown_203B250->menuAction, 0);
            }
            else {
                sub_801D894();
                sub_8012D60(&sUnknown_203B250->unk18, sUnknown_203B250->unk68, 0, sUnknown_203B250->unkA8, sUnknown_203B250->menuAction, 0);
            }
            break;
        case 3:
            sub_80227B8(sUnknown_203B250->pokeStruct);
            break;
        case 4:
            sub_8027074();
            break;
        case 5:
            CreatePartyListMenu(sUnknown_203B250->pokeStruct);
            break;
        case 6:
            CreateFriendListMenu(0);
            break;
        case 7:
            CreateFriendListMenu(1);
            break;
        case 8:
            sub_8024458(sUnknown_203B250->index, 2);
            break;
        case 9:
            CreateIQSkillMenu(sUnknown_203B250->index);
            break;
        case 10:
            CreateWigglytuffShopFriendAreaMenu(sUnknown_203B250->currFriendAreaLocation, TRUE, 2);
            break;
        case 11:
            InitializeJobListMenu(0);
            break;
        case 12:
            sub_801DCC4();
            break;
    }
}

static void sub_801D4C0(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sUnknown_203B250->unkA8, 0, sizeof(sUnknown_203B250->unkA8));

    if (sUnknown_203B250->currFriendAreaLocation == 0) {
        if (sub_8096E2C()) {
            sUnknown_203B250->unk68[loopMax].menuAction = 2;
            sUnknown_203B250->unk68[loopMax].text = sItems;
            if (GetNumberOfFilledInventorySlots() == 0)
                sUnknown_203B250->unkA8[loopMax] = 1;

            loopMax++;
            sUnknown_203B250->unk68[loopMax].text = sTeam;
            sUnknown_203B250->unk68[loopMax].menuAction = 4;

            loopMax++;
            if (sub_80023E4(2)) {
                sUnknown_203B250->unk68[loopMax].text = sJobList;
                sUnknown_203B250->unk68[loopMax].menuAction = 9;
                if (HasNoAcceptedJobs())
                    sUnknown_203B250->unkA8[loopMax] = 1;

                loopMax++;
            }
        }

        sUnknown_203B250->unk68[loopMax].text = sOthers;
        sUnknown_203B250->unk68[loopMax].menuAction = 11;
        loopMax++;
    }
    else {
        strcpy(gFormatBuffer_Monsters[0], sTripleQuestionMark);

        if (sub_8096E2C()) {
            sUnknown_203B250->unk68[loopMax].text = gCommonFriend[0];
            sUnknown_203B250->unk68[loopMax].menuAction = 5;
            if (sub_8024108(4))
                sUnknown_203B250->unkA8[loopMax] = 1;

            loopMax++;
            sUnknown_203B250->unk68[loopMax].menuAction = 2;
            sUnknown_203B250->unk68[loopMax].text = sItems;
            if (GetNumberOfFilledInventorySlots() == 0)
                sUnknown_203B250->unkA8[loopMax] = 1;

            loopMax++;
        }

        sUnknown_203B250->unk68[loopMax].text = gCommonInfo[0];
        sUnknown_203B250->unk68[loopMax].menuAction = 8;

        loopMax++;
        sUnknown_203B250->unk68[loopMax].text = gCommonExit[0];
        sUnknown_203B250->unk68[loopMax].menuAction = 10;

        loopMax++;
    }

    sUnknown_203B250->unk68[loopMax].text = NULL;
    sUnknown_203B250->unk68[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B250->unkA8[index] == 0) {
            if (sUnknown_203B250->unk68[index].menuAction == sUnknown_203B250->menuAction)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B250->unkA8[index] == 0) {
            sUnknown_203B250->menuAction = sUnknown_203B250->unk68[index].menuAction;
            break;
        }
    }
}

static void sub_801D680(void)
{
    s32 menuAction;

    menuAction = 0;

    if (!sub_8012FD8(&sUnknown_203B250->unk18)) {
        sub_8013114(&sUnknown_203B250->unk18, &menuAction);
        if (menuAction != 1)
            sUnknown_203B250->menuAction = menuAction;
    }

    switch (menuAction) {
        case 2:
            sub_801D208(3);
            break;
        case 4:
            sub_801D208(6);
            break;
        case 3:
            sub_801D208(4);
            break;
        case 5:
            sub_801D208(7);
            break;
        case 6:
            sub_801D208(8);
            break;
        case 7:
            sub_801D208(9);
            break;
        case 8:
            sub_801D208(10);
            break;
        case 9:
            sub_801D208(11);
            break;
        case 10:
            sUnknown_203B250->unk9 = 1;
            sub_801D208(2);
            break;
        case 11:
            sub_801D208(12);
            break;
        case 1:
            sub_801D208(2);
            break;
    }
}

static void sub_801D760(void)
{
    switch (sub_8022860()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_8022908();
            sub_801D208(1);
            break;
    }
}

static void sub_801D77C(void)
{
    switch (sub_80270A4()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_8027168();
            sub_801D208(1);
            break;
    }
}

static void sub_801D798(void)
{
    switch (sub_8025F68()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            if (sub_802604C())
                sUnknown_203B250->unk7 = sUnknown_203B250->currFriendAreaLocation;

            CleanPartyListMenu();
            sub_801D208(2);
            break;
    }
}

static void sub_801D7CC(void)
{
    switch (sub_8025354()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sUnknown_203B250->unk7 = sub_802540C();
            CleanFriendListMenu();

            if (sUnknown_203B250->unk7 != 0)
                sub_801D208(2);
            else
                sub_801D208(1);
            break;
    }
}

static void sub_801D808(void)
{
    switch (sub_80244E4()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_802453C();
            sub_801D208(1);
            break;
    }
}

static void sub_801D824(void)
{
    switch (sub_801BF48()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            CleanIQSkillMenu();
            sub_801D208(1);
            break;
    }
}

static void sub_801D840(void)
{
    switch (HandleWigglytuffShopFriendAreaMenuInput()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            CleanWigglytuffShopFriendAreaInfoMenu();
            sub_801D208(1);
            break;
    }
}

static void sub_801D85C(void)
{
    switch (sub_802C898()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_802C8F4();
            sub_801D208(1);
            break;
    }
}

static void sub_801D878(void)
{
    switch (sub_801DCE8()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801DD50();
            sub_801D208(1);
            break;
    }
}

static void sub_801D894(void)
{
    const u8 *location;
    s32 location_length;
    s32 x_coord;
    u8 buffer[100]; // sp +4

    if (sUnknown_203B250->currFriendAreaLocation == FRIEND_AREA_NONE)
        location = sub_8098FB4();
    else
        location = GetFriendAreaName(sUnknown_203B250->currFriendAreaLocation);

    FormatString(location, buffer, buffer + sizeof(buffer), 0);
    location_length = sub_8008ED0(buffer);
    x_coord = (128 - location_length) / 2; // Centers the location name
    CallPrepareTextbox_8008C54(1);
    sub_80073B8(1);
    PrintStringOnWindow(x_coord, 4, buffer, 1, 0);
    sub_80073E0(1);
    CallPrepareTextbox_8008C54(2);
    sub_80073B8(2);
    LoadTeamRankBadge(2, 8, 6);

    // %s {COLOR CYAN}%d{RESET} Pts.
    sprintfStatic(buffer, sFmtPointsCyan, GetTeamRankString(GetRescueTeamRank()), GetTeamRankPts());
    PrintStringOnWindow(32, 4, buffer, 2, 0);
    sprintfStatic(buffer, sFmtMoneyCyan, gTeamInventoryRef->teamMoney);
    PrintStringOnWindow(32, 18, buffer, 2, 0);
    sub_80073E0(2);
}

static void LoadTeamRankBadge(u32 a0, u32 a1, u32 a2)
{
    OpenedFile *teamBadgeFile;
    s32 paletteIndex;
    u8 rank;
    RGB *colorArray;
    u8 *teamBadgePic;

    teamBadgeFile = OpenFileAndGetFileDataPtr(sTeamRankBadgeFileName, &gTitleMenuFileArchive);
    teamBadgePic = ((struct TeamBadgeData *)(teamBadgeFile->data))->pics;
    colorArray = ((struct TeamBadgeData *)(teamBadgeFile->data))->palette;

    for (paletteIndex = 0; paletteIndex < 16; paletteIndex++) {
        SetBGPaletteBufferColorArray(paletteIndex + 224, colorArray);
        colorArray++;
    }

    rank = GetRescueTeamRank();
    teamBadgePic = &teamBadgePic[rank * 128];
    sub_8007E20(a0, a1, a2, 16, 16, (void *) teamBadgePic, 14);
    CloseFile(teamBadgeFile);
}
