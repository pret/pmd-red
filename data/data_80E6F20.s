    .section .rodata

	.global gUnknown_80E71E4
gUnknown_80E71E4: @ 80E71E4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E71FC
gUnknown_80E71FC: @ 80E71FC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7214
gUnknown_80E7214: @ 80E7214
    .4byte Error_80E7268, 0xC
    .4byte IncorrectPassword_80E7250, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

CheckAgain_80E7234:
    .string "{CENTER_ALIGN}Please check it again.\0"
    .align 2, 0

IncorrectPassword_80E7250:
    .string "{CENTER_ALIGN}Incorrect password!\0"
    .align 2, 0

Error_80E7268:
    .string "{CENTER_ALIGN}{COLOR_1 RED}Error!{END_COLOR_TEXT_1} \0"
    .align 2, 0

	.global gUnknown_80E7278
gUnknown_80E7278: @ 80E7278
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7290
gUnknown_80E7290: @ 80E7290
    .4byte Success_80E72D8, 0xC
    .4byte PasswordAccept_80E72B4, 0xC
    .4byte DATA_80E72B0, 0xC
    .4byte 0, 0xA

DATA_80E72B0:
    .string "  \0"
    .align 2, 0

PasswordAccept_80E72B4:
    .string "{CENTER_ALIGN}The password has been accepted.\0"
    .align 2, 0

Success_80E72D8:
    .string "{CENTER_ALIGN}{COLOR_1 LIGHT_BLUE_2}Success!{END_COLOR_TEXT_1} \0"
    .align 2, 0

	.global gUnknown_80E72EC
gUnknown_80E72EC: @ 80E72EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7304
gUnknown_80E7304: @ 80E7304
    .4byte Error_80E7268, 0xC
    .4byte NotSOSMail_80E7324, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

NotSOSMail_80E7324:
    .string "{CENTER_ALIGN}This is not an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}.\0"
    .align 2, 0

	.global gUnknown_80E7344
gUnknown_80E7344: @ 80E7344
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E735C
gUnknown_80E735C: @ 80E735C
    .4byte Error_80E7268, 0xC
    .4byte ReceiveSOSMail_80E737C, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

ReceiveSOSMail_80E737C:
    .string "{CENTER_ALIGN}This {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} has been received already.\0"
    .align 2, 0

	.global gUnknown_80E73AC
gUnknown_80E73AC: @ 80E73AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E73C4
gUnknown_80E73C4: @ 80E73C4
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E73E4, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E73E4:
    .string "#+This is not an #CGA-OK Mail#R.\0"
    .align 2, 0

	.global gUnknown_80E7408
gUnknown_80E7408: @ 80E7408
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7420
gUnknown_80E7420: @ 80E7420
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E7440, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E7440:
    .string "#+This #CGA-OK Mail#R cannot be used.\0"
    .align 2, 0

	.global gUnknown_80E7468
gUnknown_80E7468: @ 80E7468
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7480
gUnknown_80E7480: @ 80E7480
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E74A0, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E74A0:
    .string "#+This is not a #CGThank-You Mail#R.\0"
    .align 2, 0

	.global gUnknown_80E74C8
gUnknown_80E74C8: @ 80E74C8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E74E0
gUnknown_80E74E0: @ 80E74E0
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E7500, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E7500:
    .string "#+This #CGThank-You Mail#R cannot be used.\0"
    .align 2, 0

	.global gUnknown_80E752C
gUnknown_80E752C: @ 80E752C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7544
gUnknown_80E7544: @ 80E7544
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E7564, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E7564:
    .string "#+This is not a #CGWonder Mail#R.\0"
    .align 2, 0

	.global gUnknown_80E7588
gUnknown_80E7588: @ 80E7588
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E75A0
gUnknown_80E75A0: @ 80E75A0
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E75CC, 0xC
    .4byte sUnknown_80E75C0, 0xC
    .4byte 0, 0xA

sUnknown_80E75C0:
    .string "#+new mail.\0"
    .align 2, 0

sUnknown_80E75CC:
    .string "#+There is no space for receiving\0"
    .align 2, 0

    .string "pksdir0\0"

