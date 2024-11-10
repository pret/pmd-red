#ifndef GUARD_CODE_8092334_H
#define GUARD_CODE_8092334_H

#include "data_serializer.h"

void nullsub_102(DataSerializer *seri);
void ReadBits(DataSerializer *seri, void *dst, s32 numBits);
void WriteBits(DataSerializer *seri, void *src, s32 numBits);
void InitBitReader(DataSerializer *seri, u8 *buffer, s32 bufLen);
void InitBitWriter(DataSerializer *seri, u8 *buffer, s32 bufLen);

#endif // GUARD_CODE_8092334_H