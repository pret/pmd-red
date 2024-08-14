#include "debug.h"
#include "global.h"
#include "ground_map_1.h"
#include "ground_script.h"

s32 sub_8001658(ScriptUnion832*, s32);
u8 FlagJudge(s32 r0, s32 r1, u32 operation);

extern u8 gUnknown_2039A36;
extern u8 gUnknown_2039A38[];
extern u32 gUnknown_2039B48[];
extern u8 gUnknown_2039AC0[];
extern u8 gUnknown_8116848[];

s32 sub_80A8B1C(s16);
s32 sub_80AC320(s16);
s32 sub_80AD238(s16);

// TODO: this is still WIP

// void GroundScript_Unlock(void) 
// {
//     s32 index;
//     u8 temp;
//     s16 temp_s16;
// 
//     if(gUnknown_2039A36 != 0)
//     {
//         gUnknown_2039A36 = 0;
//         for(index = 0; index < 0x81; index++)
//         {
//             if(gUnknown_2039A38[index] != 0)
//             {
//                 Log(1, gUnknown_8116848, index);
//                 temp = sub_80A4D2C(index);
//                 temp |= sub_80A8B1C(index);
//                 temp |= sub_80AC320(index);
//                 temp |= sub_80AD238(index);
// 
//                 if(gUnknown_2039AC0[index] != 0)
//                 {
//                    if (temp != 0)
//                    {
//                         temp_s16 = index;
//                         temp_s16 |= 0x80;
//                         sub_80A4D2C(temp_s16);
//                         sub_80A8B1C(temp_s16);
//                         sub_80AC320(temp_s16);
//                         sub_80AD238(temp_s16);
//                         gUnknown_2039AC0[index] = 0;
//                    }
//                 }
//                 else {
//                    gUnknown_2039A38[index] = 0;
//                 }
//             }
//         }
//     }
// }

ScriptCommand *sub_80A242C(Action *action, s32 r1)
{
    ScriptCommand script;
    ScriptCommand *scriptPtr2;
    ScriptCommand *scriptPtr;

    scriptPtr2 = action->scriptData.script.ptr2;
    scriptPtr = scriptPtr2 + 1;

    while(1) {
        script = *scriptPtr;
        scriptPtr++;

        if(script.op == 0xF4)
        {
            if(r1 == script.argShort)
                return scriptPtr;
        }
    }
}

ScriptCommand *sub_80A2460(Action *action, s32 r1)
{
    ScriptCommand script;
    ScriptCommand *scriptPtr;
    s32 temp;

    scriptPtr = action->scriptData.script.ptr;

    while(1) {
        script = *scriptPtr;

        if (script.op == 0xCC)
        {
            if(FlagJudge(r1, script.arg1, 0x2))
                return sub_80A242C(action, script.argShort);
        }
        else if (script.op == 0xCD)
        {
            if(FlagJudge(r1, script.arg1, script.argByte))
                return sub_80A242C(action, script.argShort);
        }
        else if (script.op == 0xCE)
        {
            temp = sub_8001658(action->scriptData.unk50, (s16)script.arg1);
            if(FlagJudge(r1, temp, script.argByte))
                return sub_80A242C(action, script.argShort);
        }
        else
        {
            return scriptPtr;
        }
        scriptPtr++;
    }
}

