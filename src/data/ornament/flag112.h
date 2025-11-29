const RGB_Struct gFlag112Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag112.pmdpal") };

static const axmain sAxMainFlag112;
const SiroArchive gAxFlag112 = {"SIRO", &sAxMainFlag112};

static const ax_pose sFlag112Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag112Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag112Gfx1[] = INCBIN_U8("graphics/ornament/Flag112/sprite_1.4bpp");
static const ax_sprite sFlag112Sprites1[] = {
	{sFlag112Gfx1, ARRAY_COUNT(sFlag112Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx2[] = INCBIN_U8("graphics/ornament/Flag112/sprite_2.4bpp");
static const ax_sprite sFlag112Sprites2[] = {
	{sFlag112Gfx2, ARRAY_COUNT(sFlag112Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx3[] = INCBIN_U8("graphics/ornament/Flag112/sprite_3.4bpp");
static const ax_sprite sFlag112Sprites3[] = {
	{sFlag112Gfx3, ARRAY_COUNT(sFlag112Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx4[] = INCBIN_U8("graphics/ornament/Flag112/sprite_4.4bpp");
static const ax_sprite sFlag112Sprites4[] = {
	{sFlag112Gfx4, ARRAY_COUNT(sFlag112Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx5[] = INCBIN_U8("graphics/ornament/Flag112/sprite_5.4bpp");
static const ax_sprite sFlag112Sprites5[] = {
	{sFlag112Gfx5, ARRAY_COUNT(sFlag112Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx6[] = INCBIN_U8("graphics/ornament/Flag112/sprite_6.4bpp");
static const ax_sprite sFlag112Sprites6[] = {
	{sFlag112Gfx6, ARRAY_COUNT(sFlag112Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag112[] = {
	sFlag112Pose1,
	sFlag112Pose2,
	sFlag112Pose3,
	sFlag112Pose4,
	sFlag112Pose5,
	sFlag112Pose6,
};

static const ax_anim *const sFlag112AnimTable1[] = {
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag112[] = {
	sFlag112AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag112[] = {
	sFlag112Sprites1,
	sFlag112Sprites2,
	sFlag112Sprites3,
	sFlag112Sprites4,
	sFlag112Sprites5,
	sFlag112Sprites6,
};

static const axmain sAxMainFlag112 = {
	.poses = sAxPosesFlag112,
	.animations = sAxAnimationsFlag112,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag112),
	.spriteData = sAxSpritesFlag112,
	.positions = NULL,
};
