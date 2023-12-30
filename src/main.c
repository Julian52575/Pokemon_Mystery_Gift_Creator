/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** main
*/

#include "pokemon_file.h"
#include "lib.h"
#include <stdio.h>

//Alright so you call the libMysteryGift.so from backend/
//

int
main(const int argc, const char **argv)
{
    pokemon_file_t pf = { 0x01 };

    fwrite(&pf, sizeof(pokemon_file_t) ,1, stdout );
    //set_default_values(&pf);
    //update_checksum( (uint8_t *) &pf, sizeof( pokemon_file_t ) );
    return 0;
}
