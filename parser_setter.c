/*
** parser_utils_2.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Feb 22 16:18:31 2017 Thibaut Cornolti
** Last update Mon Mar 13 14:12:35 2017 Thibaut Cornolti
*/

#include "tetris.h"

void		init_pars(t_pre_pars *p)
{
  my_setupterm();
  p->l = DEF_L;
  if ((long) (p->kl = tigetstr(DEF_KL)) <= 0)
    p->kl = "a";
  if ((long) (p->kr = tigetstr(DEF_KR)) <= 0)
    p->kr = "d";
  if ((long) (p->kt = tigetstr(DEF_KT)) <= 0)
    p->kt = "w";
  if ((long) (p->kd = tigetstr(DEF_KD)) <= 0)
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
