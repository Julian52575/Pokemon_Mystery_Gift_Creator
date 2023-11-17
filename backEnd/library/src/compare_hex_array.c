/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** compare_hex_array
*/

#include "lib.h"

bool
compare_hex_array(unsigned char *s, int l, unsigned char *s2, int l2)
{
    int smaller_lenght = (l < l2 ? l : l2);

    for ( int i = 0; i < smaller_lenght; i++ ) {
        if ( s[i] != s2[i] )
            return false;
    }
    return true;
}
