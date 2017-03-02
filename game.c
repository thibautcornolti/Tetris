/*
** game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 16:42:04 2017 Bastien
** Last update Thu Mar  2 14:34:50 2017 Bastien
*/

#include <stdlib.h>
#include <time.h>
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
  i = (int)rand()%my_shapeslen(shapes);
  while (shapes[i].map == NULL)
    i = (int)rand()%my_shapeslen(shapes);
  pos->index = i;
  pos->x = (pars->col - my_strlen(shapes->map[i])) / 2;
  pos->y = 0;
  pos->orient = 0;
  pos->map = shapes[i].map;
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
	board[pos->y + i][pos->x + j] = pos->map[i][j];
    }
  printf("oui\n");
  return ;  
}

void	check_hit(char **board, t_pos *pos)
{

  int	i;
  int	j;

  if (pos->index == -1)
    return ;
  i = -1;
  j = -1;
  while (pos->map[++i]);
  i -= 1;
  while (pos->map[i][++j])
    if (board[pos->y + i + 1][pos->x + j] > 0 && pos->map[i][j] > 0)
      {
	apply_map(board, pos);
	pos->index = -1;
      }
}

void	falling_shapes(char **board, t_pos *pos)
{
  int	i;
  int	j;

  i = -1;
  pos->index = (my_strlen(pos->map[0]) + pos->x >
		my_strlen(board[0])) ? -1 : pos->index;
  pos->index = (my_tablen(pos->map) + pos->y >
		my_tablen(board)) ? -1 : pos->index;
  while (pos->index != -1 && pos->map[++i])
    {
      j = -1;
      while (pos->index != -1 && pos->map[i][++j])
	{
	  if (!board[pos->y + i + 1] && !pos->map[i + 1])
	    {
	      apply_map(board, pos);
	      pos->index = -1;
	    }
	  else if (pos->map[i][j] > 0 && board[pos->y + i][pos->x + j] > 0)
	    pos->index = -1;
	}
    }
  check_hit(board, pos);
  if (pos->index != -1)
    pos->y += 1;
}

void	show_the_map(char **board)
{
  int	i;

  i = -1;
  while (board[++i])
    printf("%s\n", board[i]);
  printf("%s", "\n\n");
}

void	game(t_shapes *shapes, t_pars *pars, t_game *game)
{
  char	**board;
  t_pos	pos;
  int	action;

  init_board(&board, pars);
  while (check_loss(board))
    {
      rand_next(&pos, shapes, pars);
      /* printf("%d\n", pos.index); */
      while (pos.index != -1)
	{
	  /* printf("%d\n", pos.y); */
	  if ((action = get_action(pars)))
	    apply_action(action, board, &pos, shapes);
	  /* printf("oui"); */
	  falling_shapes(board, &pos);
	  show_the_map(board);
	  //	  display(board, pos, pars);
	}
    }
  //TODO : Loss fct
}
