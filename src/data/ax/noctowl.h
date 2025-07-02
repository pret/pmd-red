static const axmain sAxMainNoctowl;
const SiroArchive gAxNoctowl = {"SIRO", &sAxMainNoctowl};

static const ax_pose sNoctowlPose1[] = {
	AX_POSE(0, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(248, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose2[] = {
	AX_POSE(4, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose3[] = {
	AX_POSE(5, OAM1(241, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(233, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose4[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose5[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose6[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose7[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose8[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose9[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose10[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose11[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose12[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose13[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose14[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose15[] = {
	AX_POSE(23, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose16[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose17[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose18[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose19[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose20[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose21[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose22[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose23[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose24[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose25[] = {
	AX_POSE(0, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(248, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose26[] = {
	AX_POSE(4, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose27[] = {
	AX_POSE(5, OAM1(241, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(233, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose28[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose29[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose30[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose31[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose32[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose33[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose34[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose35[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose36[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose37[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose38[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose39[] = {
	AX_POSE(23, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose40[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose41[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose42[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose43[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose44[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose45[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose46[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose47[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose48[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose49[] = {
	AX_POSE(0, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(248, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose50[] = {
	AX_POSE(4, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose51[] = {
	AX_POSE(5, OAM1(241, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(233, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose52[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose53[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose54[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose55[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose56[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose57[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose58[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose59[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose60[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose61[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose62[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose63[] = {
	AX_POSE(23, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose64[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose65[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose66[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose67[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose68[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose69[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose70[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose71[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose72[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose73[] = {
	AX_POSE(0, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(248, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose74[] = {
	AX_POSE(4, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose75[] = {
	AX_POSE(5, OAM1(241, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(233, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose76[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose77[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose78[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose79[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose80[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose81[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose82[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose83[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose84[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose85[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose86[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose87[] = {
	AX_POSE(23, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose88[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose89[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose90[] = {
	AX_POSE(16, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose91[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose92[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose93[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose94[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose95[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose96[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose97[] = {
	AX_POSE(24, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose98[] = {
	AX_POSE(0, OAM1(234, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose99[] = {
	AX_POSE(4, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose100[] = {
	AX_POSE(5, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(234, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose101[] = {
	AX_POSE(25, OAM1(247, ST_OAM_H_RECTANGLE, 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(26, OAM1(231, ST_OAM_H_RECTANGLE, 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 4)),
	AX_POSE(27, OAM1(255, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(28, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(15, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose102[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose103[] = {
	AX_POSE(8, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose104[] = {
	AX_POSE(9, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose105[] = {
	AX_POSE(10, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose106[] = {
	AX_POSE(30, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose107[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose108[] = {
	AX_POSE(11, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose109[] = {
	AX_POSE(12, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose110[] = {
	AX_POSE(13, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose111[] = {
	AX_POSE(32, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose112[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose113[] = {
	AX_POSE(14, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose114[] = {
	AX_POSE(15, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose115[] = {
	AX_POSE(16, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose116[] = {
	AX_POSE(34, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose117[] = {
	AX_POSE(35, OAM1(229, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose118[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose119[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose120[] = {
	AX_POSE(23, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose121[] = {
	AX_POSE(36, OAM1(229, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(37, OAM1(245, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(38, OAM1(253, ST_OAM_H_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(39, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose122[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose123[] = {
	AX_POSE(14, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose124[] = {
	AX_POSE(15, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose125[] = {
	AX_POSE(16, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose126[] = {
	AX_POSE(34, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose127[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose128[] = {
	AX_POSE(11, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose129[] = {
	AX_POSE(12, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose130[] = {
	AX_POSE(13, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose131[] = {
	AX_POSE(32, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose132[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose133[] = {
	AX_POSE(8, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose134[] = {
	AX_POSE(9, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose135[] = {
	AX_POSE(10, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose136[] = {
	AX_POSE(30, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose137[] = {
	AX_POSE(40, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose138[] = {
	AX_POSE(41, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose139[] = {
	AX_POSE(42, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose140[] = {
	AX_POSE(43, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose141[] = {
	AX_POSE(44, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose142[] = {
	AX_POSE(45, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose143[] = {
	AX_POSE(46, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose144[] = {
	AX_POSE(45, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose145[] = {
	AX_POSE(44, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose146[] = {
	AX_POSE(43, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose147[] = {
	AX_POSE(24, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose148[] = {
	AX_POSE(0, OAM1(230, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(246, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose149[] = {
	AX_POSE(4, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose150[] = {
	AX_POSE(5, OAM1(239, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(231, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(249, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose151[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose152[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose153[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose154[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose155[] = {
	AX_POSE(31, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose156[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose157[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose158[] = {
	AX_POSE(13, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose159[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose160[] = {
	AX_POSE(14, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose161[] = {
	AX_POSE(15, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose162[] = {
	AX_POSE(16, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose163[] = {
	AX_POSE(35, OAM1(229, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose164[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose165[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose166[] = {
	AX_POSE(23, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose167[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose168[] = {
	AX_POSE(14, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose169[] = {
	AX_POSE(15, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose170[] = {
	AX_POSE(16, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose171[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose172[] = {
	AX_POSE(11, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose173[] = {
	AX_POSE(12, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose174[] = {
	AX_POSE(13, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose175[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose176[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose177[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose178[] = {
	AX_POSE(10, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose179[] = {
	AX_POSE(4, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose180[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose181[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose182[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose183[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose184[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose185[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose186[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose187[] = {
	AX_POSE(25, OAM1(247, ST_OAM_H_RECTANGLE, 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(26, OAM1(231, ST_OAM_H_RECTANGLE, 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 4)),
	AX_POSE(27, OAM1(255, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(28, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(15, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose188[] = {
	AX_POSE(30, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose189[] = {
	AX_POSE(32, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose190[] = {
	AX_POSE(34, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose191[] = {
	AX_POSE(36, OAM1(229, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(37, OAM1(245, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(38, OAM1(253, ST_OAM_H_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(39, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose192[] = {
	AX_POSE(34, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose193[] = {
	AX_POSE(32, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose194[] = {
	AX_POSE(30, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose195[] = {
	AX_POSE(47, OAM1(232, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose196[] = {
	AX_POSE(0, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(1, OAM1(248, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose197[] = {
	AX_POSE(4, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose198[] = {
	AX_POSE(5, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(6, OAM1(235, ST_OAM_H_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(7, OAM1(253, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose199[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose200[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose201[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose202[] = {
	AX_POSE(10, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose203[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose204[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose205[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose206[] = {
	AX_POSE(13, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose207[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose208[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose209[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose210[] = {
	AX_POSE(16, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose211[] = {
	AX_POSE(35, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose212[] = {
	AX_POSE(17, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(18, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(19, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 4)),
	AX_POSE(20, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(16, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 4)),
	AX_POSE(21, OAM1(238, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose213[] = {
	AX_POSE(22, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose214[] = {
	AX_POSE(23, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose215[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose216[] = {
	AX_POSE(14, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose217[] = {
	AX_POSE(15, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose218[] = {
	AX_POSE(16, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose219[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose220[] = {
	AX_POSE(11, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose221[] = {
	AX_POSE(12, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose222[] = {
	AX_POSE(13, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose223[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose224[] = {
	AX_POSE(8, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose225[] = {
	AX_POSE(9, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose226[] = {
	AX_POSE(10, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose227[] = {
	AX_POSE(25, OAM1(247, ST_OAM_H_RECTANGLE, 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(26, OAM1(231, ST_OAM_H_RECTANGLE, 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 4)),
	AX_POSE(27, OAM1(255, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(28, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(15, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose228[] = {
	AX_POSE(30, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose229[] = {
	AX_POSE(32, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose230[] = {
	AX_POSE(34, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose231[] = {
	AX_POSE(36, OAM1(229, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE(37, OAM1(245, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 4)),
	AX_POSE(38, OAM1(253, ST_OAM_H_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 4)),
	AX_POSE(39, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose232[] = {
	AX_POSE(34, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose233[] = {
	AX_POSE(32, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose234[] = {
	AX_POSE(30, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose235[] = {
	AX_POSE(47, OAM1(232, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose236[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose237[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose238[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose239[] = {
	AX_POSE(35, OAM1(230, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose240[] = {
	AX_POSE(33, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose241[] = {
	AX_POSE(31, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sNoctowlPose242[] = {
	AX_POSE(29, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 6, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 7, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 6, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 8, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 9, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 10, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 9, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 11, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 12, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 13, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 12, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 14, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 15, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 16, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 15, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 17, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 18, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 19, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 18, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 20, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_1_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 21, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 22, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 21, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 23, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 25, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 26, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 24, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 25, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 25, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 25, .offset = {0, 22}, .shadow = {0, 22} },
	{ .frames = 2, .unkFlags = 1, .poseId = 25, .offset = {1, 22}, .shadow = {1, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 25, .offset = {0, 22}, .shadow = {0, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 25, .offset = {1, 22}, .shadow = {1, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 24, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 28, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 29, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 27, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 28, .offset = {4, 4}, .shadow = {4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 28, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 28, .offset = {22, 22}, .shadow = {22, 22} },
	{ .frames = 2, .unkFlags = 1, .poseId = 28, .offset = {23, 21}, .shadow = {23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 28, .offset = {22, 22}, .shadow = {22, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 28, .offset = {23, 21}, .shadow = {23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 27, .offset = {6, 6}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 31, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 32, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 30, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 31, .offset = {4, 0}, .shadow = {4, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 31, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 31, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 31, .offset = {18, 1}, .shadow = {18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 31, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 31, .offset = {18, 1}, .shadow = {18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 30, .offset = {6, 0}, .shadow = {6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 34, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 35, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 33, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 34, .offset = {5, -6}, .shadow = {5, -6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 34, .offset = {10, -13}, .shadow = {10, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 34, .offset = {22, -17}, .shadow = {22, -17} },
	{ .frames = 2, .unkFlags = 1, .poseId = 34, .offset = {23, -16}, .shadow = {23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 34, .offset = {22, -17}, .shadow = {22, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 34, .offset = {23, -16}, .shadow = {23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 33, .offset = {5, -6}, .shadow = {5, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 38, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 36, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 37, .offset = {0, -4}, .shadow = {0, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 37, .offset = {0, -11}, .shadow = {0, -11} },
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {0, -17}, .shadow = {0, -17} },
	{ .frames = 2, .unkFlags = 1, .poseId = 37, .offset = {1, -17}, .shadow = {1, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {0, -17}, .shadow = {0, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {1, -17}, .shadow = {1, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 36, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 40, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 41, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 39, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 40, .offset = {-5, -6}, .shadow = {-5, -6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 40, .offset = {-10, -13}, .shadow = {-10, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 40, .offset = {-22, -17}, .shadow = {-22, -17} },
	{ .frames = 2, .unkFlags = 1, .poseId = 40, .offset = {-23, -16}, .shadow = {-23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 40, .offset = {-22, -17}, .shadow = {-22, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 40, .offset = {-23, -16}, .shadow = {-23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 39, .offset = {-5, -6}, .shadow = {-5, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 43, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 44, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 42, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 43, .offset = {-4, 0}, .shadow = {-4, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 43, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 43, .offset = {-18, 0}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 43, .offset = {-18, 1}, .shadow = {-18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 43, .offset = {-18, 0}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 43, .offset = {-18, 1}, .shadow = {-18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 42, .offset = {-6, 0}, .shadow = {-6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_2_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 47, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 45, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 46, .offset = {-4, 4}, .shadow = {-4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 46, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {-22, 22}, .shadow = {-22, 22} },
	{ .frames = 2, .unkFlags = 1, .poseId = 46, .offset = {-23, 21}, .shadow = {-23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {-22, 22}, .shadow = {-22, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {-23, 21}, .shadow = {-23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 45, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 49, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 50, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 48, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 49, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 49, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 49, .offset = {0, 22}, .shadow = {0, 22} },
	{ .frames = 2, .unkFlags = 1, .poseId = 49, .offset = {1, 22}, .shadow = {1, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 49, .offset = {0, 22}, .shadow = {0, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 49, .offset = {1, 22}, .shadow = {1, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 48, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 53, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 51, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 52, .offset = {4, 4}, .shadow = {4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 52, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {22, 22}, .shadow = {22, 22} },
	{ .frames = 2, .unkFlags = 1, .poseId = 52, .offset = {23, 21}, .shadow = {23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {22, 22}, .shadow = {22, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {23, 21}, .shadow = {23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 51, .offset = {6, 6}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 55, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 56, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 54, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 55, .offset = {4, 0}, .shadow = {4, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 55, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 55, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 55, .offset = {18, 1}, .shadow = {18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 55, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 55, .offset = {18, 1}, .shadow = {18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 54, .offset = {6, 0}, .shadow = {6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 58, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 59, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 57, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 58, .offset = {5, -6}, .shadow = {5, -6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 58, .offset = {10, -13}, .shadow = {10, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 58, .offset = {22, -17}, .shadow = {22, -17} },
	{ .frames = 2, .unkFlags = 1, .poseId = 58, .offset = {23, -16}, .shadow = {23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 58, .offset = {22, -17}, .shadow = {22, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 58, .offset = {23, -16}, .shadow = {23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 57, .offset = {5, -6}, .shadow = {5, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 62, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 60, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 61, .offset = {0, -4}, .shadow = {0, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 61, .offset = {0, -11}, .shadow = {0, -11} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {0, -17}, .shadow = {0, -17} },
	{ .frames = 2, .unkFlags = 1, .poseId = 61, .offset = {1, -17}, .shadow = {1, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {0, -17}, .shadow = {0, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {1, -17}, .shadow = {1, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 60, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 64, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 65, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 63, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 64, .offset = {-5, -6}, .shadow = {-5, -6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 64, .offset = {-10, -13}, .shadow = {-10, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 64, .offset = {-22, -17}, .shadow = {-22, -17} },
	{ .frames = 2, .unkFlags = 1, .poseId = 64, .offset = {-23, -16}, .shadow = {-23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 64, .offset = {-22, -17}, .shadow = {-22, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 64, .offset = {-23, -16}, .shadow = {-23, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 63, .offset = {-5, -6}, .shadow = {-5, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 68, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 66, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 67, .offset = {-4, 0}, .shadow = {-4, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 67, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {-18, 0}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 67, .offset = {-18, 1}, .shadow = {-18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {-18, 0}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {-18, 1}, .shadow = {-18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 66, .offset = {-6, 0}, .shadow = {-6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_3_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 70, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 71, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 69, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 70, .offset = {-4, 4}, .shadow = {-4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 70, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 70, .offset = {-22, 22}, .shadow = {-22, 22} },
	{ .frames = 2, .unkFlags = 1, .poseId = 70, .offset = {-23, 21}, .shadow = {-23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 70, .offset = {-22, 22}, .shadow = {-22, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 70, .offset = {-23, 21}, .shadow = {-23, 21} },
	{ .frames = 2, .unkFlags = 0, .poseId = 69, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_1[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 73, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 73, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 73, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 73, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_2[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_3[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 79, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 79, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 79, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 79, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_4[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 83, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 83, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 83, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 83, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_5[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 85, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 85, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 85, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 85, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_6[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_7[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_4_8[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_1[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 96, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 100, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 100, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 100, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 100, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 100, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 100, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_2[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 101, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 105, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 105, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 105, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 105, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 105, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 105, .offset = {-1, 1}, .shadow = {-1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_3[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 106, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 110, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 110, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 110, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 110, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 110, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 110, .offset = {0, -1}, .shadow = {0, -1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_4[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 111, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 115, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 115, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 115, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 115, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 115, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 115, .offset = {-1, -1}, .shadow = {-1, -1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_5[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 116, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 120, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 120, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 120, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 120, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 120, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 120, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_6[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 121, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 125, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 125, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 125, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 125, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 125, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 125, .offset = {1, -1}, .shadow = {1, -1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_7[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 126, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 130, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 130, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 130, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 130, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 130, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 130, .offset = {0, -1}, .shadow = {0, -1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_5_8[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 131, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 2, .poseId = 135, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 135, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 135, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 135, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 135, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 135, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_6_1[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 136, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 137, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 138, .offset = {0, -3}, .shadow = {0, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 139, .offset = {-3, -3}, .shadow = {-3, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 140, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 140, .offset = {-3, 0}, .shadow = {-3, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 141, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 141, .offset = {-3, 3}, .shadow = {-3, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 142, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 142, .offset = {0, 3}, .shadow = {0, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 143, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 143, .offset = {3, 3}, .shadow = {3, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 144, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 144, .offset = {3, 0}, .shadow = {3, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_7_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 145, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 145, .offset = {3, -3}, .shadow = {3, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_1[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 146, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 148, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 149, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 148, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_2[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 150, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 152, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 153, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 152, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_3[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 154, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 157, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 155, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 156, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 157, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 157, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 155, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 156, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 155, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 157, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 157, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 157, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 155, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 155, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 155, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 155, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_4[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 158, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 161, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 159, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 160, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 161, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 161, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 159, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 160, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 159, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 161, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 161, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 161, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 159, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 159, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 159, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 159, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_5[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 162, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 165, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 163, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 164, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 165, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 165, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 163, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 164, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 163, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 165, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 165, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 165, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 163, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 163, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 163, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 163, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_6[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 166, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 169, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 167, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 168, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 169, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 169, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 167, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 168, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 167, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 169, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 169, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 169, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 167, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 167, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 167, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 167, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_7[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 170, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 173, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 171, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 172, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 173, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 173, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 171, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 172, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 171, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 173, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 173, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 173, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 171, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 171, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 171, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 171, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_8_8[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 174, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 177, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 175, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 176, .offset = {0, 3}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 177, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 177, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 175, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 176, .offset = {0, -7}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 175, .offset = {0, -5}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 177, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 177, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 177, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 175, .offset = {0, -9}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 175, .offset = {0, -8}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 175, .offset = {0, -6}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 175, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 178, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 179, .offset = {6, 3}, .shadow = {6, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 180, .offset = {8, 9}, .shadow = {8, 9} },
	{ .frames = 2, .unkFlags = 0, .poseId = 181, .offset = {7, 17}, .shadow = {7, 17} },
	{ .frames = 3, .unkFlags = 0, .poseId = 182, .offset = {0, 21}, .shadow = {0, 21} },
	{ .frames = 2, .unkFlags = 3, .poseId = 183, .offset = {-7, 17}, .shadow = {-7, 17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 184, .offset = {-8, 9}, .shadow = {-8, 9} },
	{ .frames = 1, .unkFlags = 0, .poseId = 185, .offset = {-6, 3}, .shadow = {-6, 3} },
	{ .frames = 1, .unkFlags = 0, .poseId = 178, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 178, .offset = {8, 0}, .shadow = {8, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {18, 5}, .shadow = {18, 5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 180, .offset = {20, 13}, .shadow = {20, 13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 181, .offset = {21, 22}, .shadow = {21, 22} },
	{ .frames = 2, .unkFlags = 3, .poseId = 182, .offset = {13, 22}, .shadow = {13, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 183, .offset = {3, 15}, .shadow = {3, 15} },
	{ .frames = 1, .unkFlags = 0, .poseId = 184, .offset = {0, 7}, .shadow = {0, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 184, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 185, .offset = {3, -5}, .shadow = {3, -5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 178, .offset = {11, -6}, .shadow = {11, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {16, -5}, .shadow = {16, -5} },
	{ .frames = 3, .unkFlags = 0, .poseId = 180, .offset = {20, 0}, .shadow = {20, 0} },
	{ .frames = 2, .unkFlags = 3, .poseId = 181, .offset = {18, 4}, .shadow = {18, 4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {12, 5}, .shadow = {12, 5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 183, .offset = {4, 3}, .shadow = {4, 3} },
	{ .frames = 1, .unkFlags = 0, .poseId = 184, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 183, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 184, .offset = {-1, -8}, .shadow = {-1, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {4, -16}, .shadow = {4, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 178, .offset = {12, -22}, .shadow = {12, -22} },
	{ .frames = 3, .unkFlags = 0, .poseId = 179, .offset = {22, -18}, .shadow = {22, -18} },
	{ .frames = 2, .unkFlags = 3, .poseId = 180, .offset = {20, -12}, .shadow = {20, -12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 181, .offset = {17, -4}, .shadow = {17, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 182, .offset = {7, -1}, .shadow = {7, -1} },
	{ .frames = 1, .unkFlags = 0, .poseId = 183, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 183, .offset = {-8, -4}, .shadow = {-8, -4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 184, .offset = {-9, -12}, .shadow = {-9, -12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {-7, -17}, .shadow = {-7, -17} },
	{ .frames = 3, .unkFlags = 0, .poseId = 178, .offset = {0, -19}, .shadow = {0, -19} },
	{ .frames = 2, .unkFlags = 3, .poseId = 179, .offset = {7, -17}, .shadow = {7, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 180, .offset = {9, -12}, .shadow = {9, -12} },
	{ .frames = 1, .unkFlags = 0, .poseId = 181, .offset = {8, -4}, .shadow = {8, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 181, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 180, .offset = {1, -8}, .shadow = {1, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {-4, -16}, .shadow = {-4, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 178, .offset = {-12, -22}, .shadow = {-12, -22} },
	{ .frames = 3, .unkFlags = 0, .poseId = 185, .offset = {-22, -18}, .shadow = {-22, -18} },
	{ .frames = 2, .unkFlags = 3, .poseId = 184, .offset = {-20, -12}, .shadow = {-20, -12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 183, .offset = {-17, -4}, .shadow = {-17, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 182, .offset = {-7, -1}, .shadow = {-7, -1} },
	{ .frames = 1, .unkFlags = 0, .poseId = 181, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 180, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 179, .offset = {-3, -5}, .shadow = {-3, -5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 178, .offset = {-11, -6}, .shadow = {-11, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {-16, -5}, .shadow = {-16, -5} },
	{ .frames = 3, .unkFlags = 0, .poseId = 184, .offset = {-20, 0}, .shadow = {-20, 0} },
	{ .frames = 2, .unkFlags = 3, .poseId = 183, .offset = {-18, 4}, .shadow = {-18, 4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {-12, 5}, .shadow = {-12, 5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 181, .offset = {-4, 3}, .shadow = {-4, 3} },
	{ .frames = 1, .unkFlags = 0, .poseId = 180, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_9_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 178, .offset = {-8, 0}, .shadow = {-8, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {-18, 5}, .shadow = {-18, 5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 184, .offset = {-20, 13}, .shadow = {-20, 13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 183, .offset = {-21, 22}, .shadow = {-21, 22} },
	{ .frames = 2, .unkFlags = 3, .poseId = 182, .offset = {-13, 22}, .shadow = {-13, 22} },
	{ .frames = 2, .unkFlags = 0, .poseId = 181, .offset = {-3, 15}, .shadow = {-3, 15} },
	{ .frames = 1, .unkFlags = 0, .poseId = 180, .offset = {0, 7}, .shadow = {0, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 186, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 186, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 186, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 186, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 186, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 187, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 187, .offset = {13, -13}, .shadow = {13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 187, .offset = {-13, 13}, .shadow = {-13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 187, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 187, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 188, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 188, .offset = {0, -13}, .shadow = {0, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 188, .offset = {0, 13}, .shadow = {0, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 188, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 189, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 189, .offset = {-13, -13}, .shadow = {-13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 189, .offset = {13, 13}, .shadow = {13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 189, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 189, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 190, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 190, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 190, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 190, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 190, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 191, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 191, .offset = {13, -13}, .shadow = {13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 191, .offset = {-13, 13}, .shadow = {-13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 191, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 192, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 192, .offset = {0, -13}, .shadow = {0, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 192, .offset = {0, 13}, .shadow = {0, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 192, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_10_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 193, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 193, .offset = {-13, -13}, .shadow = {-13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 193, .offset = {13, 13}, .shadow = {13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 193, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 193, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 197, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 197, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 197, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 195, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 196, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 196, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 196, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 196, .offset = {0, 2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 198, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 201, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 201, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 201, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 201, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 199, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 200, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 200, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 200, .offset = {0, 3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 205, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 205, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 205, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 203, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 204, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 204, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 204, .offset = {0, 2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 209, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 209, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 209, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 207, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 208, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, -17}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 208, .offset = {0, -11}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 208, .offset = {0, 2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 213, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 213, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 213, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 213, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 211, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 212, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 212, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 212, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 212, .offset = {0, 2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 217, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 217, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 217, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 217, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 216, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 216, .offset = {0, -17}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 216, .offset = {0, -11}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 216, .offset = {0, 2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 221, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 221, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 221, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 221, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 219, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 220, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 220, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 220, .offset = {0, 2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_11_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 225, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 223, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 224, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 224, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 224, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 224, .offset = {0, 3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 226, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 226, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 226, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 227, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 227, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 228, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 229, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 230, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 231, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 232, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_12_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sNoctowlAnims_13_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};

static const u8 sNoctowlGfx1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_1.4bpp");
static const ax_sprite sNoctowlSprites1[] = {
	{sNoctowlGfx1, ARRAY_COUNT(sNoctowlGfx1)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx2[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_2.4bpp");
static const ax_sprite sNoctowlSprites2[] = {
	{sNoctowlGfx2, ARRAY_COUNT(sNoctowlGfx2)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx3[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_3.4bpp");
static const ax_sprite sNoctowlSprites3[] = {
	{sNoctowlGfx3, ARRAY_COUNT(sNoctowlGfx3)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx4[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_4.4bpp");
static const ax_sprite sNoctowlSprites4[] = {
	{sNoctowlGfx4, ARRAY_COUNT(sNoctowlGfx4)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx5[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_5.4bpp");
static const ax_sprite sNoctowlSprites5[] = {
	{sNoctowlGfx5, ARRAY_COUNT(sNoctowlGfx5)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx6[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_6.4bpp");
static const ax_sprite sNoctowlSprites6[] = {
	{sNoctowlGfx6, ARRAY_COUNT(sNoctowlGfx6)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx7[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_7.4bpp");
static const ax_sprite sNoctowlSprites7[] = {
	{sNoctowlGfx7, ARRAY_COUNT(sNoctowlGfx7)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx8[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_8.4bpp");
static const ax_sprite sNoctowlSprites8[] = {
	{sNoctowlGfx8, ARRAY_COUNT(sNoctowlGfx8)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx9[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_9.4bpp");
static const ax_sprite sNoctowlSprites9[] = {
	{sNoctowlGfx9, ARRAY_COUNT(sNoctowlGfx9)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx10[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_10.4bpp");
static const ax_sprite sNoctowlSprites10[] = {
	{sNoctowlGfx10, ARRAY_COUNT(sNoctowlGfx10)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx11[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_11.4bpp");
static const ax_sprite sNoctowlSprites11[] = {
	{sNoctowlGfx11, ARRAY_COUNT(sNoctowlGfx11)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx12[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_12.4bpp");
static const ax_sprite sNoctowlSprites12[] = {
	{sNoctowlGfx12, ARRAY_COUNT(sNoctowlGfx12)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx13[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_13.4bpp");
static const ax_sprite sNoctowlSprites13[] = {
	{sNoctowlGfx13, ARRAY_COUNT(sNoctowlGfx13)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx14[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_14.4bpp");
static const ax_sprite sNoctowlSprites14[] = {
	{sNoctowlGfx14, ARRAY_COUNT(sNoctowlGfx14)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx15[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_15.4bpp");
static const ax_sprite sNoctowlSprites15[] = {
	{sNoctowlGfx15, ARRAY_COUNT(sNoctowlGfx15)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx16[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_16.4bpp");
static const ax_sprite sNoctowlSprites16[] = {
	{sNoctowlGfx16, ARRAY_COUNT(sNoctowlGfx16)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx17[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_17.4bpp");
static const ax_sprite sNoctowlSprites17[] = {
	{sNoctowlGfx17, ARRAY_COUNT(sNoctowlGfx17)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx18[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_18.4bpp");
static const ax_sprite sNoctowlSprites18[] = {
	{sNoctowlGfx18, ARRAY_COUNT(sNoctowlGfx18)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx19[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_19.4bpp");
static const ax_sprite sNoctowlSprites19[] = {
	{sNoctowlGfx19, ARRAY_COUNT(sNoctowlGfx19)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx20[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_20.4bpp");
static const ax_sprite sNoctowlSprites20[] = {
	{sNoctowlGfx20, ARRAY_COUNT(sNoctowlGfx20)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx21[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_21.4bpp");
static const ax_sprite sNoctowlSprites21[] = {
	{sNoctowlGfx21, ARRAY_COUNT(sNoctowlGfx21)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx22[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_22.4bpp");
static const ax_sprite sNoctowlSprites22[] = {
	{sNoctowlGfx22, ARRAY_COUNT(sNoctowlGfx22)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx23[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_23.4bpp");
static const ax_sprite sNoctowlSprites23[] = {
	{sNoctowlGfx23, ARRAY_COUNT(sNoctowlGfx23)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx24[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_24.4bpp");
static const ax_sprite sNoctowlSprites24[] = {
	{sNoctowlGfx24, ARRAY_COUNT(sNoctowlGfx24)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx25[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_25.4bpp");
static const u8 sNoctowlGfx25_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_25_1.4bpp");
static const u8 sNoctowlGfx25_2[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_25_2.4bpp");
static const u8 sNoctowlGfx25_3[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_25_3.4bpp");
static const ax_sprite sNoctowlSprites25[] = {
	{sNoctowlGfx25, ARRAY_COUNT(sNoctowlGfx25)}, 
	{NULL, 64}, 
	{sNoctowlGfx25_1, ARRAY_COUNT(sNoctowlGfx25_1)}, 
	{NULL, 64}, 
	{sNoctowlGfx25_2, ARRAY_COUNT(sNoctowlGfx25_2)}, 
	{NULL, 64}, 
	{sNoctowlGfx25_3, ARRAY_COUNT(sNoctowlGfx25_3)}, 
	{NULL, 64}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx26[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_26.4bpp");
static const ax_sprite sNoctowlSprites26[] = {
	{sNoctowlGfx26, ARRAY_COUNT(sNoctowlGfx26)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx27[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_27.4bpp");
static const ax_sprite sNoctowlSprites27[] = {
	{sNoctowlGfx27, ARRAY_COUNT(sNoctowlGfx27)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx28[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_28.4bpp");
static const ax_sprite sNoctowlSprites28[] = {
	{sNoctowlGfx28, ARRAY_COUNT(sNoctowlGfx28)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx29[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_29.4bpp");
static const ax_sprite sNoctowlSprites29[] = {
	{sNoctowlGfx29, ARRAY_COUNT(sNoctowlGfx29)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx30[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_30.4bpp");
static const u8 sNoctowlGfx30_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_30_1.4bpp");
static const u8 sNoctowlGfx30_2[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_30_2.4bpp");
static const u8 sNoctowlGfx30_3[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_30_3.4bpp");
static const ax_sprite sNoctowlSprites30[] = {
	{sNoctowlGfx30, ARRAY_COUNT(sNoctowlGfx30)}, 
	{NULL, 32}, 
	{sNoctowlGfx30_1, ARRAY_COUNT(sNoctowlGfx30_1)}, 
	{NULL, 64}, 
	{sNoctowlGfx30_2, ARRAY_COUNT(sNoctowlGfx30_2)}, 
	{NULL, 64}, 
	{sNoctowlGfx30_3, ARRAY_COUNT(sNoctowlGfx30_3)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx31[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_31.4bpp");
static const u8 sNoctowlGfx31_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_31_1.4bpp");
static const ax_sprite sNoctowlSprites31[] = {
	{sNoctowlGfx31, ARRAY_COUNT(sNoctowlGfx31)}, 
	{NULL, 32}, 
	{sNoctowlGfx31_1, ARRAY_COUNT(sNoctowlGfx31_1)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx32[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_32.4bpp");
static const u8 sNoctowlGfx32_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_32_1.4bpp");
static const u8 sNoctowlGfx32_2[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_32_2.4bpp");
static const u8 sNoctowlGfx32_3[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_32_3.4bpp");
static const ax_sprite sNoctowlSprites32[] = {
	{sNoctowlGfx32, ARRAY_COUNT(sNoctowlGfx32)}, 
	{NULL, 32}, 
	{sNoctowlGfx32_1, ARRAY_COUNT(sNoctowlGfx32_1)}, 
	{NULL, 64}, 
	{sNoctowlGfx32_2, ARRAY_COUNT(sNoctowlGfx32_2)}, 
	{NULL, 32}, 
	{sNoctowlGfx32_3, ARRAY_COUNT(sNoctowlGfx32_3)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx33[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_33.4bpp");
static const u8 sNoctowlGfx33_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_33_1.4bpp");
static const ax_sprite sNoctowlSprites33[] = {
	{sNoctowlGfx33, ARRAY_COUNT(sNoctowlGfx33)}, 
	{NULL, 32}, 
	{sNoctowlGfx33_1, ARRAY_COUNT(sNoctowlGfx33_1)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx34[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_34.4bpp");
static const u8 sNoctowlGfx34_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_34_1.4bpp");
static const u8 sNoctowlGfx34_2[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_34_2.4bpp");
static const u8 sNoctowlGfx34_3[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_34_3.4bpp");
static const ax_sprite sNoctowlSprites34[] = {
	{NULL, 32}, 
	{sNoctowlGfx34, ARRAY_COUNT(sNoctowlGfx34)}, 
	{NULL, 32}, 
	{sNoctowlGfx34_1, ARRAY_COUNT(sNoctowlGfx34_1)}, 
	{NULL, 64}, 
	{sNoctowlGfx34_2, ARRAY_COUNT(sNoctowlGfx34_2)}, 
	{NULL, 64}, 
	{sNoctowlGfx34_3, ARRAY_COUNT(sNoctowlGfx34_3)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx35[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_35.4bpp");
static const u8 sNoctowlGfx35_1[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_35_1.4bpp");
static const ax_sprite sNoctowlSprites35[] = {
	{sNoctowlGfx35, ARRAY_COUNT(sNoctowlGfx35)}, 
	{NULL, 64}, 
	{sNoctowlGfx35_1, ARRAY_COUNT(sNoctowlGfx35_1)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx36[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_36.4bpp");
static const ax_sprite sNoctowlSprites36[] = {
	{sNoctowlGfx36, ARRAY_COUNT(sNoctowlGfx36)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx37[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_37.4bpp");
static const ax_sprite sNoctowlSprites37[] = {
	{sNoctowlGfx37, ARRAY_COUNT(sNoctowlGfx37)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx38[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_38.4bpp");
static const ax_sprite sNoctowlSprites38[] = {
	{sNoctowlGfx38, ARRAY_COUNT(sNoctowlGfx38)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx39[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_39.4bpp");
static const ax_sprite sNoctowlSprites39[] = {
	{sNoctowlGfx39, ARRAY_COUNT(sNoctowlGfx39)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx40[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_40.4bpp");
static const ax_sprite sNoctowlSprites40[] = {
	{sNoctowlGfx40, ARRAY_COUNT(sNoctowlGfx40)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx41[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_41.4bpp");
static const ax_sprite sNoctowlSprites41[] = {
	{sNoctowlGfx41, ARRAY_COUNT(sNoctowlGfx41)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx42[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_42.4bpp");
static const ax_sprite sNoctowlSprites42[] = {
	{sNoctowlGfx42, ARRAY_COUNT(sNoctowlGfx42)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx43[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_43.4bpp");
static const ax_sprite sNoctowlSprites43[] = {
	{sNoctowlGfx43, ARRAY_COUNT(sNoctowlGfx43)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx44[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_44.4bpp");
static const ax_sprite sNoctowlSprites44[] = {
	{sNoctowlGfx44, ARRAY_COUNT(sNoctowlGfx44)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx45[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_45.4bpp");
static const ax_sprite sNoctowlSprites45[] = {
	{sNoctowlGfx45, ARRAY_COUNT(sNoctowlGfx45)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx46[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_46.4bpp");
static const ax_sprite sNoctowlSprites46[] = {
	{sNoctowlGfx46, ARRAY_COUNT(sNoctowlGfx46)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx47[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_47.4bpp");
static const ax_sprite sNoctowlSprites47[] = {
	{sNoctowlGfx47, ARRAY_COUNT(sNoctowlGfx47)}, 
	{NULL, 0}
};
static const u8 sNoctowlGfx48[] = INCBIN_U8("graphics/ax/mon/noctowl/sprite_48.4bpp");
static const ax_sprite sNoctowlSprites48[] = {
	{sNoctowlGfx48, ARRAY_COUNT(sNoctowlGfx48)}, 
	{NULL, 0}
};

static const ax_pose *const sAxPosesNoctowl[] = {
	sNoctowlPose1,
	sNoctowlPose2,
	sNoctowlPose3,
	sNoctowlPose4,
	sNoctowlPose5,
	sNoctowlPose6,
	sNoctowlPose7,
	sNoctowlPose8,
	sNoctowlPose9,
	sNoctowlPose10,
	sNoctowlPose11,
	sNoctowlPose12,
	sNoctowlPose13,
	sNoctowlPose14,
	sNoctowlPose15,
	sNoctowlPose16,
	sNoctowlPose17,
	sNoctowlPose18,
	sNoctowlPose19,
	sNoctowlPose20,
	sNoctowlPose21,
	sNoctowlPose22,
	sNoctowlPose23,
	sNoctowlPose24,
	sNoctowlPose25,
	sNoctowlPose26,
	sNoctowlPose27,
	sNoctowlPose28,
	sNoctowlPose29,
	sNoctowlPose30,
	sNoctowlPose31,
	sNoctowlPose32,
	sNoctowlPose33,
	sNoctowlPose34,
	sNoctowlPose35,
	sNoctowlPose36,
	sNoctowlPose37,
	sNoctowlPose38,
	sNoctowlPose39,
	sNoctowlPose40,
	sNoctowlPose41,
	sNoctowlPose42,
	sNoctowlPose43,
	sNoctowlPose44,
	sNoctowlPose45,
	sNoctowlPose46,
	sNoctowlPose47,
	sNoctowlPose48,
	sNoctowlPose49,
	sNoctowlPose50,
	sNoctowlPose51,
	sNoctowlPose52,
	sNoctowlPose53,
	sNoctowlPose54,
	sNoctowlPose55,
	sNoctowlPose56,
	sNoctowlPose57,
	sNoctowlPose58,
	sNoctowlPose59,
	sNoctowlPose60,
	sNoctowlPose61,
	sNoctowlPose62,
	sNoctowlPose63,
	sNoctowlPose64,
	sNoctowlPose65,
	sNoctowlPose66,
	sNoctowlPose67,
	sNoctowlPose68,
	sNoctowlPose69,
	sNoctowlPose70,
	sNoctowlPose71,
	sNoctowlPose72,
	sNoctowlPose73,
	sNoctowlPose74,
	sNoctowlPose75,
	sNoctowlPose76,
	sNoctowlPose77,
	sNoctowlPose78,
	sNoctowlPose79,
	sNoctowlPose80,
	sNoctowlPose81,
	sNoctowlPose82,
	sNoctowlPose83,
	sNoctowlPose84,
	sNoctowlPose85,
	sNoctowlPose86,
	sNoctowlPose87,
	sNoctowlPose88,
	sNoctowlPose89,
	sNoctowlPose90,
	sNoctowlPose91,
	sNoctowlPose92,
	sNoctowlPose93,
	sNoctowlPose94,
	sNoctowlPose95,
	sNoctowlPose96,
	sNoctowlPose97,
	sNoctowlPose98,
	sNoctowlPose99,
	sNoctowlPose100,
	sNoctowlPose101,
	sNoctowlPose102,
	sNoctowlPose103,
	sNoctowlPose104,
	sNoctowlPose105,
	sNoctowlPose106,
	sNoctowlPose107,
	sNoctowlPose108,
	sNoctowlPose109,
	sNoctowlPose110,
	sNoctowlPose111,
	sNoctowlPose112,
	sNoctowlPose113,
	sNoctowlPose114,
	sNoctowlPose115,
	sNoctowlPose116,
	sNoctowlPose117,
	sNoctowlPose118,
	sNoctowlPose119,
	sNoctowlPose120,
	sNoctowlPose121,
	sNoctowlPose122,
	sNoctowlPose123,
	sNoctowlPose124,
	sNoctowlPose125,
	sNoctowlPose126,
	sNoctowlPose127,
	sNoctowlPose128,
	sNoctowlPose129,
	sNoctowlPose130,
	sNoctowlPose131,
	sNoctowlPose132,
	sNoctowlPose133,
	sNoctowlPose134,
	sNoctowlPose135,
	sNoctowlPose136,
	sNoctowlPose137,
	sNoctowlPose138,
	sNoctowlPose139,
	sNoctowlPose140,
	sNoctowlPose141,
	sNoctowlPose142,
	sNoctowlPose143,
	sNoctowlPose144,
	sNoctowlPose145,
	sNoctowlPose146,
	sNoctowlPose147,
	sNoctowlPose148,
	sNoctowlPose149,
	sNoctowlPose150,
	sNoctowlPose151,
	sNoctowlPose152,
	sNoctowlPose153,
	sNoctowlPose154,
	sNoctowlPose155,
	sNoctowlPose156,
	sNoctowlPose157,
	sNoctowlPose158,
	sNoctowlPose159,
	sNoctowlPose160,
	sNoctowlPose161,
	sNoctowlPose162,
	sNoctowlPose163,
	sNoctowlPose164,
	sNoctowlPose165,
	sNoctowlPose166,
	sNoctowlPose167,
	sNoctowlPose168,
	sNoctowlPose169,
	sNoctowlPose170,
	sNoctowlPose171,
	sNoctowlPose172,
	sNoctowlPose173,
	sNoctowlPose174,
	sNoctowlPose175,
	sNoctowlPose176,
	sNoctowlPose177,
	sNoctowlPose178,
	sNoctowlPose179,
	sNoctowlPose180,
	sNoctowlPose181,
	sNoctowlPose182,
	sNoctowlPose183,
	sNoctowlPose184,
	sNoctowlPose185,
	sNoctowlPose186,
	sNoctowlPose187,
	sNoctowlPose188,
	sNoctowlPose189,
	sNoctowlPose190,
	sNoctowlPose191,
	sNoctowlPose192,
	sNoctowlPose193,
	sNoctowlPose194,
	sNoctowlPose195,
	sNoctowlPose196,
	sNoctowlPose197,
	sNoctowlPose198,
	sNoctowlPose199,
	sNoctowlPose200,
	sNoctowlPose201,
	sNoctowlPose202,
	sNoctowlPose203,
	sNoctowlPose204,
	sNoctowlPose205,
	sNoctowlPose206,
	sNoctowlPose207,
	sNoctowlPose208,
	sNoctowlPose209,
	sNoctowlPose210,
	sNoctowlPose211,
	sNoctowlPose212,
	sNoctowlPose213,
	sNoctowlPose214,
	sNoctowlPose215,
	sNoctowlPose216,
	sNoctowlPose217,
	sNoctowlPose218,
	sNoctowlPose219,
	sNoctowlPose220,
	sNoctowlPose221,
	sNoctowlPose222,
	sNoctowlPose223,
	sNoctowlPose224,
	sNoctowlPose225,
	sNoctowlPose226,
	sNoctowlPose227,
	sNoctowlPose228,
	sNoctowlPose229,
	sNoctowlPose230,
	sNoctowlPose231,
	sNoctowlPose232,
	sNoctowlPose233,
	sNoctowlPose234,
	sNoctowlPose235,
	sNoctowlPose236,
	sNoctowlPose237,
	sNoctowlPose238,
	sNoctowlPose239,
	sNoctowlPose240,
	sNoctowlPose241,
	sNoctowlPose242,
};

static const struct PositionSets sAxPositionsNoctowl[] = {
	[0] = { .set = { {-1, -9}, {-17, -15}, {15, -15}, {-1, -8} } },
	[1] = { .set = { {-1, -8}, {-12, -20}, {10, -20}, {-1, -9} } },
	[2] = { .set = { {-1, -10}, {-15, -3}, {13, -3}, {-1, -8} } },
	[3] = { .set = { {5, -9}, {12, -18}, {-14, -15}, {-1, -7} } },
	[4] = { .set = { {5, -8}, {7, -23}, {-11, -20}, {-1, -8} } },
	[5] = { .set = { {5, -10}, {9, -3}, {-11, 0}, {0, -9} } },
	[6] = { .set = { {12, -9}, {0, -20}, {-5, -14}, {1, -8} } },
	[7] = { .set = { {12, -8}, {0, -23}, {-4, -18}, {1, -7} } },
	[8] = { .set = { {12, -10}, {-2, -2}, {-4, 2}, {0, -8} } },
	[9] = { .set = { {3, -15}, {-14, -19}, {11, -9}, {-3, -9} } },
	[10] = { .set = { {3, -13}, {-10, -24}, {7, -18}, {-3, -10} } },
	[11] = { .set = { {2, -15}, {-14, -7}, {7, 1}, {-3, -9} } },
	[12] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[13] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[14] = { .set = { {-1, -15}, {12, -1}, {-14, -1}, {-1, -8} } },
	[15] = { .set = { {-5, -15}, {12, -19}, {-13, -9}, {1, -9} } },
	[16] = { .set = { {-5, -13}, {8, -24}, {-9, -18}, {1, -10} } },
	[17] = { .set = { {-4, -15}, {12, -7}, {-9, 1}, {1, -9} } },
	[18] = { .set = { {-14, -9}, {-2, -20}, {3, -14}, {-3, -8} } },
	[19] = { .set = { {-14, -8}, {-2, -23}, {2, -18}, {-3, -7} } },
	[20] = { .set = { {-14, -10}, {0, -2}, {2, 2}, {-2, -8} } },
	[21] = { .set = { {-7, -9}, {-14, -18}, {12, -15}, {-1, -7} } },
	[22] = { .set = { {-7, -8}, {-9, -23}, {9, -20}, {-1, -8} } },
	[23] = { .set = { {-7, -10}, {-11, -3}, {9, 0}, {-2, -9} } },
	[24] = { .set = { {-1, -9}, {-17, -15}, {15, -15}, {-1, -8} } },
	[25] = { .set = { {-1, -8}, {-12, -20}, {10, -20}, {-1, -9} } },
	[26] = { .set = { {-1, -10}, {-15, -3}, {13, -3}, {-1, -8} } },
	[27] = { .set = { {5, -9}, {12, -18}, {-14, -15}, {-1, -7} } },
	[28] = { .set = { {5, -8}, {7, -23}, {-11, -20}, {-1, -8} } },
	[29] = { .set = { {5, -10}, {9, -3}, {-11, 0}, {0, -9} } },
	[30] = { .set = { {12, -9}, {0, -20}, {-5, -14}, {1, -8} } },
	[31] = { .set = { {12, -8}, {0, -23}, {-4, -18}, {1, -7} } },
	[32] = { .set = { {12, -10}, {-2, -2}, {-4, 2}, {0, -8} } },
	[33] = { .set = { {3, -15}, {-14, -19}, {11, -9}, {-3, -9} } },
	[34] = { .set = { {3, -13}, {-10, -24}, {7, -18}, {-3, -10} } },
	[35] = { .set = { {2, -15}, {-14, -7}, {7, 1}, {-3, -9} } },
	[36] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[37] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[38] = { .set = { {-1, -15}, {12, -1}, {-14, -1}, {-1, -8} } },
	[39] = { .set = { {-5, -15}, {12, -19}, {-13, -9}, {1, -9} } },
	[40] = { .set = { {-5, -13}, {8, -24}, {-9, -18}, {1, -10} } },
	[41] = { .set = { {-4, -15}, {12, -7}, {-9, 1}, {1, -9} } },
	[42] = { .set = { {-14, -9}, {-2, -20}, {3, -14}, {-3, -8} } },
	[43] = { .set = { {-14, -8}, {-2, -23}, {2, -18}, {-3, -7} } },
	[44] = { .set = { {-14, -10}, {0, -2}, {2, 2}, {-2, -8} } },
	[45] = { .set = { {-7, -9}, {-14, -18}, {12, -15}, {-1, -7} } },
	[46] = { .set = { {-7, -8}, {-9, -23}, {9, -20}, {-1, -8} } },
	[47] = { .set = { {-7, -10}, {-11, -3}, {9, 0}, {-2, -9} } },
	[48] = { .set = { {-1, -9}, {-17, -15}, {15, -15}, {-1, -8} } },
	[49] = { .set = { {-1, -8}, {-12, -20}, {10, -20}, {-1, -9} } },
	[50] = { .set = { {-1, -10}, {-15, -3}, {13, -3}, {-1, -8} } },
	[51] = { .set = { {5, -9}, {12, -18}, {-14, -15}, {-1, -7} } },
	[52] = { .set = { {5, -8}, {7, -23}, {-11, -20}, {-1, -8} } },
	[53] = { .set = { {5, -10}, {9, -3}, {-11, 0}, {0, -9} } },
	[54] = { .set = { {12, -9}, {0, -20}, {-5, -14}, {1, -8} } },
	[55] = { .set = { {12, -8}, {0, -23}, {-4, -18}, {1, -7} } },
	[56] = { .set = { {12, -10}, {-2, -2}, {-4, 2}, {0, -8} } },
	[57] = { .set = { {3, -15}, {-14, -19}, {11, -9}, {-3, -9} } },
	[58] = { .set = { {3, -13}, {-10, -24}, {7, -18}, {-3, -10} } },
	[59] = { .set = { {2, -15}, {-14, -7}, {7, 1}, {-3, -9} } },
	[60] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[61] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[62] = { .set = { {-1, -15}, {12, -1}, {-14, -1}, {-1, -8} } },
	[63] = { .set = { {-5, -15}, {12, -19}, {-13, -9}, {1, -9} } },
	[64] = { .set = { {-5, -13}, {8, -24}, {-9, -18}, {1, -10} } },
	[65] = { .set = { {-4, -15}, {12, -7}, {-9, 1}, {1, -9} } },
	[66] = { .set = { {-14, -9}, {-2, -20}, {3, -14}, {-3, -8} } },
	[67] = { .set = { {-14, -8}, {-2, -23}, {2, -18}, {-3, -7} } },
	[68] = { .set = { {-14, -10}, {0, -2}, {2, 2}, {-2, -8} } },
	[69] = { .set = { {-7, -9}, {-14, -18}, {12, -15}, {-1, -7} } },
	[70] = { .set = { {-7, -8}, {-9, -23}, {9, -20}, {-1, -8} } },
	[71] = { .set = { {-7, -10}, {-11, -3}, {9, 0}, {-2, -9} } },
	[72] = { .set = { {-1, -9}, {-17, -15}, {15, -15}, {-1, -8} } },
	[73] = { .set = { {-1, -8}, {-12, -20}, {10, -20}, {-1, -9} } },
	[74] = { .set = { {-1, -10}, {-15, -3}, {13, -3}, {-1, -8} } },
	[75] = { .set = { {5, -9}, {12, -18}, {-14, -15}, {-1, -7} } },
	[76] = { .set = { {5, -8}, {7, -23}, {-11, -20}, {-1, -8} } },
	[77] = { .set = { {5, -10}, {9, -3}, {-11, 0}, {0, -9} } },
	[78] = { .set = { {12, -9}, {0, -20}, {-5, -14}, {1, -8} } },
	[79] = { .set = { {12, -8}, {0, -23}, {-4, -18}, {1, -7} } },
	[80] = { .set = { {12, -10}, {-2, -2}, {-4, 2}, {0, -8} } },
	[81] = { .set = { {3, -15}, {-14, -19}, {11, -9}, {-3, -9} } },
	[82] = { .set = { {3, -13}, {-10, -24}, {7, -18}, {-3, -10} } },
	[83] = { .set = { {2, -15}, {-14, -7}, {7, 1}, {-3, -9} } },
	[84] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[85] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[86] = { .set = { {-1, -15}, {12, -1}, {-14, -1}, {-1, -8} } },
	[87] = { .set = { {-5, -15}, {12, -19}, {-13, -9}, {1, -9} } },
	[88] = { .set = { {-5, -13}, {8, -24}, {-9, -18}, {1, -10} } },
	[89] = { .set = { {-4, -15}, {12, -7}, {-9, 1}, {1, -9} } },
	[90] = { .set = { {-14, -9}, {-2, -20}, {3, -14}, {-3, -8} } },
	[91] = { .set = { {-14, -8}, {-2, -23}, {2, -18}, {-3, -7} } },
	[92] = { .set = { {-14, -10}, {0, -2}, {2, 2}, {-2, -8} } },
	[93] = { .set = { {-7, -9}, {-14, -18}, {12, -15}, {-1, -7} } },
	[94] = { .set = { {-7, -8}, {-9, -23}, {9, -20}, {-1, -8} } },
	[95] = { .set = { {-7, -10}, {-11, -3}, {9, 0}, {-2, -9} } },
	[96] = { .set = { {-1, -12}, {-6, -5}, {4, -5}, {-1, -8} } },
	[97] = { .set = { {-1, -7}, {-17, -13}, {15, -13}, {-1, -6} } },
	[98] = { .set = { {-1, -5}, {-12, -17}, {10, -17}, {-1, -6} } },
	[99] = { .set = { {-1, -9}, {-15, -2}, {13, -2}, {-1, -7} } },
	[100] = { .set = { {-1, -11}, {-15, -19}, {13, -19}, {-1, -8} } },
	[101] = { .set = { {2, -11}, {0, -5}, {-8, -4}, {-1, -7} } },
	[102] = { .set = { {7, -7}, {14, -16}, {-12, -13}, {1, -5} } },
	[103] = { .set = { {7, -5}, {9, -20}, {-9, -17}, {1, -5} } },
	[104] = { .set = { {7, -9}, {11, -2}, {-9, 1}, {2, -8} } },
	[105] = { .set = { {3, -11}, {7, -23}, {-15, -17}, {0, -8} } },
	[106] = { .set = { {5, -12}, {-5, -5}, {-6, -3}, {-2, -8} } },
	[107] = { .set = { {12, -10}, {0, -21}, {-5, -15}, {1, -9} } },
	[108] = { .set = { {10, -9}, {-2, -24}, {-6, -19}, {-1, -8} } },
	[109] = { .set = { {10, -11}, {-4, -3}, {-6, 1}, {-2, -9} } },
	[110] = { .set = { {6, -12}, {-9, -20}, {-12, -15}, {0, -8} } },
	[111] = { .set = { {2, -14}, {-6, -5}, {-2, -3}, {-2, -8} } },
	[112] = { .set = { {5, -16}, {-12, -20}, {13, -10}, {-1, -10} } },
	[113] = { .set = { {5, -14}, {-8, -25}, {9, -19}, {-1, -11} } },
	[114] = { .set = { {4, -16}, {-12, -8}, {9, 0}, {-1, -10} } },
	[115] = { .set = { {3, -16}, {-10, -25}, {12, -18}, {-1, -9} } },
	[116] = { .set = { {-1, -17}, {1, -4}, {-3, -4}, {-1, -10} } },
	[117] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[118] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[119] = { .set = { {-1, -15}, {12, -1}, {-14, -1}, {-1, -8} } },
	[120] = { .set = { {-1, -17}, {14, -20}, {-16, -20}, {-1, -10} } },
	[121] = { .set = { {-3, -14}, {5, -5}, {1, -3}, {1, -8} } },
	[122] = { .set = { {-6, -16}, {11, -20}, {-14, -10}, {0, -10} } },
	[123] = { .set = { {-6, -14}, {7, -25}, {-10, -19}, {0, -11} } },
	[124] = { .set = { {-5, -16}, {11, -8}, {-10, 0}, {0, -10} } },
	[125] = { .set = { {-4, -16}, {9, -25}, {-13, -18}, {0, -9} } },
	[126] = { .set = { {-6, -12}, {4, -5}, {5, -3}, {1, -8} } },
	[127] = { .set = { {-13, -10}, {-1, -21}, {4, -15}, {-2, -9} } },
	[128] = { .set = { {-11, -9}, {1, -24}, {5, -19}, {0, -8} } },
	[129] = { .set = { {-11, -11}, {3, -3}, {5, 1}, {1, -9} } },
	[130] = { .set = { {-7, -12}, {8, -20}, {11, -15}, {-1, -8} } },
	[131] = { .set = { {-3, -11}, {-1, -5}, {7, -4}, {0, -7} } },
	[132] = { .set = { {-8, -7}, {-15, -16}, {11, -13}, {-2, -5} } },
	[133] = { .set = { {-8, -5}, {-10, -20}, {8, -17}, {-2, -5} } },
	[134] = { .set = { {-8, -9}, {-12, -2}, {8, 1}, {-3, -8} } },
	[135] = { .set = { {-4, -11}, {-8, -23}, {14, -17}, {-1, -8} } },
	[136] = { .set = { {-1, -9}, {-6, -3}, {4, -3}, {-1, -7} } },
	[137] = { .set = { {-1, -7}, {-6, -2}, {4, -2}, {-1, -5} } },
	[138] = { .set = { {2, -18}, {-10, -24}, {13, -19}, {0, -10} } },
	[139] = { .set = { {-1, -15}, {5, -24}, {-14, -16}, {1, -8} } },
	[140] = { .set = { {3, -18}, {-3, -25}, {-8, -18}, {-1, -8} } },
	[141] = { .set = { {5, -20}, {-4, -24}, {10, -13}, {-1, -9} } },
	[142] = { .set = { {-1, -13}, {10, -18}, {-11, -14}, {0, -6} } },
	[143] = { .set = { {-4, -20}, {5, -24}, {-9, -13}, {2, -9} } },
	[144] = { .set = { {-4, -17}, {2, -24}, {7, -17}, {0, -7} } },
	[145] = { .set = { {1, -15}, {-5, -24}, {14, -16}, {-1, -8} } },
	[146] = { .set = { {-1, -12}, {-6, -5}, {4, -5}, {-1, -8} } },
	[147] = { .set = { {-1, -11}, {-17, -17}, {15, -17}, {-1, -10} } },
	[148] = { .set = { {-1, -10}, {-12, -22}, {10, -22}, {-1, -11} } },
	[149] = { .set = { {-1, -12}, {-15, -5}, {13, -5}, {-1, -10} } },
	[150] = { .set = { {2, -11}, {0, -5}, {-8, -4}, {-1, -7} } },
	[151] = { .set = { {4, -9}, {11, -18}, {-15, -15}, {-2, -7} } },
	[152] = { .set = { {4, -8}, {6, -23}, {-12, -20}, {-2, -8} } },
	[153] = { .set = { {4, -10}, {8, -3}, {-12, 0}, {-1, -9} } },
	[154] = { .set = { {6, -11}, {-4, -4}, {-5, -2}, {-1, -7} } },
	[155] = { .set = { {10, -9}, {-2, -20}, {-7, -14}, {-1, -8} } },
	[156] = { .set = { {10, -8}, {-2, -23}, {-6, -18}, {-1, -7} } },
	[157] = { .set = { {10, -10}, {-4, -2}, {-6, 2}, {-2, -8} } },
	[158] = { .set = { {2, -14}, {-6, -5}, {-2, -3}, {-2, -8} } },
	[159] = { .set = { {4, -16}, {-13, -20}, {12, -10}, {-2, -10} } },
	[160] = { .set = { {4, -14}, {-9, -25}, {8, -19}, {-2, -11} } },
	[161] = { .set = { {3, -17}, {-13, -9}, {8, -1}, {-2, -11} } },
	[162] = { .set = { {-1, -17}, {1, -4}, {-3, -4}, {-1, -10} } },
	[163] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[164] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[165] = { .set = { {-1, -15}, {12, -1}, {-14, -1}, {-1, -8} } },
	[166] = { .set = { {-4, -14}, {4, -5}, {0, -3}, {0, -8} } },
	[167] = { .set = { {-4, -16}, {13, -20}, {-12, -10}, {2, -10} } },
	[168] = { .set = { {-4, -14}, {9, -25}, {-8, -19}, {2, -11} } },
	[169] = { .set = { {-3, -17}, {13, -9}, {-8, -1}, {2, -11} } },
	[170] = { .set = { {-8, -12}, {2, -5}, {3, -3}, {-1, -8} } },
	[171] = { .set = { {-11, -10}, {1, -21}, {6, -15}, {0, -9} } },
	[172] = { .set = { {-11, -9}, {1, -24}, {5, -19}, {0, -8} } },
	[173] = { .set = { {-11, -11}, {3, -3}, {5, 1}, {1, -9} } },
	[174] = { .set = { {-4, -11}, {-2, -5}, {6, -4}, {-1, -7} } },
	[175] = { .set = { {-6, -9}, {-13, -18}, {13, -15}, {0, -7} } },
	[176] = { .set = { {-6, -8}, {-8, -23}, {10, -20}, {0, -8} } },
	[177] = { .set = { {-6, -10}, {-10, -3}, {10, 0}, {-1, -9} } },
	[178] = { .set = { {-1, -8}, {-12, -20}, {10, -20}, {-1, -9} } },
	[179] = { .set = { {-7, -8}, {-9, -23}, {9, -20}, {-1, -8} } },
	[180] = { .set = { {-12, -8}, {0, -23}, {4, -18}, {-1, -7} } },
	[181] = { .set = { {-7, -13}, {6, -24}, {-11, -18}, {-1, -10} } },
	[182] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[183] = { .set = { {5, -13}, {-8, -24}, {9, -18}, {-1, -10} } },
	[184] = { .set = { {10, -8}, {-2, -23}, {-6, -18}, {-1, -7} } },
	[185] = { .set = { {5, -8}, {7, -23}, {-11, -20}, {-1, -8} } },
	[186] = { .set = { {-1, -11}, {-15, -19}, {13, -19}, {-1, -8} } },
	[187] = { .set = { {3, -11}, {7, -23}, {-15, -17}, {0, -8} } },
	[188] = { .set = { {7, -12}, {-8, -20}, {-11, -15}, {1, -8} } },
	[189] = { .set = { {3, -16}, {-10, -25}, {12, -18}, {-1, -9} } },
	[190] = { .set = { {-1, -17}, {14, -20}, {-16, -20}, {-1, -10} } },
	[191] = { .set = { {-4, -16}, {9, -25}, {-13, -18}, {0, -9} } },
	[192] = { .set = { {-8, -12}, {7, -20}, {10, -15}, {-2, -8} } },
	[193] = { .set = { {-4, -11}, {-8, -23}, {14, -17}, {-1, -8} } },
	[194] = { .set = { {-1, -11}, {-6, -4}, {4, -4}, {-1, -7} } },
	[195] = { .set = { {-1, -9}, {-17, -15}, {15, -15}, {-1, -8} } },
	[196] = { .set = { {-1, -8}, {-12, -20}, {10, -20}, {-1, -9} } },
	[197] = { .set = { {-1, -8}, {-15, -1}, {13, -1}, {-1, -6} } },
	[198] = { .set = { {3, -11}, {1, -5}, {-7, -4}, {0, -7} } },
	[199] = { .set = { {5, -9}, {12, -18}, {-14, -15}, {-1, -7} } },
	[200] = { .set = { {5, -8}, {7, -23}, {-11, -20}, {-1, -8} } },
	[201] = { .set = { {5, -8}, {9, -1}, {-11, 2}, {0, -7} } },
	[202] = { .set = { {6, -12}, {-4, -5}, {-5, -3}, {-1, -8} } },
	[203] = { .set = { {10, -9}, {-2, -20}, {-7, -14}, {-1, -8} } },
	[204] = { .set = { {10, -8}, {-2, -23}, {-6, -18}, {-1, -7} } },
	[205] = { .set = { {10, -8}, {-4, 0}, {-6, 4}, {-2, -6} } },
	[206] = { .set = { {2, -14}, {-6, -5}, {-2, -3}, {-2, -8} } },
	[207] = { .set = { {4, -15}, {-13, -19}, {12, -9}, {-2, -9} } },
	[208] = { .set = { {4, -13}, {-9, -24}, {8, -18}, {-2, -10} } },
	[209] = { .set = { {3, -14}, {-13, -6}, {8, 2}, {-2, -8} } },
	[210] = { .set = { {-1, -16}, {1, -3}, {-3, -3}, {-1, -9} } },
	[211] = { .set = { {-1, -14}, {15, -14}, {-17, -14}, {-1, -9} } },
	[212] = { .set = { {-1, -13}, {11, -21}, {-13, -21}, {-1, -9} } },
	[213] = { .set = { {-1, -13}, {12, 1}, {-14, 1}, {-1, -6} } },
	[214] = { .set = { {-4, -14}, {4, -5}, {0, -3}, {0, -8} } },
	[215] = { .set = { {-6, -15}, {11, -19}, {-14, -9}, {0, -9} } },
	[216] = { .set = { {-6, -13}, {7, -24}, {-10, -18}, {0, -10} } },
	[217] = { .set = { {-5, -14}, {11, -6}, {-10, 2}, {0, -8} } },
	[218] = { .set = { {-8, -12}, {2, -5}, {3, -3}, {-1, -8} } },
	[219] = { .set = { {-12, -9}, {0, -20}, {5, -14}, {-1, -8} } },
	[220] = { .set = { {-12, -8}, {0, -23}, {4, -18}, {-1, -7} } },
	[221] = { .set = { {-12, -8}, {2, 0}, {4, 4}, {0, -6} } },
	[222] = { .set = { {-5, -11}, {-3, -5}, {5, -4}, {-2, -7} } },
	[223] = { .set = { {-7, -9}, {-14, -18}, {12, -15}, {-1, -7} } },
	[224] = { .set = { {-7, -8}, {-9, -23}, {9, -20}, {-1, -8} } },
	[225] = { .set = { {-7, -8}, {-11, -1}, {9, 2}, {-2, -7} } },
	[226] = { .set = { {-1, -11}, {-15, -19}, {13, -19}, {-1, -8} } },
	[227] = { .set = { {3, -11}, {7, -23}, {-15, -17}, {0, -8} } },
	[228] = { .set = { {7, -12}, {-8, -20}, {-11, -15}, {1, -8} } },
	[229] = { .set = { {3, -16}, {-10, -25}, {12, -18}, {-1, -9} } },
	[230] = { .set = { {-1, -17}, {14, -20}, {-16, -20}, {-1, -10} } },
	[231] = { .set = { {-4, -16}, {9, -25}, {-13, -18}, {0, -9} } },
	[232] = { .set = { {-8, -12}, {7, -20}, {10, -15}, {-2, -8} } },
	[233] = { .set = { {-4, -11}, {-8, -23}, {14, -17}, {-1, -8} } },
	[234] = { .set = { {-1, -11}, {-6, -4}, {4, -4}, {-1, -7} } },
	[235] = { .set = { {-5, -11}, {-3, -5}, {5, -4}, {-2, -7} } },
	[236] = { .set = { {-8, -12}, {2, -5}, {3, -3}, {-1, -8} } },
	[237] = { .set = { {-4, -14}, {4, -5}, {0, -3}, {0, -8} } },
	[238] = { .set = { {-1, -16}, {1, -3}, {-3, -3}, {-1, -9} } },
	[239] = { .set = { {2, -14}, {-6, -5}, {-2, -3}, {-2, -8} } },
	[240] = { .set = { {6, -12}, {-4, -5}, {-5, -3}, {-1, -8} } },
	[241] = { .set = { {3, -11}, {1, -5}, {-7, -4}, {0, -7} } },
};

static const ax_anim *const sNoctowlAnimTable1[] = {
	sNoctowlAnims_1_1,
	sNoctowlAnims_1_2,
	sNoctowlAnims_1_3,
	sNoctowlAnims_1_4,
	sNoctowlAnims_1_5,
	sNoctowlAnims_1_6,
	sNoctowlAnims_1_7,
	sNoctowlAnims_1_8,
};

static const ax_anim *const sNoctowlAnimTable2[] = {
	sNoctowlAnims_2_1,
	sNoctowlAnims_2_2,
	sNoctowlAnims_2_3,
	sNoctowlAnims_2_4,
	sNoctowlAnims_2_5,
	sNoctowlAnims_2_6,
	sNoctowlAnims_2_7,
	sNoctowlAnims_2_8,
};

static const ax_anim *const sNoctowlAnimTable3[] = {
	sNoctowlAnims_3_1,
	sNoctowlAnims_3_2,
	sNoctowlAnims_3_3,
	sNoctowlAnims_3_4,
	sNoctowlAnims_3_5,
	sNoctowlAnims_3_6,
	sNoctowlAnims_3_7,
	sNoctowlAnims_3_8,
};

static const ax_anim *const sNoctowlAnimTable4[] = {
	sNoctowlAnims_4_1,
	sNoctowlAnims_4_2,
	sNoctowlAnims_4_3,
	sNoctowlAnims_4_4,
	sNoctowlAnims_4_5,
	sNoctowlAnims_4_6,
	sNoctowlAnims_4_7,
	sNoctowlAnims_4_8,
};

static const ax_anim *const sNoctowlAnimTable5[] = {
	sNoctowlAnims_5_1,
	sNoctowlAnims_5_2,
	sNoctowlAnims_5_3,
	sNoctowlAnims_5_4,
	sNoctowlAnims_5_5,
	sNoctowlAnims_5_6,
	sNoctowlAnims_5_7,
	sNoctowlAnims_5_8,
};

static const ax_anim *const sNoctowlAnimTable6[] = {
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
	sNoctowlAnims_6_1,
};

static const ax_anim *const sNoctowlAnimTable7[] = {
	sNoctowlAnims_7_1,
	sNoctowlAnims_7_2,
	sNoctowlAnims_7_3,
	sNoctowlAnims_7_4,
	sNoctowlAnims_7_5,
	sNoctowlAnims_7_6,
	sNoctowlAnims_7_7,
	sNoctowlAnims_7_8,
};

static const ax_anim *const sNoctowlAnimTable8[] = {
	sNoctowlAnims_8_1,
	sNoctowlAnims_8_2,
	sNoctowlAnims_8_3,
	sNoctowlAnims_8_4,
	sNoctowlAnims_8_5,
	sNoctowlAnims_8_6,
	sNoctowlAnims_8_7,
	sNoctowlAnims_8_8,
};

static const ax_anim *const sNoctowlAnimTable9[] = {
	sNoctowlAnims_9_1,
	sNoctowlAnims_9_2,
	sNoctowlAnims_9_3,
	sNoctowlAnims_9_4,
	sNoctowlAnims_9_5,
	sNoctowlAnims_9_6,
	sNoctowlAnims_9_7,
	sNoctowlAnims_9_8,
};

static const ax_anim *const sNoctowlAnimTable10[] = {
	sNoctowlAnims_10_1,
	sNoctowlAnims_10_2,
	sNoctowlAnims_10_3,
	sNoctowlAnims_10_4,
	sNoctowlAnims_10_5,
	sNoctowlAnims_10_6,
	sNoctowlAnims_10_7,
	sNoctowlAnims_10_8,
};

static const ax_anim *const sNoctowlAnimTable11[] = {
	sNoctowlAnims_11_1,
	sNoctowlAnims_11_2,
	sNoctowlAnims_11_3,
	sNoctowlAnims_11_4,
	sNoctowlAnims_11_5,
	sNoctowlAnims_11_6,
	sNoctowlAnims_11_7,
	sNoctowlAnims_11_8,
};

static const ax_anim *const sNoctowlAnimTable12[] = {
	sNoctowlAnims_12_1,
	sNoctowlAnims_12_2,
	sNoctowlAnims_12_3,
	sNoctowlAnims_12_4,
	sNoctowlAnims_12_5,
	sNoctowlAnims_12_6,
	sNoctowlAnims_12_7,
	sNoctowlAnims_12_8,
};

static const ax_anim *const sNoctowlAnimTable13[] = {
	sNoctowlAnims_13_1,
	sNoctowlAnims_13_2,
	sNoctowlAnims_13_3,
	sNoctowlAnims_13_4,
	sNoctowlAnims_13_5,
	sNoctowlAnims_13_6,
	sNoctowlAnims_13_7,
	sNoctowlAnims_13_8,
};

static const ax_anim *const *const sAxAnimationsNoctowl[] = {
	sNoctowlAnimTable1,
	sNoctowlAnimTable2,
	sNoctowlAnimTable3,
	sNoctowlAnimTable4,
	sNoctowlAnimTable5,
	sNoctowlAnimTable6,
	sNoctowlAnimTable7,
	sNoctowlAnimTable8,
	sNoctowlAnimTable9,
	sNoctowlAnimTable10,
	sNoctowlAnimTable11,
	sNoctowlAnimTable12,
	sNoctowlAnimTable13,
};

static const ax_sprite *const sAxSpritesNoctowl[] = {
	sNoctowlSprites1,
	sNoctowlSprites2,
	sNoctowlSprites3,
	sNoctowlSprites4,
	sNoctowlSprites5,
	sNoctowlSprites6,
	sNoctowlSprites7,
	sNoctowlSprites8,
	sNoctowlSprites9,
	sNoctowlSprites10,
	sNoctowlSprites11,
	sNoctowlSprites12,
	sNoctowlSprites13,
	sNoctowlSprites14,
	sNoctowlSprites15,
	sNoctowlSprites16,
	sNoctowlSprites17,
	sNoctowlSprites18,
	sNoctowlSprites19,
	sNoctowlSprites20,
	sNoctowlSprites21,
	sNoctowlSprites22,
	sNoctowlSprites23,
	sNoctowlSprites24,
	sNoctowlSprites25,
	sNoctowlSprites26,
	sNoctowlSprites27,
	sNoctowlSprites28,
	sNoctowlSprites29,
	sNoctowlSprites30,
	sNoctowlSprites31,
	sNoctowlSprites32,
	sNoctowlSprites33,
	sNoctowlSprites34,
	sNoctowlSprites35,
	sNoctowlSprites36,
	sNoctowlSprites37,
	sNoctowlSprites38,
	sNoctowlSprites39,
	sNoctowlSprites40,
	sNoctowlSprites41,
	sNoctowlSprites42,
	sNoctowlSprites43,
	sNoctowlSprites44,
	sNoctowlSprites45,
	sNoctowlSprites46,
	sNoctowlSprites47,
	sNoctowlSprites48,
};

static const axmain sAxMainNoctowl = {
	.poses = sAxPosesNoctowl,
	.animations = sAxAnimationsNoctowl,
	.animCount = ARRAY_COUNT(sAxAnimationsNoctowl),
	.spriteData = sAxSpritesNoctowl,
	.positions = sAxPositionsNoctowl,
};
