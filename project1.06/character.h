#ifndef CHARACTER_H
# define CHARACTER_H

# include <stdint.h>

# include "poke327.h"

class Map;
class Character;

// typedef struct npc {
//   character_type_t ctype;
//   movement_type_t mtype;
//   int defeated;
//   pair_t dir;
// } npc_t;

// typedef struct pc {
// } pc_t;

/* character is defined in poke327.h to allow an instance of character
 * in world without including character.h in poke327.h                 */

int32_t cmp_char_turns(const void *key, const void *with);
void delete_character(void *v);
void pathfind(Map *m);

int pc_move(char);

#endif
