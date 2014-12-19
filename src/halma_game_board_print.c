/**
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
 *
 * @author Spanti Nicola (RyDroid)
 */


#include "halma_game_board_print.h"


#define fprint_color(stream, param) fprintf(stream,"\033[%sm", param)
/* TODO define macros for color */


void halma_game_board_print_stream_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players, FILE * stream)
{
#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
  system("clear");
#elif defined(_WIN32)
  system("cls");
#endif
  halma_game_end(tab_2d,players);
  printf("--------------------------------------------------\n\t\t\tMenu:\n--------------------------------------------------\n\tn or next : To move.\n\tnew       : To start a new game.\n\tq or quit : To exit the game.\n\tp or print: To display the game board.\n--------------------------------------------------\n");
  printf("Scores:\n Player -%s-:%d\n",players->tab[0].name,players->tab[0].score);
	printf(" Player -%s-:%d\n",players->tab[1].name,players->tab[1].score);
	printf(" Player -%s-:%d\n",players->tab[2].name,players->tab[2].score);
	if(players->nb !=3){
		printf(" Player -%s-:%d\n",players->tab[3].name,players->tab[3].score);
	}
  if(tab_2d != NULL && tab_2d->tab != NULL)
    {
      for(size_t line=0, column; line < tab_2d->nb_lines; ++line)
	{
	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[0].char_pawn)
		{
		  fprint_color(stream, "31");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fprint_color(stream, "0");
		}
	      else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[1].char_pawn)
		{
		  fprint_color(stream, "32");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fprint_color(stream, "0");
		}
	      else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[2].char_pawn)
		{
		  fprint_color(stream, "34");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fprint_color(stream, "0");
		}
	      else if(players->nb != 3 && tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[3].char_pawn)
		{
		  fprint_color(stream, "35");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fprint_color(stream, "0");
		}
	      else
		{
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		}
	    }
	  fprintf(stream, "\n");
	}
    }
}

void halma_game_board_print_stdout_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players)
{
  halma_game_board_print_stream_without_grid(tab_2d, players, stdout);
}
