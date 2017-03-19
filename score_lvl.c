/*
** score_lvl.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar  9 10:57:02 2017 Bastien
** Last update Thu Mar  9 11:07:43 2017 Bastien
*/

int	get_update(char **board, t_pos *pos, t_scores *score)
{
  if (score->score > score->next)
    {
      score->level += 1;
      score->speed -= 50;
    }
  if (ftime(score->tp) && score->tp.millitm == score->speed)
    {
      falling_shapes(board, pos);
      usleep(1000);
      return (1);
    }
  return (0);
}
