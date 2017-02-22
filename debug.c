/*
** debug.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Feb 22 17:09:29 2017 Thibaut Cornolti
** Last update Wed Feb 22 17:27:08 2017 Thibaut Cornolti
*/

#include "tetris.h"

static void	print_debug(char *s)
{
  if (!my_strcmp(s, " "))
    my_putstr("(space)");
  else
    my_putstr(s);
}

void		debug(t_pars *p)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  print_debug(p->kl);
  my_putstr("\nKey Right : ");
  print_debug(p->kr);
  my_putstr("\nKey Turn : ");
  print_debug(p->kt);
  my_putstr("\nKey Drop : ");
  print_debug(p->kd);
  my_putstr("\nKey Quit : ");
  print_debug(p->kq);
  my_putstr("\nKey Pause : ");
  print_debug(p->kp);
  my_putstr("\nNext : ");
  my_putstr((p->w) ? "Yes" : "No");
  my_putstr("\nLevel : ");
  my_put_nbr(p->l);
  my_putstr("\nSize : ");
  my_put_nbr(p->row);
  my_putstr("*");
  my_put_nbr(p->col);
  my_putstr("\n");
}
