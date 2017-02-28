/*
** utils2.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 09:40:36 2017 Bastien
** Last update Tue Feb 28 09:42:08 2017 Bastien
*/

int	my_tablen(char	**tab)
{
  int	i;

  i = 0;
  while (tab && tab[++i]);
  return (i);
}
