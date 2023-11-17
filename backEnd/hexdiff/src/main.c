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

char binary_to_ascii(unsigned char c, int half);

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */

static bool my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return false;
    }
    if (s1[i] != s2[i])
        return false;
    return true;
}

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

void compare_hexs(char *one, char *two, bool *difference_array, int max_lenght, int len1, int len2)
{
    int i = 0;
    for (; i < len1 && i < len2; i++) {
        if (one[i] == two[i])
            difference_array[i] = true;
        else
            difference_array[i] = false;
    }
    for (; i < max_lenght; i++)
        difference_array[i] = false;
}

void print_ascii_line(char *file, bool *difference_array, int i, int max_lenght)
{
    int x = 0;

    for (; x < 16 && i + x < max_lenght; x++) {
        if (x == 8)
            printf("  ");
        if ( file[i + x] >= 31 ) {

            if (difference_array[i + x] == true)
                printf( GREEN " %c " RESET, file[i + x] );
            else
                printf( RED " %c " RESET, file[i + x] );

        } else
            printf(" . ");
    }
    for(; x < 16; x++)
        printf( "   " );
}

void print_hex_line(char *file, bool *difference_array, int i, int max_lenght)
{
    int x = 0;

    for (; x < 16 && i + x < max_lenght; x++) {
        if (x == 8)
            printf("  ");

        if ( file[i + x] == -1 ) {
            printf(RESET "FF ");
            continue;
        }

        if (difference_array[i + x] == true)
            printf(GREEN "%c%c " RESET, binary_to_ascii(file[i + x], 1), binary_to_ascii(file[i + x], 2) );
        else
            printf(RED "%c%c " RESET, binary_to_ascii(file[i + x], 1), binary_to_ascii(file[i + x], 2) );
    }

    for(; x < 16; x++)
        printf( "__ " );
}

void print_difference(char *one, char *two, bool *difference_array, int max_lenght, bool ascii)
{
    for (int i = 0; i < max_lenght - 1; i += 16) {
        printf("%02x\t:", i); //OFFSET
        print_hex_line(one, difference_array, i, max_lenght);
        printf(BOLDYELLOW "\t||\t" RESET);
        print_hex_line(two, difference_array, i, max_lenght);
        printf("\n");

        if (!ascii)
            continue;
        printf("\t");
        print_ascii_line(one, difference_array, i, max_lenght);
        printf(BOLDYELLOW "\t||\t" RESET);
        print_ascii_line(two, difference_array, i, max_lenght);
        printf("\n"); 
    }
}

int main(int ac, char **av)
{
    char *one = NULL;
    char *second = NULL;
    bool *difference_array = NULL;
    int len1 = 0;
    int len2 = 0;
    int max_lenght = 0;
    bool ascii = false;

    if (ac < 3)
        return 84;
    for (int i = 0; i < ac; i++)
        if (my_strcmp(av[i], "-a") == true)
            ascii = true;

    one = my_open_file(av[1 + ascii], &len1);
    if (!one)
        return 84;
    second = my_open_file(av[2 + ascii], &len2);
    if (!second)
        return 84;

    max_lenght = (len1 > len2 ? len1 : len2);
    difference_array = malloc(sizeof(bool) * max_lenght);
    compare_hexs(one, second, difference_array, max_lenght, len1, len2);
    printf(BOLDYELLOW "\t\t\t%s\t\t\t\t\t\t\t%s\n" RESET, av[1 + ascii], av[2 + ascii]);
    print_difference(one, second, difference_array, max_lenght, ascii);
    free(one);
    free(second);
    free(difference_array);
    return 0;
}
