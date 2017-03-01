/*
** action_game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Mar  1 11:06:23 2017 Bastien
** Last update Wed Mar  1 17:41:51 2017 Bastien
*/

#include "tetris.h"

void   	can_rotate(t_shapes *shapes, t_pos *pos, char **board)
{
  char	**tab;
  int	i;

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
  pos->index = ((pos->orient + 1)%4 == 0) ? 0 : pos->index + 1;
}

void	apply_action(int action, char **board, t_pos *pos, t_shapes *shapes)
{
  if (action == 0 && pos->x > 0)
    pos->x -= 1;
  else if (action == 1 && pos->x + shapes->width < my_strlen(board[pos->y]))
    pos->x += 1;
  else if (action == 2)
    can_rotate(&shapes[pos->index], pos, board);
  else if (action == 3)
    falling_shapes(board, pos);
  else if (action == 4); //TODO : Quit fct
  else if (action == 5); //TODO : Pause fct
}
