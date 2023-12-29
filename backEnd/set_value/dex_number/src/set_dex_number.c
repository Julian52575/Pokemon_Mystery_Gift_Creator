/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** set_dex_number
*/

#include "pokemon_file.h"
#define ARCEUS_NUMBER 493
//update the dex number in the pokemon_file_t structure
//return true if the dex number is valid

bool
set_dex_number(pokemon_file_t *pf, uint16_t dex_number)
{
    if ( dex_number <= ARCEUS_NUMBER ) {
        pf->dex_number = dex_number;
        return true;
    }
    return false;
}
