/*
** RULIAN PROJECT, 2023
** PMGG
** File description:
** pokemon_file
*/

typedef struct pokemon_file_s( scalar_storage_order("big-endian") )
{
    /*          "Header"          */

    unsigned short gift_type;   /*  00 01 for pokemon   */
    unsigned char card_slot;    /*  from Project Pokemon documentation  */
    unsigned char data_specific;    /*  from Project Pokemon documentation  */
    unsigned int a;             /*  Unknow  */
    unsigned int nature_shinyness;   /*  */
    unsigned short b;           /*  Unknow  */
    unsigned short checksum;    /*  Unknow  */

    /*          Pokemon Data            */
    unsigned short dex_number;
    unsigned short item_held;
    unsigned short TID;
    unsigned short SID;
    unsigned int   experience_point;
    unsigned char friendship;
    unsigned char ability;
    unsigned char marking;
    unsigned char language_of_origin;

    /*          Effort Values           */
    unsigned char hp_ev;
    unsigned char attack_ev;
    unsigned char defence_ev;
    unsigned char speed_ev;
    unsigned char sp_attack_ev;
    unsigned char sp_defence_ev;
    /*          Contest Values          */
    unsigned char cool;
    unsigned char beauty;
    unsigned char cute;
    unsigned char smart;
    unsigned char tough;
    unsigned char sheen;

    /*          Sinnoh Ribbons 1        */
    unsigned int sinnoh_ribbons_1;  /*  see sinnoh_ribbons_1.h    */
    
    /*          Moves Values            */
    unsigned short move1;
    unsigned short move2;
    unsigned short move3;
    unsigned short move4;

    unsigned char pp1;
    unsigned char pp2;
    unsigned char pp3;
    unsigned char pp4;
    
    unsigned char pp_up1;
    unsigned char pp_up2;
    unsigned char pp_up3;
    unsigned char pp_up4;

    unsigned int individual_value;  /*  Bit 30 = Egg flag;
                                        Bit 31 = Nickname flag   */

    /*          Hoenn Ribbons           */
    unsigned int hoenn_ribbons;     /*  see hoenn_ribbons.h     */

    unsigned char form;             /* Bit 0 = Fateful encounter;
                                       Bit 1&2 = Gender;
                                       Bit 3-7 = Alternate forms */
    unsigned char shiny_leaves;

    unsigned short unused;
    unsigned short platinum_egg_location;
    unsigned short platinum_met_location;

    /*          Nickname                */
    unsigned short nickname[11];    /* see character_encoding.h */
    
    unsigned char unused;

    unsigned char origin_game;

    /*          Sinnoh Ribbons 2         */
    unsigned int sinnoh_ribbons_2;  /* see sinnoh_ribbons_2.h   */

    unsigned int unused2;
    
    /*          Trainer Name             */
    unsigned short trainer_name[8];
} pokemon_file_t;
