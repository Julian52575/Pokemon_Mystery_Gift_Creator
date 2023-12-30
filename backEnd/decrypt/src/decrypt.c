/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** decrypt
*/

#include "lib.h"

static unsigned long int
PRNG_call(unsigned long int seed)
{
    return (0x41C64E6Du * seed + 0x00006073u);
}

static void 
PRNG_function(unsigned long int *result, unsigned short *key)
{
    *result = PRNG_call(*result);
    *key = (unsigned short) (*result >> 0x10);
}

//Read the PID and the Checksum before decrypting the bytes
//Returns void as the bytes pointed by file are directly decrypted
void
decrypt_file(uint8_t *file, int lenght)
{
    unsigned long int pid = file[8]
                            + ( file[9] * my_compute_power(16, 2) )
                            + ( file[10] * my_compute_power(16, 4) )
                            + ( file[11] * my_compute_power(16, 6) );
    //Removing Header
    file = file + 0x0e;
    lenght = lenght - 0x0e;
    //

    unsigned long int checksum = file[1] * (16 * 16) + file[0];
    unsigned long int result = checksum; 
    unsigned short key = 0x0000;
    unsigned short Y = 0x0000;
    union_t u = {0};
    bool changeSeed = false;

    file += 2;
    for ( int i = 0; i < lenght && i < 0xe4; i += 2 ) {
        if ( i >= 0x80 && (changeSeed == false) ) {
            result = pid;
            changeSeed = true;
        }
        PRNG_function(&result, &key);
        Y = (file[i + 1] * (16 * 16) + file[i]);
        u.usi = Y ^ key;
        file[i] = u.hex_array[0];
        file[i + 1] = u.hex_array[1];
    }
}

