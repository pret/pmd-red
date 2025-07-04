const RGB gFlag111Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag111.pmdpal") };

static const axmain sAxMainFlag111;
const SiroArchive gAxFlag111 = {"SIRO", &sAxMainFlag111};

static const ax_pose sFlag111Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag111Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag111Gfx1[] = INCBIN_U8("graphics/ornament/Flag111/sprite_1.4bpp");
static const ax_sprite sFlag111Sprites1[] = {
	{sFlag111Gfx1, ARRAY_COUNT(sFlag111Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx2[] = INCBIN_U8("graphics/ornament/Flag111/sprite_2.4bpp");
static const ax_sprite sFlag111Sprites2[] = {
	{sFlag111Gfx2, ARRAY_COUNT(sFlag111Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx3[] = INCBIN_U8("graphics/ornament/Flag111/sprite_3.4bpp");
static const ax_sprite sFlag111Sprites3[] = {
	{sFlag111Gfx3, ARRAY_COUNT(sFlag111Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx4[] = INCBIN_U8("graphics/ornament/Flag111/sprite_4.4bpp");
static const ax_sprite sFlag111Sprites4[] = {
	{sFlag111Gfx4, ARRAY_COUNT(sFlag111Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx5[] = INCBIN_U8("graphics/ornament/Flag111/sprite_5.4bpp");
static const ax_sprite sFlag111Sprites5[] = {
	{sFlag111Gfx5, ARRAY_COUNT(sFlag111Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx6[] = INCBIN_U8("graphics/ornament/Flag111/sprite_6.4bpp");
static const ax_sprite sFlag111Sprites6[] = {
	{sFlag111Gfx6, ARRAY_COUNT(sFlag111Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag111[] = {
	sFlag111Pose1,
	sFlag111Pose2,
	sFlag111Pose3,
	sFlag111Pose4,
	sFlag111Pose5,
	sFlag111Pose6,
};

static const ax_anim *const sFlag111AnimTable1[] = {
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag111[] = {
	sFlag111AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag111[] = {
	sFlag111Sprites1,
	sFlag111Sprites2,
	sFlag111Sprites3,
	sFlag111Sprites4,
	sFlag111Sprites5,
	sFlag111Sprites6,
};

static const axmain sAxMainFlag111 = {
	.poses = sAxPosesFlag111,
	.animations = sAxAnimationsFlag111,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag111),
	.spriteData = sAxSpritesFlag111,
	.positions = NULL,
};
