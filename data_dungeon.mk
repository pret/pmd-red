# Dungeon data

DUNGEON_DIR = $(DATA_ASM_SUBDIR)/dungeon
DUNGEON_DATA = $(DUNGEON_DIR)/dungeon_data.inc

# Headers included by tools/dungeonjson/dungeonjson.cpp:generate_dungeon_data_text
DUNGEON_DATA_INC = \
	include/constants/dungeon.h \
	include/constants/move_id.h

data_dungeon: $(DUNGEON_DATA);

$(DUNGEON_DATA): $(DUNGEON_DIR)/dungeon_data.json $(DUNGEON_DATA_INC)
	$(DUNGEONJSON) dungeon pmd-red $<
