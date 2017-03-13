/*
** utils2.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 09:40:36 2017 Bastien
** Last update Mon Mar 13 14:14:40 2017 Thibaut Cornolti
*/

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
