/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** Library Header
*/

#pragma once

//uint16_t my love <3 <3 <3
#include <stdint.h>
//LibC Include
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

//Lib Prototype
long long int
my_compute_power(int nb, int pow);

//Cooler Lib Prototype
char 
binary_to_ascii(unsigned char c, int half);
char *
my_open_file(const char *file, int *len);
bool
write_in_new_file(unsigned char *content, int lenght, char *new_file_name);
void
print_hex_file(unsigned char *file, int lenght);
bool
compare_hex_array(unsigned char *first, int first_length, 
                    unsigned char *second, int second_length);

//Easy convertion union
typedef union union_s {
    unsigned char hex_array[1];
    unsigned short int usi;
} union_t;

