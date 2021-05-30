#include "global.h"
#include "bg.h"
#include "constants/bg_music.h"
#include "file_system.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "music.h"
#include "play_time.h"
#include "save.h"
#include "gUnknown_203B46C.h"
#include "text.h"

extern void NDS_DebugInit(void);
extern void sub_801180C(void);
extern void NDS_LoadOverlay_GroundMain(void);
extern void sub_8014144(void);
extern void LoadMonsterParameters(void);
extern void sub_8097670(void);
extern void LoadGameOptions(void);
extern void sub_8094C14(void);
extern void LoadExclusivePokemon(void);
extern void LoadItemParameters(void);
extern void LoadRescueTeamInfo(void);
extern void LoadWazaParameters(void);
extern void sub_80950BC(void);
extern void sub_80958E8(void);
extern void sub_800CD64(u32, u32);
extern void InitializeGameOptions(u32);
extern void SetWindowTitle(char *);
extern void sub_800DAAC(void);
extern void SetSavingIconCoords(u32);
extern void sub_800135C(void);
extern void xxx_script_related_8001334(u32);
extern void sub_80015C0(u32, u32);
extern u32 sub_8001658(u32, u32);
extern void sub_800A8F8(u32);
extern void ResetSprites(u32);
extern void sub_80097B0(void);
extern void sub_800CDA8(u32);
extern void LoadTitleScreen(void);
extern void SetBGPaletteBufferColorRGB(s32, u8 *, s32, u8 *);
extern void sub_80095CC(u32, u32);
extern void InitMainMenu(void);
extern u8 sub_80363E0(void);
extern void SetUpMenu(void);
extern u32 UpdateMenu(void);
extern void CleanUpMenu(void);
extern void DeleteMainMenu(void);
extern s32 sub_80953D4(u32);
extern void sub_8095240(u8);
extern void nullsub_33(void);
extern u32 sub_80009D0(u32);

extern void xxx_draw_string_80144C4(void);
extern void sub_8005838(u32, u32);
extern void nullsub_8(u32);
extern void sub_8005180(void);
extern void sub_80060EC(void);
extern void sub_8011860(void);
extern void sub_800CB20(void);
extern void CopySpritesToOam(void);
extern void sub_8005304(void);
extern void TransferBGPaletteBuffer(void);
extern void xxx_call_update_bg_vram(void);
extern void sub_8009908(void);
extern void xxx_call_update_bg_sound_input(void);

extern u32 gUnknown_203B03C;
extern u16 gUnknown_2026E4E;
extern s32 gUnknown_2000A80;
extern struct OpenedFile *gTitlePaletteFile;
extern struct Inputs gRealInputs;
extern struct UnkSaveStruct1 *gUnknown_203B46C;

extern char gPMDBuildVersion[];

void xxx_update_stuff(u32);

void GameLoop(void)
{
    u32 tmp;
    u8 tmp3 = 1;
    u32 nextMenu;
    u32 flag;

    InitHeap();
    NDS_DebugInit();
    sub_801180C();
    NDS_LoadOverlay_GroundMain();
    sub_8014144();
    LoadMonsterParameters();
    sub_8097670();
    InitializePlayTime();
    LoadGameOptions();
    sub_8094C14();
    LoadExclusivePokemon();
    LoadFriendAreas();
    LoadItemParameters();
    LoadRescueTeamInfo();
    LoadWazaParameters();
    sub_80950BC();
    sub_80958E8();
    sub_800CD64(0x8000, 0);
    sub_8012284();
    InitializeGameOptions(1);
    SetWindowTitle(gPMDBuildVersion);
    sub_800DAAC();
    SetSavingIconCoords(0);
    tmp = 0;
    if (ReadSaveFromPak(&tmp))
        sub_800135C();
    xxx_script_related_8001334(14);
    xxx_script_related_8001334(15);
    sub_80015C0(0, 57);
    xxx_script_related_8001334(16);
    if (sub_8001658(0, 57) == 0)
        xxx_script_related_8001334(17);

    while (1) {
        gUnknown_203B03C = 0; // ???
        sub_800A8F8(2);
        ResetSprites(1);
        xxx_update_some_bg_tiles(0);
        sub_80097B0();
        sub_800CDA8(2);
        sub_800641C(0, 1, 1);
        gUnknown_2026E4E = 0x1000;
        LoadTitleScreen();
        SetBG2RegOffsets(0, 0);
        SetBG3RegOffsets(0, 0);
        gUnknown_2000A80 = 0;
        while (gUnknown_2000A80 < 32) {
            s32 i;
            gUnknown_2000A80++;
            for (i = 0; i < 240; i++)
                SetBGPaletteBufferColorRGB(i, &gTitlePaletteFile->data[i * 4], gUnknown_2000A80, 0);
            xxx_update_stuff(0);
        }
        if (tmp3) {
            sub_8012468();
            while ((u8)(tmp3 = sub_8012484()))
                xxx_update_stuff(0);
            sub_8012558();
        }
        tmp3 = 1;
        StartNewBGM(MUS_LOADING_SCREEN);
        flag = TRUE;
        sub_80095CC(0, 20);
        InitMainMenu();
        while (1) {
            if ((u8)sub_80363E0()) {
                if (gRealInputs.pressed & L_BUTTON) {
                    flag = FALSE;
                    SetBGOBJEnableFlags(19);
                } else if (!flag && (gRealInputs.held & L_BUTTON) == 0) {
                    flag = TRUE;
                    SetBGOBJEnableFlags(0);
                }
                if (!flag) {
                    xxx_update_stuff(0);
                    continue;
                }
            }
            SetUpMenu();
            xxx_update_stuff(0);
            nextMenu = UpdateMenu();
            CleanUpMenu();
            if (nextMenu == 2) break;
            if (nextMenu == 4) break;
            if (nextMenu == 3) break;
        }
        DeleteMainMenu();
        while (gUnknown_2000A80 > 0) {
            s32 i;
            gUnknown_2000A80--;
            for (i = 0; i < 240; i++)
                SetBGPaletteBufferColorRGB(i, &gTitlePaletteFile->data[i * 4], gUnknown_2000A80, 0);
            xxx_update_stuff(0);
        }
        CloseFile(gTitlePaletteFile);
        switch (nextMenu) {
            case 2: {
                s32 tmp5 = sub_80953D4(7);
                if (tmp5 != -1) {
                    sub_8095240(tmp5);
                    tmp3 = sub_80009D0(2);
                } else {
                    tmp3 = sub_80009D0(1);
                }
                break;
            }
            case 4:
                tmp3 = sub_80009D0(3);
                break;
            case 3:
                sub_80122A8();
                nullsub_33();
                tmp3 = sub_80009D0(0);
                break;
        }

    }
}

void xxx_update_stuff(u32 r0)
{
    xxx_draw_string_80144C4();
    sub_8005838(0, 0);
    nullsub_8(gUnknown_203B46C->unkA);
    sub_8005180();
    sub_80060EC();
    sub_8011860();
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    ResetSprites(0);
}
