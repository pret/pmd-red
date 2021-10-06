# Move data

MOVE_DIR = $(DATA_ASM_SUBDIR)/move
MOVE_DATA = $(MOVE_DIR)/move_data.inc

data_move: $(MOVE_DATA);

$(MOVE_DATA): $(MOVE_DIR)/move_data.json
	$(DUNGEONJSON) move pmd-red $<
