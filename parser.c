/*
** parser.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 20 13:26:06 2017 Thibaut Cornolti
** Last update Mon Feb 20 18:22:16 2017 Thibaut Cornolti
*/

#include "tetris.h"

static void	init_pars(t_pars *p)
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

static int	fill_arg_max(t_pars *p, char **arg)
{
  char		**tab;
  int		**val;
  int		i;

  tab = init_arg_max();
  val = init_val(p);
  i = -1;
  while (tab[++i])
    if (!my_strcmp(arg[0], tab[i]))
      {
	*(val[i]) = my_getnbr(arg[1]);
	free(tab);
	free(val);
	free_tab(&arg);
	return (0);
      }
  free(tab);
  free(val);
  free_tab(&arg);
  exit(my_puterror("Invalid argument.\n"));
}

static int	fill_arg_min(t_pars *p, char *arg, char *arg2)
{
  char		**tab;
  int		**val;
  int		i;

  tab = init_arg_min();
  val = init_val(p);
  i = -1;
  while (tab[++i])
    if (!my_strcmp(arg, tab[i]))
      {
	*(val[i]) = my_getnbr(arg2);
	free(tab);
	free(val);
	return (1);
      }
  free(tab);
  free(val);
  exit(my_puterror("Invalid argument.\n"));
}

static int	fill_arg(t_pars *p, char **av, int i)
{
  char		*arg;

  arg = av[i] + 1;
  if (contains_char(arg, '='))
    return (fill_arg_max(p, my_strsplit(arg, '=')));
  else
    return (fill_arg_min(p, arg, av[i + 1]));
}

void		my_super_parser(t_pars *p, char **av)
{
  int		i;

  init_pars(p);
  i = 0;
  while (av[++i])
    if (av[i][0] == '-')
      i += fill_arg(p, av, i);
    else
      exit(my_puterror("Invalid argument.\n") + 84);
}
