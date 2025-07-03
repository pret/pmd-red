	.section .rodata


.string "pksdir0\0"
.global gFlag113Pal
gFlag113Pal:
.incbin "graphics/ornament/pal/flag113.pmdpal"
.global gAxFlag113
gAxFlag113:
.string "SIRO"
.4byte sAxMainFlag113
.4byte 0, 0
.global sFlag113Pose1
sFlag113Pose1:
.incbin "baserom.gba", 0x1E709B8, 0x14
.global sFlag113Pose2
sFlag113Pose2:
.incbin "baserom.gba", 0x1E709CC, 0x14
.global sFlag113Pose3
sFlag113Pose3:
.incbin "baserom.gba", 0x1E709E0, 0x14
.global sFlag113Pose4
sFlag113Pose4:
.incbin "baserom.gba", 0x1E709F4, 0x14
.global sFlag113Pose5
sFlag113Pose5:
.incbin "baserom.gba", 0x1E70A08, 0x14
.global sFlag113Pose6
sFlag113Pose6:
.incbin "baserom.gba", 0x1E70A1C, 0x14
.global sFlag113Anims_1_1
sFlag113Anims_1_1:
.incbin "baserom.gba", 0x1E70A30, 0x54
.global sFlag113Gfx1
sFlag113Gfx1:
.incbin "baserom.gba", 0x1E70A84, 0x180
.global sFlag113Sprites1
sFlag113Sprites1:
.4byte sFlag113Gfx1
.incbin "baserom.gba", 0x1E70C08, 0x14
.global sFlag113Gfx2
sFlag113Gfx2:
.incbin "baserom.gba", 0x1E70C1C, 0x180
.global sFlag113Sprites2
sFlag113Sprites2:
.4byte sFlag113Gfx2
.incbin "baserom.gba", 0x1E70DA0, 0x14
.global sFlag113Gfx3
sFlag113Gfx3:
.incbin "baserom.gba", 0x1E70DB4, 0x180
.global sFlag113Sprites3
sFlag113Sprites3:
.4byte sFlag113Gfx3
.incbin "baserom.gba", 0x1E70F38, 0x14
.global sFlag113Gfx4
sFlag113Gfx4:
.incbin "baserom.gba", 0x1E70F4C, 0x180
.global sFlag113Sprites4
sFlag113Sprites4:
.4byte sFlag113Gfx4
.incbin "baserom.gba", 0x1E710D0, 0x14
.global sFlag113Gfx5
sFlag113Gfx5:
.incbin "baserom.gba", 0x1E710E4, 0x180
.global sFlag113Sprites5
sFlag113Sprites5:
.4byte sFlag113Gfx5
.incbin "baserom.gba", 0x1E71268, 0x14
.global sFlag113Gfx6
sFlag113Gfx6:
.incbin "baserom.gba", 0x1E7127C, 0x180
.global sFlag113Sprites6
sFlag113Sprites6:
.4byte sFlag113Gfx6
.incbin "baserom.gba", 0x1E71400, 0x14
.global sAxPosesFlag113
sAxPosesFlag113:
.4byte sFlag113Pose1
.4byte sFlag113Pose2
.4byte sFlag113Pose3
.4byte sFlag113Pose4
.4byte sFlag113Pose5
.4byte sFlag113Pose6
.global sFlag113AnimTable1
sFlag113AnimTable1:
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.4byte sFlag113Anims_1_1
.global sAxAnimationsFlag113
sAxAnimationsFlag113:
.4byte sFlag113AnimTable1
.global sAxSpritesFlag113
sAxSpritesFlag113:
.4byte sFlag113Sprites1
.4byte sFlag113Sprites2
.4byte sFlag113Sprites3
.4byte sFlag113Sprites4
.4byte sFlag113Sprites5
.4byte sFlag113Sprites6
.global sAxMainFlag113
sAxMainFlag113:
.4byte sAxPosesFlag113
.4byte sAxAnimationsFlag113
.incbin "baserom.gba", 0x1E71470, 0x4
.4byte sAxSpritesFlag113
.4byte 0
.global gFlag114Pal
gFlag114Pal:
.incbin "graphics/ornament/pal/flag114.pmdpal"
.global gAxFlag114
gAxFlag114:
.string "SIRO"
.4byte sAxMainFlag114
.4byte 0, 0
.global sFlag114Pose1
sFlag114Pose1:
.incbin "baserom.gba", 0x1E714CC, 0x14
.global sFlag114Pose2
sFlag114Pose2:
.incbin "baserom.gba", 0x1E714E0, 0x14
.global sFlag114Pose3
sFlag114Pose3:
.incbin "baserom.gba", 0x1E714F4, 0x14
.global sFlag114Pose4
sFlag114Pose4:
.incbin "baserom.gba", 0x1E71508, 0x14
.global sFlag114Pose5
sFlag114Pose5:
.incbin "baserom.gba", 0x1E7151C, 0x14
.global sFlag114Pose6
sFlag114Pose6:
.incbin "baserom.gba", 0x1E71530, 0x14
.global sFlag114Anims_1_1
sFlag114Anims_1_1:
.incbin "baserom.gba", 0x1E71544, 0x54
.global sFlag114Gfx1
sFlag114Gfx1:
.incbin "baserom.gba", 0x1E71598, 0x180
.global sFlag114Sprites1
sFlag114Sprites1:
.4byte sFlag114Gfx1
.incbin "baserom.gba", 0x1E7171C, 0x14
.global sFlag114Gfx2
sFlag114Gfx2:
.incbin "baserom.gba", 0x1E71730, 0x180
.global sFlag114Sprites2
sFlag114Sprites2:
.4byte sFlag114Gfx2
.incbin "baserom.gba", 0x1E718B4, 0x14
.global sFlag114Gfx3
sFlag114Gfx3:
.incbin "baserom.gba", 0x1E718C8, 0x180
.global sFlag114Sprites3
sFlag114Sprites3:
.4byte sFlag114Gfx3
.incbin "baserom.gba", 0x1E71A4C, 0x14
.global sFlag114Gfx4
sFlag114Gfx4:
.incbin "baserom.gba", 0x1E71A60, 0x180
.global sFlag114Sprites4
sFlag114Sprites4:
.4byte sFlag114Gfx4
.incbin "baserom.gba", 0x1E71BE4, 0x14
.global sFlag114Gfx5
sFlag114Gfx5:
.incbin "baserom.gba", 0x1E71BF8, 0x180
.global sFlag114Sprites5
sFlag114Sprites5:
.4byte sFlag114Gfx5
.incbin "baserom.gba", 0x1E71D7C, 0x14
.global sFlag114Gfx6
sFlag114Gfx6:
.incbin "baserom.gba", 0x1E71D90, 0x180
.global sFlag114Sprites6
sFlag114Sprites6:
.4byte sFlag114Gfx6
.incbin "baserom.gba", 0x1E71F14, 0x14
.global sAxPosesFlag114
sAxPosesFlag114:
.4byte sFlag114Pose1
.4byte sFlag114Pose2
.4byte sFlag114Pose3
.4byte sFlag114Pose4
.4byte sFlag114Pose5
.4byte sFlag114Pose6
.global sFlag114AnimTable1
sFlag114AnimTable1:
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.4byte sFlag114Anims_1_1
.global sAxAnimationsFlag114
sAxAnimationsFlag114:
.4byte sFlag114AnimTable1
.global sAxSpritesFlag114
sAxSpritesFlag114:
.4byte sFlag114Sprites1
.4byte sFlag114Sprites2
.4byte sFlag114Sprites3
.4byte sFlag114Sprites4
.4byte sFlag114Sprites5
.4byte sFlag114Sprites6
.global sAxMainFlag114
sAxMainFlag114:
.4byte sAxPosesFlag114
.4byte sAxAnimationsFlag114
.incbin "baserom.gba", 0x1E71F84, 0x4
.4byte sAxSpritesFlag114
.4byte 0
.global gFlag11Pal
gFlag11Pal:
.incbin "graphics/ornament/pal/flag11.pmdpal"
.global gAxFlag11
gAxFlag11:
.string "SIRO"
.4byte sAxMainFlag11
.4byte 0, 0
.global sFlag11Pose1
sFlag11Pose1:
.incbin "baserom.gba", 0x1E71FE0, 0x14
.global sFlag11Pose2
sFlag11Pose2:
.incbin "baserom.gba", 0x1E71FF4, 0x14
.global sFlag11Pose3
sFlag11Pose3:
.incbin "baserom.gba", 0x1E72008, 0x14
.global sFlag11Pose4
sFlag11Pose4:
.incbin "baserom.gba", 0x1E7201C, 0x14
.global sFlag11Pose5
sFlag11Pose5:
.incbin "baserom.gba", 0x1E72030, 0x14
.global sFlag11Pose6
sFlag11Pose6:
.incbin "baserom.gba", 0x1E72044, 0x14
.global sFlag11Anims_1_1
sFlag11Anims_1_1:
.incbin "baserom.gba", 0x1E72058, 0x54
.global sFlag11Gfx1
sFlag11Gfx1:
.incbin "baserom.gba", 0x1E720AC, 0x180
.global sFlag11Sprites1
sFlag11Sprites1:
.4byte sFlag11Gfx1
.incbin "baserom.gba", 0x1E72230, 0x14
.global sFlag11Gfx2
sFlag11Gfx2:
.incbin "baserom.gba", 0x1E72244, 0x180
.global sFlag11Sprites2
sFlag11Sprites2:
.4byte sFlag11Gfx2
.incbin "baserom.gba", 0x1E723C8, 0x14
.global sFlag11Gfx3
sFlag11Gfx3:
.incbin "baserom.gba", 0x1E723DC, 0x180
.global sFlag11Sprites3
sFlag11Sprites3:
.4byte sFlag11Gfx3
.incbin "baserom.gba", 0x1E72560, 0x14
.global sFlag11Gfx4
sFlag11Gfx4:
.incbin "baserom.gba", 0x1E72574, 0x180
.global sFlag11Sprites4
sFlag11Sprites4:
.4byte sFlag11Gfx4
.incbin "baserom.gba", 0x1E726F8, 0x14
.global sFlag11Gfx5
sFlag11Gfx5:
.incbin "baserom.gba", 0x1E7270C, 0x180
.global sFlag11Sprites5
sFlag11Sprites5:
.4byte sFlag11Gfx5
.incbin "baserom.gba", 0x1E72890, 0x14
.global sFlag11Gfx6
sFlag11Gfx6:
.incbin "baserom.gba", 0x1E728A4, 0x180
.global sFlag11Sprites6
sFlag11Sprites6:
.4byte sFlag11Gfx6
.incbin "baserom.gba", 0x1E72A28, 0x14
.global sAxPosesFlag11
sAxPosesFlag11:
.4byte sFlag11Pose1
.4byte sFlag11Pose2
.4byte sFlag11Pose3
.4byte sFlag11Pose4
.4byte sFlag11Pose5
.4byte sFlag11Pose6
.global sFlag11AnimTable1
sFlag11AnimTable1:
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.4byte sFlag11Anims_1_1
.global sAxAnimationsFlag11
sAxAnimationsFlag11:
.4byte sFlag11AnimTable1
.global sAxSpritesFlag11
sAxSpritesFlag11:
.4byte sFlag11Sprites1
.4byte sFlag11Sprites2
.4byte sFlag11Sprites3
.4byte sFlag11Sprites4
.4byte sFlag11Sprites5
.4byte sFlag11Sprites6
.global sAxMainFlag11
sAxMainFlag11:
.4byte sAxPosesFlag11
.4byte sAxAnimationsFlag11
.incbin "baserom.gba", 0x1E72A98, 0x4
.4byte sAxSpritesFlag11
.4byte 0
.global gFlag12Pal
gFlag12Pal:
.incbin "graphics/ornament/pal/flag12.pmdpal"
.global gAxFlag12
gAxFlag12:
.string "SIRO"
.4byte sAxMainFlag12
.4byte 0, 0
.global sFlag12Pose1
sFlag12Pose1:
.incbin "baserom.gba", 0x1E72AF4, 0x14
.global sFlag12Pose2
sFlag12Pose2:
.incbin "baserom.gba", 0x1E72B08, 0x14
.global sFlag12Pose3
sFlag12Pose3:
.incbin "baserom.gba", 0x1E72B1C, 0x14
.global sFlag12Pose4
sFlag12Pose4:
.incbin "baserom.gba", 0x1E72B30, 0x14
.global sFlag12Pose5
sFlag12Pose5:
.incbin "baserom.gba", 0x1E72B44, 0x14
.global sFlag12Pose6
sFlag12Pose6:
.incbin "baserom.gba", 0x1E72B58, 0x14
.global sFlag12Anims_1_1
sFlag12Anims_1_1:
.incbin "baserom.gba", 0x1E72B6C, 0x54
.global sFlag12Gfx1
sFlag12Gfx1:
.incbin "baserom.gba", 0x1E72BC0, 0x180
.global sFlag12Sprites1
sFlag12Sprites1:
.4byte sFlag12Gfx1
.incbin "baserom.gba", 0x1E72D44, 0x14
.global sFlag12Gfx2
sFlag12Gfx2:
.incbin "baserom.gba", 0x1E72D58, 0x180
.global sFlag12Sprites2
sFlag12Sprites2:
.4byte sFlag12Gfx2
.incbin "baserom.gba", 0x1E72EDC, 0x14
.global sFlag12Gfx3
sFlag12Gfx3:
.incbin "baserom.gba", 0x1E72EF0, 0x180
.global sFlag12Sprites3
sFlag12Sprites3:
.4byte sFlag12Gfx3
.incbin "baserom.gba", 0x1E73074, 0x14
.global sFlag12Gfx4
sFlag12Gfx4:
.incbin "baserom.gba", 0x1E73088, 0x180
.global sFlag12Sprites4
sFlag12Sprites4:
.4byte sFlag12Gfx4
.incbin "baserom.gba", 0x1E7320C, 0x14
.global sFlag12Gfx5
sFlag12Gfx5:
.incbin "baserom.gba", 0x1E73220, 0x180
.global sFlag12Sprites5
sFlag12Sprites5:
.4byte sFlag12Gfx5
.incbin "baserom.gba", 0x1E733A4, 0x14
.global sFlag12Gfx6
sFlag12Gfx6:
.incbin "baserom.gba", 0x1E733B8, 0x180
.global sFlag12Sprites6
sFlag12Sprites6:
.4byte sFlag12Gfx6
.incbin "baserom.gba", 0x1E7353C, 0x14
.global sAxPosesFlag12
sAxPosesFlag12:
.4byte sFlag12Pose1
.4byte sFlag12Pose2
.4byte sFlag12Pose3
.4byte sFlag12Pose4
.4byte sFlag12Pose5
.4byte sFlag12Pose6
.global sFlag12AnimTable1
sFlag12AnimTable1:
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.4byte sFlag12Anims_1_1
.global sAxAnimationsFlag12
sAxAnimationsFlag12:
.4byte sFlag12AnimTable1
.global sAxSpritesFlag12
sAxSpritesFlag12:
.4byte sFlag12Sprites1
.4byte sFlag12Sprites2
.4byte sFlag12Sprites3
.4byte sFlag12Sprites4
.4byte sFlag12Sprites5
.4byte sFlag12Sprites6
.global sAxMainFlag12
sAxMainFlag12:
.4byte sAxPosesFlag12
.4byte sAxAnimationsFlag12
.incbin "baserom.gba", 0x1E735AC, 0x4
.4byte sAxSpritesFlag12
.4byte 0
.global gFlag13Pal
gFlag13Pal:
.incbin "graphics/ornament/pal/flag13.pmdpal"
.global gAxFlag13
gAxFlag13:
.string "SIRO"
.4byte sAxMainFlag13
.4byte 0, 0
.global sFlag13Pose1
sFlag13Pose1:
.incbin "baserom.gba", 0x1E73608, 0x14
.global sFlag13Pose2
sFlag13Pose2:
.incbin "baserom.gba", 0x1E7361C, 0x14
.global sFlag13Pose3
sFlag13Pose3:
.incbin "baserom.gba", 0x1E73630, 0x14
.global sFlag13Pose4
sFlag13Pose4:
.incbin "baserom.gba", 0x1E73644, 0x14
.global sFlag13Pose5
sFlag13Pose5:
.incbin "baserom.gba", 0x1E73658, 0x14
.global sFlag13Pose6
sFlag13Pose6:
.incbin "baserom.gba", 0x1E7366C, 0x14
.global sFlag13Anims_1_1
sFlag13Anims_1_1:
.incbin "baserom.gba", 0x1E73680, 0x54
.global sFlag13Gfx1
sFlag13Gfx1:
.incbin "baserom.gba", 0x1E736D4, 0x180
.global sFlag13Sprites1
sFlag13Sprites1:
.4byte sFlag13Gfx1
.incbin "baserom.gba", 0x1E73858, 0x14
.global sFlag13Gfx2
sFlag13Gfx2:
.incbin "baserom.gba", 0x1E7386C, 0x180
.global sFlag13Sprites2
sFlag13Sprites2:
.4byte sFlag13Gfx2
.incbin "baserom.gba", 0x1E739F0, 0x14
.global sFlag13Gfx3
sFlag13Gfx3:
.incbin "baserom.gba", 0x1E73A04, 0x180
.global sFlag13Sprites3
sFlag13Sprites3:
.4byte sFlag13Gfx3
.incbin "baserom.gba", 0x1E73B88, 0x14
.global sFlag13Gfx4
sFlag13Gfx4:
.incbin "baserom.gba", 0x1E73B9C, 0x180
.global sFlag13Sprites4
sFlag13Sprites4:
.4byte sFlag13Gfx4
.incbin "baserom.gba", 0x1E73D20, 0x14
.global sFlag13Gfx5
sFlag13Gfx5:
.incbin "baserom.gba", 0x1E73D34, 0x180
.global sFlag13Sprites5
sFlag13Sprites5:
.4byte sFlag13Gfx5
.incbin "baserom.gba", 0x1E73EB8, 0x14
.global sFlag13Gfx6
sFlag13Gfx6:
.incbin "baserom.gba", 0x1E73ECC, 0x180
.global sFlag13Sprites6
sFlag13Sprites6:
.4byte sFlag13Gfx6
.incbin "baserom.gba", 0x1E74050, 0x14
.global sAxPosesFlag13
sAxPosesFlag13:
.4byte sFlag13Pose1
.4byte sFlag13Pose2
.4byte sFlag13Pose3
.4byte sFlag13Pose4
.4byte sFlag13Pose5
.4byte sFlag13Pose6
.global sFlag13AnimTable1
sFlag13AnimTable1:
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.4byte sFlag13Anims_1_1
.global sAxAnimationsFlag13
sAxAnimationsFlag13:
.4byte sFlag13AnimTable1
.global sAxSpritesFlag13
sAxSpritesFlag13:
.4byte sFlag13Sprites1
.4byte sFlag13Sprites2
.4byte sFlag13Sprites3
.4byte sFlag13Sprites4
.4byte sFlag13Sprites5
.4byte sFlag13Sprites6
.global sAxMainFlag13
sAxMainFlag13:
.4byte sAxPosesFlag13
.4byte sAxAnimationsFlag13
.incbin "baserom.gba", 0x1E740C0, 0x4
.4byte sAxSpritesFlag13
.4byte 0
.global gFlag14Pal
gFlag14Pal:
.incbin "graphics/ornament/pal/flag14.pmdpal"
.global gAxFlag14
gAxFlag14:
.string "SIRO"
.4byte sAxMainFlag14
.4byte 0, 0
.global sFlag14Pose1
sFlag14Pose1:
.incbin "baserom.gba", 0x1E7411C, 0x14
.global sFlag14Pose2
sFlag14Pose2:
.incbin "baserom.gba", 0x1E74130, 0x14
.global sFlag14Pose3
sFlag14Pose3:
.incbin "baserom.gba", 0x1E74144, 0x14
.global sFlag14Pose4
sFlag14Pose4:
.incbin "baserom.gba", 0x1E74158, 0x14
.global sFlag14Pose5
sFlag14Pose5:
.incbin "baserom.gba", 0x1E7416C, 0x14
.global sFlag14Pose6
sFlag14Pose6:
.incbin "baserom.gba", 0x1E74180, 0x14
.global sFlag14Anims_1_1
sFlag14Anims_1_1:
.incbin "baserom.gba", 0x1E74194, 0x54
.global sFlag14Gfx1
sFlag14Gfx1:
.incbin "baserom.gba", 0x1E741E8, 0x160
.global sFlag14Sprites1
sFlag14Sprites1:
.4byte sFlag14Gfx1
.incbin "baserom.gba", 0x1E7434C, 0x14
.global sFlag14Gfx2
sFlag14Gfx2:
.incbin "baserom.gba", 0x1E74360, 0x60
.global sFlag14Gfx2_2
sFlag14Gfx2_2:
.incbin "baserom.gba", 0x1E743C0, 0xE0
.global sFlag14Sprites2
sFlag14Sprites2:
.4byte sFlag14Gfx2
.incbin "baserom.gba", 0x1E744A4, 0xC
.4byte sFlag14Gfx2_2
.incbin "baserom.gba", 0x1E744B4, 0x14
.global sFlag14Gfx3
sFlag14Gfx3:
.incbin "baserom.gba", 0x1E744C8, 0x60
.global sFlag14Gfx3_2
sFlag14Gfx3_2:
.incbin "baserom.gba", 0x1E74528, 0x100
.global sFlag14Sprites3
sFlag14Sprites3:
.4byte sFlag14Gfx3
.incbin "baserom.gba", 0x1E7462C, 0xC
.4byte sFlag14Gfx3_2
.incbin "baserom.gba", 0x1E7463C, 0x14
.global sFlag14Gfx4
sFlag14Gfx4:
.incbin "baserom.gba", 0x1E74650, 0x60
.global sFlag14Gfx4_2
sFlag14Gfx4_2:
.incbin "baserom.gba", 0x1E746B0, 0x100
.global sFlag14Sprites4
sFlag14Sprites4:
.4byte sFlag14Gfx4
.incbin "baserom.gba", 0x1E747B4, 0xC
.4byte sFlag14Gfx4_2
.incbin "baserom.gba", 0x1E747C4, 0x14
.global sFlag14Gfx5
sFlag14Gfx5:
.incbin "baserom.gba", 0x1E747D8, 0x60
.global sFlag14Gfx5_2
sFlag14Gfx5_2:
.incbin "baserom.gba", 0x1E74838, 0x100
.global sFlag14Sprites5
sFlag14Sprites5:
.4byte sFlag14Gfx5
.incbin "baserom.gba", 0x1E7493C, 0xC
.4byte sFlag14Gfx5_2
.incbin "baserom.gba", 0x1E7494C, 0x14
.global sFlag14Gfx6
sFlag14Gfx6:
.incbin "baserom.gba", 0x1E74960, 0x160
.global sFlag14Sprites6
sFlag14Sprites6:
.4byte sFlag14Gfx6
.incbin "baserom.gba", 0x1E74AC4, 0x14
.global sAxPosesFlag14
sAxPosesFlag14:
.4byte sFlag14Pose1
.4byte sFlag14Pose2
.4byte sFlag14Pose3
.4byte sFlag14Pose4
.4byte sFlag14Pose5
.4byte sFlag14Pose6
.global sFlag14AnimTable1
sFlag14AnimTable1:
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.4byte sFlag14Anims_1_1
.global sAxAnimationsFlag14
sAxAnimationsFlag14:
.4byte sFlag14AnimTable1
.global sAxSpritesFlag14
sAxSpritesFlag14:
.4byte sFlag14Sprites1
.4byte sFlag14Sprites2
.4byte sFlag14Sprites3
.4byte sFlag14Sprites4
.4byte sFlag14Sprites5
.4byte sFlag14Sprites6
.global sAxMainFlag14
sAxMainFlag14:
.4byte sAxPosesFlag14
.4byte sAxAnimationsFlag14
.incbin "baserom.gba", 0x1E74B34, 0x4
.4byte sAxSpritesFlag14
.4byte 0
.global gFlag15Pal
gFlag15Pal:
.incbin "graphics/ornament/pal/flag15.pmdpal"
.global gAxFlag15
gAxFlag15:
.string "SIRO"
.4byte sAxMainFlag15
.4byte 0, 0
.global sFlag15Pose1
sFlag15Pose1:
.incbin "baserom.gba", 0x1E74B90, 0x14
.global sFlag15Pose2
sFlag15Pose2:
.incbin "baserom.gba", 0x1E74BA4, 0x14
.global sFlag15Pose3
sFlag15Pose3:
.incbin "baserom.gba", 0x1E74BB8, 0x14
.global sFlag15Pose4
sFlag15Pose4:
.incbin "baserom.gba", 0x1E74BCC, 0x14
.global sFlag15Pose5
sFlag15Pose5:
.incbin "baserom.gba", 0x1E74BE0, 0x14
.global sFlag15Pose6
sFlag15Pose6:
.incbin "baserom.gba", 0x1E74BF4, 0x14
.global sFlag15Anims_1_1
sFlag15Anims_1_1:
.incbin "baserom.gba", 0x1E74C08, 0x54
.global sFlag15Gfx1
sFlag15Gfx1:
.incbin "baserom.gba", 0x1E74C5C, 0x180
.global sFlag15Sprites1
sFlag15Sprites1:
.4byte sFlag15Gfx1
.incbin "baserom.gba", 0x1E74DE0, 0x14
.global sFlag15Gfx2
sFlag15Gfx2:
.incbin "baserom.gba", 0x1E74DF4, 0x180
.global sFlag15Sprites2
sFlag15Sprites2:
.4byte sFlag15Gfx2
.incbin "baserom.gba", 0x1E74F78, 0x14
.global sFlag15Gfx3
sFlag15Gfx3:
.incbin "baserom.gba", 0x1E74F8C, 0x180
.global sFlag15Sprites3
sFlag15Sprites3:
.4byte sFlag15Gfx3
.incbin "baserom.gba", 0x1E75110, 0x14
.global sFlag15Gfx4
sFlag15Gfx4:
.incbin "baserom.gba", 0x1E75124, 0x180
.global sFlag15Sprites4
sFlag15Sprites4:
.4byte sFlag15Gfx4
.incbin "baserom.gba", 0x1E752A8, 0x14
.global sFlag15Gfx5
sFlag15Gfx5:
.incbin "baserom.gba", 0x1E752BC, 0x180
.global sFlag15Sprites5
sFlag15Sprites5:
.4byte sFlag15Gfx5
.incbin "baserom.gba", 0x1E75440, 0x14
.global sFlag15Gfx6
sFlag15Gfx6:
.incbin "baserom.gba", 0x1E75454, 0x180
.global sFlag15Sprites6
sFlag15Sprites6:
.4byte sFlag15Gfx6
.incbin "baserom.gba", 0x1E755D8, 0x14
.global sAxPosesFlag15
sAxPosesFlag15:
.4byte sFlag15Pose1
.4byte sFlag15Pose2
.4byte sFlag15Pose3
.4byte sFlag15Pose4
.4byte sFlag15Pose5
.4byte sFlag15Pose6
.global sFlag15AnimTable1
sFlag15AnimTable1:
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.4byte sFlag15Anims_1_1
.global sAxAnimationsFlag15
sAxAnimationsFlag15:
.4byte sFlag15AnimTable1
.global sAxSpritesFlag15
sAxSpritesFlag15:
.4byte sFlag15Sprites1
.4byte sFlag15Sprites2
.4byte sFlag15Sprites3
.4byte sFlag15Sprites4
.4byte sFlag15Sprites5
.4byte sFlag15Sprites6
.global sAxMainFlag15
sAxMainFlag15:
.4byte sAxPosesFlag15
.4byte sAxAnimationsFlag15
.incbin "baserom.gba", 0x1E75648, 0x4
.4byte sAxSpritesFlag15
.4byte 0
.global gFlag16Pal
gFlag16Pal:
.incbin "graphics/ornament/pal/flag16.pmdpal"
.global gAxFlag16
gAxFlag16:
.string "SIRO"
.4byte sAxMainFlag16
.4byte 0, 0
.global sFlag16Pose1
sFlag16Pose1:
.incbin "baserom.gba", 0x1E756A4, 0x14
.global sFlag16Pose2
sFlag16Pose2:
.incbin "baserom.gba", 0x1E756B8, 0x14
.global sFlag16Pose3
sFlag16Pose3:
.incbin "baserom.gba", 0x1E756CC, 0x14
.global sFlag16Pose4
sFlag16Pose4:
.incbin "baserom.gba", 0x1E756E0, 0x14
.global sFlag16Pose5
sFlag16Pose5:
.incbin "baserom.gba", 0x1E756F4, 0x14
.global sFlag16Pose6
sFlag16Pose6:
.incbin "baserom.gba", 0x1E75708, 0x14
.global sFlag16Anims_1_1
sFlag16Anims_1_1:
.incbin "baserom.gba", 0x1E7571C, 0x54
.global sFlag16Gfx1
sFlag16Gfx1:
.incbin "baserom.gba", 0x1E75770, 0x180
.global sFlag16Sprites1
sFlag16Sprites1:
.4byte sFlag16Gfx1
.incbin "baserom.gba", 0x1E758F4, 0x14
.global sFlag16Gfx2
sFlag16Gfx2:
.incbin "baserom.gba", 0x1E75908, 0x180
.global sFlag16Sprites2
sFlag16Sprites2:
.4byte sFlag16Gfx2
.incbin "baserom.gba", 0x1E75A8C, 0x14
.global sFlag16Gfx3
sFlag16Gfx3:
.incbin "baserom.gba", 0x1E75AA0, 0x180
.global sFlag16Sprites3
sFlag16Sprites3:
.4byte sFlag16Gfx3
.incbin "baserom.gba", 0x1E75C24, 0x14
.global sFlag16Gfx4
sFlag16Gfx4:
.incbin "baserom.gba", 0x1E75C38, 0x180
.global sFlag16Sprites4
sFlag16Sprites4:
.4byte sFlag16Gfx4
.incbin "baserom.gba", 0x1E75DBC, 0x14
.global sFlag16Gfx5
sFlag16Gfx5:
.incbin "baserom.gba", 0x1E75DD0, 0x180
.global sFlag16Sprites5
sFlag16Sprites5:
.4byte sFlag16Gfx5
.incbin "baserom.gba", 0x1E75F54, 0x14
.global sFlag16Gfx6
sFlag16Gfx6:
.incbin "baserom.gba", 0x1E75F68, 0x180
.global sFlag16Sprites6
sFlag16Sprites6:
.4byte sFlag16Gfx6
.incbin "baserom.gba", 0x1E760EC, 0x14
.global sAxPosesFlag16
sAxPosesFlag16:
.4byte sFlag16Pose1
.4byte sFlag16Pose2
.4byte sFlag16Pose3
.4byte sFlag16Pose4
.4byte sFlag16Pose5
.4byte sFlag16Pose6
.global sFlag16AnimTable1
sFlag16AnimTable1:
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.4byte sFlag16Anims_1_1
.global sAxAnimationsFlag16
sAxAnimationsFlag16:
.4byte sFlag16AnimTable1
.global sAxSpritesFlag16
sAxSpritesFlag16:
.4byte sFlag16Sprites1
.4byte sFlag16Sprites2
.4byte sFlag16Sprites3
.4byte sFlag16Sprites4
.4byte sFlag16Sprites5
.4byte sFlag16Sprites6
.global sAxMainFlag16
sAxMainFlag16:
.4byte sAxPosesFlag16
.4byte sAxAnimationsFlag16
.incbin "baserom.gba", 0x1E7615C, 0x4
.4byte sAxSpritesFlag16
.4byte 0
.string"pksdir0\0"
.global gAxItem01
gAxItem01:
.string "SIRO"
.4byte sAxMainItem01
.4byte 0, 0
.global sItem01Pose1
sItem01Pose1:
.incbin "baserom.gba", 0x1E76180, 0x14
.global sItem01Pose2
sItem01Pose2:
.incbin "baserom.gba", 0x1E76194, 0x14
.global sItem01Pose3
sItem01Pose3:
.incbin "baserom.gba", 0x1E761A8, 0x14
.global sItem01Pose4
sItem01Pose4:
.incbin "baserom.gba", 0x1E761BC, 0x14
.global sItem01Pose5
sItem01Pose5:
.incbin "baserom.gba", 0x1E761D0, 0x14
.global sItem01Pose6
sItem01Pose6:
.incbin "baserom.gba", 0x1E761E4, 0x14
.global sItem01Pose7
sItem01Pose7:
.incbin "baserom.gba", 0x1E761F8, 0x14
.global sItem01Pose8
sItem01Pose8:
.incbin "baserom.gba", 0x1E7620C, 0x14
.global sItem01Pose9
sItem01Pose9:
.incbin "baserom.gba", 0x1E76220, 0x14
.global sItem01Pose10
sItem01Pose10:
.incbin "baserom.gba", 0x1E76234, 0x14
.global sItem01Pose11
sItem01Pose11:
.incbin "baserom.gba", 0x1E76248, 0x14
.global sItem01Pose12
sItem01Pose12:
.incbin "baserom.gba", 0x1E7625C, 0x14
.global sItem01Pose13
sItem01Pose13:
.incbin "baserom.gba", 0x1E76270, 0x14
.global sItem01Pose14
sItem01Pose14:
.incbin "baserom.gba", 0x1E76284, 0x14
.global sItem01Pose15
sItem01Pose15:
.incbin "baserom.gba", 0x1E76298, 0x14
.global sItem01Pose16
sItem01Pose16:
.incbin "baserom.gba", 0x1E762AC, 0x14
.global sItem01Pose17
sItem01Pose17:
.incbin "baserom.gba", 0x1E762C0, 0x14
.global sItem01Pose18
sItem01Pose18:
.incbin "baserom.gba", 0x1E762D4, 0x14
.global sItem01Pose19
sItem01Pose19:
.incbin "baserom.gba", 0x1E762E8, 0x14
.global sItem01Pose20
sItem01Pose20:
.incbin "baserom.gba", 0x1E762FC, 0x14
.global sItem01Pose21
sItem01Pose21:
.incbin "baserom.gba", 0x1E76310, 0x14
.global sItem01Pose22
sItem01Pose22:
.incbin "baserom.gba", 0x1E76324, 0x14
.global sItem01Pose23
sItem01Pose23:
.incbin "baserom.gba", 0x1E76338, 0x14
.global sItem01Pose24
sItem01Pose24:
.incbin "baserom.gba", 0x1E7634C, 0x14
.global sItem01Anims_1_1
sItem01Anims_1_1:
.incbin "baserom.gba", 0x1E76360, 0x18
.global sItem01Anims_1_2
sItem01Anims_1_2:
.incbin "baserom.gba", 0x1E76378, 0x18
.global sItem01Anims_1_3
sItem01Anims_1_3:
.incbin "baserom.gba", 0x1E76390, 0x18
.global sItem01Anims_1_4
sItem01Anims_1_4:
.incbin "baserom.gba", 0x1E763A8, 0x18
.global sItem01Anims_1_5
sItem01Anims_1_5:
.incbin "baserom.gba", 0x1E763C0, 0x18
.global sItem01Anims_1_6
sItem01Anims_1_6:
.incbin "baserom.gba", 0x1E763D8, 0x18
.global sItem01Anims_1_7
sItem01Anims_1_7:
.incbin "baserom.gba", 0x1E763F0, 0x18
.global sItem01Anims_1_8
sItem01Anims_1_8:
.incbin "baserom.gba", 0x1E76408, 0x18
.global sItem01Gfx1
sItem01Gfx1:
.incbin "baserom.gba", 0x1E76420, 0x80
.global sItem01Sprites1
sItem01Sprites1:
.4byte sItem01Gfx1
.incbin "baserom.gba", 0x1E764A4, 0xC
.global sItem01Gfx2
sItem01Gfx2:
.incbin "baserom.gba", 0x1E764B0, 0x80
.global sItem01Sprites2
sItem01Sprites2:
.4byte sItem01Gfx2
.incbin "baserom.gba", 0x1E76534, 0xC
.global sItem01Gfx3
sItem01Gfx3:
.incbin "baserom.gba", 0x1E76540, 0x80
.global sItem01Sprites3
sItem01Sprites3:
.4byte sItem01Gfx3
.incbin "baserom.gba", 0x1E765C4, 0xC
.global sItem01Gfx4
sItem01Gfx4:
.incbin "baserom.gba", 0x1E765D0, 0x80
.global sItem01Sprites4
sItem01Sprites4:
.4byte sItem01Gfx4
.incbin "baserom.gba", 0x1E76654, 0xC
.global sItem01Gfx5
sItem01Gfx5:
.incbin "baserom.gba", 0x1E76660, 0x80
.global sItem01Sprites5
sItem01Sprites5:
.4byte sItem01Gfx5
.incbin "baserom.gba", 0x1E766E4, 0xC
.global sItem01Gfx6
sItem01Gfx6:
.incbin "baserom.gba", 0x1E766F0, 0x80
.global sItem01Sprites6
sItem01Sprites6:
.4byte sItem01Gfx6
.incbin "baserom.gba", 0x1E76774, 0xC
.global sItem01Gfx7
sItem01Gfx7:
.incbin "baserom.gba", 0x1E76780, 0x80
.global sItem01Sprites7
sItem01Sprites7:
.4byte sItem01Gfx7
.incbin "baserom.gba", 0x1E76804, 0xC
.global sItem01Gfx8
sItem01Gfx8:
.incbin "baserom.gba", 0x1E76810, 0x80
.global sItem01Sprites8
sItem01Sprites8:
.4byte sItem01Gfx8
.incbin "baserom.gba", 0x1E76894, 0xC
.global sItem01Gfx9
sItem01Gfx9:
.incbin "baserom.gba", 0x1E768A0, 0x80
.global sItem01Sprites9
sItem01Sprites9:
.4byte sItem01Gfx9
.incbin "baserom.gba", 0x1E76924, 0xC
.global sItem01Gfx10
sItem01Gfx10:
.incbin "baserom.gba", 0x1E76930, 0x80
.global sItem01Sprites10
sItem01Sprites10:
.4byte sItem01Gfx10
.incbin "baserom.gba", 0x1E769B4, 0xC
.global sItem01Gfx11
sItem01Gfx11:
.incbin "baserom.gba", 0x1E769C0, 0x80
.global sItem01Sprites11
sItem01Sprites11:
.4byte sItem01Gfx11
.incbin "baserom.gba", 0x1E76A44, 0xC
.global sItem01Gfx12
sItem01Gfx12:
.incbin "baserom.gba", 0x1E76A50, 0x80
.global sItem01Sprites12
sItem01Sprites12:
.4byte sItem01Gfx12
.incbin "baserom.gba", 0x1E76AD4, 0xC
.global sItem01Gfx13
sItem01Gfx13:
.incbin "baserom.gba", 0x1E76AE0, 0x80
.global sItem01Sprites13
sItem01Sprites13:
.4byte sItem01Gfx13
.incbin "baserom.gba", 0x1E76B64, 0xC
.global sItem01Gfx14
sItem01Gfx14:
.incbin "baserom.gba", 0x1E76B70, 0x80
.global sItem01Sprites14
sItem01Sprites14:
.4byte sItem01Gfx14
.incbin "baserom.gba", 0x1E76BF4, 0xC
.global sItem01Gfx15
sItem01Gfx15:
.incbin "baserom.gba", 0x1E76C00, 0x80
.global sItem01Sprites15
sItem01Sprites15:
.4byte sItem01Gfx15
.incbin "baserom.gba", 0x1E76C84, 0xC
.global sItem01Gfx16
sItem01Gfx16:
.incbin "baserom.gba", 0x1E76C90, 0x80
.global sItem01Sprites16
sItem01Sprites16:
.4byte sItem01Gfx16
.incbin "baserom.gba", 0x1E76D14, 0xC
.global sItem01Gfx17
sItem01Gfx17:
.incbin "baserom.gba", 0x1E76D20, 0x80
.global sItem01Sprites17
sItem01Sprites17:
.4byte sItem01Gfx17
.incbin "baserom.gba", 0x1E76DA4, 0xC
.global sItem01Gfx18
sItem01Gfx18:
.incbin "baserom.gba", 0x1E76DB0, 0x80
.global sItem01Sprites18
sItem01Sprites18:
.4byte sItem01Gfx18
.incbin "baserom.gba", 0x1E76E34, 0xC
.global sItem01Gfx19
sItem01Gfx19:
.incbin "baserom.gba", 0x1E76E40, 0x80
.global sItem01Sprites19
sItem01Sprites19:
.4byte sItem01Gfx19
.incbin "baserom.gba", 0x1E76EC4, 0xC
.global sItem01Gfx20
sItem01Gfx20:
.incbin "baserom.gba", 0x1E76ED0, 0x80
.global sItem01Sprites20
sItem01Sprites20:
.4byte sItem01Gfx20
.incbin "baserom.gba", 0x1E76F54, 0xC
.global sItem01Gfx21
sItem01Gfx21:
.incbin "baserom.gba", 0x1E76F60, 0x80
.global sItem01Sprites21
sItem01Sprites21:
.4byte sItem01Gfx21
.incbin "baserom.gba", 0x1E76FE4, 0xC
.global sItem01Gfx22
sItem01Gfx22:
.incbin "baserom.gba", 0x1E76FF0, 0x80
.global sItem01Sprites22
sItem01Sprites22:
.4byte sItem01Gfx22
.incbin "baserom.gba", 0x1E77074, 0xC
.global sItem01Gfx23
sItem01Gfx23:
.incbin "baserom.gba", 0x1E77080, 0x80
.global sItem01Sprites23
sItem01Sprites23:
.4byte sItem01Gfx23
.incbin "baserom.gba", 0x1E77104, 0xC
.global sItem01Gfx24
sItem01Gfx24:
.incbin "baserom.gba", 0x1E77110, 0x80
.global sItem01Sprites24
sItem01Sprites24:
.4byte sItem01Gfx24
.incbin "baserom.gba", 0x1E77194, 0xC
.global sAxPosesItem01
sAxPosesItem01:
.4byte sItem01Pose1
.4byte sItem01Pose2
.4byte sItem01Pose3
.4byte sItem01Pose4
.4byte sItem01Pose5
.4byte sItem01Pose6
.4byte sItem01Pose7
.4byte sItem01Pose8
.4byte sItem01Pose9
.4byte sItem01Pose10
.4byte sItem01Pose11
.4byte sItem01Pose12
.4byte sItem01Pose13
.4byte sItem01Pose14
.4byte sItem01Pose15
.4byte sItem01Pose16
.4byte sItem01Pose17
.4byte sItem01Pose18
.4byte sItem01Pose19
.4byte sItem01Pose20
.4byte sItem01Pose21
.4byte sItem01Pose22
.4byte sItem01Pose23
.4byte sItem01Pose24
.global sItem01AnimTable1
sItem01AnimTable1:
.4byte sItem01Anims_1_1
.4byte sItem01Anims_1_2
.4byte sItem01Anims_1_3
.4byte sItem01Anims_1_4
.4byte sItem01Anims_1_5
.4byte sItem01Anims_1_6
.4byte sItem01Anims_1_7
.4byte sItem01Anims_1_8
.global sAxAnimationsItem01
sAxAnimationsItem01:
.4byte sItem01AnimTable1
.global sAxSpritesItem01
sAxSpritesItem01:
.4byte sItem01Sprites1
.4byte sItem01Sprites2
.4byte sItem01Sprites3
.4byte sItem01Sprites4
.4byte sItem01Sprites5
.4byte sItem01Sprites6
.4byte sItem01Sprites7
.4byte sItem01Sprites8
.4byte sItem01Sprites9
.4byte sItem01Sprites10
.4byte sItem01Sprites11
.4byte sItem01Sprites12
.4byte sItem01Sprites13
.4byte sItem01Sprites14
.4byte sItem01Sprites15
.4byte sItem01Sprites16
.4byte sItem01Sprites17
.4byte sItem01Sprites18
.4byte sItem01Sprites19
.4byte sItem01Sprites20
.4byte sItem01Sprites21
.4byte sItem01Sprites22
.4byte sItem01Sprites23
.4byte sItem01Sprites24
.global sAxMainItem01
sAxMainItem01:
.4byte sAxPosesItem01
.4byte sAxAnimationsItem01
.incbin "baserom.gba", 0x1E7728C, 0x4
.4byte sAxSpritesItem01
.4byte 0
.global gAxNpc01
gAxNpc01:
.string "SIRO"
.4byte sAxMainNpc01
.4byte 0, 0
.global sNpc01Pose1
sNpc01Pose1:
.incbin "baserom.gba", 0x1E772A8, 0x14
.global sNpc01Anims_1_1
sNpc01Anims_1_1:
.incbin "baserom.gba", 0x1E772BC, 0x18
.global sNpc01Gfx1
sNpc01Gfx1:
.incbin "baserom.gba", 0x1E772D4, 0x20
.global sNpc01Gfx1_2
sNpc01Gfx1_2:
.incbin "baserom.gba", 0x1E772F4, 0x60
.global sNpc01Gfx1_3
sNpc01Gfx1_3:
.incbin "baserom.gba", 0x1E77354, 0x60
.global sNpc01Gfx1_4
sNpc01Gfx1_4:
.incbin "baserom.gba", 0x1E773B4, 0x60
.global sNpc01Sprites1
sNpc01Sprites1:
.incbin "baserom.gba", 0x1E77414, 0x8
.4byte sNpc01Gfx1
.incbin "baserom.gba", 0x1E77420, 0xC
.4byte sNpc01Gfx1_2
.incbin "baserom.gba", 0x1E77430, 0xC
.4byte sNpc01Gfx1_3
.incbin "baserom.gba", 0x1E77440, 0xC
.4byte sNpc01Gfx1_4
.incbin "baserom.gba", 0x1E77450, 0x14
.global sAxPosesNpc01
sAxPosesNpc01:
.4byte sNpc01Pose1
.global sNpc01AnimTable1
sNpc01AnimTable1:
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.4byte sNpc01Anims_1_1
.global sAxAnimationsNpc01
sAxAnimationsNpc01:
.4byte sNpc01AnimTable1
.global sAxSpritesNpc01
sAxSpritesNpc01:
.4byte sNpc01Sprites1
.global sAxMainNpc01
sAxMainNpc01:
.4byte sAxPosesNpc01
.4byte sAxAnimationsNpc01
.incbin "baserom.gba", 0x1E77498, 0x4
.4byte sAxSpritesNpc01
.4byte 0
.global gAxNpc02
gAxNpc02:
.string "SIRO"
.4byte sAxMainNpc02
.4byte 0, 0
.global sNpc02Pose1
sNpc02Pose1:
.incbin "baserom.gba", 0x1E774B4, 0x14
.global sNpc02Anims_1_1
sNpc02Anims_1_1:
.incbin "baserom.gba", 0x1E774C8, 0x18
.global sNpc02Gfx1
sNpc02Gfx1:
.incbin "baserom.gba", 0x1E774E0, 0x200
.global sNpc02Sprites1
sNpc02Sprites1:
.4byte sNpc02Gfx1
.incbin "baserom.gba", 0x1E776E4, 0xC
.global sAxPosesNpc02
sAxPosesNpc02:
.4byte sNpc02Pose1
.global sNpc02AnimTable1
sNpc02AnimTable1:
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.4byte sNpc02Anims_1_1
.global sAxAnimationsNpc02
sAxAnimationsNpc02:
.4byte sNpc02AnimTable1
.global sAxSpritesNpc02
sAxSpritesNpc02:
.4byte sNpc02Sprites1
.global sAxMainNpc02
sAxMainNpc02:
.4byte sAxPosesNpc02
.4byte sAxAnimationsNpc02
.incbin "baserom.gba", 0x1E77724, 0x4
.4byte sAxSpritesNpc02
.4byte 0
.global gAxNpc03
gAxNpc03:
.string "SIRO"
.4byte sAxMainNpc03
.4byte 0, 0
.global sNpc03Pose1
sNpc03Pose1:
.incbin "baserom.gba", 0x1E77740, 0x14
.global sNpc03Anims_1_1
sNpc03Anims_1_1:
.incbin "baserom.gba", 0x1E77754, 0x18
.global sNpc03Gfx1
sNpc03Gfx1:
.incbin "baserom.gba", 0x1E7776C, 0x1E0
.global sNpc03Sprites1
sNpc03Sprites1:
.incbin "baserom.gba", 0x1E7794C, 0x8
.4byte sNpc03Gfx1
.incbin "baserom.gba", 0x1E77958, 0xC
.global sAxPosesNpc03
sAxPosesNpc03:
.4byte sNpc03Pose1
.global sNpc03AnimTable1
sNpc03AnimTable1:
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.4byte sNpc03Anims_1_1
.global sAxAnimationsNpc03
sAxAnimationsNpc03:
.4byte sNpc03AnimTable1
.global sAxSpritesNpc03
sAxSpritesNpc03:
.4byte sNpc03Sprites1
.global sAxMainNpc03
sAxMainNpc03:
.4byte sAxPosesNpc03
.4byte sAxAnimationsNpc03
.incbin "baserom.gba", 0x1E77998, 0x4
.4byte sAxSpritesNpc03
.4byte 0
.global gAxNpc04
gAxNpc04:
.string "SIRO"
.4byte sAxMainNpc04
.4byte 0, 0
.global sNpc04Pose1
sNpc04Pose1:
.incbin "baserom.gba", 0x1E779B4, 0x14
.global sNpc04Anims_1_1
sNpc04Anims_1_1:
.incbin "baserom.gba", 0x1E779C8, 0x18
.global sNpc04Gfx1
sNpc04Gfx1:
.incbin "baserom.gba", 0x1E779E0, 0x100
.global sNpc04Sprites1
sNpc04Sprites1:
.4byte sNpc04Gfx1
.incbin "baserom.gba", 0x1E77AE4, 0xC
.global sAxPosesNpc04
sAxPosesNpc04:
.4byte sNpc04Pose1
.global sNpc04AnimTable1
sNpc04AnimTable1:
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.4byte sNpc04Anims_1_1
.global sAxAnimationsNpc04
sAxAnimationsNpc04:
.4byte sNpc04AnimTable1
.global sAxSpritesNpc04
sAxSpritesNpc04:
.4byte sNpc04Sprites1
.global sAxMainNpc04
sAxMainNpc04:
.4byte sAxPosesNpc04
.4byte sAxAnimationsNpc04
.incbin "baserom.gba", 0x1E77B24, 0x4
.4byte sAxSpritesNpc04
.4byte 0
.global gStoneimPal
gStoneimPal:
.incbin "graphics/ornament/pal/stoneim.pmdpal"
.global gAxTitlebg1
gAxTitlebg1:
.string "SIRO"
.4byte sAxMainTitlebg1
.4byte 0, 0
.global sTitlebg1Pose1
sTitlebg1Pose1:
.incbin "baserom.gba", 0x1E77B80, 0x82
.global sTitlebg1Pose2
sTitlebg1Pose2:
.incbin "baserom.gba", 0x1E77C02, 0x82
.global sTitlebg1Pose3
sTitlebg1Pose3:
.incbin "baserom.gba", 0x1E77C84, 0x82
.global sTitlebg1Pose4
sTitlebg1Pose4:
.incbin "baserom.gba", 0x1E77D06, 0x82
.global sTitlebg1Pose5
sTitlebg1Pose5:
.incbin "baserom.gba", 0x1E77D88, 0x82
.global sTitlebg1Pose6
sTitlebg1Pose6:
.incbin "baserom.gba", 0x1E77E0A, 0x82
.global sTitlebg1Pose7
sTitlebg1Pose7:
.incbin "baserom.gba", 0x1E77E8C, 0x82
.global sTitlebg1Pose8
sTitlebg1Pose8:
.incbin "baserom.gba", 0x1E77F0E, 0x82
.global sTitlebg1Pose9
sTitlebg1Pose9:
.incbin "baserom.gba", 0x1E77F90, 0x82
.global sTitlebg1Pose10
sTitlebg1Pose10:
.incbin "baserom.gba", 0x1E78012, 0x82
.global sTitlebg1Pose11
sTitlebg1Pose11:
.incbin "baserom.gba", 0x1E78094, 0x82
.global sTitlebg1Pose12
sTitlebg1Pose12:
.incbin "baserom.gba", 0x1E78116, 0x82
.global sTitlebg1Anims_1_1
sTitlebg1Anims_1_1:
.incbin "baserom.gba", 0x1E78198, 0x9C
.global sTitlebg1Gfx1
sTitlebg1Gfx1:
.incbin "baserom.gba", 0x1E78234, 0x200
.global sTitlebg1Sprites1
sTitlebg1Sprites1:
.4byte sTitlebg1Gfx1
.incbin "baserom.gba", 0x1E78438, 0xC
.global sTitlebg1Gfx2
sTitlebg1Gfx2:
.incbin "baserom.gba", 0x1E78444, 0x200
.global sTitlebg1Sprites2
sTitlebg1Sprites2:
.4byte sTitlebg1Gfx2
.incbin "baserom.gba", 0x1E78648, 0xC
.global sTitlebg1Gfx3
sTitlebg1Gfx3:
.incbin "baserom.gba", 0x1E78654, 0x200
.global sTitlebg1Sprites3
sTitlebg1Sprites3:
.4byte sTitlebg1Gfx3
.incbin "baserom.gba", 0x1E78858, 0xC
.global sTitlebg1Gfx4
sTitlebg1Gfx4:
.incbin "baserom.gba", 0x1E78864, 0x100
.global sTitlebg1Gfx4_2
sTitlebg1Gfx4_2:
.incbin "baserom.gba", 0x1E78964, 0x80
.global sTitlebg1Sprites4
sTitlebg1Sprites4:
.4byte sTitlebg1Gfx4
.incbin "baserom.gba", 0x1E789E8, 0xC
.4byte sTitlebg1Gfx4_2
.incbin "baserom.gba", 0x1E789F8, 0xC
.global sTitlebg1Gfx5
sTitlebg1Gfx5:
.incbin "baserom.gba", 0x1E78A04, 0x200
.global sTitlebg1Sprites5
sTitlebg1Sprites5:
.4byte sTitlebg1Gfx5
.incbin "baserom.gba", 0x1E78C08, 0xC
.global sTitlebg1Gfx6
sTitlebg1Gfx6:
.incbin "baserom.gba", 0x1E78C14, 0x200
.global sTitlebg1Sprites6
sTitlebg1Sprites6:
.4byte sTitlebg1Gfx6
.incbin "baserom.gba", 0x1E78E18, 0xC
.global sTitlebg1Gfx7
sTitlebg1Gfx7:
.incbin "baserom.gba", 0x1E78E24, 0x200
.global sTitlebg1Sprites7
sTitlebg1Sprites7:
.4byte sTitlebg1Gfx7
.incbin "baserom.gba", 0x1E79028, 0xC
.global sTitlebg1Gfx8
sTitlebg1Gfx8:
.incbin "baserom.gba", 0x1E79034, 0x200
.global sTitlebg1Sprites8
sTitlebg1Sprites8:
.4byte sTitlebg1Gfx8
.incbin "baserom.gba", 0x1E79238, 0xC
.global sTitlebg1Gfx9
sTitlebg1Gfx9:
.incbin "baserom.gba", 0x1E79244, 0x200
.global sTitlebg1Sprites9
sTitlebg1Sprites9:
.4byte sTitlebg1Gfx9
.incbin "baserom.gba", 0x1E79448, 0xC
.global sTitlebg1Gfx10
sTitlebg1Gfx10:
.incbin "baserom.gba", 0x1E79454, 0x200
.global sTitlebg1Sprites10
sTitlebg1Sprites10:
.4byte sTitlebg1Gfx10
.incbin "baserom.gba", 0x1E79658, 0xC
.global sTitlebg1Gfx11
sTitlebg1Gfx11:
.incbin "baserom.gba", 0x1E79664, 0x200
.global sTitlebg1Sprites11
sTitlebg1Sprites11:
.4byte sTitlebg1Gfx11
.incbin "baserom.gba", 0x1E79868, 0xC
.global sTitlebg1Gfx12
sTitlebg1Gfx12:
.incbin "baserom.gba", 0x1E79874, 0x200
.global sTitlebg1Sprites12
sTitlebg1Sprites12:
.4byte sTitlebg1Gfx12
.incbin "baserom.gba", 0x1E79A78, 0xC
.global sTitlebg1Gfx13
sTitlebg1Gfx13:
.incbin "baserom.gba", 0x1E79A84, 0x200
.global sTitlebg1Sprites13
sTitlebg1Sprites13:
.4byte sTitlebg1Gfx13
.incbin "baserom.gba", 0x1E79C88, 0xC
.global sTitlebg1Gfx14
sTitlebg1Gfx14:
.incbin "baserom.gba", 0x1E79C94, 0x200
.global sTitlebg1Sprites14
sTitlebg1Sprites14:
.4byte sTitlebg1Gfx14
.incbin "baserom.gba", 0x1E79E98, 0xC
.global sTitlebg1Gfx15
sTitlebg1Gfx15:
.incbin "baserom.gba", 0x1E79EA4, 0x200
.global sTitlebg1Sprites15
sTitlebg1Sprites15:
.4byte sTitlebg1Gfx15
.incbin "baserom.gba", 0x1E7A0A8, 0xC
.global sTitlebg1Gfx16
sTitlebg1Gfx16:
.incbin "baserom.gba", 0x1E7A0B4, 0x200
.global sTitlebg1Sprites16
sTitlebg1Sprites16:
.4byte sTitlebg1Gfx16
.incbin "baserom.gba", 0x1E7A2B8, 0xC
.global sTitlebg1Gfx17
sTitlebg1Gfx17:
.incbin "baserom.gba", 0x1E7A2C4, 0x200
.global sTitlebg1Sprites17
sTitlebg1Sprites17:
.4byte sTitlebg1Gfx17
.incbin "baserom.gba", 0x1E7A4C8, 0xC
.global sTitlebg1Gfx18
sTitlebg1Gfx18:
.incbin "baserom.gba", 0x1E7A4D4, 0x200
.global sTitlebg1Sprites18
sTitlebg1Sprites18:
.4byte sTitlebg1Gfx18
.incbin "baserom.gba", 0x1E7A6D8, 0xC
.global sTitlebg1Gfx19
sTitlebg1Gfx19:
.incbin "baserom.gba", 0x1E7A6E4, 0x200
.global sTitlebg1Sprites19
sTitlebg1Sprites19:
.4byte sTitlebg1Gfx19
.incbin "baserom.gba", 0x1E7A8E8, 0xC
.global sTitlebg1Gfx20
sTitlebg1Gfx20:
.incbin "baserom.gba", 0x1E7A8F4, 0x200
.global sTitlebg1Sprites20
sTitlebg1Sprites20:
.4byte sTitlebg1Gfx20
.incbin "baserom.gba", 0x1E7AAF8, 0xC
.global sTitlebg1Gfx21
sTitlebg1Gfx21:
.incbin "baserom.gba", 0x1E7AB04, 0x200
.global sTitlebg1Sprites21
sTitlebg1Sprites21:
.4byte sTitlebg1Gfx21
.incbin "baserom.gba", 0x1E7AD08, 0xC
.global sTitlebg1Gfx22
sTitlebg1Gfx22:
.incbin "baserom.gba", 0x1E7AD14, 0x200
.global sTitlebg1Sprites22
sTitlebg1Sprites22:
.4byte sTitlebg1Gfx22
.incbin "baserom.gba", 0x1E7AF18, 0xC
.global sTitlebg1Gfx23
sTitlebg1Gfx23:
.incbin "baserom.gba", 0x1E7AF24, 0x200
.global sTitlebg1Sprites23
sTitlebg1Sprites23:
.4byte sTitlebg1Gfx23
.incbin "baserom.gba", 0x1E7B128, 0xC
.global sTitlebg1Gfx24
sTitlebg1Gfx24:
.incbin "baserom.gba", 0x1E7B134, 0x200
.global sTitlebg1Sprites24
sTitlebg1Sprites24:
.4byte sTitlebg1Gfx24
.incbin "baserom.gba", 0x1E7B338, 0xC
.global sTitlebg1Gfx25
sTitlebg1Gfx25:
.incbin "baserom.gba", 0x1E7B344, 0x200
.global sTitlebg1Sprites25
sTitlebg1Sprites25:
.4byte sTitlebg1Gfx25
.incbin "baserom.gba", 0x1E7B548, 0xC
.global sTitlebg1Gfx26
sTitlebg1Gfx26:
.incbin "baserom.gba", 0x1E7B554, 0x200
.global sTitlebg1Sprites26
sTitlebg1Sprites26:
.4byte sTitlebg1Gfx26
.incbin "baserom.gba", 0x1E7B758, 0xC
.global sAxPosesTitlebg1
sAxPosesTitlebg1:
.4byte sTitlebg1Pose1
.4byte sTitlebg1Pose2
.4byte sTitlebg1Pose3
.4byte sTitlebg1Pose4
.4byte sTitlebg1Pose5
.4byte sTitlebg1Pose6
.4byte sTitlebg1Pose7
.4byte sTitlebg1Pose8
.4byte sTitlebg1Pose9
.4byte sTitlebg1Pose10
.4byte sTitlebg1Pose11
.4byte sTitlebg1Pose12
.global sTitlebg1AnimTable1
sTitlebg1AnimTable1:
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.4byte sTitlebg1Anims_1_1
.global sAxAnimationsTitlebg1
sAxAnimationsTitlebg1:
.4byte sTitlebg1AnimTable1
.global sAxSpritesTitlebg1
sAxSpritesTitlebg1:
.4byte sTitlebg1Sprites1
.4byte sTitlebg1Sprites2
.4byte sTitlebg1Sprites3
.4byte sTitlebg1Sprites4
.4byte sTitlebg1Sprites5
.4byte sTitlebg1Sprites6
.4byte sTitlebg1Sprites7
.4byte sTitlebg1Sprites8
.4byte sTitlebg1Sprites9
.4byte sTitlebg1Sprites10
.4byte sTitlebg1Sprites11
.4byte sTitlebg1Sprites12
.4byte sTitlebg1Sprites13
.4byte sTitlebg1Sprites14
.4byte sTitlebg1Sprites15
.4byte sTitlebg1Sprites16
.4byte sTitlebg1Sprites17
.4byte sTitlebg1Sprites18
.4byte sTitlebg1Sprites19
.4byte sTitlebg1Sprites20
.4byte sTitlebg1Sprites21
.4byte sTitlebg1Sprites22
.4byte sTitlebg1Sprites23
.4byte sTitlebg1Sprites24
.4byte sTitlebg1Sprites25
.4byte sTitlebg1Sprites26
.global sAxMainTitlebg1
sAxMainTitlebg1:
.4byte sAxPosesTitlebg1
.4byte sAxAnimationsTitlebg1
.incbin "baserom.gba", 0x1E7B828, 0x4
.4byte sAxSpritesTitlebg1
.4byte 0
.global gTitlebgPal
gTitlebgPal:
.incbin "graphics/ornament/pal/titlebg.pmdpal"
.global gAxTitleop1
gAxTitleop1:
.string "SIRO"
.4byte sAxMainTitleop1
.4byte 0, 0
.global sTitleop1Pose1
sTitleop1Pose1:
.incbin "baserom.gba", 0x1E7B884, 0x1E
.global sTitleop1Pose2
sTitleop1Pose2:
.incbin "baserom.gba", 0x1E7B8A2, 0x1E
.global sTitleop1Pose3
sTitleop1Pose3:
.incbin "baserom.gba", 0x1E7B8C0, 0x1E
.global sTitleop1Pose4
sTitleop1Pose4:
.incbin "baserom.gba", 0x1E7B8DE, 0x1E
.global sTitleop1Pose5
sTitleop1Pose5:
.incbin "baserom.gba", 0x1E7B8FC, 0x1E
.global sTitleop1Pose6
sTitleop1Pose6:
.incbin "baserom.gba", 0x1E7B91A, 0x1E
.global sTitleop1Pose7
sTitleop1Pose7:
.incbin "baserom.gba", 0x1E7B938, 0x28
.global sTitleop1Pose8
sTitleop1Pose8:
.incbin "baserom.gba", 0x1E7B960, 0x1E
.global sTitleop1Pose9
sTitleop1Pose9:
.incbin "baserom.gba", 0x1E7B97E, 0x28
.global sTitleop1Pose10
sTitleop1Pose10:
.incbin "baserom.gba", 0x1E7B9A6, 0x28
.global sTitleop1Pose11
sTitleop1Pose11:
.incbin "baserom.gba", 0x1E7B9CE, 0x3C
.global sTitleop1Pose12
sTitleop1Pose12:
.incbin "baserom.gba", 0x1E7BA0A, 0x1E
.global sTitleop1Pose13
sTitleop1Pose13:
.incbin "baserom.gba", 0x1E7BA28, 0x1E
.global sTitleop1Pose14
sTitleop1Pose14:
.incbin "baserom.gba", 0x1E7BA46, 0x1E
.global sTitleop1Pose15
sTitleop1Pose15:
.incbin "baserom.gba", 0x1E7BA64, 0x1E
.global sTitleop1Pose16
sTitleop1Pose16:
.incbin "baserom.gba", 0x1E7BA82, 0x1E
.global sTitleop1Pose17
sTitleop1Pose17:
.incbin "baserom.gba", 0x1E7BAA0, 0x1E
.global sTitleop1Pose18
sTitleop1Pose18:
.incbin "baserom.gba", 0x1E7BABE, 0x28
.global sTitleop1Pose19
sTitleop1Pose19:
.incbin "baserom.gba", 0x1E7BAE6, 0x1E
.global sTitleop1Pose20
sTitleop1Pose20:
.incbin "baserom.gba", 0x1E7BB04, 0x28
.global sTitleop1Pose21
sTitleop1Pose21:
.incbin "baserom.gba", 0x1E7BB2C, 0x28
.global sTitleop1Pose22
sTitleop1Pose22:
.incbin "baserom.gba", 0x1E7BB54, 0x3C
.global sTitleop1Pose23
sTitleop1Pose23:
.incbin "baserom.gba", 0x1E7BB90, 0x14
.global sTitleop1Pose24
sTitleop1Pose24:
.incbin "baserom.gba", 0x1E7BBA4, 0x14
.global sTitleop1Pose25
sTitleop1Pose25:
.incbin "baserom.gba", 0x1E7BBB8, 0x14
.global sTitleop1Pose26
sTitleop1Pose26:
.incbin "baserom.gba", 0x1E7BBCC, 0x14
.global sTitleop1Pose27
sTitleop1Pose27:
.incbin "baserom.gba", 0x1E7BBE0, 0x14
.global sTitleop1Pose28
sTitleop1Pose28:
.incbin "baserom.gba", 0x1E7BBF4, 0x14
.global sTitleop1Pose29
sTitleop1Pose29:
.incbin "baserom.gba", 0x1E7BC08, 0x14
.global sTitleop1Pose30
sTitleop1Pose30:
.incbin "baserom.gba", 0x1E7BC1C, 0x14
.global sTitleop1Pose31
sTitleop1Pose31:
.incbin "baserom.gba", 0x1E7BC30, 0x1E
.global sTitleop1Pose32
sTitleop1Pose32:
.incbin "baserom.gba", 0x1E7BC4E, 0x1E
.global sTitleop1Pose33
sTitleop1Pose33:
.incbin "baserom.gba", 0x1E7BC6C, 0x1E
.global sTitleop1Pose34
sTitleop1Pose34:
.incbin "baserom.gba", 0x1E7BC8A, 0x1E
.global sTitleop1Pose35
sTitleop1Pose35:
.incbin "baserom.gba", 0x1E7BCA8, 0x1E
.global sTitleop1Pose36
sTitleop1Pose36:
.incbin "baserom.gba", 0x1E7BCC6, 0x1E
.global sTitleop1Pose37
sTitleop1Pose37:
.incbin "baserom.gba", 0x1E7BCE4, 0x28
.global sTitleop1Pose38
sTitleop1Pose38:
.incbin "baserom.gba", 0x1E7BD0C, 0x1E
.global sTitleop1Pose39
sTitleop1Pose39:
.incbin "baserom.gba", 0x1E7BD2A, 0x28
.global sTitleop1Pose40
sTitleop1Pose40:
.incbin "baserom.gba", 0x1E7BD52, 0x28
.global sTitleop1Pose41
sTitleop1Pose41:
.incbin "baserom.gba", 0x1E7BD7A, 0x3C
.global sTitleop1Pose42
sTitleop1Pose42:
.incbin "baserom.gba", 0x1E7BDB6, 0x1E
.global sTitleop1Pose43
sTitleop1Pose43:
.incbin "baserom.gba", 0x1E7BDD4, 0x1E
.global sTitleop1Pose44
sTitleop1Pose44:
.incbin "baserom.gba", 0x1E7BDF2, 0x1E
.global sTitleop1Pose45
sTitleop1Pose45:
.incbin "baserom.gba", 0x1E7BE10, 0x1E
.global sTitleop1Pose46
sTitleop1Pose46:
.incbin "baserom.gba", 0x1E7BE2E, 0x1E
.global sTitleop1Pose47
sTitleop1Pose47:
.incbin "baserom.gba", 0x1E7BE4C, 0x1E
.global sTitleop1Pose48
sTitleop1Pose48:
.incbin "baserom.gba", 0x1E7BE6A, 0x28
.global sTitleop1Pose49
sTitleop1Pose49:
.incbin "baserom.gba", 0x1E7BE92, 0x1E
.global sTitleop1Pose50
sTitleop1Pose50:
.incbin "baserom.gba", 0x1E7BEB0, 0x28
.global sTitleop1Pose51
sTitleop1Pose51:
.incbin "baserom.gba", 0x1E7BED8, 0x28
.global sTitleop1Pose52
sTitleop1Pose52:
.incbin "baserom.gba", 0x1E7BF00, 0x3C
.global sTitleop1Pose53
sTitleop1Pose53:
.incbin "baserom.gba", 0x1E7BF3C, 0x14
.global sTitleop1Pose54
sTitleop1Pose54:
.incbin "baserom.gba", 0x1E7BF50, 0x14
.global sTitleop1Pose55
sTitleop1Pose55:
.incbin "baserom.gba", 0x1E7BF64, 0x14
.global sTitleop1Pose56
sTitleop1Pose56:
.incbin "baserom.gba", 0x1E7BF78, 0x14
.global sTitleop1Pose57
sTitleop1Pose57:
.incbin "baserom.gba", 0x1E7BF8C, 0x14
.global sTitleop1Pose58
sTitleop1Pose58:
.incbin "baserom.gba", 0x1E7BFA0, 0x14
.global sTitleop1Pose59
sTitleop1Pose59:
.incbin "baserom.gba", 0x1E7BFB4, 0x14
.global sTitleop1Pose60
sTitleop1Pose60:
.incbin "baserom.gba", 0x1E7BFC8, 0x14
.global sTitleop1Anims_1_1
sTitleop1Anims_1_1:
.incbin "baserom.gba", 0x1E7BFDC, 0x54
.global sTitleop1Anims_1_2
sTitleop1Anims_1_2:
.incbin "baserom.gba", 0x1E7C030, 0x18
.global sTitleop1Anims_1_3
sTitleop1Anims_1_3:
.incbin "baserom.gba", 0x1E7C048, 0x18
.global sTitleop1Anims_1_4
sTitleop1Anims_1_4:
.incbin "baserom.gba", 0x1E7C060, 0x18
.global sTitleop1Anims_1_5
sTitleop1Anims_1_5:
.incbin "baserom.gba", 0x1E7C078, 0x18
.global sTitleop1Anims_1_6
sTitleop1Anims_1_6:
.incbin "baserom.gba", 0x1E7C090, 0x18
.global sTitleop1Anims_1_7
sTitleop1Anims_1_7:
.incbin "baserom.gba", 0x1E7C0A8, 0x18
.global sTitleop1Anims_1_8
sTitleop1Anims_1_8:
.incbin "baserom.gba", 0x1E7C0C0, 0x54
.global sTitleop1Anims_2_1
sTitleop1Anims_2_1:
.incbin "baserom.gba", 0x1E7C114, 0x54
.global sTitleop1Anims_2_2
sTitleop1Anims_2_2:
.incbin "baserom.gba", 0x1E7C168, 0x18
.global sTitleop1Anims_2_3
sTitleop1Anims_2_3:
.incbin "baserom.gba", 0x1E7C180, 0x18
.global sTitleop1Anims_2_4
sTitleop1Anims_2_4:
.incbin "baserom.gba", 0x1E7C198, 0x18
.global sTitleop1Anims_2_5
sTitleop1Anims_2_5:
.incbin "baserom.gba", 0x1E7C1B0, 0x18
.global sTitleop1Anims_2_6
sTitleop1Anims_2_6:
.incbin "baserom.gba", 0x1E7C1C8, 0x18
.global sTitleop1Anims_2_7
sTitleop1Anims_2_7:
.incbin "baserom.gba", 0x1E7C1E0, 0x18
.global sTitleop1Anims_2_8
sTitleop1Anims_2_8:
.incbin "baserom.gba", 0x1E7C1F8, 0x54
.global sTitleop1Gfx1
sTitleop1Gfx1:
.incbin "baserom.gba", 0x1E7C24C, 0x20
.global sTitleop1Gfx1_2
sTitleop1Gfx1_2:
.incbin "baserom.gba", 0x1E7C26C, 0x100
.global sTitleop1Gfx1_3
sTitleop1Gfx1_3:
.incbin "baserom.gba", 0x1E7C36C, 0x60
.global sTitleop1Sprites1
sTitleop1Sprites1:
.incbin "baserom.gba", 0x1E7C3CC, 0x8
.4byte sTitleop1Gfx1
.incbin "baserom.gba", 0x1E7C3D8, 0xC
.4byte sTitleop1Gfx1_2
.incbin "baserom.gba", 0x1E7C3E8, 0xC
.4byte sTitleop1Gfx1_3
.incbin "baserom.gba", 0x1E7C3F8, 0xC
.global sTitleop1Gfx2
sTitleop1Gfx2:
.incbin "baserom.gba", 0x1E7C404, 0x80
.global sTitleop1Sprites2
sTitleop1Sprites2:
.incbin "baserom.gba", 0x1E7C484, 0x8
.4byte sTitleop1Gfx2
.incbin "baserom.gba", 0x1E7C490, 0x14
.global sTitleop1Gfx3
sTitleop1Gfx3:
.incbin "baserom.gba", 0x1E7C4A4, 0x40
.global sTitleop1Gfx3_2
sTitleop1Gfx3_2:
.incbin "baserom.gba", 0x1E7C4E4, 0x160
.global sTitleop1Sprites3
sTitleop1Sprites3:
.incbin "baserom.gba", 0x1E7C644, 0x8
.4byte sTitleop1Gfx3
.incbin "baserom.gba", 0x1E7C650, 0xC
.4byte sTitleop1Gfx3_2
.incbin "baserom.gba", 0x1E7C660, 0xC
.global sTitleop1Gfx4
sTitleop1Gfx4:
.incbin "baserom.gba", 0x1E7C66C, 0x80
.global sTitleop1Sprites4
sTitleop1Sprites4:
.incbin "baserom.gba", 0x1E7C6EC, 0x8
.4byte sTitleop1Gfx4
.incbin "baserom.gba", 0x1E7C6F8, 0xC
.global sTitleop1Gfx5
sTitleop1Gfx5:
.incbin "baserom.gba", 0x1E7C704, 0x40
.global sTitleop1Gfx5_2
sTitleop1Gfx5_2:
.incbin "baserom.gba", 0x1E7C744, 0x60
.global sTitleop1Gfx5_3
sTitleop1Gfx5_3:
.incbin "baserom.gba", 0x1E7C7A4, 0xE0
.global sTitleop1Sprites5
sTitleop1Sprites5:
.incbin "baserom.gba", 0x1E7C884, 0x8
.4byte sTitleop1Gfx5
.incbin "baserom.gba", 0x1E7C890, 0xC
.4byte sTitleop1Gfx5_2
.incbin "baserom.gba", 0x1E7C8A0, 0xC
.4byte sTitleop1Gfx5_3
.incbin "baserom.gba", 0x1E7C8B0, 0xC
.global sTitleop1Gfx6
sTitleop1Gfx6:
.incbin "baserom.gba", 0x1E7C8BC, 0x20
.global sTitleop1Gfx6_2
sTitleop1Gfx6_2:
.incbin "baserom.gba", 0x1E7C8DC, 0x20
.global sTitleop1Gfx6_3
sTitleop1Gfx6_3:
.incbin "baserom.gba", 0x1E7C8FC, 0x20
.global sTitleop1Sprites6
sTitleop1Sprites6:
.incbin "baserom.gba", 0x1E7C91C, 0x8
.4byte sTitleop1Gfx6
.incbin "baserom.gba", 0x1E7C928, 0xC
.4byte sTitleop1Gfx6_2
.incbin "baserom.gba", 0x1E7C938, 0xC
.4byte sTitleop1Gfx6_3
.incbin "baserom.gba", 0x1E7C948, 0x14
.global sTitleop1Gfx7
sTitleop1Gfx7:
.incbin "baserom.gba", 0x1E7C95C, 0x40
.global sTitleop1Gfx7_2
sTitleop1Gfx7_2:
.incbin "baserom.gba", 0x1E7C99C, 0x160
.global sTitleop1Sprites7
sTitleop1Sprites7:
.incbin "baserom.gba", 0x1E7CAFC, 0x8
.4byte sTitleop1Gfx7
.incbin "baserom.gba", 0x1E7CB08, 0xC
.4byte sTitleop1Gfx7_2
.incbin "baserom.gba", 0x1E7CB18, 0xC
.global sTitleop1Gfx8
sTitleop1Gfx8:
.incbin "baserom.gba", 0x1E7CB24, 0x20
.global sTitleop1Gfx8_2
sTitleop1Gfx8_2:
.incbin "baserom.gba", 0x1E7CB44, 0x20
.global sTitleop1Gfx8_3
sTitleop1Gfx8_3:
.incbin "baserom.gba", 0x1E7CB64, 0x20
.global sTitleop1Sprites8
sTitleop1Sprites8:
.incbin "baserom.gba", 0x1E7CB84, 0x8
.4byte sTitleop1Gfx8
.incbin "baserom.gba", 0x1E7CB90, 0xC
.4byte sTitleop1Gfx8_2
.incbin "baserom.gba", 0x1E7CBA0, 0xC
.4byte sTitleop1Gfx8_3
.incbin "baserom.gba", 0x1E7CBB0, 0x14
.global sTitleop1Gfx9
sTitleop1Gfx9:
.incbin "baserom.gba", 0x1E7CBC4, 0x20
.global sTitleop1Gfx9_2
sTitleop1Gfx9_2:
.incbin "baserom.gba", 0x1E7CBE4, 0x100
.global sTitleop1Gfx9_3
sTitleop1Gfx9_3:
.incbin "baserom.gba", 0x1E7CCE4, 0x60
.global sTitleop1Sprites9
sTitleop1Sprites9:
.incbin "baserom.gba", 0x1E7CD44, 0x8
.4byte sTitleop1Gfx9
.incbin "baserom.gba", 0x1E7CD50, 0xC
.4byte sTitleop1Gfx9_2
.incbin "baserom.gba", 0x1E7CD60, 0xC
.4byte sTitleop1Gfx9_3
.incbin "baserom.gba", 0x1E7CD70, 0xC
.global sTitleop1Gfx10
sTitleop1Gfx10:
.incbin "baserom.gba", 0x1E7CD7C, 0x80
.global sTitleop1Sprites10
sTitleop1Sprites10:
.incbin "baserom.gba", 0x1E7CDFC, 0x8
.4byte sTitleop1Gfx10
.incbin "baserom.gba", 0x1E7CE08, 0x14
.global sTitleop1Gfx11
sTitleop1Gfx11:
.incbin "baserom.gba", 0x1E7CE1C, 0x40
.global sTitleop1Gfx11_2
sTitleop1Gfx11_2:
.incbin "baserom.gba", 0x1E7CE5C, 0x80
.global sTitleop1Gfx11_3
sTitleop1Gfx11_3:
.incbin "baserom.gba", 0x1E7CEDC, 0x60
.global sTitleop1Gfx11_4
sTitleop1Gfx11_4:
.incbin "baserom.gba", 0x1E7CF3C, 0x60
.global sTitleop1Sprites11
sTitleop1Sprites11:
.4byte sTitleop1Gfx11
.incbin "baserom.gba", 0x1E7CFA0, 0xC
.4byte sTitleop1Gfx11_2
.incbin "baserom.gba", 0x1E7CFB0, 0xC
.4byte sTitleop1Gfx11_3
.incbin "baserom.gba", 0x1E7CFC0, 0xC
.4byte sTitleop1Gfx11_4
.incbin "baserom.gba", 0x1E7CFD0, 0xC
.global sTitleop1Gfx12
sTitleop1Gfx12:
.incbin "baserom.gba", 0x1E7CFDC, 0xA0
.global sTitleop1Sprites12
sTitleop1Sprites12:
.4byte sTitleop1Gfx12
.incbin "baserom.gba", 0x1E7D080, 0x14
.global sTitleop1Gfx13
sTitleop1Gfx13:
.incbin "baserom.gba", 0x1E7D094, 0xE0
.global sTitleop1Gfx13_2
sTitleop1Gfx13_2:
.incbin "baserom.gba", 0x1E7D174, 0x60
.global sTitleop1Gfx13_3
sTitleop1Gfx13_3:
.incbin "baserom.gba", 0x1E7D1D4, 0x40
.global sTitleop1Sprites13
sTitleop1Sprites13:
.incbin "baserom.gba", 0x1E7D214, 0x8
.4byte sTitleop1Gfx13
.incbin "baserom.gba", 0x1E7D220, 0xC
.4byte sTitleop1Gfx13_2
.incbin "baserom.gba", 0x1E7D230, 0xC
.4byte sTitleop1Gfx13_3
.incbin "baserom.gba", 0x1E7D240, 0xC
.global sTitleop1Gfx14
sTitleop1Gfx14:
.incbin "baserom.gba", 0x1E7D24C, 0x80
.global sTitleop1Sprites14
sTitleop1Sprites14:
.incbin "baserom.gba", 0x1E7D2CC, 0x8
.4byte sTitleop1Gfx14
.incbin "baserom.gba", 0x1E7D2D8, 0x14
.global sTitleop1Gfx15
sTitleop1Gfx15:
.incbin "baserom.gba", 0x1E7D2EC, 0x40
.global sTitleop1Sprites15
sTitleop1Sprites15:
.incbin "baserom.gba", 0x1E7D32C, 0x8
.4byte sTitleop1Gfx15
.incbin "baserom.gba", 0x1E7D338, 0x14
.global sTitleop1Gfx16
sTitleop1Gfx16:
.incbin "baserom.gba", 0x1E7D34C, 0x100
.global sTitleop1Gfx16_2
sTitleop1Gfx16_2:
.incbin "baserom.gba", 0x1E7D44C, 0x60
.global sTitleop1Gfx16_3
sTitleop1Gfx16_3:
.incbin "baserom.gba", 0x1E7D4AC, 0x40
.global sTitleop1Sprites16
sTitleop1Sprites16:
.4byte sTitleop1Gfx16
.incbin "baserom.gba", 0x1E7D4F0, 0xC
.4byte sTitleop1Gfx16_2
.incbin "baserom.gba", 0x1E7D500, 0xC
.4byte sTitleop1Gfx16_3
.incbin "baserom.gba", 0x1E7D510, 0xC
.global sTitleop1Gfx17
sTitleop1Gfx17:
.incbin "baserom.gba", 0x1E7D51C, 0x20
.global sTitleop1Gfx17_2
sTitleop1Gfx17_2:
.incbin "baserom.gba", 0x1E7D53C, 0x120
.global sTitleop1Sprites17
sTitleop1Sprites17:
.4byte sTitleop1Gfx17
.incbin "baserom.gba", 0x1E7D660, 0xC
.4byte sTitleop1Gfx17_2
.incbin "baserom.gba", 0x1E7D670, 0x14
.global sTitleop1Gfx18
sTitleop1Gfx18:
.incbin "baserom.gba", 0x1E7D684, 0x100
.global sTitleop1Gfx18_2
sTitleop1Gfx18_2:
.incbin "baserom.gba", 0x1E7D784, 0x60
.global sTitleop1Gfx18_3
sTitleop1Gfx18_3:
.incbin "baserom.gba", 0x1E7D7E4, 0x40
.global sTitleop1Sprites18
sTitleop1Sprites18:
.4byte sTitleop1Gfx18
.incbin "baserom.gba", 0x1E7D828, 0xC
.4byte sTitleop1Gfx18_2
.incbin "baserom.gba", 0x1E7D838, 0xC
.4byte sTitleop1Gfx18_3
.incbin "baserom.gba", 0x1E7D848, 0xC
.global sTitleop1Gfx19
sTitleop1Gfx19:
.incbin "baserom.gba", 0x1E7D854, 0x20
.global sTitleop1Gfx19_2
sTitleop1Gfx19_2:
.incbin "baserom.gba", 0x1E7D874, 0x140
.global sTitleop1Sprites19
sTitleop1Sprites19:
.4byte sTitleop1Gfx19
.incbin "baserom.gba", 0x1E7D9B8, 0xC
.4byte sTitleop1Gfx19_2
.incbin "baserom.gba", 0x1E7D9C8, 0x14
.global sTitleop1Gfx20
sTitleop1Gfx20:
.incbin "baserom.gba", 0x1E7D9DC, 0x40
.global sTitleop1Sprites20
sTitleop1Sprites20:
.incbin "baserom.gba", 0x1E7DA1C, 0x8
.4byte sTitleop1Gfx20
.incbin "baserom.gba", 0x1E7DA28, 0x14
.global sTitleop1Gfx21
sTitleop1Gfx21:
.incbin "baserom.gba", 0x1E7DA3C, 0x100
.global sTitleop1Gfx21_2
sTitleop1Gfx21_2:
.incbin "baserom.gba", 0x1E7DB3C, 0x60
.global sTitleop1Gfx21_3
sTitleop1Gfx21_3:
.incbin "baserom.gba", 0x1E7DB9C, 0x40
.global sTitleop1Sprites21
sTitleop1Sprites21:
.4byte sTitleop1Gfx21
.incbin "baserom.gba", 0x1E7DBE0, 0xC
.4byte sTitleop1Gfx21_2
.incbin "baserom.gba", 0x1E7DBF0, 0xC
.4byte sTitleop1Gfx21_3
.incbin "baserom.gba", 0x1E7DC00, 0xC
.global sTitleop1Gfx22
sTitleop1Gfx22:
.incbin "baserom.gba", 0x1E7DC0C, 0x40
.global sTitleop1Gfx22_2
sTitleop1Gfx22_2:
.incbin "baserom.gba", 0x1E7DC4C, 0x160
.global sTitleop1Sprites22
sTitleop1Sprites22:
.4byte sTitleop1Gfx22
.incbin "baserom.gba", 0x1E7DDB0, 0xC
.4byte sTitleop1Gfx22_2
.incbin "baserom.gba", 0x1E7DDC0, 0x14
.global sTitleop1Gfx23
sTitleop1Gfx23:
.incbin "baserom.gba", 0x1E7DDD4, 0x20
.global sTitleop1Gfx23_2
sTitleop1Gfx23_2:
.incbin "baserom.gba", 0x1E7DDF4, 0x80
.global sTitleop1Sprites23
sTitleop1Sprites23:
.4byte sTitleop1Gfx23
.incbin "baserom.gba", 0x1E7DE78, 0xC
.4byte sTitleop1Gfx23_2
.incbin "baserom.gba", 0x1E7DE88, 0x14
.global sTitleop1Gfx24
sTitleop1Gfx24:
.incbin "baserom.gba", 0x1E7DE9C, 0x100
.global sTitleop1Gfx24_2
sTitleop1Gfx24_2:
.incbin "baserom.gba", 0x1E7DF9C, 0x60
.global sTitleop1Gfx24_3
sTitleop1Gfx24_3:
.incbin "baserom.gba", 0x1E7DFFC, 0x40
.global sTitleop1Sprites24
sTitleop1Sprites24:
.4byte sTitleop1Gfx24
.incbin "baserom.gba", 0x1E7E040, 0xC
.4byte sTitleop1Gfx24_2
.incbin "baserom.gba", 0x1E7E050, 0xC
.4byte sTitleop1Gfx24_3
.incbin "baserom.gba", 0x1E7E060, 0xC
.global sTitleop1Gfx25
sTitleop1Gfx25:
.incbin "baserom.gba", 0x1E7E06C, 0x1E0
.global sTitleop1Sprites25
sTitleop1Sprites25:
.4byte sTitleop1Gfx25
.incbin "baserom.gba", 0x1E7E250, 0x14
.global sTitleop1Gfx26
sTitleop1Gfx26:
.incbin "baserom.gba", 0x1E7E264, 0x180
.global sTitleop1Sprites26
sTitleop1Sprites26:
.4byte sTitleop1Gfx26
.incbin "baserom.gba", 0x1E7E3E8, 0x14
.global sTitleop1Gfx27
sTitleop1Gfx27:
.incbin "baserom.gba", 0x1E7E3FC, 0x40
.global sTitleop1Sprites27
sTitleop1Sprites27:
.4byte sTitleop1Gfx27
.incbin "baserom.gba", 0x1E7E440, 0xC
.global sTitleop1Gfx28
sTitleop1Gfx28:
.incbin "baserom.gba", 0x1E7E44C, 0x80
.global sTitleop1Sprites28
sTitleop1Sprites28:
.4byte sTitleop1Gfx28
.incbin "baserom.gba", 0x1E7E4D0, 0xC
.global sTitleop1Gfx29
sTitleop1Gfx29:
.incbin "baserom.gba", 0x1E7E4DC, 0x20
.global sTitleop1Sprites29
sTitleop1Sprites29:
.4byte sTitleop1Gfx29
.incbin "baserom.gba", 0x1E7E500, 0xC
.global sTitleop1Gfx30
sTitleop1Gfx30:
.incbin "baserom.gba", 0x1E7E50C, 0x20
.global sTitleop1Sprites30
sTitleop1Sprites30:
.4byte sTitleop1Gfx30
.incbin "baserom.gba", 0x1E7E530, 0xC
.global sTitleop1Gfx31
sTitleop1Gfx31:
.incbin "baserom.gba", 0x1E7E53C, 0x20
.global sTitleop1Sprites31
sTitleop1Sprites31:
.4byte sTitleop1Gfx31
.incbin "baserom.gba", 0x1E7E560, 0xC
.global sTitleop1Gfx32
sTitleop1Gfx32:
.incbin "baserom.gba", 0x1E7E56C, 0x20
.global sTitleop1Sprites32
sTitleop1Sprites32:
.4byte sTitleop1Gfx32
.incbin "baserom.gba", 0x1E7E590, 0xC
.global sAxPosesTitleop1
sAxPosesTitleop1:
.4byte sTitleop1Pose1
.4byte sTitleop1Pose2
.4byte sTitleop1Pose3
.4byte sTitleop1Pose4
.4byte sTitleop1Pose5
.4byte sTitleop1Pose6
.4byte sTitleop1Pose7
.4byte sTitleop1Pose8
.4byte sTitleop1Pose9
.4byte sTitleop1Pose10
.4byte sTitleop1Pose11
.4byte sTitleop1Pose12
.4byte sTitleop1Pose13
.4byte sTitleop1Pose14
.4byte sTitleop1Pose15
.4byte sTitleop1Pose16
.4byte sTitleop1Pose17
.4byte sTitleop1Pose18
.4byte sTitleop1Pose19
.4byte sTitleop1Pose20
.4byte sTitleop1Pose21
.4byte sTitleop1Pose22
.4byte sTitleop1Pose23
.4byte sTitleop1Pose24
.4byte sTitleop1Pose25
.4byte sTitleop1Pose26
.4byte sTitleop1Pose27
.4byte sTitleop1Pose28
.4byte sTitleop1Pose29
.4byte sTitleop1Pose30
.4byte sTitleop1Pose31
.4byte sTitleop1Pose32
.4byte sTitleop1Pose33
.4byte sTitleop1Pose34
.4byte sTitleop1Pose35
.4byte sTitleop1Pose36
.4byte sTitleop1Pose37
.4byte sTitleop1Pose38
.4byte sTitleop1Pose39
.4byte sTitleop1Pose40
.4byte sTitleop1Pose41
.4byte sTitleop1Pose42
.4byte sTitleop1Pose43
.4byte sTitleop1Pose44
.4byte sTitleop1Pose45
.4byte sTitleop1Pose46
.4byte sTitleop1Pose47
.4byte sTitleop1Pose48
.4byte sTitleop1Pose49
.4byte sTitleop1Pose50
.4byte sTitleop1Pose51
.4byte sTitleop1Pose52
.4byte sTitleop1Pose53
.4byte sTitleop1Pose54
.4byte sTitleop1Pose55
.4byte sTitleop1Pose56
.4byte sTitleop1Pose57
.4byte sTitleop1Pose58
.4byte sTitleop1Pose59
.4byte sTitleop1Pose60
.global sTitleop1AnimTable1
sTitleop1AnimTable1:
.4byte sTitleop1Anims_1_1
.4byte sTitleop1Anims_1_2
.4byte sTitleop1Anims_1_3
.4byte sTitleop1Anims_1_4
.4byte sTitleop1Anims_1_5
.4byte sTitleop1Anims_1_6
.4byte sTitleop1Anims_1_7
.4byte sTitleop1Anims_1_8
.global sTitleop1AnimTable2
sTitleop1AnimTable2:
.4byte sTitleop1Anims_2_1
.4byte sTitleop1Anims_2_2
.4byte sTitleop1Anims_2_3
.4byte sTitleop1Anims_2_4
.4byte sTitleop1Anims_2_5
.4byte sTitleop1Anims_2_6
.4byte sTitleop1Anims_2_7
.4byte sTitleop1Anims_2_8
.global sAxAnimationsTitleop1
sAxAnimationsTitleop1:
.4byte sTitleop1AnimTable1
.4byte sTitleop1AnimTable2
.global sAxSpritesTitleop1
sAxSpritesTitleop1:
.4byte sTitleop1Sprites1
.4byte sTitleop1Sprites2
.4byte sTitleop1Sprites3
.4byte sTitleop1Sprites4
.4byte sTitleop1Sprites5
.4byte sTitleop1Sprites6
.4byte sTitleop1Sprites7
.4byte sTitleop1Sprites8
.4byte sTitleop1Sprites9
.4byte sTitleop1Sprites10
.4byte sTitleop1Sprites11
.4byte sTitleop1Sprites12
.4byte sTitleop1Sprites13
.4byte sTitleop1Sprites14
.4byte sTitleop1Sprites15
.4byte sTitleop1Sprites16
.4byte sTitleop1Sprites17
.4byte sTitleop1Sprites18
.4byte sTitleop1Sprites19
.4byte sTitleop1Sprites20
.4byte sTitleop1Sprites21
.4byte sTitleop1Sprites22
.4byte sTitleop1Sprites23
.4byte sTitleop1Sprites24
.4byte sTitleop1Sprites25
.4byte sTitleop1Sprites26
.4byte sTitleop1Sprites27
.4byte sTitleop1Sprites28
.4byte sTitleop1Sprites29
.4byte sTitleop1Sprites30
.4byte sTitleop1Sprites31
.4byte sTitleop1Sprites32
.global sAxMainTitleop1
sAxMainTitleop1:
.4byte sAxPosesTitleop1
.4byte sAxAnimationsTitleop1
.incbin "baserom.gba", 0x1E7E75C, 0x4
.4byte sAxSpritesTitleop1
.4byte 0
.global gAxTitleop2
gAxTitleop2:
.string "SIRO"
.4byte sAxMainTitleop2
.4byte 0, 0
.global sTitleop2Pose1
sTitleop2Pose1:
.incbin "baserom.gba", 0x1E7E778, 0x14
.global sTitleop2Anims_1_1
sTitleop2Anims_1_1:
.incbin "baserom.gba", 0x1E7E78C, 0x18
.global sTitleop2Anims_1_2
sTitleop2Anims_1_2:
.incbin "baserom.gba", 0x1E7E7A4, 0xCC
.global sTitleop2Anims_1_3
sTitleop2Anims_1_3:
.incbin "baserom.gba", 0x1E7E870, 0x18
.global sTitleop2Anims_1_4
sTitleop2Anims_1_4:
.incbin "baserom.gba", 0x1E7E888, 0x18
.global sTitleop2Anims_1_5
sTitleop2Anims_1_5:
.incbin "baserom.gba", 0x1E7E8A0, 0x18
.global sTitleop2Anims_1_6
sTitleop2Anims_1_6:
.incbin "baserom.gba", 0x1E7E8B8, 0x18
.global sTitleop2Anims_1_7
sTitleop2Anims_1_7:
.incbin "baserom.gba", 0x1E7E8D0, 0x18
.global sTitleop2Anims_1_8
sTitleop2Anims_1_8:
.incbin "baserom.gba", 0x1E7E8E8, 0x18
.global sTitleop2Gfx1
sTitleop2Gfx1:
.incbin "baserom.gba", 0x1E7E900, 0x100
.global sTitleop2Gfx1_2
sTitleop2Gfx1_2:
.incbin "baserom.gba", 0x1E7EA00, 0x60
.global sTitleop2Sprites1
sTitleop2Sprites1:
.4byte sTitleop2Gfx1
.incbin "baserom.gba", 0x1E7EA64, 0xC
.4byte sTitleop2Gfx1_2
.incbin "baserom.gba", 0x1E7EA74, 0x14
.global sAxPosesTitleop2
sAxPosesTitleop2:
.4byte sTitleop2Pose1
.global sTitleop2AnimTable1
sTitleop2AnimTable1:
.4byte sTitleop2Anims_1_1
.4byte sTitleop2Anims_1_2
.4byte sTitleop2Anims_1_3
.4byte sTitleop2Anims_1_4
.4byte sTitleop2Anims_1_5
.4byte sTitleop2Anims_1_6
.4byte sTitleop2Anims_1_7
.4byte sTitleop2Anims_1_8
.global sAxAnimationsTitleop2
sAxAnimationsTitleop2:
.4byte sTitleop2AnimTable1
.global sAxSpritesTitleop2
sAxSpritesTitleop2:
.4byte sTitleop2Sprites1
.global sAxMainTitleop2
sAxMainTitleop2:
.4byte sAxPosesTitleop2
.4byte sAxAnimationsTitleop2
.incbin "baserom.gba", 0x1E7EABC, 0x4
.4byte sAxSpritesTitleop2
.4byte 0
.global gTitleopPal
gTitleopPal:
.incbin "graphics/ornament/pal/titleop.pmdpal"
