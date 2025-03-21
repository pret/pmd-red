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
.include "data/ax/bulbasaur.inc"
.include "data/ax/ivysaur.inc"
.include "data/ax/venusaur.inc"
.include "data/ax/charmander.inc"
.include "data/ax/charmeleon.inc"
.include "data/ax/charizard.inc"
.include "data/ax/squirtle.inc"
.include "data/ax/wartortle.inc"
.include "data/ax/blastoise.inc"
.include "data/ax/caterpie.inc"
.string "pksdir0\0"
.include "data/ax/metapod.inc"
.include "data/ax/butterfree.inc"
.include "data/ax/weedle.inc"
.include "data/ax/kakuna.inc"
.include "data/ax/beedrill.inc"
.include "data/ax/pidgey.inc"
.include "data/ax/pidgeotto.inc"
.include "data/ax/pidgeot.inc"
.include "data/ax/rattata.inc"
.include "data/ax/raticate.inc"
.string "pksdir0\0"
.include "data/ax/spearow.inc"
.include "data/ax/fearow.inc"
.include "data/ax/ekans.inc"
.include "data/ax/arbok.inc"
.include "data/ax/pikachu.inc"
.include "data/ax/raichu.inc"
.include "data/ax/sandshrew.inc"
.include "data/ax/sandslash.inc"
.include "data/ax/nidoranf.inc"
.include "data/ax/nidorina.inc"
.string "pksdir0\0"
.include "data/ax/nidoqueen.inc"
.include "data/ax/nidoranm.inc"
.include "data/ax/nidorino.inc"
.include "data/ax/nidoking.inc"
.include "data/ax/clefairy.inc"
.include "data/ax/clefable.inc"
.include "data/ax/vulpix.inc"
.include "data/ax/ninetales.inc"
.include "data/ax/jigglypuff.inc"
.include "data/ax/wigglytuff.inc"
.string "pksdir0\0"
.include "data/ax/zubat.inc"
.include "data/ax/golbat.inc"
.include "data/ax/oddish.inc"
.include "data/ax/gloom.inc"
.include "data/ax/vileplume.inc"
.include "data/ax/paras.inc"
.include "data/ax/parasect.inc"
.include "data/ax/venonat.inc"
.include "data/ax/venomoth.inc"
.include "data/ax/diglett.inc"
.string "pksdir0\0"
.include "data/ax/dugtrio.inc"
.include "data/ax/meowth.inc"
.include "data/ax/persian.inc"
.include "data/ax/psyduck.inc"
.include "data/ax/golduck.inc"
.include "data/ax/mankey.inc"
.include "data/ax/primeape.inc"
.include "data/ax/growlithe.inc"
.include "data/ax/arcanine.inc"
.include "data/ax/poliwag.inc"
.string "pksdir0\0"
.include "data/ax/poliwhirl.inc"
.include "data/ax/poliwrath.inc"
.include "data/ax/abra.inc"
.include "data/ax/kadabra.inc"
.include "data/ax/alakazam.inc"
.include "data/ax/machop.inc"
.include "data/ax/machoke.inc"
.include "data/ax/machamp.inc"
.include "data/ax/bellsprout.inc"
.include "data/ax/weepinbell.inc"
.string "pksdir0\0"
.include "data/ax/victreebel.inc"
.include "data/ax/tentacool.inc"
.include "data/ax/tentacruel.inc"
.include "data/ax/geodude.inc"
.include "data/ax/graveler.inc"
.include "data/ax/golem.inc"
.include "data/ax/ponyta.inc"
.include "data/ax/rapidash.inc"
.include "data/ax/slowpoke.inc"
.include "data/ax/slowbro.inc"
.string "pksdir0\0"
.include "data/ax/magnemite.inc"
.include "data/ax/magneton.inc"
.include "data/ax/farfetchd.inc"
.include "data/ax/doduo.inc"
.include "data/ax/dodrio.inc"
.include "data/ax/seel.inc"
.include "data/ax/dewgong.inc"
.include "data/ax/grimer.inc"
.include "data/ax/muk.inc"
.include "data/ax/shellder.inc"
.string "pksdir0\0"
.include "data/ax/cloyster.inc"
.include "data/ax/gastly.inc"
.include "data/ax/haunter.inc"
.include "data/ax/gengar.inc"
.include "data/ax/onix.inc"
.include "data/ax/drowzee.inc"
.include "data/ax/hypno.inc"
.include "data/ax/krabby.inc"
.include "data/ax/kingler.inc"
.include "data/ax/voltorb.inc"
.string "pksdir0\0"
.include "data/ax/electrode.inc"
.include "data/ax/exeggcute.inc"
.include "data/ax/exeggutor.inc"
.include "data/ax/cubone.inc"
.include "data/ax/marowak.inc"
.include "data/ax/hitmonlee.inc"
.include "data/ax/hitmonchan.inc"
.include "data/ax/lickitung.inc"
.include "data/ax/koffing.inc"
.include "data/ax/weezing.inc"
.string "pksdir0\0"
.include "data/ax/rhyhorn.inc"
.include "data/ax/rhydon.inc"
.include "data/ax/chansey.inc"
.include "data/ax/tangela.inc"
.include "data/ax/kangaskhan.inc"
.include "data/ax/horsea.inc"
.include "data/ax/seadra.inc"
.include "data/ax/goldeen.inc"
.include "data/ax/seaking.inc"
.include "data/ax/staryu.inc"
.string "pksdir0\0"
.include "data/ax/starmie.inc"
.include "data/ax/mrmime.inc"
.include "data/ax/scyther.inc"
.include "data/ax/jynx.inc"
.include "data/ax/electabuzz.inc"
.include "data/ax/magmar.inc"
.include "data/ax/pinsir.inc"
.include "data/ax/tauros.inc"
.include "data/ax/magikarp.inc"
.include "data/ax/gyarados.inc"
.string "pksdir0\0"
.include "data/ax/lapras.inc"
.include "data/ax/ditto.inc"
.include "data/ax/eevee.inc"
.include "data/ax/vaporeon.inc"
.include "data/ax/jolteon.inc"
.include "data/ax/flareon.inc"
.include "data/ax/porygon.inc"
.include "data/ax/omanyte.inc"
.include "data/ax/omastar.inc"
.include "data/ax/kabuto.inc"
.string "pksdir0\0"
.include "data/ax/kabutops.inc"
.include "data/ax/aerodactyl.inc"
.include "data/ax/snorlax.inc"
.include "data/ax/articuno.inc"
.include "data/ax/zapdos.inc"
.include "data/ax/moltres.inc"
.include "data/ax/dratini.inc"
.include "data/ax/dragonair.inc"
.include "data/ax/dragonite.inc"
.include "data/ax/mewtwo.inc"
.string "pksdir0\0"
.include "data/ax/mew.inc"
.include "data/ax/chikorita.inc"
.include "data/ax/bayleef.inc"
.include "data/ax/meganium.inc"
.include "data/ax/cyndaquil.inc"
.include "data/ax/quilava.inc"
.include "data/ax/typhlosion.inc"
.include "data/ax/totodile.inc"
.include "data/ax/croconaw.inc"
.include "data/ax/feraligatr.inc"
.string "pksdir0\0"
.include "data/ax/sentret.inc"
.include "data/ax/furret.inc"
.include "data/ax/hoothoot.inc"
.include "data/ax/noctowl.inc"
.include "data/ax/ledyba.inc"
.include "data/ax/ledian.inc"
.include "data/ax/spinarak.inc"
.include "data/ax/ariados.inc"
.include "data/ax/crobat.inc"
.include "data/ax/chinchou.inc"
.string "pksdir0\0"
.include "data/ax/lanturn.inc"
.include "data/ax/pichu.inc"
.include "data/ax/cleffa.inc"
.include "data/ax/igglybuff.inc"
.include "data/ax/togepi.inc"
.include "data/ax/togetic.inc"
.include "data/ax/natu.inc"
.include "data/ax/xatu.inc"
.include "data/ax/mareep.inc"
.include "data/ax/flaaffy.inc"
.string "pksdir0\0"
.include "data/ax/ampharos.inc"
.include "data/ax/bellossom.inc"
.include "data/ax/marill.inc"
.include "data/ax/azumarill.inc"
.include "data/ax/sudowoodo.inc"
.include "data/ax/politoed.inc"
.include "data/ax/hoppip.inc"
.include "data/ax/skiploom.inc"
.include "data/ax/jumpluff.inc"
.include "data/ax/aipom.inc"
.string "pksdir0\0"
.include "data/ax/sunkern.inc"
.include "data/ax/sunflora.inc"
.include "data/ax/yanma.inc"
.include "data/ax/wooper.inc"
.include "data/ax/quagsire.inc"
.include "data/ax/espeon.inc"
.include "data/ax/umbreon.inc"
.include "data/ax/murkrow.inc"
.include "data/ax/slowking.inc"
.include "data/ax/misdreavus.inc"
.string "pksdir0\0"
.include "data/ax/unowna.inc"
.include "data/ax/unownb.inc"
.include "data/ax/unownc.inc"
.include "data/ax/unownd.inc"
.include "data/ax/unowne.inc"
.include "data/ax/unownf.inc"
.include "data/ax/unowng.inc"
.include "data/ax/unownh.inc"
.include "data/ax/unowni.inc"
.include "data/ax/unownj.inc"
.string "pksdir0\0"
.include "data/ax/unownk.inc"
.include "data/ax/unownl.inc"
.include "data/ax/unownm.inc"
.include "data/ax/unownn.inc"
.include "data/ax/unowno.inc"
.include "data/ax/unownp.inc"
.include "data/ax/unownq.inc"
.include "data/ax/unownr.inc"
.include "data/ax/unowns.inc"
.include "data/ax/unownt.inc"
.string "pksdir0\0"
.include "data/ax/unownu.inc"
.include "data/ax/unownv.inc"
.include "data/ax/unownw.inc"
.include "data/ax/unownx.inc"
.include "data/ax/unowny.inc"
.include "data/ax/unownz.inc"
.include "data/ax/wobbuffet.inc"
.include "data/ax/girafarig.inc"
.include "data/ax/pineco.inc"
.include "data/ax/forretress.inc"
.string "pksdir0\0"
.include "data/ax/dunsparce.inc"
.include "data/ax/gligar.inc"
.include "data/ax/steelix.inc"
.include "data/ax/snubbull.inc"
.include "data/ax/granbull.inc"
.include "data/ax/qwilfish.inc"
.include "data/ax/scizor.inc"
.include "data/ax/shuckle.inc"
.include "data/ax/heracross.inc"
.include "data/ax/sneasel.inc"
.string "pksdir0\0"
.include "data/ax/teddiursa.inc"
.include "data/ax/ursaring.inc"
.include "data/ax/slugma.inc"
.include "data/ax/magcargo.inc"
.include "data/ax/swinub.inc"
.include "data/ax/piloswine.inc"
.include "data/ax/corsola.inc"
.include "data/ax/remoraid.inc"
.include "data/ax/octillery.inc"
.include "data/ax/delibird.inc"
.string "pksdir0\0"
.include "data/ax/mantine.inc"
.include "data/ax/skarmory.inc"
.include "data/ax/houndour.inc"
.include "data/ax/houndoom.inc"
.include "data/ax/kingdra.inc"
.include "data/ax/phanpy.inc"
.include "data/ax/donphan.inc"
.include "data/ax/porygon2.inc"
.include "data/ax/stantler.inc"
.include "data/ax/smeargle.inc"
.string "pksdir0\0"
.include "data/ax/tyrogue.inc"
.include "data/ax/hitmontop.inc"
.include "data/ax/smoochum.inc"
.include "data/ax/elekid.inc"
.include "data/ax/magby.inc"
.include "data/ax/miltank.inc"
.include "data/ax/blissey.inc"
.include "data/ax/raikou.inc"
.include "data/ax/entei.inc"
.include "data/ax/suicune.inc"
.string "pksdir0\0"
.include "data/ax/larvitar.inc"
.include "data/ax/pupitar.inc"
.include "data/ax/tyranitar.inc"
.include "data/ax/lugia.inc"
.include "data/ax/hooh.inc"
.include "data/ax/celebi.inc"
.include "data/ax/treecko.inc"
.include "data/ax/grovyle.inc"
.include "data/ax/sceptile.inc"
.include "data/ax/torchic.inc"
.string "pksdir0\0"
.include "data/ax/combusken.inc"
.include "data/ax/blaziken.inc"
.include "data/ax/mudkip.inc"
.include "data/ax/marshtomp.inc"
.include "data/ax/swampert.inc"
.include "data/ax/poochyena.inc"
.include "data/ax/mightyena.inc"
.include "data/ax/zigzagoon.inc"
.include "data/ax/linoone.inc"
.include "data/ax/wurmple.inc"
.string "pksdir0\0"
.include "data/ax/silcoon.inc"
.include "data/ax/beautifly.inc"
.include "data/ax/cascoon.inc"
.include "data/ax/dustox.inc"
.include "data/ax/lotad.inc"
.include "data/ax/lombre.inc"
.include "data/ax/ludicolo.inc"
.include "data/ax/seedot.inc"
.include "data/ax/nuzleaf.inc"
.include "data/ax/shiftry.inc"
.string "pksdir0\0"
.include "data/ax/taillow.inc"
.include "data/ax/swellow.inc"
.include "data/ax/wingull.inc"
.include "data/ax/pelipper.inc"
.include "data/ax/ralts.inc"
.include "data/ax/kirlia.inc"
.include "data/ax/gardevoir.inc"
.include "data/ax/surskit.inc"
.include "data/ax/masquerain.inc"
.include "data/ax/shroomish.inc"
.string "pksdir0\0"
.include "data/ax/breloom.inc"
.include "data/ax/slakoth.inc"
.include "data/ax/vigoroth.inc"
.include "data/ax/slaking.inc"
.include "data/ax/nincada.inc"
.include "data/ax/ninjask.inc"
.include "data/ax/shedinja.inc"
.include "data/ax/whismur.inc"
.include "data/ax/loudred.inc"
.include "data/ax/exploud.inc"
.string "pksdir0\0"
.include "data/ax/makuhita.inc"
.include "data/ax/hariyama.inc"
.include "data/ax/azurill.inc"
.include "data/ax/nosepass.inc"
.include "data/ax/skitty.inc"
.include "data/ax/delcatty.inc"
.include "data/ax/sableye.inc"
.include "data/ax/mawile.inc"
.include "data/ax/aron.inc"
.include "data/ax/lairon.inc"
.string "pksdir0\0"
.include "data/ax/aggron.inc"
.include "data/ax/meditite.inc"
.include "data/ax/medicham.inc"
.include "data/ax/electrike.inc"
.include "data/ax/manectric.inc"
.include "data/ax/plusle.inc"
.include "data/ax/minun.inc"
.include "data/ax/volbeat.inc"
.include "data/ax/illumise.inc"
.include "data/ax/roselia.inc"
.string "pksdir0\0"
.include "data/ax/gulpin.inc"
.include "data/ax/swalot.inc"
.include "data/ax/carvanha.inc"
.include "data/ax/sharpedo.inc"
.include "data/ax/wailmer.inc"
.include "data/ax/wailord.inc"
.include "data/ax/numel.inc"
.include "data/ax/camerupt.inc"
.include "data/ax/torkoal.inc"
.include "data/ax/spoink.inc"
.string "pksdir0\0"
.include "data/ax/grumpig.inc"
.include "data/ax/spinda.inc"
.include "data/ax/trapinch.inc"
.include "data/ax/vibrava.inc"
.include "data/ax/flygon.inc"
.include "data/ax/cacnea.inc"
.include "data/ax/cacturne.inc"
.include "data/ax/swablu.inc"
.include "data/ax/altaria.inc"
.include "data/ax/zangoose.inc"
.string "pksdir0\0"
.include "data/ax/seviper.inc"
.include "data/ax/lunatone.inc"
.include "data/ax/solrock.inc"
.include "data/ax/barboach.inc"
.include "data/ax/whiscash.inc"
.include "data/ax/corphish.inc"
.include "data/ax/crawdaunt.inc"
.include "data/ax/baltoy.inc"
.include "data/ax/claydol.inc"
.include "data/ax/lileep.inc"
.string "pksdir0\0"
.include "data/ax/cradily.inc"
.include "data/ax/anorith.inc"
.include "data/ax/armaldo.inc"
.include "data/ax/feebas.inc"
.include "data/ax/milotic.inc"
.include "data/ax/castform.inc"
.include "data/ax/castformsnowy.inc"
.include "data/ax/castformsunny.inc"
.include "data/ax/castformrainy.inc"
.include "data/ax/kecleon.inc"
.string "pksdir0\0"
.include "data/ax/shuppet.inc"
.include "data/ax/banette.inc"
.include "data/ax/duskull.inc"
.include "data/ax/dusclops.inc"
.include "data/ax/tropius.inc"
.include "data/ax/chimecho.inc"
.include "data/ax/absol.inc"
.include "data/ax/wynaut.inc"
.include "data/ax/snorunt.inc"
.include "data/ax/glalie.inc"
.string "pksdir0\0"
.include "data/ax/spheal.inc"
.include "data/ax/sealeo.inc"
.include "data/ax/walrein.inc"
.include "data/ax/clamperl.inc"
.include "data/ax/huntail.inc"
.include "data/ax/gorebyss.inc"
.include "data/ax/relicanth.inc"
.include "data/ax/luvdisc.inc"
.include "data/ax/bagon.inc"
.include "data/ax/shelgon.inc"
.string "pksdir0\0"
.include "data/ax/salamence.inc"
.include "data/ax/beldum.inc"
.include "data/ax/metang.inc"
.include "data/ax/metagross.inc"
.include "data/ax/regirock.inc"
.include "data/ax/regice.inc"
.include "data/ax/registeel.inc"
.include "data/ax/latias.inc"
.include "data/ax/latios.inc"
.include "data/ax/kyogre.inc"
.string "pksdir0\0"
.include "data/ax/groudon.inc"
.include "data/ax/rayquaza.inc"
.include "data/ax/jirachi.inc"
.include "data/ax/deoxysnormal.inc"
.include "data/ax/unownemark.inc"
.include "data/ax/unownqmark.inc"
.include "data/ax/deoxysattack.inc"
.include "data/ax/deoxysdefense.inc"
.include "data/ax/deoxysspeed.inc"
.include "data/ax/munchlax.inc"
.string "pksdir0\0"
.include "data/ax/decoy.inc"
.include "data/ax/statue.inc"
.include "data/ax/rayquazacutscene.inc"

