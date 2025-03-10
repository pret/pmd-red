#include "global.h"
#include "dungeon_util_1.h"
#include "memory.h"
#include "structs/rgb.h"
#include "structs/sprite_oam.h"
#include "structs/str_dungeon_8042F6C.h"
#include "code_803E46C.h"
#include "code_800E9E4.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "dungeon_util.h"
#include "dungeon_message.h"
#include "dungeon_generation.h"
#include "bg_control.h"
#include "random.h"
#include "file_system.h"
#include "dungeon_leader.h"
#include "dungeon.h"
#include "dungeon_ai.h"
#include "pokemon.h"
#include "cpu.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "code_8009804.h"
#include "tile_types.h"
#include "text.h"
#include "code_805D8C8.h"
#include "code_803E668.h"
#include "dungeon_engine.h"
#include "dungeon_map_access.h"
#include "pokemon.h"
#include "weather.h"
#include "moves.h"
#include "code_8094F88.h"
#include "code_8099360.h"
#include "bg_palette_buffer.h"
#include "exclusive_pokemon.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "constants/trap.h"
#include "dungeon_serializer.h"
#include "dungeon_config.h"
#include "dungeon_map.h"

extern void sub_800EE5C(s32);
extern void sub_800EF64(void);
extern void sub_800F15C(s32);

struct UnkStruct_203B414
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[16];
    s32 unk4C[16];
    struct DungeonPos unk8C[16];
};

EWRAM_INIT DungeonPos gPlayerDotMapPosition = {100, 100};
static EWRAM_INIT struct UnkStruct_203B414 *sUnknown_203B414 = NULL;
EWRAM_INIT Dungeon *gDungeon = NULL;
EWRAM_INIT u8 *gSerializedData_203B41C = NULL;
EWRAM_INIT u8 gUnknown_203B420[8] = {0x15, 0x00, 0x16, 0x00, 0x15, 0x00, 0x16, 0x00}; // Could be a different file?
EWRAM_INIT u8 gUnknown_203B428[8] = {0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x02}; // Could be a different file?

struct UnkStruct_80F6624
{
    s16 unk0;
    s32 unk4;
};

extern const struct UnkStruct_80F6624 gUnknown_80F6624[][3];

extern const unkStruct_2039DB0 gUnknown_80F683C;

void sub_8042B34(s32 a0, s32 a1, s32 a2)
{
    unkStruct_80416E0 spStruct;
    unkStruct_2039DB0 stack1C;
    s32 i;
    s32 r8 = 0;
    Entity *leader = xxx_call_GetLeader();
    sUnknown_203B414 = MemoryAlloc(sizeof(*sUnknown_203B414), 7);

    sUnknown_203B414->unk0 = a0;
    sUnknown_203B414->unk8 = (a1 + 1) * 4;
    sub_800EE5C(gUnknown_80F6624[a0][0].unk0);
    sub_800EF64();
    sub_803E46C(0x46);
    sUnknown_203B414->unk4 = a2;
    for (i = 0; i < sUnknown_203B414->unk8; i++) {
        s32 rnd;

        spStruct.unk0 = gUnknown_80F6624[sUnknown_203B414->unk0][r8].unk0;
        spStruct.unk4 = i;
        spStruct.dir = 0;
        spStruct.x = leader->pixelPos.x / 256;
        spStruct.y = leader->pixelPos.y / 256;

        rnd = RandInt(2);
        sUnknown_203B414->unk4C[i] = (gUnknown_80F6624[sUnknown_203B414->unk0][r8].unk4 * 2) + rnd;
        sUnknown_203B414->unk8C[i].x = RandInt(240) + 152;
        sUnknown_203B414->unk8C[i].y = RandInt(8 + (i * 2)) - (((i - (i / 4 * 4)) * 40) - 24);

        spStruct.unk10 = sUnknown_203B414->unk8C[i].x;
        spStruct.unk12 = sUnknown_203B414->unk8C[i].y;
        spStruct.unk14 = 4;
        spStruct.unk18 = 0xFFFF;
        stack1C = gUnknown_80F683C;
        sUnknown_203B414->unkC[i] = sub_800E890(&spStruct);

        r8++;
        if (r8 >= 3 || gUnknown_80F6624[sUnknown_203B414->unk0][r8].unk0 == 0) {
            r8 = 0;
        }

        sub_800F15C(sub_800ECA4(spStruct.unk0)->effectId);
    }
}

