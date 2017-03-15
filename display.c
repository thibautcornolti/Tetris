/*
** display.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:12:32 2017 Thibaut Cornolti
** Last update Wed Mar 15 13:21:11 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include "tetris.h"

static void	init_pair_color()
{
  init_pair(8, 1, 1);
  init_pair(9, 2, 2);
  init_pair(10, 3, 3);
  init_pair(11, 4, 4);
  init_pair(12, 5, 5);
  init_pair(13, 6, 6);
  init_pair(14, 7, 7);
}

static void	draw_shape(t_pos *pos, t_pars *p)
{
  int		i;
  int		j;

  i = -1;
  attron(COLOR_PAIR(pos->color % 7 + 8));
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (pos->map[i][j] != -1)
	  mvprintw(16 + pos->y + i, 33 + pos->x + j, "*");
    }
  attroff(COLOR_PAIR(pos->color % 7 + 8));
}

static void	draw_board(t_pos *pos, t_pars *p, char **board)
{
  int		i;
  int		j;

  init_pair_color();
  create_box(15, 32, p->row + 2, p->col + 2);
  i = -1;
  while (board[++i])
    {
      j = -1;
      while (board[i][++j])
	{
	  attron(COLOR_PAIR(board[i][j] % 7 + 8));
	  mvprintw(16 + i, 33 + j,
		   (board[i][j] == -1) ? " " : "*");
	  attroff(COLOR_PAIR(board[i][j] % 8));
	}
    }
  draw_shape(pos, p);
}

int		display(char **board, t_pos *pos, t_game *g, t_pars *p)
{
  clear();
  if (COLS > 78 && LINES > 25 &&
      LINES - 16 > p->row &&
      COLS - 32 > p->col)
    {
      draw_stats(g, p);
      draw_title(pos, p);
      draw_board(pos, p, board);
    }
  else
    mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
  refresh();
  return (0);
}
