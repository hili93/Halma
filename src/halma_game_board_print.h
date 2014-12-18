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


#ifndef HALMA_GAME_BOARD_PRINT_H
#define HALMA_GAME_BOARD_PRINT_H


#include <stdio.h>
#include "tab_2d_char_essential.h"
#include "halma_game_players.h"


/**
 * Print a 2D table of char not in a grid to a stream.
 * @param stream A stream
 * @param players a table of players
 * @param tab_2d A pointer of a 2D table of char
 */
void halma_game_print_stream_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players, FILE * stream);

/**
 * Print a 2D table of char not in a grid to stdout.
 * @param tab_2d A pointer of a 2D table of char
 * @param players a table of players
 */
void halma_game_print_stdout_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players);


#endif