bool8 sub_8042CC0(void)
{
    s32 i;
    bool8 ret = FALSE;

    if (sUnknown_203B414->unk4 != 0) {
        ret = TRUE;
        sUnknown_203B414->unk4--;
    }

    for (i = 0; i < sUnknown_203B414->unk8; i++) {
       sUnknown_203B414->unk8C[i].x -= sUnknown_203B414->unk4C[i];
       if (sUnknown_203B414->unk8C[i].x <= -152) {
            if (sUnknown_203B414->unk4 > 0) {
                sUnknown_203B414->unk8C[i].x = 152;
            }
            else {
                sUnknown_203B414->unk8C[i].x = -152;
            }
       }
       else {
            ret = TRUE;
       }
       sub_800E8AC(sUnknown_203B414->unkC[i], NULL, &sUnknown_203B414->unk8C[i], 0, NULL);
    }

    sub_800E90C(&gDungeon->unk181e8.cameraPixelPos);
    return ret;
}

void sub_8042D7C(void)
{
    s32 i;

    if (sUnknown_203B414 == NULL)
        return;

    for (i = 0; i < sUnknown_203B414->unk8; i++) {
        if (sub_800E9A8(sUnknown_203B414->unkC[i])) {
            sub_800DC14(sUnknown_203B414->unkC[i]);
        }
    }
    sub_800DBBC();
    MemoryFree(sUnknown_203B414);
    sUnknown_203B414 = NULL;
}

extern s32 sub_800E6D8(s32);

// TODO: Figure out if a new file should start here
void sub_8042DD4(s32 a0, Entity *a1, s32 a2)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 == -1) {
            strPtr->unk0 = a0;
            strPtr->unkC = a1;
            strPtr->unk4 = a2;
            strPtr->unk8 = sub_800E6D8(a0);
            return;
        }
    }
}

UNUSED bool32 sub_8042E1C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 != -1 && sub_800E9A8(strPtr->unk0)) {
            return TRUE;
        }
    }

    return FALSE;
}

void sub_8042E5C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 >= 0 && !sub_800E9A8(strPtr->unk0)) {
            strPtr->unk0 = -1;
            strPtr->unkC = NULL;
        }
    }
}

void sub_8042E98(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        strPtr->unk0 = -1;
        strPtr->unk4 = 0;
        strPtr->unkC = NULL;
    }
}

extern void sub_800569C(DungeonPos *, axdata *, u8);
extern void sub_800EB24(s32 param_1, DungeonPos *param_2, DungeonPos *param_3,
			s32 param_4, s32 param_5);

void sub_8042EC8(Entity *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 >= 0 && strPtr->unkC == a0) {
            DungeonPos sp8 = {a0->pixelPos.x / 256, a0->pixelPos.y / 256};
            DungeonPos sp4 = {0};
            EntityInfo *entInfo = GetEntInfo(a0);

            if (strPtr->unk8 != -1) {
                sub_800569C(&sp4,
                            &a0->axObj.axdata,
                            strPtr->unk8);
            }

            sub_800EB24(strPtr->unk0, &sp8, &sp4,a1, entInfo->action.direction);
        }
    }
}

extern u8 gUnknown_203B40C;


extern void sub_8040094(u8 r0);
extern void sub_8068BDC(u8 r0);
extern s16 GetTurnLimit(u8 dungeon);
extern void sub_8041888(u8 param_1);
extern void sub_803D4AC(void);
extern void sub_804513C(void);
extern void sub_8043CD8(void);
extern void sub_803E250(void);
extern void sub_803E830(void);
extern void sub_803E214(void);
extern void nullsub_56(void);
extern void sub_8047104(void);
extern void sub_8068F28(void);
extern void sub_806C1D8(void);
extern void sub_804700C(void);
extern void IncrementThievingSuccesses(void);
extern void sub_803E13C(void);
extern void sub_80841EC(void);
extern void sub_8084424(void);
extern void sub_8086130(void);
extern void FreeDungeonPokemonSprites(void);
extern void sub_803DF60(void);
extern void sub_803E02C(void);
extern void sub_80847D4(void);
extern void sub_8043D60(void);
extern void sub_806890C(void);
extern void sub_80840A4(void);
extern void sub_803E178(void);
extern void sub_80848F0(void);
extern void IncrementAdventureFloorsExplored(void);
extern void sub_806AB2C(void);
extern void DisplayPreFightDialogue(void);
extern void sub_8071DA4(Entity *);
extern void sub_803E748(void);
extern void sub_8083D68(void);
extern void sub_803E7C8(void);
extern void ShowWholeRevealedDungeonMap(void);
extern void sub_807E5AC(void);
extern void TriggerWeatherAbilities(void);
extern void sub_807E88C(void);
extern void InitDungeonPokemonSprites(void);
extern void nullsub_16(void);
extern void sub_80521D0(void);
extern void sub_803F27C(u8);
extern void sub_807E7FC(u8);
extern bool8 IsLevelResetTo1(u8 dungeon);
extern void sub_8068A84(PokemonStruct1 *pokemon);
extern void sub_807EAA0(u32, u32);
extern void sub_803D4D0(void);
extern void sub_80842F0(void);
extern void sub_80427AC(void);
extern void sub_806AA70(void);
extern void sub_803D8F0(void);
extern void sub_806AD3C(void);
extern void sub_806C42C(void);
extern void sub_806B678(void);
extern void sub_806C3C0(void);
extern void sub_806B168(void);
extern void sub_806B6C4(void);
extern void sub_806A338(void);
extern void sub_8051E3C(void);
extern void sub_8045CB0(void);
extern void sub_807FA18(void);
extern void sub_806A974(void);
extern void sub_806CF60(void);
extern void sub_8068F80(void);
extern bool8 sub_8044B28(void);
extern bool8 sub_8083C24(void);
extern bool8 sub_8083C88(u8 param_1);
extern bool8 sub_8043ED0(bool8);
extern void ShowDungeonNameBanner(void);
extern void sub_803EAF0(u32, u32);
extern void sub_806A914(bool8 a0, bool8 a1, bool8 showRunAwayEffect);
extern void sub_803F4A0(Entity *a0);
extern void sub_8083AB0(s16 param_0, Entity * target, Entity * entity);
extern void sub_8046F84(s32 itemFlag);
extern bool8 sub_8083C50(void);
extern void sub_8068FE0(Entity *, u32, Entity *r2);
extern void ResetMonEntityData(EntityInfo *, u32);
extern s32 GetMovesLearnedAtLevel(u16* dst, s16 species, s32 level, s32 IQPoints);
extern bool8 IsKeepMoney(u8 dungeon);
extern void sub_8042B0C(Entity *);

