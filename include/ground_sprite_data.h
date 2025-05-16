#ifndef GUARD_GROUND_SPRITE_DATA_H
#define GUARD_GROUND_SPRITE_DATA_H

struct GroundObjectKind
{
    s8 unk0;
    u16 unk2;
    const char *fileName;
};

extern const char *const gUnknown_81178F4[];
extern const struct GroundObjectKind gGroundObjectKinds[];
extern const struct GroundObjectKind gUnknown_8117E8C[];

#endif // GUARD_GROUND_SPRITE_DATA_H
