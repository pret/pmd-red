// The code assumes these two strings are the same size:

ALIGNED(4) static const u8 sYayoiSan[] = _("やよい{INVALID_SEQUENCE_976C}"); // 0x82, 0xE2, 0x82, 0xE6, 0x82, 0xA2, 0x97, 0x6C, 0x00
ALIGNED(4) static const u8 sMisakiSan[] = _("みさき{INVALID_SEQUENCE_976C}"); // 0x82, 0xDD, 0x82, 0xB3, 0x82, 0xAB, 0x97, 0x6C, 0x00

// -1 because of the trailing "\0"
#define BLAME_SIZE (sizeof(sYayoiSan) - 1)

// Should be aligned to 4 bytes. Default blame size is 8, stack size 12. If blame size was 11, stack size should still be 12
#define BLAME_STACK_SIZE (BLAME_SIZE - (BLAME_SIZE % 4) + 4)