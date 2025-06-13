#include "global.h"
#include "globaldata.h"
#include "run_dungeon.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "constants/trap.h"
#include "structs/rgb.h"
#include "structs/sprite_oam.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "code_800E9E4.h"
#include "code_800ED38.h"
#include "code_803D110.h"
#include "dungeon_vram.h"
#include "code_803E724.h"
#include "code_805D8C8.h"
#include "code_8094F88.h"
#include "code_8099360.h"
#include "cpu.h"
#include "dungeon_8083AB0.h"
#include "dungeon_info.h"
#include "dungeon_ai.h"
#include "dungeon_config.h"
#include "dungeon_engine.h"
#include "dungeon_generation.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_message_log.h"
#include "dungeon_misc.h"
#include "dungeon_music.h"
#include "dungeon_name_banner.h"
#include "dungeon_spawns.h"
#include "dungeon_pokemon_sprites.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_serializer.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "file_system.h"
#include "moves.h"
#include "pokemon.h"
#include "random.h"
#include "sprite.h"
#include "text_1.h"
#include "text_3.h"
#include "weather.h"

EWRAM_INIT struct UnkStruct_203B414 *gUnknown_203B414 = NULL;
EWRAM_INIT Dungeon *gDungeon = NULL;
static EWRAM_INIT u8 *gSerializedData_203B41C = NULL;

extern u8 gUnknown_203B40C;

extern void sub_8040094(u8 r0);
extern void sub_8068BDC(u8 r0);
extern s16 GetTurnLimit(u8 dungeon);
extern void sub_8041888(u8 param_1);
extern void sub_803D4AC(void);
extern void sub_804513C(void);
extern void sub_803E830(void);
extern void sub_8068F28(void);
extern void sub_806C1D8(void);
extern void IncrementThievingSuccesses(void);
extern void ShowDungeonClearedWindow(void);
extern void sub_8084424(void);
extern void sub_8086130(void);
extern void sub_80847D4(void);
extern void sub_8043D60(void);
extern void sub_806890C(void);
extern void sub_80840A4(void);
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
extern void nullsub_16(void);
extern void sub_80521D0(void);
extern void sub_803F27C(u8);
extern void sub_807E7FC(u8);
extern bool8 IsLevelResetTo1(u8 dungeon);
extern void sub_8068A84(PokemonStruct1 *pokemon);
extern void sub_807EAA0(u32, u32);
extern void SetFloorItemMonsterSpawns(void);
extern void sub_80842F0(void);
extern void sub_80427AC(void);
extern void sub_806AA70(void);
extern void sub_806AD3C(void);
extern void sub_806C42C(void);
extern void sub_806B678(void);
extern void sub_806C3C0(void);
extern void sub_806B168(void);
extern void sub_806B6C4(void);
extern void sub_806A338(void);
extern void sub_8051E3C(void);
extern void sub_807FA18(void);
extern void sub_806A974(void);
extern void sub_806CF60(void);
extern void sub_8068F80(void);
extern void sub_8042E98(void);
extern bool8 sub_8044B28(void);
extern bool8 sub_8043ED0(bool8);
extern void sub_806A914(bool8 a0, bool8 a1, bool8 showRunAwayEffect);
extern void sub_803F4A0(Entity *a0);
extern void ResetMonEntityData(EntityInfo *, u32);
extern s32 GetMovesLearnedAtLevel(u16* dst, s16 species, s32 level, s32 IQPoints);
extern bool8 IsKeepMoney(u8 dungeon);
extern void sub_8042B0C(Entity *);

extern u8 gUnknown_202F32C;
extern u8 gUnknown_202F1A8;
extern s32 gDungeonBrightness;
extern Entity *gLeaderPointer;

void EnforceMaxItemsAndMoney(void);
static void sub_8043FD0(void);
void sub_806B404(void);

extern OpenedFile *gDungeonNameBannerPalette;

// These functions are not part of dungeon's overlay5 and connect, in a way, overworld with dungeon.

