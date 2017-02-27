/*
** parser.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 20 13:26:06 2017 Thibaut Cornolti
** Last update Mon Feb 27 14:06:25 2017 Thibaut Cornolti
*/

#include "tetris.h"

static int	fill_arg_max(t_pre_pars *p, char **arg)
{
  char		**tab;
  char		***val;
  char		*tmp;
  int		i;

  tab = init_arg_max();
  val = init_val(p);
  i = -1;
  while (tab[++i] && arg[1])
    if (!my_strcmp(arg[0], tab[i]))
      {
	tmp = spe_pure(my_strdup(arg[1]));
	*(val[i]) = tmp;
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

static int	fill_arg_min(t_pre_pars *p, char *arg, char *arg2)
{
  char		**tab;
  char		*tmp;
  char		***val;
  int		i;

  tab = init_arg_min();
  val = init_val(p);
  i = -1;
  while (tab[++i])
    if (!my_strcmp(arg, tab[i]))
      {
	tmp = spe_pure(my_strdup(arg2));
	*(val[i]) = tmp;
	free(tab);
	free(val);
	return (1);
      }
  free(tab);
  free(val);
  exit(my_puterror("Invalid argument.\n"));
}

static int	fill_arg(t_pre_pars *p, char **av, int i)
{
  char		*arg;

  arg = av[i] + 1;
  if (!my_strcmp(arg, "d") || !my_strcmp(arg, "-debug"))
    return (0 * (long) (p->d = "true"));
  else if (!my_strcmp(arg, "-help"))
    return (my_help());
  else if (!my_strncmp(av[i], "--", 2))
    return (fill_arg_max(p, my_strsplit(arg + 1, '=')));
  else
    return (fill_arg_min(p, arg, av[i + 1]));
}

void		my_super_parser(t_pars *p, char **av)
{
  int		i;
  t_pre_pars	pp;

  init_pars(&pp);
  i = 0;
  while (av[++i])
    if (av[i][0] == '-')
      i += fill_arg(&pp, av, i);
    else
      exit(my_puterror("Invalid argument.\n") + 84);
  set_pars(&pp, p);
}
