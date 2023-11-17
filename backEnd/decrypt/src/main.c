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

//char 0x00 | short 0x0000
static void
decrypt_file(unsigned char *file, int lenght, unsigned long int pid)
{
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

int
main(int ac, char **av)
{
    unsigned char *file = NULL;
    int lenght = 0;
    unsigned long int pid = 0x00;

    if (ac < 2)
        return printf("Usage: decrypt {file}.\n");
    file = (unsigned char *) my_open_file(av[1], &lenght);
    if (!file)
        return 84;
    print_file(file, lenght);

    pid = file[8]
        + ( file[9] * my_compute_power(16, 2) )
        + ( file[10] * my_compute_power(16, 4) )
        + ( file[11] * my_compute_power(16, 6) );
    fprintf(stderr, "Pid _%8lx_ | File[8] _%x_ File[11] _%x_.\n", pid, file[8], file[11]);//
    fprintf(stderr, "Compute power 16^6 _%lld_ 16^2 _%lld_.\n",
            my_compute_power(16, 6),
            my_compute_power(16, 2)
            );//
    decrypt_file(file + 0x0e, lenght - 0x0e, pid);
    print_file(file, lenght);
    return 0;
}
