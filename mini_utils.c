/*
** utils2.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 09:40:36 2017 Bastien
** Last update Fri Mar 17 12:42:35 2017 Thibaut Cornolti
*/

#include "my.h"

void	del_final_space(char *s)
{
  int	e;
  int	i;

  i = -1;
  e = -1;
  while (s[++i])
    if (s[i] == '*')
      e = i;
  if (e != -1)
    s[e + 1] = 0;
}

int	my_tablen(char	**tab)
{
  int	i;

  i = 0;
  while (tab && tab[++i]);
  return (i);
}

void	print_debug(char *s)
{
  if (!my_strcmp(s, " "))
    my_putstr("(space)");
  else
    my_putstr(s);
}
