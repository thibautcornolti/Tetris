/*
** tetris.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 12:18:30 2017 Bastien
** Last update Mon Feb 27 20:03:02 2017 Thibaut Cornolti
*/

#include <ncurses.h>
#include "tetris.h"

void		nonblock()
{
  struct termios t;

  tcgetattr(0, &t);
  t.c_lflag |= ICANON;
}

int		main(int ac, char **av)
{
  t_pars	p;
  t_shapes	*s;

  initscr();
  keypad(stdscr, TRUE);
  (void) ac;
  my_super_parser(&p, av);
  get_tetrimino(&s);
  nonblock();
  if (p.d)
    debug(&p, s);
  return (0);
}
