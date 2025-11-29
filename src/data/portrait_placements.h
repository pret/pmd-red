// There is no #ifdef guard here because we want this array duplicated into different overlays.

#define X_L 2
#define X_MID_L 7
#define X_CENTER_L 12
#define X_CENTER_R 13
#define X_MID_R 18
#define X_R 23

#define Y_T 1
#define Y_MID_T 2
#define Y_CENTER 5
// Looks like they defined `Y_MID_B` as 8 instead of 7 and that's why we have a duplicate placement
#define Y_B 8

static const struct PortraitPlacementInfo sPortraitPlacements[PLACEMENT_COUNT] = {
    [PLACEMENT_LEFT_BOTTOM_1] = { { X_L, Y_B }, FALSE },
    [PLACEMENT_CENTERLEFT_CENTER] = { { X_CENTER_L, Y_CENTER }, FALSE },
    [PLACEMENT_LEFT_BOTTOM_2] = { { X_L, Y_B }, FALSE },
    [PLACEMENT_RIGHT_BOTTOM_FLIP] = { { X_R, Y_B }, TRUE },
    [PLACEMENT_MIDLEFT_BOTTOM] = { { X_MID_L, Y_B }, FALSE },
    [PLACEMENT_MIDRIGHT_BOTTOM_FLIP] = { { X_MID_R, Y_B }, TRUE },
    [PLACEMENT_CENTERRIGHT_CENTER_FLIP] = { { X_CENTER_R, Y_CENTER }, TRUE },
    [PLACEMENT_LEFT_BOTTOM_FLIP] = { { X_L, Y_B }, TRUE },
    [PLACEMENT_RIGHT_BOTTOM] = { { X_R, Y_B }, FALSE },
    [PLACEMENT_MIDLEFT_BOTTOM_FLIP] = { { X_MID_L, Y_B }, TRUE },
    [PLACEMENT_MIDRIGHT_BOTTOM] = { { X_MID_R, Y_B }, FALSE },
    [PLACEMENT_CENTERLEFT_TOP] = { { X_CENTER_L, Y_T }, FALSE },
    [PLACEMENT_LEFT_MIDTOP] = { { X_L, Y_MID_T }, FALSE },
    [PLACEMENT_RIGHT_MIDTOP_FLIP] = { { X_R, Y_MID_T }, TRUE },
    [PLACEMENT_MIDLEFT_TOP] = { { X_MID_L, Y_T }, FALSE },
    [PLACEMENT_MIDRIGHT_TOP_FLIP] = { { X_MID_R, Y_T }, TRUE },
    [PLACEMENT_CENTERRIGHT_TOP_FLIP] = { { X_CENTER_R, Y_T }, TRUE },
    [PLACEMENT_LEFT_MIDTOP_FLIP] = { { X_L, Y_MID_T }, TRUE },
    [PLACEMENT_RIGHT_MIDTOP] = { { X_R, Y_MID_T }, FALSE },
    [PLACEMENT_MIDLEFT_TOP_FLIP] = { { X_MID_L, Y_T }, TRUE },
    [PLACEMENT_MIDRIGHT_TOP] = { { X_MID_R, Y_T }, FALSE },
};

#undef X_L
#undef X_MID_L
#undef X_CENTER_L
#undef X_CENTER_R
#undef X_MID_R
#undef X_R

#undef Y_T
#undef Y_MID_T
#undef Y_CENTER
#undef Y_B