const RGB_Struct gFlag102Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag102.pmdpal") };

static const axmain sAxMainFlag102;
const SiroArchive gAxFlag102 = {"SIRO", &sAxMainFlag102};

static const ax_pose sFlag102Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag102Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag102Gfx1[] = INCBIN_U8("graphics/ornament/Flag102/sprite_1.4bpp");
static const ax_sprite sFlag102Sprites1[] = {
	{sFlag102Gfx1, ARRAY_COUNT(sFlag102Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx2[] = INCBIN_U8("graphics/ornament/Flag102/sprite_2.4bpp");
static const ax_sprite sFlag102Sprites2[] = {
	{sFlag102Gfx2, ARRAY_COUNT(sFlag102Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx3[] = INCBIN_U8("graphics/ornament/Flag102/sprite_3.4bpp");
static const ax_sprite sFlag102Sprites3[] = {
	{sFlag102Gfx3, ARRAY_COUNT(sFlag102Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx4[] = INCBIN_U8("graphics/ornament/Flag102/sprite_4.4bpp");
static const ax_sprite sFlag102Sprites4[] = {
	{sFlag102Gfx4, ARRAY_COUNT(sFlag102Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx5[] = INCBIN_U8("graphics/ornament/Flag102/sprite_5.4bpp");
static const ax_sprite sFlag102Sprites5[] = {
	{sFlag102Gfx5, ARRAY_COUNT(sFlag102Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx6[] = INCBIN_U8("graphics/ornament/Flag102/sprite_6.4bpp");
static const ax_sprite sFlag102Sprites6[] = {
	{sFlag102Gfx6, ARRAY_COUNT(sFlag102Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag102[] = {
	sFlag102Pose1,
	sFlag102Pose2,
	sFlag102Pose3,
	sFlag102Pose4,
	sFlag102Pose5,
	sFlag102Pose6,
};

static const ax_anim *const sFlag102AnimTable1[] = {
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag102[] = {
	sFlag102AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag102[] = {
	sFlag102Sprites1,
	sFlag102Sprites2,
	sFlag102Sprites3,
	sFlag102Sprites4,
	sFlag102Sprites5,
	sFlag102Sprites6,
};

static const axmain sAxMainFlag102 = {
	.poses = sAxPosesFlag102,
	.animations = sAxAnimationsFlag102,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag102),
	.spriteData = sAxSpritesFlag102,
	.positions = NULL,
};
