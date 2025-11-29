static const axmain sAxMainFlag109;
const SiroArchive gAxFlag109 = {"SIRO", &sAxMainFlag109};

static const ax_pose sFlag109Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag109Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag109Gfx1[] = INCBIN_U8("graphics/ornament/Flag109/sprite_1.4bpp");
static const ax_sprite sFlag109Sprites1[] = {
	{sFlag109Gfx1, ARRAY_COUNT(sFlag109Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx2[] = INCBIN_U8("graphics/ornament/Flag109/sprite_2.4bpp");
static const ax_sprite sFlag109Sprites2[] = {
	{sFlag109Gfx2, ARRAY_COUNT(sFlag109Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx3[] = INCBIN_U8("graphics/ornament/Flag109/sprite_3.4bpp");
static const ax_sprite sFlag109Sprites3[] = {
	{sFlag109Gfx3, ARRAY_COUNT(sFlag109Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx4[] = INCBIN_U8("graphics/ornament/Flag109/sprite_4.4bpp");
static const ax_sprite sFlag109Sprites4[] = {
	{sFlag109Gfx4, ARRAY_COUNT(sFlag109Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx5[] = INCBIN_U8("graphics/ornament/Flag109/sprite_5.4bpp");
static const ax_sprite sFlag109Sprites5[] = {
	{sFlag109Gfx5, ARRAY_COUNT(sFlag109Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx6[] = INCBIN_U8("graphics/ornament/Flag109/sprite_6.4bpp");
static const ax_sprite sFlag109Sprites6[] = {
	{sFlag109Gfx6, ARRAY_COUNT(sFlag109Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag109[] = {
	sFlag109Pose1,
	sFlag109Pose2,
	sFlag109Pose3,
	sFlag109Pose4,
	sFlag109Pose5,
	sFlag109Pose6,
};

static const ax_anim *const sFlag109AnimTable1[] = {
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag109[] = {
	sFlag109AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag109[] = {
	sFlag109Sprites1,
	sFlag109Sprites2,
	sFlag109Sprites3,
	sFlag109Sprites4,
	sFlag109Sprites5,
	sFlag109Sprites6,
};

static const axmain sAxMainFlag109 = {
	.poses = sAxPosesFlag109,
	.animations = sAxAnimationsFlag109,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag109),
	.spriteData = sAxSpritesFlag109,
	.positions = NULL,
};
const RGB_Struct gFlag10Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag10.pmdpal") };

static const axmain sAxMainFlag10;
const SiroArchive gAxFlag10 = {"SIRO", &sAxMainFlag10};

static const ax_pose sFlag10Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag10Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag10Gfx1[] = INCBIN_U8("graphics/ornament/Flag10/sprite_1.4bpp");
static const ax_sprite sFlag10Sprites1[] = {
	{sFlag10Gfx1, ARRAY_COUNT(sFlag10Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx2[] = INCBIN_U8("graphics/ornament/Flag10/sprite_2.4bpp");
static const ax_sprite sFlag10Sprites2[] = {
	{sFlag10Gfx2, ARRAY_COUNT(sFlag10Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx3[] = INCBIN_U8("graphics/ornament/Flag10/sprite_3.4bpp");
static const ax_sprite sFlag10Sprites3[] = {
	{sFlag10Gfx3, ARRAY_COUNT(sFlag10Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx4[] = INCBIN_U8("graphics/ornament/Flag10/sprite_4.4bpp");
static const ax_sprite sFlag10Sprites4[] = {
	{sFlag10Gfx4, ARRAY_COUNT(sFlag10Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx5[] = INCBIN_U8("graphics/ornament/Flag10/sprite_5.4bpp");
static const ax_sprite sFlag10Sprites5[] = {
	{sFlag10Gfx5, ARRAY_COUNT(sFlag10Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx6[] = INCBIN_U8("graphics/ornament/Flag10/sprite_6.4bpp");
static const ax_sprite sFlag10Sprites6[] = {
	{sFlag10Gfx6, ARRAY_COUNT(sFlag10Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag10[] = {
	sFlag10Pose1,
	sFlag10Pose2,
	sFlag10Pose3,
	sFlag10Pose4,
	sFlag10Pose5,
	sFlag10Pose6,
};

static const ax_anim *const sFlag10AnimTable1[] = {
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag10[] = {
	sFlag10AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag10[] = {
	sFlag10Sprites1,
	sFlag10Sprites2,
	sFlag10Sprites3,
	sFlag10Sprites4,
	sFlag10Sprites5,
	sFlag10Sprites6,
};

static const axmain sAxMainFlag10 = {
	.poses = sAxPosesFlag10,
	.animations = sAxAnimationsFlag10,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag10),
	.spriteData = sAxSpritesFlag10,
	.positions = NULL,
};
