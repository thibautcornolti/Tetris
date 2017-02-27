/*
** tetris.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 12:18:30 2017 Bastien
** Last update Mon Feb 27 18:40:15 2017 Bastien
*/

#include "tetris.h"

int		main(int ac, char **av)
{
  t_pars	p;
  t_shapes	*s;

  (void) ac;
  my_super_parser(&p, av);
  get_tetrimino(&s);
  if (p.d)
    debug(&p);
  return (0);
}
