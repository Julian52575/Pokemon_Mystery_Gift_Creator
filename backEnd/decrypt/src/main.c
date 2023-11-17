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
char *my_open_file(const char *file, int *len);

typedef union union_s {
    unsigned char hex_array[1];
    unsigned short int usi;
} union_t;

static void
save_file(unsigned char *file, int lenght, char *file_name)
{
    int fd = 0;

    fd = creat( (const char *) file_name,// O_CREAT | O_WRONLY,
            S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (void) fprintf(stderr, "Cannot open file.\n");
    if ( write(fd, file, lenght) <= 0 )
        return (void) fprintf(stderr, "Cannot write in file.\n");
    close(fd);
    return;
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

static unsigned long int
PRNG_call(unsigned long int seed)
{
    return (0x41C64E6Du * seed + 0x00006073u);
}

static void 
PRNG_function(unsigned long int *result, unsigned short *key)
{
    *result = PRNG_call(*result);
    *key = (unsigned short) (*result >> 0x10);
}

//char 0x00 | short 0x0000
static void
decrypt_file(unsigned char *file, int lenght, unsigned long int pid)
{
    unsigned long int checksum = file[1] * (16 * 16) + file[0];
    unsigned long int result = checksum; 
    unsigned short key = 0x0000;
    unsigned short Y = 0x0000;
    union_t u = {0};
    bool changeSeed = false;


    printf("\nStarting decryption with checksum _%4lx_ | Pid _%12lx_\n", checksum, pid);
    //fprintf(stderr, "Checksum is _%8x_ || PRNG is _%8x_ | _%32b_\n", checksum, key, key);///
    file += 2;
 
    for ( int i = 0; i < lenght && i < 0xe4; i += 2 ) {
        if ( i >= 0x80 && (changeSeed == false) ) {
            //fprintf(stderr, "Changing seed at i _%d_ | file[i] _%2x__%2x_.\n", i, file[i], file[i + 1]);
            result = pid;
            changeSeed = true;
        }
        //fprintf(stderr, "After PRNG call : file[i] _%2x_ ^ key _%2x_ | result _%x_.\n", file[i], key, result);
        PRNG_function(&result, &key);
        Y = (file[i + 1] * (16 * 16) + file[i]);
        u.usi = Y ^ key;
        file[i] = u.hex_array[0];
        file[i + 1] = u.hex_array[1];
        //fprintf(stderr, "Key _%4x_ ^ Y _%4x_ = usi _%4x_ | File _%2x_%2x_.\n", key, Y, u.usi, file[i], file[i + 1] );
    }
}

int
main(int ac, char **av)
{
    unsigned char *file = NULL;
    int lenght = 0;
    unsigned long int pid = 0x00000000;

    if (ac < 2)
        return printf("Usage: decrypt {file}.\n");
    file = (unsigned char *) my_open_file(av[1], &lenght);
    if (!file)
        return 84;
    print_file(file, lenght);//

    pid = file[0] + (file[1] * (16 * 16)) + (file[2] * (16 * 16 * 16)) + (file[3] * (16 * 16 * 16 * 16) );
    decrypt_file(file + 0x0e, lenght - 0x0e, pid);
    print_file(file, lenght);
    save_file(file, lenght, "decryptedFile");
    free(file);
    return 0;
}
