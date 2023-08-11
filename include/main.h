#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

typedef void (*IntrCallback)(void);

extern IntrCallback gIntrCallbacks[6];

void AckInterrupt(u16);
bool8 EnableInterrupts(void);
bool8 DisableInterrupts(void);

#endif // GUARD_MAIN_H