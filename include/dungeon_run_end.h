#ifndef GUARD_DUNGEON_RUN_END
#define GUARD_DUNGEON_RUN_END

#include "structs/str_dungeon.h"

void PrintOnDungeonFinishedWindow(u32 windowId, const u8 *headerText, DungeonExitSummary *param_3);
s16 GetDungeonExitReasonFromMoveOrItemID(u16 moveID, u8 id);

#endif
