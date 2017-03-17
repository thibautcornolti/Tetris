/*
** check.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 17 13:40:26 2017 Thibaut Cornolti
** Last update Fri Mar 17 13:43:26 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "tetris.h"

void		check_game(t_shapes *s)
{
  if (!s)
    {
      my_puterror("Not enough tetriminos!\n");
      exit(84);
    }
  while (s->name)
    {
      if (s->valide)
	return ;
      s += 1;
    }
  my_puterror("Not enough tetriminos!\n");
  exit(84);
}
