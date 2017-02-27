/*
** tools.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 27 19:09:51 2017 Thibaut Cornolti
** Last update Mon Feb 27 19:10:57 2017 Thibaut Cornolti
*/

#include "tetris.h"

int		my_shapeslen(t_shapes *s)
{
  int		i;

  i = -1;
  while (s[++i].map);
  return (i);
}
