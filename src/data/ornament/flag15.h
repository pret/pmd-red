const RGB gFlag15Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag15.pmdpal") };

static const axmain sAxMainFlag15;
const SiroArchive gAxFlag15 = {"SIRO", &sAxMainFlag15};

static const ax_pose sFlag15Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag15Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag15Gfx1[] = INCBIN_U8("graphics/ornament/Flag15/sprite_1.4bpp");
static const ax_sprite sFlag15Sprites1[] = {
	{sFlag15Gfx1, ARRAY_COUNT(sFlag15Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx2[] = INCBIN_U8("graphics/ornament/Flag15/sprite_2.4bpp");
static const ax_sprite sFlag15Sprites2[] = {
	{sFlag15Gfx2, ARRAY_COUNT(sFlag15Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx3[] = INCBIN_U8("graphics/ornament/Flag15/sprite_3.4bpp");
static const ax_sprite sFlag15Sprites3[] = {
	{sFlag15Gfx3, ARRAY_COUNT(sFlag15Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx4[] = INCBIN_U8("graphics/ornament/Flag15/sprite_4.4bpp");
static const ax_sprite sFlag15Sprites4[] = {
	{sFlag15Gfx4, ARRAY_COUNT(sFlag15Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx5[] = INCBIN_U8("graphics/ornament/Flag15/sprite_5.4bpp");
static const ax_sprite sFlag15Sprites5[] = {
	{sFlag15Gfx5, ARRAY_COUNT(sFlag15Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx6[] = INCBIN_U8("graphics/ornament/Flag15/sprite_6.4bpp");
static const ax_sprite sFlag15Sprites6[] = {
	{sFlag15Gfx6, ARRAY_COUNT(sFlag15Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag15[] = {
	sFlag15Pose1,
	sFlag15Pose2,
	sFlag15Pose3,
	sFlag15Pose4,
	sFlag15Pose5,
	sFlag15Pose6,
};

static const ax_anim *const sFlag15AnimTable1[] = {
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag15[] = {
	sFlag15AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag15[] = {
	sFlag15Sprites1,
	sFlag15Sprites2,
	sFlag15Sprites3,
	sFlag15Sprites4,
	sFlag15Sprites5,
	sFlag15Sprites6,
};

static const axmain sAxMainFlag15 = {
	.poses = sAxPosesFlag15,
	.animations = sAxAnimationsFlag15,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag15),
	.spriteData = sAxSpritesFlag15,
	.positions = NULL,
};
