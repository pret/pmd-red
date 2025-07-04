const RGB gFlag104Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag104.pmdpal") };

static const axmain sAxMainFlag104;
const SiroArchive gAxFlag104 = {"SIRO", &sAxMainFlag104};

static const ax_pose sFlag104Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag104Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag104Gfx1[] = INCBIN_U8("graphics/ornament/Flag104/sprite_1.4bpp");
static const ax_sprite sFlag104Sprites1[] = {
	{sFlag104Gfx1, ARRAY_COUNT(sFlag104Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx2[] = INCBIN_U8("graphics/ornament/Flag104/sprite_2.4bpp");
static const ax_sprite sFlag104Sprites2[] = {
	{sFlag104Gfx2, ARRAY_COUNT(sFlag104Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx3[] = INCBIN_U8("graphics/ornament/Flag104/sprite_3.4bpp");
static const ax_sprite sFlag104Sprites3[] = {
	{sFlag104Gfx3, ARRAY_COUNT(sFlag104Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx4[] = INCBIN_U8("graphics/ornament/Flag104/sprite_4.4bpp");
static const ax_sprite sFlag104Sprites4[] = {
	{sFlag104Gfx4, ARRAY_COUNT(sFlag104Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx5[] = INCBIN_U8("graphics/ornament/Flag104/sprite_5.4bpp");
static const ax_sprite sFlag104Sprites5[] = {
	{sFlag104Gfx5, ARRAY_COUNT(sFlag104Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx6[] = INCBIN_U8("graphics/ornament/Flag104/sprite_6.4bpp");
static const ax_sprite sFlag104Sprites6[] = {
	{sFlag104Gfx6, ARRAY_COUNT(sFlag104Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag104[] = {
	sFlag104Pose1,
	sFlag104Pose2,
	sFlag104Pose3,
	sFlag104Pose4,
	sFlag104Pose5,
	sFlag104Pose6,
};

static const ax_anim *const sFlag104AnimTable1[] = {
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag104[] = {
	sFlag104AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag104[] = {
	sFlag104Sprites1,
	sFlag104Sprites2,
	sFlag104Sprites3,
	sFlag104Sprites4,
	sFlag104Sprites5,
	sFlag104Sprites6,
};

static const axmain sAxMainFlag104 = {
	.poses = sAxPosesFlag104,
	.animations = sAxAnimationsFlag104,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag104),
	.spriteData = sAxSpritesFlag104,
	.positions = NULL,
};
