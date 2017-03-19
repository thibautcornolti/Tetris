/*
** game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 16:42:04 2017 Bastien
** Last update Sun Mar 19 16:44:42 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/timeb.h>
#include "tetris.h"

void	init_board(char ***board, t_pars *pars, t_pos *pos, int *count)
{
  int	i;
  int	j;

  i = -1;
  if (((*board) = malloc(sizeof(char *) * (pars->row + 1))) == NULL)
    return ;
  while (++i < pars->row)
    {
      j = -1;
      if (((*board)[i] = malloc(sizeof(char) *
				(pars->col + 1))) == NULL)
	return ;
      while (++j < pars->col)
	(*board)[i][j] = -1;
      (*board)[i][j] = 0;
    }
  (*board)[pars->row] = NULL;
  my_memset(pos, 0, sizeof(t_pos));
  *count = 400;
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

int	falling_time(char **board, t_pos *pos, t_game *game, t_pars *pars)
{
  falling_shapes(board, pos);
  display(board, pos, game, pars);
  usleep(1000);
  return (0);
}

void	one_turn(int *count, t_game *game)
{
  *count += game->level;
  usleep(1000);
}

void	game(t_shapes *shapes, t_pars *pars, t_game *game)
{
  char	**board;
  t_pos	pos;
  int	action;
  int	count;

  init_board(&board, pars, &pos, &count);
  while (check_loss(board))
    {
      rand_next(&pos, shapes);
      while (pos.index != -1)
	{
	  if ((action = get_action(pars)))
	    {
	      if (my_pause(game, action))
		if (apply_action(action, board, &pos, shapes))
		  return ;
	      display(board, &pos, game, pars);
	    }
	  if (count >= 400 && !game->pause.paused)
	    count = falling_time(board, &pos, game, pars);
	  while (check_fulline(board, game))
	    display(board, &pos, game, pars);
	  one_turn(&count, game);
	}
    }
}
