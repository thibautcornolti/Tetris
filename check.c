/*
** check.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 17 13:40:26 2017 Thibaut Cornolti
** Last update Sun Mar 19 18:26:33 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "tetris.h"

static void	check_pars_tab(char **pars)
{
  int		i;
  int		j;

  i = -1;
  while (++i < 6)
    {
      j = -1;
      while (++j < 6)
	{
	  if (j == i)
	    continue ;
	  if (!my_strcmp(pars[i], pars[j]))
	    {
	      my_puterror("Parsing error.\n");
	      exit(84);
	    }
	}
    }
}

void		check_pars(t_pars *p)
{
  char		*pars[6];

  pars[0] = p->kl;
  pars[1] = p->kr;
  pars[2] = p->kt;
  pars[3] = p->kd;
  pars[4] = p->kq;
  pars[5] = p->kp;
  check_pars_tab(pars);
}

void		check_game(t_shapes *s, t_pars *p, int i)
{
  if (!s)
    {
      my_puterror("Not enough tetriminos!\n");
      non_block(0,0);
      exit(84);
    }
  if (i)
    {
      while (s->name)
	{
	  if (s->valide &&
	      s->height <= p->row &&
	      s->width <= p->col)
	    return ;
	  s += 1;
	}
      my_puterror("Not enough tetriminos!\n");
      non_block(0,0);
      exit(84);
    }
}
