/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** main
*/

#include "lib.h"
#include "update_checksum.h"

int
main(int argc, char **argv)
{
    uint8_t *file = NULL;
    int lenght = 0;

    if ( argc != 2 ) {
        printf("Usage:\t./update_checkum\t{pgt file}.\n");
        return 84;
    }
    file = (uint8_t *) my_open_file(argv[1], &lenght);
    update_checksum(file, lenght);
    print_hex_file(file, lenght);
    write_in_new_file(file, lenght, "New_Checksum.pgt");
    free(file);
    return 0;
}
