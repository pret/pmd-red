#include "global.h"
#include "globaldata.h"
#include "effect_files_table.h"
#include "decompress_sir.h"

// TODO: move to header
extern const SiroArchive gUnknown_9740950;
extern const SiroArchive gUnknown_974BE54;
extern const SiroArchive gUnknown_97547D8;
extern const SiroArchive gUnknown_9756674;
extern const SiroArchive gUnknown_9766A78;
extern const SiroArchive gUnknown_9769088;
extern const SiroArchive gUnknown_9773B00;
extern const SiroArchive gUnknown_9783F04;
extern const SiroArchive gUnknown_978C7C0;
extern const SiroArchive gUnknown_979B730;
extern const SiroArchive gUnknown_979DCF4;
extern const SiroArchive gUnknown_979ECC4;
extern const SiroArchive gUnknown_97A0F34;
extern const SiroArchive gUnknown_97A20C4;
extern const SiroArchive gUnknown_97A3988;
extern const SiroArchive gUnknown_97A4FAC;
extern const SiroArchive gUnknown_97A8C38;
extern const SiroArchive gUnknown_97AA0B0;
extern const SiroArchive gUnknown_97AABA8;
extern const SiroArchive gUnknown_97AF214;
extern const SiroArchive gUnknown_97AFE54;
extern const SiroArchive gUnknown_97B0900;
extern const SiroArchive gUnknown_97B568C;
extern const SiroArchive gUnknown_97B6924;
extern const SiroArchive gUnknown_97B6F2C;
extern const SiroArchive gUnknown_97B8B68;
extern const SiroArchive gUnknown_97B9074;
extern const SiroArchive gUnknown_97BA958;
extern const SiroArchive gUnknown_97BACC4;
extern const SiroArchive gUnknown_97BD45C;
extern const SiroArchive gUnknown_97BE614;
extern const SiroArchive gUnknown_97BF08C;
extern const SiroArchive gUnknown_97C17A8;
extern const SiroArchive gUnknown_97C2784;
extern const SiroArchive gUnknown_97C3E1C;
extern const SiroArchive gUnknown_97C6B08;
extern const SiroArchive gUnknown_97C76A8;
extern const SiroArchive gUnknown_97CA290;
extern const SiroArchive gUnknown_97CBD58;
extern const SiroArchive gUnknown_97CD47C;
extern const SiroArchive gUnknown_97CE624;
extern const SiroArchive gUnknown_97D0694;
extern const SiroArchive gUnknown_97D2DF8;
extern const SiroArchive gUnknown_97D33BC;
extern const SiroArchive gUnknown_97D48EC;
extern const SiroArchive gUnknown_97D6918;
extern const SiroArchive gUnknown_97DB4E0;
extern const SiroArchive gUnknown_97DE2C0;
extern const SiroArchive gUnknown_97DFFD8;
extern const SiroArchive gUnknown_97E0B18;
extern const SiroArchive gUnknown_97E3E10;
extern const SiroArchive gUnknown_97E5548;
extern const SiroArchive gUnknown_97EAC34;
extern const SiroArchive gUnknown_97EB458;
extern const SiroArchive gUnknown_97EC8E4;
extern const SiroArchive gUnknown_97EDE74;
extern const SiroArchive gUnknown_97EE16C;
extern const SiroArchive gUnknown_97F06D8;
extern const SiroArchive gUnknown_97F20B8;
extern const SiroArchive gUnknown_97F2C10;
extern const SiroArchive gUnknown_97F5038;
extern const SiroArchive gUnknown_97F56AC;
extern const SiroArchive gUnknown_97F772C;
extern const SiroArchive gUnknown_97F810C;
extern const SiroArchive gUnknown_97F8FF4;
extern const SiroArchive gUnknown_97FA0F0;
extern const SiroArchive gUnknown_97FBF1C;
extern const SiroArchive gUnknown_97FCEAC;
extern const SiroArchive gUnknown_97FDEF4;
extern const SiroArchive gUnknown_9800B00;
extern const SiroArchive gUnknown_9801080;
extern const SiroArchive gUnknown_98015FC;
extern const SiroArchive gUnknown_9802438;
extern const SiroArchive gUnknown_9803184;
extern const SiroArchive gUnknown_98045E8;
extern const SiroArchive gUnknown_980519C;
extern const SiroArchive gUnknown_9805FF4;
extern const SiroArchive gUnknown_98067DC;
extern const SiroArchive gUnknown_9806E60;
extern const SiroArchive gUnknown_98074A4;
extern const SiroArchive gUnknown_98078A0;
extern const SiroArchive gUnknown_9807BDC;
extern const SiroArchive gUnknown_9808890;
extern const SiroArchive gUnknown_980A350;
extern const SiroArchive gUnknown_980B580;
extern const SiroArchive gUnknown_980C308;
extern const SiroArchive gUnknown_980C830;
extern const SiroArchive gUnknown_980DB3C;
extern const SiroArchive gUnknown_980E08C;
extern const SiroArchive gUnknown_980EBEC;
extern const SiroArchive gUnknown_9812F54;
extern const SiroArchive gUnknown_9813710;
extern const SiroArchive gUnknown_981447C;
extern const SiroArchive gUnknown_9814C9C;
extern const SiroArchive gUnknown_9815C0C;
extern const SiroArchive gUnknown_9815E9C;
extern const SiroArchive gUnknown_98170B4;
extern const SiroArchive gUnknown_9817550;
extern const SiroArchive gUnknown_9817B3C;
extern const SiroArchive gUnknown_98196BC;
extern const SiroArchive gUnknown_981AC60;
extern const SiroArchive gUnknown_981AFC8;
extern const SiroArchive gUnknown_981CC20;
extern const SiroArchive gUnknown_981D97C;
extern const SiroArchive gUnknown_981E450;
extern const SiroArchive gUnknown_981FDDC;
extern const SiroArchive gUnknown_98216EC;
extern const SiroArchive gUnknown_9821A1C;
extern const SiroArchive gUnknown_9823C10;
extern const SiroArchive gUnknown_9824E2C;
extern const SiroArchive gUnknown_9825508;
extern const SiroArchive gUnknown_98278D8;
extern const SiroArchive gUnknown_9828ED8;
extern const SiroArchive gUnknown_9829B6C;
extern const SiroArchive gUnknown_982A960;
extern const SiroArchive gUnknown_982AEDC;
extern const SiroArchive gUnknown_982B0C8;
extern const SiroArchive gUnknown_98344C8;
extern const SiroArchive gUnknown_98367D4;
extern const SiroArchive gUnknown_9837A34;
extern const SiroArchive gUnknown_9838678;
extern const SiroArchive gUnknown_9838AB4;
extern const SiroArchive gUnknown_983A7A8;
extern const SiroArchive gUnknown_983BED4;
extern const SiroArchive gUnknown_983C248;
extern const SiroArchive gUnknown_983D410;
extern const SiroArchive gUnknown_983D5FC;
extern const SiroArchive gUnknown_983DFF0;
extern const SiroArchive gUnknown_983F060;
extern const SiroArchive gUnknown_983F3A4;
extern const SiroArchive gUnknown_9842498;
extern const SiroArchive gUnknown_9844EDC;
extern const SiroArchive gUnknown_98452E0;
extern const SiroArchive gUnknown_9846AC8;
extern const SiroArchive gUnknown_9847D1C;
extern const SiroArchive gUnknown_98482D0;
extern const SiroArchive gUnknown_98489E4;
extern const SiroArchive gUnknown_98491A8;
extern const SiroArchive gUnknown_984AE74;
extern const SiroArchive gUnknown_984BDF8;
extern const SiroArchive gUnknown_984CCEC;
extern const SiroArchive gUnknown_984E45C;
extern const SiroArchive gUnknown_984EBA0;
extern const SiroArchive gUnknown_984FC40;
extern const SiroArchive gUnknown_9853444;
extern const SiroArchive gUnknown_98549B8;
extern const SiroArchive gUnknown_9854D10;

