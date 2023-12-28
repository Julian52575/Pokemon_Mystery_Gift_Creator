/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** open_decrypt_compare_files
*/

#include "lib.h"
#include "decrypt.h"

bool
open_decrypt_compare_files(char E[], char D[])
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
