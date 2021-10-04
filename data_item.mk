# Item data

ITEM_DIR = $(DATA_ASM_SUBDIR)/item
ITEM_DATA = $(ITEM_DIR)/item_data.inc

data_item: $(ITEM_DATA);

$(ITEM_DATA): $(ITEM_DIR)/item_data.json
	$(DUNGEONJSON) item pmd-red $<
