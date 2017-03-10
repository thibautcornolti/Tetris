/*
** parser_utils_2.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Feb 22 16:18:31 2017 Thibaut Cornolti
** Last update Fri Mar 10 11:29:41 2017 Thibaut Cornolti
*/

#include "tetris.h"

void		init_pars(t_pre_pars *p)
{
  my_setupterm();
  p->l = DEF_L;
  if (!(p->kl = tigetstr(DEF_KL)))
    p->kl = "q";
  if (!(p->kr = tigetstr(DEF_KR)))
    p->kr = "d";
  if (!(p->kt = tigetstr(DEF_KT)))
    p->kt = "z";
  if (!(p->kd = tigetstr(DEF_KD)))
    p->kd = "s";
  endwin();
  p->kq = DEF_KQ;
  p->kp = DEF_KP;
  p->map_size = DEF_MAPSIZE;
  p->w = DEF_W;
  p->d = DEF_D;
}

void		set_pars(t_pre_pars *pp, t_pars *p)
{
  char		**tab;

  p->l = my_getnbr(pp->l);
  p->kl = pp->kl;
  p->kr = pp->kr;
  p->kt = pp->kt;
  p->kd = pp->kd;
  p->kq = pp->kq;
  p->kp = pp->kp;
  tab = my_strsplit(pp->map_size, ',');
  p->row = my_getnbr(tab[0]);
  p->col = my_getnbr(tab[1]);
  free_tab(&tab);
  p->w = (my_strcmp(pp->w, "false")) ? 1 : 0;
  p->d = (my_strcmp(pp->d, "false")) ? 1 : 0;
}
