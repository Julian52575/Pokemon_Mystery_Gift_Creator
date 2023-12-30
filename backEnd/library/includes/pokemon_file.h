/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** pokemon_file
*/

#include <stdint.h>

struct __attribute__((packed, scalar_storage_order("big-endian"))) pokemon_file_s {
    /*          "Header"          */

    uint16_t gift_type;   /*  00 01 for pokemon   */
    uint8_t card_slot;    /*  from Project Pokemon documentation  */
    uint8_t data_specific;    /*  from Project Pokemon documentation  */
    uint32_t a;             /*  Unknow  */
    uint32_t nature_shinyness;   /*  */
    uint16_t b;           /*  Unknow  */
    uint16_t checksum;    /*  dear god  */

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

    uint32_t individual_value;  /* IVs
                                    Bit 30 = Egg flag;
                                        Bit 31 = Nickname flag   */

    /*          Hoenn Ribbons           */
    uint32_t hoenn_ribbons;     /*  see hoenn_ribbons.h     */

    uint8_t form;             /* Bit 0 = Fateful encounter;
                                       Bit 1&2 = Gender;
                                       Bit 3-7 = Alternate forms */
    uint8_t shiny_leaves;

    uint16_t unused;
    uint16_t egg_location;
    uint16_t met_location;

    /*          Nickname                */
    uint16_t nickname[11];    /* see character_encoding.h */
    
    uint8_t unused2;

    uint8_t origin_game;

    /*          Sinnoh Ribbons 2         */
    uint32_t sinnoh_ribbons_2;  /* see sinnoh_ribbons_2.h   */

    uint32_t unused3;
    
    /*          Trainer Name             */
    uint16_t trainer_name[8];
     
    /*          Date                    */
    uint8_t egg_year;
    uint8_t egg_month;
    uint8_t egg_day;

    uint8_t met_year;
    uint8_t met_month;
    uint8_t met_day;

    /*          Old location        */
    uint16_t egg_location_old;
    uint16_t met_location_old;

    uint8_t pokerus;
    uint8_t pokeball;
    uint8_t met_level_ot_gender;
    uint8_t c;  /* unused */
    uint8_t hgss_pokeball;
    uint8_t d;  /* unused */
    uint8_t status;
    uint8_t e;  /* unused */
    uint16_t f; /* unused */
    uint8_t level;

    uint8_t seal;
    
    /* All of the following data will be replaced by the game once received */
    /*  On top of being ignored for the checksum calculation     */
    /*  And working despite a modified encryption   */
    uint16_t current_hp;
    uint16_t current_atk;

};
typedef struct pokemon_file_s pokemon_file_t;
