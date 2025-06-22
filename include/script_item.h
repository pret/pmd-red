#ifndef GUARD_SCRIPT_ITEM_H
#define GUARD_SCRIPT_ITEM_H

void InitInternalScriptItemsData(void);
void FreeInternalScriptItemsData(void);
void ClearScriptItemScriptVars(void);
s32 HasItemInInventory(u8 item);
s32 CheckScriptItemSpace(s32 tableId);
s32 TryGiveScriptItem(u32 tableId, s32 a1);
u32 ScriptItemTextboxFunc(void);

#endif // GUARD_SCRIPT_ITEM_H
