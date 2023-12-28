/*
** RULIAN PROJECT, 2023
** PMMG
** File description:
** checksum_t
*/

#include <criterion/criterion.h>
#include "update_checksum.h"
#include "lib.h"

#define     CELEBI_DECRYPTED    "../library/reference/decrypted/celebiD"
#define     RIOLU_DECRYPTED     "../library/reference/decrypted/rioluD"

uint16_t
open_update_checksum(char F[])
{
    uint16_t checksum = 0x0000;
    int lenght = 0;
    uint8_t *file = (uint8_t *) my_open_file(F, &lenght);

    checksum = get_checksum(file + 0x10, lenght - 0x10);
    free(file);
    return checksum;
    
}

Test(Celebi, Update_checksum)
{
    cr_assert( open_update_checksum(CELEBI_DECRYPTED) == 0xd509);
}

Test(Riolu, Update_checksum)
{
    cr_assert( open_update_checksum(RIOLU_DECRYPTED) == 0x2988);
}
