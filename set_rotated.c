/*
** set_rotated.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Feb 23 21:45:45 2017 Bastien
** Last update Tue Mar  7 14:36:25 2017 Bastien
*/

#include <stdlib.h>
#include "tetris.h"

void	rotate_down(t_shapes *piece)
{
  int	i;
  int	j;
  int	k;
  int	v;

  i = -1;
  k = piece->height;
  if ((piece->map_down = malloc(sizeof(char *) *
				(piece->height + 1))) == NULL)
    return ;
  piece->map_down[k] = NULL;
  while (--k >= 0 && piece->map[k])
    {
      j = piece->width;
      v = -1;
      if ((piece->map_down[++i] = malloc(sizeof(char) *
					 (piece->width + 1))) == NULL)
  	return ;
      while (--j >= 0)
  	piece->map_down[i][++v] = piece->map[k][j];
      piece->map_down[i][++v] = '\0';
    }
}

void	rotate_left(t_shapes *piece)
{
  int   j;
  int   k;
  int   v;
  int   w;

  k = piece->width;
  v = 0;
  if ((piece->map_left = malloc(sizeof(char *) *
				(piece->width + 1))) == NULL)
    return ;
  piece->map_left[piece->width] = NULL;
  while (--k >= 0)
    {
      j = -1;
      w = -1;
      if ((piece->map_left[v] = malloc(sizeof(char) *
				       (piece->height + 1))) == NULL)
	return ;
      piece->map_left[v][piece->height] = '\0';
      while (++j < piece->height)
	piece->map_left[v][++w] = piece->map[j][k];
      v++;
    }
  rotate_down(piece);
}

void	rotate_right(t_shapes *piece)
{
  int	j;
  int	k;
  int	v;
  int	w;

  k = -1;
  v = 0;
  if (piece->map == NULL)
    return ;
  if ((piece->map_right = malloc(sizeof(char *) *
				 (piece->width + 1))) == NULL)
    return ;
  piece->map_right[piece->width] = NULL;
  while (++k < piece->width)
    {
      j = -1;
      w = piece->height;
      if ((piece->map_right[v] = malloc(sizeof(char) *
					(piece->height + 1))) == NULL)
  	return ;
      piece->map_right[v][piece->height] = '\0';
      while (++j < piece->height)
  	piece->map_right[v][--w] = piece->map[j][k];
      v++;
    }
  rotate_left(piece);
}
