# Map JSON data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_DIRS := $(dir $(wildcard $(DUNGEONS_DIR)/*/pokemon_found.json))

dungeon_pokemon: TinyWoods ThunderwaveCave

TinyWoods: $(DUNGEONS_DIR)/TinyWoods/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/TinyWoods/pokemon_found.json

ThunderwaveCave: $(DUNGEONS_DIR)/ThunderwaveCave/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/ThunderwaveCave/pokemon_found.json

