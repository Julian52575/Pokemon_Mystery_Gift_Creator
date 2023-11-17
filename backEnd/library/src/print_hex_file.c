/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** print_hex_file
*/

#include "lib.h"

void
print_hex_file(unsigned char *file, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        if (i % 16 == 0) {
            printf("\n%x\t:", i); //offset
        } else if (i % 8 == 0) {
            printf("  ");
        }
        printf("%c%c ",
                binary_to_ascii(file[i], 1 ),
                binary_to_ascii(file[i], 2) );
    }
    printf("\n");
}
