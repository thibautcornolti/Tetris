/*
** tools.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 27 19:09:51 2017 Thibaut Cornolti
** Last update Tue Mar  7 15:23:12 2017 Bastien
*/

#include <ncurses.h>
#include <time.h>
#include "tetris.h"

void		replace_space(char **map)
{
  int		i;
  int		j;

  i = -1;
  while (map[++i])
    {
      j = -1;
      while (map[i][++j])
	if (map[i][j] == ' ')
	  map[i][j] = -1;
    }
}

int		my_shapeslen(t_shapes *s)
{
  int		i;

  i = -1;
  while (s[++i].name);
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
