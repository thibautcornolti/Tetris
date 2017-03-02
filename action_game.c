/*
** action_game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Mar  1 11:06:23 2017 Bastien
** Last update Thu Mar  2 21:13:25 2017 Thibaut Cornolti
*/

#include "tetris.h"

void   	can_rotate(t_shapes *shapes, t_pos *pos, char **board)
{
  char	**tab;
  int	i;

  my_puterror("\nINDEX:");
  my_puterror(my_int_to_str(pos->index, NULL));
  my_puterror("\nORIENT:");
  my_puterror(my_int_to_str(pos->orient, NULL));
  my_puterror("\n");
  i = pos->index;
  tab = pos->map;
  pos->map = (pos->orient == 0) ? shapes->map_right : pos->map;
  pos->map = (pos->orient == 1) ? shapes->map_down : pos->map;
  pos->map = (pos->orient == 2) ? shapes->map_left : pos->map;
  pos->map = (pos->orient == 3) ? shapes->map : pos->map;
  falling_shapes(board, pos);
  pos->map = tab;
  if (i != pos->index)
    {
      pos->map = tab;
      pos->index = i;
    }
  else
    pos->y -= 1;
  pos->index = ((pos->orient + 1) % 4 == 0) ? 0 : pos->index + 1;
}

int	apply_action(int action, char **board, t_pos *pos, t_shapes *shapes)
{
  if (action == 1 && pos->x > 0)
    pos->x -= 1;
  else if (action == 2 && pos->x + shapes->width < my_strlen(board[pos->y]))
    pos->x += 1;
  else if (action == 3)
    can_rotate(&shapes[pos->index], pos, board);
  else if (action == 4)
    falling_shapes(board, pos);
  else if (action == 5)
    return (1);
  else if (action == 6); //TODO : Pause fct
  return (0);
}

int		get_action(t_pars *p)
{
  char		buff[201];

  buff[read(0, buff, 199)] = 0;
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
