/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** update_checksum
*/

#include "update_checksum.h"
#include "lib.h"

/* From Bulbapedia :
The checksum is calculated in three steps:

    Split the unencrypted data from offsets 0x08 to 0x87 into two-byte words,
    Take the sum of the words, and
    Truncate the sum to sixteen bits.
*/

uint16_t
get_checksum(uint8_t *file, int lenght)
{
    uint64_t checksum = 0x0000;
    //parsing the first 80 values to get the checksum
    for ( int i = 0; i < lenght && i <= 0x80; i += 2) {
        checksum += (file[i + 1] << 8) + file[i];
    }
    checksum = checksum & 0xFFFF;
    return checksum;
}

void
update_checksum(uint8_t *file, int lenght)
{
    uint64_t checksum = 0x00000000;

    //ignoring header
    checksum = get_checksum(file + 0x10, lenght - 0x10);

    //writing the new checksum inside the file
    file -= 0x02;
    file[0] = checksum & 0x00FF;
    file[1] = checksum >> 8;

    printf("The new checksum is: _%lx_\n", checksum);
    return;
}

