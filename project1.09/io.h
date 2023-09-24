#ifndef IO_H
#define IO_H

#include "character.h"
#include "poke327.h"
#include "pokemon.h"

class character;

void io_init_terminal(void);
void io_reset_terminal(void);
void io_display(void);
void io_handle_input(pair_t dest);
void io_queue_message(const char *format, ...);
void io_battle(character *aggressor, character *defender);
void io_encounter_pokemon();
void io_choose_starter();

void io_trainer(npc *npc);
void io_pokemonBattle(pokemon *p);
void io_backpack(int inBattle);
void io_getItem(int numItem);

#endif
