# Pokémon (monster) data

MONSTER_DIR = $(DATA_ASM_SUBDIR)/monster
MONSTER_DATA = $(MONSTER_DIR)/monster_data.inc

# Headers included by tools/dungeonjson/dungeonjson.cpp:generate_monster_data_text
MONSTER_DATA_INC = \
	include/constants/ability.h \
	include/constants/evolve_type.h \
	include/constants/friend_area.h \
	include/constants/item.h \
	include/constants/monster.h \
	include/constants/type.h \
	include/constants/walkable_tile.h

data_monster: $(MONSTER_DATA);

$(MONSTER_DATA): $(MONSTER_DIR)/monster_data.json $(MONSTER_DATA_INC)
	$(DUNGEONJSON) monster pmd-red $<


LEARNSET_DIR = $(MONSTER_DIR)/learnset
LEARNSET_DATA = $(LEARNSET_DIR)/learnset_data.inc

data_learnset: $(LEARNSET_DATA);

$(LEARNSET_DATA): $(LEARNSET_DIR)/learnset_data.json
	$(DUNGEONJSON) learnset pmd-red $<

