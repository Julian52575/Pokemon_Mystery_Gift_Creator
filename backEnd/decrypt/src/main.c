/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** main
*/

#include "lib.h"
#include "decrypt.h"

int
main(int ac, char **av)
{
    unsigned char *file = NULL;
    int lenght = 0;

    if (ac < 2)
        return printf("Usage: decrypt {file}.\n");
    file = (unsigned char *) my_open_file(av[1], &lenght);
    if (!file)
        return 84;
    print_hex_file(file, lenght);
    printf("\n...Here is your undecrypted file :\n");
    decrypt_file(file, lenght);
    print_hex_file(file, lenght);
    return 0;
}
