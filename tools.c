/*
** tools.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 27 19:09:51 2017 Thibaut Cornolti
** Last update Wed Mar  1 10:14:43 2017 Thibaut Cornolti
*/

#include <ncurses.h>
#include <time.h>
#include "tetris.h"

int		my_shapeslen(t_shapes *s)
{
  int		i;

  i = -1;
  while (s[++i].map);
  return (i);
}

int		my_intlen(int i)
{
  char		*tmp;
  int		len;

  tmp = my_int_to_str(i, NULL);
  len = my_strlen(tmp);
  free(tmp);
  return (len);
}

void		init_game(t_game *g, t_pars *p)
{
  g->high_score = 0;
  g->score = 0;
  g->line = 0;
  g->level = p->l;
  g->timer = 0;
  g->start_time = time(NULL);
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}
