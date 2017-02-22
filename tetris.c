/*
** tetris.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 12:18:30 2017 Bastien
** Last update Wed Feb 22 16:34:20 2017 Thibaut Cornolti
*/

#include "tetris.h"

void		debug(t_pars *p)
{
  printf("l: '%d'\n", p->l);
  printf("kl: '%s'\n", p->kl);
  printf("kr: '%s'\n", p->kr);
  printf("kt: '%s'\n", p->kt);
  printf("kd: '%s'\n", p->kd);
  printf("kq: '%s'\n", p->kq);
  printf("kp: '%s'\n", p->kp);
  printf("row: '%d'\n", p->row);
  printf("col: '%d'\n", p->col);
  printf("w: '%d'\n", p->w);
  printf("d: '%d'\n", p->d);
}

int		main(int ac, char **av)
{
  t_pars	p;

  (void) ac;
  my_super_parser(&p, av);
  debug(&p);
  return (0);
}
