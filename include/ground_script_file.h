#ifndef INCLUDE_GROUND_SCRIPT_FILE_H
#define INCLUDE_GROUND_SCRIPT_FILE_H 

void sub_80A7744(void);
void sub_80A7754(void);
bool8 ChangeScriptFile(s16 a0);
const struct GroundScriptHeader *GetGroundScript(s16 mapId, const DebugLocation *unused);

#endif /* INCLUDE_GROUND_SCRIPT_FILE_H */
