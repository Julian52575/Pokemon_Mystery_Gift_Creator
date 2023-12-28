/*
** RULIAN PROJECT, 2023
** project_name
** File description:
** encrypt_t
*/

#include <criterion/criterion.h>
#include "decrypt.h"
#include "lib.h"

#define     CELEBI_DECRYPTED    "../library/reference/decrypted/celebiD"
#define     CELEBI_ENCRYPTED    "../library/reference/encrypted/celebiE"
#define     RIOLU_DECRYPTED     "../library/reference/decrypted/rioluD"
#define     RIOLU_ENCRYPTED     "../library/reference/encrypted/rioluE"

bool open_decrypt_compare_files(char E[], char D[]);

Test(Riolu, Encryption)
{
    cr_assert( open_decrypt_compare_files(RIOLU_DECRYPTED, RIOLU_ENCRYPTED ) );
}

Test(Celebi, Encryption)
{
    cr_assert( open_decrypt_compare_files(CELEBI_DECRYPTED, CELEBI_ENCRYPTED ) );
}
