/*
** utils.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 17:49:11 2017 Bastien
** Last update Mon Feb 27 12:50:54 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "tetris.h"

void	free_tab(char ***tab)
{
  int	i;

  i = -1;
  while (*tab && (*tab)[++i])
    free((*tab)[i]);
  free((*tab)[i]);
  if (*tab)
    free((*tab));
}

char	*spe_pure(char *s)
{
  if (s[0] == '"' || s[0] == '\'' || s[0] == '{')
    {
      s[my_strlen(s) - 1] = 0;
      s += 1;
    }
  return (s);
}
