/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** decrypt_celebi_t
*/

#include <criterion/criterion.h>
#include "decrypt.h"
#include "lib.h"

#define     CELEBI_DECRYPTED    "../library/reference/decrypted/celebiD"
#define     CELEBI_ENCRYPTED    "../library/reference/encrypted/celebiE"
#define     RIOLU_DECRYPTED     "../library/reference/decrypted/rioluD"
#define     RIOLU_ENCRYPTED     "../library/reference/encrypted/rioluE"

bool open_decrypt_compare_files(char E[], char D[])
{
    unsigned char *encrypted = NULL;
    int en_length = 0;
    unsigned char *decrypted = NULL;
    int de_length = 0;

    encrypted = (unsigned char *) my_open_file(E, &en_length);
    if ( !encrypted ) {
        printf("[C Decrypt]Error:\nError when reading %s.\n", E);
        return false;
    }

    decrypted = (unsigned char *) my_open_file(D, &de_length);
    if ( !decrypted ) {
        if (encrypted) {
            free(encrypted);
        }
        printf("[C Decrypt]Error:\nError when reading %s.\n", D);
        return false;
    }
    
    decrypt_file(encrypted, en_length);
    return compare_hex_array(encrypted, en_length, decrypted, de_length);
}


Test(Riolu, Decryption)
{
   cr_assert( open_decrypt_compare_files(RIOLU_ENCRYPTED, RIOLU_DECRYPTED) );
}

Test(Celebi, Decryption)
{
   cr_assert( open_decrypt_compare_files(CELEBI_ENCRYPTED, CELEBI_DECRYPTED) );
}
