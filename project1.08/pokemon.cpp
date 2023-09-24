#include "pokemon.h"
#include "db_parse.h"
#include "poke327.h"
#include <stdlib.h>

// takes in what world position it is
Pokemon::Pokemon()
{
    int i;
    int id = rand() % 1093 + 1;

    this->poke = pokemon[id];

    i = 0;
    do
    {
        i++;
    } while (species[i].id != poke.id);

    this->p_species = species[i];

    i = 0;
    do
    {
        i++;
    } while (pokemon_stats[i].pokemon_id != poke.id);

    int pStat = 0;
    do
    {
        pStat++;
    } while (pokemon_stats[i + pStat].stat_id != 1);

    int base = pokemon_stats[i + pStat].base_stat;

    pStat = 0;
    do
    {
        pStat++;
    } while (pokemon_stats[i + pStat].stat_id != 2);

    base = pokemon_stats[i + pStat].base_stat;

    this->attack = otherStat(base);

    pStat = 0;
    do
    {
        pStat++;
    } while (pokemon_stats[i + pStat].stat_id != 3);

    base = pokemon_stats[i + pStat].base_stat;

    this->defense = otherStat(base);

    pStat = 0;
    do
    {
        pStat++;
    } while (pokemon_stats[i + pStat].stat_id != 4);

    base = pokemon_stats[i + pStat].base_stat;

    this->s_Attack = otherStat(base);

    pStat = 0;
    do
    {
        pStat++;
    } while (pokemon_stats[i + pStat].stat_id != 5);

    base = pokemon_stats[i + pStat].base_stat;

    this->s_Defense = otherStat(base);

    pStat = 0;
    do
    {
        pStat++;
    } while (pokemon_stats[i + pStat].stat_id != 6);

    base = pokemon_stats[i + pStat].base_stat;

    if (rand() % 8192 == 0)
    {
        this->isShiny = true;
    }
    else
    {
        this->isShiny = false;
    }

    if (rand() % 2 == 1)
    {
        this->isFemale = true;
    }
    else
    {
        this->isFemale = false;
    }

    this->speed = otherStat(base);

    this->hp = calcHealth(base);

    this->level = calcLevel();

    this->name = p_species.identifier;
};

int Pokemon::calcHealth(int base)
{
    int iv = rand() % 16;
    return (((((base + iv) * 2) * this->level) / 100) + this->level + 10);
};

int Pokemon::otherStat(int base)
{
    if (base == 0)
        return 0;
    int iv = rand() % 16;
    return ((((base + iv) * 2) * this->level) / 100) + 5;
}

int Pokemon::calcLevel()
{
    int min, max;
    int dist = (abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)) +
                abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)));

    if (dist <= 200)
    {
        min = 1;
        max = dist / 2;
    }
    else
    {
        min = (dist - 200) / 2;
        max = 100;
    }
    if (min < 1)
    {
        min = 1;
    }
    if (min > 100)
    {
        min = 100;
    }
    if (max < 1)
    {
        max = 1;
    }
    if (max > 100)
    {
        max = 100;
    }

    int lvl = rand() % (max - min + 1) + min;
    return lvl;
}