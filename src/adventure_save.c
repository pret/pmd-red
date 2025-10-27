#include "global.h"
#include "globaldata.h"
#include "adventure_info.h"
#include "data_serializer.h"
#include "play_time.h"
#include "game_options.h"
#include "exclusive_pokemon.h"

u32 SaveAdventureData(u8 *buffer, u32 bufLen)
{
    DataSerializer seri;

    InitBitWriter(&seri, buffer, bufLen);

    WriteGameOptionsBits(&seri);
    WritePlayTimeBits(&seri);
    WriteAdventureBits(&seri);
    WriteExclusivePokemon(&seri);

    FinishBitSerializer(&seri);
    return seri.count;
}

u32 RestoreAdventureData(u8 *buffer, u32 bufLen)
{
    DataSerializer seri;

    InitBitReader(&seri, buffer, bufLen);

    ReadGameOptionsBits(&seri);
    ReadPlayTimeBits(&seri);
    ReadAdventureBits(&seri);
    ReadExclusivePokemon(&seri);

    FinishBitSerializer(&seri);
    return seri.count;
}
