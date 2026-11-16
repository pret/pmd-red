%.4bpp:   %.png  ; $(GBAGFX) $< $@
%.pmdpal: %.pal  ; $(GBAGFX) $< $@

# Build .pmdpal from every .pal in graphics/kao/pal
KAO_PAL := $(wildcard graphics/kao/pal/*.pal)
KAO_PMDPAL := $(patsubst %.pal,%.pmdpal,$(KAO_PAL))
kao_pal: $(KAO_PMDPAL)
