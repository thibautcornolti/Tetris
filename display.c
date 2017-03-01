/*
** display.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:12:32 2017 Thibaut Cornolti
** Last update Wed Mar  1 11:22:14 2017 Thibaut Cornolti
*/

#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
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

static void	draw_title()
{
  int		fd;
  int		i;
  char		*buff;

  fd = open("title.txt", O_RDONLY);
  i = 0;
  start_color();
  init_pair(1, 1, COLOR_BLACK);
  init_pair(2, 2, COLOR_BLACK);
  init_pair(3, 3, COLOR_BLACK);
  init_pair(4, 4, COLOR_BLACK);
  init_pair(5, 5, COLOR_BLACK);
  init_pair(6, 6, COLOR_BLACK);
  while ((buff = get_next_line(fd)))
    {
      draw_title_te(buff, i);
      i += 1;
    }
  close(fd);
}

static void	draw_stats(t_game *g)
{
  int		m;
  int		s;

  m = (time(NULL) - g->start_time) / 60;
  s = (time(NULL) - g->start_time) % 60;
  create_box_sl(LINES / 2 - 5, 3, 10, 28);
  mvprintw(LINES / 2 - 3, 5, "High Score");
  mvprintw(LINES / 2 - 3, 29 - my_intlen(g->high_score), "%d", g->high_score);
  mvprintw(LINES / 2 - 2, 5, "Score");
  mvprintw(LINES / 2 - 2, 29 - my_intlen(g->score), "%d", g->score);
  mvprintw(LINES / 2 + 0, 5, "Lines");
  mvprintw(LINES / 2 + 0, 29 - my_intlen(g->line), "%d", g->line);
  mvprintw(LINES / 2 + 1, 5, "Level");
  mvprintw(LINES / 2 + 1, 29 - my_intlen(g->level), "%d", g->level);
  mvprintw(LINES / 2 + 3, 5, "Timer");
  mvprintw(LINES / 2 + 3, 24, "%s%d:%s%d",
	   (m < 10) ? "0" : "", m, (s < 10) ? "0" : "", s);
}

int		display(t_game *g, t_pars *p)
{
  clear();
  if (!(COLS < 80 || LINES < 20))
    {
      draw_stats(g);
      draw_title();
    }
  else
    mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
  if (get_action(p) == 5)
    return (1);
  refresh();
  return (0);
}
