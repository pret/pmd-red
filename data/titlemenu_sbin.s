	.section .rodata

	.global gTitleMenuFileArchive
gTitleMenuFileArchive: @ 8380000
@ replacing	.incbin "baserom.gba", 0x380000, 0x22E74
.string "pksdir0\0"
.incbin "baserom.gba", 0x380008, 0x4
.4byte gUnknown_8380018
.string "pksdir0\0"
.global gUnknown_8380018
gUnknown_8380018:
.4byte gUnknown_8380190
.4byte gUnknown_83801A0
.4byte gUnknown_8380188
.4byte gUnknown_8380AB8
.4byte gUnknown_838017C
.4byte gUnknown_8382884
.4byte gUnknown_8380174
.4byte gUnknown_8382C04
.4byte gUnknown_838016C
.4byte gUnknown_8384914
.4byte gUnknown_8380164
.4byte gUnknown_8384C9C
.4byte gUnknown_8380158
.4byte gUnknown_8388AD0
.4byte gUnknown_8380150
.4byte gUnknown_8388E50
.4byte gUnknown_8380144
.4byte gUnknown_838CF98
.4byte gUnknown_838013C
.4byte gUnknown_838D318
.4byte gUnknown_8380130
.4byte gUnknown_8391C48
.4byte gUnknown_8380128
.4byte gUnknown_8391FC8
.4byte gUnknown_8380120
.4byte gUnknown_83923A0
.4byte gUnknown_8380114
.4byte gUnknown_8392638
.4byte gUnknown_8380108
.4byte gUnknown_8392B88
.4byte gUnknown_8380100
.4byte gUnknown_8398A9C
.4byte gUnknown_83800F8
.4byte gUnknown_8399F84
.4byte gUnknown_83800F0
.4byte gUnknown_839A304
.4byte gUnknown_83800E4
.4byte gUnknown_839B584
.4byte gUnknown_83800D8
.4byte gUnknown_839B814
.4byte gUnknown_83800D0
.4byte gUnknown_83A1574
.4byte gUnknown_83800C8
.4byte gUnknown_83A2AF4
.global gUnknown_83800C8
gUnknown_83800C8:
.incbin "baserom.gba", 0x3800C8, 0x8
.global gUnknown_83800D0
gUnknown_83800D0:
.incbin "baserom.gba", 0x3800D0, 0x8
.global gUnknown_83800D8
gUnknown_83800D8:
.incbin "baserom.gba", 0x3800D8, 0xC
.global gUnknown_83800E4
gUnknown_83800E4:
.incbin "baserom.gba", 0x3800E4, 0xC
.global gUnknown_83800F0
gUnknown_83800F0:
.incbin "baserom.gba", 0x3800F0, 0x8
.global gUnknown_83800F8
gUnknown_83800F8:
.incbin "baserom.gba", 0x3800F8, 0x8
.global gUnknown_8380100
gUnknown_8380100:
.incbin "baserom.gba", 0x380100, 0x8
.global gUnknown_8380108
gUnknown_8380108:
.incbin "baserom.gba", 0x380108, 0xC
.global gUnknown_8380114
gUnknown_8380114:
.incbin "baserom.gba", 0x380114, 0xC
.global gUnknown_8380120
gUnknown_8380120:
.incbin "baserom.gba", 0x380120, 0x8
.global gUnknown_8380128
gUnknown_8380128:
.incbin "baserom.gba", 0x380128, 0x8
.global gUnknown_8380130
gUnknown_8380130:
.incbin "baserom.gba", 0x380130, 0xC
.global gUnknown_838013C
gUnknown_838013C:
.incbin "baserom.gba", 0x38013C, 0x8
.global gUnknown_8380144
gUnknown_8380144:
.incbin "baserom.gba", 0x380144, 0xC
.global gUnknown_8380150
gUnknown_8380150:
.incbin "baserom.gba", 0x380150, 0x8
.global gUnknown_8380158
gUnknown_8380158:
.incbin "baserom.gba", 0x380158, 0xC
.global gUnknown_8380164
gUnknown_8380164:
.incbin "baserom.gba", 0x380164, 0x8
.global gUnknown_838016C
gUnknown_838016C:
.incbin "baserom.gba", 0x38016C, 0x8
.global gUnknown_8380174
gUnknown_8380174:
.incbin "baserom.gba", 0x380174, 0x8
.global gUnknown_838017C
gUnknown_838017C:
.incbin "baserom.gba", 0x38017C, 0xC
.global gUnknown_8380188
gUnknown_8380188:
.incbin "baserom.gba", 0x380188, 0x8
.global gUnknown_8380190
gUnknown_8380190:
.incbin "baserom.gba", 0x380190, 0x8
.string "pksdir0\0"
.global gUnknown_83801A0
gUnknown_83801A0:
.string "SIRO"
.4byte gUnknown_8380AB0
.incbin "baserom.gba", 0x3801A8, 0x8
.global gUnknown_83801B0
gUnknown_83801B0:
.incbin "baserom.gba", 0x3801B0, 0x800
.global gUnknown_83809B0
gUnknown_83809B0:
.incbin "baserom.gba", 0x3809B0, 0x100
.global gUnknown_8380AB0
gUnknown_8380AB0:
.4byte gUnknown_83801B0
.4byte gUnknown_83809B0
.global gUnknown_8380AB8
gUnknown_8380AB8:
.incbin "baserom.gba", 0x380AB8, 0x1DCC
.global gUnknown_8382884
gUnknown_8382884:
.incbin "baserom.gba", 0x382884, 0x380
.global gUnknown_8382C04
gUnknown_8382C04:
.incbin "baserom.gba", 0x382C04, 0x1D10
.global gUnknown_8384914
gUnknown_8384914:
.incbin "baserom.gba", 0x384914, 0x380
.string "pksdir0\0"
.global gUnknown_8384C9C
gUnknown_8384C9C:
.incbin "baserom.gba", 0x384C9C, 0x3E34
.global gUnknown_8388AD0
gUnknown_8388AD0:
.incbin "baserom.gba", 0x388AD0, 0x380
.global gUnknown_8388E50
gUnknown_8388E50:
.string "AT4PX"
.incbin "baserom.gba", 0x388E55, 0x4143
.global gUnknown_838CF98
gUnknown_838CF98:
.incbin "baserom.gba", 0x38CF98, 0x380
.global gUnknown_838D318
gUnknown_838D318:
.incbin "baserom.gba", 0x38D318, 0x4928
.string "pksdir0\0"
.global gUnknown_8391C48
gUnknown_8391C48:
.incbin "baserom.gba", 0x391C48, 0x380
.global gUnknown_8391FC8
gUnknown_8391FC8:
.string "SIRO"
.4byte gUnknown_8392398
.incbin "baserom.gba", 0x391FD0, 0x8
.global gUnknown_8391FD8
gUnknown_8391FD8:
.incbin "baserom.gba", 0x391FD8, 0x380
.global gUnknown_8392358
gUnknown_8392358:
.incbin "baserom.gba", 0x392358, 0x40
.global gUnknown_8392398
gUnknown_8392398:
.4byte gUnknown_8391FD8
.4byte gUnknown_8392358
.global gUnknown_83923A0
gUnknown_83923A0:
.string "SIRO"
.4byte gUnknown_8392630
.incbin "baserom.gba", 0x3923A8, 0x8
.global gUnknown_83923B0
gUnknown_83923B0:
.incbin "baserom.gba", 0x3923B0, 0x80
.global gUnknown_8392430
gUnknown_8392430:
.incbin "baserom.gba", 0x392430, 0x200
.global gUnknown_8392630
gUnknown_8392630:
.4byte gUnknown_83923B0
.4byte gUnknown_8392430
.global gUnknown_8392638
gUnknown_8392638:
.string "SIRO"
.4byte gUnknown_8392B48
.incbin "baserom.gba", 0x392640, 0x8
.global gUnknown_8392648
gUnknown_8392648:
.incbin "baserom.gba", 0x392648, 0x50
.global gUnknown_8392698
gUnknown_8392698:
.incbin "baserom.gba", 0x392698, 0x50
.global gUnknown_83926E8
gUnknown_83926E8:
.incbin "baserom.gba", 0x3926E8, 0x50
.global gUnknown_8392738
gUnknown_8392738:
.incbin "baserom.gba", 0x392738, 0x50
.global gUnknown_8392788
gUnknown_8392788:
.incbin "baserom.gba", 0x392788, 0x50
.global gUnknown_83927D8
gUnknown_83927D8:
.incbin "baserom.gba", 0x3927D8, 0x50
.global gUnknown_8392828
gUnknown_8392828:
.incbin "baserom.gba", 0x392828, 0x50
.global gUnknown_8392878
gUnknown_8392878:
.incbin "baserom.gba", 0x392878, 0x2D0
.global gUnknown_8392B48
gUnknown_8392B48:
.4byte gUnknown_8392648
.4byte gUnknown_8392698
.4byte gUnknown_83926E8
.4byte gUnknown_8392738
.4byte gUnknown_8392788
.4byte gUnknown_83927D8
.4byte gUnknown_8392828
.4byte gUnknown_8392878
.incbin "baserom.gba", 0x392B68, 0x20
.global gUnknown_8392B88
gUnknown_8392B88:
.incbin "baserom.gba", 0x392B88, 0x5F0C
.string "pksdir0\0"
.global gUnknown_8398A9C
gUnknown_8398A9C:
.incbin "baserom.gba", 0x398A9C, 0x4
.4byte gUnknown_8398AAC
.incbin "baserom.gba", 0x398AA4, 0x8
.global gUnknown_8398AAC
gUnknown_8398AAC:
.incbin "baserom.gba", 0x398AAC, 0x14D8
.global gUnknown_8399F84
gUnknown_8399F84:
.incbin "baserom.gba", 0x399F84, 0x380
.global gUnknown_839A304
gUnknown_839A304:
.string "SIRO"
.4byte gUnknown_839B564
.incbin "baserom.gba", 0x39A30C, 0x8
.global gUnknown_839A314
gUnknown_839A314:
.incbin "baserom.gba", 0x39A314, 0x14
.global gUnknown_839A328
gUnknown_839A328:
.incbin "baserom.gba", 0x39A328, 0x14
.global gUnknown_839A33C
gUnknown_839A33C:
.incbin "baserom.gba", 0x39A33C, 0x14
.global gUnknown_839A350
gUnknown_839A350:
.incbin "baserom.gba", 0x39A350, 0x14
.global gUnknown_839A364
gUnknown_839A364:
.incbin "baserom.gba", 0x39A364, 0x14
.global gUnknown_839A378
gUnknown_839A378:
.incbin "baserom.gba", 0x39A378, 0x14
.global gUnknown_839A38C
gUnknown_839A38C:
.incbin "baserom.gba", 0x39A38C, 0x14
.global gUnknown_839A3A0
gUnknown_839A3A0:
.incbin "baserom.gba", 0x39A3A0, 0x14
.global gUnknown_839A3B4
gUnknown_839A3B4:
.incbin "baserom.gba", 0x39A3B4, 0x14
.global gUnknown_839A3C8
gUnknown_839A3C8:
.incbin "baserom.gba", 0x39A3C8, 0x14
.global gUnknown_839A3DC
gUnknown_839A3DC:
.incbin "baserom.gba", 0x39A3DC, 0x14
.global gUnknown_839A3F0
gUnknown_839A3F0:
.incbin "baserom.gba", 0x39A3F0, 0x14
.global gUnknown_839A404
gUnknown_839A404:
.incbin "baserom.gba", 0x39A404, 0x14
.global gUnknown_839A418
gUnknown_839A418:
.incbin "baserom.gba", 0x39A418, 0x14
.global gUnknown_839A42C
gUnknown_839A42C:
.incbin "baserom.gba", 0x39A42C, 0x18
.global gUnknown_839A444
gUnknown_839A444:
.incbin "baserom.gba", 0x39A444, 0x30
.global gUnknown_839A474
gUnknown_839A474:
.incbin "baserom.gba", 0x39A474, 0x18
.global gUnknown_839A48C
gUnknown_839A48C:
.incbin "baserom.gba", 0x39A48C, 0x18
.global gUnknown_839A4A4
gUnknown_839A4A4:
.incbin "baserom.gba", 0x39A4A4, 0x18
.global gUnknown_839A4BC
gUnknown_839A4BC:
.incbin "baserom.gba", 0x39A4BC, 0x18
.global gUnknown_839A4D4
gUnknown_839A4D4:
.incbin "baserom.gba", 0x39A4D4, 0x18
.global gUnknown_839A4EC
gUnknown_839A4EC:
.incbin "baserom.gba", 0x39A4EC, 0x18
.global gUnknown_839A504
gUnknown_839A504:
.incbin "baserom.gba", 0x39A504, 0x18
.global gUnknown_839A51C
gUnknown_839A51C:
.incbin "baserom.gba", 0x39A51C, 0x18
.global gUnknown_839A534
gUnknown_839A534:
.incbin "baserom.gba", 0x39A534, 0x18
.global gUnknown_839A54C
gUnknown_839A54C:
.incbin "baserom.gba", 0x39A54C, 0x18
.global gUnknown_839A564
gUnknown_839A564:
.incbin "baserom.gba", 0x39A564, 0x18
.global gUnknown_839A57C
gUnknown_839A57C:
.incbin "baserom.gba", 0x39A57C, 0x18
.global gUnknown_839A594
gUnknown_839A594:
.incbin "baserom.gba", 0x39A594, 0xD80
.global gUnknown_839B314
gUnknown_839B314:
.incbin "baserom.gba", 0x39B314, 0x40
.global gUnknown_839B354
gUnknown_839B354:
.4byte gUnknown_839A314
.4byte gUnknown_839A328
.4byte gUnknown_839A33C
.4byte gUnknown_839A350
.4byte gUnknown_839A364
.4byte gUnknown_839A378
.4byte gUnknown_839A38C
.4byte gUnknown_839A3A0
.4byte gUnknown_839A3B4
.4byte gUnknown_839A3C8
.4byte gUnknown_839A3DC
.4byte gUnknown_839A3F0
.4byte gUnknown_839A404
.4byte gUnknown_839A418
.4byte gUnknown_839A42C
.global gUnknown_839B390
gUnknown_839B390:
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.4byte gUnknown_839A444
.global gUnknown_839B3B0
gUnknown_839B3B0:
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.4byte gUnknown_839A474
.global gUnknown_839B3D0
gUnknown_839B3D0:
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.4byte gUnknown_839A48C
.global gUnknown_839B3F0
gUnknown_839B3F0:
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.4byte gUnknown_839A4A4
.global gUnknown_839B410
gUnknown_839B410:
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.4byte gUnknown_839A4BC
.global gUnknown_839B430
gUnknown_839B430:
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.4byte gUnknown_839A4D4
.global gUnknown_839B450
gUnknown_839B450:
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.4byte gUnknown_839A4EC
.global gUnknown_839B470
gUnknown_839B470:
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.4byte gUnknown_839A504
.global gUnknown_839B490
gUnknown_839B490:
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.4byte gUnknown_839A51C
.global gUnknown_839B4B0
gUnknown_839B4B0:
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.4byte gUnknown_839A534
.global gUnknown_839B4D0
gUnknown_839B4D0:
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.4byte gUnknown_839A54C
.global gUnknown_839B4F0
gUnknown_839B4F0:
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.4byte gUnknown_839A564
.global gUnknown_839B510
gUnknown_839B510:
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.4byte gUnknown_839A57C
.global gUnknown_839B530
gUnknown_839B530:
.4byte gUnknown_839B390
.4byte gUnknown_839B3B0
.4byte gUnknown_839B3D0
.4byte gUnknown_839B3F0
.4byte gUnknown_839B410
.4byte gUnknown_839B430
.4byte gUnknown_839B450
.4byte gUnknown_839B470
.4byte gUnknown_839B490
.4byte gUnknown_839B4B0
.4byte gUnknown_839B4D0
.4byte gUnknown_839B4F0
.4byte gUnknown_839B510
.global gUnknown_839B564
gUnknown_839B564:
.4byte gUnknown_839B354
.4byte gUnknown_839B530
.incbin "baserom.gba", 0x39B56C, 0xC
.4byte gUnknown_839A594
.4byte gUnknown_839B314
.incbin "baserom.gba", 0x39B580, 0x4
.global gUnknown_839B584
gUnknown_839B584:
.string "SIRO"
.4byte gUnknown_839B7D4
.incbin "baserom.gba", 0x39B58C, 0x8
.global gUnknown_839B594
gUnknown_839B594:
.incbin "baserom.gba", 0x39B594, 0x24
.global gUnknown_839B5B8
gUnknown_839B5B8:
.incbin "baserom.gba", 0x39B5B8, 0x24
.global gUnknown_839B5DC
gUnknown_839B5DC:
.incbin "baserom.gba", 0x39B5DC, 0x24
.global gUnknown_839B600
gUnknown_839B600:
.incbin "baserom.gba", 0x39B600, 0x24
.global gUnknown_839B624
gUnknown_839B624:
.incbin "baserom.gba", 0x39B624, 0x24
.global gUnknown_839B648
gUnknown_839B648:
.incbin "baserom.gba", 0x39B648, 0x24
.global gUnknown_839B66C
gUnknown_839B66C:
.incbin "baserom.gba", 0x39B66C, 0x24
.global gUnknown_839B690
gUnknown_839B690:
.incbin "baserom.gba", 0x39B690, 0x144
.global gUnknown_839B7D4
gUnknown_839B7D4:
.4byte gUnknown_839B594
.4byte gUnknown_839B5B8
.4byte gUnknown_839B5DC
.4byte gUnknown_839B600
.4byte gUnknown_839B624
.4byte gUnknown_839B648
.4byte gUnknown_839B66C
.4byte gUnknown_839B690
.incbin "baserom.gba", 0x39B7F4, 0x20
.global gUnknown_839B814
gUnknown_839B814:
.incbin "baserom.gba", 0x39B814, 0x5D58
.string "pksdir0\0"
.global gUnknown_83A1574
gUnknown_83A1574:
.string "SIRO"
.4byte gUnknown_83A1584
.incbin "baserom.gba", 0x3A157C, 0x8
.global gUnknown_83A1584
gUnknown_83A1584:
.incbin "baserom.gba", 0x3A1584, 0x1570
.global gUnknown_83A2AF4
gUnknown_83A2AF4:
.incbin "baserom.gba", 0x3A2AF4, 0x380
