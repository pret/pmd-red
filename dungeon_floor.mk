# Map JSON data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

dungeon_floor: TinyWoodsFloor ThunderwaveCaveFloor MtSteelFloor

TinyWoodsFloor: $(DUNGEONS_DIR)/TinyWoods/floor_id.json
	$(DUNGEONJSON) floor pmd-red $(DUNGEONS_DIR)/TinyWoods/floor_id.json

ThunderwaveCaveFloor: $(DUNGEONS_DIR)/ThunderwaveCave/floor_id.json
	$(DUNGEONJSON) floor pmd-red $(DUNGEONS_DIR)/ThunderwaveCave/floor_id.json

MtSteelFloor: $(DUNGEONS_DIR)/MtSteel/floor_id.json
	$(DUNGEONJSON) floor pmd-red $(DUNGEONS_DIR)/MtSteel/floor_id.json
