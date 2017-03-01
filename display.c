/*
** display.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:12:32 2017 Thibaut Cornolti
** Last update Wed Mar  1 09:36:55 2017 Thibaut Cornolti
*/

#include <time.h>
#include "tetris.h"

int		get_action(t_pars *p)
{
  char		buff[201];

  buff[read(0, buff, 199)] = 0;
  if (my_strstr(buff, p->kl))
    return (1);
  if (my_strstr(buff, p->kr))
    return (2);
  if (my_strstr(buff, p->kt))
    return (3);
  if (my_strstr(buff, p->kd))
    return (4);
  if (my_strstr(buff, p->kq))
    return (5);
  if (my_strstr(buff, p->kp))
    return (6);
  return (0);
}

int		display(t_game *g, t_pars *p)
{
  int		m;
  int		s;

  m = (time(NULL) - g->start_time) / 60;
  s = (time(NULL) - g->start_time) % 60;
  clear();
  printw("%s%d:%s%d\n", (m < 10) ? "0" : "", m, (s < 10) ? "0" : "", s);
  if (get_action(p) == 5)
    return (1);
  refresh();
  return (0);
}
