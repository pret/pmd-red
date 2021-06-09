# Dungeon Pokemon data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_DIRS := $(dir $(wildcard $(DUNGEONS_DIR)/*/pokemon_found.json))
DUNGEON_POKEMON := $(patsubst $(DUNGEONS_DIR)/%/,$(DUNGEONS_DIR)/%/pokemon_found.inc,$(DUNGEON_DIRS))

dungeon_pokemon: $(DUNGEON_POKEMON);

$(DUNGEONS_DIR)/%/pokemon_found.inc: $(DUNGEONS_DIR)/%/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $<
