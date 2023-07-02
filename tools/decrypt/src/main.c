/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** main
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
char binary_to_ascii(unsigned char c, int half);

typedef union union_s {
    unsigned char hex_array[1];
    unsigned short int usi;
} union_t;

static char *my_open_file(const char *file, int *len)
{
    struct stat sb;
    int fd = 0;
    char *buffer = NULL;

    if (stat(file, &sb) != 0)
        return NULL;
    fd = open( (const char *) file, O_RDONLY);
    if (fd == -1)
        return NULL; 
    *len = sb.st_size;
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (!buffer)
        return NULL;
    buffer[sb.st_size] = '\0';
    if (read(fd, buffer, sb.st_size) == - 1) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

//
static void print_file(unsigned char *file, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        if (i % 16 == 0) {
            printf("\n%x\t:", i); //offset
        } else if (i % 8 == 0) {
            printf("  ");
        }
        printf("%c%c ", binary_to_ascii(file[i], 1 ), binary_to_ascii(file[i], 2) );
    }
    printf("\n");
}


static unsigned short int rand_function(unsigned char *file, int n)
{
    unsigned short int li = file[ n + 1 ] = (0x41C64E6D * file[ n ] + 0x6073);
    return li;
}

static void decrypt_file(unsigned char *file, int lenght, int n)
{
    unsigned short int seed = 0; //signed or not ?
    union_t u = { 0 };
    if ( n >= lenght )
        return;

    //Filling the union
    u.hex_array[1] = file[ n ];
    u.hex_array[0] = file[ n + 1 ];

    printf("File[ %d ]", n);//////////////////////////////
    printf(" _%x_ - _%x_", u.hex_array[1], u.hex_array[0] );
    printf(" | 2Bytes Words : _%x_.\n", u.usi);

    //Getting and applying the seed
    seed = rand_function(file, n);
    u.usi ^= seed;

    //Modifying the file
    file[ n ] = u.hex_array[1];
    file[ n + 1] = u.hex_array[0];

    printf("Seed is _%u_ / _%b_\n", seed, seed);///////////////////////////////
    printf(" | hex is _%x_ / _%b_.\n", u.usi, u.usi);

    //Recursive
    decrypt_file(file, lenght, n + 1);
}

int main(int ac, char **av)
{
    unsigned char *file = NULL;
    int lenght = 0;

    if (ac < 2)
        return printf("Usage: decrypt {file}.\n");
    file = (unsigned char *) my_open_file(av[1], &lenght);
    if (!file)
        return 84;
    printf("Starting decryption\n");
    print_file(file, lenght);//
    decrypt_file(file + 0x10, lenght - 0x10, 0);
    print_file(file, lenght);
    free(file);
    return 0;
}
