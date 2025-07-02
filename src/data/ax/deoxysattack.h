static const axmain sAxMainDeoxysAttack;
const SiroArchive gAxDeoxysAttack = {"SIRO", &sAxMainDeoxysAttack};

static const ax_pose sDeoxysAttackPose1[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose2[] = {
	AX_POSE(1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose3[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose4[] = {
	AX_POSE(1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose5[] = {
	AX_POSE(2, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose6[] = {
	AX_POSE(3, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose7[] = {
	AX_POSE(4, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose8[] = {
	AX_POSE(5, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose9[] = {
	AX_POSE(6, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(7, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(8, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(9, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose10[] = {
	AX_POSE(10, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose11[] = {
	AX_POSE(11, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(12, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(13, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(14, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose12[] = {
	AX_POSE(15, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose13[] = {
	AX_POSE(16, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(17, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(18, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose14[] = {
	AX_POSE(20, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose15[] = {
	AX_POSE(21, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(22, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(23, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(2, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(24, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose16[] = {
	AX_POSE(25, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose17[] = {
	AX_POSE(26, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose18[] = {
	AX_POSE(27, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose19[] = {
	AX_POSE(26, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose20[] = {
	AX_POSE(27, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose21[] = {
	AX_POSE(16, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(17, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(18, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose22[] = {
	AX_POSE(20, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose23[] = {
	AX_POSE(21, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(22, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(23, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(24, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(15, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose24[] = {
	AX_POSE(25, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose25[] = {
	AX_POSE(6, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(7, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(8, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(9, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose26[] = {
	AX_POSE(10, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose27[] = {
	AX_POSE(11, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(12, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(13, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(14, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose28[] = {
	AX_POSE(15, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose29[] = {
	AX_POSE(2, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose30[] = {
	AX_POSE(3, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose31[] = {
	AX_POSE(4, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose32[] = {
	AX_POSE(5, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose33[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose34[] = {
	AX_POSE(1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose35[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose36[] = {
	AX_POSE(1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose37[] = {
	AX_POSE(28, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose38[] = {
	AX_POSE(2, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose39[] = {
	AX_POSE(3, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose40[] = {
	AX_POSE(4, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose41[] = {
	AX_POSE(5, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose42[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose43[] = {
	AX_POSE(6, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(7, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(8, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(9, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose44[] = {
	AX_POSE(10, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose45[] = {
	AX_POSE(11, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(12, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(13, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(14, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose46[] = {
	AX_POSE(15, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose47[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose48[] = {
	AX_POSE(16, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(17, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(18, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose49[] = {
	AX_POSE(20, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose50[] = {
	AX_POSE(21, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(22, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(23, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(2, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(24, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose51[] = {
	AX_POSE(25, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose52[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose53[] = {
	AX_POSE(26, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose54[] = {
	AX_POSE(27, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose55[] = {
	AX_POSE(26, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose56[] = {
	AX_POSE(27, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose57[] = {
	AX_POSE(32, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose58[] = {
	AX_POSE(16, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(17, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(18, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose59[] = {
	AX_POSE(20, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose60[] = {
	AX_POSE(21, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(22, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(23, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(24, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(15, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose61[] = {
	AX_POSE(25, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose62[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose63[] = {
	AX_POSE(6, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(7, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(8, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(9, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose64[] = {
	AX_POSE(10, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose65[] = {
	AX_POSE(11, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(12, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(13, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(14, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose66[] = {
	AX_POSE(15, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose67[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose68[] = {
	AX_POSE(2, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose69[] = {
	AX_POSE(3, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose70[] = {
	AX_POSE(4, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose71[] = {
	AX_POSE(5, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose72[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose73[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose74[] = {
	AX_POSE(1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose75[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose76[] = {
	AX_POSE(1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose77[] = {
	AX_POSE(28, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose78[] = {
	AX_POSE(2, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose79[] = {
	AX_POSE(3, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose80[] = {
	AX_POSE(4, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose81[] = {
	AX_POSE(5, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose82[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose83[] = {
	AX_POSE(6, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(7, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(8, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(9, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose84[] = {
	AX_POSE(10, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose85[] = {
	AX_POSE(11, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(12, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(13, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(14, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose86[] = {
	AX_POSE(15, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose87[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose88[] = {
	AX_POSE(16, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(17, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(18, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose89[] = {
	AX_POSE(20, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose90[] = {
	AX_POSE(21, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(22, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(23, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(2, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(24, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(234, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose91[] = {
	AX_POSE(25, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(233, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose92[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose93[] = {
	AX_POSE(26, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose94[] = {
	AX_POSE(27, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose95[] = {
	AX_POSE(26, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose96[] = {
	AX_POSE(27, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose97[] = {
	AX_POSE(32, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose98[] = {
	AX_POSE(16, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(17, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(18, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose99[] = {
	AX_POSE(20, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose100[] = {
	AX_POSE(21, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(22, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(23, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(7, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(19, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(24, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(15, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose101[] = {
	AX_POSE(25, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose102[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose103[] = {
	AX_POSE(6, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(7, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(8, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(9, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose104[] = {
	AX_POSE(10, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose105[] = {
	AX_POSE(11, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(12, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(13, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(14, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose106[] = {
	AX_POSE(15, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose107[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose108[] = {
	AX_POSE(2, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose109[] = {
	AX_POSE(3, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose110[] = {
	AX_POSE(4, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose111[] = {
	AX_POSE(5, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose112[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose113[] = {
	AX_POSE(33, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose114[] = {
	AX_POSE(28, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose115[] = {
	AX_POSE(34, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose116[] = {
	AX_POSE(35, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose117[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose118[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose119[] = {
	AX_POSE(37, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose120[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose121[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(1, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose122[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose123[] = {
	AX_POSE(43, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(44, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(45, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(46, OAM1(242, ST_OAM_SQUARE     , 1), OAM2(19, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(47, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose124[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose125[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose126[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose127[] = {
	AX_POSE(54, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(55, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(3, ST_OAM_SIZE_1, FLIP(1, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(56, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(11, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(57, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose128[] = {
	AX_POSE(58, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose129[] = {
	AX_POSE(59, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose130[] = {
	AX_POSE(32, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose131[] = {
	AX_POSE(60, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(61, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE(-1, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose132[] = {
	AX_POSE(62, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose133[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose134[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose135[] = {
	AX_POSE(54, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(55, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(56, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(57, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose136[] = {
	AX_POSE(58, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose137[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose138[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose139[] = {
	AX_POSE(43, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(44, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(45, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(46, OAM1(242, ST_OAM_SQUARE     , 1), OAM2(230, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(47, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose140[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose141[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose142[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose143[] = {
	AX_POSE(37, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose144[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose145[] = {
	AX_POSE(33, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose146[] = {
	AX_POSE(63, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 0)),
	AX_POSE(-1, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 0)),
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose147[] = {
	AX_POSE(70, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(13, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose148[] = {
	AX_POSE(71, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose149[] = {
	AX_POSE(72, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose150[] = {
	AX_POSE(73, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose151[] = {
	AX_POSE(74, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(249, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(16, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose152[] = {
	AX_POSE(64, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(65, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(66, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(67, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(68, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(69, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(14, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose153[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose154[] = {
	AX_POSE(63, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose155[] = {
	AX_POSE(70, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose156[] = {
	AX_POSE(71, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose157[] = {
	AX_POSE(72, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose158[] = {
	AX_POSE(73, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose159[] = {
	AX_POSE(74, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose160[] = {
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(13, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(3, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose161[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(1, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose162[] = {
	AX_POSE(63, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(-1, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose163[] = {
	AX_POSE(70, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(9, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(-1, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose164[] = {
	AX_POSE(71, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose165[] = {
	AX_POSE(72, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose166[] = {
	AX_POSE(73, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose167[] = {
	AX_POSE(74, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose168[] = {
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(8, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose169[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose170[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(63, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(224, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose171[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(70, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(224, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose172[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(71, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose173[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(72, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose174[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(73, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose175[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(74, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_1, FLIP(0, 0), 2, 1), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose176[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(247, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose177[] = {
	AX_POSE(59, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose178[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(63, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(255, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose179[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(70, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(255, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose180[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(71, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose181[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(72, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose182[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(73, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose183[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(74, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(222, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose184[] = {
	AX_POSE(93, OAM1(226, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(94, OAM1(242, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(95, OAM1(250, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(96, OAM1(250, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(97, OAM1(218, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose185[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose186[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(63, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(224, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose187[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(70, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(224, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose188[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(71, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose189[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(72, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose190[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(73, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose191[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE(74, OAM1(223, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE(-1, OAM1(220, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(16, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose192[] = {
	AX_POSE(87, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(88, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(89, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(90, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(91, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(92, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose193[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose194[] = {
	AX_POSE(63, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(-1, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose195[] = {
	AX_POSE(70, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(247, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(-1, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose196[] = {
	AX_POSE(71, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose197[] = {
	AX_POSE(72, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose198[] = {
	AX_POSE(73, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose199[] = {
	AX_POSE(74, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(-1, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose200[] = {
	AX_POSE(82, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(83, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(84, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(85, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(86, OAM1(219, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose201[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose202[] = {
	AX_POSE(63, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose203[] = {
	AX_POSE(70, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(250, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(1, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(9, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(11, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(16, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose204[] = {
	AX_POSE(71, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose205[] = {
	AX_POSE(72, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose206[] = {
	AX_POSE(73, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose207[] = {
	AX_POSE(74, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(-1, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(4, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(17, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(18, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(19, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose208[] = {
	AX_POSE(75, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(76, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(77, OAM1(243, ST_OAM_SQUARE     , 1), OAM2(5, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(78, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE(79, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(13, 3, 9)),
	AX_POSE(80, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(246, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(81, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose209[] = {
	AX_POSE(98, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose210[] = {
	AX_POSE(99, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose211[] = {
	AX_POSE(35, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose212[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose213[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose214[] = {
	AX_POSE(58, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose215[] = {
	AX_POSE(62, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose216[] = {
	AX_POSE(58, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose217[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose218[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose219[] = {
	AX_POSE(33, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose220[] = {
	AX_POSE(100, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose221[] = {
	AX_POSE(33, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose222[] = {
	AX_POSE(100, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose223[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose224[] = {
	AX_POSE(101, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose225[] = {
	AX_POSE(102, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose226[] = {
	AX_POSE(103, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose227[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(1, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose228[] = {
	AX_POSE(104, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(251, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(105, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(106, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose229[] = {
	AX_POSE(108, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(251, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(109, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose230[] = {
	AX_POSE(110, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(251, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(111, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(112, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose231[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose232[] = {
	AX_POSE(113, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(114, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose233[] = {
	AX_POSE(116, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(117, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose234[] = {
	AX_POSE(118, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(253, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(119, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(245, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose235[] = {
	AX_POSE(59, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose236[] = {
	AX_POSE(120, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose237[] = {
	AX_POSE(59, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose238[] = {
	AX_POSE(120, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose239[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose240[] = {
	AX_POSE(113, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(114, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(3, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose241[] = {
	AX_POSE(116, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(117, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(3, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose242[] = {
	AX_POSE(118, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(119, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(4, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose243[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose244[] = {
	AX_POSE(104, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(105, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(106, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose245[] = {
	AX_POSE(108, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(109, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(255, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose246[] = {
	AX_POSE(110, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(111, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(112, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose247[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose248[] = {
	AX_POSE(101, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose249[] = {
	AX_POSE(102, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose250[] = {
	AX_POSE(103, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose251[] = {
	AX_POSE(28, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose252[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose253[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose254[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose255[] = {
	AX_POSE(32, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose256[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose257[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose258[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose259[] = {
	AX_POSE(35, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose260[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose261[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(245, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose262[] = {
	AX_POSE(58, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose263[] = {
	AX_POSE(62, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose264[] = {
	AX_POSE(58, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose265[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(235, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose266[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose267[] = {
	AX_POSE(33, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose268[] = {
	AX_POSE(28, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose269[] = {
	AX_POSE(35, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose270[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose271[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose272[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose273[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(1, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose274[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose275[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose276[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose277[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose278[] = {
	AX_POSE(58, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose279[] = {
	AX_POSE(59, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose280[] = {
	AX_POSE(32, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose281[] = {
	AX_POSE(62, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose282[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose283[] = {
	AX_POSE(31, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose284[] = {
	AX_POSE(58, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose285[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose286[] = {
	AX_POSE(30, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose287[] = {
	AX_POSE(48, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose288[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose289[] = {
	AX_POSE(29, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose290[] = {
	AX_POSE(38, OAM1(225, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose291[] = {
	AX_POSE(100, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose292[] = {
	AX_POSE(101, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose293[] = {
	AX_POSE(104, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(105, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(106, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(6, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(10, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose294[] = {
	AX_POSE(113, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(114, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(3, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose295[] = {
	AX_POSE(120, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose296[] = {
	AX_POSE(113, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(254, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(114, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(246, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(115, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(254, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose297[] = {
	AX_POSE(104, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(251, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(105, OAM1(235, ST_OAM_V_RECTANGLE, 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(106, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(10, 3, 9)),
	AX_POSE(107, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(251, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(11, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose298[] = {
	AX_POSE(101, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose299[] = {
	AX_POSE(33, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose300[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose301[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose302[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(240, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(0, ST_OAM_SIZE_0, FLIP(0, 0), 0, 1), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose303[] = {
	AX_POSE(59, OAM1(226, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose304[] = {
	AX_POSE(49, OAM1(227, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE(50, OAM1(243, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(51, OAM1(251, ST_OAM_H_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(52, OAM1(251, ST_OAM_SQUARE     , 1), OAM2(1, ST_OAM_SIZE_0, FLIP(1, 0), 0, 1), OAM3(14, 3, 9)),
	AX_POSE(53, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(15, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose305[] = {
	AX_POSE(39, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(1, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 9)),
	AX_POSE(40, OAM1(227, ST_OAM_V_RECTANGLE, 1), OAM2(249, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(8, 3, 9)),
	AX_POSE(41, OAM1(243, ST_OAM_V_RECTANGLE, 1), OAM2(241, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(12, 3, 9)),
	AX_POSE(42, OAM1(219, ST_OAM_SQUARE     , 1), OAM2(253, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(14, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_pose sDeoxysAttackPose306[] = {
	AX_POSE(36, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 9)),
	AX_POSE_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 0, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 0, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 0, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 1, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 3, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 2, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 2, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 2, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 3, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 1, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 4, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 4, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 4, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 5, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 7, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 6, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 6, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 6, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 7, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 5, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 8, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 8, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 8, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 9, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 11, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 10, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 10, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 10, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 11, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 9, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 12, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 12, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 12, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 13, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 15, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 14, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 14, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 14, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 15, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 13, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 16, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 16, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 16, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 17, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 19, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 18, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 18, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 18, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 19, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 17, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 20, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 20, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 20, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 21, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 23, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 22, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 22, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 22, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 23, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 21, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 24, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 24, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 24, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 25, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 27, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 26, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 26, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 26, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 27, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 25, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_1_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 28, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 28, .offset = {0, -3}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 28, .offset = {0, -4}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 29, .offset = {0, -5}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 31, .offset = {0, -5}, .shadow = {0, 1} },
	{ .frames = 8, .unkFlags = 0, .poseId = 30, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 30, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 30, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 31, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 29, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 32, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 32, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 34, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 32, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 34, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 32, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 36, .offset = {0, 20}, .shadow = {0, 20} },
	{ .frames = 2, .unkFlags = 1, .poseId = 36, .offset = {1, 20}, .shadow = {1, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 36, .offset = {0, 20}, .shadow = {0, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 36, .offset = {1, 20}, .shadow = {1, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 32, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 37, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 39, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 37, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 39, .offset = {4, 4}, .shadow = {4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 37, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 41, .offset = {19, 20}, .shadow = {19, 20} },
	{ .frames = 2, .unkFlags = 1, .poseId = 41, .offset = {20, 19}, .shadow = {20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 41, .offset = {19, 20}, .shadow = {19, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 41, .offset = {20, 19}, .shadow = {20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {6, 6}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 42, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 42, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 44, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 42, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 44, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 42, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {22, 0}, .shadow = {22, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 46, .offset = {22, 1}, .shadow = {22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {22, 0}, .shadow = {22, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {22, 1}, .shadow = {22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 42, .offset = {8, 0}, .shadow = {8, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 47, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 47, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 49, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 47, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 49, .offset = {7, -4}, .shadow = {7, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 47, .offset = {12, -8}, .shadow = {12, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 51, .offset = {23, -14}, .shadow = {23, -14} },
	{ .frames = 2, .unkFlags = 1, .poseId = 51, .offset = {24, -13}, .shadow = {24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 51, .offset = {23, -14}, .shadow = {23, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 51, .offset = {24, -13}, .shadow = {24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 47, .offset = {8, -5}, .shadow = {8, -5} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 52, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 54, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 52, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 54, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 52, .offset = {0, -8}, .shadow = {0, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 56, .offset = {0, -15}, .shadow = {0, -15} },
	{ .frames = 2, .unkFlags = 1, .poseId = 56, .offset = {1, -15}, .shadow = {1, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 56, .offset = {0, -15}, .shadow = {0, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 56, .offset = {1, -15}, .shadow = {1, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 57, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 57, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 59, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 57, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 59, .offset = {-7, -4}, .shadow = {-7, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 57, .offset = {-12, -8}, .shadow = {-12, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {-23, -14}, .shadow = {-23, -14} },
	{ .frames = 2, .unkFlags = 1, .poseId = 61, .offset = {-24, -13}, .shadow = {-24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {-23, -14}, .shadow = {-23, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {-24, -13}, .shadow = {-24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 57, .offset = {-8, -5}, .shadow = {-8, -5} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 62, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 62, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 64, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 62, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 64, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 62, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 66, .offset = {-22, 0}, .shadow = {-22, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 66, .offset = {-22, 1}, .shadow = {-22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 66, .offset = {-22, 0}, .shadow = {-22, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 66, .offset = {-22, 1}, .shadow = {-22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 62, .offset = {-8, 0}, .shadow = {-8, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_2_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 67, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 69, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 67, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 69, .offset = {-4, 4}, .shadow = {-4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 67, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 71, .offset = {-19, 20}, .shadow = {-19, 20} },
	{ .frames = 2, .unkFlags = 1, .poseId = 71, .offset = {-20, 19}, .shadow = {-20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 71, .offset = {-19, 20}, .shadow = {-19, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 71, .offset = {-20, 19}, .shadow = {-20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 72, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 72, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 74, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 74, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 72, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {0, 20}, .shadow = {0, 20} },
	{ .frames = 2, .unkFlags = 1, .poseId = 76, .offset = {1, 20}, .shadow = {1, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {0, 20}, .shadow = {0, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {1, 20}, .shadow = {1, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 72, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 77, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 77, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 79, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 79, .offset = {4, 4}, .shadow = {4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 77, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 81, .offset = {19, 20}, .shadow = {19, 20} },
	{ .frames = 2, .unkFlags = 1, .poseId = 81, .offset = {20, 19}, .shadow = {20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 81, .offset = {19, 20}, .shadow = {19, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 81, .offset = {20, 19}, .shadow = {20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 77, .offset = {6, 6}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 82, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 82, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 84, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 84, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 82, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {22, 0}, .shadow = {22, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 86, .offset = {22, 1}, .shadow = {22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {22, 0}, .shadow = {22, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {22, 1}, .shadow = {22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 82, .offset = {8, 0}, .shadow = {8, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 87, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 87, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 89, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 89, .offset = {7, -4}, .shadow = {7, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 87, .offset = {12, -8}, .shadow = {12, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 91, .offset = {23, -14}, .shadow = {23, -14} },
	{ .frames = 2, .unkFlags = 1, .poseId = 91, .offset = {24, -13}, .shadow = {24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 91, .offset = {23, -14}, .shadow = {23, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 91, .offset = {24, -13}, .shadow = {24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 87, .offset = {8, -5}, .shadow = {8, -5} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 92, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 92, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 94, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 94, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 92, .offset = {0, -8}, .shadow = {0, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 96, .offset = {0, -15}, .shadow = {0, -15} },
	{ .frames = 2, .unkFlags = 1, .poseId = 96, .offset = {1, -15}, .shadow = {1, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 96, .offset = {0, -15}, .shadow = {0, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 96, .offset = {1, -15}, .shadow = {1, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 92, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 97, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 97, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 99, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 97, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 1, .unkFlags = 2, .poseId = 99, .offset = {-7, -4}, .shadow = {-7, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 97, .offset = {-12, -8}, .shadow = {-12, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 101, .offset = {-23, -14}, .shadow = {-23, -14} },
	{ .frames = 2, .unkFlags = 1, .poseId = 101, .offset = {-24, -13}, .shadow = {-24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 101, .offset = {-23, -14}, .shadow = {-23, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 101, .offset = {-24, -13}, .shadow = {-24, -13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 97, .offset = {-8, -5}, .shadow = {-8, -5} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 102, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 102, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 104, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 102, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 104, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 102, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 106, .offset = {-22, 0}, .shadow = {-22, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 106, .offset = {-22, 1}, .shadow = {-22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 106, .offset = {-22, 0}, .shadow = {-22, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 106, .offset = {-22, 1}, .shadow = {-22, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 102, .offset = {-8, 0}, .shadow = {-8, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_3_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 107, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 107, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 109, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 107, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 2, .poseId = 109, .offset = {-4, 4}, .shadow = {-4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 107, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 111, .offset = {-19, 20}, .shadow = {-19, 20} },
	{ .frames = 2, .unkFlags = 1, .poseId = 111, .offset = {-20, 19}, .shadow = {-20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 111, .offset = {-19, 20}, .shadow = {-19, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 111, .offset = {-20, 19}, .shadow = {-20, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 107, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 115, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 115, .offset = {0, -3}, .shadow = {0, -3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 112, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 114, .offset = {0, 3}, .shadow = {0, 3} },
	{ .frames = 4, .unkFlags = 2, .poseId = 114, .offset = {1, 3}, .shadow = {1, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 114, .offset = {0, 3}, .shadow = {0, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 114, .offset = {1, 3}, .shadow = {1, 3} },
	{ .frames = 2, .unkFlags = 1, .poseId = 114, .offset = {0, 3}, .shadow = {0, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 115, .offset = {0, -5}, .shadow = {0, -5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 115, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 119, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 119, .offset = {-3, -3}, .shadow = {-3, -3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 116, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 118, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 4, .unkFlags = 2, .poseId = 118, .offset = {3, 1}, .shadow = {3, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 118, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 118, .offset = {3, 1}, .shadow = {3, 1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 118, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 119, .offset = {-5, -5}, .shadow = {-5, -5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 119, .offset = {-6, -6}, .shadow = {-6, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 123, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 123, .offset = {-3, 0}, .shadow = {-3, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 120, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 122, .offset = {3, 0}, .shadow = {3, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 122, .offset = {3, -1}, .shadow = {3, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 122, .offset = {3, 0}, .shadow = {3, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 122, .offset = {3, -1}, .shadow = {3, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 122, .offset = {3, 0}, .shadow = {3, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 123, .offset = {-5, 0}, .shadow = {-5, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 123, .offset = {-6, 0}, .shadow = {-6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 127, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 127, .offset = {-3, 3}, .shadow = {-3, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 124, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 126, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 4, .unkFlags = 2, .poseId = 126, .offset = {3, -1}, .shadow = {3, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 126, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 126, .offset = {3, -1}, .shadow = {3, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 126, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 127, .offset = {-5, 5}, .shadow = {-5, 5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 127, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 131, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 131, .offset = {0, 3}, .shadow = {0, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 128, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 130, .offset = {0, -3}, .shadow = {0, -3} },
	{ .frames = 4, .unkFlags = 2, .poseId = 130, .offset = {1, -3}, .shadow = {1, -3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 130, .offset = {0, -3}, .shadow = {0, -3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 130, .offset = {1, -3}, .shadow = {1, -3} },
	{ .frames = 2, .unkFlags = 1, .poseId = 130, .offset = {0, -3}, .shadow = {0, -3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 131, .offset = {0, 5}, .shadow = {0, 5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 131, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 135, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 135, .offset = {3, 3}, .shadow = {3, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 132, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 134, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 4, .unkFlags = 2, .poseId = 134, .offset = {-3, -1}, .shadow = {-3, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 134, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 134, .offset = {-3, -1}, .shadow = {-3, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 134, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 135, .offset = {5, 5}, .shadow = {5, 5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 135, .offset = {6, 6}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 139, .offset = {3, 0}, .shadow = {3, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 136, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 138, .offset = {-3, 0}, .shadow = {-3, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 138, .offset = {-3, -1}, .shadow = {-3, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {-3, 0}, .shadow = {-3, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {-3, -1}, .shadow = {-3, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 138, .offset = {-3, 0}, .shadow = {-3, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {5, 0}, .shadow = {5, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 139, .offset = {6, 0}, .shadow = {6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_4_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 143, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 143, .offset = {3, -3}, .shadow = {3, -3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 140, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 142, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 4, .unkFlags = 2, .poseId = 142, .offset = {-3, 1}, .shadow = {-3, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 142, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 142, .offset = {-3, 1}, .shadow = {-3, 1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 142, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 143, .offset = {5, -5}, .shadow = {5, -5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 143, .offset = {6, -6}, .shadow = {6, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 144, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 144, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 151, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 146, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 147, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 148, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 149, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 146, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 150, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 151, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 159, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 152, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 159, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 159, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 154, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 155, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 156, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 157, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 154, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 158, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 159, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 167, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 160, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 167, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 160, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 167, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 162, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 163, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 164, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 165, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 162, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 166, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 167, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 175, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 168, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 175, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 168, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 175, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 170, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 171, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 172, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 173, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 170, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 174, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 175, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 183, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 176, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 183, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 176, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 183, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 178, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 180, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 181, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 178, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 183, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 184, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 184, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 186, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 187, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 189, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 186, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 190, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 199, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 192, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 199, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 192, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 199, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 195, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 196, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 197, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 198, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 199, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_5_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_6_1[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 210, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 210, .offset = {0, -3}, .shadow = {0, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 211, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 211, .offset = {-3, -3}, .shadow = {-3, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 212, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 212, .offset = {-3, 0}, .shadow = {-3, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 213, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 213, .offset = {-3, 3}, .shadow = {-3, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 214, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 3}, .shadow = {0, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 215, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 215, .offset = {3, 3}, .shadow = {3, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 216, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 216, .offset = {3, 0}, .shadow = {3, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_7_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 217, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 217, .offset = {3, -3}, .shadow = {3, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_1[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 218, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 219, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 220, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 221, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_2[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 222, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 223, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 224, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_3[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 226, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 227, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 228, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 229, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_4[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 230, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 231, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 233, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_5[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 234, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 235, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 236, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 237, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_6[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 238, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 239, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 240, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 241, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_7[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 242, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 243, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 244, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 245, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_8_8[] = {
	{ .frames = 14, .unkFlags = 0, .poseId = 246, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 247, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 15, .unkFlags = 0, .poseId = 248, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 14, .unkFlags = 0, .poseId = 249, .offset = {0, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 251, .offset = {7, 4}, .shadow = {7, 4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 252, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 253, .offset = {8, 17}, .shadow = {8, 17} },
	{ .frames = 3, .unkFlags = 0, .poseId = 254, .offset = {0, 19}, .shadow = {0, 19} },
	{ .frames = 2, .unkFlags = 3, .poseId = 255, .offset = {-8, 17}, .shadow = {-8, 17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 256, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 1, .unkFlags = 0, .poseId = 257, .offset = {-7, 4}, .shadow = {-7, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 257, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 250, .offset = {8, 0}, .shadow = {8, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 251, .offset = {16, 3}, .shadow = {16, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 252, .offset = {24, 9}, .shadow = {24, 9} },
	{ .frames = 3, .unkFlags = 0, .poseId = 253, .offset = {22, 19}, .shadow = {22, 19} },
	{ .frames = 2, .unkFlags = 3, .poseId = 254, .offset = {13, 20}, .shadow = {13, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 255, .offset = {1, 18}, .shadow = {1, 18} },
	{ .frames = 1, .unkFlags = 0, .poseId = 256, .offset = {-2, 7}, .shadow = {-2, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 257, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 256, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 257, .offset = {3, -5}, .shadow = {3, -5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 250, .offset = {11, -7}, .shadow = {11, -7} },
	{ .frames = 2, .unkFlags = 0, .poseId = 251, .offset = {19, -6}, .shadow = {19, -6} },
	{ .frames = 3, .unkFlags = 0, .poseId = 252, .offset = {23, -2}, .shadow = {23, -2} },
	{ .frames = 2, .unkFlags = 3, .poseId = 253, .offset = {21, 5}, .shadow = {21, 5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 254, .offset = {12, 6}, .shadow = {12, 6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 255, .offset = {1, 5}, .shadow = {1, 5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 256, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 255, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 256, .offset = {0, -8}, .shadow = {0, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 257, .offset = {4, -17}, .shadow = {4, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 250, .offset = {12, -20}, .shadow = {12, -20} },
	{ .frames = 3, .unkFlags = 0, .poseId = 251, .offset = {21, -20}, .shadow = {21, -20} },
	{ .frames = 2, .unkFlags = 3, .poseId = 252, .offset = {26, -14}, .shadow = {26, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 253, .offset = {21, -5}, .shadow = {21, -5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 254, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 255, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 255, .offset = {-8, -4}, .shadow = {-8, -4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 256, .offset = {-9, -11}, .shadow = {-9, -11} },
	{ .frames = 2, .unkFlags = 0, .poseId = 257, .offset = {-7, -18}, .shadow = {-7, -18} },
	{ .frames = 3, .unkFlags = 0, .poseId = 250, .offset = {0, -20}, .shadow = {0, -20} },
	{ .frames = 2, .unkFlags = 3, .poseId = 251, .offset = {8, -18}, .shadow = {8, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 252, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 1, .unkFlags = 0, .poseId = 253, .offset = {9, -2}, .shadow = {9, -2} },
	{ .frames = 1, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 252, .offset = {0, -8}, .shadow = {0, -8} },
	{ .frames = 2, .unkFlags = 0, .poseId = 251, .offset = {-4, -17}, .shadow = {-4, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 250, .offset = {-12, -20}, .shadow = {-12, -20} },
	{ .frames = 3, .unkFlags = 0, .poseId = 257, .offset = {-21, -20}, .shadow = {-21, -20} },
	{ .frames = 2, .unkFlags = 3, .poseId = 256, .offset = {-26, -14}, .shadow = {-26, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 255, .offset = {-21, -5}, .shadow = {-21, -5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 254, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 251, .offset = {-3, -5}, .shadow = {-3, -5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 250, .offset = {-11, -7}, .shadow = {-11, -7} },
	{ .frames = 2, .unkFlags = 0, .poseId = 257, .offset = {-19, -6}, .shadow = {-19, -6} },
	{ .frames = 3, .unkFlags = 0, .poseId = 256, .offset = {-23, -2}, .shadow = {-23, -2} },
	{ .frames = 2, .unkFlags = 3, .poseId = 255, .offset = {-21, 5}, .shadow = {-21, 5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 254, .offset = {-12, 6}, .shadow = {-12, 6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 253, .offset = {-1, 5}, .shadow = {-1, 5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_9_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 250, .offset = {-8, 0}, .shadow = {-8, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 257, .offset = {-16, 3}, .shadow = {-16, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 256, .offset = {-24, 9}, .shadow = {-24, 9} },
	{ .frames = 3, .unkFlags = 0, .poseId = 255, .offset = {-22, 19}, .shadow = {-22, 19} },
	{ .frames = 2, .unkFlags = 3, .poseId = 254, .offset = {-13, 20}, .shadow = {-13, 20} },
	{ .frames = 2, .unkFlags = 0, .poseId = 253, .offset = {-1, 18}, .shadow = {-1, 18} },
	{ .frames = 1, .unkFlags = 0, .poseId = 252, .offset = {2, 7}, .shadow = {2, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 258, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 258, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 258, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 258, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 259, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 259, .offset = {13, -13}, .shadow = {13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 259, .offset = {-13, 13}, .shadow = {-13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 259, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 259, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 260, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 260, .offset = {0, -13}, .shadow = {0, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 260, .offset = {0, 13}, .shadow = {0, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 260, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 260, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 261, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 261, .offset = {-13, -13}, .shadow = {-13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 261, .offset = {13, 13}, .shadow = {13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 261, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 261, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 262, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 262, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 262, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 262, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 262, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 263, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 263, .offset = {13, -13}, .shadow = {13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 263, .offset = {-13, 13}, .shadow = {-13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 263, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 264, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 264, .offset = {0, -13}, .shadow = {0, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 264, .offset = {0, 13}, .shadow = {0, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 264, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 264, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_10_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 265, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 265, .offset = {-13, -13}, .shadow = {-13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 265, .offset = {13, 13}, .shadow = {13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 265, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 265, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 266, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 266, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 266, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 266, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 266, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 266, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 267, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 267, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 267, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 267, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 269, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 269, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 269, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 269, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 269, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 269, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 270, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 270, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 270, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 270, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 272, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 272, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 272, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 272, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 272, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 272, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 273, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 273, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 273, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 273, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 275, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 275, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 275, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 275, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 275, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 275, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 276, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 276, .offset = {0, -17}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 276, .offset = {0, -11}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 276, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 278, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 278, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 278, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 278, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 278, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 278, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 279, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 279, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 279, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 279, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 281, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 281, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 281, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 281, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 281, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 281, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 282, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 282, .offset = {0, -17}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 282, .offset = {0, -11}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 282, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 284, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 284, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 284, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 284, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 284, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 284, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 285, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 285, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 285, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 285, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_11_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 287, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 287, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 287, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 287, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 287, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 287, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 288, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 288, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 288, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 288, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 290, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 290, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 290, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 297, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 297, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 297, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 296, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 296, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 296, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 295, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 295, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 295, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 294, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 294, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 294, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 293, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 293, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 293, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 292, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 292, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 292, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_12_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 291, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 291, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 291, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sDeoxysAttackAnims_13_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 300, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 301, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 302, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 303, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 304, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 305, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 298, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 299, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};

static const u8 sDeoxysAttackGfx1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_1.4bpp");
static const ax_sprite sDeoxysAttackSprites1[] = {
	{sDeoxysAttackGfx1, ARRAY_COUNT(sDeoxysAttackGfx1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx2[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_2.4bpp");
static const ax_sprite sDeoxysAttackSprites2[] = {
	{sDeoxysAttackGfx2, ARRAY_COUNT(sDeoxysAttackGfx2)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx3[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_3.4bpp");
static const ax_sprite sDeoxysAttackSprites3[] = {
	{sDeoxysAttackGfx3, ARRAY_COUNT(sDeoxysAttackGfx3)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx4[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_4.4bpp");
static const ax_sprite sDeoxysAttackSprites4[] = {
	{sDeoxysAttackGfx4, ARRAY_COUNT(sDeoxysAttackGfx4)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx5[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_5.4bpp");
static const ax_sprite sDeoxysAttackSprites5[] = {
	{sDeoxysAttackGfx5, ARRAY_COUNT(sDeoxysAttackGfx5)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx6[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_6.4bpp");
static const ax_sprite sDeoxysAttackSprites6[] = {
	{sDeoxysAttackGfx6, ARRAY_COUNT(sDeoxysAttackGfx6)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx7[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_7.4bpp");
static const ax_sprite sDeoxysAttackSprites7[] = {
	{sDeoxysAttackGfx7, ARRAY_COUNT(sDeoxysAttackGfx7)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx8[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_8.4bpp");
static const ax_sprite sDeoxysAttackSprites8[] = {
	{sDeoxysAttackGfx8, ARRAY_COUNT(sDeoxysAttackGfx8)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx9[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_9.4bpp");
static const ax_sprite sDeoxysAttackSprites9[] = {
	{sDeoxysAttackGfx9, ARRAY_COUNT(sDeoxysAttackGfx9)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx10[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_10.4bpp");
static const ax_sprite sDeoxysAttackSprites10[] = {
	{sDeoxysAttackGfx10, ARRAY_COUNT(sDeoxysAttackGfx10)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx11[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_11.4bpp");
static const ax_sprite sDeoxysAttackSprites11[] = {
	{sDeoxysAttackGfx11, ARRAY_COUNT(sDeoxysAttackGfx11)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx12[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_12.4bpp");
static const ax_sprite sDeoxysAttackSprites12[] = {
	{sDeoxysAttackGfx12, ARRAY_COUNT(sDeoxysAttackGfx12)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx13[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_13.4bpp");
static const ax_sprite sDeoxysAttackSprites13[] = {
	{sDeoxysAttackGfx13, ARRAY_COUNT(sDeoxysAttackGfx13)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx14[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_14.4bpp");
static const ax_sprite sDeoxysAttackSprites14[] = {
	{sDeoxysAttackGfx14, ARRAY_COUNT(sDeoxysAttackGfx14)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx15[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_15.4bpp");
static const ax_sprite sDeoxysAttackSprites15[] = {
	{sDeoxysAttackGfx15, ARRAY_COUNT(sDeoxysAttackGfx15)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx16[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_16.4bpp");
static const ax_sprite sDeoxysAttackSprites16[] = {
	{sDeoxysAttackGfx16, ARRAY_COUNT(sDeoxysAttackGfx16)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx17[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_17.4bpp");
static const ax_sprite sDeoxysAttackSprites17[] = {
	{sDeoxysAttackGfx17, ARRAY_COUNT(sDeoxysAttackGfx17)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx18[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_18.4bpp");
static const ax_sprite sDeoxysAttackSprites18[] = {
	{sDeoxysAttackGfx18, ARRAY_COUNT(sDeoxysAttackGfx18)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx19[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_19.4bpp");
static const ax_sprite sDeoxysAttackSprites19[] = {
	{sDeoxysAttackGfx19, ARRAY_COUNT(sDeoxysAttackGfx19)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx20[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_20.4bpp");
static const ax_sprite sDeoxysAttackSprites20[] = {
	{sDeoxysAttackGfx20, ARRAY_COUNT(sDeoxysAttackGfx20)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx21[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_21.4bpp");
static const ax_sprite sDeoxysAttackSprites21[] = {
	{sDeoxysAttackGfx21, ARRAY_COUNT(sDeoxysAttackGfx21)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx22[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_22.4bpp");
static const ax_sprite sDeoxysAttackSprites22[] = {
	{sDeoxysAttackGfx22, ARRAY_COUNT(sDeoxysAttackGfx22)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx23[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_23.4bpp");
static const ax_sprite sDeoxysAttackSprites23[] = {
	{sDeoxysAttackGfx23, ARRAY_COUNT(sDeoxysAttackGfx23)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx24[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_24.4bpp");
static const ax_sprite sDeoxysAttackSprites24[] = {
	{sDeoxysAttackGfx24, ARRAY_COUNT(sDeoxysAttackGfx24)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx25[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_25.4bpp");
static const ax_sprite sDeoxysAttackSprites25[] = {
	{sDeoxysAttackGfx25, ARRAY_COUNT(sDeoxysAttackGfx25)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx26[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_26.4bpp");
static const ax_sprite sDeoxysAttackSprites26[] = {
	{sDeoxysAttackGfx26, ARRAY_COUNT(sDeoxysAttackGfx26)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx27[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_27.4bpp");
static const ax_sprite sDeoxysAttackSprites27[] = {
	{sDeoxysAttackGfx27, ARRAY_COUNT(sDeoxysAttackGfx27)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx28[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_28.4bpp");
static const ax_sprite sDeoxysAttackSprites28[] = {
	{sDeoxysAttackGfx28, ARRAY_COUNT(sDeoxysAttackGfx28)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx29[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_29.4bpp");
static const u8 sDeoxysAttackGfx29_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_29_1.4bpp");
static const ax_sprite sDeoxysAttackSprites29[] = {
	{sDeoxysAttackGfx29, ARRAY_COUNT(sDeoxysAttackGfx29)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx29_1, ARRAY_COUNT(sDeoxysAttackGfx29_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx30[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_30.4bpp");
static const u8 sDeoxysAttackGfx30_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_30_1.4bpp");
static const ax_sprite sDeoxysAttackSprites30[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx30, ARRAY_COUNT(sDeoxysAttackGfx30)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx30_1, ARRAY_COUNT(sDeoxysAttackGfx30_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx31[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_31.4bpp");
static const u8 sDeoxysAttackGfx31_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_31_1.4bpp");
static const u8 sDeoxysAttackGfx31_2[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_31_2.4bpp");
static const u8 sDeoxysAttackGfx31_3[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_31_3.4bpp");
static const ax_sprite sDeoxysAttackSprites31[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx31, ARRAY_COUNT(sDeoxysAttackGfx31)}, 
	{NULL, 64}, 
	{sDeoxysAttackGfx31_1, ARRAY_COUNT(sDeoxysAttackGfx31_1)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx31_2, ARRAY_COUNT(sDeoxysAttackGfx31_2)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx31_3, ARRAY_COUNT(sDeoxysAttackGfx31_3)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx32[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_32.4bpp");
static const u8 sDeoxysAttackGfx32_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_32_1.4bpp");
static const u8 sDeoxysAttackGfx32_2[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_32_2.4bpp");
static const u8 sDeoxysAttackGfx32_3[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_32_3.4bpp");
static const ax_sprite sDeoxysAttackSprites32[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx32, ARRAY_COUNT(sDeoxysAttackGfx32)}, 
	{NULL, 64}, 
	{sDeoxysAttackGfx32_1, ARRAY_COUNT(sDeoxysAttackGfx32_1)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx32_2, ARRAY_COUNT(sDeoxysAttackGfx32_2)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx32_3, ARRAY_COUNT(sDeoxysAttackGfx32_3)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx33[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_33.4bpp");
static const ax_sprite sDeoxysAttackSprites33[] = {
	{sDeoxysAttackGfx33, ARRAY_COUNT(sDeoxysAttackGfx33)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx34[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_34.4bpp");
static const u8 sDeoxysAttackGfx34_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_34_1.4bpp");
static const ax_sprite sDeoxysAttackSprites34[] = {
	{sDeoxysAttackGfx34, ARRAY_COUNT(sDeoxysAttackGfx34)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx34_1, ARRAY_COUNT(sDeoxysAttackGfx34_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx35[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_35.4bpp");
static const u8 sDeoxysAttackGfx35_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_35_1.4bpp");
static const ax_sprite sDeoxysAttackSprites35[] = {
	{sDeoxysAttackGfx35, ARRAY_COUNT(sDeoxysAttackGfx35)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx35_1, ARRAY_COUNT(sDeoxysAttackGfx35_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx36[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_36.4bpp");
static const ax_sprite sDeoxysAttackSprites36[] = {
	{sDeoxysAttackGfx36, ARRAY_COUNT(sDeoxysAttackGfx36)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx37[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_37.4bpp");
static const u8 sDeoxysAttackGfx37_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_37_1.4bpp");
static const u8 sDeoxysAttackGfx37_2[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_37_2.4bpp");
static const ax_sprite sDeoxysAttackSprites37[] = {
	{sDeoxysAttackGfx37, ARRAY_COUNT(sDeoxysAttackGfx37)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx37_1, ARRAY_COUNT(sDeoxysAttackGfx37_1)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx37_2, ARRAY_COUNT(sDeoxysAttackGfx37_2)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx38[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_38.4bpp");
static const ax_sprite sDeoxysAttackSprites38[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx38, ARRAY_COUNT(sDeoxysAttackGfx38)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx39[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_39.4bpp");
static const ax_sprite sDeoxysAttackSprites39[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx39, ARRAY_COUNT(sDeoxysAttackGfx39)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx40[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_40.4bpp");
static const u8 sDeoxysAttackGfx40_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_40_1.4bpp");
static const ax_sprite sDeoxysAttackSprites40[] = {
	{sDeoxysAttackGfx40, ARRAY_COUNT(sDeoxysAttackGfx40)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx40_1, ARRAY_COUNT(sDeoxysAttackGfx40_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx41[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_41.4bpp");
static const ax_sprite sDeoxysAttackSprites41[] = {
	{sDeoxysAttackGfx41, ARRAY_COUNT(sDeoxysAttackGfx41)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx42[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_42.4bpp");
static const ax_sprite sDeoxysAttackSprites42[] = {
	{sDeoxysAttackGfx42, ARRAY_COUNT(sDeoxysAttackGfx42)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx43[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_43.4bpp");
static const ax_sprite sDeoxysAttackSprites43[] = {
	{sDeoxysAttackGfx43, ARRAY_COUNT(sDeoxysAttackGfx43)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx44[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_44.4bpp");
static const u8 sDeoxysAttackGfx44_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_44_1.4bpp");
static const ax_sprite sDeoxysAttackSprites44[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx44, ARRAY_COUNT(sDeoxysAttackGfx44)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx44_1, ARRAY_COUNT(sDeoxysAttackGfx44_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx45[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_45.4bpp");
static const ax_sprite sDeoxysAttackSprites45[] = {
	{sDeoxysAttackGfx45, ARRAY_COUNT(sDeoxysAttackGfx45)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx46[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_46.4bpp");
static const ax_sprite sDeoxysAttackSprites46[] = {
	{sDeoxysAttackGfx46, ARRAY_COUNT(sDeoxysAttackGfx46)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx47[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_47.4bpp");
static const ax_sprite sDeoxysAttackSprites47[] = {
	{sDeoxysAttackGfx47, ARRAY_COUNT(sDeoxysAttackGfx47)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx48[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_48.4bpp");
static const ax_sprite sDeoxysAttackSprites48[] = {
	{sDeoxysAttackGfx48, ARRAY_COUNT(sDeoxysAttackGfx48)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx49[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_49.4bpp");
static const u8 sDeoxysAttackGfx49_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_49_1.4bpp");
static const u8 sDeoxysAttackGfx49_2[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_49_2.4bpp");
static const u8 sDeoxysAttackGfx49_3[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_49_3.4bpp");
static const ax_sprite sDeoxysAttackSprites49[] = {
	{NULL, 64}, 
	{sDeoxysAttackGfx49, ARRAY_COUNT(sDeoxysAttackGfx49)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx49_1, ARRAY_COUNT(sDeoxysAttackGfx49_1)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx49_2, ARRAY_COUNT(sDeoxysAttackGfx49_2)}, 
	{NULL, 64}, 
	{sDeoxysAttackGfx49_3, ARRAY_COUNT(sDeoxysAttackGfx49_3)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx50[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_50.4bpp");
static const ax_sprite sDeoxysAttackSprites50[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx50, ARRAY_COUNT(sDeoxysAttackGfx50)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx51[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_51.4bpp");
static const ax_sprite sDeoxysAttackSprites51[] = {
	{sDeoxysAttackGfx51, ARRAY_COUNT(sDeoxysAttackGfx51)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx52[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_52.4bpp");
static const ax_sprite sDeoxysAttackSprites52[] = {
	{sDeoxysAttackGfx52, ARRAY_COUNT(sDeoxysAttackGfx52)}, 
	{NULL, 32}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx53[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_53.4bpp");
static const ax_sprite sDeoxysAttackSprites53[] = {
	{sDeoxysAttackGfx53, ARRAY_COUNT(sDeoxysAttackGfx53)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx54[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_54.4bpp");
static const ax_sprite sDeoxysAttackSprites54[] = {
	{sDeoxysAttackGfx54, ARRAY_COUNT(sDeoxysAttackGfx54)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx55[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_55.4bpp");
static const ax_sprite sDeoxysAttackSprites55[] = {
	{sDeoxysAttackGfx55, ARRAY_COUNT(sDeoxysAttackGfx55)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx56[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_56.4bpp");
static const ax_sprite sDeoxysAttackSprites56[] = {
	{sDeoxysAttackGfx56, ARRAY_COUNT(sDeoxysAttackGfx56)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx57[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_57.4bpp");
static const ax_sprite sDeoxysAttackSprites57[] = {
	{sDeoxysAttackGfx57, ARRAY_COUNT(sDeoxysAttackGfx57)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx58[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_58.4bpp");
static const ax_sprite sDeoxysAttackSprites58[] = {
	{sDeoxysAttackGfx58, ARRAY_COUNT(sDeoxysAttackGfx58)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx59[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_59.4bpp");
static const u8 sDeoxysAttackGfx59_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_59_1.4bpp");
static const u8 sDeoxysAttackGfx59_2[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_59_2.4bpp");
static const ax_sprite sDeoxysAttackSprites59[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx59, ARRAY_COUNT(sDeoxysAttackGfx59)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx59_1, ARRAY_COUNT(sDeoxysAttackGfx59_1)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx59_2, ARRAY_COUNT(sDeoxysAttackGfx59_2)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx60[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_60.4bpp");
static const ax_sprite sDeoxysAttackSprites60[] = {
	{sDeoxysAttackGfx60, ARRAY_COUNT(sDeoxysAttackGfx60)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx61[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_61.4bpp");
static const ax_sprite sDeoxysAttackSprites61[] = {
	{sDeoxysAttackGfx61, ARRAY_COUNT(sDeoxysAttackGfx61)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx62[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_62.4bpp");
static const ax_sprite sDeoxysAttackSprites62[] = {
	{sDeoxysAttackGfx62, ARRAY_COUNT(sDeoxysAttackGfx62)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx63[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_63.4bpp");
static const u8 sDeoxysAttackGfx63_1[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_63_1.4bpp");
static const ax_sprite sDeoxysAttackSprites63[] = {
	{sDeoxysAttackGfx63, ARRAY_COUNT(sDeoxysAttackGfx63)}, 
	{NULL, 32}, 
	{sDeoxysAttackGfx63_1, ARRAY_COUNT(sDeoxysAttackGfx63_1)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx64[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_64.4bpp");
static const ax_sprite sDeoxysAttackSprites64[] = {
	{sDeoxysAttackGfx64, ARRAY_COUNT(sDeoxysAttackGfx64)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx65[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_65.4bpp");
static const ax_sprite sDeoxysAttackSprites65[] = {
	{sDeoxysAttackGfx65, ARRAY_COUNT(sDeoxysAttackGfx65)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx66[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_66.4bpp");
static const ax_sprite sDeoxysAttackSprites66[] = {
	{sDeoxysAttackGfx66, ARRAY_COUNT(sDeoxysAttackGfx66)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx67[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_67.4bpp");
static const ax_sprite sDeoxysAttackSprites67[] = {
	{sDeoxysAttackGfx67, ARRAY_COUNT(sDeoxysAttackGfx67)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx68[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_68.4bpp");
static const ax_sprite sDeoxysAttackSprites68[] = {
	{sDeoxysAttackGfx68, ARRAY_COUNT(sDeoxysAttackGfx68)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx69[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_69.4bpp");
static const ax_sprite sDeoxysAttackSprites69[] = {
	{sDeoxysAttackGfx69, ARRAY_COUNT(sDeoxysAttackGfx69)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx70[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_70.4bpp");
static const ax_sprite sDeoxysAttackSprites70[] = {
	{sDeoxysAttackGfx70, ARRAY_COUNT(sDeoxysAttackGfx70)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx71[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_71.4bpp");
static const ax_sprite sDeoxysAttackSprites71[] = {
	{sDeoxysAttackGfx71, ARRAY_COUNT(sDeoxysAttackGfx71)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx72[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_72.4bpp");
static const ax_sprite sDeoxysAttackSprites72[] = {
	{sDeoxysAttackGfx72, ARRAY_COUNT(sDeoxysAttackGfx72)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx73[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_73.4bpp");
static const ax_sprite sDeoxysAttackSprites73[] = {
	{sDeoxysAttackGfx73, ARRAY_COUNT(sDeoxysAttackGfx73)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx74[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_74.4bpp");
static const ax_sprite sDeoxysAttackSprites74[] = {
	{sDeoxysAttackGfx74, ARRAY_COUNT(sDeoxysAttackGfx74)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx75[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_75.4bpp");
static const ax_sprite sDeoxysAttackSprites75[] = {
	{sDeoxysAttackGfx75, ARRAY_COUNT(sDeoxysAttackGfx75)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx76[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_76.4bpp");
static const ax_sprite sDeoxysAttackSprites76[] = {
	{sDeoxysAttackGfx76, ARRAY_COUNT(sDeoxysAttackGfx76)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx77[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_77.4bpp");
static const ax_sprite sDeoxysAttackSprites77[] = {
	{sDeoxysAttackGfx77, ARRAY_COUNT(sDeoxysAttackGfx77)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx78[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_78.4bpp");
static const ax_sprite sDeoxysAttackSprites78[] = {
	{sDeoxysAttackGfx78, ARRAY_COUNT(sDeoxysAttackGfx78)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx79[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_79.4bpp");
static const ax_sprite sDeoxysAttackSprites79[] = {
	{sDeoxysAttackGfx79, ARRAY_COUNT(sDeoxysAttackGfx79)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx80[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_80.4bpp");
static const ax_sprite sDeoxysAttackSprites80[] = {
	{sDeoxysAttackGfx80, ARRAY_COUNT(sDeoxysAttackGfx80)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx81[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_81.4bpp");
static const ax_sprite sDeoxysAttackSprites81[] = {
	{sDeoxysAttackGfx81, ARRAY_COUNT(sDeoxysAttackGfx81)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx82[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_82.4bpp");
static const ax_sprite sDeoxysAttackSprites82[] = {
	{sDeoxysAttackGfx82, ARRAY_COUNT(sDeoxysAttackGfx82)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx83[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_83.4bpp");
static const ax_sprite sDeoxysAttackSprites83[] = {
	{sDeoxysAttackGfx83, ARRAY_COUNT(sDeoxysAttackGfx83)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx84[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_84.4bpp");
static const ax_sprite sDeoxysAttackSprites84[] = {
	{sDeoxysAttackGfx84, ARRAY_COUNT(sDeoxysAttackGfx84)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx85[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_85.4bpp");
static const ax_sprite sDeoxysAttackSprites85[] = {
	{sDeoxysAttackGfx85, ARRAY_COUNT(sDeoxysAttackGfx85)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx86[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_86.4bpp");
static const ax_sprite sDeoxysAttackSprites86[] = {
	{sDeoxysAttackGfx86, ARRAY_COUNT(sDeoxysAttackGfx86)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx87[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_87.4bpp");
static const ax_sprite sDeoxysAttackSprites87[] = {
	{sDeoxysAttackGfx87, ARRAY_COUNT(sDeoxysAttackGfx87)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx88[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_88.4bpp");
static const ax_sprite sDeoxysAttackSprites88[] = {
	{NULL, 32}, 
	{sDeoxysAttackGfx88, ARRAY_COUNT(sDeoxysAttackGfx88)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx89[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_89.4bpp");
static const ax_sprite sDeoxysAttackSprites89[] = {
	{sDeoxysAttackGfx89, ARRAY_COUNT(sDeoxysAttackGfx89)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx90[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_90.4bpp");
static const ax_sprite sDeoxysAttackSprites90[] = {
	{sDeoxysAttackGfx90, ARRAY_COUNT(sDeoxysAttackGfx90)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx91[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_91.4bpp");
static const ax_sprite sDeoxysAttackSprites91[] = {
	{sDeoxysAttackGfx91, ARRAY_COUNT(sDeoxysAttackGfx91)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx92[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_92.4bpp");
static const ax_sprite sDeoxysAttackSprites92[] = {
	{sDeoxysAttackGfx92, ARRAY_COUNT(sDeoxysAttackGfx92)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx93[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_93.4bpp");
static const ax_sprite sDeoxysAttackSprites93[] = {
	{sDeoxysAttackGfx93, ARRAY_COUNT(sDeoxysAttackGfx93)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx94[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_94.4bpp");
static const ax_sprite sDeoxysAttackSprites94[] = {
	{sDeoxysAttackGfx94, ARRAY_COUNT(sDeoxysAttackGfx94)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx95[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_95.4bpp");
static const ax_sprite sDeoxysAttackSprites95[] = {
	{sDeoxysAttackGfx95, ARRAY_COUNT(sDeoxysAttackGfx95)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx96[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_96.4bpp");
static const ax_sprite sDeoxysAttackSprites96[] = {
	{sDeoxysAttackGfx96, ARRAY_COUNT(sDeoxysAttackGfx96)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx97[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_97.4bpp");
static const ax_sprite sDeoxysAttackSprites97[] = {
	{sDeoxysAttackGfx97, ARRAY_COUNT(sDeoxysAttackGfx97)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx98[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_98.4bpp");
static const ax_sprite sDeoxysAttackSprites98[] = {
	{sDeoxysAttackGfx98, ARRAY_COUNT(sDeoxysAttackGfx98)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx99[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_99.4bpp");
static const ax_sprite sDeoxysAttackSprites99[] = {
	{sDeoxysAttackGfx99, ARRAY_COUNT(sDeoxysAttackGfx99)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx100[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_100.4bpp");
static const ax_sprite sDeoxysAttackSprites100[] = {
	{sDeoxysAttackGfx100, ARRAY_COUNT(sDeoxysAttackGfx100)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx101[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_101.4bpp");
static const ax_sprite sDeoxysAttackSprites101[] = {
	{sDeoxysAttackGfx101, ARRAY_COUNT(sDeoxysAttackGfx101)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx102[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_102.4bpp");
static const ax_sprite sDeoxysAttackSprites102[] = {
	{sDeoxysAttackGfx102, ARRAY_COUNT(sDeoxysAttackGfx102)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx103[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_103.4bpp");
static const ax_sprite sDeoxysAttackSprites103[] = {
	{sDeoxysAttackGfx103, ARRAY_COUNT(sDeoxysAttackGfx103)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx104[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_104.4bpp");
static const ax_sprite sDeoxysAttackSprites104[] = {
	{sDeoxysAttackGfx104, ARRAY_COUNT(sDeoxysAttackGfx104)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx105[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_105.4bpp");
static const ax_sprite sDeoxysAttackSprites105[] = {
	{sDeoxysAttackGfx105, ARRAY_COUNT(sDeoxysAttackGfx105)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx106[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_106.4bpp");
static const ax_sprite sDeoxysAttackSprites106[] = {
	{sDeoxysAttackGfx106, ARRAY_COUNT(sDeoxysAttackGfx106)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx107[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_107.4bpp");
static const ax_sprite sDeoxysAttackSprites107[] = {
	{sDeoxysAttackGfx107, ARRAY_COUNT(sDeoxysAttackGfx107)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx108[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_108.4bpp");
static const ax_sprite sDeoxysAttackSprites108[] = {
	{sDeoxysAttackGfx108, ARRAY_COUNT(sDeoxysAttackGfx108)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx109[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_109.4bpp");
static const ax_sprite sDeoxysAttackSprites109[] = {
	{sDeoxysAttackGfx109, ARRAY_COUNT(sDeoxysAttackGfx109)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx110[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_110.4bpp");
static const ax_sprite sDeoxysAttackSprites110[] = {
	{sDeoxysAttackGfx110, ARRAY_COUNT(sDeoxysAttackGfx110)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx111[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_111.4bpp");
static const ax_sprite sDeoxysAttackSprites111[] = {
	{sDeoxysAttackGfx111, ARRAY_COUNT(sDeoxysAttackGfx111)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx112[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_112.4bpp");
static const ax_sprite sDeoxysAttackSprites112[] = {
	{sDeoxysAttackGfx112, ARRAY_COUNT(sDeoxysAttackGfx112)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx113[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_113.4bpp");
static const ax_sprite sDeoxysAttackSprites113[] = {
	{sDeoxysAttackGfx113, ARRAY_COUNT(sDeoxysAttackGfx113)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx114[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_114.4bpp");
static const ax_sprite sDeoxysAttackSprites114[] = {
	{sDeoxysAttackGfx114, ARRAY_COUNT(sDeoxysAttackGfx114)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx115[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_115.4bpp");
static const ax_sprite sDeoxysAttackSprites115[] = {
	{sDeoxysAttackGfx115, ARRAY_COUNT(sDeoxysAttackGfx115)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx116[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_116.4bpp");
static const ax_sprite sDeoxysAttackSprites116[] = {
	{sDeoxysAttackGfx116, ARRAY_COUNT(sDeoxysAttackGfx116)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx117[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_117.4bpp");
static const ax_sprite sDeoxysAttackSprites117[] = {
	{sDeoxysAttackGfx117, ARRAY_COUNT(sDeoxysAttackGfx117)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx118[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_118.4bpp");
static const ax_sprite sDeoxysAttackSprites118[] = {
	{sDeoxysAttackGfx118, ARRAY_COUNT(sDeoxysAttackGfx118)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx119[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_119.4bpp");
static const ax_sprite sDeoxysAttackSprites119[] = {
	{sDeoxysAttackGfx119, ARRAY_COUNT(sDeoxysAttackGfx119)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx120[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_120.4bpp");
static const ax_sprite sDeoxysAttackSprites120[] = {
	{sDeoxysAttackGfx120, ARRAY_COUNT(sDeoxysAttackGfx120)}, 
	{NULL, 0}
};
static const u8 sDeoxysAttackGfx121[] = INCBIN_U8("graphics/ax/mon/deoxysattack/sprite_121.4bpp");
static const ax_sprite sDeoxysAttackSprites121[] = {
	{sDeoxysAttackGfx121, ARRAY_COUNT(sDeoxysAttackGfx121)}, 
	{NULL, 0}
};

static const ax_pose *const sAxPosesDeoxysAttack[] = {
	sDeoxysAttackPose1,
	sDeoxysAttackPose2,
	sDeoxysAttackPose3,
	sDeoxysAttackPose4,
	sDeoxysAttackPose5,
	sDeoxysAttackPose6,
	sDeoxysAttackPose7,
	sDeoxysAttackPose8,
	sDeoxysAttackPose9,
	sDeoxysAttackPose10,
	sDeoxysAttackPose11,
	sDeoxysAttackPose12,
	sDeoxysAttackPose13,
	sDeoxysAttackPose14,
	sDeoxysAttackPose15,
	sDeoxysAttackPose16,
	sDeoxysAttackPose17,
	sDeoxysAttackPose18,
	sDeoxysAttackPose19,
	sDeoxysAttackPose20,
	sDeoxysAttackPose21,
	sDeoxysAttackPose22,
	sDeoxysAttackPose23,
	sDeoxysAttackPose24,
	sDeoxysAttackPose25,
	sDeoxysAttackPose26,
	sDeoxysAttackPose27,
	sDeoxysAttackPose28,
	sDeoxysAttackPose29,
	sDeoxysAttackPose30,
	sDeoxysAttackPose31,
	sDeoxysAttackPose32,
	sDeoxysAttackPose33,
	sDeoxysAttackPose34,
	sDeoxysAttackPose35,
	sDeoxysAttackPose36,
	sDeoxysAttackPose37,
	sDeoxysAttackPose38,
	sDeoxysAttackPose39,
	sDeoxysAttackPose40,
	sDeoxysAttackPose41,
	sDeoxysAttackPose42,
	sDeoxysAttackPose43,
	sDeoxysAttackPose44,
	sDeoxysAttackPose45,
	sDeoxysAttackPose46,
	sDeoxysAttackPose47,
	sDeoxysAttackPose48,
	sDeoxysAttackPose49,
	sDeoxysAttackPose50,
	sDeoxysAttackPose51,
	sDeoxysAttackPose52,
	sDeoxysAttackPose53,
	sDeoxysAttackPose54,
	sDeoxysAttackPose55,
	sDeoxysAttackPose56,
	sDeoxysAttackPose57,
	sDeoxysAttackPose58,
	sDeoxysAttackPose59,
	sDeoxysAttackPose60,
	sDeoxysAttackPose61,
	sDeoxysAttackPose62,
	sDeoxysAttackPose63,
	sDeoxysAttackPose64,
	sDeoxysAttackPose65,
	sDeoxysAttackPose66,
	sDeoxysAttackPose67,
	sDeoxysAttackPose68,
	sDeoxysAttackPose69,
	sDeoxysAttackPose70,
	sDeoxysAttackPose71,
	sDeoxysAttackPose72,
	sDeoxysAttackPose73,
	sDeoxysAttackPose74,
	sDeoxysAttackPose75,
	sDeoxysAttackPose76,
	sDeoxysAttackPose77,
	sDeoxysAttackPose78,
	sDeoxysAttackPose79,
	sDeoxysAttackPose80,
	sDeoxysAttackPose81,
	sDeoxysAttackPose82,
	sDeoxysAttackPose83,
	sDeoxysAttackPose84,
	sDeoxysAttackPose85,
	sDeoxysAttackPose86,
	sDeoxysAttackPose87,
	sDeoxysAttackPose88,
	sDeoxysAttackPose89,
	sDeoxysAttackPose90,
	sDeoxysAttackPose91,
	sDeoxysAttackPose92,
	sDeoxysAttackPose93,
	sDeoxysAttackPose94,
	sDeoxysAttackPose95,
	sDeoxysAttackPose96,
	sDeoxysAttackPose97,
	sDeoxysAttackPose98,
	sDeoxysAttackPose99,
	sDeoxysAttackPose100,
	sDeoxysAttackPose101,
	sDeoxysAttackPose102,
	sDeoxysAttackPose103,
	sDeoxysAttackPose104,
	sDeoxysAttackPose105,
	sDeoxysAttackPose106,
	sDeoxysAttackPose107,
	sDeoxysAttackPose108,
	sDeoxysAttackPose109,
	sDeoxysAttackPose110,
	sDeoxysAttackPose111,
	sDeoxysAttackPose112,
	sDeoxysAttackPose113,
	sDeoxysAttackPose114,
	sDeoxysAttackPose115,
	sDeoxysAttackPose116,
	sDeoxysAttackPose117,
	sDeoxysAttackPose118,
	sDeoxysAttackPose119,
	sDeoxysAttackPose120,
	sDeoxysAttackPose121,
	sDeoxysAttackPose122,
	sDeoxysAttackPose123,
	sDeoxysAttackPose124,
	sDeoxysAttackPose125,
	sDeoxysAttackPose126,
	sDeoxysAttackPose127,
	sDeoxysAttackPose128,
	sDeoxysAttackPose129,
	sDeoxysAttackPose130,
	sDeoxysAttackPose131,
	sDeoxysAttackPose132,
	sDeoxysAttackPose133,
	sDeoxysAttackPose134,
	sDeoxysAttackPose135,
	sDeoxysAttackPose136,
	sDeoxysAttackPose137,
	sDeoxysAttackPose138,
	sDeoxysAttackPose139,
	sDeoxysAttackPose140,
	sDeoxysAttackPose141,
	sDeoxysAttackPose142,
	sDeoxysAttackPose143,
	sDeoxysAttackPose144,
	sDeoxysAttackPose145,
	sDeoxysAttackPose146,
	sDeoxysAttackPose147,
	sDeoxysAttackPose148,
	sDeoxysAttackPose149,
	sDeoxysAttackPose150,
	sDeoxysAttackPose151,
	sDeoxysAttackPose152,
	sDeoxysAttackPose153,
	sDeoxysAttackPose154,
	sDeoxysAttackPose155,
	sDeoxysAttackPose156,
	sDeoxysAttackPose157,
	sDeoxysAttackPose158,
	sDeoxysAttackPose159,
	sDeoxysAttackPose160,
	sDeoxysAttackPose161,
	sDeoxysAttackPose162,
	sDeoxysAttackPose163,
	sDeoxysAttackPose164,
	sDeoxysAttackPose165,
	sDeoxysAttackPose166,
	sDeoxysAttackPose167,
	sDeoxysAttackPose168,
	sDeoxysAttackPose169,
	sDeoxysAttackPose170,
	sDeoxysAttackPose171,
	sDeoxysAttackPose172,
	sDeoxysAttackPose173,
	sDeoxysAttackPose174,
	sDeoxysAttackPose175,
	sDeoxysAttackPose176,
	sDeoxysAttackPose177,
	sDeoxysAttackPose178,
	sDeoxysAttackPose179,
	sDeoxysAttackPose180,
	sDeoxysAttackPose181,
	sDeoxysAttackPose182,
	sDeoxysAttackPose183,
	sDeoxysAttackPose184,
	sDeoxysAttackPose185,
	sDeoxysAttackPose186,
	sDeoxysAttackPose187,
	sDeoxysAttackPose188,
	sDeoxysAttackPose189,
	sDeoxysAttackPose190,
	sDeoxysAttackPose191,
	sDeoxysAttackPose192,
	sDeoxysAttackPose193,
	sDeoxysAttackPose194,
	sDeoxysAttackPose195,
	sDeoxysAttackPose196,
	sDeoxysAttackPose197,
	sDeoxysAttackPose198,
	sDeoxysAttackPose199,
	sDeoxysAttackPose200,
	sDeoxysAttackPose201,
	sDeoxysAttackPose202,
	sDeoxysAttackPose203,
	sDeoxysAttackPose204,
	sDeoxysAttackPose205,
	sDeoxysAttackPose206,
	sDeoxysAttackPose207,
	sDeoxysAttackPose208,
	sDeoxysAttackPose209,
	sDeoxysAttackPose210,
	sDeoxysAttackPose211,
	sDeoxysAttackPose212,
	sDeoxysAttackPose213,
	sDeoxysAttackPose214,
	sDeoxysAttackPose215,
	sDeoxysAttackPose216,
	sDeoxysAttackPose217,
	sDeoxysAttackPose218,
	sDeoxysAttackPose219,
	sDeoxysAttackPose220,
	sDeoxysAttackPose221,
	sDeoxysAttackPose222,
	sDeoxysAttackPose223,
	sDeoxysAttackPose224,
	sDeoxysAttackPose225,
	sDeoxysAttackPose226,
	sDeoxysAttackPose227,
	sDeoxysAttackPose228,
	sDeoxysAttackPose229,
	sDeoxysAttackPose230,
	sDeoxysAttackPose231,
	sDeoxysAttackPose232,
	sDeoxysAttackPose233,
	sDeoxysAttackPose234,
	sDeoxysAttackPose235,
	sDeoxysAttackPose236,
	sDeoxysAttackPose237,
	sDeoxysAttackPose238,
	sDeoxysAttackPose239,
	sDeoxysAttackPose240,
	sDeoxysAttackPose241,
	sDeoxysAttackPose242,
	sDeoxysAttackPose243,
	sDeoxysAttackPose244,
	sDeoxysAttackPose245,
	sDeoxysAttackPose246,
	sDeoxysAttackPose247,
	sDeoxysAttackPose248,
	sDeoxysAttackPose249,
	sDeoxysAttackPose250,
	sDeoxysAttackPose251,
	sDeoxysAttackPose252,
	sDeoxysAttackPose253,
	sDeoxysAttackPose254,
	sDeoxysAttackPose255,
	sDeoxysAttackPose256,
	sDeoxysAttackPose257,
	sDeoxysAttackPose258,
	sDeoxysAttackPose259,
	sDeoxysAttackPose260,
	sDeoxysAttackPose261,
	sDeoxysAttackPose262,
	sDeoxysAttackPose263,
	sDeoxysAttackPose264,
	sDeoxysAttackPose265,
	sDeoxysAttackPose266,
	sDeoxysAttackPose267,
	sDeoxysAttackPose268,
	sDeoxysAttackPose269,
	sDeoxysAttackPose270,
	sDeoxysAttackPose271,
	sDeoxysAttackPose272,
	sDeoxysAttackPose273,
	sDeoxysAttackPose274,
	sDeoxysAttackPose275,
	sDeoxysAttackPose276,
	sDeoxysAttackPose277,
	sDeoxysAttackPose278,
	sDeoxysAttackPose279,
	sDeoxysAttackPose280,
	sDeoxysAttackPose281,
	sDeoxysAttackPose282,
	sDeoxysAttackPose283,
	sDeoxysAttackPose284,
	sDeoxysAttackPose285,
	sDeoxysAttackPose286,
	sDeoxysAttackPose287,
	sDeoxysAttackPose288,
	sDeoxysAttackPose289,
	sDeoxysAttackPose290,
	sDeoxysAttackPose291,
	sDeoxysAttackPose292,
	sDeoxysAttackPose293,
	sDeoxysAttackPose294,
	sDeoxysAttackPose295,
	sDeoxysAttackPose296,
	sDeoxysAttackPose297,
	sDeoxysAttackPose298,
	sDeoxysAttackPose299,
	sDeoxysAttackPose300,
	sDeoxysAttackPose301,
	sDeoxysAttackPose302,
	sDeoxysAttackPose303,
	sDeoxysAttackPose304,
	sDeoxysAttackPose305,
	sDeoxysAttackPose306,
};

static const struct PositionSets sAxPositionsDeoxysAttack[] = {
	[0] = { .set = { {0, -14}, {-11, -2}, {12, -8}, {-1, -13} } },
	[1] = { .set = { {-1, -13}, {-10, -2}, {11, -5}, {-1, -12} } },
	[2] = { .set = { {-2, -14}, {9, -2}, {-14, -8}, {-1, -13} } },
	[3] = { .set = { {-1, -13}, {8, -2}, {-13, -5}, {-1, -12} } },
	[4] = { .set = { {-1, -16}, {8, -7}, {-12, -6}, {-1, -15} } },
	[5] = { .set = { {1, -15}, {8, -7}, {-10, -5}, {0, -14} } },
	[6] = { .set = { {2, -16}, {11, -10}, {-10, -3}, {1, -15} } },
	[7] = { .set = { {1, -15}, {9, -8}, {-9, -2}, {-1, -15} } },
	[8] = { .set = { {0, -16}, {-9, -12}, {-8, -6}, {-3, -15} } },
	[9] = { .set = { {0, -15}, {-9, -12}, {-7, -4}, {-3, -14} } },
	[10] = { .set = { {0, -16}, {-7, -5}, {-8, -3}, {-3, -15} } },
	[11] = { .set = { {0, -15}, {-7, -4}, {-8, -2}, {-3, -15} } },
	[12] = { .set = { {0, -17}, {-10, -7}, {1, -4}, {-2, -16} } },
	[13] = { .set = { {0, -16}, {-10, -6}, {2, -1}, {-2, -15} } },
	[14] = { .set = { {0, -17}, {-11, -9}, {3, -1}, {-2, -16} } },
	[15] = { .set = { {0, -16}, {-10, -7}, {2, 0}, {-2, -15} } },
	[16] = { .set = { {0, -17}, {12, -3}, {-13, -6}, {0, -14} } },
	[17] = { .set = { {0, -16}, {11, -3}, {-11, -5}, {0, -13} } },
	[18] = { .set = { {0, -17}, {-12, -3}, {13, -6}, {0, -14} } },
	[19] = { .set = { {0, -16}, {-11, -3}, {11, -5}, {0, -13} } },
	[20] = { .set = { {0, -17}, {10, -7}, {-1, -4}, {2, -16} } },
	[21] = { .set = { {0, -16}, {10, -6}, {-2, -1}, {2, -15} } },
	[22] = { .set = { {0, -17}, {11, -9}, {-3, -1}, {2, -16} } },
	[23] = { .set = { {0, -16}, {10, -7}, {-2, 0}, {2, -15} } },
	[24] = { .set = { {0, -16}, {9, -12}, {8, -6}, {3, -15} } },
	[25] = { .set = { {0, -15}, {9, -12}, {7, -4}, {3, -14} } },
	[26] = { .set = { {0, -16}, {7, -5}, {8, -3}, {3, -15} } },
	[27] = { .set = { {0, -15}, {7, -4}, {8, -2}, {3, -15} } },
	[28] = { .set = { {0, -16}, {-9, -7}, {11, -6}, {0, -15} } },
	[29] = { .set = { {-1, -15}, {-8, -7}, {10, -5}, {0, -14} } },
	[30] = { .set = { {-2, -16}, {-11, -10}, {10, -3}, {-1, -15} } },
	[31] = { .set = { {-1, -15}, {-9, -8}, {9, -2}, {1, -15} } },
	[32] = { .set = { {0, -14}, {-11, -2}, {12, -8}, {-1, -13} } },
	[33] = { .set = { {-1, -13}, {-10, -2}, {11, -5}, {-1, -12} } },
	[34] = { .set = { {-2, -14}, {9, -2}, {-14, -8}, {-1, -13} } },
	[35] = { .set = { {-1, -13}, {8, -2}, {-13, -5}, {-1, -12} } },
	[36] = { .set = { {-1, -13}, {-11, -6}, {9, -6}, {-1, -12} } },
	[37] = { .set = { {0, -16}, {9, -7}, {-11, -6}, {0, -15} } },
	[38] = { .set = { {1, -15}, {8, -7}, {-10, -5}, {0, -14} } },
	[39] = { .set = { {2, -16}, {11, -10}, {-10, -3}, {1, -15} } },
	[40] = { .set = { {1, -15}, {9, -8}, {-9, -2}, {-1, -15} } },
	[41] = { .set = { {1, -14}, {10, -8}, {-11, -2}, {0, -14} } },
	[42] = { .set = { {0, -16}, {-9, -12}, {-8, -6}, {-3, -15} } },
	[43] = { .set = { {0, -15}, {-9, -12}, {-7, -4}, {-3, -14} } },
	[44] = { .set = { {0, -16}, {-7, -5}, {-8, -3}, {-3, -15} } },
	[45] = { .set = { {0, -15}, {-7, -4}, {-8, -2}, {-3, -15} } },
	[46] = { .set = { {1, -15}, {-7, -3}, {-9, -1}, {-2, -15} } },
	[47] = { .set = { {0, -17}, {-10, -7}, {1, -4}, {-2, -16} } },
	[48] = { .set = { {0, -16}, {-10, -6}, {2, -1}, {-2, -15} } },
	[49] = { .set = { {0, -17}, {-11, -9}, {3, -1}, {-2, -16} } },
	[50] = { .set = { {0, -16}, {-10, -7}, {2, 0}, {-2, -15} } },
	[51] = { .set = { {-1, -15}, {-12, -8}, {1, 0}, {-3, -15} } },
	[52] = { .set = { {0, -17}, {12, -3}, {-13, -6}, {0, -14} } },
	[53] = { .set = { {0, -16}, {11, -3}, {-11, -5}, {0, -13} } },
	[54] = { .set = { {0, -17}, {-12, -3}, {13, -6}, {0, -14} } },
	[55] = { .set = { {0, -16}, {-11, -3}, {11, -5}, {0, -13} } },
	[56] = { .set = { {0, -17}, {10, -3}, {-10, -4}, {0, -14} } },
	[57] = { .set = { {0, -17}, {10, -7}, {-1, -4}, {2, -16} } },
	[58] = { .set = { {0, -16}, {10, -6}, {-2, -1}, {2, -15} } },
	[59] = { .set = { {0, -17}, {11, -9}, {-3, -1}, {2, -16} } },
	[60] = { .set = { {0, -16}, {10, -7}, {-2, 0}, {2, -15} } },
	[61] = { .set = { {1, -15}, {12, -8}, {-1, 0}, {3, -15} } },
	[62] = { .set = { {0, -16}, {9, -12}, {8, -6}, {3, -15} } },
	[63] = { .set = { {0, -15}, {9, -12}, {7, -4}, {3, -14} } },
	[64] = { .set = { {0, -16}, {7, -5}, {8, -3}, {3, -15} } },
	[65] = { .set = { {0, -15}, {7, -4}, {8, -2}, {3, -15} } },
	[66] = { .set = { {-1, -15}, {7, -3}, {9, -1}, {2, -15} } },
	[67] = { .set = { {0, -16}, {-9, -7}, {11, -6}, {0, -15} } },
	[68] = { .set = { {-1, -15}, {-8, -7}, {10, -5}, {0, -14} } },
	[69] = { .set = { {-2, -16}, {-11, -10}, {10, -3}, {-1, -15} } },
	[70] = { .set = { {-1, -15}, {-9, -8}, {9, -2}, {1, -15} } },
	[71] = { .set = { {-1, -14}, {-10, -8}, {11, -2}, {0, -14} } },
	[72] = { .set = { {0, -14}, {-11, -2}, {12, -8}, {-1, -13} } },
	[73] = { .set = { {-1, -13}, {-10, -2}, {11, -5}, {-1, -12} } },
	[74] = { .set = { {-2, -14}, {9, -2}, {-14, -8}, {-1, -13} } },
	[75] = { .set = { {-1, -13}, {8, -2}, {-13, -5}, {-1, -12} } },
	[76] = { .set = { {-1, -13}, {-11, -6}, {9, -6}, {-1, -12} } },
	[77] = { .set = { {0, -16}, {9, -7}, {-11, -6}, {0, -15} } },
	[78] = { .set = { {1, -15}, {8, -7}, {-10, -5}, {0, -14} } },
	[79] = { .set = { {2, -16}, {11, -10}, {-10, -3}, {1, -15} } },
	[80] = { .set = { {1, -15}, {9, -8}, {-9, -2}, {-1, -15} } },
	[81] = { .set = { {1, -14}, {10, -8}, {-11, -2}, {0, -14} } },
	[82] = { .set = { {0, -16}, {-9, -12}, {-8, -6}, {-3, -15} } },
	[83] = { .set = { {0, -15}, {-9, -12}, {-7, -4}, {-3, -14} } },
	[84] = { .set = { {0, -16}, {-7, -5}, {-8, -3}, {-3, -15} } },
	[85] = { .set = { {0, -15}, {-7, -4}, {-8, -2}, {-3, -15} } },
	[86] = { .set = { {1, -15}, {-7, -3}, {-9, -1}, {-2, -15} } },
	[87] = { .set = { {0, -17}, {-10, -7}, {1, -4}, {-2, -16} } },
	[88] = { .set = { {0, -16}, {-10, -6}, {2, -1}, {-2, -15} } },
	[89] = { .set = { {0, -17}, {-11, -9}, {3, -1}, {-2, -16} } },
	[90] = { .set = { {0, -16}, {-10, -7}, {2, 0}, {-2, -15} } },
	[91] = { .set = { {-1, -15}, {-12, -8}, {1, 0}, {-3, -15} } },
	[92] = { .set = { {0, -17}, {12, -3}, {-13, -6}, {0, -14} } },
	[93] = { .set = { {0, -16}, {11, -3}, {-11, -5}, {0, -13} } },
	[94] = { .set = { {0, -17}, {-12, -3}, {13, -6}, {0, -14} } },
	[95] = { .set = { {0, -16}, {-11, -3}, {11, -5}, {0, -13} } },
	[96] = { .set = { {0, -17}, {10, -3}, {-10, -4}, {0, -14} } },
	[97] = { .set = { {0, -17}, {10, -7}, {-1, -4}, {2, -16} } },
	[98] = { .set = { {0, -16}, {10, -6}, {-2, -1}, {2, -15} } },
	[99] = { .set = { {0, -17}, {11, -9}, {-3, -1}, {2, -16} } },
	[100] = { .set = { {0, -16}, {10, -7}, {-2, 0}, {2, -15} } },
	[101] = { .set = { {1, -15}, {12, -8}, {-1, 0}, {3, -15} } },
	[102] = { .set = { {0, -16}, {9, -12}, {8, -6}, {3, -15} } },
	[103] = { .set = { {0, -15}, {9, -12}, {7, -4}, {3, -14} } },
	[104] = { .set = { {0, -16}, {7, -5}, {8, -3}, {3, -15} } },
	[105] = { .set = { {0, -15}, {7, -4}, {8, -2}, {3, -15} } },
	[106] = { .set = { {-1, -15}, {7, -3}, {9, -1}, {2, -15} } },
	[107] = { .set = { {0, -16}, {-9, -7}, {11, -6}, {0, -15} } },
	[108] = { .set = { {-1, -15}, {-8, -7}, {10, -5}, {0, -14} } },
	[109] = { .set = { {-2, -16}, {-11, -10}, {10, -3}, {-1, -15} } },
	[110] = { .set = { {-1, -15}, {-9, -8}, {9, -2}, {1, -15} } },
	[111] = { .set = { {-1, -14}, {-10, -8}, {11, -2}, {0, -14} } },
	[112] = { .set = { {-1, -15}, {-12, -22}, {7, -16}, {-1, -13} } },
	[113] = { .set = { {-1, -13}, {-11, -6}, {9, -6}, {-1, -12} } },
	[114] = { .set = { {-1, -14}, {-8, -2}, {6, -2}, {-1, -13} } },
	[115] = { .set = { {-1, -18}, {-13, -8}, {11, -27}, {-1, -15} } },
	[116] = { .set = { {2, -16}, {11, -22}, {-3, -15}, {0, -14} } },
	[117] = { .set = { {1, -14}, {10, -8}, {-11, -2}, {0, -14} } },
	[118] = { .set = { {2, -14}, {17, -8}, {8, -3}, {1, -13} } },
	[119] = { .set = { {0, -20}, {13, -12}, {-13, -23}, {-1, -19} } },
	[120] = { .set = { {1, -16}, {7, -26}, {7, -14}, {-1, -14} } },
	[121] = { .set = { {1, -15}, {-7, -3}, {-9, -1}, {-2, -15} } },
	[122] = { .set = { {3, -16}, {17, -19}, {16, -13}, {0, -15} } },
	[123] = { .set = { {1, -17}, {6, -11}, {-1, -19}, {-1, -16} } },
	[124] = { .set = { {1, -16}, {-5, -25}, {9, -17}, {-1, -15} } },
	[125] = { .set = { {-1, -15}, {-12, -8}, {1, 0}, {-3, -15} } },
	[126] = { .set = { {1, -16}, {5, -31}, {16, -24}, {-2, -15} } },
	[127] = { .set = { {1, -16}, {2, -8}, {8, -22}, {0, -13} } },
	[128] = { .set = { {0, -17}, {11, -21}, {-5, -18}, {0, -14} } },
	[129] = { .set = { {0, -17}, {10, -3}, {-10, -4}, {0, -14} } },
	[130] = { .set = { {0, -16}, {7, -30}, {-7, -30}, {0, -14} } },
	[131] = { .set = { {0, -16}, {12, -7}, {-13, -25}, {0, -13} } },
	[132] = { .set = { {-1, -16}, {5, -25}, {-9, -17}, {1, -15} } },
	[133] = { .set = { {1, -15}, {12, -8}, {-1, 0}, {3, -15} } },
	[134] = { .set = { {-1, -16}, {-5, -31}, {-16, -24}, {2, -15} } },
	[135] = { .set = { {0, -16}, {-1, -8}, {-7, -22}, {1, -13} } },
	[136] = { .set = { {-1, -16}, {-7, -26}, {-7, -14}, {1, -14} } },
	[137] = { .set = { {-1, -15}, {7, -3}, {9, -1}, {2, -15} } },
	[138] = { .set = { {-3, -16}, {-17, -19}, {-16, -13}, {0, -15} } },
	[139] = { .set = { {-3, -17}, {-8, -11}, {-1, -19}, {-1, -16} } },
	[140] = { .set = { {-2, -16}, {-11, -22}, {3, -15}, {0, -14} } },
	[141] = { .set = { {-1, -14}, {-10, -8}, {11, -2}, {0, -14} } },
	[142] = { .set = { {-2, -14}, {-17, -8}, {-8, -3}, {-1, -13} } },
	[143] = { .set = { {-1, -20}, {-14, -12}, {12, -23}, {0, -19} } },
	[144] = { .set = { {-1, -15}, {-12, -22}, {7, -16}, {-1, -13} } },
	[145] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[146] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[147] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[148] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[149] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[150] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[151] = { .set = { {-1, -16}, {-13, -24}, {7, -17}, {-1, -14} } },
	[152] = { .set = { {2, -16}, {11, -22}, {-3, -15}, {0, -14} } },
	[153] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[154] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[155] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[156] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[157] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[158] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[159] = { .set = { {2, -17}, {12, -24}, {-3, -16}, {-1, -15} } },
	[160] = { .set = { {1, -16}, {7, -26}, {7, -14}, {-1, -14} } },
	[161] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[162] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[163] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[164] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[165] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[166] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[167] = { .set = { {2, -18}, {7, -27}, {9, -14}, {-1, -15} } },
	[168] = { .set = { {1, -16}, {-5, -25}, {9, -17}, {-1, -15} } },
	[169] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[170] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[171] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[172] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[173] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[174] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[175] = { .set = { {1, -18}, {-5, -28}, {9, -20}, {-2, -17} } },
	[176] = { .set = { {0, -17}, {11, -21}, {-5, -18}, {0, -14} } },
	[177] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[178] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[179] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[180] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[181] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[182] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[183] = { .set = { {0, -18}, {12, -23}, {-6, -19}, {0, -15} } },
	[184] = { .set = { {-1, -16}, {5, -25}, {-9, -17}, {1, -15} } },
	[185] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[186] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[187] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[188] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[189] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[190] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[191] = { .set = { {-1, -18}, {5, -28}, {-9, -20}, {2, -17} } },
	[192] = { .set = { {-1, -16}, {-7, -26}, {-7, -14}, {1, -14} } },
	[193] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[194] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[195] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[196] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[197] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[198] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[199] = { .set = { {-2, -18}, {-7, -27}, {-9, -14}, {1, -15} } },
	[200] = { .set = { {-2, -16}, {-11, -22}, {3, -15}, {0, -14} } },
	[201] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[202] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[203] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[204] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[205] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[206] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[207] = { .set = { {-2, -17}, {-12, -24}, {3, -16}, {1, -15} } },
	[208] = { .set = { {-2, -17}, {-9, -3}, {9, -2}, {-1, -15} } },
	[209] = { .set = { {-2, -16}, {-9, -1}, {9, 0}, {-1, -15} } },
	[210] = { .set = { {-1, -18}, {-13, -8}, {11, -27}, {-1, -15} } },
	[211] = { .set = { {0, -20}, {13, -12}, {-13, -23}, {-1, -19} } },
	[212] = { .set = { {2, -17}, {7, -11}, {0, -19}, {0, -16} } },
	[213] = { .set = { {1, -16}, {2, -8}, {8, -22}, {0, -13} } },
	[214] = { .set = { {0, -16}, {12, -7}, {-13, -25}, {0, -13} } },
	[215] = { .set = { {-2, -16}, {-3, -8}, {-9, -22}, {-1, -13} } },
	[216] = { .set = { {-3, -17}, {-8, -11}, {-1, -19}, {-1, -16} } },
	[217] = { .set = { {-1, -20}, {-14, -12}, {12, -23}, {0, -19} } },
	[218] = { .set = { {-1, -15}, {-12, -22}, {7, -16}, {-1, -13} } },
	[219] = { .set = { {-1, -15}, {-6, -19}, {6, -20}, {-1, -13} } },
	[220] = { .set = { {-1, -15}, {10, -22}, {-9, -16}, {-1, -13} } },
	[221] = { .set = { {-1, -15}, {4, -19}, {-8, -20}, {-1, -13} } },
	[222] = { .set = { {2, -16}, {11, -22}, {-3, -15}, {0, -14} } },
	[223] = { .set = { {2, -16}, {7, -19}, {-4, -19}, {-1, -15} } },
	[224] = { .set = { {2, -16}, {8, -15}, {-9, -22}, {0, -15} } },
	[225] = { .set = { {2, -16}, {9, -19}, {-2, -18}, {0, -15} } },
	[226] = { .set = { {1, -16}, {7, -26}, {7, -14}, {-1, -14} } },
	[227] = { .set = { {2, -15}, {6, -20}, {6, -18}, {-1, -15} } },
	[228] = { .set = { {1, -16}, {6, -15}, {-4, -20}, {-2, -16} } },
	[229] = { .set = { {1, -14}, {8, -21}, {6, -16}, {-1, -15} } },
	[230] = { .set = { {1, -16}, {-5, -25}, {9, -17}, {-1, -15} } },
	[231] = { .set = { {0, -16}, {-3, -22}, {9, -18}, {-2, -15} } },
	[232] = { .set = { {0, -16}, {-3, -18}, {10, -22}, {-2, -15} } },
	[233] = { .set = { {0, -16}, {-6, -21}, {7, -19}, {-2, -15} } },
	[234] = { .set = { {0, -17}, {11, -21}, {-5, -18}, {0, -14} } },
	[235] = { .set = { {0, -17}, {7, -20}, {-8, -20}, {0, -14} } },
	[236] = { .set = { {0, -17}, {-11, -21}, {5, -18}, {0, -14} } },
	[237] = { .set = { {0, -17}, {-7, -20}, {8, -20}, {0, -14} } },
	[238] = { .set = { {-1, -16}, {5, -25}, {-9, -17}, {1, -15} } },
	[239] = { .set = { {0, -16}, {3, -22}, {-9, -18}, {2, -15} } },
	[240] = { .set = { {0, -16}, {3, -18}, {-10, -22}, {2, -15} } },
	[241] = { .set = { {0, -16}, {6, -21}, {-7, -19}, {2, -15} } },
	[242] = { .set = { {-1, -16}, {-7, -26}, {-7, -14}, {1, -14} } },
	[243] = { .set = { {-2, -15}, {-6, -20}, {-6, -18}, {1, -15} } },
	[244] = { .set = { {-1, -16}, {-6, -15}, {4, -20}, {2, -16} } },
	[245] = { .set = { {-1, -14}, {-8, -21}, {-6, -16}, {1, -15} } },
	[246] = { .set = { {-2, -16}, {-11, -22}, {3, -15}, {0, -14} } },
	[247] = { .set = { {-2, -16}, {-7, -19}, {4, -19}, {1, -15} } },
	[248] = { .set = { {-2, -16}, {-8, -15}, {9, -22}, {0, -15} } },
	[249] = { .set = { {-2, -16}, {-9, -19}, {2, -18}, {0, -15} } },
	[250] = { .set = { {-1, -13}, {-11, -6}, {9, -6}, {-1, -12} } },
	[251] = { .set = { {-1, -14}, {-10, -8}, {11, -2}, {0, -14} } },
	[252] = { .set = { {-3, -15}, {5, -3}, {7, -1}, {0, -15} } },
	[253] = { .set = { {-1, -15}, {10, -8}, {-3, 0}, {1, -15} } },
	[254] = { .set = { {0, -17}, {10, -3}, {-10, -4}, {0, -14} } },
	[255] = { .set = { {1, -15}, {-10, -8}, {3, 0}, {-1, -15} } },
	[256] = { .set = { {3, -15}, {-5, -3}, {-7, -1}, {0, -15} } },
	[257] = { .set = { {1, -14}, {10, -8}, {-11, -2}, {0, -14} } },
	[258] = { .set = { {-1, -18}, {-13, -8}, {11, -27}, {-1, -15} } },
	[259] = { .set = { {0, -20}, {13, -12}, {-13, -23}, {-1, -19} } },
	[260] = { .set = { {3, -17}, {8, -11}, {1, -19}, {1, -16} } },
	[261] = { .set = { {1, -17}, {2, -9}, {8, -23}, {0, -14} } },
	[262] = { .set = { {0, -16}, {12, -7}, {-13, -25}, {0, -13} } },
	[263] = { .set = { {-1, -17}, {-2, -9}, {-8, -23}, {0, -14} } },
	[264] = { .set = { {-4, -17}, {-9, -11}, {-2, -19}, {-2, -16} } },
	[265] = { .set = { {-1, -20}, {-14, -12}, {12, -23}, {0, -19} } },
	[266] = { .set = { {-1, -15}, {-12, -22}, {7, -16}, {-1, -13} } },
	[267] = { .set = { {-1, -13}, {-11, -6}, {9, -6}, {-1, -12} } },
	[268] = { .set = { {-1, -17}, {-13, -7}, {11, -26}, {-1, -14} } },
	[269] = { .set = { {2, -16}, {11, -22}, {-3, -15}, {0, -14} } },
	[270] = { .set = { {1, -14}, {10, -8}, {-11, -2}, {0, -14} } },
	[271] = { .set = { {0, -20}, {13, -12}, {-13, -23}, {-1, -19} } },
	[272] = { .set = { {1, -16}, {7, -26}, {7, -14}, {-1, -14} } },
	[273] = { .set = { {1, -15}, {-7, -3}, {-9, -1}, {-2, -15} } },
	[274] = { .set = { {1, -17}, {6, -11}, {-1, -19}, {-1, -16} } },
	[275] = { .set = { {1, -16}, {-5, -25}, {9, -17}, {-1, -15} } },
	[276] = { .set = { {-1, -15}, {-12, -8}, {1, 0}, {-3, -15} } },
	[277] = { .set = { {0, -16}, {1, -8}, {7, -22}, {-1, -13} } },
	[278] = { .set = { {0, -17}, {11, -21}, {-5, -18}, {0, -14} } },
	[279] = { .set = { {0, -17}, {10, -3}, {-10, -4}, {0, -14} } },
	[280] = { .set = { {0, -16}, {12, -7}, {-13, -25}, {0, -13} } },
	[281] = { .set = { {-1, -16}, {5, -25}, {-9, -17}, {1, -15} } },
	[282] = { .set = { {1, -15}, {12, -8}, {-1, 0}, {3, -15} } },
	[283] = { .set = { {0, -16}, {-1, -8}, {-7, -22}, {1, -13} } },
	[284] = { .set = { {-1, -16}, {-7, -26}, {-7, -14}, {1, -14} } },
	[285] = { .set = { {-1, -15}, {7, -3}, {9, -1}, {2, -15} } },
	[286] = { .set = { {-3, -17}, {-8, -11}, {-1, -19}, {-1, -16} } },
	[287] = { .set = { {-2, -16}, {-11, -22}, {3, -15}, {0, -14} } },
	[288] = { .set = { {-1, -14}, {-10, -8}, {11, -2}, {0, -14} } },
	[289] = { .set = { {-1, -20}, {-14, -12}, {12, -23}, {0, -19} } },
	[290] = { .set = { {-1, -15}, {-6, -19}, {6, -20}, {-1, -13} } },
	[291] = { .set = { {-2, -16}, {-7, -19}, {4, -19}, {1, -15} } },
	[292] = { .set = { {-2, -15}, {-6, -20}, {-6, -18}, {1, -15} } },
	[293] = { .set = { {0, -16}, {3, -22}, {-9, -18}, {2, -15} } },
	[294] = { .set = { {0, -17}, {7, -20}, {-8, -20}, {0, -14} } },
	[295] = { .set = { {0, -16}, {-3, -22}, {9, -18}, {-2, -15} } },
	[296] = { .set = { {2, -15}, {6, -20}, {6, -18}, {-1, -15} } },
	[297] = { .set = { {2, -16}, {7, -19}, {-4, -19}, {-1, -15} } },
	[298] = { .set = { {0, -15}, {-11, -22}, {8, -16}, {0, -13} } },
	[299] = { .set = { {-2, -16}, {-11, -22}, {3, -15}, {0, -14} } },
	[300] = { .set = { {-1, -16}, {-7, -26}, {-7, -14}, {1, -14} } },
	[301] = { .set = { {-1, -16}, {5, -25}, {-9, -17}, {1, -15} } },
	[302] = { .set = { {0, -17}, {11, -21}, {-5, -18}, {0, -14} } },
	[303] = { .set = { {1, -16}, {-5, -25}, {9, -17}, {-1, -15} } },
	[304] = { .set = { {1, -16}, {7, -26}, {7, -14}, {-1, -14} } },
	[305] = { .set = { {2, -16}, {11, -22}, {-3, -15}, {0, -14} } },
};

static const ax_anim *const sDeoxysAttackAnimTable1[] = {
	sDeoxysAttackAnims_1_1,
	sDeoxysAttackAnims_1_2,
	sDeoxysAttackAnims_1_3,
	sDeoxysAttackAnims_1_4,
	sDeoxysAttackAnims_1_5,
	sDeoxysAttackAnims_1_6,
	sDeoxysAttackAnims_1_7,
	sDeoxysAttackAnims_1_8,
};

static const ax_anim *const sDeoxysAttackAnimTable2[] = {
	sDeoxysAttackAnims_2_1,
	sDeoxysAttackAnims_2_2,
	sDeoxysAttackAnims_2_3,
	sDeoxysAttackAnims_2_4,
	sDeoxysAttackAnims_2_5,
	sDeoxysAttackAnims_2_6,
	sDeoxysAttackAnims_2_7,
	sDeoxysAttackAnims_2_8,
};

static const ax_anim *const sDeoxysAttackAnimTable3[] = {
	sDeoxysAttackAnims_3_1,
	sDeoxysAttackAnims_3_2,
	sDeoxysAttackAnims_3_3,
	sDeoxysAttackAnims_3_4,
	sDeoxysAttackAnims_3_5,
	sDeoxysAttackAnims_3_6,
	sDeoxysAttackAnims_3_7,
	sDeoxysAttackAnims_3_8,
};

static const ax_anim *const sDeoxysAttackAnimTable4[] = {
	sDeoxysAttackAnims_4_1,
	sDeoxysAttackAnims_4_2,
	sDeoxysAttackAnims_4_3,
	sDeoxysAttackAnims_4_4,
	sDeoxysAttackAnims_4_5,
	sDeoxysAttackAnims_4_6,
	sDeoxysAttackAnims_4_7,
	sDeoxysAttackAnims_4_8,
};

static const ax_anim *const sDeoxysAttackAnimTable5[] = {
	sDeoxysAttackAnims_5_1,
	sDeoxysAttackAnims_5_2,
	sDeoxysAttackAnims_5_3,
	sDeoxysAttackAnims_5_4,
	sDeoxysAttackAnims_5_5,
	sDeoxysAttackAnims_5_6,
	sDeoxysAttackAnims_5_7,
	sDeoxysAttackAnims_5_8,
};

static const ax_anim *const sDeoxysAttackAnimTable6[] = {
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
	sDeoxysAttackAnims_6_1,
};

static const ax_anim *const sDeoxysAttackAnimTable7[] = {
	sDeoxysAttackAnims_7_1,
	sDeoxysAttackAnims_7_2,
	sDeoxysAttackAnims_7_3,
	sDeoxysAttackAnims_7_4,
	sDeoxysAttackAnims_7_5,
	sDeoxysAttackAnims_7_6,
	sDeoxysAttackAnims_7_7,
	sDeoxysAttackAnims_7_8,
};

static const ax_anim *const sDeoxysAttackAnimTable8[] = {
	sDeoxysAttackAnims_8_1,
	sDeoxysAttackAnims_8_2,
	sDeoxysAttackAnims_8_3,
	sDeoxysAttackAnims_8_4,
	sDeoxysAttackAnims_8_5,
	sDeoxysAttackAnims_8_6,
	sDeoxysAttackAnims_8_7,
	sDeoxysAttackAnims_8_8,
};

static const ax_anim *const sDeoxysAttackAnimTable9[] = {
	sDeoxysAttackAnims_9_1,
	sDeoxysAttackAnims_9_2,
	sDeoxysAttackAnims_9_3,
	sDeoxysAttackAnims_9_4,
	sDeoxysAttackAnims_9_5,
	sDeoxysAttackAnims_9_6,
	sDeoxysAttackAnims_9_7,
	sDeoxysAttackAnims_9_8,
};

static const ax_anim *const sDeoxysAttackAnimTable10[] = {
	sDeoxysAttackAnims_10_1,
	sDeoxysAttackAnims_10_2,
	sDeoxysAttackAnims_10_3,
	sDeoxysAttackAnims_10_4,
	sDeoxysAttackAnims_10_5,
	sDeoxysAttackAnims_10_6,
	sDeoxysAttackAnims_10_7,
	sDeoxysAttackAnims_10_8,
};

static const ax_anim *const sDeoxysAttackAnimTable11[] = {
	sDeoxysAttackAnims_11_1,
	sDeoxysAttackAnims_11_2,
	sDeoxysAttackAnims_11_3,
	sDeoxysAttackAnims_11_4,
	sDeoxysAttackAnims_11_5,
	sDeoxysAttackAnims_11_6,
	sDeoxysAttackAnims_11_7,
	sDeoxysAttackAnims_11_8,
};

static const ax_anim *const sDeoxysAttackAnimTable12[] = {
	sDeoxysAttackAnims_12_1,
	sDeoxysAttackAnims_12_2,
	sDeoxysAttackAnims_12_3,
	sDeoxysAttackAnims_12_4,
	sDeoxysAttackAnims_12_5,
	sDeoxysAttackAnims_12_6,
	sDeoxysAttackAnims_12_7,
	sDeoxysAttackAnims_12_8,
};

static const ax_anim *const sDeoxysAttackAnimTable13[] = {
	sDeoxysAttackAnims_13_1,
	sDeoxysAttackAnims_13_2,
	sDeoxysAttackAnims_13_3,
	sDeoxysAttackAnims_13_4,
	sDeoxysAttackAnims_13_5,
	sDeoxysAttackAnims_13_6,
	sDeoxysAttackAnims_13_7,
	sDeoxysAttackAnims_13_8,
};

static const ax_anim *const *const sAxAnimationsDeoxysAttack[] = {
	sDeoxysAttackAnimTable1,
	sDeoxysAttackAnimTable2,
	sDeoxysAttackAnimTable3,
	sDeoxysAttackAnimTable4,
	sDeoxysAttackAnimTable5,
	sDeoxysAttackAnimTable6,
	sDeoxysAttackAnimTable7,
	sDeoxysAttackAnimTable8,
	sDeoxysAttackAnimTable9,
	sDeoxysAttackAnimTable10,
	sDeoxysAttackAnimTable11,
	sDeoxysAttackAnimTable12,
	sDeoxysAttackAnimTable13,
};

static const ax_sprite *const sAxSpritesDeoxysAttack[] = {
	sDeoxysAttackSprites1,
	sDeoxysAttackSprites2,
	sDeoxysAttackSprites3,
	sDeoxysAttackSprites4,
	sDeoxysAttackSprites5,
	sDeoxysAttackSprites6,
	sDeoxysAttackSprites7,
	sDeoxysAttackSprites8,
	sDeoxysAttackSprites9,
	sDeoxysAttackSprites10,
	sDeoxysAttackSprites11,
	sDeoxysAttackSprites12,
	sDeoxysAttackSprites13,
	sDeoxysAttackSprites14,
	sDeoxysAttackSprites15,
	sDeoxysAttackSprites16,
	sDeoxysAttackSprites17,
	sDeoxysAttackSprites18,
	sDeoxysAttackSprites19,
	sDeoxysAttackSprites20,
	sDeoxysAttackSprites21,
	sDeoxysAttackSprites22,
	sDeoxysAttackSprites23,
	sDeoxysAttackSprites24,
	sDeoxysAttackSprites25,
	sDeoxysAttackSprites26,
	sDeoxysAttackSprites27,
	sDeoxysAttackSprites28,
	sDeoxysAttackSprites29,
	sDeoxysAttackSprites30,
	sDeoxysAttackSprites31,
	sDeoxysAttackSprites32,
	sDeoxysAttackSprites33,
	sDeoxysAttackSprites34,
	sDeoxysAttackSprites35,
	sDeoxysAttackSprites36,
	sDeoxysAttackSprites37,
	sDeoxysAttackSprites38,
	sDeoxysAttackSprites39,
	sDeoxysAttackSprites40,
	sDeoxysAttackSprites41,
	sDeoxysAttackSprites42,
	sDeoxysAttackSprites43,
	sDeoxysAttackSprites44,
	sDeoxysAttackSprites45,
	sDeoxysAttackSprites46,
	sDeoxysAttackSprites47,
	sDeoxysAttackSprites48,
	sDeoxysAttackSprites49,
	sDeoxysAttackSprites50,
	sDeoxysAttackSprites51,
	sDeoxysAttackSprites52,
	sDeoxysAttackSprites53,
	sDeoxysAttackSprites54,
	sDeoxysAttackSprites55,
	sDeoxysAttackSprites56,
	sDeoxysAttackSprites57,
	sDeoxysAttackSprites58,
	sDeoxysAttackSprites59,
	sDeoxysAttackSprites60,
	sDeoxysAttackSprites61,
	sDeoxysAttackSprites62,
	sDeoxysAttackSprites63,
	sDeoxysAttackSprites64,
	sDeoxysAttackSprites65,
	sDeoxysAttackSprites66,
	sDeoxysAttackSprites67,
	sDeoxysAttackSprites68,
	sDeoxysAttackSprites69,
	sDeoxysAttackSprites70,
	sDeoxysAttackSprites71,
	sDeoxysAttackSprites72,
	sDeoxysAttackSprites73,
	sDeoxysAttackSprites74,
	sDeoxysAttackSprites75,
	sDeoxysAttackSprites76,
	sDeoxysAttackSprites77,
	sDeoxysAttackSprites78,
	sDeoxysAttackSprites79,
	sDeoxysAttackSprites80,
	sDeoxysAttackSprites81,
	sDeoxysAttackSprites82,
	sDeoxysAttackSprites83,
	sDeoxysAttackSprites84,
	sDeoxysAttackSprites85,
	sDeoxysAttackSprites86,
	sDeoxysAttackSprites87,
	sDeoxysAttackSprites88,
	sDeoxysAttackSprites89,
	sDeoxysAttackSprites90,
	sDeoxysAttackSprites91,
	sDeoxysAttackSprites92,
	sDeoxysAttackSprites93,
	sDeoxysAttackSprites94,
	sDeoxysAttackSprites95,
	sDeoxysAttackSprites96,
	sDeoxysAttackSprites97,
	sDeoxysAttackSprites98,
	sDeoxysAttackSprites99,
	sDeoxysAttackSprites100,
	sDeoxysAttackSprites101,
	sDeoxysAttackSprites102,
	sDeoxysAttackSprites103,
	sDeoxysAttackSprites104,
	sDeoxysAttackSprites105,
	sDeoxysAttackSprites106,
	sDeoxysAttackSprites107,
	sDeoxysAttackSprites108,
	sDeoxysAttackSprites109,
	sDeoxysAttackSprites110,
	sDeoxysAttackSprites111,
	sDeoxysAttackSprites112,
	sDeoxysAttackSprites113,
	sDeoxysAttackSprites114,
	sDeoxysAttackSprites115,
	sDeoxysAttackSprites116,
	sDeoxysAttackSprites117,
	sDeoxysAttackSprites118,
	sDeoxysAttackSprites119,
	sDeoxysAttackSprites120,
	sDeoxysAttackSprites121,
};

static const axmain sAxMainDeoxysAttack = {
	.poses = sAxPosesDeoxysAttack,
	.animations = sAxAnimationsDeoxysAttack,
	.animCount = ARRAY_COUNT(sAxAnimationsDeoxysAttack),
	.spriteData = sAxSpritesDeoxysAttack,
	.positions = sAxPositionsDeoxysAttack,
};
