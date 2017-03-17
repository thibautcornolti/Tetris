/*
** action_game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Mar  1 11:06:23 2017 Bastien
** Last update Fri Mar 17 13:35:22 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "tetris.h"

int		can_dash(t_pos *pos, char **board, int d)
{
  int		i;
  int		j;

  i = -1;
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (board[pos->y + i][pos->x + j + d] > 0 && pos->map[i][j] > 0)
	  return (0);
    }
  return (1);
}

static void	set_can_rotate(t_shapes *shapes, t_pos *pos)
{
  pos->map = (pos->orient == 0) ? shapes->map_right : pos->map;
  pos->map = (pos->orient == 1) ? shapes->map_down : pos->map;
  pos->map = (pos->orient == 2) ? shapes->map_left : pos->map;
  pos->map = (pos->orient == 3) ? shapes->map : pos->map;
}

void	   	can_rotate(t_shapes *shapes, t_pos *pos, char **board)
{
  char		**tab;
  int		i;
  int		j;

  tab = pos->map;
  set_can_rotate(shapes, pos);
  i = -1;
  if ((my_strlen(pos->map[0]) + pos->x > my_strlen(board[0]))
      || (my_tablen(pos->map) + pos->y > my_tablen(board)))
    {
      pos->map = tab;
      return ;
    }
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (board[pos->y + i][pos->x + j] > 0 && pos->map[i][j] > 0)
	  {
	    pos->map = tab;
	    return ;
	  }
    }
  pos->orient = ((pos->orient + 1) % 4 == 0) ? 0 : pos->orient + 1;
}

int		apply_action(int action, char **board,
		     t_pos *pos, t_shapes *shapes)
{
  if (action == 1 && pos->x > 0 && can_dash(pos, board, -1))
    pos->x -= 1;
  else if (action == 2 &&
	   pos->x + my_strlen(pos->map[0]) < my_strlen(board[0])
	   && can_dash(pos, board, 1))
    pos->x += 1;
  else if (action == 3)
    can_rotate(&shapes[pos->index], pos, board);
  else if (action == 4)
    falling_shapes(board, pos);
  else if (action == 5)
    return (1);
  return (0);
}

int		get_action(t_pars *p)
{
  char		buff[201];
  int		n;

  if ((n = read(0, buff, 199)) <= 0)
    return (0);
  buff[n] = 0;
  if (my_strstr(buff, p->kl))
    return (1);
  if (my_strstr(buff, p->kr))
    return (2);
  if (my_strstr(buff, p->kt))
    return (3);
  if (my_strstr(buff, p->kd))
    return (4);
  if (my_strstr(buff, p->kq))
    return (5);
  if (my_strstr(buff, p->kp))
    return (6);
  return (0);
}
