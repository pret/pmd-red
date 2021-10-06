# Pokémon species data

POKEMON_DIR = $(DATA_ASM_SUBDIR)/pokemon
POKEMON_SPECIES = $(POKEMON_DIR)/species_data.inc

data_pokemon: $(POKEMON_SPECIES);

$(POKEMON_SPECIES): $(POKEMON_DIR)/species_data.json
	$(DUNGEONJSON) species pmd-red $<
