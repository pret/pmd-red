.global gAxStatue
gAxStatue:
ax_siro sAxMainStatue
sStatuePose1:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose2:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose3:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose4:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose5:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose6:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose7:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose8:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose9:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose10:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose11:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose12:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
sStatuePose13:
ax_pose 0, 0x01e6, 0x84f0, 0xdc00
ax_pose_terminator
.align 2
sStatueAnims_1_1:
ax_anim 6, 0, 0, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_2_1:
ax_anim 6, 0, 1, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_3_1:
ax_anim 6, 0, 2, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_4_1:
ax_anim 6, 0, 3, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_5_1:
ax_anim 6, 0, 4, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_6_1:
ax_anim 6, 0, 5, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_7_1:
ax_anim 6, 0, 6, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_8_1:
ax_anim 6, 0, 7, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_9_1:
ax_anim 6, 0, 8, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_10_1:
ax_anim 6, 0, 9, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_11_1:
ax_anim 6, 0, 10, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_12_1:
ax_anim 6, 0, 11, 0, 0, 0, 0,
ax_anim_terminator
.align 2
sStatueAnims_13_1:
ax_anim 6, 0, 12, 0, 0, 0, 0,
ax_anim_terminator
sStatueGfx1:
.incbin "baserom.gba", 0x1659D1C, 0x200
sStatueSprites1:
ax_sprite sStatueGfx1, 0x200
ax_sprite_terminator
sAxPosesStatue:
.4byte sStatuePose1
.4byte sStatuePose2
.4byte sStatuePose3
.4byte sStatuePose4
.4byte sStatuePose5
.4byte sStatuePose6
.4byte sStatuePose7
.4byte sStatuePose8
.4byte sStatuePose9
.4byte sStatuePose10
.4byte sStatuePose11
.4byte sStatuePose12
.4byte sStatuePose13
sAxPositionsStatue:
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
.2byte   -1,  -11, 	 -12,  -11, 	  12,  -11, 	  -1,   -6
sStatueAnimTable1:
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
.4byte sStatueAnims_1_1
sStatueAnimTable2:
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
.4byte sStatueAnims_2_1
sStatueAnimTable3:
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
.4byte sStatueAnims_3_1
sStatueAnimTable4:
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
.4byte sStatueAnims_4_1
sStatueAnimTable5:
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
.4byte sStatueAnims_5_1
sStatueAnimTable6:
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
.4byte sStatueAnims_6_1
sStatueAnimTable7:
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
.4byte sStatueAnims_7_1
sStatueAnimTable8:
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
.4byte sStatueAnims_8_1
sStatueAnimTable9:
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
.4byte sStatueAnims_9_1
sStatueAnimTable10:
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
.4byte sStatueAnims_10_1
sStatueAnimTable11:
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
.4byte sStatueAnims_11_1
sStatueAnimTable12:
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
.4byte sStatueAnims_12_1
sStatueAnimTable13:
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
.4byte sStatueAnims_13_1
sAxAnimationsStatue:
.4byte sStatueAnimTable1
.4byte sStatueAnimTable2
.4byte sStatueAnimTable3
.4byte sStatueAnimTable4
.4byte sStatueAnimTable5
.4byte sStatueAnimTable6
.4byte sStatueAnimTable7
.4byte sStatueAnimTable8
.4byte sStatueAnimTable9
.4byte sStatueAnimTable10
.4byte sStatueAnimTable11
.4byte sStatueAnimTable12
.4byte sStatueAnimTable13
sAxSpritesStatue:
.4byte sStatueSprites1
sAxMainStatue:
ax_main sAxPosesStatue, sAxAnimationsStatue, 13, sAxSpritesStatue, sAxPositionsStatue