const File gEffectFiles[EFFECT_FILES_COUNT] = {
    [0] = { "efbg000", &gUnknown_9740950, },
    [1] = { "efbg001", &gUnknown_974BE54, },
    [2] = { "efbg002", &gUnknown_97547D8, },
    [3] = { "efbg003", &gUnknown_9756674, },
    [4] = { "efbg004", &gUnknown_9766A78, },
    [5] = { "efbg005", &gUnknown_9769088, },
    [6] = { "efbg006", &gUnknown_9773B00, },
    [7] = { "efbg007", &gUnknown_9783F04, },
    [8] = { "efob000", &gUnknown_978C7C0, },
    [9] = { "efob001", &gUnknown_979B730, },
    [10] = { "efob002", &gUnknown_979DCF4, },
    [11] = { "efob003", &gUnknown_979ECC4, },
    [12] = { "efob004", &gUnknown_97A0F34, },
    [13] = { "efob005", &gUnknown_97A20C4, },
    [14] = { "efob006", &gUnknown_97A3988, },
    [15] = { "efob007", &gUnknown_97A4FAC, },
    [16] = { "efob008", &gUnknown_97A8C38, },
    [17] = { "efob009", &gUnknown_97AA0B0, },
    [18] = { "efob010", &gUnknown_97AABA8, },
    [19] = { "efob011", &gUnknown_97AF214, },
    [20] = { "efob012", &gUnknown_97AFE54, },
    [21] = { "efob013", &gUnknown_97B0900, },
    [22] = { "efob014", &gUnknown_97B568C, },
    [23] = { "efob015", &gUnknown_97B6924, },
    [24] = { "efob016", &gUnknown_97B6F2C, },
    [25] = { "efob017", &gUnknown_97B8B68, },
    [26] = { "efob018", &gUnknown_97B9074, },
    [27] = { "efob019", &gUnknown_97BA958, },
    [28] = { "efob020", &gUnknown_97BACC4, },
    [29] = { "efob021", &gUnknown_97BD45C, },
    [30] = { "efob022", &gUnknown_97BE614, },
    [31] = { "efob023", &gUnknown_97BF08C, },
    [32] = { "efob024", &gUnknown_97C17A8, },
    [33] = { "efob025", &gUnknown_97C2784, },
    [34] = { "efob026", &gUnknown_97C3E1C, },
    [35] = { "efob027", &gUnknown_97C6B08, },
    [36] = { "efob028", &gUnknown_97C76A8, },
    [37] = { "efob029", &gUnknown_97CA290, },
    [38] = { "efob030", &gUnknown_97CBD58, },
    [39] = { "efob031", &gUnknown_97CD47C, },
    [40] = { "efob032", &gUnknown_97CE624, },
    [41] = { "efob033", &gUnknown_97D0694, },
    [42] = { "efob034", &gUnknown_97D2DF8, },
    [43] = { "efob035", &gUnknown_97D33BC, },
    [44] = { "efob036", &gUnknown_97D48EC, },
    [45] = { "efob037", &gUnknown_97D6918, },
    [46] = { "efob038", &gUnknown_97DB4E0, },
    [47] = { "efob039", &gUnknown_97DE2C0, },
    [48] = { "efob040", &gUnknown_97DFFD8, },
    [49] = { "efob041", &gUnknown_97E0B18, },
    [50] = { "efob042", &gUnknown_97E3E10, },
    [51] = { "efob043", &gUnknown_97E5548, },
    [52] = { "efob044", &gUnknown_97EAC34, },
    [53] = { "efob045", &gUnknown_97EB458, },
    [54] = { "efob046", &gUnknown_97EC8E4, },
    [55] = { "efob047", &gUnknown_97EDE74, },
    [56] = { "efob048", &gUnknown_97EE16C, },
    [57] = { "efob049", &gUnknown_97F06D8, },
    [58] = { "efob050", &gUnknown_97F20B8, },
    [59] = { "efob051", &gUnknown_97F2C10, },
    [60] = { "efob052", &gUnknown_97F5038, },
    [61] = { "efob053", &gUnknown_97F56AC, },
    [62] = { "efob054", &gUnknown_97F772C, },
    [63] = { "efob055", &gUnknown_97F810C, },
    [64] = { "efob056", &gUnknown_97F8FF4, },
    [65] = { "efob057", &gUnknown_97FA0F0, },
    [66] = { "efob058", &gUnknown_97FBF1C, },
    [67] = { "efob059", &gUnknown_97FCEAC, },
    [68] = { "efob060", &gUnknown_97FDEF4, },
    [69] = { "efob061", &gUnknown_9800B00, },
    [70] = { "efob062", &gUnknown_9801080, },
    [71] = { "efob063", &gUnknown_98015FC, },
    [72] = { "efob064", &gUnknown_9802438, },
    [73] = { "efob065", &gUnknown_9803184, },
    [74] = { "efob066", &gUnknown_98045E8, },
    [75] = { "efob067", &gUnknown_980519C, },
    [76] = { "efob068", &gUnknown_9805FF4, },
    [77] = { "efob069", &gUnknown_98067DC, },
    [78] = { "efob070", &gUnknown_9806E60, },
    [79] = { "efob071", &gUnknown_98074A4, },
    [80] = { "efob072", &gUnknown_98078A0, },
    [81] = { "efob073", &gUnknown_9807BDC, },
    [82] = { "efob074", &gUnknown_9808890, },
    [83] = { "efob075", &gUnknown_980A350, },
    [84] = { "efob076", &gUnknown_980B580, },
    [85] = { "efob077", &gUnknown_980C308, },
    [86] = { "efob078", &gUnknown_980C830, },
    [87] = { "efob079", &gUnknown_980DB3C, },
    [88] = { "efob080", &gUnknown_980E08C, },
    [89] = { "efob081", &gUnknown_980EBEC, },
    [90] = { "efob082", &gUnknown_9812F54, },
    [91] = { "efob083", &gUnknown_9813710, },
    [92] = { "efob084", &gUnknown_981447C, },
    [93] = { "efob085", &gUnknown_9814C9C, },
    [94] = { "efob086", &gUnknown_9815C0C, },
    [95] = { "efob087", &gUnknown_9815E9C, },
    [96] = { "efob088", &gUnknown_98170B4, },
    [97] = { "efob089", &gUnknown_9817550, },
    [98] = { "efob090", &gUnknown_9817B3C, },
    [99] = { "efob091", &gUnknown_98196BC, },
    [100] = { "efob092", &gUnknown_981AC60, },
    [101] = { "efob093", &gUnknown_981AFC8, },
    [102] = { "efob094", &gUnknown_981CC20, },
    [103] = { "efob095", &gUnknown_981D97C, },
    [104] = { "efob096", &gUnknown_981E450, },
    [105] = { "efob097", &gUnknown_981FDDC, },
    [106] = { "efob098", &gUnknown_98216EC, },
    [107] = { "efob099", &gUnknown_9821A1C, },
    [108] = { "efob100", &gUnknown_9823C10, },
    [109] = { "efob101", &gUnknown_9824E2C, },
    [110] = { "efob102", &gUnknown_9825508, },
    [111] = { "efob103", &gUnknown_98278D8, },
    [112] = { "efob104", &gUnknown_9828ED8, },
    [113] = { "efob105", &gUnknown_9829B6C, },
    [114] = { "efob106", &gUnknown_982A960, },
    [115] = { "efob107", &gUnknown_982AEDC, },
    [116] = { "efob108", &gUnknown_982B0C8, },
    [117] = { "efob109", &gUnknown_98344C8, },
    [118] = { "efob110", &gUnknown_98367D4, },
    [119] = { "efob111", &gUnknown_9837A34, },
    [120] = { "efob112", &gUnknown_9838678, },
    [121] = { "efob113", &gUnknown_9838AB4, },
    [122] = { "efob114", &gUnknown_983A7A8, },
    [123] = { "efob115", &gUnknown_983BED4, },
    [124] = { "efob116", &gUnknown_983C248, },
    [125] = { "efob117", &gUnknown_983D410, },
    [126] = { "efob118", &gUnknown_983D5FC, },
    [127] = { "efob119", &gUnknown_983DFF0, },
    [128] = { "efob120", &gUnknown_983F060, },
    [129] = { "efob121", &gUnknown_983F3A4, },
    [130] = { "efob122", &gUnknown_9842498, },
    [131] = { "efob123", &gUnknown_9844EDC, },
    [132] = { "efob124", &gUnknown_98452E0, },
    [133] = { "efob125", &gUnknown_9846AC8, },
    [134] = { "efob126", &gUnknown_9847D1C, },
    [135] = { "efob127", &gUnknown_98482D0, },
    [136] = { "efob128", &gUnknown_98489E4, },
    [137] = { "efob129", &gUnknown_98491A8, },
    [138] = { "efob130", &gUnknown_984AE74, },
    [139] = { "efob131", &gUnknown_984BDF8, },
    [140] = { "efob132", &gUnknown_984CCEC, },
    [141] = { "efob133", &gUnknown_984E45C, },
    [142] = { "efob134", &gUnknown_984EBA0, },
    [143] = { "efob135", &gUnknown_984FC40, },
    [144] = { "efob136", &gUnknown_9853444, },
    [145] = { "efob137", &gUnknown_98549B8, },
    [146] = { "efob138", &gUnknown_9854D10, },
};