extern s16 gUnknown_2026E4E;
extern u8 gUnknown_202F32C;
extern u8 gUnknown_202F1A8;
extern s32 gDungeonBrightness;
extern Entity *gLeaderPointer;

void EnforceMaxItemsAndMoney(void);
static void sub_8043FD0(void);
void sub_806B404(void);
u8 GetFloorType(void);

extern const u8 *gUnknown_80FEC48;
extern const u8 *gUnknown_80FEC7C;
extern const u8 *gUnknown_81002B8;
extern const u8 *gPtrFinalChanceMessage;
extern const u8 *gPtrClientFaintedMessage;
extern const u8 *const gUnknown_80F89B4;
extern const u8 *const gUnknown_80F89D4;
extern const u8 *const gUnknown_80F89D8;

extern const s16 gUnknown_80F6850[4];

extern OpenedFile *gDungeonNameBannerPalette;

// This functions is the main 'loop' when the player is in a Dungeon. It runs from the moment the player enters a dungeon, until they leave(by completing or by fainting).
// arm9.bin::0206A848
void RunDungeon(UnkStruct_RunDungeon *r8)
{
    bool8 check;
    Entity *leader;
    u8 *dungeonPtr;
    s32 i;
    bool8 r6;
    bool8 r9;
    bool8 r10;
    u8 sp;
    RGB color;

    gUnknown_203B40C = 0;
    r6 = r8->unk8;
    r9 = r8->unk11;
    r10 = r8->unk10;
    gSerializedData_203B41C = r8->unk74;
    gDungeon = r8->unk78;
    if (!r6) {
        *gSerializedData_203B41C = 0;
    }

    // Why not use memset?
    dungeonPtr = (u8 *)(gDungeon);
    for (i = 0; i < sizeof(Dungeon); i++) {
        dungeonPtr[i] = 0;
    }

    gPlayerDotMapPosition.x = 0; // Needed to match
    gPlayerDotMapPosition.x = 100;

    if (!r6) {
        gDungeon->unk644.unk34 = r8->unkF;
        gDungeon->unk644.unk8 = r8->unk14;
        gDungeon->unk644.windTurns = GetTurnLimit(r8->unk4.id);
        gDungeon->unk644.unk36 = 0;
        gDungeon->unk644.unk37 = GetRescuesAllowed(r8->unk4.id);
    }
    gDungeon->unk644.unk54 = 0;
    gDungeon->unk644.unk55 = 0;
    gDungeon->unk644.unk18 = r8->unk9;
    gDungeon->unk644.unk16 = r8->unkC;
    gDungeon->unk644.unk14 = r8->unkA;
    gDungeon->unk644.unk15 = r8->unkB;
    gDungeon->unk644.unk17 = r8->unkD;
    gDungeon->unk644.unk19 = r8->unkE;
    StopDungeonBGM();
    sub_803D4AC();
    sub_804513C();
    sub_8043CD8();
    sub_80495E4();
    sub_803E250();
    OpenDungeonMapFile();
    SetDungeonMapToNotShown();
    sub_803F27C(1);
    gUnknown_2026E4E = 2056;
    sub_80095CC(1, 0x14);
    sub_800DAC0(0);
    UpdateFadeInTile(1);
    sub_803DF60();
    sub_803E02C();
    sub_8042E98();
    gUnknown_202F32C = 0;
    if (r6) {
        ReadDungeonState(gSerializedData_203B41C, 0x4800);
        sub_8049840();
    }
    if (r9) {
        sub_8043D60();
    }

    if (!r6) {
        gDungeon->unk181e8.allTilesRevealed = 1;
        gDungeon->unk181e8.unk1820C = 1;
        if (gDungeon->unk644.unk34 == 1) {
            gDungeon->unk644.dungeonLocation.id = r8->unk14.unk0;
            gDungeon->unk644.dungeonLocation.floor = 1;
        }
        else {
            gDungeon->unk644.dungeonLocation = r8->unk4;
        }

        gDungeon->unk644.unk30 = 0;
        EnforceMaxItemsAndMoney();
    }
    if (!r6) {
        if (gDungeon->unk644.unk34 == 1) {
            gDungeon->unk644.unk38 = r8->unk14.unk4;
        }
        else {
            gDungeon->unk644.unk38 = Rand32Bit() & 0xFFFFFF;
        }
        sub_808408C(gDungeon->unk644.unk38);
    }
    if (!r6) {
        if (!sub_80980A4() && gDungeon->unk644.dungeonLocation.id == DUNGEON_TINY_WOODS) {
            sub_8043FD0();
        }
        sub_806890C();
    }

    if (r9) {
        gFormatArgs[0] = gDungeon->unk644.unk37;
        if (gFormatArgs[0] != 0) {
            DisplayDungeonMessage(0, gUnknown_80FEC48, 1);
        }
        else {
            DisplayDungeonMessage(0, gUnknown_80FEC7C, 1);
        }
    }

    if (r10) {
        r8->unk1C.heldItem.id = 0;
        if (IsLevelResetTo1(gDungeon->unk644.dungeonLocation.id)) {
            sub_808D0D8(&r8->unk1C);
        }
        sub_8068A84(&r8->unk1C);
        if (r6) {
            sub_806B404();
        }
    }

    OpenDungeonPaletteFile();
    if (!r6 && gDungeon->unk644.unk34 == 1) {
        if (sub_8099394(&sp)) {
            unkStruct_203B480 *mailStr = GetMailatIndex(sp);
            if (mailStr->rescuesAllowed) {
                gFormatArgs[0] = mailStr->rescuesAllowed;
                DisplayDungeonMessage(0, gUnknown_81002B8, 1);
            }
            else {
                DisplayDungeonMessage(0, gPtrFinalChanceMessage, 1);
            }
        }
    }

    while (1) {
        sub_8098080();
        nullsub_16();
        sub_80521D0();
        ResetMessageLog();
        InitDungeonPokemonSprites();
        if (!r6) {
            sub_804513C();
        }
        gLeaderPointer = NULL;
        gDungeon->unk0 = 0;
        if (!r6) {
            gDungeon->unk644.unk3C = YetAnotherRandom24();
            gDungeon->unk644.unk24 = 10;
            InitDungeonRNG(gDungeon->unk644.unk3C);
        }
        gDungeon->unk37EC = 0;
        if (!r6) {
            s32 rnd;

            gDungeon->decoyIsActive = FALSE;
            rnd = DungeonRandInt(4);
            gDungeon->unk37FD = 0;
            gDungeon->deoxysDefeat = FALSE;
            gDungeon->deoxysForm = gUnknown_80F6850[rnd];
            gDungeon->unk37FF = 0;
            gDungeon->unk644.unk31 = 0;
        }
        sub_803D4D0();
        gDungeon->unk1 = 0;
        gDungeon->unk10 = 0;
        gDungeon->unk2 = 0;
        gDungeon->unk4 = 0;
        gDungeon->unk11 = 0;
        gDungeon->unk8 = 0;
        gDungeon->unk3 = 0;
        gDungeon->unk6 = 0;
        gDungeon->noActionInProgress = FALSE;
        gDungeon->unk5C0 = -1;
        gDungeon->unk7 = 0;
        gDungeon->unk9 = 0;
        gDungeon->unkA = 0;
        gDungeon->unkB = 1;
        gDungeon->unkD = 1;
        gDungeon->unkE = 0;
        gDungeon->unk1BDD4.unk1C05E = 0;
        if (!r6) {
            gDungeon->unk644.unk35 = 0;
            gDungeon->unk644.unk48 = 0;
            gDungeon->unk644.unk4C = 0;
            gDungeon->unk644.unk50 = 0;
            gDungeon->unk644.fractionalTurn = 0;
            gDungeon->unk644.unk1E = 0;
            gDungeon->unk644.unk2A = 0;
            gDungeon->unk644.unk2B = 0;
            gDungeon->unk644.unk2C = 0;
            gDungeon->unk644.itemHoldersIdentified = 0;
            gDungeon->unk644.monsterHouseTriggered = 0;
            gDungeon->unk644.monsterHouseTriggeredEvent = 0;
            gDungeon->unk644.bossSongIndex = 999;
            gDungeon->unk644.unk44 = 0;
            gDungeon->unk644.unk46 = 0;
            gDungeon->unk644.unk40 = 99;
            gDungeon->unk644.unk42 = 99;
            gDungeon->weather.weather = 0;
            gDungeon->tileset = gDungeon->unk1C574.unk2;
            gDungeon->unk3A10 = gDungeon->unk1C574.unk3;
            gDungeon->fixedRoomNumber = gDungeon->unk1C574.unk12;
            sub_807E5E4(0);
            sub_80842F0();
        }
        sub_803D8F0();
        LoadDungeonPokemonSprites();
        if (!r6) {
            sub_80687AC();
        }
        else {
            LoadDungeonActivePokemonSprites();
            sub_8082B40();
        }
        sub_806C42C();
        sub_806AD3C();

        if (!r6) {
            DungeonStartNewBGM(gDungeonMusic[gDungeon->unk3A10]);
            sub_80847D4();
        }
        sub_8049840();
        sub_803E178();
        gDungeonBrightness = 0;
        SetDungeonMapToNotShown();
        sub_803EAF0(4, 0);
        sub_8052210(0);
        sub_803F27C(r6);
        ShowDungeonNameBanner();

        if (!r6) {
            GenerateFloor();
            gDungeon->unk644.windTurns = GetTurnLimit(gDungeon->unk644.dungeonLocation.id);
            gDungeon->unk644.unk36 = 0;
        }
        sub_804AAD4();
        sub_8049B8C();
        LoadDungeonTilesetAssets();
        if (!r6) {
            sub_806B168();
            sub_806C3C0();
            sub_806B6C4();
        }
        else {
            sub_806B678();
        }

        gDungeon->lightningRodPokemon = NULL;
        gDungeon->unk17B38 = 0;
        gDungeon->snatchPokemon = NULL;
        gDungeon->unk17B3C = 0;
        gDungeon->unk17B34 = NULL;
        gDungeon->unk17B40 = 0;
        if (!r6) {
            sub_807FA18();
            sub_8045CB0();
            gDungeon->unk644.unk50 = gDungeon->unk644.unk48;
            gDungeon->unk644.unk4C = 0;
            sub_8051E3C();
            sub_804AAAC();
        }
        else {
            sub_806A338();
        }
        sub_8068F80();
        sub_8049884();
        sub_8049ED4();

        if (!r6) {
            sub_806A914(TRUE, FALSE, FALSE);
        }
        else {
            sub_806CF60();
            sub_806A974();
        }
        sub_8041888(1);

        if (!r6) {
            sub_80848F0();
            IncrementAdventureFloorsExplored();
        }

        gUnknown_203B40C = 1;
        if (r6) {
            sub_807E88C();
            sub_806AB2C();
        }

        if (gDungeon->unk7 == 0) {
            sub_803E748();
        }
        else {
            sub_803E7C8();
        }
        sub_8040094(0);
        sub_803EAF0(0, 0);
        InitDungeonMap(r6);
        ShowWholeRevealedDungeonMap();
        gDungeon->unkB8 = NULL;
        gDungeon->unk644.unk28 = 0;
        gDungeon->unk644.unk29 = 0;
        gDungeon->unk12 = 99;
        gDungeon->unk0 = 1;

        if (!r6) {
            TryDisplayGeneralTutorialMessage();
            if (gDungeon->unk9 != 0) {
                gDungeon->unk9 = 0;
                sub_8083D68();
                DisplayYouReachedDestFloorStr();
            }
        }
        gLeaderPointer = NULL;
        gDungeon->unk5 = 0;
        if (!r6) {
            DisplayPreFightDialogue();
            if (gDungeon->unk4 != 0 || gDungeon->unk2 != 0) {
                gDungeon->unk5 = 1;
            }
            else {
                sub_803F4A0(GetLeader());
                ShowWholeRevealedDungeonMap();
            }
        }

        if (!r6) {
            if (gDungeon->unk5 == 0) {
                sub_807E5AC();
                if (GetApparentWeather(NULL) != 0) {
                    sub_807E7FC(1);
                }
            }
        }
        else {
            TriggerWeatherAbilities();
        }

        if (r6) {
            r6 = FALSE;
        }
        else {
            sub_80427AC();
            sub_8075900(GetLeader(), gDungeon->forceMonsterHouse);
            sub_807EAA0(1, 0);
        }

        nullsub_16();
        if (gDungeon->unk5 == 0) {
            bool8 param = TRUE;

            gDungeon->unk644.unk10 = 0;
            gDungeon->unk181e8.unk18218 = 0;
            gDungeon->unk181e8.unk18219 = 1;
            do {
                RunFractionalTurn(param);
                param = FALSE;
            } while (!sub_8044B28());
        }

        leader = GetLeader();
        if (EntityIsValid(leader)) {
            sub_8071DA4(leader);
        }

        if (gDungeon->unk644.unk10 != 1) {
            if (sub_8043ED0(TRUE)) {
                gDungeon->unk644.unk10 = 1;
            }
        }
        if (gDungeon->unk644.unk10 == 1 || gDungeon->unk11 != 0) {
            if (gDungeon->unk6 == 0) {
                sub_806AA70();
            }
        }

        if (EntityIsValid(GetLeader())) {
            sub_80526D0(0x4F);
            sub_8052740(0x4F);
        }

        SetDungeonMapToNotShown();
        sub_803EAF0(1, 0);
        gDungeon->unk181e8.unk18219 = 0;
        gDungeon->unk181e8.unk18218 = 1;
        if (gDungeon->unk3 == 0
            && gDungeon->unk6 == 0
            && gDungeon->musPlayer.queuedSongIndex == 0x72
            && gDungeon->unk644.dungeonLocation.id == DUNGEON_BURIED_RELIC)
        {
            DungeonFadeOutBGM(60);
        }

        sub_803E708(4, 0x4F);
        if (gDungeon->unk7 == 0) {
            sub_803E830();
        }

        SetBGOBJEnableFlags(0);
        color.r = 0x60;
        color.g = 0x80;
        color.b = 0xF8;
        SetBGPaletteBufferColorRGB(253, &color, gDungeonBrightness, NULL);
        sub_8040094(1);
        gDungeon->unk181e8.unk18218 = 1;
        if ((gDungeon->unk10 == 2 || gDungeon->unk10 == 3) && gDungeon->unk6 != 0) {
            leader = GetLeader();
            DisplayDungeonMessage(0, gPtrClientFaintedMessage, 1);
            gDungeon->unk6 = 0;
            sub_8083AB0(0x222, leader, leader);
        }
        CloseAllSpriteFiles();
        sub_8049820();
        CloseFile(gDungeonNameBannerPalette);
        FreeDungeonPokemonSprites();
        gUnknown_203B40C = 0;

        if (gDungeon->unk3 != 0) {
            SaveDungeonState(gSerializedData_203B41C, 0x4800);
            r8->unk7C = 3;
            r8->unk80 = gDungeon->unk644.dungeonLocation;
            check = FALSE;
        }
        else
        {
            s16 var;

            if (gDungeon->unk6 != 0) {
                SaveDungeonState(gSerializedData_203B41C, 0x4800);
            }
            else {
                sub_8046F84(ITEM_FLAG_IN_SHOP);
            }
            sub_806C1D8();

            if (gDungeon->unk644.unk10 == 1) {
                if (gDungeon->unk644.unk2A != 0) {
                    sub_804700C();
                }
                check = TRUE;
            }
            else if (gDungeon->unk11 == 1) {
                sub_8083AB0(0x226, NULL, GetLeader());
                check = TRUE;
            }
            else if (gDungeon->unk11 == 2) {
                sub_8083AB0(0x229, NULL, GetLeader());
                if (gDungeon->unk644.unk2A != 0) {
                    IncrementThievingSuccesses();
                }
                check = TRUE;
            }
            else if (gDungeon->unk11 == 3) {
                sub_8083AB0(0x22A, NULL, GetLeader());
                if (gDungeon->unk644.unk2A != 0) {
                    IncrementThievingSuccesses();
                }
                check = TRUE;
            }
            else if (gDungeon->unk11 == 4) {
                var = 0x227;
                sub_8083AB0(var, NULL, GetLeader());
                check = TRUE;
            }
            else if (gDungeon->unk644.unk34 == 1 && GetFloorType() == FLOOR_TYPE_RESCUE && gDungeon->unk644.unk10 == 2) {
                sub_8083AB0(0x228, NULL, GetLeader());
                if (gDungeon->unk644.unk2A != 0) {
                    IncrementThievingSuccesses();
                }
                check = TRUE;
            }
            else {
                if (gDungeon->unk644.unk2A != 0) {
                    IncrementThievingSuccesses();
                }
                if (gDungeon->unk644.dungeonLocation.floor + 1 < gDungeon->unk1CEC8) {
                    gDungeon->unk644.dungeonLocation.floor++;
                    if (gDungeon->unk644.dungeonLocation.id == DUNGEON_FROSTY_FOREST
                        && gDungeon->unk644.dungeonLocation.floor == 6
                        && !sub_8098100(0x1F))
                    {
                        sub_8097FA8(0x1F);
                        sub_8086130();
                        sub_8097FF8();
                    }
                    // We go back to the loop's start.
                    continue;
                }
                else {
                    var = 0x227;
                    sub_8083AB0(var, NULL, GetLeader());
                    check = TRUE;
                    // This goto is a fakematch I had to create in order to generate matching code.
                    // It has no real effect, because the control flow is the same without it(since check is TRUE). Unfortunately agbcc is blind and goto is needed.
                    // Feel free to remove it.
                    goto FAKEMATCH;
                }
            }
        }
        break;
    }

    if (check) {
    // See comment above
    FAKEMATCH:
        gUnknown_203B40C = 0;
        r8->unk7E = 0;
        sub_8097FF8();
        sub_80095CC(1, 0x14);
        sub_803E13C();
        sub_800CDA8(4);
        if (gDungeon->unk6 == 0 && sub_8083C88(gDungeon->unk644.unk34)) {
            sub_80841EC();
        }

        if (sub_8083C24()) {
            if (gDungeon->unk6 != 0) {
                r8->unk7C = -2;
                memset(&r8->unk84, 0, sizeof(r8->unk84));
                r8->unk80 = gDungeon->unk644.dungeonLocation;
                r8->unk84.dungeon = gDungeon->unk644.dungeonLocation;
                r8->unk84.seed = gDungeon->unk644.unk38;

            }
            else {
                r8->unk7C = -1;
            }
        }
        else if (sub_8083C50()) {
            if (gDungeon->unk644.unk34 == 1) {
                r8->unk7C = 4;
            }
            else if (gDungeon->unk644.unk34 == 0) {
                r8->unk7C = 1;
                sub_8084424();
            }
            else {
                r8->unk7C = 1;
                sub_8084424();
            }
            r8->unk7E = gDungeon->unk644.unk30;
        }
        else {
            r8->unk7C = 2;
            sub_8084424();
        }
    }

    CloseDungeonPaletteFile();
    sub_803E214();
    nullsub_56();
    CloseDungeonMapFile();
    if (r8->unk7C == 1 || r8->unk7C == 4 || r8->unk7C == 2) {
        sub_8047104();
    }
    if (r8->unk7C == 1 || r8->unk7C == -2 || r8->unk7C == 4 || r8->unk7C == -1 || r8->unk7C == 2) {
        if (r8->unk7C == 1 || r8->unk7C == 4 || r8->unk7C == 2) {
            sub_8068BDC(1);
        }
        else if (r8->unk7C == -2) {
            sub_8068BDC(0);
        }
        else {
            sub_8068F28();
            sub_8068BDC(0);
        }
    }
    sub_800DB7C();
    gDungeon = NULL;
    gSerializedData_203B41C = 0;
    nullsub_16();
}

