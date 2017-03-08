/*
** game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 16:42:04 2017 Bastien
** Last update Wed Mar  8 17:38:49 2017 Bastien
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/timeb.h>
#include "tetris.h"

int	check_loss(char **tab)
{
  int	i;

  i = -1;
  while (tab && tab[0][++i])
    if ((int)tab[0][i] > 0)
      return (0);
  return (1);
}

void	init_board(char ***board, t_pars *pars)
{
  int	i;
  int	j;

  i = -1;
  if (((*board) = malloc(sizeof(char *) * (pars->row + 1))) == NULL)
    return ;
  while (++i < pars->row)
    {
      j = -1;
      if (((*board)[i] = malloc(sizeof(char) * (pars->col + 1))) == NULL)
	return ;
      while (++j < pars->col)
	(*board)[i][j] = -1;
      (*board)[i][j] = 0;
    }
  (*board)[pars->row] = NULL;
}

void	rand_next(t_pos *pos, t_shapes *shapes, t_pars *pars)
{
  int	i;

  srand(time(NULL));
  i = (int)rand() % my_shapeslen(shapes);
  while (!shapes[i].valide || shapes[i].map == NULL)
    i = (int)rand() % my_shapeslen(shapes);
  pos->index = i;
  pos->x = (pars->col - my_strlen(shapes->map[i])) / 2;
  pos->y = 0;
  pos->orient = 0;
  pos->map = shapes[i].map;
  pos->color = shapes[i].color;
}

void	apply_map(char **board, t_pos *pos)
{
  int	i;
  int	j;

  i = -1;
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (pos->map[i][j] != -1)
	  board[pos->y + i][pos->x + j] = pos->map[i][j];
    }

  return ;  
}

void	check_hit(char **board, t_pos *pos)
{

  int	i;
  int	j;

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

void	falling_shapes(char **board, t_pos *pos)
{
  int	i;

  i = -1;
  pos->index = (my_strlen(pos->map[0]) + pos->x >
		my_strlen(board[0])) ? -1 : pos->index;
  pos->index = (my_tablen(pos->map) + pos->y >
		my_tablen(board)) ? -1 : pos->index;
  while (pos->index != -1 && pos->map[++i + 1]);
  if (!board[pos->y + i + 1] && !pos->map[i + 1])
    {
      apply_map(board, pos);
      pos->index = -1;
    }
  if (pos->index != -1)
    check_hit(board, pos);
  pos->y = (pos->index == -1) ? pos->y : pos->y + 1;
}

void	game(t_shapes *shapes, t_pars *pars, t_game *game)
{
  char	**board;
  t_pos	pos;
  int	action;
  struct timeb tp;

  init_board(&board, pars);
  memset(&pos, 0, sizeof(t_pos));
  while (check_loss(board))
    {
      rand_next(&pos, shapes, pars);
      while (pos.index != -1)
	{
	  if ((action = get_action(pars)))
	    {
	      if (apply_action(action, board, &pos, shapes))
		return ;
	      display(board, &pos, game, pars);
	    }
	  if (!ftime(&tp) && tp.millitm == 500)
	    {
	      falling_shapes(board, &pos);
	      display(board, &pos, game, pars);
	      usleep(1000);
	    }
	  while (check_fulline(board))
	    display(board, &pos, game, pars);
	}
    }
  //TODO : Loss fct
}
