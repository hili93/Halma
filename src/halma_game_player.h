/**
 * @file
 * 
 * @section license License
 * 
 * Copyright (C) 2014  Spanti Nicola (RyDroid) <rydroid_dev@yahoo.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef HALMA_GAME_PLAYER_H
#define HALMA_GAME_PLAYER_H


#include "bool.h"
#include "string_functions.h"
#include "halma_game_essential.h"


typedef struct halma_game_player halma_game_player;

/**
 * A player of Halma game.
 */
struct halma_game_player
{
  /**
   * The name of a player of Halma game.
   */
  char* name;
  
  /**
   * The pawn character of a player of Halma game.
   * It must not be an empty or a mark character.
   */
  char char_pawn;
};


/**
 * Returns true if a player has a name, otherwise false.
 * @param player A Halma game player
 * @return True if a player has a name, otherwise false
 */
bool halma_game_player_has_a_name(const halma_game_player* player);

/**
 * Set a name of a Halma game player.
 * @param player A Halma game player
 * @param new_name New name of the player
 * @return True if the player has the new name, otherwise false
 */
bool halma_game_player_set_name(halma_game_player* player, const char* new_name);

/**
 * Returns true if a pawn character is possible for a Halma game player, otherwise false.
 * @param new_paw A potential pawn character of a player
 * @return True if a pawn character is possible for a Halma game player, otherwise false
 */
bool halma_game_player_is_possible_char_pawn(char pawn_char)
#ifndef __GNUC__
#define  __attribute__((const))
#endif
;

/**
 * Set a character pawn of a Halma game player.
 * @param player A Halma game player
 * @param new_paw New pawn character of the player
 * @return True if the player has the new pawn character, otherwise false
 */
bool halma_game_player_set_char_pawn(halma_game_player* player, char new_pawn);

/**
 * Returns true if a player is initialized, otherwise false.
 * @param player A Halma game player
 * @return True if a player is initialized, otherwise false
 */
bool halma_game_player_is_init(const halma_game_player* player);

/**
 * Initialize a Halma game player.
 * @param player A Halma game player
 * @param new_name New name of the player
 * @param new_paw New pawn character of the player
 * @return True if the player is initialized, otherwise false
 */
bool halma_game_player_init(halma_game_player* player, const char* name, char pawn_char);

/**
 * Destruct a Halma game player (dynamic allocation, etc).
 * @param player A Halma game player
 */
void halma_game_player_destruct(halma_game_player* player);

#endif