void sub_8043CD8(void)
{
    vram_related_8009804();
}

bool8 sub_8043CE4(s32 dungeonId)
{
    if (gUnknown_202F1A8)
        return TRUE;

    return (gDungeonWaterType[dungeonId] == 2);
}

u8 GetFloorType(void)
{
    if (gDungeon->unk644.unk34 == 1 && gDungeon->unk644.unk8.unk1 == gDungeon->unk644.dungeonLocation.floor)
        return FLOOR_TYPE_RESCUE;
    else if (IsBossFight())
        return FLOOR_TYPE_FIXED;
    else
        return FLOOR_TYPE_NORMAL;
}

void sub_8043D50(s32 *a0, s32 *a1)
{
    *a1 = sizeof(Dungeon);
    *a0 = 0x4800; // Hmmm
}

void sub_8043D60(void)
{
    s32 x, y, monId;

    for (monId = 0; monId < DUNGEON_MAX_WILD_POKEMON; monId++) {
        Entity *mon = gDungeon->wildPokemon[monId];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            bool32 unk = TRUE;

            if (monInfo->shopkeeper == TRUE)
                unk = FALSE;
            if (IsExperienceLocked(monInfo->joinedAt.id))
                unk = FALSE;
            if (monInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET)
                unk = FALSE;

            if (unk) {
                sub_8068FE0(mon, 0x207, mon);
            }
        }
    }

    for (monId = 0; monId < MAX_TEAM_MEMBERS; monId++) {
        Entity *mon = gDungeon->teamPokemon[monId];
        if (EntityIsValid(mon)) {
            s32 i;
            EntityInfo *monInfo;

            mon->unk22 = 0;
            mon->isVisible = TRUE;
            monInfo = GetEntInfo(mon);
            monInfo->HP = monInfo->maxHPStat;
            monInfo->belly = monInfo->maxBelly;
            gDungeon->unk644.itemHoldersIdentified = FALSE;
            ResetMonEntityData(monInfo, 0);
            monInfo->apparentID = monInfo->id;
            monInfo->perishSongTurns = 0;
            for (i = 0; i < MAX_MON_MOVES; i++) {
                Move *move = &monInfo->moves.moves[i];
                if (move->moveFlags & MOVE_FLAG_EXISTS) {
                    move->PP = GetMoveBasePP(move);
                }
            }
        }
    }

    for (y = 0; y < 32; y++) {
        for (x = 0; x < 56; x++) {
            Entity *object = GetTileMut(x, y)->object;
            if (EntityIsValid(object) && GetEntityType(object) == ENTITY_TRAP) {
                Trap *trapData = GetTrapData(object);
                if (trapData->id == 27) {
                    trapData->id = TRAP_PITFALL_TRAP;
                }
            }
        }
    }

    sub_8046F84(ITEM_FLAG_IN_SHOP);
}

