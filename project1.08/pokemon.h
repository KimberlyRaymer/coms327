#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "db_parse.h"
#include "character.h"
#include <cstdlib>
#include <stdint.h>

class Pokemon
{
public:
    Pokemon();
    std::string name;
    int hp;
    int level;
    int attack;
    int defense;
    int speed;
    int s_Attack;
    int s_Defense;
    bool isShiny;
    bool isFemale;

    pokemon_db poke;
    pokemon_species_db p_species;

    int calcHealth(int base);
    int otherStat(int base);
    int calcLevel();
};

#endif