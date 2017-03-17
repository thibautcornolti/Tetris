/*
** utils.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 17:49:11 2017 Bastien
** Last update Fri Mar 17 12:07:50 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "tetris.h"

char		*fill_str(char *str, int i)
{
  char		*dest;
  int		j;

  j = -1;
  if (my_strlen(str) > i)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  while (str && str[++j])
    dest[j] = str[j];
  j--;
  while (++j < i)
    dest[j] = ' ';
  dest[j] = '\0';
  free(str);
  return (dest);
}

void		free_tab(char ***tab)
{
  int		i;

  i = -1;
  while (*tab && (*tab)[++i])
    free((*tab)[i]);
  free((*tab)[i]);
  if (*tab)
    free((*tab));
}

char		*spe_pure(char *s)
{
  if (s[0] == '"' || s[0] == '\'' || s[0] == '{')
    {
      s[my_strlen(s) - 1] = 0;
      s += 1;
    }
  return (s);
}

void		sort_tetri(t_shapes *shapes)
{
  int		i;
  int		j;
  t_shapes	tmp;

  i = -1;
  if (!shapes)
    return ;
  while (shapes[++i].name)
    shapes[i].name[my_strlen(shapes[i].name) - 10] = 0;
  i = -1;
  while (shapes[++i].name)
    {
      j = -1;
      while (shapes[++j].name)
	if (my_strcmp(shapes[i].name, shapes[j].name) < 0)
	  {
	    tmp = shapes[i];
	    shapes[i] = shapes[j];
	    shapes[j] = tmp;
	  }
    }
}

int		my_help(char *name)
{
  my_putstr("Usage:  ");
  my_putstr(name);
  my_putstr(" [options]\nOptions:\n");
  my_putstr("  --help\t\tDisplay this help\n  -l --level");
  my_putstr("={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("  -kl --key-left={K}\tMove the tetrimino ");
  my_putstr("LEFT using the K key (def: left arrow)\n");
  my_putstr("  -kr --key-right={K}\tMove the tetrimino ");
  my_putstr("RIGHT using the K key (def: right arrow)\n");
  my_putstr("  -kt --key-turn={K}\tTURN the tetrimino ");
  my_putstr("clockwise 90d using the K key (def: top arrow)\n");
  my_putstr("  -kd --key-down={K}\tDROP the tetrimino ");
  my_putstr("using the K key (def: down arrow)\n");
  my_putstr("  -kq --key-quit={K}\tQUIT the tetrimino ");
  my_putstr("using the K key (def: 'q' key)\n");
  my_putstr("  -kp --key-drop={K}\tPAUSE/RESTART the game ");
  my_putstr("using the K key (def: space bar)\n");
  my_putstr("  --map-size={row,col}\tSet the numbers of ");
  my_putstr("rows and columns of the map (def: 20,10)\n");
  my_putstr("  -w --without-next\tHide next tetrimino (def: ");
  my_putstr("false)\n  -d --debug\t\tDebug mode (def: false)\n");
  exit(0);
}
