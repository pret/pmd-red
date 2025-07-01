	.section .rodata
    
.align 2

@ These macros correspond to structs defined in 'include/structs/axdata.h'

.macro ax_siro ptr:req
.string "SIRO"
.4byte \ptr
.word 0, 0
.endm

.macro ax_main poses:req, anims:req, animCount:req, sprites:req, positions:req
.4byte \poses
.4byte \anims
.4byte \animCount
.4byte \sprites
.4byte \positions
.endm

.macro ax_pose_full spriteId:req, unk1AlwaysZero:req, unk2AlwaysZero:req, flags1:req, flags2:req, flags3:req
.2byte \spriteId
.byte \unk1AlwaysZero
.byte \unk2AlwaysZero
.2byte \flags1
.2byte \flags2
.2byte \flags3
.endm

.macro ax_pose spriteId:req, flags1:req, flags2:req, flags3:req
ax_pose_full \spriteId, 0, 0, \flags1, \flags2, \flags3
.endm

.macro ax_pose_terminator
ax_pose_full -1, -1, -1, -1, -1, -1
.endm

.macro ax_anim frames:req, unkFlags:req, poseId:req, offsetX:req, offsetY:req, shadowX:req, shadowY:req
.byte \frames
.byte \unkFlags
.2byte \poseId
.2byte \offsetX, \offsetY
.2byte \shadowX, \shadowY
.endm

.macro ax_anim_terminator
ax_anim 0, 0, 0, 0, 0, 0, 0
.endm

.macro ax_sprite ptr:req, size:req
.4byte \ptr
.4byte \size
.endm

.macro ax_sprite_terminator
ax_sprite 0, 0
.endm

@ It seems pksdir is put every 10 mons



.macro kao_siro ptr:req
.string "SIRO"
.4byte \ptr
.word 0, 0
.endm

@ See "include/structs_str_mon_portrait.h"
.macro kao_portrait pal:req, gfx:req
.4byte \pal
.4byte \gfx
.endm

.include "data/kao/bulbasaur.inc"
.include "data/kao/charmander.inc"
.include "data/kao/charizard.inc"
.include "data/kao/squirtle.inc"
.include "data/kao/blastoise.inc"
.include "data/kao/caterpie.inc"
.include "data/kao/metapod.inc"
.string "pksdir0\0"
.include "data/kao/butterfree.inc"
.include "data/kao/ekans.inc"
.include "data/kao/pikachu.inc"
.include "data/kao/ninetales.inc"
.include "data/kao/wigglytuff.inc"
.include "data/kao/diglett.inc"
.include "data/kao/dugtrio.inc"
.include "data/kao/meowth.inc"
.include "data/kao/persian.inc"
.include "data/kao/psyduck.inc"
.include "data/kao/mankey.inc"
.include "data/kao/alakazam.inc"
.include "data/kao/machop.inc"
.include "data/kao/bellsprout.inc"
.include "data/kao/golem.inc"
.include "data/kao/magnemite.inc"
.include "data/kao/gengar.inc"
.include "data/kao/cubone.inc"
.include "data/kao/kangaskhan.inc"
.include "data/kao/eevee.inc"
.include "data/kao/articuno.inc"
.include "data/kao/zapdos.inc"
.include "data/kao/moltres.inc"
.include "data/kao/mewtwo.inc"
.include "data/kao/chikorita.inc"
.include "data/kao/cyndaquil.inc"
.include "data/kao/totodile.inc"
.include "data/kao/xatu.inc"
.include "data/kao/jumpluff.inc"
.include "data/kao/wobbuffet.inc"
.string "pksdir0\0"
.include "data/kao/snubbull.inc"
.include "data/kao/granbull.inc"
.include "data/kao/octillery.inc"
.include "data/kao/skarmory.inc"
.include "data/kao/smeargle.inc"
.include "data/kao/raikou.inc"
.include "data/kao/entei.inc"
.include "data/kao/suicune.inc"
.include "data/kao/tyranitar.inc"
.include "data/kao/lugia.inc"
.string "pksdir0\0"
.include "data/kao/hooh.inc"
.include "data/kao/treecko.inc"
.include "data/kao/torchic.inc"
.include "data/kao/mudkip.inc"
.include "data/kao/lombre.inc"
.include "data/kao/shiftry.inc"
.include "data/kao/pelipper.inc"
.include "data/kao/gardevoir.inc"
.include "data/kao/makuhita.inc"
.include "data/kao/skitty.inc"
.include "data/kao/medicham.inc"
.include "data/kao/gulpin.inc"
.include "data/kao/spinda.inc"
.include "data/kao/whiscash.inc"
.include "data/kao/kecleon.inc"
.include "data/kao/absol.inc"
.include "data/kao/wynaut.inc"
.include "data/kao/latias.inc"
.include "data/kao/latios.inc"
.include "data/kao/kyogre.inc"
.string "pksdir0\0"
.include "data/kao/groudon.inc"
.include "data/kao/rayquaza.inc"
.include "data/kao/jirachi.inc"
.include "data/kao/deoxysnormal.inc"
.include "data/kao/munchlax.inc"
.include "data/kao/rayquazacutscene.inc"
