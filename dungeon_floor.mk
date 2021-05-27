# Map JSON data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

dungeon_floor: TinyWoods

TinyWoods: $(DUNGEONS_DIR)/TinyWoods/floor_id.json
	$(DUNGEONJSON) floor pmd-red $(DUNGEONS_DIR)/TinyWoods/floor_id.json
