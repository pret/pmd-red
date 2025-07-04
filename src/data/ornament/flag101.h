const RGB gFlag101Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag101.pmdpal") };

static const axmain sAxMainFlag101;
const SiroArchive gAxFlag101 = {"SIRO", &sAxMainFlag101};

static const ax_pose sFlag101Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag101Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag101Gfx1[] = INCBIN_U8("graphics/ornament/Flag101/sprite_1.4bpp");
static const ax_sprite sFlag101Sprites1[] = {
	{sFlag101Gfx1, ARRAY_COUNT(sFlag101Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx2[] = INCBIN_U8("graphics/ornament/Flag101/sprite_2.4bpp");
static const ax_sprite sFlag101Sprites2[] = {
	{sFlag101Gfx2, ARRAY_COUNT(sFlag101Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx3[] = INCBIN_U8("graphics/ornament/Flag101/sprite_3.4bpp");
static const ax_sprite sFlag101Sprites3[] = {
	{sFlag101Gfx3, ARRAY_COUNT(sFlag101Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx4[] = INCBIN_U8("graphics/ornament/Flag101/sprite_4.4bpp");
static const ax_sprite sFlag101Sprites4[] = {
	{sFlag101Gfx4, ARRAY_COUNT(sFlag101Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx5[] = INCBIN_U8("graphics/ornament/Flag101/sprite_5.4bpp");
static const ax_sprite sFlag101Sprites5[] = {
	{sFlag101Gfx5, ARRAY_COUNT(sFlag101Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx6[] = INCBIN_U8("graphics/ornament/Flag101/sprite_6.4bpp");
static const ax_sprite sFlag101Sprites6[] = {
	{sFlag101Gfx6, ARRAY_COUNT(sFlag101Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag101[] = {
	sFlag101Pose1,
	sFlag101Pose2,
	sFlag101Pose3,
	sFlag101Pose4,
	sFlag101Pose5,
	sFlag101Pose6,
};

static const ax_anim *const sFlag101AnimTable1[] = {
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag101[] = {
	sFlag101AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag101[] = {
	sFlag101Sprites1,
	sFlag101Sprites2,
	sFlag101Sprites3,
	sFlag101Sprites4,
	sFlag101Sprites5,
	sFlag101Sprites6,
};

static const axmain sAxMainFlag101 = {
	.poses = sAxPosesFlag101,
	.animations = sAxAnimationsFlag101,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag101),
	.spriteData = sAxSpritesFlag101,
	.positions = NULL,
};
