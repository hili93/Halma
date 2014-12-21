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
  /* TODO this funnction should only print the board: clear/cls and scores should not be here. */
  
#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
  system("clear");
#elif defined(_WIN32)
  system("cls");
#endif
  halma_game_end(tab_2d, players);
  
  printf("--------------------------------------------------\n\t\t\tMenu:\n--------------------------------------------------\n\tn or next : To move.\n\tnew       : To start a new game.\n\tq or quit : To exit the game.\n\tp or print: To display the game board.\n--------------------------------------------------\n");
  
  puts("Scores:");
  for(signed char i=0; i < players->nb; ++i)
    {
      printf("* Player %hhu '%s': %u\n",
	     i,
	     players->tab[i].name,
	     players->tab[i].score
	     );
    }
  
  printf("--------------------------------------------------\n");
  printf("   ");
  for(unsigned int i=0; i < tab_2d->nb_columns; ++i)
    {
      printf("%2u ", i);
    }
  puts("");
  
  if(tab_2d_char_is_init(tab_2d))
    {
      for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
	{
	  printf("%2u  ", line);

	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[0].char_pawn)
		{
		  fprint_color(stream, "31");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fputc(32, stream);
		  fputc(32, stream);
		  fprint_color(stream, "0");
		}
	      else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[1].char_pawn)
		{
		  fprint_color(stream, "32");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fputc(32, stream);
		  fputc(32, stream);
		  fprint_color(stream, "0");
		}
	      else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[2].char_pawn)
		{
		  fprint_color(stream, "34");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fputc(32, stream);
		  fputc(32, stream);
		  fprint_color(stream, "0");
		}
	      else if(players->nb != 3 && tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[3].char_pawn)
		{
		  fprint_color(stream, "35");
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fputc(32, stream);
		  fputc(32, stream);
		  fprint_color(stream, "0");
		}
	      else
		{
		  fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		  fputc(32, stream);
		  fputc(32, stream);
		}
	    }
	  printf("%2u  ", line);

	  fprintf(stream, "\n");
	}
      printf("   ");
      for(unsigned int i=0; i < tab_2d->nb_columns; ++i)
	{
	  printf("%2u ", i);
	}
      puts("");
    }
}

void halma_game_board_print_stdout_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players)
{
  halma_game_board_print_stream_without_grid(tab_2d, players, stdout);
}