static const s16 sDeoxysForms[4] = {MONSTER_DEOXYS_NORMAL, MONSTER_DEOXYS_ATTACK, MONSTER_DEOXYS_DEFENSE, MONSTER_DEOXYS_SPEED};

static void sub_8043CD8(void);

// This functions is the main 'loop' when the player is in a Dungeon. It runs from the moment the player enters a dungeon, until they leave(by completing or by fainting).
// arm9.bin::0206A848
void RunDungeon_Async(DungeonSetupStruct *setupPtr)
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
    r6 = setupPtr->info.sub0.unk4;
    r9 = setupPtr->info.sub0.unkD;
    r10 = setupPtr->info.sub0.unkC;
    gSerializedData_203B41C = setupPtr->info.unk74;
    gDungeon = setupPtr->info.dungeon;
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
        gDungeon->unk644.unk34 = setupPtr->info.sub0.unkB;
        gDungeon->unk644.dungeonSeed = setupPtr->info.dungeonSeed;
        gDungeon->unk644.windTurns = GetTurnLimit(setupPtr->info.sub0.unk0.id);
        gDungeon->unk644.unk36 = 0;
        gDungeon->unk644.unk37 = GetRescuesAllowed(setupPtr->info.sub0.unk0.id);
    }
    gDungeon->unk644.unk54 = 0;
    gDungeon->unk644.unk55 = 0;
    gDungeon->unk644.unk18 = setupPtr->info.sub0.unk5;
    gDungeon->unk644.unk16 = setupPtr->info.sub0.unk8;
    gDungeon->unk644.canRecruit = setupPtr->info.sub0.unk6;
    gDungeon->unk644.unk15 = setupPtr->info.sub0.unk7;
    gDungeon->unk644.hasInventory = setupPtr->info.sub0.unk9;
    gDungeon->unk644.unk19 = setupPtr->info.sub0.unkA;
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
            gDungeon->unk644.dungeonLocation.id = setupPtr->info.dungeonSeed.location.id;
            gDungeon->unk644.dungeonLocation.floor = 1;
        }
        else {
            gDungeon->unk644.dungeonLocation = setupPtr->info.sub0.unk0;
        }

        gDungeon->unk644.unk30 = 0;
        EnforceMaxItemsAndMoney();
    }
    if (!r6) {
        if (gDungeon->unk644.unk34 == 1) {
            gDungeon->unk644.unk38 = setupPtr->info.dungeonSeed.seed;
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
        setupPtr->info.mon.heldItem.id = 0;
        if (IsLevelResetTo1(gDungeon->unk644.dungeonLocation.id)) {
            sub_808D0D8(&setupPtr->info.mon);
        }
        sub_8068A84(&setupPtr->info.mon);
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

    while (TRUE) {
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
        gDungeon->monsterSpawnsPopulated = FALSE;
        if (!r6) {
            s32 rnd;

            gDungeon->decoyIsActive = FALSE;
            rnd = DungeonRandInt(ARRAY_COUNT(sDeoxysForms));
            gDungeon->unk37FD = 0;
            gDungeon->deoxysDefeat = FALSE;
            gDungeon->deoxysForm = sDeoxysForms[rnd];
            gDungeon->unk37FF = 0;
            gDungeon->unk644.unk31 = 0;
        }
        SetFloorItemMonsterSpawns();
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
            gDungeon->tileset = gDungeon->floorProperties.unk2;
            gDungeon->unk3A10 = gDungeon->floorProperties.unk3;
            gDungeon->fixedRoomNumber = gDungeon->floorProperties.unk12;
            sub_807E5E4(0);
            sub_80842F0();
        }
        SetCurrentMonsterSpawns();
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
        sub_803EAF0(4, NULL);
        sub_8052210(0);
        sub_803F27C(r6);
        ShowDungeonNameBanner_Async();

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
            CreateFloorItems();
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
        sub_803EAF0(0, NULL);
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
        sub_803EAF0(1, NULL);
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
            setupPtr->info.unk7C = 3;
            setupPtr->info.unk80 = gDungeon->unk644.dungeonLocation;
            check = FALSE;
        }
        else
        {
            s16 var;

            if (gDungeon->unk6 != 0) {
                SaveDungeonState(gSerializedData_203B41C, 0x4800);
            }
            else {
                ClearAllItemsWithFlag(ITEM_FLAG_IN_SHOP);
            }
            sub_806C1D8();

            if (gDungeon->unk644.unk10 == 1) {
                if (gDungeon->unk644.unk2A != 0) {
                    AllItemsToPlainSeed();
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
        setupPtr->info.unk7E = 0;
        sub_8097FF8();
        sub_80095CC(1, 0x14);
        sub_803E13C();
        sub_800CDA8(4);
        if (gDungeon->unk6 == 0 && sub_8083C88(gDungeon->unk644.unk34)) {
            ShowDungeonClearedWindow();
        }

        if (sub_8083C24()) {
            if (gDungeon->unk6 != 0) {
                setupPtr->info.unk7C = -2;
                memset(&setupPtr->info.unk84, 0, sizeof(setupPtr->info.unk84));
                setupPtr->info.unk80 = gDungeon->unk644.dungeonLocation;
                setupPtr->info.unk84.location = gDungeon->unk644.dungeonLocation;
                setupPtr->info.unk84.seed = gDungeon->unk644.unk38;

            }
            else {
                setupPtr->info.unk7C = -1;
            }
        }
        else if (sub_8083C50()) {
            if (gDungeon->unk644.unk34 == 1) {
                setupPtr->info.unk7C = 4;
            }
            else if (gDungeon->unk644.unk34 == 0) {
                setupPtr->info.unk7C = 1;
                sub_8084424();
            }
            else {
                setupPtr->info.unk7C = 1;
                sub_8084424();
            }
            setupPtr->info.unk7E = gDungeon->unk644.unk30;
        }
        else {
            setupPtr->info.unk7C = 2;
            sub_8084424();
        }
    }

    CloseDungeonPaletteFile();
    sub_803E214();
    nullsub_56();
    CloseDungeonMapFile();
    if (setupPtr->info.unk7C == 1 || setupPtr->info.unk7C == 4 || setupPtr->info.unk7C == 2) {
        CleanUpInventoryItems();
    }
    if (setupPtr->info.unk7C == 1 || setupPtr->info.unk7C == -2 || setupPtr->info.unk7C == 4 || setupPtr->info.unk7C == -1 || setupPtr->info.unk7C == 2) {
        if (setupPtr->info.unk7C == 1 || setupPtr->info.unk7C == 4 || setupPtr->info.unk7C == 2) {
            sub_8068BDC(1);
        }
        else if (setupPtr->info.unk7C == -2) {
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

static void sub_8043CD8(void)
{
    ResetVramPalOAM();
}

bool8 sub_8043CE4(s32 dungeonId)
{
    if (gUnknown_202F1A8)
        return TRUE;

    return (gDungeonWaterType[dungeonId] == 2);
}

u8 GetFloorType(void)
{
    if (gDungeon->unk644.unk34 == 1 && gDungeon->unk644.dungeonSeed.location.floor == gDungeon->unk644.dungeonLocation.floor)
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

    ClearAllItemsWithFlag(ITEM_FLAG_IN_SHOP);
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

bool8 IsBossFight(void)
{
    if (gDungeon->fixedRoomNumber != 0 && gDungeon->fixedRoomNumber <= 0x31)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsCurrentFixedRoomBossFight(void)
{
    if (gDungeon->tileset > DUNGEON_OUT_ON_RESCUE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsMakuhitaTrainingMaze(void)
{
    if (DUNGEON_IS_MAZE(gDungeon->unk644.dungeonLocation.id))
        return TRUE;
    else
        return FALSE;
}
