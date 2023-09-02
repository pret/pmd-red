#include "global.h"
#include "adventure_log.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_8097670.h"
#include "constants/input.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct AdventureLog *sAdventureLog = {0};

static const UnkTextStruct2 sUnknown_80E1FF0 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};
static const UnkTextStruct2 sUnknown_80E2008 = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x1A, 0x04,
    0x06, 0x00,
    NULL
};

static const u8 sAdventureLogHeaderText[] = "Adventure Log";
static const u8 sAdventureLogTextPlaceholder[] = "~95~95~95~95~95~95~95~95~95~95~95~95~95~95~95 "; // string of ???????
static const u8 sFill1[] = "pksdir0";

// ???
extern u32 gUnknown_202DE30;

static void DisplayAdventureLog();
static void sub_8032084();

bool8 CreateAdventureLogScreen(u32 kind)
{
    sAdventureLog = MemoryAlloc(sizeof(struct AdventureLog), 8);
    sAdventureLog->unk34 = kind;
    sAdventureLog->unk38 = &sAdventureLog->unk3C[kind];
    sub_8006518(sAdventureLog->unk3C);
    sAdventureLog->unk3C[sAdventureLog->unk34] = sUnknown_80E2008;
    sAdventureLog->unk38->unk14 = sAdventureLog->unk9C;

    ResetUnusedInputStruct();
    sub_800641C(sAdventureLog->unk3C, TRUE, TRUE);
    sub_8013818(&sAdventureLog->input, 0x20, 8, kind);
    sub_8032084();
    DisplayAdventureLog();
    return TRUE;
}

u32 HandleAdventureLogInput(u8 param_1)
{
    if (param_1 == 0) {
        sub_8013660(&sAdventureLog->input);
        return 0;
    }

    switch (GetKeyPress(&sAdventureLog->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (sub_8013938(&sAdventureLog->input)) {
                sub_8032084();
                DisplayAdventureLog();
                return 1;
            }
            return 0;
    }
}

void CleanAdventureLogScreen(void)
{
    if (sAdventureLog != NULL) {
        sAdventureLog->unk3C[sAdventureLog->unk34] = sUnknown_80E1FF0;
        ResetUnusedInputStruct();
        sub_800641C(sAdventureLog->unk3C, TRUE, TRUE);
        MemoryFree(sAdventureLog);
        sAdventureLog = NULL;
    }
}

#ifdef NONMATCHING
static void sub_8032084(void)
{
    u32 sVar2;

    sAdventureLog->unk9C[0] = sAdventureLog->unk20;
    sAdventureLog->unk9C[1] = sAdventureLog->unk0.unk1E;
    sAdventureLog->unk9C[2] = 11;
    sAdventureLog->unk9C[3] = 0;
    // So a sign extend..
    sVar2 = sub_80095E4(sAdventureLog->unk0.unk1A, 12) + 2 << 0x10;
    // TODO needs asr r3, r0, r16
    //        and lsr r0, r0, r16
    sAdventureLog->unk3C[sAdventureLog->unk34].unkE = sVar2;
    // Good past here except regs for this store
    sAdventureLog->unk3C[sAdventureLog->unk34].unk10 = sVar2 + 2;
    ResetUnusedInputStruct();
    sub_800641C(sAdventureLog->unk3C, TRUE, TRUE);
}
#else
NAKED
static void sub_8032084(void)
{
	asm_unified("\tpush {r4,lr}\n"
	"\tldr r4, _080320F4\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x20]\n"
	"\tadds r0, 0x9C\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x1E]\n"
	"\tadds r0, 0x9D\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9E\n"
	"\tmovs r1, 0xB\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9F\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x1A\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x34]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x4A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x4C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_080320F4: .4byte sAdventureLog");
}
#endif

static void DisplayAdventureLog(void)
{
    s32 counter;
    s32 r4; // r4
    s32 r6; // r6
    u8 temp;
    s32 v1, v2, v3, v4, v5, v6;

    sub_8008C54(sAdventureLog->unk34);
    sub_80073B8(sAdventureLog->unk34);
    r4 = sAdventureLog->input.unk1E * 8;
    r6 = r4;
    r6 += 10;
    // Draw Header
    xxx_call_draw_string(r6, 0, sAdventureLogHeaderText, sAdventureLog->unk34, 0);
    r4 += 4;
    r6 = r4 + sAdventureLog->unk9C[2] * 8;
    // Draw Page #
    sub_8012BC4(r6, 0, sAdventureLog->input.unk1E + 1, 1, 7, sAdventureLog->unk34);

    for (counter = 0; counter < sAdventureLog->input.unk1A; counter++) {
        temp = sAdventureLog->input.unk1E * sAdventureLog->input.unk1C + counter;

        if (sub_8097710(temp)) {
            switch (temp) {
                case 12:
                    v1 = sub_80978B8();
                    gUnknown_202DE30 = (s16)v1;
                    xxx_format_and_draw(8, sub_8013800(&sAdventureLog->input, counter), GetAdventureLogLine(temp), sAdventureLog->unk34, 0);
                    break;
                case 7:
                    v2 = sub_8097880();
                    gUnknown_202DE30 = (s16)v2;
                    xxx_format_and_draw(8, sub_8013800(&sAdventureLog->input, counter), GetAdventureLogLine(temp), sAdventureLog->unk34, 0);
                    break;
                case 11:
                    v3 = sub_8097838();
                    gUnknown_202DE30 = (s16)v3;
                    xxx_format_and_draw(8, sub_8013800(&sAdventureLog->input, counter), GetAdventureLogLine(temp), sAdventureLog->unk34, 0);
                    break;
                case 8:
                    v4 = sub_80977B8();
                    gUnknown_202DE30 = v4;
                    xxx_format_and_draw(8, sub_8013800(&sAdventureLog->input, counter), GetAdventureLogLine(temp), sAdventureLog->unk34, 0);
                    break;
                case 9:
                    v5 = sub_80977F8();
                    gUnknown_202DE30 = v5;
                    xxx_format_and_draw(8, sub_8013800(&sAdventureLog->input, counter), GetAdventureLogLine(temp), sAdventureLog->unk34, 0);
                    break;
                case 10:
                    v6 = sub_8097870();
                    gUnknown_202DE30 = (s16)v6;
                    // fallthrough
                default:
                    xxx_format_and_draw(8, sub_8013800(&sAdventureLog->input, counter), GetAdventureLogLine(temp), sAdventureLog->unk34, 0);
                    break;
            }
        }
        else {
            // Draw the ?????????? across the row
            xxx_call_draw_string(8, sub_8013800(&sAdventureLog->input, counter), sAdventureLogTextPlaceholder, sAdventureLog->unk34, 0);
        }
    }

    sub_80073E0(sAdventureLog->unk34);
}
