/*
** my_memset.c for my_memset in /home/thibrex
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Oct 24 21:52:16 2016 Thibaut Cornolti
** Last update Fri Mar 17 12:13:18 2017 Thibaut Cornolti
*/

void	*my_memset(void *src, char c, int n)
{
  int	i;
  char	*s;

  s = src;
  i = -1;
  while (++i < n)
    s[i] = c;
  return (src);
}