bool8 sub_8043ED0(bool8 a0)
{
    bool8 ret = FALSE;

    if (!a0 && sub_8044B28())
        return FALSE;

    if (gDungeon->unk10 == 1) {
        Entity *leader = GetLeader();
        if (EntityIsValid(leader)) {
            if (!a0) {
                strcpy(gFormatBuffer_Monsters[0], gDungeon->faintStringBuffer);
                DisplayDungeonMessage(0, gUnknown_80F89B4, 1);
            }
            sub_8042B0C(leader);
            sub_8068FE0(leader, 0x21F, leader);
            ret = TRUE;
        }
    }
    else if (gDungeon->unk10 == 2) {
        Entity *leader = GetLeader();
        if (EntityIsValid(leader)) {
            if (!a0) {
                strcpy(gFormatBuffer_Monsters[0], gDungeon->faintStringBuffer);
                DisplayDungeonMessage(0, gUnknown_80F89D4, 1);
            }
            sub_8042B0C(leader);
            sub_8068FE0(leader, 0x222, leader);
            ret = TRUE;
        }
    }
    else if (gDungeon->unk10 == 3) {
        Entity *leader = GetLeader();
        if (EntityIsValid(leader)) {
            if (!a0) {
                strcpy(gFormatBuffer_Monsters[0], gDungeon->faintStringBuffer);
                DisplayDungeonMessage(0, gUnknown_80F89D8, 1);
            }
            sub_8042B0C(leader);
            sub_8068FE0(leader, 0x222, leader);
            ret = TRUE;
        }
    }

    return ret;
}

