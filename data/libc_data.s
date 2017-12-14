	.section .rodata

	.align 2, 0
	.global gUnknown_826FDE4
gUnknown_826FDE4: @ 826FDE4
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20

	.global gUnknown_826FDF4
gUnknown_826FDF4: @ 826FDF4
	.byte 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30

	.align 2, 0
	.global gUnknown_826FE04
gUnknown_826FE04: @ 826FE04
	.ascii "Inf"

	.align 2, 0
	.global gUnknown_826FE08
gUnknown_826FE08: @ 826FE08
	.ascii "NaN"

	.align 2, 0
	.global gUnknown_826FE0C
gUnknown_826FE0C: @ 826FE0C
	.ascii "0123456789abcdef"
	.space 4

	.global gUnknown_826FE20
gUnknown_826FE20: @ 826FE20
	.ascii "(null)"

	.align 2, 0
	.global gUnknown_826FE28
gUnknown_826FE28: @ 826FE28
	.ascii "0123456789ABCDEF"
	.space 4

	.global gUnknown_826FE3C
gUnknown_826FE3C: @ 826FE3C
	.ascii "bug in vfprintf: bad base"

	.align 2, 0
	.global gUnknown_826FE58
gUnknown_826FE58: @ 826FE58
	.ascii "0"

	.align 2, 0
	.global gUnknown_826FE5C
gUnknown_826FE5C: @ 826FE5C
	.ascii "."

	.align 2, 0
	.global gUnknown_826FE60
gUnknown_826FE60: @ 826FE60
	.ascii "Infinity"

	.space 4
	.global gUnknown_826FE6C
gUnknown_826FE6C: @ 826FE6C
	.ascii "NaN"

	.align 2, 0
	.global gUnknown_826FE70
gUnknown_826FE70: @ 826FE70
	.ascii "0"
	.align 2, 0
	.ascii "C"
	.align 2, 0

	.global lconv
lconv: @ 826FE78
	.4byte gUnknown_826FEAC, gUnknown_826FEA8
	.4byte gUnknown_826FEA8, gUnknown_826FEA8
	.4byte gUnknown_826FEA8, gUnknown_826FEA8
	.4byte gUnknown_826FEA8, gUnknown_826FEA8
	.4byte gUnknown_826FEA8, gUnknown_826FEA8
	.4byte 0xffffffff,       0xffffffff

	.global gUnknown_826FEA8
gUnknown_826FEA8: @ 826FEA8
	.ascii ""

	.space 4
	.global gUnknown_826FEAC
gUnknown_826FEAC: @ 826FEAC
	.ascii "."

	.align 2, 0
	.global gUnknown_826FEB0
gUnknown_826FEB0: @ 826FEB0
	.ascii "C"

	.align 2, 0
	.global gUnknown_826FEB4
gUnknown_826FEB4: @ 826FEB4
	.4byte 5
	.4byte 25
	.4byte 125

	.align 2, 0
	.global gUnknown_826FEC0
gUnknown_826FEC0: @ 826FEC0
	.8byte 0x000000003ff00000 @ 1e0
	.8byte 0x0000000040240000 @ 1e1
	.8byte 0x0000000040590000 @ 1e2
	.8byte 0x00000000408f4000 @ 1e3
	.8byte 0x0000000040c38800 @ 1e4
	.8byte 0x0000000040f86a00 @ 1e5
	.8byte 0x00000000412e8480 @ 1e6
	.8byte 0x00000000416312d0 @ 1e7
	.8byte 0x000000004197d784 @ 1e8
	.8byte 0x0000000041cdcd65 @ 1e9
	.8byte 0x200000004202a05f @ 1e10
	.8byte 0xe800000042374876 @ 1e11
	.8byte 0xa2000000426d1a94 @ 1e12
	.8byte 0xe540000042a2309c @ 1e13
	.8byte 0x1e90000042d6bcc4 @ 1e14
	.8byte 0x26340000430c6bf5 @ 1e15
	.8byte 0x37e080004341c379 @ 1e16
	.8byte 0x85d8a00043763457 @ 1e17
	.8byte 0x674ec80043abc16d @ 1e18
	.8byte 0x60913d0043e158e4 @ 1e19
	.8byte 0x78b58c404415af1d @ 1e20
	.8byte 0xd6e2ef50444b1ae4 @ 1e21
	.8byte 0x064dd5924480f0cf @ 1e22
	.8byte 0xc7e14af644b52d02 @ 1e23
	.8byte 0x79d99db444ea7843 @ 1e24

	.align 2, 0
	.global gUnknown_826FF88
gUnknown_826FF88: @ 826FF88
	@ big tens
	.8byte 0x37e080004341c379 @ 1e16
	.8byte 0xb5056e174693b8b5 @ 1e32
	.8byte 0xe93ff9f54d384f03 @ 1e64
	.8byte 0xf9301d325a827748 @ 1e128
	.8byte 0x7f73bf3c75154fdd @ 1e256
	@ tiny tenths
	.8byte 0x97d889bc3c9cd2b2 @ 1e-16
	.8byte 0xd5a8a7333949f623 @ 1e-32
	.8byte 0x44f4a73d32a50ffd @ 1e-64
	.8byte 0xcf8c979d255bba08 @ 1e-128
	.8byte 0x64ac6f430ac80628 @ 1e-256

	.align 2, 0
	.global gUnknown_826FFD8
gUnknown_826FFD8: @ 826FFD8
	.ascii ":tt"
	.byte 0

	.align 2, 0
	.global gUnknown_826FFDC
gUnknown_826FFDC: @ 826FFDC
	.ascii "_sbrk: Heap and stack collision\n"
	.byte 0

	.align 2, 0 @ don't pad with nop
