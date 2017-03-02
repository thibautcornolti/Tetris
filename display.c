/*
** display.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:12:32 2017 Thibaut Cornolti
** Last update Thu Mar  2 21:27:52 2017 Thibaut Cornolti
*/

#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include "tetris.h"

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
  init_pair(7, 7, COLOR_BLACK);
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

static void	draw_board(t_pos *pos, t_pars *p, char **board)
{
  int		i;
  int		j;

  init_pair(8, 1, 1);
  init_pair(9, 2, 2);
  init_pair(10, 3, 3);
  init_pair(11, 4, 4);
  init_pair(12, 5, 5);
  init_pair(13, 6, 6);
  init_pair(14, 7, 7);
  create_box(15, p->col / 2 + 32, p->row + 2, p->col + 2);
  i = -1;
  while (board[++i])
    {
      j = -1;
      while (board[i][++j])
	mvprintw(16 + i, p->col / 2 + 33 + j, (board[i][j] == -1) ? " " : "*");
    }
  i = -1;
  attron(COLOR_PAIR(pos->color % 7 + 8));
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (pos->map[i][j] != -1)
	  mvprintw(16 + pos->y + i, p->col / 2 + 33 + pos->x + j, "*");
    }
  attroff(COLOR_PAIR(pos->color % 7 + 8));
}

int		display(char **board, t_pos *pos, t_game *g, t_pars *p)
{
  clear();
  if (!(COLS < 80 || LINES < 20))
    {
      draw_stats(g);
      draw_title();
      draw_board(pos, p, board);
    }
  else
    mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
  refresh();
  return (0);
}
