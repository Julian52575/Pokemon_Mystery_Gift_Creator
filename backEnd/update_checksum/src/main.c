/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** main
*/

#include "lib.h"

int
main(int argc, char **argv)
{
    unsigned char *file = NULL;
    int lenght = 0;

    if ( argc != 2 ) {
        printf("Usage:\t./update_checkum\t{pgt file}.\n");
        return 84;
    }
    file = (unsigned char *) my_open_file(argv[1], &lenght);
    update_checksum(file, lenght);
    print_hex_file(file, lenght);
    free(file);
    return 0;
}
