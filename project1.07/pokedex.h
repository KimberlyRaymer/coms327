#ifndef POKEDEX_H
#define POKEDEX_H

struct pokemon
{
    int id;
    char identifier[20];
    int species_id;
    int height;
    int weight;
    int base_experience;
    int order;
    int is_default;
};
struct moves
{
    int id;
    char identifier[20];
    int generation_id;
    int type_id;
    int power;
    int pp;
    int accuracy;
    int priority;
    int target_id;
    int damage_class_id;
    int effect_id;
    int effect_chance;
    int contest_type_id;
    int contest_effect_id;
    int super_contest_effect_id;
};
struct pokemon_moves
{
    int pokemon_id;
    int version_group_id;
    int move_id;
    int pokemon_move_method_id;
    int level;
    int order;
};
struct pokemon_species
{
    int id;
    char identifier[20];
    int generation_id;
    int evolves_from_species_id;
    int evolution_chain_id;
    int color_id;
    int shape_id;
    int habitat_id;
    int gender_rate;
    int capture_rate;
    int base_happiness;
    int is_baby;
    int hatch_counter;
    int has_gender_differences;
    int growth_rate_id;
    int forms_switchable;
    int is_legendary;
    int is_mythical;
    int order;
    int conquest_order;
};
struct experience
{
    int growth_rate_id;
    int level;
    int experience;
};
struct type_names
{
    int type_id;
    int local_language;
    char name[20];
};
struct pokemon_stats
{
    int pokemon_id;
    int stat_id;
    int base_stat;
    int effort;
};
struct stats
{
    int id;
    int damage_class_id;
    char identifer[20];
    int is_battle_only;
    int game_index;
};
struct pokemon_types 
{
    int pokemon;
    int type_id;
    int slot;
};

void printData(char filename[50]);

#endif