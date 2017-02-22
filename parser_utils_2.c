/*
** parser_utils_2.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Feb 22 16:18:31 2017 Thibaut Cornolti
** Last update Wed Feb 22 16:25:52 2017 Thibaut Cornolti
*/

#include "tetris.h"

void		init_pars(t_pre_pars *p)
{
  p->l = DEF_L;
  p->kl = DEF_KL;
  p->kr = DEF_KR;
  p->kt = DEF_KT;
  p->kd = DEF_KD;
  p->kq = DEF_KQ;
  p->kp = DEF_KP;
  p->row = DEF_ROW;
  p->col = DEF_COL;
  p->row = DEF_ROW;
  p->w = DEF_W;
  p->d = DEF_D;
}

void		set_pars(t_pre_pars *pp, t_pars *p)
{
  p->l = my_getnbr(pp->l);
  p->kl = pp->kl;
  p->kr = pp->kr;
  p->kt = pp->kt;
  p->kd = pp->kd;
  p->kq = pp->kq;
  p->kp = pp->kp;
  p->row = my_getnbr(pp->row);
  p->col = my_getnbr(pp->col);
  p->w = (my_strcmp(pp->w, "false")) ? 1 : 0;
  p->d = (my_strcmp(pp->d, "false")) ? 1 : 0;
}
