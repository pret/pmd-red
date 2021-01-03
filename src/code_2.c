#include "global.h"
#include "file_system.h"
#include "input.h"
#include "bg.h"

extern void InitHeap(void);
extern void NDS_DebugInit(void);
extern void sub_801180C(void);
extern void NDS_LoadOverlay_GroundMain(void);
extern void sub_8014144(void);
extern void LoadMonsterParameters(void);
extern void sub_8097670(void);
extern void sub_8094F88(void);
extern void sub_8094980(void);
extern void sub_8094C14(void);
extern void sub_8097F5C(void);
extern void sub_80923A0(void);
extern void sub_8090998(void);
extern void sub_809207C(void);
extern void LoadWazaParameters(void);
extern void sub_80950BC(void);
extern void sub_80958E8(void);
extern void sub_800CD64(u32, u32);
extern void sub_8012284(void);
extern void sub_8094998(u32);
extern void SetWindowTitle(char *);
extern void sub_800DAAC(void);
extern void SetSavingIconCoords(u32);
extern u32 sub_8011DAC(u32 *);
extern void sub_800135C(void);
extern void xxx_script_related_8001334(u32);
extern void sub_80015C0(u32, u32);
extern u32 sub_8001658(u32, u32);
extern void sub_800A8F8(u32);
extern void ResetSprites(u32);
extern void xxx_update_some_bg_tiles(u32);
extern void sub_80097B0(void);
extern void sub_800CDA8(u32);
extern void sub_800641C(u32, u32, u32);
extern void LoadTitleScreen(void);
extern void SetBGPaletteBufferColorRGB(s32, u8 *, s32, u8 *);
extern void sub_800BDFC(u32);
extern void sub_80095CC(u32, u32);
extern void InitMainMenu(void);
extern void sub_8012468(void);
extern u32 sub_8012484(void);
extern void sub_8012558(void);
extern u8 sub_80363E0(void);
extern void SetBGOBJEnableFlags(u32);
extern void SetUpMenu(void);
extern u32 UpdateMenu(void);
extern void CleanUpMenu(void);
extern void sub_80357D0(void);
extern s32 sub_80953D4(u32);
extern void sub_8095240(u8);
extern void sub_80122A8(void);
extern void nullsub_33(void);
extern u32 sub_80009D0(u32);

extern void xxx_draw_string_80144C4(void);
extern void sub_8005838(u32, u32);
extern void nullsub_8(u32);
extern void sub_8005180(void);
extern void sub_80060EC(void);
extern void sub_8011860(void);
extern void sub_800CB20(void);
extern void LoadBufferedInputs(void);
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
extern u8 *gUnknown_203B46C;

extern char gUnknown_80B69BC[];

void xxx_update_stuff(u32);

void GameLoop(void)
{
    u32 tmp;
    u8 tmp3 = 1;
    u32 tmp4;
    u32 flag;

    InitHeap();
    NDS_DebugInit();
    sub_801180C();
    NDS_LoadOverlay_GroundMain();
    sub_8014144();
    LoadMonsterParameters();
    sub_8097670();
    sub_8094F88();
    sub_8094980();
    sub_8094C14();
    sub_8097F5C();
    sub_80923A0();
    sub_8090998();
    sub_809207C();
    LoadWazaParameters();
    sub_80950BC();
    sub_80958E8();
    sub_800CD64(0x8000, 0);
    sub_8012284();
    sub_8094998(1);
    SetWindowTitle(gUnknown_80B69BC);
    sub_800DAAC();
    SetSavingIconCoords(0);
    tmp = 0;
    if (sub_8011DAC(&tmp))
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
        sub_800BDFC(8);
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
            tmp4 = UpdateMenu();
            CleanUpMenu();
            if (tmp4 == 2) break;
            if (tmp4 == 4) break;
            if (tmp4 == 3) break;
        }
        sub_80357D0();
        while (gUnknown_2000A80 > 0) {
            s32 i;
            gUnknown_2000A80--;
            for (i = 0; i < 240; i++)
                SetBGPaletteBufferColorRGB(i, &gTitlePaletteFile->data[i * 4], gUnknown_2000A80, 0);
            xxx_update_stuff(0);
        }
        CloseFile(gTitlePaletteFile);
        switch (tmp4) {
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
    nullsub_8(gUnknown_203B46C[10]);
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
