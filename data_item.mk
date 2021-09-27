# Item data

ITEM_DIR = $(DATA_ASM_SUBDIR)/item
ITEM_SPECIES = $(ITEM_DIR)/item_data.inc

data_item: $(ITEM_SPECIES);

$(ITEM_SPECIES): $(ITEM_DIR)/item_data.json
	$(DUNGEONJSON) item_data pmd-red $<
