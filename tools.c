/*
** tools.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 27 19:09:51 2017 Thibaut Cornolti
** Last update Tue Feb 28 17:52:57 2017 Thibaut Cornolti
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
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}
