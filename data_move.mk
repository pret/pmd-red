# Move data

MOVE_DIR = $(DATA_ASM_SUBDIR)/move
MOVE_DATA = $(MOVE_DIR)/move_data.inc

# Headers included by tools/dungeonjson/dungeonjson.cpp:generate_move_data_text
MOVE_DATA_INC = \
	include/constants/move_range.h \
	include/constants/type.h

data_move: $(MOVE_DATA);

$(MOVE_DATA): $(MOVE_DIR)/move_data.json $(MOVE_DATA_INC)
	$(DUNGEONJSON) move pmd-red $<
