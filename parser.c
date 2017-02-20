/*
** parser.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 20 13:26:06 2017 Thibaut Cornolti
** Last update Mon Feb 20 13:39:55 2017 Thibaut Cornolti
*/

#include "tetris.h"

static void	init_pars(t_pars *p)
{
  p.l = DEF_L;
  p.kl = DEF_KL;
  p.kr = DEF_KR;
  p.kt = DEF_KT;
  p.kd = DEF_KD;
  p.kq = DEF_KQ;
  p.kp = DEF_KP;
  p.row = DEF_ROW;
  p.col = DEF_COL;
  p.row = DEF_ROW;
  p.w = DEF_W;
  p.d = DEF_D;
}

void		my_super_parser(t_pars *p, char **av)
{
  init_pars(p);
}
