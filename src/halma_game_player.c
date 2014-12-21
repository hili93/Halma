/**
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


#include "halma_game_player.h"


bool halma_game_player_has_a_name(const halma_game_player* player)
{
  return player != NULL && player->name != NULL && strlen(player->name);
}

bool halma_game_player_set_name(halma_game_player* player, const char* new_name)
{
  if(player == NULL)
    return false;
  
  if(player->name != NULL)
    free(player->name);

  player->name = (char*) malloc(sizeof(char) * (strlen(new_name) +1));
  strcpy(player->name, new_name);
  string_trim(player->name, ' ');
  return strlen(player->name);
}

bool halma_game_player_is_possible_char_pawn(char pawn_char)
{
  return
    pawn_char != '\0' && pawn_char != '\n' &&
    pawn_char != HALMA_GAME_CELL_EMPTY && pawn_char != HALMA_GAME_CELL_MARK;
}

bool halma_game_player_set_char_pawn(halma_game_player* player, char new_pawn)
{
  if(player != NULL && halma_game_player_is_possible_char_pawn(new_pawn))
    {
      player->char_pawn = new_pawn;
      return true;
    }
  return false;
}

bool halma_game_player_is_init(const halma_game_player* player)
{
  return
    halma_game_player_has_a_name(player) &&
    halma_game_player_is_possible_char_pawn(player->char_pawn) &&
    player->choose_move != NULL;
}

bool halma_game_player_init(halma_game_player* player, const char* name, char pawn_char, halma_game_player_choose_move choose_move)
{
  if(player == NULL)
    return false;
  
  player->choose_move = choose_move;
  return
    halma_game_player_set_name(player, name) &&
    halma_game_player_set_char_pawn(player, pawn_char) &&
    player->choose_move != NULL;
}

void halma_game_player_destruct(halma_game_player* player)
{
  if(player != NULL)
    {
      if(player->name != NULL)
	{
	  free(player->name);
	  player->name = NULL;
	}
      player->char_pawn = HALMA_GAME_CELL_MARK;
    }
}
