/*
** display.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:12:32 2017 Thibaut Cornolti
** Last update Wed Mar  1 09:00:26 2017 Thibaut Cornolti
*/

#include <time.h>
#include "tetris.h"

/* int		get_action(char *buff) */
/* { */
/*   if (my_strstr()); */
/* } */

void		display(t_game *g)
{
  int		m;
  int		s;

  m = (time(NULL) - g->start_time) / 60;
  s = (time(NULL) - g->start_time) % 60;
  clear();
  printw("%s%d:%s%d\n", (m < 10) ? "0" : "", m, (s < 10) ? "0" : "", s);
  char *oui = malloc(200);
  read(0, oui, 199);
  oui[199] = 0;
  mvprintw(10, 10, "%d - %s\n", my_strlen(oui), oui);
  refresh();
}
