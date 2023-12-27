/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** pokemon_file
*/

#include <stdint.h>

typedef struct pokemon_file_s( scalar_storage_order("big-endian") )
{
    /*          "Header"          */

    uint16_t gift_type;   /*  00 01 for pokemon   */
    uint8_t card_slot;    /*  from Project Pokemon documentation  */
    uint8_t data_specific;    /*  from Project Pokemon documentation  */
    uint32_t a;             /*  Unknow  */
    uint32_t nature_shinyness;   /*  */
    uint16_t b;           /*  Unknow  */
    uint16_t checksum;    /*  Unknow  */

    /*          Pokemon Data            */
    uint16_t dex_number;
    uint16_t item_held;
    uint16_t TID;
    uint16_t SID;
    uint32_t experience_point;
    uint8_t friendship;
    uint8_t ability;
    uint8_t marking;
    uint8_t language_of_origin;

    /*          Effort Values           */
    uint8_t hp_ev;
    uint8_t attack_ev;
    uint8_t defence_ev;
    uint8_t speed_ev;
    uint8_t sp_attack_ev;
    uint8_t sp_defence_ev;
    /*          Contest Values          */
    uint8_t cool;
    uint8_t beauty;
    uint8_t cute;
    uint8_t smart;
    uint8_t tough;
    uint8_t sheen;

    /*          Sinnoh Ribbons 1        */
    uint32_t sinnoh_ribbons_1;  /*  see sinnoh_ribbons_1.h    */
    
    /*          Moves Values            */
    uint16_t move1;
    uint16_t move2;
    uint16_t move3;
    uint16_t move4;

    uint8_t pp1;
    uint8_t pp2;
    uint8_t pp3;
    uint8_t pp4;
    
    uint8_t pp_up1;
    uint8_t pp_up2;
    uint8_t pp_up3;
    uint8_t pp_up4;

    uint32_t individual_value;  /*  Bit 30 = Egg flag;
                                        Bit 31 = Nickname flag   */

    /*          Hoenn Ribbons           */
    uint32_t hoenn_ribbons;     /*  see hoenn_ribbons.h     */

    uint8_t form;             /* Bit 0 = Fateful encounter;
                                       Bit 1&2 = Gender;
                                       Bit 3-7 = Alternate forms */
    uint8_t shiny_leaves;

    uint16_t unused;
    uint16_t platinum_egg_location;
    uint16_t platinum_met_location;

    /*          Nickname                */
    uint16_t nickname[11];    /* see character_encoding.h */
    
    uint8_t unused;

    uint8_t origin_game;

    /*          Sinnoh Ribbons 2         */
    uint32_t sinnoh_ribbons_2;  /* see sinnoh_ribbons_2.h   */

    uint32_t unused2;
    
    /*          Trainer Name             */
    uint16_t trainer_name[8];
} pokemon_file_t;
