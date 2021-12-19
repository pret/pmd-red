# Pokémon species data

POKEMON_DIR = $(DATA_ASM_SUBDIR)/pokemon
POKEMON_SPECIES = $(POKEMON_DIR)/species_data.inc

# Headers included by tools/dungeonjson/dungeonjson.cpp:generate_species_data_text
POKEMON_SPECIES_INC = \
	include/constants/ability.h \
	include/constants/evolve_type.h \
	include/constants/friend_area.h \
	include/constants/item.h \
	include/constants/species.h \
	include/constants/type.h \
	include/constants/walkable_tile.h

data_pokemon: $(POKEMON_SPECIES);

$(POKEMON_SPECIES): $(POKEMON_DIR)/species_data.json $(POKEMON_SPECIES_INC)
	$(DUNGEONJSON) species pmd-red $<