.global gKaoBulbasaur
gKaoBulbasaur:
.string "SIRO"
.4byte gUnknown_9682588
.incbin "baserom.gba", 0x167FE80, 0x8
.global gUnknown_967FE88
gUnknown_967FE88:
.incbin "baserom.gba", 0x167FE88, 0x40
.global gUnknown_967FEC8
gUnknown_967FEC8:
.string "AT4PX"
.incbin "baserom.gba", 0x167FECD, 0x2BF
.global gUnknown_968018C
gUnknown_968018C:
.incbin "baserom.gba", 0x168018C, 0x40
.global gUnknown_96801CC
gUnknown_96801CC:
.incbin "baserom.gba", 0x16801CC, 0x2AC
.global gUnknown_9680478
gUnknown_9680478:
.incbin "baserom.gba", 0x1680478, 0x40
.global gUnknown_96804B8
gUnknown_96804B8:
.string "AT4PX"
.incbin "baserom.gba", 0x16804BD, 0x2C3
.global gUnknown_9680780
gUnknown_9680780:
.incbin "baserom.gba", 0x1680780, 0x40
.global gUnknown_96807C0
gUnknown_96807C0:
.string "AT4PX"
.incbin "baserom.gba", 0x16807C5, 0x2DF
.global gUnknown_9680AA4
gUnknown_9680AA4:
.incbin "baserom.gba", 0x1680AA4, 0x40
.global gUnknown_9680AE4
gUnknown_9680AE4:
.incbin "baserom.gba", 0x1680AE4, 0x2CC
.global gUnknown_9680DB0
gUnknown_9680DB0:
.incbin "baserom.gba", 0x1680DB0, 0x40
.global gUnknown_9680DF0
gUnknown_9680DF0:
.string "AT4PX"
.incbin "baserom.gba", 0x1680DF5, 0x2A7
.global gUnknown_968109C
gUnknown_968109C:
.incbin "baserom.gba", 0x168109C, 0x40
.global gUnknown_96810DC
gUnknown_96810DC:
.incbin "baserom.gba", 0x16810DC, 0x2BC
.global gUnknown_9681398
gUnknown_9681398:
.incbin "baserom.gba", 0x1681398, 0x40
.global gUnknown_96813D8
gUnknown_96813D8:
.incbin "baserom.gba", 0x16813D8, 0x2C8
.global gUnknown_96816A0
gUnknown_96816A0:
.incbin "baserom.gba", 0x16816A0, 0x40
.global gUnknown_96816E0
gUnknown_96816E0:
.string "AT4PX"
.incbin "baserom.gba", 0x16816E5, 0x2A7
.global gUnknown_968198C
gUnknown_968198C:
.incbin "baserom.gba", 0x168198C, 0x40
.global gUnknown_96819CC
gUnknown_96819CC:
.incbin "baserom.gba", 0x16819CC, 0x2B0
.global gUnknown_9681C7C
gUnknown_9681C7C:
.incbin "baserom.gba", 0x1681C7C, 0x40
.global gUnknown_9681CBC
gUnknown_9681CBC:
.incbin "baserom.gba", 0x1681CBC, 0x2C0
.global gUnknown_9681F7C
gUnknown_9681F7C:
.incbin "baserom.gba", 0x1681F7C, 0x40
.global gUnknown_9681FBC
gUnknown_9681FBC:
.incbin "baserom.gba", 0x1681FBC, 0x2BC
.global gUnknown_9682278
gUnknown_9682278:
.incbin "baserom.gba", 0x1682278, 0x40
.global gUnknown_96822B8
gUnknown_96822B8:
.incbin "baserom.gba", 0x16822B8, 0x2D0
.global gUnknown_9682588
gUnknown_9682588:
.4byte gUnknown_967FE88
.4byte gUnknown_967FEC8
.4byte gUnknown_968018C
.4byte gUnknown_96801CC
.4byte gUnknown_9680478
.4byte gUnknown_96804B8
.4byte gUnknown_9680780
.4byte gUnknown_96807C0
.4byte gUnknown_9680AA4
.4byte gUnknown_9680AE4
.4byte gUnknown_9680DB0
.4byte gUnknown_9680DF0
.4byte gUnknown_968109C
.4byte gUnknown_96810DC
.4byte gUnknown_9681398
.4byte gUnknown_96813D8
.4byte gUnknown_96816A0
.4byte gUnknown_96816E0
.4byte gUnknown_968198C
.4byte gUnknown_96819CC
.4byte gUnknown_9681C7C
.4byte gUnknown_9681CBC
.4byte gUnknown_9681F7C
.4byte gUnknown_9681FBC
.4byte gUnknown_9682278
.4byte gUnknown_96822B8
.global gKaoCharmander
gKaoCharmander:
.string "SIRO"
.4byte gUnknown_96848C8
.incbin "baserom.gba", 0x16825F8, 0x8
.global gUnknown_9682600
gUnknown_9682600:
.incbin "baserom.gba", 0x1682600, 0x40
.global gUnknown_9682640
gUnknown_9682640:
.string "AT4PX"
.incbin "baserom.gba", 0x1682645, 0x247
.global gUnknown_968288C
gUnknown_968288C:
.incbin "baserom.gba", 0x168288C, 0x40
.global gUnknown_96828CC
gUnknown_96828CC:
.incbin "baserom.gba", 0x16828CC, 0x234
.global gUnknown_9682B00
gUnknown_9682B00:
.incbin "baserom.gba", 0x1682B00, 0x40
.global gUnknown_9682B40
gUnknown_9682B40:
.string "AT4PX"
.incbin "baserom.gba", 0x1682B45, 0x253
.global gUnknown_9682D98
gUnknown_9682D98:
.incbin "baserom.gba", 0x1682D98, 0x40
.global gUnknown_9682DD8
gUnknown_9682DD8:
.string "AT4PX"
.incbin "baserom.gba", 0x1682DDD, 0x27B
.global gUnknown_9683058
gUnknown_9683058:
.incbin "baserom.gba", 0x1683058, 0x40
.global gUnknown_9683098
gUnknown_9683098:
.incbin "baserom.gba", 0x1683098, 0x254
.global gUnknown_96832EC
gUnknown_96832EC:
.incbin "baserom.gba", 0x16832EC, 0x40
.global gUnknown_968332C
gUnknown_968332C:
.incbin "baserom.gba", 0x168332C, 0x254
.global gUnknown_9683580
gUnknown_9683580:
.incbin "baserom.gba", 0x1683580, 0x40
.global gUnknown_96835C0
gUnknown_96835C0:
.string "AT4PX"
.incbin "baserom.gba", 0x16835C5, 0x263
.global gUnknown_9683828
gUnknown_9683828:
.incbin "baserom.gba", 0x1683828, 0x40
.global gUnknown_9683868
gUnknown_9683868:
.incbin "baserom.gba", 0x1683868, 0x2A8
.global gUnknown_9683B10
gUnknown_9683B10:
.incbin "baserom.gba", 0x1683B10, 0x40
.global gUnknown_9683B50
gUnknown_9683B50:
.string "AT4PX"
.incbin "baserom.gba", 0x1683B55, 0x25B
.global gUnknown_9683DB0
gUnknown_9683DB0:
.incbin "baserom.gba", 0x1683DB0, 0x40
.global gUnknown_9683DF0
gUnknown_9683DF0:
.string "AT4PX"
.incbin "baserom.gba", 0x1683DF5, 0x247
.global gUnknown_968403C
gUnknown_968403C:
.incbin "baserom.gba", 0x168403C, 0x40
.global gUnknown_968407C
gUnknown_968407C:
.incbin "baserom.gba", 0x168407C, 0x2E0
.global gUnknown_968435C
gUnknown_968435C:
.incbin "baserom.gba", 0x168435C, 0x40
.global gUnknown_968439C
gUnknown_968439C:
.incbin "baserom.gba", 0x168439C, 0x248
.global gUnknown_96845E4
gUnknown_96845E4:
.incbin "baserom.gba", 0x16845E4, 0x40
.global gUnknown_9684624
gUnknown_9684624:
.incbin "baserom.gba", 0x1684624, 0x2A4
.global gUnknown_96848C8
gUnknown_96848C8:
.4byte gUnknown_9682600
.4byte gUnknown_9682640
.4byte gUnknown_968288C
.4byte gUnknown_96828CC
.4byte gUnknown_9682B00
.4byte gUnknown_9682B40
.4byte gUnknown_9682D98
.4byte gUnknown_9682DD8
.4byte gUnknown_9683058
.4byte gUnknown_9683098
.4byte gUnknown_96832EC
.4byte gUnknown_968332C
.4byte gUnknown_9683580
.4byte gUnknown_96835C0
.4byte gUnknown_9683828
.4byte gUnknown_9683868
.4byte gUnknown_9683B10
.4byte gUnknown_9683B50
.4byte gUnknown_9683DB0
.4byte gUnknown_9683DF0
.4byte gUnknown_968403C
.4byte gUnknown_968407C
.4byte gUnknown_968435C
.4byte gUnknown_968439C
.4byte gUnknown_96845E4
.4byte gUnknown_9684624
.global gKaoCharizard
gKaoCharizard:
.string "SIRO"
.4byte gUnknown_9685780
.incbin "baserom.gba", 0x1684938, 0x8
.global gUnknown_9684940
gUnknown_9684940:
.incbin "baserom.gba", 0x1684940, 0x40
.global gUnknown_9684980
gUnknown_9684980:
.string "AT4PX"
.incbin "baserom.gba", 0x1684985, 0x267
.global gUnknown_9684BEC
gUnknown_9684BEC:
.incbin "baserom.gba", 0x1684BEC, 0x40
.global gUnknown_9684C2C
gUnknown_9684C2C:
.incbin "baserom.gba", 0x1684C2C, 0x2B4
.global gUnknown_9684EE0
gUnknown_9684EE0:
.incbin "baserom.gba", 0x1684EE0, 0x40
.global gUnknown_9684F20
gUnknown_9684F20:
.string "AT4PX"
.incbin "baserom.gba", 0x1684F25, 0x28F
.global gUnknown_96851B4
gUnknown_96851B4:
.incbin "baserom.gba", 0x16851B4, 0x40
.global gUnknown_96851F4
gUnknown_96851F4:
.string "AT4PX"
.incbin "baserom.gba", 0x16851F9, 0x2BF
.global gUnknown_96854B8
gUnknown_96854B8:
.incbin "baserom.gba", 0x16854B8, 0x40
.global gUnknown_96854F8
gUnknown_96854F8:
.incbin "baserom.gba", 0x16854F8, 0x288
.global gUnknown_9685780
gUnknown_9685780:
.4byte gUnknown_9684940
.4byte gUnknown_9684980
.4byte gUnknown_9684BEC
.4byte gUnknown_9684C2C
.4byte gUnknown_9684EE0
.4byte gUnknown_9684F20
.4byte gUnknown_96851B4
.4byte gUnknown_96851F4
.4byte gUnknown_96854B8
.4byte gUnknown_96854F8
.incbin "baserom.gba", 0x16857A8, 0x40
.global gKaoSquirtle
gKaoSquirtle:
.string "SIRO"
.4byte gUnknown_9687E10
.incbin "baserom.gba", 0x16857F0, 0x8
.global gUnknown_96857F8
gUnknown_96857F8:
.incbin "baserom.gba", 0x16857F8, 0x40
.global gUnknown_9685838
gUnknown_9685838:
.string "AT4PX"
.incbin "baserom.gba", 0x168583D, 0x28F
.global gUnknown_9685ACC
gUnknown_9685ACC:
.incbin "baserom.gba", 0x1685ACC, 0x40
.global gUnknown_9685B0C
gUnknown_9685B0C:
.incbin "baserom.gba", 0x1685B0C, 0x2A4
.global gUnknown_9685DB0
gUnknown_9685DB0:
.incbin "baserom.gba", 0x1685DB0, 0x40
.global gUnknown_9685DF0
gUnknown_9685DF0:
.string "AT4PX"
.incbin "baserom.gba", 0x1685DF5, 0x2A3
.global gUnknown_9686098
gUnknown_9686098:
.incbin "baserom.gba", 0x1686098, 0x40
.global gUnknown_96860D8
gUnknown_96860D8:
.string "AT4PX"
.incbin "baserom.gba", 0x16860DD, 0x2C7
.global gUnknown_96863A4
gUnknown_96863A4:
.incbin "baserom.gba", 0x16863A4, 0x40
.global gUnknown_96863E4
gUnknown_96863E4:
.incbin "baserom.gba", 0x16863E4, 0x2B4
.global gUnknown_9686698
gUnknown_9686698:
.incbin "baserom.gba", 0x1686698, 0x40
.global gUnknown_96866D8
gUnknown_96866D8:
.incbin "baserom.gba", 0x16866D8, 0x29C
.global gUnknown_9686974
gUnknown_9686974:
.incbin "baserom.gba", 0x1686974, 0x40
.global gUnknown_96869B4
gUnknown_96869B4:
.incbin "baserom.gba", 0x16869B4, 0x2AC
.global gUnknown_9686C60
gUnknown_9686C60:
.incbin "baserom.gba", 0x1686C60, 0x40
.global gUnknown_9686CA0
gUnknown_9686CA0:
.string "AT4PX"
.incbin "baserom.gba", 0x1686CA5, 0x2A7
.global gUnknown_9686F4C
gUnknown_9686F4C:
.incbin "baserom.gba", 0x1686F4C, 0x40
.global gUnknown_9686F8C
gUnknown_9686F8C:
.incbin "baserom.gba", 0x1686F8C, 0x2A0
.global gUnknown_968722C
gUnknown_968722C:
.incbin "baserom.gba", 0x168722C, 0x40
.global gUnknown_968726C
gUnknown_968726C:
.incbin "baserom.gba", 0x168726C, 0x298
.global gUnknown_9687504
gUnknown_9687504:
.incbin "baserom.gba", 0x1687504, 0x40
.global gUnknown_9687544
gUnknown_9687544:
.incbin "baserom.gba", 0x1687544, 0x2E4
.global gUnknown_9687828
gUnknown_9687828:
.incbin "baserom.gba", 0x1687828, 0x40
.global gUnknown_9687868
gUnknown_9687868:
.incbin "baserom.gba", 0x1687868, 0x298
.global gUnknown_9687B00
gUnknown_9687B00:
.incbin "baserom.gba", 0x1687B00, 0x40
.global gUnknown_9687B40
gUnknown_9687B40:
.string "AT4PX"
.incbin "baserom.gba", 0x1687B45, 0x2CB
.global gUnknown_9687E10
gUnknown_9687E10:
.4byte gUnknown_96857F8
.4byte gUnknown_9685838
.4byte gUnknown_9685ACC
.4byte gUnknown_9685B0C
.4byte gUnknown_9685DB0
.4byte gUnknown_9685DF0
.4byte gUnknown_9686098
.4byte gUnknown_96860D8
.4byte gUnknown_96863A4
.4byte gUnknown_96863E4
.4byte gUnknown_9686698
.4byte gUnknown_96866D8
.4byte gUnknown_9686974
.4byte gUnknown_96869B4
.4byte gUnknown_9686C60
.4byte gUnknown_9686CA0
.4byte gUnknown_9686F4C
.4byte gUnknown_9686F8C
.4byte gUnknown_968722C
.4byte gUnknown_968726C
.4byte gUnknown_9687504
.4byte gUnknown_9687544
.4byte gUnknown_9687828
.4byte gUnknown_9687868
.4byte gUnknown_9687B00
.4byte gUnknown_9687B40
.global gKaoBlastoise
gKaoBlastoise:
.string "SIRO"
.4byte gUnknown_9688A40
.incbin "baserom.gba", 0x1687E80, 0x8
.global gUnknown_9687E88
gUnknown_9687E88:
.incbin "baserom.gba", 0x1687E88, 0x40
.global gUnknown_9687EC8
gUnknown_9687EC8:
.string "AT4PX"
.incbin "baserom.gba", 0x1687ECD, 0x2AB
.global gUnknown_9688178
gUnknown_9688178:
.incbin "baserom.gba", 0x1688178, 0x40
.global gUnknown_96881B8
gUnknown_96881B8:
.string "AT4PX"
.incbin "baserom.gba", 0x16881BD, 0x2A3
.global gUnknown_9688460
gUnknown_9688460:
.incbin "baserom.gba", 0x1688460, 0x40
.global gUnknown_96884A0
gUnknown_96884A0:
.string "AT4PX"
.incbin "baserom.gba", 0x16884A5, 0x2B3
.global gUnknown_9688758
gUnknown_9688758:
.incbin "baserom.gba", 0x1688758, 0x40
.global gUnknown_9688798
gUnknown_9688798:
.string "AT4PX"
.incbin "baserom.gba", 0x168879D, 0x2A3
.global gUnknown_9688A40
gUnknown_9688A40:
.4byte gUnknown_9687E88
.4byte gUnknown_9687EC8
.4byte gUnknown_9688178
.4byte gUnknown_96881B8
.4byte gUnknown_9688460
.4byte gUnknown_96884A0
.4byte gUnknown_9688758
.4byte gUnknown_9688798
.incbin "baserom.gba", 0x1688A60, 0x48
.global gKaoCaterpie
gKaoCaterpie:
.string "SIRO"
.4byte gUnknown_9689364
.incbin "baserom.gba", 0x1688AB0, 0x8
.global gUnknown_9688AB8
gUnknown_9688AB8:
.incbin "baserom.gba", 0x1688AB8, 0x40
.global gUnknown_9688AF8
gUnknown_9688AF8:
.string "AT4PX"
.incbin "baserom.gba", 0x1688AFD, 0x29B
.global gUnknown_9688D98
gUnknown_9688D98:
.incbin "baserom.gba", 0x1688D98, 0x40
.global gUnknown_9688DD8
gUnknown_9688DD8:
.string "AT4PX"
.incbin "baserom.gba", 0x1688DDD, 0x2AF
.global gUnknown_968908C
gUnknown_968908C:
.incbin "baserom.gba", 0x168908C, 0x40
.global gUnknown_96890CC
gUnknown_96890CC:
.incbin "baserom.gba", 0x16890CC, 0x298
.global gUnknown_9689364
gUnknown_9689364:
.4byte gUnknown_9688AB8
.4byte gUnknown_9688AF8
.4byte gUnknown_9688D98
.4byte gUnknown_9688DD8
.4byte gUnknown_968908C
.4byte gUnknown_96890CC
.incbin "baserom.gba", 0x168937C, 0x50
.global gKaoMetapod
gKaoMetapod:
.string "SIRO"
.4byte gUnknown_96896B4
.incbin "baserom.gba", 0x16893D4, 0x8
.global gUnknown_96893DC
gUnknown_96893DC:
.incbin "baserom.gba", 0x16893DC, 0x40
.global gUnknown_968941C
gUnknown_968941C:
.incbin "baserom.gba", 0x168941C, 0x298
.global gUnknown_96896B4
gUnknown_96896B4:
.4byte gUnknown_96893DC
.4byte gUnknown_968941C
.incbin "baserom.gba", 0x16896BC, 0x68
.global gKaoButterfree
gKaoButterfree:
.string "SIRO"
.4byte gUnknown_9689A60
.incbin "baserom.gba", 0x168972C, 0x8
.global gUnknown_9689734
gUnknown_9689734:
.incbin "baserom.gba", 0x1689734, 0x40
.global gUnknown_9689774
gUnknown_9689774:
.string "AT4PX"
.incbin "baserom.gba", 0x1689779, 0x2E7
.global gUnknown_9689A60
gUnknown_9689A60:
.4byte gUnknown_9689734
.4byte gUnknown_9689774
.incbin "baserom.gba", 0x1689A68, 0x60
.global gKaoEkans
gKaoEkans:
.string "SIRO"
.4byte gUnknown_968A2D4
.incbin "baserom.gba", 0x1689AD0, 0x8
.global gUnknown_9689AD8
gUnknown_9689AD8:
.incbin "baserom.gba", 0x1689AD8, 0x40
.global gUnknown_9689B18
gUnknown_9689B18:
.string "AT4PX"
.incbin "baserom.gba", 0x1689B1D, 0x23B
.global gUnknown_9689D58
gUnknown_9689D58:
.incbin "baserom.gba", 0x1689D58, 0x40
.global gUnknown_9689D98
gUnknown_9689D98:
.string "AT4PX"
.incbin "baserom.gba", 0x1689D9D, 0x2A3
.global gUnknown_968A040
gUnknown_968A040:
.incbin "baserom.gba", 0x168A040, 0x40
.global gUnknown_968A080
gUnknown_968A080:
.string "AT4PX"
.incbin "baserom.gba", 0x168A085, 0x24F
.global gUnknown_968A2D4
gUnknown_968A2D4:
.4byte gUnknown_9689AD8
.4byte gUnknown_9689B18
.4byte gUnknown_9689D58
.4byte gUnknown_9689D98
.4byte gUnknown_968A040
.4byte gUnknown_968A080
.incbin "baserom.gba", 0x168A2EC, 0x50
.global gKaoPikachu
gKaoPikachu:
.string "SIRO"
.4byte gUnknown_968C6D0
.incbin "baserom.gba", 0x168A344, 0x8
.global gUnknown_968A34C
gUnknown_968A34C:
.incbin "baserom.gba", 0x168A34C, 0x40
.global gUnknown_968A38C
gUnknown_968A38C:
.incbin "baserom.gba", 0x168A38C, 0x260
.global gUnknown_968A5EC
gUnknown_968A5EC:
.incbin "baserom.gba", 0x168A5EC, 0x40
.global gUnknown_968A62C
gUnknown_968A62C:
.incbin "baserom.gba", 0x168A62C, 0x274
.global gUnknown_968A8A0
gUnknown_968A8A0:
.incbin "baserom.gba", 0x168A8A0, 0x40
.global gUnknown_968A8E0
gUnknown_968A8E0:
.string "AT4PX"
.incbin "baserom.gba", 0x168A8E5, 0x263
.global gUnknown_968AB48
gUnknown_968AB48:
.incbin "baserom.gba", 0x168AB48, 0x40
.global gUnknown_968AB88
gUnknown_968AB88:
.string "AT4PX"
.incbin "baserom.gba", 0x168AB8D, 0x2AB
.global gUnknown_968AE38
gUnknown_968AE38:
.incbin "baserom.gba", 0x168AE38, 0x40
.global gUnknown_968AE78
gUnknown_968AE78:
.incbin "baserom.gba", 0x168AE78, 0x260
.global gUnknown_968B0D8
gUnknown_968B0D8:
.incbin "baserom.gba", 0x168B0D8, 0x40
.global gUnknown_968B118
gUnknown_968B118:
.incbin "baserom.gba", 0x168B118, 0x254
.global gUnknown_968B36C
gUnknown_968B36C:
.incbin "baserom.gba", 0x168B36C, 0x40
.global gUnknown_968B3AC
gUnknown_968B3AC:
.incbin "baserom.gba", 0x168B3AC, 0x2A4
.global gUnknown_968B650
gUnknown_968B650:
.incbin "baserom.gba", 0x168B650, 0x40
.global gUnknown_968B690
gUnknown_968B690:
.string "AT4PX"
.incbin "baserom.gba", 0x168B695, 0x293
.global gUnknown_968B928
gUnknown_968B928:
.incbin "baserom.gba", 0x168B928, 0x40
.global gUnknown_968B968
gUnknown_968B968:
.incbin "baserom.gba", 0x168B968, 0x274
.global gUnknown_968BBDC
gUnknown_968BBDC:
.incbin "baserom.gba", 0x168BBDC, 0x40
.global gUnknown_968BC1C
gUnknown_968BC1C:
.incbin "baserom.gba", 0x168BC1C, 0x244
.global gUnknown_968BE60
gUnknown_968BE60:
.incbin "baserom.gba", 0x168BE60, 0x40
.global gUnknown_968BEA0
gUnknown_968BEA0:
.string "AT4PX"
.incbin "baserom.gba", 0x168BEA5, 0x2A3
.global gUnknown_968C148
gUnknown_968C148:
.incbin "baserom.gba", 0x168C148, 0x40
.global gUnknown_968C188
gUnknown_968C188:
.incbin "baserom.gba", 0x168C188, 0x26C
.global gUnknown_968C3F4
gUnknown_968C3F4:
.incbin "baserom.gba", 0x168C3F4, 0x40
.global gUnknown_968C434
gUnknown_968C434:
.incbin "baserom.gba", 0x168C434, 0x29C
.global gUnknown_968C6D0
gUnknown_968C6D0:
.4byte gUnknown_968A34C
.4byte gUnknown_968A38C
.4byte gUnknown_968A5EC
.4byte gUnknown_968A62C
.4byte gUnknown_968A8A0
.4byte gUnknown_968A8E0
.4byte gUnknown_968AB48
.4byte gUnknown_968AB88
.4byte gUnknown_968AE38
.4byte gUnknown_968AE78
.4byte gUnknown_968B0D8
.4byte gUnknown_968B118
.4byte gUnknown_968B36C
.4byte gUnknown_968B3AC
.4byte gUnknown_968B650
.4byte gUnknown_968B690
.4byte gUnknown_968B928
.4byte gUnknown_968B968
.4byte gUnknown_968BBDC
.4byte gUnknown_968BC1C
.4byte gUnknown_968BE60
.4byte gUnknown_968BEA0
.4byte gUnknown_968C148
.4byte gUnknown_968C188
.4byte gUnknown_968C3F4
.4byte gUnknown_968C434
.global gKaoNinetales
gKaoNinetales:
.string "SIRO"
.4byte gUnknown_968CA44
.incbin "baserom.gba", 0x168C740, 0x8
.global gUnknown_968C748
gUnknown_968C748:
.incbin "baserom.gba", 0x168C748, 0x40
.global gUnknown_968C788
gUnknown_968C788:
.string "AT4PX"
.incbin "baserom.gba", 0x168C78D, 0x2B7
.global gUnknown_968CA44
gUnknown_968CA44:
.4byte gUnknown_968C748
.4byte gUnknown_968C788
.incbin "baserom.gba", 0x168CA4C, 0x60
.global gKaoWigglytuff
gKaoWigglytuff:
.string "SIRO"
.4byte gUnknown_968CDA0
.incbin "baserom.gba", 0x168CAB4, 0x8
.global gUnknown_968CABC
gUnknown_968CABC:
.incbin "baserom.gba", 0x168CABC, 0x40
.global gUnknown_968CAFC
gUnknown_968CAFC:
.incbin "baserom.gba", 0x168CAFC, 0x2A4
.global gUnknown_968CDA0
gUnknown_968CDA0:
.4byte gUnknown_968CABC
.4byte gUnknown_968CAFC
.incbin "baserom.gba", 0x168CDA8, 0x60
.global gKaoDiglett
gKaoDiglett:
.string "SIRO"
.4byte gUnknown_968D294
.incbin "baserom.gba", 0x168CE10, 0x8
.global gUnknown_968CE18
gUnknown_968CE18:
.incbin "baserom.gba", 0x168CE18, 0x40
.global gUnknown_968CE58
gUnknown_968CE58:
.string "AT4PX"
.incbin "baserom.gba", 0x168CE5D, 0x1FB
.global gUnknown_968D058
gUnknown_968D058:
.incbin "baserom.gba", 0x168D058, 0x40
.global gUnknown_968D098
gUnknown_968D098:
.string "AT4PX"
.incbin "baserom.gba", 0x168D09D, 0x1F7
.global gUnknown_968D294
gUnknown_968D294:
.4byte gUnknown_968CE18
.4byte gUnknown_968CE58
.4byte gUnknown_968D058
.4byte gUnknown_968D098
.incbin "baserom.gba", 0x168D2A4, 0x58
.global gKaoDugtrio
gKaoDugtrio:
.string "SIRO"
.4byte gUnknown_968D5BC
.incbin "baserom.gba", 0x168D304, 0x8
.global gUnknown_968D30C
gUnknown_968D30C:
.incbin "baserom.gba", 0x168D30C, 0x40
.global gUnknown_968D34C
gUnknown_968D34C:
.incbin "baserom.gba", 0x168D34C, 0x270
.global gUnknown_968D5BC
gUnknown_968D5BC:
.4byte gUnknown_968D30C
.4byte gUnknown_968D34C
.incbin "baserom.gba", 0x168D5C4, 0x60
.global gKaoMeowth
gKaoMeowth:
.string "SIRO"
.4byte gUnknown_968FE50
.incbin "baserom.gba", 0x168D62C, 0x8
.global gUnknown_968D634
gUnknown_968D634:
.incbin "baserom.gba", 0x168D634, 0x40
.global gUnknown_968D674
gUnknown_968D674:
.string "AT4PX"
.incbin "baserom.gba", 0x168D679, 0x2CF
.global gUnknown_968D948
gUnknown_968D948:
.incbin "baserom.gba", 0x168D948, 0x40
.global gUnknown_968D988
gUnknown_968D988:
.string "AT4PX"
.incbin "baserom.gba", 0x168D98D, 0x2DF
.global gUnknown_968DC6C
gUnknown_968DC6C:
.incbin "baserom.gba", 0x168DC6C, 0x40
.global gUnknown_968DCAC
gUnknown_968DCAC:
.incbin "baserom.gba", 0x168DCAC, 0x2E8
.global gUnknown_968DF94
gUnknown_968DF94:
.incbin "baserom.gba", 0x168DF94, 0x40
.global gUnknown_968DFD4
gUnknown_968DFD4:
.string "AT4PX"
.incbin "baserom.gba", 0x168DFD9, 0x2F3
.global gUnknown_968E2CC
gUnknown_968E2CC:
.incbin "baserom.gba", 0x168E2CC, 0x40
.global gUnknown_968E30C
gUnknown_968E30C:
.incbin "baserom.gba", 0x168E30C, 0x2BC
.global gUnknown_968E5C8
gUnknown_968E5C8:
.incbin "baserom.gba", 0x168E5C8, 0x40
.global gUnknown_968E608
gUnknown_968E608:
.incbin "baserom.gba", 0x168E608, 0x2D0
.global gUnknown_968E8D8
gUnknown_968E8D8:
.incbin "baserom.gba", 0x168E8D8, 0x40
.global gUnknown_968E918
gUnknown_968E918:
.incbin "baserom.gba", 0x168E918, 0x2A8
.global gUnknown_968EBC0
gUnknown_968EBC0:
.incbin "baserom.gba", 0x168EBC0, 0x40
.global gUnknown_968EC00
gUnknown_968EC00:
.incbin "baserom.gba", 0x168EC00, 0x2F0
.global gUnknown_968EEF0
gUnknown_968EEF0:
.incbin "baserom.gba", 0x168EEF0, 0x40
.global gUnknown_968EF30
gUnknown_968EF30:
.string "AT4PX"
.incbin "baserom.gba", 0x168EF35, 0x2AB
.global gUnknown_968F1E0
gUnknown_968F1E0:
.incbin "baserom.gba", 0x168F1E0, 0x40
.global gUnknown_968F220
gUnknown_968F220:
.string "AT4PX"
.incbin "baserom.gba", 0x168F225, 0x2D3
.global gUnknown_968F4F8
gUnknown_968F4F8:
.incbin "baserom.gba", 0x168F4F8, 0x40
.global gUnknown_968F538
gUnknown_968F538:
.incbin "baserom.gba", 0x168F538, 0x2CC
.global gUnknown_968F804
gUnknown_968F804:
.incbin "baserom.gba", 0x168F804, 0x40
.global gUnknown_968F844
gUnknown_968F844:
.incbin "baserom.gba", 0x168F844, 0x2D4
.global gUnknown_968FB18
gUnknown_968FB18:
.incbin "baserom.gba", 0x168FB18, 0x40
.global gUnknown_968FB58
gUnknown_968FB58:
.incbin "baserom.gba", 0x168FB58, 0x2F8
.global gUnknown_968FE50
gUnknown_968FE50:
.4byte gUnknown_968D634
.4byte gUnknown_968D674
.4byte gUnknown_968D948
.4byte gUnknown_968D988
.4byte gUnknown_968DC6C
.4byte gUnknown_968DCAC
.4byte gUnknown_968DF94
.4byte gUnknown_968DFD4
.4byte gUnknown_968E2CC
.4byte gUnknown_968E30C
.4byte gUnknown_968E5C8
.4byte gUnknown_968E608
.4byte gUnknown_968E8D8
.4byte gUnknown_968E918
.4byte gUnknown_968EBC0
.4byte gUnknown_968EC00
.4byte gUnknown_968EEF0
.4byte gUnknown_968EF30
.4byte gUnknown_968F1E0
.4byte gUnknown_968F220
.4byte gUnknown_968F4F8
.4byte gUnknown_968F538
.4byte gUnknown_968F804
.4byte gUnknown_968F844
.4byte gUnknown_968FB18
.4byte gUnknown_968FB58
.global gKaoPersian
gKaoPersian:
.string "SIRO"
.4byte gUnknown_96901BC
.incbin "baserom.gba", 0x168FEC0, 0x8
.global gUnknown_968FEC8
gUnknown_968FEC8:
.incbin "baserom.gba", 0x168FEC8, 0x40
.global gUnknown_968FF08
gUnknown_968FF08:
.incbin "baserom.gba", 0x168FF08, 0x2B4
.global gUnknown_96901BC
gUnknown_96901BC:
.4byte gUnknown_968FEC8
.4byte gUnknown_968FF08
.incbin "baserom.gba", 0x16901C4, 0x60
.global gKaoPsyduck
gKaoPsyduck:
.string "SIRO"
.4byte gUnknown_969269C
.incbin "baserom.gba", 0x169022C, 0x8
.global gUnknown_9690234
gUnknown_9690234:
.incbin "baserom.gba", 0x1690234, 0x40
.global gUnknown_9690274
gUnknown_9690274:
.string "AT4PX"
.incbin "baserom.gba", 0x1690279, 0x277
.global gUnknown_96904F0
gUnknown_96904F0:
.incbin "baserom.gba", 0x16904F0, 0x40
.global gUnknown_9690530
gUnknown_9690530:
.string "AT4PX"
.incbin "baserom.gba", 0x1690535, 0x277
.global gUnknown_96907AC
gUnknown_96907AC:
.incbin "baserom.gba", 0x16907AC, 0x40
.global gUnknown_96907EC
gUnknown_96907EC:
.incbin "baserom.gba", 0x16907EC, 0x280
.global gUnknown_9690A6C
gUnknown_9690A6C:
.incbin "baserom.gba", 0x1690A6C, 0x40
.global gUnknown_9690AAC
gUnknown_9690AAC:
.incbin "baserom.gba", 0x1690AAC, 0x284
.global gUnknown_9690D30
gUnknown_9690D30:
.incbin "baserom.gba", 0x1690D30, 0x40
.global gUnknown_9690D70
gUnknown_9690D70:
.string "AT4PX"
.incbin "baserom.gba", 0x1690D75, 0x267
.global gUnknown_9690FDC
gUnknown_9690FDC:
.incbin "baserom.gba", 0x1690FDC, 0x40
.global gUnknown_969101C
gUnknown_969101C:
.incbin "baserom.gba", 0x169101C, 0x290
.global gUnknown_96912AC
gUnknown_96912AC:
.incbin "baserom.gba", 0x16912AC, 0x40
.global gUnknown_96912EC
gUnknown_96912EC:
.incbin "baserom.gba", 0x16912EC, 0x288
.global gUnknown_9691574
gUnknown_9691574:
.incbin "baserom.gba", 0x1691574, 0x40
.global gUnknown_96915B4
gUnknown_96915B4:
.incbin "baserom.gba", 0x16915B4, 0x28C
.global gUnknown_9691840
gUnknown_9691840:
.incbin "baserom.gba", 0x1691840, 0x40
.global gUnknown_9691880
gUnknown_9691880:
.string "AT4PX"
.incbin "baserom.gba", 0x1691885, 0x287
.global gUnknown_9691B0C
gUnknown_9691B0C:
.incbin "baserom.gba", 0x1691B0C, 0x40
.global gUnknown_9691B4C
gUnknown_9691B4C:
.incbin "baserom.gba", 0x1691B4C, 0x28C
.global gUnknown_9691DD8
gUnknown_9691DD8:
.incbin "baserom.gba", 0x1691DD8, 0x40
.global gUnknown_9691E18
gUnknown_9691E18:
.incbin "baserom.gba", 0x1691E18, 0x2CC
.global gUnknown_96920E4
gUnknown_96920E4:
.incbin "baserom.gba", 0x16920E4, 0x40
.global gUnknown_9692124
gUnknown_9692124:
.incbin "baserom.gba", 0x1692124, 0x29C
.global gUnknown_96923C0
gUnknown_96923C0:
.incbin "baserom.gba", 0x16923C0, 0x40
.global gUnknown_9692400
gUnknown_9692400:
.string "AT4PX"
.incbin "baserom.gba", 0x1692405, 0x297
.global gUnknown_969269C
gUnknown_969269C:
.4byte gUnknown_9690234
.4byte gUnknown_9690274
.4byte gUnknown_96904F0
.4byte gUnknown_9690530
.4byte gUnknown_96907AC
.4byte gUnknown_96907EC
.4byte gUnknown_9690A6C
.4byte gUnknown_9690AAC
.4byte gUnknown_9690D30
.4byte gUnknown_9690D70
.4byte gUnknown_9690FDC
.4byte gUnknown_969101C
.4byte gUnknown_96912AC
.4byte gUnknown_96912EC
.4byte gUnknown_9691574
.4byte gUnknown_96915B4
.4byte gUnknown_9691840
.4byte gUnknown_9691880
.4byte gUnknown_9691B0C
.4byte gUnknown_9691B4C
.4byte gUnknown_9691DD8
.4byte gUnknown_9691E18
.4byte gUnknown_96920E4
.4byte gUnknown_9692124
.4byte gUnknown_96923C0
.4byte gUnknown_9692400
.incbin "baserom.gba", 0x1692704, 0x8
.global gKaoMankey
gKaoMankey:
.string "SIRO"
.4byte gUnknown_9692D58
.incbin "baserom.gba", 0x1692714, 0x8
.global gUnknown_969271C
gUnknown_969271C:
.incbin "baserom.gba", 0x169271C, 0x40
.global gUnknown_969275C
gUnknown_969275C:
.incbin "baserom.gba", 0x169275C, 0x2CC
.global gUnknown_9692A28
gUnknown_9692A28:
.incbin "baserom.gba", 0x1692A28, 0x40
.global gUnknown_9692A68
gUnknown_9692A68:
.string "AT4PX"
.incbin "baserom.gba", 0x1692A6D, 0x2EB
.global gUnknown_9692D58
gUnknown_9692D58:
.4byte gUnknown_969271C
.4byte gUnknown_969275C
.4byte gUnknown_9692A28
.4byte gUnknown_9692A68
.incbin "baserom.gba", 0x1692D68, 0x58
.global gKaoAlakazam
gKaoAlakazam:
.string "SIRO"
.4byte gUnknown_9693744
.incbin "baserom.gba", 0x1692DC8, 0x8
.global gUnknown_9692DD0
gUnknown_9692DD0:
.incbin "baserom.gba", 0x1692DD0, 0x40
.global gUnknown_9692E10
gUnknown_9692E10:
.string "AT4PX"
.incbin "baserom.gba", 0x1692E15, 0x2DB
.global gUnknown_96930F0
gUnknown_96930F0:
.incbin "baserom.gba", 0x16930F0, 0x40
.global gUnknown_9693130
gUnknown_9693130:
.string "AT4PX"
.incbin "baserom.gba", 0x1693135, 0x2F7
.global gUnknown_969342C
gUnknown_969342C:
.incbin "baserom.gba", 0x169342C, 0x40
.global gUnknown_969346C
gUnknown_969346C:
.incbin "baserom.gba", 0x169346C, 0x2D8
.global gUnknown_9693744
gUnknown_9693744:
.4byte gUnknown_9692DD0
.4byte gUnknown_9692E10
.4byte gUnknown_96930F0
.4byte gUnknown_9693130
.4byte gUnknown_969342C
.4byte gUnknown_969346C
.incbin "baserom.gba", 0x169375C, 0x50
.global gKaoMachop
gKaoMachop:
.string "SIRO"
.4byte gUnknown_9695D4C
.incbin "baserom.gba", 0x16937B4, 0x8
.global gUnknown_96937BC
gUnknown_96937BC:
.incbin "baserom.gba", 0x16937BC, 0x40
.global gUnknown_96937FC
gUnknown_96937FC:
.incbin "baserom.gba", 0x16937FC, 0x284
.global gUnknown_9693A80
gUnknown_9693A80:
.incbin "baserom.gba", 0x1693A80, 0x40
.global gUnknown_9693AC0
gUnknown_9693AC0:
.string "AT4PX"
.incbin "baserom.gba", 0x1693AC5, 0x25B
.global gUnknown_9693D20
gUnknown_9693D20:
.incbin "baserom.gba", 0x1693D20, 0x40
.global gUnknown_9693D60
gUnknown_9693D60:
.string "AT4PX"
.incbin "baserom.gba", 0x1693D65, 0x2B3
.global gUnknown_9694018
gUnknown_9694018:
.incbin "baserom.gba", 0x1694018, 0x40
.global gUnknown_9694058
gUnknown_9694058:
.string "AT4PX"
.incbin "baserom.gba", 0x169405D, 0x2B7
.global gUnknown_9694314
gUnknown_9694314:
.incbin "baserom.gba", 0x1694314, 0x40
.global gUnknown_9694354
gUnknown_9694354:
.incbin "baserom.gba", 0x1694354, 0x2B4
.global gUnknown_9694608
gUnknown_9694608:
.incbin "baserom.gba", 0x1694608, 0x40
.global gUnknown_9694648
gUnknown_9694648:
.incbin "baserom.gba", 0x1694648, 0x2A4
.global gUnknown_96948EC
gUnknown_96948EC:
.incbin "baserom.gba", 0x16948EC, 0x40
.global gUnknown_969492C
gUnknown_969492C:
.incbin "baserom.gba", 0x169492C, 0x2AC
.global gUnknown_9694BD8
gUnknown_9694BD8:
.incbin "baserom.gba", 0x1694BD8, 0x40
.global gUnknown_9694C18
gUnknown_9694C18:
.incbin "baserom.gba", 0x1694C18, 0x2B8
.global gUnknown_9694ED0
gUnknown_9694ED0:
.incbin "baserom.gba", 0x1694ED0, 0x40
.global gUnknown_9694F10
gUnknown_9694F10:
.string "AT4PX"
.incbin "baserom.gba", 0x1694F15, 0x283
.global gUnknown_9695198
gUnknown_9695198:
.incbin "baserom.gba", 0x1695198, 0x40
.global gUnknown_96951D8
gUnknown_96951D8:
.incbin "baserom.gba", 0x16951D8, 0x274
.global gUnknown_969544C
gUnknown_969544C:
.incbin "baserom.gba", 0x169544C, 0x40
.global gUnknown_969548C
gUnknown_969548C:
.incbin "baserom.gba", 0x169548C, 0x2D4
.global gUnknown_9695760
gUnknown_9695760:
.incbin "baserom.gba", 0x1695760, 0x40
.global gUnknown_96957A0
gUnknown_96957A0:
.string "AT4PX"
.incbin "baserom.gba", 0x16957A5, 0x28B
.global gUnknown_9695A30
gUnknown_9695A30:
.incbin "baserom.gba", 0x1695A30, 0x40
.global gUnknown_9695A70
gUnknown_9695A70:
.string "AT4PX"
.incbin "baserom.gba", 0x1695A75, 0x2D7
.global gUnknown_9695D4C
gUnknown_9695D4C:
.4byte gUnknown_96937BC
.4byte gUnknown_96937FC
.4byte gUnknown_9693A80
.4byte gUnknown_9693AC0
.4byte gUnknown_9693D20
.4byte gUnknown_9693D60
.4byte gUnknown_9694018
.4byte gUnknown_9694058
.4byte gUnknown_9694314
.4byte gUnknown_9694354
.4byte gUnknown_9694608
.4byte gUnknown_9694648
.4byte gUnknown_96948EC
.4byte gUnknown_969492C
.4byte gUnknown_9694BD8
.4byte gUnknown_9694C18
.4byte gUnknown_9694ED0
.4byte gUnknown_9694F10
.4byte gUnknown_9695198
.4byte gUnknown_96951D8
.4byte gUnknown_969544C
.4byte gUnknown_969548C
.4byte gUnknown_9695760
.4byte gUnknown_96957A0
.4byte gUnknown_9695A30
.4byte gUnknown_9695A70
.global gKaoBellsprout
gKaoBellsprout:
.string "SIRO"
.4byte gUnknown_96962FC
.incbin "baserom.gba", 0x1695DBC, 0x8
.global gUnknown_9695DC4
gUnknown_9695DC4:
.incbin "baserom.gba", 0x1695DC4, 0x40
.global gUnknown_9695E04
gUnknown_9695E04:
.string "AT4PX"
.incbin "baserom.gba", 0x1695E09, 0x26B
.global gUnknown_9696074
gUnknown_9696074:
.incbin "baserom.gba", 0x1696074, 0x40
.global gUnknown_96960B4
gUnknown_96960B4:
.string "AT4PX"
.incbin "baserom.gba", 0x16960B9, 0x243
.global gUnknown_96962FC
gUnknown_96962FC:
.4byte gUnknown_9695DC4
.4byte gUnknown_9695E04
.4byte gUnknown_9696074
.4byte gUnknown_96960B4
.incbin "baserom.gba", 0x169630C, 0x58
.global gKaoGolem
gKaoGolem:
.string "SIRO"
.4byte gUnknown_9696664
.incbin "baserom.gba", 0x169636C, 0x8
.global gUnknown_9696374
gUnknown_9696374:
.incbin "baserom.gba", 0x1696374, 0x40
.global gUnknown_96963B4
gUnknown_96963B4:
.string "AT4PX"
.incbin "baserom.gba", 0x16963B9, 0x2AB
.global gUnknown_9696664
gUnknown_9696664:
.4byte gUnknown_9696374
.4byte gUnknown_96963B4
.incbin "baserom.gba", 0x169666C, 0x60
.global gKaoMagnemite
gKaoMagnemite:
.string "SIRO"
.4byte gUnknown_9696CD0
.incbin "baserom.gba", 0x16966D4, 0x8
.global gUnknown_96966DC
gUnknown_96966DC:
.incbin "baserom.gba", 0x16966DC, 0x40
.global gUnknown_969671C
gUnknown_969671C:
.incbin "baserom.gba", 0x169671C, 0x2B8
.global gUnknown_96969D4
gUnknown_96969D4:
.incbin "baserom.gba", 0x16969D4, 0x40
.global gUnknown_9696A14
gUnknown_9696A14:
.string "AT4PX"
.incbin "baserom.gba", 0x1696A19, 0x2B7
.global gUnknown_9696CD0
gUnknown_9696CD0:
.4byte gUnknown_96966DC
.4byte gUnknown_969671C
.4byte gUnknown_96969D4
.4byte gUnknown_9696A14
.incbin "baserom.gba", 0x1696CE0, 0x58
.global gKaoGengar
gKaoGengar:
.string "SIRO"
.4byte gUnknown_96981FC
.incbin "baserom.gba", 0x1696D40, 0x8
.global gUnknown_9696D48
gUnknown_9696D48:
.incbin "baserom.gba", 0x1696D48, 0x40
.global gUnknown_9696D88
gUnknown_9696D88:
.string "AT4PX"
.incbin "baserom.gba", 0x1696D8D, 0x2C3
.global gUnknown_9697050
gUnknown_9697050:
.incbin "baserom.gba", 0x1697050, 0x40
.global gUnknown_9697090
gUnknown_9697090:
.string "AT4PX"
.incbin "baserom.gba", 0x1697095, 0x2A3
.global gUnknown_9697338
gUnknown_9697338:
.incbin "baserom.gba", 0x1697338, 0x40
.global gUnknown_9697378
gUnknown_9697378:
.string "AT4PX"
.incbin "baserom.gba", 0x169737D, 0x2BF
.global gUnknown_969763C
gUnknown_969763C:
.incbin "baserom.gba", 0x169763C, 0x40
.global gUnknown_969767C
gUnknown_969767C:
.incbin "baserom.gba", 0x169767C, 0x29C
.global gUnknown_9697918
gUnknown_9697918:
.incbin "baserom.gba", 0x1697918, 0x40
.global gUnknown_9697958
gUnknown_9697958:
.incbin "baserom.gba", 0x1697958, 0x2A4
.global gUnknown_9697BFC
gUnknown_9697BFC:
.incbin "baserom.gba", 0x1697BFC, 0x40
.global gUnknown_9697C3C
gUnknown_9697C3C:
.incbin "baserom.gba", 0x1697C3C, 0x2B4
.global gUnknown_9697EF0
gUnknown_9697EF0:
.incbin "baserom.gba", 0x1697EF0, 0x40
.global gUnknown_9697F30
gUnknown_9697F30:
.string "AT4PX"
.incbin "baserom.gba", 0x1697F35, 0x2C7
.global gUnknown_96981FC
gUnknown_96981FC:
.4byte gUnknown_9696D48
.4byte gUnknown_9696D88
.4byte gUnknown_9697050
.4byte gUnknown_9697090
.4byte gUnknown_9697338
.4byte gUnknown_9697378
.4byte gUnknown_969763C
.4byte gUnknown_969767C
.4byte gUnknown_9697918
.4byte gUnknown_9697958
.4byte gUnknown_9697BFC
.4byte gUnknown_9697C3C
.4byte gUnknown_9697EF0
.4byte gUnknown_9697F30
.incbin "baserom.gba", 0x1698234, 0x30
.global gKaoCubone
gKaoCubone:
.string "SIRO"
.4byte gUnknown_969AA48
.incbin "baserom.gba", 0x169826C, 0x8
.global gUnknown_9698274
gUnknown_9698274:
.incbin "baserom.gba", 0x1698274, 0x40
.global gUnknown_96982B4
gUnknown_96982B4:
.string "AT4PX"
.incbin "baserom.gba", 0x16982B9, 0x2DB
.global gUnknown_9698594
gUnknown_9698594:
.incbin "baserom.gba", 0x1698594, 0x40
.global gUnknown_96985D4
gUnknown_96985D4:
.string "AT4PX"
.incbin "baserom.gba", 0x16985D9, 0x2CF
.global gUnknown_96988A8
gUnknown_96988A8:
.incbin "baserom.gba", 0x16988A8, 0x40
.global gUnknown_96988E8
gUnknown_96988E8:
.string "AT4PX"
.incbin "baserom.gba", 0x16988ED, 0x2B7
.global gUnknown_9698BA4
gUnknown_9698BA4:
.incbin "baserom.gba", 0x1698BA4, 0x40
.global gUnknown_9698BE4
gUnknown_9698BE4:
.string "AT4PX"
.incbin "baserom.gba", 0x1698BE9, 0x2D7
.global gUnknown_9698EC0
gUnknown_9698EC0:
.incbin "baserom.gba", 0x1698EC0, 0x40
.global gUnknown_9698F00
gUnknown_9698F00:
.incbin "baserom.gba", 0x1698F00, 0x2AC
.global gUnknown_96991AC
gUnknown_96991AC:
.incbin "baserom.gba", 0x16991AC, 0x40
.global gUnknown_96991EC
gUnknown_96991EC:
.incbin "baserom.gba", 0x16991EC, 0x2C4
.global gUnknown_96994B0
gUnknown_96994B0:
.incbin "baserom.gba", 0x16994B0, 0x40
.global gUnknown_96994F0
gUnknown_96994F0:
.string "AT4PX"
.incbin "baserom.gba", 0x16994F5, 0x2B7
.global gUnknown_96997AC
gUnknown_96997AC:
.incbin "baserom.gba", 0x16997AC, 0x40
.global gUnknown_96997EC
gUnknown_96997EC:
.incbin "baserom.gba", 0x16997EC, 0x2F4
.global gUnknown_9699AE0
gUnknown_9699AE0:
.incbin "baserom.gba", 0x1699AE0, 0x40
.global gUnknown_9699B20
gUnknown_9699B20:
.string "AT4PX"
.incbin "baserom.gba", 0x1699B25, 0x2E3
.global gUnknown_9699E08
gUnknown_9699E08:
.incbin "baserom.gba", 0x1699E08, 0x40
.global gUnknown_9699E48
gUnknown_9699E48:
.incbin "baserom.gba", 0x1699E48, 0x2B0
.global gUnknown_969A0F8
gUnknown_969A0F8:
.incbin "baserom.gba", 0x169A0F8, 0x40
.global gUnknown_969A138
gUnknown_969A138:
.incbin "baserom.gba", 0x169A138, 0x2C8
.global gUnknown_969A400
gUnknown_969A400:
.incbin "baserom.gba", 0x169A400, 0x40
.global gUnknown_969A440
gUnknown_969A440:
.string "AT4PX"
.incbin "baserom.gba", 0x169A445, 0x2DB
.global gUnknown_969A720
gUnknown_969A720:
.incbin "baserom.gba", 0x169A720, 0x40
.global gUnknown_969A760
gUnknown_969A760:
.string "AT4PX"
.incbin "baserom.gba", 0x169A765, 0x2E3
.global gUnknown_969AA48
gUnknown_969AA48:
.4byte gUnknown_9698274
.4byte gUnknown_96982B4
.4byte gUnknown_9698594
.4byte gUnknown_96985D4
.4byte gUnknown_96988A8
.4byte gUnknown_96988E8
.4byte gUnknown_9698BA4
.4byte gUnknown_9698BE4
.4byte gUnknown_9698EC0
.4byte gUnknown_9698F00
.4byte gUnknown_96991AC
.4byte gUnknown_96991EC
.4byte gUnknown_96994B0
.4byte gUnknown_96994F0
.4byte gUnknown_96997AC
.4byte gUnknown_96997EC
.4byte gUnknown_9699AE0
.4byte gUnknown_9699B20
.4byte gUnknown_9699E08
.4byte gUnknown_9699E48
.4byte gUnknown_969A0F8
.4byte gUnknown_969A138
.4byte gUnknown_969A400
.4byte gUnknown_969A440
.4byte gUnknown_969A720
.4byte gUnknown_969A760
.global gKaoKangaskhan
gKaoKangaskhan:
.string "SIRO"
.4byte gUnknown_969B09C
.incbin "baserom.gba", 0x169AAB8, 0x8
.global gUnknown_969AAC0
gUnknown_969AAC0:
.incbin "baserom.gba", 0x169AAC0, 0x40
.global gUnknown_969AB00
gUnknown_969AB00:
.string "AT4PX"
.incbin "baserom.gba", 0x169AB05, 0x2AF
.global gUnknown_969ADB4
gUnknown_969ADB4:
.incbin "baserom.gba", 0x169ADB4, 0x40
.global gUnknown_969ADF4
gUnknown_969ADF4:
.string "AT4PX"
.incbin "baserom.gba", 0x169ADF9, 0x2A3
.global gUnknown_969B09C
gUnknown_969B09C:
.4byte gUnknown_969AAC0
.4byte gUnknown_969AB00
.4byte gUnknown_969ADB4
.4byte gUnknown_969ADF4
.incbin "baserom.gba", 0x169B0AC, 0x58
.global gKaoEevee
gKaoEevee:
.string "SIRO"
.4byte gUnknown_969D6C8
.incbin "baserom.gba", 0x169B10C, 0x8
.global gUnknown_969B114
gUnknown_969B114:
.incbin "baserom.gba", 0x169B114, 0x40
.global gUnknown_969B154
gUnknown_969B154:
.string "AT4PX"
.incbin "baserom.gba", 0x169B159, 0x2B7
.global gUnknown_969B410
gUnknown_969B410:
.incbin "baserom.gba", 0x169B410, 0x40
.global gUnknown_969B450
gUnknown_969B450:
.string "AT4PX"
.incbin "baserom.gba", 0x169B455, 0x29F
.global gUnknown_969B6F4
gUnknown_969B6F4:
.incbin "baserom.gba", 0x169B6F4, 0x40
.global gUnknown_969B734
gUnknown_969B734:
.string "AT4PX"
.incbin "baserom.gba", 0x169B739, 0x267
.global gUnknown_969B9A0
gUnknown_969B9A0:
.incbin "baserom.gba", 0x169B9A0, 0x40
.global gUnknown_969B9E0
gUnknown_969B9E0:
.string "AT4PX"
.incbin "baserom.gba", 0x169B9E5, 0x2BB
.global gUnknown_969BCA0
gUnknown_969BCA0:
.incbin "baserom.gba", 0x169BCA0, 0x40
.global gUnknown_969BCE0
gUnknown_969BCE0:
.string "AT4PX"
.incbin "baserom.gba", 0x169BCE5, 0x28F
.global gUnknown_969BF74
gUnknown_969BF74:
.incbin "baserom.gba", 0x169BF74, 0x40
.global gUnknown_969BFB4
gUnknown_969BFB4:
.incbin "baserom.gba", 0x169BFB4, 0x288
.global gUnknown_969C23C
gUnknown_969C23C:
.incbin "baserom.gba", 0x169C23C, 0x40
.global gUnknown_969C27C
gUnknown_969C27C:
.incbin "baserom.gba", 0x169C27C, 0x278
.global gUnknown_969C4F4
gUnknown_969C4F4:
.incbin "baserom.gba", 0x169C4F4, 0x40
.global gUnknown_969C534
gUnknown_969C534:
.incbin "baserom.gba", 0x169C534, 0x2A0
.global gUnknown_969C7D4
gUnknown_969C7D4:
.incbin "baserom.gba", 0x169C7D4, 0x40
.global gUnknown_969C814
gUnknown_969C814:
.incbin "baserom.gba", 0x169C814, 0x2B4
.global gUnknown_969CAC8
gUnknown_969CAC8:
.incbin "baserom.gba", 0x169CAC8, 0x40
.global gUnknown_969CB08
gUnknown_969CB08:
.incbin "baserom.gba", 0x169CB08, 0x2A4
.global gUnknown_969CDAC
gUnknown_969CDAC:
.incbin "baserom.gba", 0x169CDAC, 0x40
.global gUnknown_969CDEC
gUnknown_969CDEC:
.incbin "baserom.gba", 0x169CDEC, 0x2D4
.global gUnknown_969D0C0
gUnknown_969D0C0:
.incbin "baserom.gba", 0x169D0C0, 0x40
.global gUnknown_969D100
gUnknown_969D100:
.string "AT4PX"
.incbin "baserom.gba", 0x169D105, 0x2BF
.global gUnknown_969D3C4
gUnknown_969D3C4:
.incbin "baserom.gba", 0x169D3C4, 0x40
.global gUnknown_969D404
gUnknown_969D404:
.incbin "baserom.gba", 0x169D404, 0x2C4
.global gUnknown_969D6C8
gUnknown_969D6C8:
.4byte gUnknown_969B114
.4byte gUnknown_969B154
.4byte gUnknown_969B410
.4byte gUnknown_969B450
.4byte gUnknown_969B6F4
.4byte gUnknown_969B734
.4byte gUnknown_969B9A0
.4byte gUnknown_969B9E0
.4byte gUnknown_969BCA0
.4byte gUnknown_969BCE0
.4byte gUnknown_969BF74
.4byte gUnknown_969BFB4
.4byte gUnknown_969C23C
.4byte gUnknown_969C27C
.4byte gUnknown_969C4F4
.4byte gUnknown_969C534
.4byte gUnknown_969C7D4
.4byte gUnknown_969C814
.4byte gUnknown_969CAC8
.4byte gUnknown_969CB08
.4byte gUnknown_969CDAC
.4byte gUnknown_969CDEC
.4byte gUnknown_969D0C0
.4byte gUnknown_969D100
.4byte gUnknown_969D3C4
.4byte gUnknown_969D404
.string "pksdir0\0"
.global gKaoArticuno
gKaoArticuno:
.string "SIRO"
.4byte gUnknown_969DA48
.incbin "baserom.gba", 0x169D740, 0x8
.global gUnknown_969D748
gUnknown_969D748:
.incbin "baserom.gba", 0x169D748, 0x40
.global gUnknown_969D788
gUnknown_969D788:
.string "AT4PX"
.incbin "baserom.gba", 0x169D78D, 0x2BB
.global gUnknown_969DA48
gUnknown_969DA48:
.4byte gUnknown_969D748
.4byte gUnknown_969D788
.incbin "baserom.gba", 0x169DA50, 0x60
.global gKaoZapdos
gKaoZapdos:
.string "SIRO"
.4byte gUnknown_969DD9C
.incbin "baserom.gba", 0x169DAB8, 0x8
.global gUnknown_969DAC0
gUnknown_969DAC0:
.incbin "baserom.gba", 0x169DAC0, 0x40
.global gUnknown_969DB00
gUnknown_969DB00:
.string "AT4PX"
.incbin "baserom.gba", 0x169DB05, 0x297
.global gUnknown_969DD9C
gUnknown_969DD9C:
.4byte gUnknown_969DAC0
.4byte gUnknown_969DB00
.incbin "baserom.gba", 0x169DDA4, 0x60
.global gKaoMoltres
gKaoMoltres:
.string "SIRO"
.4byte gUnknown_969E150
.incbin "baserom.gba", 0x169DE0C, 0x8
.global gUnknown_969DE14
gUnknown_969DE14:
.incbin "baserom.gba", 0x169DE14, 0x40
.global gUnknown_969DE54
gUnknown_969DE54:
.string "AT4PX"
.incbin "baserom.gba", 0x169DE59, 0x2F7
.global gUnknown_969E150
gUnknown_969E150:
.4byte gUnknown_969DE14
.4byte gUnknown_969DE54
.incbin "baserom.gba", 0x169E158, 0x60
.global gKaoMewtwo
gKaoMewtwo:
.string "SIRO"
.4byte gUnknown_969E4BC
.incbin "baserom.gba", 0x169E1C0, 0x8
.global gUnknown_969E1C8
gUnknown_969E1C8:
.incbin "baserom.gba", 0x169E1C8, 0x40
.global gUnknown_969E208
gUnknown_969E208:
.string "AT4PX"
.incbin "baserom.gba", 0x169E20D, 0x2AF
.global gUnknown_969E4BC
gUnknown_969E4BC:
.4byte gUnknown_969E1C8
.4byte gUnknown_969E208
.incbin "baserom.gba", 0x169E4C4, 0x60
.global gKaoChikorita
gKaoChikorita:
.string "SIRO"
.4byte gUnknown_96A0A30
.incbin "baserom.gba", 0x169E52C, 0x8
.global gUnknown_969E534
gUnknown_969E534:
.incbin "baserom.gba", 0x169E534, 0x40
.global gUnknown_969E574
gUnknown_969E574:
.string "AT4PX"
.incbin "baserom.gba", 0x169E579, 0x29F
.global gUnknown_969E818
gUnknown_969E818:
.incbin "baserom.gba", 0x169E818, 0x40
.global gUnknown_969E858
gUnknown_969E858:
.string "AT4PX"
.incbin "baserom.gba", 0x169E85D, 0x27F
.global gUnknown_969EADC
gUnknown_969EADC:
.incbin "baserom.gba", 0x169EADC, 0x40
.global gUnknown_969EB1C
gUnknown_969EB1C:
.incbin "baserom.gba", 0x169EB1C, 0x290
.global gUnknown_969EDAC
gUnknown_969EDAC:
.incbin "baserom.gba", 0x169EDAC, 0x40
.global gUnknown_969EDEC
gUnknown_969EDEC:
.incbin "baserom.gba", 0x169EDEC, 0x27C
.global gUnknown_969F068
gUnknown_969F068:
.incbin "baserom.gba", 0x169F068, 0x40
.global gUnknown_969F0A8
gUnknown_969F0A8:
.incbin "baserom.gba", 0x169F0A8, 0x294
.global gUnknown_969F33C
gUnknown_969F33C:
.incbin "baserom.gba", 0x169F33C, 0x40
.global gUnknown_969F37C
gUnknown_969F37C:
.incbin "baserom.gba", 0x169F37C, 0x2A0
.global gUnknown_969F61C
gUnknown_969F61C:
.incbin "baserom.gba", 0x169F61C, 0x40
.global gUnknown_969F65C
gUnknown_969F65C:
.incbin "baserom.gba", 0x169F65C, 0x2A8
.global gUnknown_969F904
gUnknown_969F904:
.incbin "baserom.gba", 0x169F904, 0x40
.global gUnknown_969F944
gUnknown_969F944:
.incbin "baserom.gba", 0x169F944, 0x290
.global gUnknown_969FBD4
gUnknown_969FBD4:
.incbin "baserom.gba", 0x169FBD4, 0x40
.global gUnknown_969FC14
gUnknown_969FC14:
.incbin "baserom.gba", 0x169FC14, 0x2A4
.global gUnknown_969FEB8
gUnknown_969FEB8:
.incbin "baserom.gba", 0x169FEB8, 0x40
.global gUnknown_969FEF8
gUnknown_969FEF8:
.incbin "baserom.gba", 0x169FEF8, 0x270
.global gUnknown_96A0168
gUnknown_96A0168:
.incbin "baserom.gba", 0x16A0168, 0x40
.global gUnknown_96A01A8
gUnknown_96A01A8:
.incbin "baserom.gba", 0x16A01A8, 0x2C0
.global gUnknown_96A0468
gUnknown_96A0468:
.incbin "baserom.gba", 0x16A0468, 0x40
.global gUnknown_96A04A8
gUnknown_96A04A8:
.incbin "baserom.gba", 0x16A04A8, 0x29C
.global gUnknown_96A0744
gUnknown_96A0744:
.incbin "baserom.gba", 0x16A0744, 0x40
.global gUnknown_96A0784
gUnknown_96A0784:
.incbin "baserom.gba", 0x16A0784, 0x2AC
.global gUnknown_96A0A30
gUnknown_96A0A30:
.4byte gUnknown_969E534
.4byte gUnknown_969E574
.4byte gUnknown_969E818
.4byte gUnknown_969E858
.4byte gUnknown_969EADC
.4byte gUnknown_969EB1C
.4byte gUnknown_969EDAC
.4byte gUnknown_969EDEC
.4byte gUnknown_969F068
.4byte gUnknown_969F0A8
.4byte gUnknown_969F33C
.4byte gUnknown_969F37C
.4byte gUnknown_969F61C
.4byte gUnknown_969F65C
.4byte gUnknown_969F904
.4byte gUnknown_969F944
.4byte gUnknown_969FBD4
.4byte gUnknown_969FC14
.4byte gUnknown_969FEB8
.4byte gUnknown_969FEF8
.4byte gUnknown_96A0168
.4byte gUnknown_96A01A8
.4byte gUnknown_96A0468
.4byte gUnknown_96A04A8
.4byte gUnknown_96A0744
.4byte gUnknown_96A0784
.global gKaoCyndaquil
gKaoCyndaquil:
.string "SIRO"
.4byte gUnknown_96A2EF4
.incbin "baserom.gba", 0x16A0AA0, 0x8
.global gUnknown_96A0AA8
gUnknown_96A0AA8:
.incbin "baserom.gba", 0x16A0AA8, 0x40
.global gUnknown_96A0AE8
gUnknown_96A0AE8:
.string "AT4PX"
.incbin "baserom.gba", 0x16A0AED, 0x26B
.global gUnknown_96A0D58
gUnknown_96A0D58:
.incbin "baserom.gba", 0x16A0D58, 0x40
.global gUnknown_96A0D98
gUnknown_96A0D98:
.string "AT4PX"
.incbin "baserom.gba", 0x16A0D9D, 0x257
.global gUnknown_96A0FF4
gUnknown_96A0FF4:
.incbin "baserom.gba", 0x16A0FF4, 0x40
.global gUnknown_96A1034
gUnknown_96A1034:
.string "AT4PX"
.incbin "baserom.gba", 0x16A1039, 0x2A3
.global gUnknown_96A12DC
gUnknown_96A12DC:
.incbin "baserom.gba", 0x16A12DC, 0x40
.global gUnknown_96A131C
gUnknown_96A131C:
.incbin "baserom.gba", 0x16A131C, 0x2D8
.global gUnknown_96A15F4
gUnknown_96A15F4:
.incbin "baserom.gba", 0x16A15F4, 0x40
.global gUnknown_96A1634
gUnknown_96A1634:
.incbin "baserom.gba", 0x16A1634, 0x258
.global gUnknown_96A188C
gUnknown_96A188C:
.incbin "baserom.gba", 0x16A188C, 0x40
.global gUnknown_96A18CC
gUnknown_96A18CC:
.incbin "baserom.gba", 0x16A18CC, 0x288
.global gUnknown_96A1B54
gUnknown_96A1B54:
.incbin "baserom.gba", 0x16A1B54, 0x40
.global gUnknown_96A1B94
gUnknown_96A1B94:
.incbin "baserom.gba", 0x16A1B94, 0x270
.global gUnknown_96A1E04
gUnknown_96A1E04:
.incbin "baserom.gba", 0x16A1E04, 0x40
.global gUnknown_96A1E44
gUnknown_96A1E44:
.incbin "baserom.gba", 0x16A1E44, 0x2C4
.global gUnknown_96A2108
gUnknown_96A2108:
.incbin "baserom.gba", 0x16A2108, 0x40
.global gUnknown_96A2148
gUnknown_96A2148:
.incbin "baserom.gba", 0x16A2148, 0x28C
.global gUnknown_96A23D4
gUnknown_96A23D4:
.incbin "baserom.gba", 0x16A23D4, 0x40
.global gUnknown_96A2414
gUnknown_96A2414:
.incbin "baserom.gba", 0x16A2414, 0x270
.global gUnknown_96A2684
gUnknown_96A2684:
.incbin "baserom.gba", 0x16A2684, 0x40
.global gUnknown_96A26C4
gUnknown_96A26C4:
.incbin "baserom.gba", 0x16A26C4, 0x2A4
.global gUnknown_96A2968
gUnknown_96A2968:
.incbin "baserom.gba", 0x16A2968, 0x40
.global gUnknown_96A29A8
gUnknown_96A29A8:
.incbin "baserom.gba", 0x16A29A8, 0x29C
.global gUnknown_96A2C44
gUnknown_96A2C44:
.incbin "baserom.gba", 0x16A2C44, 0x40
.global gUnknown_96A2C84
gUnknown_96A2C84:
.incbin "baserom.gba", 0x16A2C84, 0x270
.global gUnknown_96A2EF4
gUnknown_96A2EF4:
.4byte gUnknown_96A0AA8
.4byte gUnknown_96A0AE8
.4byte gUnknown_96A0D58
.4byte gUnknown_96A0D98
.4byte gUnknown_96A0FF4
.4byte gUnknown_96A1034
.4byte gUnknown_96A12DC
.4byte gUnknown_96A131C
.4byte gUnknown_96A15F4
.4byte gUnknown_96A1634
.4byte gUnknown_96A188C
.4byte gUnknown_96A18CC
.4byte gUnknown_96A1B54
.4byte gUnknown_96A1B94
.4byte gUnknown_96A1E04
.4byte gUnknown_96A1E44
.4byte gUnknown_96A2108
.4byte gUnknown_96A2148
.4byte gUnknown_96A23D4
.4byte gUnknown_96A2414
.4byte gUnknown_96A2684
.4byte gUnknown_96A26C4
.4byte gUnknown_96A2968
.4byte gUnknown_96A29A8
.4byte gUnknown_96A2C44
.4byte gUnknown_96A2C84
.global gKaoTotodile
gKaoTotodile:
.string "SIRO"
.4byte gUnknown_96A55EC
.incbin "baserom.gba", 0x16A2F64, 0x8
.global gUnknown_96A2F6C
gUnknown_96A2F6C:
.incbin "baserom.gba", 0x16A2F6C, 0x40
.global gUnknown_96A2FAC
gUnknown_96A2FAC:
.incbin "baserom.gba", 0x16A2FAC, 0x2A0
.global gUnknown_96A324C
gUnknown_96A324C:
.incbin "baserom.gba", 0x16A324C, 0x40
.global gUnknown_96A328C
gUnknown_96A328C:
.incbin "baserom.gba", 0x16A328C, 0x29C
.global gUnknown_96A3528
gUnknown_96A3528:
.incbin "baserom.gba", 0x16A3528, 0x40
.global gUnknown_96A3568
gUnknown_96A3568:
.string "AT4PX"
.incbin "baserom.gba", 0x16A356D, 0x2A7
.global gUnknown_96A3814
gUnknown_96A3814:
.incbin "baserom.gba", 0x16A3814, 0x40
.global gUnknown_96A3854
gUnknown_96A3854:
.string "AT4PX"
.incbin "baserom.gba", 0x16A3859, 0x2A7
.global gUnknown_96A3B00
gUnknown_96A3B00:
.incbin "baserom.gba", 0x16A3B00, 0x40
.global gUnknown_96A3B40
gUnknown_96A3B40:
.string "AT4PX"
.incbin "baserom.gba", 0x16A3B45, 0x293
.global gUnknown_96A3DD8
gUnknown_96A3DD8:
.incbin "baserom.gba", 0x16A3DD8, 0x40
.global gUnknown_96A3E18
gUnknown_96A3E18:
.incbin "baserom.gba", 0x16A3E18, 0x2AC
.global gUnknown_96A40C4
gUnknown_96A40C4:
.incbin "baserom.gba", 0x16A40C4, 0x40
.global gUnknown_96A4104
gUnknown_96A4104:
.incbin "baserom.gba", 0x16A4104, 0x2DC
.global gUnknown_96A43E0
gUnknown_96A43E0:
.incbin "baserom.gba", 0x16A43E0, 0x40
.global gUnknown_96A4420
gUnknown_96A4420:
.string "AT4PX"
.incbin "baserom.gba", 0x16A4425, 0x2D3
.global gUnknown_96A46F8
gUnknown_96A46F8:
.incbin "baserom.gba", 0x16A46F8, 0x40
.global gUnknown_96A4738
gUnknown_96A4738:
.incbin "baserom.gba", 0x16A4738, 0x2A8
.global gUnknown_96A49E0
gUnknown_96A49E0:
.incbin "baserom.gba", 0x16A49E0, 0x40
.global gUnknown_96A4A20
gUnknown_96A4A20:
.string "AT4PX"
.incbin "baserom.gba", 0x16A4A25, 0x2A3
.global gUnknown_96A4CC8
gUnknown_96A4CC8:
.incbin "baserom.gba", 0x16A4CC8, 0x40
.global gUnknown_96A4D08
gUnknown_96A4D08:
.incbin "baserom.gba", 0x16A4D08, 0x2F0
.global gUnknown_96A4FF8
gUnknown_96A4FF8:
.incbin "baserom.gba", 0x16A4FF8, 0x40
.global gUnknown_96A5038
gUnknown_96A5038:
.incbin "baserom.gba", 0x16A5038, 0x29C
.global gUnknown_96A52D4
gUnknown_96A52D4:
.incbin "baserom.gba", 0x16A52D4, 0x40
.global gUnknown_96A5314
gUnknown_96A5314:
.incbin "baserom.gba", 0x16A5314, 0x2D8
.global gUnknown_96A55EC
gUnknown_96A55EC:
.4byte gUnknown_96A2F6C
.4byte gUnknown_96A2FAC
.4byte gUnknown_96A324C
.4byte gUnknown_96A328C
.4byte gUnknown_96A3528
.4byte gUnknown_96A3568
.4byte gUnknown_96A3814
.4byte gUnknown_96A3854
.4byte gUnknown_96A3B00
.4byte gUnknown_96A3B40
.4byte gUnknown_96A3DD8
.4byte gUnknown_96A3E18
.4byte gUnknown_96A40C4
.4byte gUnknown_96A4104
.4byte gUnknown_96A43E0
.4byte gUnknown_96A4420
.4byte gUnknown_96A46F8
.4byte gUnknown_96A4738
.4byte gUnknown_96A49E0
.4byte gUnknown_96A4A20
.4byte gUnknown_96A4CC8
.4byte gUnknown_96A4D08
.4byte gUnknown_96A4FF8
.4byte gUnknown_96A5038
.4byte gUnknown_96A52D4
.4byte gUnknown_96A5314
.global gKaoXatu
gKaoXatu:
.string "SIRO"
.4byte gUnknown_96A5920
.incbin "baserom.gba", 0x16A565C, 0x8
.global gUnknown_96A5664
gUnknown_96A5664:
.incbin "baserom.gba", 0x16A5664, 0x40
.global gUnknown_96A56A4
gUnknown_96A56A4:
.string "AT4PX"
.incbin "baserom.gba", 0x16A56A9, 0x277
.global gUnknown_96A5920
gUnknown_96A5920:
.4byte gUnknown_96A5664
.4byte gUnknown_96A56A4
.incbin "baserom.gba", 0x16A5928, 0x60
.global gKaoJumpluff
gKaoJumpluff:
.string "SIRO"
.4byte gUnknown_96A5F28
.incbin "baserom.gba", 0x16A5990, 0x8
.global gUnknown_96A5998
gUnknown_96A5998:
.incbin "baserom.gba", 0x16A5998, 0x40
.global gUnknown_96A59D8
gUnknown_96A59D8:
.string "AT4PX"
.incbin "baserom.gba", 0x16A59DD, 0x283
.global gUnknown_96A5C60
gUnknown_96A5C60:
.incbin "baserom.gba", 0x16A5C60, 0x40
.global gUnknown_96A5CA0
gUnknown_96A5CA0:
.string "AT4PX"
.incbin "baserom.gba", 0x16A5CA5, 0x283
.global gUnknown_96A5F28
gUnknown_96A5F28:
.4byte gUnknown_96A5998
.4byte gUnknown_96A59D8
.4byte gUnknown_96A5C60
.4byte gUnknown_96A5CA0
.incbin "baserom.gba", 0x16A5F38, 0x58
.global gKaoWobbuffet
gKaoWobbuffet:
.string "SIRO"
.4byte gUnknown_96A64F0
.incbin "baserom.gba", 0x16A5F98, 0x8
.global gUnknown_96A5FA0
gUnknown_96A5FA0:
.incbin "baserom.gba", 0x16A5FA0, 0x40
.global gUnknown_96A5FE0
gUnknown_96A5FE0:
.string "AT4PX"
.incbin "baserom.gba", 0x16A5FE5, 0x223
.global gUnknown_96A6208
gUnknown_96A6208:
.incbin "baserom.gba", 0x16A6208, 0x40
.global gUnknown_96A6248
gUnknown_96A6248:
.string "AT4PX"
.incbin "baserom.gba", 0x16A624D, 0x2A3
.global gUnknown_96A64F0
gUnknown_96A64F0:
.4byte gUnknown_96A5FA0
.4byte gUnknown_96A5FE0
.4byte gUnknown_96A6208
.4byte gUnknown_96A6248
.incbin "baserom.gba", 0x16A6500, 0x60
.global gKaoSnubbull
gKaoSnubbull:
.string "SIRO"
.4byte gUnknown_96A6EA0
.incbin "baserom.gba", 0x16A6568, 0x8
.global gUnknown_96A6570
gUnknown_96A6570:
.incbin "baserom.gba", 0x16A6570, 0x40
.global gUnknown_96A65B0
gUnknown_96A65B0:
.string "AT4PX"
.incbin "baserom.gba", 0x16A65B5, 0x2B7
.global gUnknown_96A686C
gUnknown_96A686C:
.incbin "baserom.gba", 0x16A686C, 0x40
.global gUnknown_96A68AC
gUnknown_96A68AC:
.incbin "baserom.gba", 0x16A68AC, 0x2F8
.global gUnknown_96A6BA4
gUnknown_96A6BA4:
.incbin "baserom.gba", 0x16A6BA4, 0x40
.global gUnknown_96A6BE4
gUnknown_96A6BE4:
.string "AT4PX"
.incbin "baserom.gba", 0x16A6BE9, 0x2B7
.global gUnknown_96A6EA0
gUnknown_96A6EA0:
.4byte gUnknown_96A6570
.4byte gUnknown_96A65B0
.4byte gUnknown_96A686C
.4byte gUnknown_96A68AC
.4byte gUnknown_96A6BA4
.4byte gUnknown_96A6BE4
.incbin "baserom.gba", 0x16A6EB8, 0x50
.global gKaoGranbull
gKaoGranbull:
.string "SIRO"
.4byte gUnknown_96A7254
.incbin "baserom.gba", 0x16A6F10, 0x8
.global gUnknown_96A6F18
gUnknown_96A6F18:
.incbin "baserom.gba", 0x16A6F18, 0x40
.global gUnknown_96A6F58
gUnknown_96A6F58:
.string "AT4PX"
.incbin "baserom.gba", 0x16A6F5D, 0x2F7
.global gUnknown_96A7254
gUnknown_96A7254:
.4byte gUnknown_96A6F18
.4byte gUnknown_96A6F58
.incbin "baserom.gba", 0x16A725C, 0x60
.global gKaoOctillery
gKaoOctillery:
.string "SIRO"
.4byte gUnknown_96A75D0
.incbin "baserom.gba", 0x16A72C4, 0x8
.global gUnknown_96A72CC
gUnknown_96A72CC:
.incbin "baserom.gba", 0x16A72CC, 0x40
.global gUnknown_96A730C
gUnknown_96A730C:
.incbin "baserom.gba", 0x16A730C, 0x2C4
.global gUnknown_96A75D0
gUnknown_96A75D0:
.4byte gUnknown_96A72CC
.4byte gUnknown_96A730C
.incbin "baserom.gba", 0x16A75D8, 0x60
.global gKaoSkarmory
gKaoSkarmory:
.string "SIRO"
.4byte gUnknown_96A7A64
.incbin "baserom.gba", 0x16A7640, 0x8
.global gUnknown_96A7648
gUnknown_96A7648:
.incbin "baserom.gba", 0x16A7648, 0x40
.global gUnknown_96A7688
gUnknown_96A7688:
.string "AT4PX"
.incbin "baserom.gba", 0x16A768D, 0x26B
.global gUnknown_96A78F8
gUnknown_96A78F8:
.incbin "baserom.gba", 0x16A78F8, 0x40
.global gUnknown_96A7938
gUnknown_96A7938:
.string "AT4PX"
.incbin "baserom.gba", 0x16A793D, 0x127
.global gUnknown_96A7A64
gUnknown_96A7A64:
.4byte gUnknown_96A7648
.4byte gUnknown_96A7688
.4byte gUnknown_96A78F8
.4byte gUnknown_96A7938
.incbin "baserom.gba", 0x16A7A74, 0x58
.global gKaoSmeargle
gKaoSmeargle:
.string "SIRO"
.4byte gUnknown_96A7DE4
.incbin "baserom.gba", 0x16A7AD4, 0x8
.global gUnknown_96A7ADC
gUnknown_96A7ADC:
.incbin "baserom.gba", 0x16A7ADC, 0x40
.global gUnknown_96A7B1C
gUnknown_96A7B1C:
.incbin "baserom.gba", 0x16A7B1C, 0x2C8
.global gUnknown_96A7DE4
gUnknown_96A7DE4:
.4byte gUnknown_96A7ADC
.4byte gUnknown_96A7B1C
.incbin "baserom.gba", 0x16A7DEC, 0x60
.global gKaoRaikou
gKaoRaikou:
.string "SIRO"
.4byte gUnknown_96A8178
.incbin "baserom.gba", 0x16A7E54, 0x8
.global gUnknown_96A7E5C
gUnknown_96A7E5C:
.incbin "baserom.gba", 0x16A7E5C, 0x40
.global gUnknown_96A7E9C
gUnknown_96A7E9C:
.incbin "baserom.gba", 0x16A7E9C, 0x2DC
.global gUnknown_96A8178
gUnknown_96A8178:
.4byte gUnknown_96A7E5C
.4byte gUnknown_96A7E9C
.incbin "baserom.gba", 0x16A8180, 0x60
.global gKaoEntei
gKaoEntei:
.string "SIRO"
.4byte gUnknown_96A84EC
.incbin "baserom.gba", 0x16A81E8, 0x8
.global gUnknown_96A81F0
gUnknown_96A81F0:
.incbin "baserom.gba", 0x16A81F0, 0x40
.global gUnknown_96A8230
gUnknown_96A8230:
.string "AT4PX"
.incbin "baserom.gba", 0x16A8235, 0x2B7
.global gUnknown_96A84EC
gUnknown_96A84EC:
.4byte gUnknown_96A81F0
.4byte gUnknown_96A8230
.incbin "baserom.gba", 0x16A84F4, 0x60
.global gKaoSuicune
gKaoSuicune:
.string "SIRO"
.4byte gUnknown_96A88A0
.incbin "baserom.gba", 0x16A855C, 0x8
.global gUnknown_96A8564
gUnknown_96A8564:
.incbin "baserom.gba", 0x16A8564, 0x40
.global gUnknown_96A85A4
gUnknown_96A85A4:
.string "AT4PX"
.incbin "baserom.gba", 0x16A85A9, 0x2F7
.global gUnknown_96A88A0
gUnknown_96A88A0:
.4byte gUnknown_96A8564
.4byte gUnknown_96A85A4
.incbin "baserom.gba", 0x16A88A8, 0x60
.global gKaoTyranitar
gKaoTyranitar:
.string "SIRO"
.4byte gUnknown_96A8ECC
.incbin "baserom.gba", 0x16A8910, 0x8
.global gUnknown_96A8918
gUnknown_96A8918:
.incbin "baserom.gba", 0x16A8918, 0x40
.global gUnknown_96A8958
gUnknown_96A8958:
.string "AT4PX"
.incbin "baserom.gba", 0x16A895D, 0x263
.global gUnknown_96A8BC0
gUnknown_96A8BC0:
.incbin "baserom.gba", 0x16A8BC0, 0x40
.global gUnknown_96A8C00
gUnknown_96A8C00:
.string "AT4PX"
.incbin "baserom.gba", 0x16A8C05, 0x2C7
.global gUnknown_96A8ECC
gUnknown_96A8ECC:
.4byte gUnknown_96A8918
.4byte gUnknown_96A8958
.4byte gUnknown_96A8BC0
.4byte gUnknown_96A8C00
.incbin "baserom.gba", 0x16A8EDC, 0x58
.global gKaoLugia
gKaoLugia:
.string "SIRO"
.4byte gUnknown_96A9204
.incbin "baserom.gba", 0x16A8F3C, 0x8
.global gUnknown_96A8F44
gUnknown_96A8F44:
.incbin "baserom.gba", 0x16A8F44, 0x40
.global gUnknown_96A8F84
gUnknown_96A8F84:
.string "AT4PX"
.incbin "baserom.gba", 0x16A8F89, 0x27B
.global gUnknown_96A9204
gUnknown_96A9204:
.4byte gUnknown_96A8F44
.4byte gUnknown_96A8F84
.incbin "baserom.gba", 0x16A920C, 0x68
.global gKaoHoOh
gKaoHoOh:
.string "SIRO"
.4byte gUnknown_96A959C
.incbin "baserom.gba", 0x16A927C, 0x8
.global gUnknown_96A9284
gUnknown_96A9284:
.incbin "baserom.gba", 0x16A9284, 0x40
.global gUnknown_96A92C4
gUnknown_96A92C4:
.string "AT4PX"
.incbin "baserom.gba", 0x16A92C9, 0x2D3
.global gUnknown_96A959C
gUnknown_96A959C:
.4byte gUnknown_96A9284
.4byte gUnknown_96A92C4
.incbin "baserom.gba", 0x16A95A4, 0x60
.global gKaoTreecko
gKaoTreecko:
.string "SIRO"
.4byte gUnknown_96ABBAC
.incbin "baserom.gba", 0x16A960C, 0x8
.global gUnknown_96A9614
gUnknown_96A9614:
.incbin "baserom.gba", 0x16A9614, 0x40
.global gUnknown_96A9654
gUnknown_96A9654:
.string "AT4PX"
.incbin "baserom.gba", 0x16A9659, 0x28F
.global gUnknown_96A98E8
gUnknown_96A98E8:
.incbin "baserom.gba", 0x16A98E8, 0x40
.global gUnknown_96A9928
gUnknown_96A9928:
.string "AT4PX"
.incbin "baserom.gba", 0x16A992D, 0x27F
.global gUnknown_96A9BAC
gUnknown_96A9BAC:
.incbin "baserom.gba", 0x16A9BAC, 0x40
.global gUnknown_96A9BEC
gUnknown_96A9BEC:
.incbin "baserom.gba", 0x16A9BEC, 0x2A4
.global gUnknown_96A9E90
gUnknown_96A9E90:
.incbin "baserom.gba", 0x16A9E90, 0x40
.global gUnknown_96A9ED0
gUnknown_96A9ED0:
.string "AT4PX"
.incbin "baserom.gba", 0x16A9ED5, 0x2A3
.global gUnknown_96AA178
gUnknown_96AA178:
.incbin "baserom.gba", 0x16AA178, 0x40
.global gUnknown_96AA1B8
gUnknown_96AA1B8:
.incbin "baserom.gba", 0x16AA1B8, 0x298
.global gUnknown_96AA450
gUnknown_96AA450:
.incbin "baserom.gba", 0x16AA450, 0x40
.global gUnknown_96AA490
gUnknown_96AA490:
.string "AT4PX"
.incbin "baserom.gba", 0x16AA495, 0x28B
.global gUnknown_96AA720
gUnknown_96AA720:
.incbin "baserom.gba", 0x16AA720, 0x40
.global gUnknown_96AA760
gUnknown_96AA760:
.string "AT4PX"
.incbin "baserom.gba", 0x16AA765, 0x287
.global gUnknown_96AA9EC
gUnknown_96AA9EC:
.incbin "baserom.gba", 0x16AA9EC, 0x40
.global gUnknown_96AAA2C
gUnknown_96AAA2C:
.incbin "baserom.gba", 0x16AAA2C, 0x2BC
.global gUnknown_96AACE8
gUnknown_96AACE8:
.incbin "baserom.gba", 0x16AACE8, 0x40
.global gUnknown_96AAD28
gUnknown_96AAD28:
.incbin "baserom.gba", 0x16AAD28, 0x29C
.global gUnknown_96AAFC4
gUnknown_96AAFC4:
.incbin "baserom.gba", 0x16AAFC4, 0x40
.global gUnknown_96AB004
gUnknown_96AB004:
.incbin "baserom.gba", 0x16AB004, 0x27C
.global gUnknown_96AB280
gUnknown_96AB280:
.incbin "baserom.gba", 0x16AB280, 0x40
.global gUnknown_96AB2C0
gUnknown_96AB2C0:
.string "AT4PX"
.incbin "baserom.gba", 0x16AB2C5, 0x2EF
.global gUnknown_96AB5B4
gUnknown_96AB5B4:
.incbin "baserom.gba", 0x16AB5B4, 0x40
.global gUnknown_96AB5F4
gUnknown_96AB5F4:
.incbin "baserom.gba", 0x16AB5F4, 0x2A4
.global gUnknown_96AB898
gUnknown_96AB898:
.incbin "baserom.gba", 0x16AB898, 0x40
.global gUnknown_96AB8D8
gUnknown_96AB8D8:
.incbin "baserom.gba", 0x16AB8D8, 0x2D4
.global gUnknown_96ABBAC
gUnknown_96ABBAC:
.4byte gUnknown_96A9614
.4byte gUnknown_96A9654
.4byte gUnknown_96A98E8
.4byte gUnknown_96A9928
.4byte gUnknown_96A9BAC
.4byte gUnknown_96A9BEC
.4byte gUnknown_96A9E90
.4byte gUnknown_96A9ED0
.4byte gUnknown_96AA178
.4byte gUnknown_96AA1B8
.4byte gUnknown_96AA450
.4byte gUnknown_96AA490
.4byte gUnknown_96AA720
.4byte gUnknown_96AA760
.4byte gUnknown_96AA9EC
.4byte gUnknown_96AAA2C
.4byte gUnknown_96AACE8
.4byte gUnknown_96AAD28
.4byte gUnknown_96AAFC4
.4byte gUnknown_96AB004
.4byte gUnknown_96AB280
.4byte gUnknown_96AB2C0
.4byte gUnknown_96AB5B4
.4byte gUnknown_96AB5F4
.4byte gUnknown_96AB898
.4byte gUnknown_96AB8D8
.global gKaoTorchic
gKaoTorchic:
.string "SIRO"
.4byte gUnknown_96AE15C
.incbin "baserom.gba", 0x16ABC1C, 0x8
.global gUnknown_96ABC24
gUnknown_96ABC24:
.incbin "baserom.gba", 0x16ABC24, 0x40
.global gUnknown_96ABC64
gUnknown_96ABC64:
.string "AT4PX"
.incbin "baserom.gba", 0x16ABC69, 0x287
.global gUnknown_96ABEF0
gUnknown_96ABEF0:
.incbin "baserom.gba", 0x16ABEF0, 0x40
.global gUnknown_96ABF30
gUnknown_96ABF30:
.string "AT4PX"
.incbin "baserom.gba", 0x16ABF35, 0x2A3
.global gUnknown_96AC1D8
gUnknown_96AC1D8:
.incbin "baserom.gba", 0x16AC1D8, 0x40
.global gUnknown_96AC218
gUnknown_96AC218:
.string "AT4PX"
.incbin "baserom.gba", 0x16AC21D, 0x2B3
.global gUnknown_96AC4D0
gUnknown_96AC4D0:
.incbin "baserom.gba", 0x16AC4D0, 0x40
.global gUnknown_96AC510
gUnknown_96AC510:
.string "AT4PX"
.incbin "baserom.gba", 0x16AC515, 0x293
.global gUnknown_96AC7A8
gUnknown_96AC7A8:
.incbin "baserom.gba", 0x16AC7A8, 0x40
.global gUnknown_96AC7E8
gUnknown_96AC7E8:
.incbin "baserom.gba", 0x16AC7E8, 0x260
.global gUnknown_96ACA48
gUnknown_96ACA48:
.incbin "baserom.gba", 0x16ACA48, 0x40
.global gUnknown_96ACA88
gUnknown_96ACA88:
.incbin "baserom.gba", 0x16ACA88, 0x290
.global gUnknown_96ACD18
gUnknown_96ACD18:
.incbin "baserom.gba", 0x16ACD18, 0x40
.global gUnknown_96ACD58
gUnknown_96ACD58:
.incbin "baserom.gba", 0x16ACD58, 0x28C
.global gUnknown_96ACFE4
gUnknown_96ACFE4:
.incbin "baserom.gba", 0x16ACFE4, 0x40
.global gUnknown_96AD024
gUnknown_96AD024:
.incbin "baserom.gba", 0x16AD024, 0x2D4
.global gUnknown_96AD2F8
gUnknown_96AD2F8:
.incbin "baserom.gba", 0x16AD2F8, 0x40
.global gUnknown_96AD338
gUnknown_96AD338:
.incbin "baserom.gba", 0x16AD338, 0x29C
.global gUnknown_96AD5D4
gUnknown_96AD5D4:
.incbin "baserom.gba", 0x16AD5D4, 0x40
.global gUnknown_96AD614
gUnknown_96AD614:
.incbin "baserom.gba", 0x16AD614, 0x29C
.global gUnknown_96AD8B0
gUnknown_96AD8B0:
.incbin "baserom.gba", 0x16AD8B0, 0x40
.global gUnknown_96AD8F0
gUnknown_96AD8F0:
.string "AT4PX"
.incbin "baserom.gba", 0x16AD8F5, 0x29F
.global gUnknown_96ADB94
gUnknown_96ADB94:
.incbin "baserom.gba", 0x16ADB94, 0x40
.global gUnknown_96ADBD4
gUnknown_96ADBD4:
.incbin "baserom.gba", 0x16ADBD4, 0x288
.global gUnknown_96ADE5C
gUnknown_96ADE5C:
.incbin "baserom.gba", 0x16ADE5C, 0x40
.global gUnknown_96ADE9C
gUnknown_96ADE9C:
.incbin "baserom.gba", 0x16ADE9C, 0x2C0
.global gUnknown_96AE15C
gUnknown_96AE15C:
.4byte gUnknown_96ABC24
.4byte gUnknown_96ABC64
.4byte gUnknown_96ABEF0
.4byte gUnknown_96ABF30
.4byte gUnknown_96AC1D8
.4byte gUnknown_96AC218
.4byte gUnknown_96AC4D0
.4byte gUnknown_96AC510
.4byte gUnknown_96AC7A8
.4byte gUnknown_96AC7E8
.4byte gUnknown_96ACA48
.4byte gUnknown_96ACA88
.4byte gUnknown_96ACD18
.4byte gUnknown_96ACD58
.4byte gUnknown_96ACFE4
.4byte gUnknown_96AD024
.4byte gUnknown_96AD2F8
.4byte gUnknown_96AD338
.4byte gUnknown_96AD5D4
.4byte gUnknown_96AD614
.4byte gUnknown_96AD8B0
.4byte gUnknown_96AD8F0
.4byte gUnknown_96ADB94
.4byte gUnknown_96ADBD4
.4byte gUnknown_96ADE5C
.4byte gUnknown_96ADE9C
.global gKaoMudkip
gKaoMudkip:
.string "SIRO"
.4byte gUnknown_96B064C
.incbin "baserom.gba", 0x16AE1CC, 0x8
.global gUnknown_96AE1D4
gUnknown_96AE1D4:
.incbin "baserom.gba", 0x16AE1D4, 0x40
.global gUnknown_96AE214
gUnknown_96AE214:
.string "AT4PX"
.incbin "baserom.gba", 0x16AE219, 0x27B
.global gUnknown_96AE494
gUnknown_96AE494:
.incbin "baserom.gba", 0x16AE494, 0x40
.global gUnknown_96AE4D4
gUnknown_96AE4D4:
.string "AT4PX"
.incbin "baserom.gba", 0x16AE4D9, 0x25B
.global gUnknown_96AE734
gUnknown_96AE734:
.incbin "baserom.gba", 0x16AE734, 0x40
.global gUnknown_96AE774
gUnknown_96AE774:
.string "AT4PX"
.incbin "baserom.gba", 0x16AE779, 0x287
.global gUnknown_96AEA00
gUnknown_96AEA00:
.incbin "baserom.gba", 0x16AEA00, 0x40
.global gUnknown_96AEA40
gUnknown_96AEA40:
.incbin "baserom.gba", 0x16AEA40, 0x2B8
.global gUnknown_96AECF8
gUnknown_96AECF8:
.incbin "baserom.gba", 0x16AECF8, 0x40
.global gUnknown_96AED38
gUnknown_96AED38:
.incbin "baserom.gba", 0x16AED38, 0x2A0
.global gUnknown_96AEFD8
gUnknown_96AEFD8:
.incbin "baserom.gba", 0x16AEFD8, 0x40
.global gUnknown_96AF018
gUnknown_96AF018:
.incbin "baserom.gba", 0x16AF018, 0x278
.global gUnknown_96AF290
gUnknown_96AF290:
.incbin "baserom.gba", 0x16AF290, 0x40
.global gUnknown_96AF2D0
gUnknown_96AF2D0:
.string "AT4PX"
.incbin "baserom.gba", 0x16AF2D5, 0x27B
.global gUnknown_96AF550
gUnknown_96AF550:
.incbin "baserom.gba", 0x16AF550, 0x40
.global gUnknown_96AF590
gUnknown_96AF590:
.string "AT4PX"
.incbin "baserom.gba", 0x16AF595, 0x2BB
.global gUnknown_96AF850
gUnknown_96AF850:
.incbin "baserom.gba", 0x16AF850, 0x40
.global gUnknown_96AF890
gUnknown_96AF890:
.string "AT4PX"
.incbin "baserom.gba", 0x16AF895, 0x27F
.global gUnknown_96AFB14
gUnknown_96AFB14:
.incbin "baserom.gba", 0x16AFB14, 0x40
.global gUnknown_96AFB54
gUnknown_96AFB54:
.incbin "baserom.gba", 0x16AFB54, 0x254
.global gUnknown_96AFDA8
gUnknown_96AFDA8:
.incbin "baserom.gba", 0x16AFDA8, 0x40
.global gUnknown_96AFDE8
gUnknown_96AFDE8:
.incbin "baserom.gba", 0x16AFDE8, 0x2C8
.global gUnknown_96B00B0
gUnknown_96B00B0:
.incbin "baserom.gba", 0x16B00B0, 0x40
.global gUnknown_96B00F0
gUnknown_96B00F0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B00F5, 0x267
.global gUnknown_96B035C
gUnknown_96B035C:
.incbin "baserom.gba", 0x16B035C, 0x40
.global gUnknown_96B039C
gUnknown_96B039C:
.incbin "baserom.gba", 0x16B039C, 0x2B0
.global gUnknown_96B064C
gUnknown_96B064C:
.4byte gUnknown_96AE1D4
.4byte gUnknown_96AE214
.4byte gUnknown_96AE494
.4byte gUnknown_96AE4D4
.4byte gUnknown_96AE734
.4byte gUnknown_96AE774
.4byte gUnknown_96AEA00
.4byte gUnknown_96AEA40
.4byte gUnknown_96AECF8
.4byte gUnknown_96AED38
.4byte gUnknown_96AEFD8
.4byte gUnknown_96AF018
.4byte gUnknown_96AF290
.4byte gUnknown_96AF2D0
.4byte gUnknown_96AF550
.4byte gUnknown_96AF590
.4byte gUnknown_96AF850
.4byte gUnknown_96AF890
.4byte gUnknown_96AFB14
.4byte gUnknown_96AFB54
.4byte gUnknown_96AFDA8
.4byte gUnknown_96AFDE8
.4byte gUnknown_96B00B0
.4byte gUnknown_96B00F0
.4byte gUnknown_96B035C
.4byte gUnknown_96B039C
.global gKaoLombre
gKaoLombre:
.string "SIRO"
.4byte gUnknown_96B1CEC
.incbin "baserom.gba", 0x16B06BC, 0x8
.global gUnknown_96B06C4
gUnknown_96B06C4:
.incbin "baserom.gba", 0x16B06C4, 0x40
.global gUnknown_96B0704
gUnknown_96B0704:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0709, 0x297
.global gUnknown_96B09A0
gUnknown_96B09A0:
.incbin "baserom.gba", 0x16B09A0, 0x40
.global gUnknown_96B09E0
gUnknown_96B09E0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B09E5, 0x26B
.global gUnknown_96B0C50
gUnknown_96B0C50:
.incbin "baserom.gba", 0x16B0C50, 0x40
.global gUnknown_96B0C90
gUnknown_96B0C90:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0C95, 0x29F
.global gUnknown_96B0F34
gUnknown_96B0F34:
.incbin "baserom.gba", 0x16B0F34, 0x40
.global gUnknown_96B0F74
gUnknown_96B0F74:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0F79, 0x26B
.global gUnknown_96B11E4
gUnknown_96B11E4:
.incbin "baserom.gba", 0x16B11E4, 0x40
.global gUnknown_96B1224
gUnknown_96B1224:
.incbin "baserom.gba", 0x16B1224, 0x298
.global gUnknown_96B14BC
gUnknown_96B14BC:
.incbin "baserom.gba", 0x16B14BC, 0x40
.global gUnknown_96B14FC
gUnknown_96B14FC:
.incbin "baserom.gba", 0x16B14FC, 0x260
.global gUnknown_96B175C
gUnknown_96B175C:
.incbin "baserom.gba", 0x16B175C, 0x40
.global gUnknown_96B179C
gUnknown_96B179C:
.incbin "baserom.gba", 0x16B179C, 0x2A4
.global gUnknown_96B1A40
gUnknown_96B1A40:
.incbin "baserom.gba", 0x16B1A40, 0x40
.global gUnknown_96B1A80
gUnknown_96B1A80:
.string "AT4PX"
.incbin "baserom.gba", 0x16B1A85, 0x267
.global gUnknown_96B1CEC
gUnknown_96B1CEC:
.4byte gUnknown_96B06C4
.4byte gUnknown_96B0704
.4byte gUnknown_96B09A0
.4byte gUnknown_96B09E0
.4byte gUnknown_96B0C50
.4byte gUnknown_96B0C90
.4byte gUnknown_96B0F34
.4byte gUnknown_96B0F74
.4byte gUnknown_96B11E4
.4byte gUnknown_96B1224
.4byte gUnknown_96B14BC
.4byte gUnknown_96B14FC
.4byte gUnknown_96B175C
.4byte gUnknown_96B179C
.4byte gUnknown_96B1A40
.4byte gUnknown_96B1A80
.incbin "baserom.gba", 0x16B1D2C, 0x28
.global gKaoShiftry
gKaoShiftry:
.string "SIRO"
.4byte gUnknown_96B29E0
.incbin "baserom.gba", 0x16B1D5C, 0x8
.global gUnknown_96B1D64
gUnknown_96B1D64:
.incbin "baserom.gba", 0x16B1D64, 0x40
.global gUnknown_96B1DA4
gUnknown_96B1DA4:
.string "AT4PX"
.incbin "baserom.gba", 0x16B1DA9, 0x2D3
.global gUnknown_96B207C
gUnknown_96B207C:
.incbin "baserom.gba", 0x16B207C, 0x40
.global gUnknown_96B20BC
gUnknown_96B20BC:
.incbin "baserom.gba", 0x16B20BC, 0x2F4
.global gUnknown_96B23B0
gUnknown_96B23B0:
.incbin "baserom.gba", 0x16B23B0, 0x40
.global gUnknown_96B23F0
gUnknown_96B23F0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B23F5, 0x2CB
.global gUnknown_96B26C0
gUnknown_96B26C0:
.incbin "baserom.gba", 0x16B26C0, 0x40
.global gUnknown_96B2700
gUnknown_96B2700:
.string "AT4PX"
.incbin "baserom.gba", 0x16B2705, 0x2DB
.global gUnknown_96B29E0
gUnknown_96B29E0:
.4byte gUnknown_96B1D64
.4byte gUnknown_96B1DA4
.4byte gUnknown_96B207C
.4byte gUnknown_96B20BC
.4byte gUnknown_96B23B0
.4byte gUnknown_96B23F0
.4byte gUnknown_96B26C0
.4byte gUnknown_96B2700
.incbin "baserom.gba", 0x16B2A00, 0x48
.global gKaoPelipper
gKaoPelipper:
.string "SIRO"
.4byte gUnknown_96B2CBC
.incbin "baserom.gba", 0x16B2A50, 0x8
.global gUnknown_96B2A58
gUnknown_96B2A58:
.incbin "baserom.gba", 0x16B2A58, 0x40
.global gUnknown_96B2A98
gUnknown_96B2A98:
.string "AT4PX"
.incbin "baserom.gba", 0x16B2A9D, 0x21F
.global gUnknown_96B2CBC
gUnknown_96B2CBC:
.4byte gUnknown_96B2A58
.4byte gUnknown_96B2A98
.incbin "baserom.gba", 0x16B2CC4, 0x60
.global gKaoGardevoir
gKaoGardevoir:
.string "SIRO"
.4byte gUnknown_96B35B4
.incbin "baserom.gba", 0x16B2D2C, 0x8
.global gUnknown_96B2D34
gUnknown_96B2D34:
.incbin "baserom.gba", 0x16B2D34, 0x40
.global gUnknown_96B2D74
gUnknown_96B2D74:
.string "AT4PX"
.incbin "baserom.gba", 0x16B2D79, 0x29F
.global gUnknown_96B3018
gUnknown_96B3018:
.incbin "baserom.gba", 0x16B3018, 0x40
.global gUnknown_96B3058
gUnknown_96B3058:
.string "AT4PX"
.incbin "baserom.gba", 0x16B305D, 0x293
.global gUnknown_96B32F0
gUnknown_96B32F0:
.incbin "baserom.gba", 0x16B32F0, 0x40
.global gUnknown_96B3330
gUnknown_96B3330:
.string "AT4PX"
.incbin "baserom.gba", 0x16B3335, 0x27F
.global gUnknown_96B35B4
gUnknown_96B35B4:
.4byte gUnknown_96B2D34
.4byte gUnknown_96B2D74
.4byte gUnknown_96B3018
.4byte gUnknown_96B3058
.4byte gUnknown_96B32F0
.4byte gUnknown_96B3330
.incbin "baserom.gba", 0x16B35CC, 0x50
.global gKaoMakuhita
gKaoMakuhita:
.string "SIRO"
.4byte gUnknown_96B3908
.incbin "baserom.gba", 0x16B3624, 0x8
.global gUnknown_96B362C
gUnknown_96B362C:
.incbin "baserom.gba", 0x16B362C, 0x40
.global gUnknown_96B366C
gUnknown_96B366C:
.incbin "baserom.gba", 0x16B366C, 0x29C
.global gUnknown_96B3908
gUnknown_96B3908:
.4byte gUnknown_96B362C
.4byte gUnknown_96B366C
.incbin "baserom.gba", 0x16B3910, 0x60
.global gKaoSkitty
gKaoSkitty:
.string "SIRO"
.4byte gUnknown_96B5F80
.incbin "baserom.gba", 0x16B3978, 0x8
.global gUnknown_96B3980
gUnknown_96B3980:
.incbin "baserom.gba", 0x16B3980, 0x40
.global gUnknown_96B39C0
gUnknown_96B39C0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B39C5, 0x28B
.global gUnknown_96B3C50
gUnknown_96B3C50:
.incbin "baserom.gba", 0x16B3C50, 0x40
.global gUnknown_96B3C90
gUnknown_96B3C90:
.string "AT4PX"
.incbin "baserom.gba", 0x16B3C95, 0x2A3
.global gUnknown_96B3F38
gUnknown_96B3F38:
.incbin "baserom.gba", 0x16B3F38, 0x40
.global gUnknown_96B3F78
gUnknown_96B3F78:
.string "AT4PX"
.incbin "baserom.gba", 0x16B3F7D, 0x29B
.global gUnknown_96B4218
gUnknown_96B4218:
.incbin "baserom.gba", 0x16B4218, 0x40
.global gUnknown_96B4258
gUnknown_96B4258:
.string "AT4PX"
.incbin "baserom.gba", 0x16B425D, 0x2A3
.global gUnknown_96B4500
gUnknown_96B4500:
.incbin "baserom.gba", 0x16B4500, 0x40
.global gUnknown_96B4540
gUnknown_96B4540:
.string "AT4PX"
.incbin "baserom.gba", 0x16B4545, 0x29F
.global gUnknown_96B47E4
gUnknown_96B47E4:
.incbin "baserom.gba", 0x16B47E4, 0x40
.global gUnknown_96B4824
gUnknown_96B4824:
.incbin "baserom.gba", 0x16B4824, 0x2AC
.global gUnknown_96B4AD0
gUnknown_96B4AD0:
.incbin "baserom.gba", 0x16B4AD0, 0x40
.global gUnknown_96B4B10
gUnknown_96B4B10:
.string "AT4PX"
.incbin "baserom.gba", 0x16B4B15, 0x29B
.global gUnknown_96B4DB0
gUnknown_96B4DB0:
.incbin "baserom.gba", 0x16B4DB0, 0x40
.global gUnknown_96B4DF0
gUnknown_96B4DF0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B4DF5, 0x2E3
.global gUnknown_96B50D8
gUnknown_96B50D8:
.incbin "baserom.gba", 0x16B50D8, 0x40
.global gUnknown_96B5118
gUnknown_96B5118:
.incbin "baserom.gba", 0x16B5118, 0x298
.global gUnknown_96B53B0
gUnknown_96B53B0:
.incbin "baserom.gba", 0x16B53B0, 0x40
.global gUnknown_96B53F0
gUnknown_96B53F0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B53F5, 0x2A7
.global gUnknown_96B569C
gUnknown_96B569C:
.incbin "baserom.gba", 0x16B569C, 0x40
.global gUnknown_96B56DC
gUnknown_96B56DC:
.incbin "baserom.gba", 0x16B56DC, 0x2B4
.global gUnknown_96B5990
gUnknown_96B5990:
.incbin "baserom.gba", 0x16B5990, 0x40
.global gUnknown_96B59D0
gUnknown_96B59D0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B59D5, 0x297
.global gUnknown_96B5C6C
gUnknown_96B5C6C:
.incbin "baserom.gba", 0x16B5C6C, 0x40
.global gUnknown_96B5CAC
gUnknown_96B5CAC:
.incbin "baserom.gba", 0x16B5CAC, 0x2D4
.global gUnknown_96B5F80
gUnknown_96B5F80:
.4byte gUnknown_96B3980
.4byte gUnknown_96B39C0
.4byte gUnknown_96B3C50
.4byte gUnknown_96B3C90
.4byte gUnknown_96B3F38
.4byte gUnknown_96B3F78
.4byte gUnknown_96B4218
.4byte gUnknown_96B4258
.4byte gUnknown_96B4500
.4byte gUnknown_96B4540
.4byte gUnknown_96B47E4
.4byte gUnknown_96B4824
.4byte gUnknown_96B4AD0
.4byte gUnknown_96B4B10
.4byte gUnknown_96B4DB0
.4byte gUnknown_96B4DF0
.4byte gUnknown_96B50D8
.4byte gUnknown_96B5118
.4byte gUnknown_96B53B0
.4byte gUnknown_96B53F0
.4byte gUnknown_96B569C
.4byte gUnknown_96B56DC
.4byte gUnknown_96B5990
.4byte gUnknown_96B59D0
.4byte gUnknown_96B5C6C
.4byte gUnknown_96B5CAC
.incbin "baserom.gba", 0x16B5FE8, 0x8
.global gKaoMedicham
gKaoMedicham:
.string "SIRO"
.4byte gUnknown_96B73FC
.incbin "baserom.gba", 0x16B5FF8, 0x8
.global gUnknown_96B6000
gUnknown_96B6000:
.incbin "baserom.gba", 0x16B6000, 0x40
.global gUnknown_96B6040
gUnknown_96B6040:
.string "AT4PX"
.incbin "baserom.gba", 0x16B6045, 0x297
.global gUnknown_96B62DC
gUnknown_96B62DC:
.incbin "baserom.gba", 0x16B62DC, 0x40
.global gUnknown_96B631C
gUnknown_96B631C:
.incbin "baserom.gba", 0x16B631C, 0x2A8
.global gUnknown_96B65C4
gUnknown_96B65C4:
.incbin "baserom.gba", 0x16B65C4, 0x40
.global gUnknown_96B6604
gUnknown_96B6604:
.string "AT4PX"
.incbin "baserom.gba", 0x16B6609, 0x2C3
.global gUnknown_96B68CC
gUnknown_96B68CC:
.incbin "baserom.gba", 0x16B68CC, 0x40
.global gUnknown_96B690C
gUnknown_96B690C:
.incbin "baserom.gba", 0x16B690C, 0x290
.global gUnknown_96B6B9C
gUnknown_96B6B9C:
.incbin "baserom.gba", 0x16B6B9C, 0x40
.global gUnknown_96B6BDC
gUnknown_96B6BDC:
.incbin "baserom.gba", 0x16B6BDC, 0x290
.global gUnknown_96B6E6C
gUnknown_96B6E6C:
.incbin "baserom.gba", 0x16B6E6C, 0x40
.global gUnknown_96B6EAC
gUnknown_96B6EAC:
.incbin "baserom.gba", 0x16B6EAC, 0x28C
.global gUnknown_96B7138
gUnknown_96B7138:
.incbin "baserom.gba", 0x16B7138, 0x40
.global gUnknown_96B7178
gUnknown_96B7178:
.incbin "baserom.gba", 0x16B7178, 0x284
.global gUnknown_96B73FC
gUnknown_96B73FC:
.4byte gUnknown_96B6000
.4byte gUnknown_96B6040
.4byte gUnknown_96B62DC
.4byte gUnknown_96B631C
.4byte gUnknown_96B65C4
.4byte gUnknown_96B6604
.4byte gUnknown_96B68CC
.4byte gUnknown_96B690C
.4byte gUnknown_96B6B9C
.4byte gUnknown_96B6BDC
.4byte gUnknown_96B6E6C
.4byte gUnknown_96B6EAC
.4byte gUnknown_96B7138
.4byte gUnknown_96B7178
.incbin "baserom.gba", 0x16B7434, 0x30
.global gKaoGulpin
gKaoGulpin:
.string "SIRO"
.4byte gUnknown_96B76CC
.incbin "baserom.gba", 0x16B746C, 0x8
.global gUnknown_96B7474
gUnknown_96B7474:
.incbin "baserom.gba", 0x16B7474, 0x40
.global gUnknown_96B74B4
gUnknown_96B74B4:
.string "AT4PX"
.incbin "baserom.gba", 0x16B74B9, 0x213
.global gUnknown_96B76CC
gUnknown_96B76CC:
.4byte gUnknown_96B7474
.4byte gUnknown_96B74B4
.incbin "baserom.gba", 0x16B76D4, 0x60
.global gKaoSpinda
gKaoSpinda:
.string "SIRO"
.4byte gUnknown_96B8314
.incbin "baserom.gba", 0x16B773C, 0x8
.global gUnknown_96B7744
gUnknown_96B7744:
.incbin "baserom.gba", 0x16B7744, 0x40
.global gUnknown_96B7784
gUnknown_96B7784:
.string "AT4PX"
.incbin "baserom.gba", 0x16B7789, 0x2D3
.global gUnknown_96B7A5C
gUnknown_96B7A5C:
.incbin "baserom.gba", 0x16B7A5C, 0x40
.global gUnknown_96B7A9C
gUnknown_96B7A9C:
.incbin "baserom.gba", 0x16B7A9C, 0x288
.global gUnknown_96B7D24
gUnknown_96B7D24:
.incbin "baserom.gba", 0x16B7D24, 0x40
.global gUnknown_96B7D64
gUnknown_96B7D64:
.string "AT4PX"
.incbin "baserom.gba", 0x16B7D69, 0x2DB
.global gUnknown_96B8044
gUnknown_96B8044:
.incbin "baserom.gba", 0x16B8044, 0x40
.global gUnknown_96B8084
gUnknown_96B8084:
.string "AT4PX"
.incbin "baserom.gba", 0x16B8089, 0x28B
.global gUnknown_96B8314
gUnknown_96B8314:
.4byte gUnknown_96B7744
.4byte gUnknown_96B7784
.4byte gUnknown_96B7A5C
.4byte gUnknown_96B7A9C
.4byte gUnknown_96B7D24
.4byte gUnknown_96B7D64
.4byte gUnknown_96B8044
.4byte gUnknown_96B8084
.incbin "baserom.gba", 0x16B8334, 0x48
.global gKaoWhiscash
gKaoWhiscash:
.string "SIRO"
.4byte gUnknown_96B88E8
.incbin "baserom.gba", 0x16B8384, 0x8
.global gUnknown_96B838C
gUnknown_96B838C:
.incbin "baserom.gba", 0x16B838C, 0x40
.global gUnknown_96B83CC
gUnknown_96B83CC:
.incbin "baserom.gba", 0x16B83CC, 0x27C
.global gUnknown_96B8648
gUnknown_96B8648:
.incbin "baserom.gba", 0x16B8648, 0x40
.global gUnknown_96B8688
gUnknown_96B8688:
.string "AT4PX"
.incbin "baserom.gba", 0x16B868D, 0x25B
.global gUnknown_96B88E8
gUnknown_96B88E8:
.4byte gUnknown_96B838C
.4byte gUnknown_96B83CC
.4byte gUnknown_96B8648
.4byte gUnknown_96B8688
.incbin "baserom.gba", 0x16B88F8, 0x58
.global gKaoKecleon
gKaoKecleon:
.string "SIRO"
.4byte gUnknown_96B95F0
.incbin "baserom.gba", 0x16B8958, 0x8
.global gUnknown_96B8960
gUnknown_96B8960:
.incbin "baserom.gba", 0x16B8960, 0x40
.global gUnknown_96B89A0
gUnknown_96B89A0:
.string "AT4PX"
.incbin "baserom.gba", 0x16B89A5, 0x2DF
.global gUnknown_96B8C84
gUnknown_96B8C84:
.incbin "baserom.gba", 0x16B8C84, 0x40
.global gUnknown_96B8CC4
gUnknown_96B8CC4:
.string "AT4PX"
.incbin "baserom.gba", 0x16B8CC9, 0x2E3
.global gUnknown_96B8FAC
gUnknown_96B8FAC:
.incbin "baserom.gba", 0x16B8FAC, 0x40
.global gUnknown_96B8FEC
gUnknown_96B8FEC:
.incbin "baserom.gba", 0x16B8FEC, 0x2DC
.global gUnknown_96B92C8
gUnknown_96B92C8:
.incbin "baserom.gba", 0x16B92C8, 0x40
.global gUnknown_96B9308
gUnknown_96B9308:
.incbin "baserom.gba", 0x16B9308, 0x2E8
.global gUnknown_96B95F0
gUnknown_96B95F0:
.4byte gUnknown_96B8960
.4byte gUnknown_96B89A0
.4byte gUnknown_96B8C84
.4byte gUnknown_96B8CC4
.incbin "baserom.gba", 0x16B9600, 0x20
.4byte gUnknown_96B8FAC
.4byte gUnknown_96B8FEC
.4byte gUnknown_96B92C8
.4byte gUnknown_96B9308
.incbin "baserom.gba", 0x16B9630, 0x28
.global gKaoAbsol
gKaoAbsol:
.string "SIRO"
.4byte gUnknown_96B9C14
.incbin "baserom.gba", 0x16B9660, 0x8
.global gUnknown_96B9668
gUnknown_96B9668:
.incbin "baserom.gba", 0x16B9668, 0x40
.global gUnknown_96B96A8
gUnknown_96B96A8:
.string "AT4PX"
.incbin "baserom.gba", 0x16B96AD, 0x29B
.global gUnknown_96B9948
gUnknown_96B9948:
.incbin "baserom.gba", 0x16B9948, 0x40
.global gUnknown_96B9988
gUnknown_96B9988:
.string "AT4PX"
.incbin "baserom.gba", 0x16B998D, 0x287
.global gUnknown_96B9C14
gUnknown_96B9C14:
.4byte gUnknown_96B9668
.4byte gUnknown_96B96A8
.4byte gUnknown_96B9948
.4byte gUnknown_96B9988
.incbin "baserom.gba", 0x16B9C24, 0x58
.global gKaoWynaut
gKaoWynaut:
.string "SIRO"
.4byte gUnknown_96B9F88
.incbin "baserom.gba", 0x16B9C84, 0x8
.global gUnknown_96B9C8C
gUnknown_96B9C8C:
.incbin "baserom.gba", 0x16B9C8C, 0x40
.global gUnknown_96B9CCC
gUnknown_96B9CCC:
.incbin "baserom.gba", 0x16B9CCC, 0x2BC
.global gUnknown_96B9F88
gUnknown_96B9F88:
.4byte gUnknown_96B9C8C
.4byte gUnknown_96B9CCC
.incbin "baserom.gba", 0x16B9F90, 0x60
.global gKaoLatias
gKaoLatias:
.string "SIRO"
.4byte gUnknown_96BA514
.incbin "baserom.gba", 0x16B9FF8, 0x8
.global gUnknown_96BA000
gUnknown_96BA000:
.incbin "baserom.gba", 0x16BA000, 0x40
.global gUnknown_96BA040
gUnknown_96BA040:
.string "AT4PX"
.incbin "baserom.gba", 0x16BA045, 0x24B
.global gUnknown_96BA290
gUnknown_96BA290:
.incbin "baserom.gba", 0x16BA290, 0x40
.global gUnknown_96BA2D0
gUnknown_96BA2D0:
.string "AT4PX"
.incbin "baserom.gba", 0x16BA2D5, 0x23F
.global gUnknown_96BA514
gUnknown_96BA514:
.4byte gUnknown_96BA000
.4byte gUnknown_96BA040
.4byte gUnknown_96BA290
.4byte gUnknown_96BA2D0
.incbin "baserom.gba", 0x16BA524, 0x58
.global gKaoLatios
gKaoLatios:
.string "SIRO"
.4byte gUnknown_96BAB38
.incbin "baserom.gba", 0x16BA584, 0x8
.global gUnknown_96BA58C
gUnknown_96BA58C:
.incbin "baserom.gba", 0x16BA58C, 0x40
.global gUnknown_96BA5CC
gUnknown_96BA5CC:
.incbin "baserom.gba", 0x16BA5CC, 0x290
.global gUnknown_96BA85C
gUnknown_96BA85C:
.incbin "baserom.gba", 0x16BA85C, 0x40
.global gUnknown_96BA89C
gUnknown_96BA89C:
.incbin "baserom.gba", 0x16BA89C, 0x29C
.global gUnknown_96BAB38
gUnknown_96BAB38:
.4byte gUnknown_96BA58C
.4byte gUnknown_96BA5CC
.4byte gUnknown_96BA85C
.4byte gUnknown_96BA89C
.incbin "baserom.gba", 0x16BAB48, 0x58
.global gKaoKyogre
gKaoKyogre:
.string "SIRO"
.4byte gUnknown_96BAE4C
.incbin "baserom.gba", 0x16BABA8, 0x8
.global gUnknown_96BABB0
gUnknown_96BABB0:
.incbin "baserom.gba", 0x16BABB0, 0x40
.global gUnknown_96BABF0
gUnknown_96BABF0:
.string "AT4PX"
.incbin "baserom.gba", 0x16BABF5, 0x257
.global gUnknown_96BAE4C
gUnknown_96BAE4C:
.4byte gUnknown_96BABB0
.4byte gUnknown_96BABF0
.incbin "baserom.gba", 0x16BAE54, 0x68
.global gKaoGroudon
gKaoGroudon:
.string "SIRO"
.4byte gUnknown_96BB1FC
.incbin "baserom.gba", 0x16BAEC4, 0x8
.global gUnknown_96BAECC
gUnknown_96BAECC:
.incbin "baserom.gba", 0x16BAECC, 0x40
.global gUnknown_96BAF0C
gUnknown_96BAF0C:
.incbin "baserom.gba", 0x16BAF0C, 0x2F0
.global gUnknown_96BB1FC
gUnknown_96BB1FC:
.4byte gUnknown_96BAECC
.4byte gUnknown_96BAF0C
.incbin "baserom.gba", 0x16BB204, 0x60
.global gKaoRayquaza
gKaoRayquaza:
.string "SIRO"
.4byte gUnknown_96BB584
.incbin "baserom.gba", 0x16BB26C, 0x8
.global gUnknown_96BB274
gUnknown_96BB274:
.incbin "baserom.gba", 0x16BB274, 0x40
.global gUnknown_96BB2B4
gUnknown_96BB2B4:
.string "AT4PX"
.incbin "baserom.gba", 0x16BB2B9, 0x2CB
.global gUnknown_96BB584
gUnknown_96BB584:
.4byte gUnknown_96BB274
.4byte gUnknown_96BB2B4
.incbin "baserom.gba", 0x16BB58C, 0x60
.global gKaoJirachi
gKaoJirachi:
.string "SIRO"
.4byte gUnknown_96BBB4C
.incbin "baserom.gba", 0x16BB5F4, 0x8
.global gUnknown_96BB5FC
gUnknown_96BB5FC:
.incbin "baserom.gba", 0x16BB5FC, 0x40
.global gUnknown_96BB63C
gUnknown_96BB63C:
.incbin "baserom.gba", 0x16BB63C, 0x250
.global gUnknown_96BB88C
gUnknown_96BB88C:
.incbin "baserom.gba", 0x16BB88C, 0x40
.global gUnknown_96BB8CC
gUnknown_96BB8CC:
.incbin "baserom.gba", 0x16BB8CC, 0x280
.global gUnknown_96BBB4C
gUnknown_96BBB4C:
.4byte gUnknown_96BB5FC
.4byte gUnknown_96BB63C
.4byte gUnknown_96BB88C
.4byte gUnknown_96BB8CC
.incbin "baserom.gba", 0x16BBB5C, 0x58
.global gKaoDeoxysNormal
gKaoDeoxysNormal:
.string "SIRO"
.4byte gUnknown_96BBE80
.incbin "baserom.gba", 0x16BBBBC, 0x8
.global gUnknown_96BBBC4
gUnknown_96BBBC4:
.incbin "baserom.gba", 0x16BBBC4, 0x40
.global gUnknown_96BBC04
gUnknown_96BBC04:
.string "AT4PX"
.incbin "baserom.gba", 0x16BBC09, 0x277
.global gUnknown_96BBE80
gUnknown_96BBE80:
.4byte gUnknown_96BBBC4
.4byte gUnknown_96BBC04
.incbin "baserom.gba", 0x16BBE88, 0x60
.global gKaoMunchlax
gKaoMunchlax:
.string "SIRO"
.4byte gUnknown_96BD03C
.incbin "baserom.gba", 0x16BBEF0, 0x8
.global gUnknown_96BBEF8
gUnknown_96BBEF8:
.incbin "baserom.gba", 0x16BBEF8, 0x40
.global gUnknown_96BBF38
gUnknown_96BBF38:
.string "AT4PX"
.incbin "baserom.gba", 0x16BBF3D, 0x293
.global gUnknown_96BC1D0
gUnknown_96BC1D0:
.incbin "baserom.gba", 0x16BC1D0, 0x40
.global gUnknown_96BC210
gUnknown_96BC210:
.string "AT4PX"
.incbin "baserom.gba", 0x16BC215, 0x2A3
.global gUnknown_96BC4B8
gUnknown_96BC4B8:
.incbin "baserom.gba", 0x16BC4B8, 0x40
.global gUnknown_96BC4F8
gUnknown_96BC4F8:
.string "AT4PX"
.incbin "baserom.gba", 0x16BC4FD, 0x2BF
.global gUnknown_96BC7BC
gUnknown_96BC7BC:
.incbin "baserom.gba", 0x16BC7BC, 0x40
.global gUnknown_96BC7FC
gUnknown_96BC7FC:
.incbin "baserom.gba", 0x16BC7FC, 0x284
.global gUnknown_96BCA80
gUnknown_96BCA80:
.incbin "baserom.gba", 0x16BCA80, 0x40
.global gUnknown_96BCAC0
gUnknown_96BCAC0:
.string "AT4PX"
.incbin "baserom.gba", 0x16BCAC5, 0x2AB
.global gUnknown_96BCD70
gUnknown_96BCD70:
.incbin "baserom.gba", 0x16BCD70, 0x40
.global gUnknown_96BCDB0
gUnknown_96BCDB0:
.string "AT4PX"
.incbin "baserom.gba", 0x16BCDB5, 0x287
.global gUnknown_96BD03C
gUnknown_96BD03C:
.4byte gUnknown_96BBEF8
.4byte gUnknown_96BBF38
.4byte gUnknown_96BC1D0
.4byte gUnknown_96BC210
.4byte gUnknown_96BC4B8
.4byte gUnknown_96BC4F8
.4byte gUnknown_96BC7BC
.4byte gUnknown_96BC7FC
.4byte gUnknown_96BCA80
.4byte gUnknown_96BCAC0
.4byte gUnknown_96BCD70
.4byte gUnknown_96BCDB0
.incbin "baserom.gba", 0x16BD06C, 0x38
.global gKaoRayquazaCutscene
gKaoRayquazaCutscene:
.string "SIRO"
.4byte gUnknown_96BD3C4
.incbin "baserom.gba", 0x16BD0AC, 0x8
.global gUnknown_96BD0B4
gUnknown_96BD0B4:
.incbin "baserom.gba", 0x16BD0B4, 0x40
.global gUnknown_96BD0F4
gUnknown_96BD0F4:
.string "AT4PX"
.incbin "baserom.gba", 0x16BD0F9, 0x2CB
.global gUnknown_96BD3C4
gUnknown_96BD3C4:
.4byte gUnknown_96BD0B4
.4byte gUnknown_96BD0F4
.incbin "baserom.gba", 0x16BD3CC, 0x60
.global gPaletFile
gPaletFile:
.incbin "baserom.gba", 0x16BD42C, 0x82BD4