static void sub_8043FD0(void)
{
    s32 level;
    for (level = 2; level <= 5; level++) {
        s32 i, monId, movesCount;
        for (monId = 0; monId < NUM_MONSTERS; monId++) {
            PokemonStruct1 *monStruct = &gRecruitedPokemonRef->pokemon[monId];
            if (PokemonFlag1(monStruct) && PokemonFlag2(monStruct)) {
                u16 learnedMoves[16];
                LevelData levelData;
                // I have to make the variables volatile to get matching code. I'm sure there's a solution for this, but keeping it like that for now.
                #ifdef NONMATCHING
                s32 atk, spAtk, def, spDef;
                #else
                vs32 atk, spAtk, def, spDef;
                #endif // NONMATCHING

                GetPokemonLevelData(&levelData, monStruct->speciesNum, level);
                monStruct->level = level;
                monStruct->currExp = levelData.expRequired;
                monStruct->pokeHP += levelData.gainHP;
                if (monStruct->pokeHP >= 999) // TODO: Make this a max hp define
                    monStruct->pokeHP = 999;

                atk = monStruct->offense.att[0];
                spAtk = monStruct->offense.att[1];
                def = monStruct->offense.def[0];
                spDef = monStruct->offense.def[1];

                atk += levelData.gainAtt[0];
                spAtk += levelData.gainAtt[1];
                def += levelData.gainDef[0];
                spDef += levelData.gainDef[1];

                // TODO: Make 255 max define for stats
                if (atk >= 255)     {atk = 255;}
                if (spAtk >= 255)   {spAtk = 255;}
                if (def >= 255)     {def = 255;}
                if (spDef >= 255)   {spDef = 255;}

                monStruct->offense.att[0] = atk;
                monStruct->offense.att[1] = spAtk;
                monStruct->offense.def[0] = def;
                monStruct->offense.def[1] = spDef;

                movesCount = GetMovesLearnedAtLevel(learnedMoves, monStruct->speciesNum, monStruct->level, 999);
                if (movesCount == 0)
                    continue;

                for (i = 0; i < movesCount; i++) {
                    s32 moveSlot;
                    for (moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++) {
                        if (!MoveFlagExists(&monStruct->moves[moveSlot])) {
                            InitZeroedPPPokemonMove(&monStruct->moves[moveSlot], learnedMoves[i]);
                            break;
                        }
                    }
                }
            }
        }
    }
}

void EnforceMaxItemsAndMoney(void)
{
    s32 i;

    if (GetMaxItemsAllowed(gDungeon->unk644.dungeonLocation.id) == 0)
    {
        for (i = 0; i < INVENTORY_SIZE; i++) {
            ZeroOutItem(&gTeamInventoryRef->teamItems[i]);
        }
        for (i = 0; i < NUM_MONSTERS; i++) {
            PokemonStruct1 *mon = (&gRecruitedPokemonRef->pokemon[i]);
            if (PokemonFlag1(mon) && PokemonFlag2(mon)) {
                mon->heldItem.id = 0;
            }
        }
    }

    if (!IsKeepMoney(gDungeon->unk644.dungeonLocation.id)) {
        gTeamInventoryRef->teamMoney = 0;
    }
}
