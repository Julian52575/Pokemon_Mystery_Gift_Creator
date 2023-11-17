/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_open_file
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char *my_open_file(const char *file, int *len)
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
