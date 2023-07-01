/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char *my_open_file(const char *file, int *len);

typedef union u_s {
    unsigned char uc[2];
    unsigned short us; 
} u;

static unsigned short get_file_checksum(unsigned char *file)
{

    return file[0x0e] + (file[0x0f] * (16 * 16) );
}

static void fill_diff_array(unsigned char *og_file, unsigned char *new_file,
        char *diff_array, int len)
{
    for (int i = 0; i < len; i++) {
        diff_array[ i ] = ( og_file[ i ] - new_file[ i ] );
    }
}

static unsigned short diff_array_to_checksum(char *diff_array, int len,
        unsigned short og_checksum)
{
    for (int i = 0; i < len; i++) {
        og_checksum -= diff_array[ i ];
    }
    return og_checksum;
}

static void write_new_checksum(char *file_name, char *new_file, int len,
        unsigned short new_checksum )
{
    FILE *fd = fopen(file_name, "w+");
    u my_union = {0};
    my_union.us = new_checksum;

    fwrite( new_file, sizeof(char), 0x0e, fd );
    fwrite( &my_union.uc[0], sizeof(char), 0x01, fd );
    fwrite( &my_union.uc[1], sizeof(char), 0x01, fd );
    new_file += 0x10;
    fwrite( new_file, sizeof(char), len - 0x10, fd );
}

int main(int ac, char **av)
{
    char *og_file = NULL;
    char *new_file = NULL;
    int len = 0;
    unsigned short og_checksum = 0x00;
    unsigned short new_checksum = 0x00;
    char *diff_array = NULL;

    if (ac != 3)
        return 84 + (printf("Usage:\t./update_checksum <og_PGT_file> <new_PGT_file>\tNote: the new file will be rewritten\n") * 0);

    og_file = (unsigned char *) my_open_file(av[1], &len);
    if (!og_file)
        return 84;

    new_file = (unsigned char *) my_open_file(av[2], &len);
    if (!new_file)
        return 84;

    og_checksum = get_file_checksum(og_file);
    diff_array = malloc( sizeof(char) * (len) );

    fill_diff_array(og_file + 0x10, new_file + 0x10, diff_array, len - 0x10);
    new_checksum = diff_array_to_checksum( diff_array, len, og_checksum );

    write_new_checksum(av[2], new_file, len, new_checksum);

    printf("Old File checksum is _%x_ | New is _%x_\n", og_checksum, new_checksum);
    free(og_file);
    free(new_file);
    free(diff_array);
    
    return 0;
}
