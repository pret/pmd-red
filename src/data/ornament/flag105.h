const RGB_Struct gFlag105Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag105.pmdpal") };

static const axmain sAxMainFlag105;
const SiroArchive gAxFlag105 = {"SIRO", &sAxMainFlag105};

static const ax_pose sFlag105Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag105Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag105Gfx1[] = INCBIN_U8("graphics/ornament/Flag105/sprite_1.4bpp");
static const ax_sprite sFlag105Sprites1[] = {
	{sFlag105Gfx1, ARRAY_COUNT(sFlag105Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx2[] = INCBIN_U8("graphics/ornament/Flag105/sprite_2.4bpp");
static const ax_sprite sFlag105Sprites2[] = {
	{sFlag105Gfx2, ARRAY_COUNT(sFlag105Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx3[] = INCBIN_U8("graphics/ornament/Flag105/sprite_3.4bpp");
static const ax_sprite sFlag105Sprites3[] = {
	{sFlag105Gfx3, ARRAY_COUNT(sFlag105Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx4[] = INCBIN_U8("graphics/ornament/Flag105/sprite_4.4bpp");
static const ax_sprite sFlag105Sprites4[] = {
	{sFlag105Gfx4, ARRAY_COUNT(sFlag105Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx5[] = INCBIN_U8("graphics/ornament/Flag105/sprite_5.4bpp");
static const ax_sprite sFlag105Sprites5[] = {
	{sFlag105Gfx5, ARRAY_COUNT(sFlag105Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx6[] = INCBIN_U8("graphics/ornament/Flag105/sprite_6.4bpp");
static const ax_sprite sFlag105Sprites6[] = {
	{sFlag105Gfx6, ARRAY_COUNT(sFlag105Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag105[] = {
	sFlag105Pose1,
	sFlag105Pose2,
	sFlag105Pose3,
	sFlag105Pose4,
	sFlag105Pose5,
	sFlag105Pose6,
};

static const ax_anim *const sFlag105AnimTable1[] = {
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag105[] = {
	sFlag105AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag105[] = {
	sFlag105Sprites1,
	sFlag105Sprites2,
	sFlag105Sprites3,
	sFlag105Sprites4,
	sFlag105Sprites5,
	sFlag105Sprites6,
};

static const axmain sAxMainFlag105 = {
	.poses = sAxPosesFlag105,
	.animations = sAxAnimationsFlag105,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag105),
	.spriteData = sAxSpritesFlag105,
	.positions = NULL,
};
