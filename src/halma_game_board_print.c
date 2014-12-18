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
#define couleur(stream,param) fprintf(stream,"\033[%sm",param)


void halma_game_print_stream_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players, FILE * stream)
{
  system("clear");
  if(tab_2d != NULL && tab_2d->tab != NULL)
    {
      for(size_t line=0, column; line < tab_2d->nb_lines; ++line)
	{
	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[0].char_pawn){	
		couleur(stream,"31");
		fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		couleur(stream,"0");
	      }else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[1].char_pawn){	
		couleur(stream,"32");
		fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		couleur(stream,"0");
	      }else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[2].char_pawn){	
		couleur(stream,"34");
		fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		couleur(stream,"0");
	      }else if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == players->tab[3].char_pawn){	
		couleur(stream,"35");
		fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
		couleur(stream,"0");
	      }else{
		fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
	      }
	    }
	  fprintf(stream, "\n");
	}
    }
}

void halma_game_print_stdout_without_grid(const tab_2d_char* tab_2d,const halma_game_players* players)
{
  halma_game_print_stream_without_grid(tab_2d, players, stdout);
}

