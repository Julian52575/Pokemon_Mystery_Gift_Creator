/*
** RULIAN PROJECT, 2023
** PMMG
** File description:
** set_default_values
*/

#include "pokemon_file.h"

void
set_default_values(pokemon_file_t *pf)
{
    /*      Set all values to 0x01      */
    (*pf) = {0x01};

    /*      Modify values that need to be different     */
    pf->move2 = 0x02;
    pf->move3 = 0x03;
    pf->move4 = 0x04;

    /*      Modify values that cannot be 0x01     */
    pf->form = 0x00;
    pf->shiny_leave = 0x00;
    pf->origin_game = 0x0F; //Colosseum / XD

    /*      Set name values     */
    pf->nickname[0] = 0xFF; //wip
    pf->trainer_name[0] = 0xFF; //wip
}
