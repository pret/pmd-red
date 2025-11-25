const RGB_Struct gFlag113Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag113.pmdpal") };

static const axmain sAxMainFlag113;
const SiroArchive gAxFlag113 = {"SIRO", &sAxMainFlag113};

static const ax_pose sFlag113Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag113Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag113Gfx1[] = INCBIN_U8("graphics/ornament/Flag113/sprite_1.4bpp");
static const ax_sprite sFlag113Sprites1[] = {
	{sFlag113Gfx1, ARRAY_COUNT(sFlag113Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx2[] = INCBIN_U8("graphics/ornament/Flag113/sprite_2.4bpp");
static const ax_sprite sFlag113Sprites2[] = {
	{sFlag113Gfx2, ARRAY_COUNT(sFlag113Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx3[] = INCBIN_U8("graphics/ornament/Flag113/sprite_3.4bpp");
static const ax_sprite sFlag113Sprites3[] = {
	{sFlag113Gfx3, ARRAY_COUNT(sFlag113Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx4[] = INCBIN_U8("graphics/ornament/Flag113/sprite_4.4bpp");
static const ax_sprite sFlag113Sprites4[] = {
	{sFlag113Gfx4, ARRAY_COUNT(sFlag113Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx5[] = INCBIN_U8("graphics/ornament/Flag113/sprite_5.4bpp");
static const ax_sprite sFlag113Sprites5[] = {
	{sFlag113Gfx5, ARRAY_COUNT(sFlag113Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx6[] = INCBIN_U8("graphics/ornament/Flag113/sprite_6.4bpp");
static const ax_sprite sFlag113Sprites6[] = {
	{sFlag113Gfx6, ARRAY_COUNT(sFlag113Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag113[] = {
	sFlag113Pose1,
	sFlag113Pose2,
	sFlag113Pose3,
	sFlag113Pose4,
	sFlag113Pose5,
	sFlag113Pose6,
};

static const ax_anim *const sFlag113AnimTable1[] = {
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag113[] = {
	sFlag113AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag113[] = {
	sFlag113Sprites1,
	sFlag113Sprites2,
	sFlag113Sprites3,
	sFlag113Sprites4,
	sFlag113Sprites5,
	sFlag113Sprites6,
};

static const axmain sAxMainFlag113 = {
	.poses = sAxPosesFlag113,
	.animations = sAxAnimationsFlag113,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag113),
	.spriteData = sAxSpritesFlag113,
	.positions = NULL,
};
