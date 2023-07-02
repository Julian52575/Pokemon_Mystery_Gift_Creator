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
static void print_file(char *file, int lenght)
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

static void xor_file(char *file, int lenght, int key)
{
    for (int i = 0; i < lenght; i++) {
        file[i] ^= key;
    }
}

int main(int ac, char **av)
{
    char *file = NULL;
    int lenght = 0;

    if (ac < 3)
        return printf("Usage: hexxor {file} {key}.\n");
    file = my_open_file(av[1], &lenght);
    if (!file)
        return 84;
    xor_file(file, lenght, atoi(av[2]) );
    print_file(file, lenght);
    return 0;
}
