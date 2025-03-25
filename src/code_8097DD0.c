#include "global.h"
#include "structs/str_status_text.h"
#include "strings.h"
#include "decompress_3.h"

static bool8 AreStatusesTheSame(const StatusText *status1, const StatusText *status2)
{
    if (status1->name == status2->name && status1->desc == status2->desc) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// arm9.bin::02069774
s32 PrepareStatusStringArrays(const char *str, STATUSTEXTS(statuses))
{
    s32 i, j;
    s32 counter;
    s32 stringLengths[99];
    char formattedStatusString[100];
    s32 strLen;

    counter = 0;
    for (i = 0; i < ARRAY_COUNT_INT(gStatusDescriptions); i++) {
        if (gStatusDescriptions[i].name == NULL)
            break;

        for (j = 0; j < 100; j++) {
            if (gStatusDescriptions[i].name[j] == '#' && gStatusDescriptions[i].name[j + 1] == 'r') {
                formattedStatusString[j++] = '#';
                formattedStatusString[j++] = 'r';
                formattedStatusString[j++] = '\0';
                break;
            }

            formattedStatusString[j] = gStatusDescriptions[i].name[j];
        }

        strLen = strlen(formattedStatusString);
        stringLengths[i] = strLen;
    }

    while (*str != '\0') {
        if (*str == '#') {
            for (i = 0; i < ARRAY_COUNT_INT(gStatusDescriptions) && gStatusDescriptions[i].name != NULL; i++) {
                if (StrsDifferent_IgnoreCase(gStatusDescriptions[i].name, str, stringLengths[i]) == 0) {
                    for (j = 0; j < counter; j++) {
                        if (AreStatusesTheSame(&gStatusDescriptions[i], statuses[j]) != 0)
                            break;
                    }

                    if (j == counter && counter < MAX_STATUS_TEXTS) {
                        statuses[counter++] = &gStatusDescriptions[i];
                    }
                }
            }
        }
        else {
            u8 c = *str;
            if (c == 0x81 || c == 0x82 || c == 0x83 || c == 0x84 || c == 0x87) {
                str++;
            }
        }

        str++;
    }

    return counter;
}
