/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** Library Header
*/

#pragma once

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
char 
binary_to_ascii(unsigned char c, int half);
char *
my_open_file(const char *file, int *len);
void
print_file(unsigned char *file, int lenght);
long long int
my_compute_power(int nb, int pow);

//Easy convertion union
typedef union union_s {
    unsigned char hex_array[1];
    unsigned short int usi;
} union_t;

