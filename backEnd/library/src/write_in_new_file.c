/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** write_in_new_file
*/

#include "lib.h"

bool
write_in_new_file(unsigned char *content, int lenght, char *new_file_name)
{
    int fd = 0;

    fd = creat( (const char *) new_file_name,// O_CREAT | O_WRONLY,
            S_IRUSR | S_IWUSR);
    if (fd == -1) {
        fprintf(stderr, "Cannot open file.\n");
        return false;
    }
    if ( write(fd, content, lenght) <= 0 ) {
        fprintf(stderr, "Cannot write in file.\n");
        return false;
    }
    close(fd);
    return true;
}
