        .section .rodata

        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E07EC
gUnknown_80E07EC: @ 80E07EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0804
gUnknown_80E0804: @ 80E0804
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0e, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E081C
gUnknown_80E081C: @ 80E081C
        .string "Courses\0"
        .align 2,0

	.global gUnknown_80E0824
gUnknown_80E0824: @ 80E0824
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_80E0828
gUnknown_80E0828: @ 80E0828
        .string "{COLOR_2}%c%s{END_COLOR_TEXT_2}\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E083C
gUnknown_80E083C: @ 80E083C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0854
gUnknown_80E0854: @ 80E0854
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x11, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E086C
gUnknown_80E086C: @ 80E086C

        .4byte SOSList
        .4byte RequestList
        .4byte SOSMail
        .4byte ToDoList
        .4byte AOKMail
        .4byte ThanksList
        .4byte CompletedJobs
        .4byte OkdRescue

        .global OkdRescue
        OkdRescue:
        .string "OK{APOSTROPHE}d Rescues\0"
        .align 2,0

        .global CompletedJobs
        CompletedJobs:
        .string "Completed Jobs\0"
        .align 2,0

        .global ThanksList
        ThanksList:
        .string "Thanks List\0"
        .align 2,0

        .global AOKMail
        AOKMail:
        .string "A-OK Mail\0"
        .align 2,0

        .global ToDoList
        ToDoList:
        .string "To-Do List\0"
        .align 2,0

        .global SOSMail
        SOSMail:
        .string "SOS Mail\0"
        .align 2,0

        .global RequestList
        RequestList:
        .string "Request List\0"
        .align 2,0

        .global SOSList
        SOSList:
        .string "SOS List\0"
        .align 2,0

        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E0900
gUnknown_80E0900: @ 80E0900
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global DATA_80E0918
        DATA_80E0918:
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80E091C
gUnknown_80E091C: @ 80E091C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00

        .4byte DATA_80E0918

	.global gUnknown_80E0934
gUnknown_80E0934: @ 80E0934
        .string "ID:\0"

	.global gUnknown_80E0938
gUnknown_80E0938: @ 80E0938
        .string "%-4d\0"
        .align 2,0
        .string "pksdir0\0"
