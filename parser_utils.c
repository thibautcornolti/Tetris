/*
** parser_utils.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 20 16:22:15 2017 Thibaut Cornolti
** Last update Wed Mar 15 13:21:19 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "tetris.h"

char		***init_val(t_pre_pars *p)
{
  char		***res;
  int		i;

  i = -1;
  if ((res = malloc(sizeof(char **) * 10)) == NULL)
    exit(my_puterror("Malloc error.\n") + 84);
  res[++i] = &p->l;
  res[++i] = &p->kl;
  res[++i] = &p->kr;
  res[++i] = &p->kt;
  res[++i] = &p->kd;
  res[++i] = &p->kq;
  res[++i] = &p->kp;
  res[++i] = &p->w;
  res[++i] = &p->map_size;
  res[++i] = NULL;
  return (res);
}

char		**init_arg_max()
{
  char		**res;
  int		i;

  i = -1;
  if ((res = malloc(sizeof(char *) * 10)) == NULL)
    exit(my_puterror("Malloc error.\n") + 84);
  res[++i] = "l";
  res[++i] = "key-left";
  res[++i] = "key-right";
  res[++i] = "key-turn";
  res[++i] = "key-drop";
  res[++i] = "key-quit";
  res[++i] = "key-pause";
  res[++i] = "without-next";
  res[++i] = "map-size";
  res[++i] = NULL;
  return (res);
}

char		**init_arg_min()
{
  char		**res;
  int		i;

  i = -1;
  if ((res = malloc(sizeof(char *) * 10)) == NULL)
    exit(my_puterror("Malloc error.\n") + 84);
  res[++i] = "l";
  res[++i] = "kl";
  res[++i] = "kr";
  res[++i] = "kt";
  res[++i] = "kd";
  res[++i] = "kq";
  res[++i] = "kp";
  res[++i] = "w";
  res[++i] = NULL;
  return (res);
}

int		contains_tab(char *s, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    if (!my_strcmp(s, tab[i]))
      return (1);
  return (0);
}

int		contains_char(char *s, char c)
{
  int		i;

  i = -1;
  while (s[++i])
    if (c == s[i])
      return (1);
  return (0);
}
