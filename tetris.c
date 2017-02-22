/*
** tetris.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 12:18:30 2017 Bastien
** Last update Wed Feb 22 17:21:34 2017 Thibaut Cornolti
*/

#include "tetris.h"

int		main(int ac, char **av)
{
  t_pars	p;

  (void) ac;
  my_super_parser(&p, av);
  if (p.d)
    debug(&p);
  return (0);
}
