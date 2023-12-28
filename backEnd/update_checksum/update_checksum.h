/*
** EPITECH PROJECT, 2023
** PMMG
** File description:
** update_checksum header
*/

#pragma once
#include <stdint.h>

uint16_t
get_checksum(uint8_t *file, int lenght);

void
update_checksum(uint8_t *file, int lenght);

