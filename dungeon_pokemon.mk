# Map JSON data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_DIRS := $(dir $(wildcard $(DUNGEONS_DIR)/*/pokemon_found.json))

dungeon_pokemon: TinyWoods ThunderwaveCave MtSteel SinisterWoods SilentChasm MtThunder MtThunderPeak GreatCanyon LapisCave

TinyWoods: $(DUNGEONS_DIR)/TinyWoods/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/TinyWoods/pokemon_found.json

ThunderwaveCave: $(DUNGEONS_DIR)/ThunderwaveCave/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/ThunderwaveCave/pokemon_found.json

MtSteel: $(DUNGEONS_DIR)/MtSteel/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/MtSteel/pokemon_found.json

SinisterWoods: $(DUNGEONS_DIR)/SinisterWoods/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/SinisterWoods/pokemon_found.json

SilentChasm: $(DUNGEONS_DIR)/SilentChasm/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/SilentChasm/pokemon_found.json

MtThunder: $(DUNGEONS_DIR)/MtThunder/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/MtThunder/pokemon_found.json

MtThunderPeak: $(DUNGEONS_DIR)/MtThunderPeak/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/MtThunderPeak/pokemon_found.json

GreatCanyon: $(DUNGEONS_DIR)/GreatCanyon/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/GreatCanyon/pokemon_found.json

LapisCave: $(DUNGEONS_DIR)/LapisCave/pokemon_found.json
	$(DUNGEONJSON) dungeon pmd-red $(DUNGEONS_DIR)/LapisCave/pokemon_found.json
