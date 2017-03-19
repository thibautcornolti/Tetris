/*
** game_utils.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 17 12:31:23 2017 Thibaut Cornolti
** Last update Sun Mar 19 13:54:23 2017 Bastien
*/

#include <stdlib.h>
#include <time.h>
#include "tetris.h"

int		check_loss(char **tab)
{
  int		i;

  i = -1;
  while (tab && tab[0][++i])
    if ((int)tab[0][i] > 0)
      return (0);
  return (1);
}

void		get_next_piece(t_pos *pos, t_shapes *shapes, t_pars *pars)
{
  int		i;

  srand(time(NULL));
  i = (int)rand() % my_shapeslen(shapes);
  while (!shapes[i].valide || shapes[i].map == NULL)
    i = (int)rand() % my_shapeslen(shapes);
  pos->index = i;
  //pos->x = (pars->col - my_strlen(shapes->map[i])) / 2;
  pos->x = 0;
  pos->y = 0;
  pos->orient = 0;
  pos->map = shapes[i].map;
  pos->color = shapes[i].color;
}

void		rand_next(t_pos *pos, t_shapes *shapes, t_pars *pars)
{
  static t_pos	*next_p;
  t_pos		*temp;

  if (!next_p)
    {
      if ((next_p = malloc(sizeof(t_pos))) == 0)
  	return ;
      get_next_piece(next_p, shapes, pars);
    }
  temp = next_p;
  next_p = pos;
  pos = temp;
  get_next_piece(next_p, shapes, pars);
  draw_next(next_p, NULL);
}

void		apply_map(char **board, t_pos *pos)
{
  int		i;
  int		j;

  i = -1;
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	board[pos->y + i][pos->x + j] = (pos->map[i][j] == -1) ?
	  board[pos->y + i][pos->x + j] : pos->color;
    }
}

void		check_hit(char **board, t_pos *pos)
{
  int		i;
  int		j;

  if (pos->index == -1)
    return ;
  i = -1;
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (board[pos->y + i + 1][pos->x + j] > 0 && pos->map[i][j] > 0)
	  {
	    apply_map(board, pos);
	    pos->index = -1;
	  }
    }
}
