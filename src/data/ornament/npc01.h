static const axmain sAxMainNpc01;
const SiroArchive gAxNpc01 = {"SIRO", &sAxMainNpc01};

static const ax_pose sNpc01Pose1[] = {
	AX_POSE(0, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc01Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc01Gfx1[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1.4bpp");
static const u8 sNpc01Gfx1_2[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1_2.4bpp");
static const u8 sNpc01Gfx1_3[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1_3.4bpp");
static const u8 sNpc01Gfx1_4[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1_4.4bpp");
static const ax_sprite sNpc01Sprites1[] = {
	{NULL, 32},
	{sNpc01Gfx1, ARRAY_COUNT(sNpc01Gfx1)},
	{NULL, 64},
	{sNpc01Gfx1_2, ARRAY_COUNT(sNpc01Gfx1_2)},
	{NULL, 32},
	{sNpc01Gfx1_3, ARRAY_COUNT(sNpc01Gfx1_3)},
	{NULL, 32},
	{sNpc01Gfx1_4, ARRAY_COUNT(sNpc01Gfx1_4)},
	{NULL, 32},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc01[] = {
	sNpc01Pose1,
};

static const ax_anim *const sNpc01AnimTable1[] = {
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc01[] = {
	sNpc01AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc01[] = {
	sNpc01Sprites1,
};

static const axmain sAxMainNpc01 = {
	.poses = sAxPosesNpc01,
	.animations = sAxAnimationsNpc01,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc01),
	.spriteData = sAxSpritesNpc01,
	.positions = NULL,
};
