/*
** remove_line.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Mar  7 18:30:07 2017 Bastien
** Last update Tue Mar  7 18:51:39 2017 Bastien
*/

#include "my.h"

int	remove_line(char **board, int i)
{
  int	x;
  int	y;

  y = i + 1;
  while (--y > 0)
    {
      x = -1;
      while (board[y][++x])
	board[y][x] = board[y - 1][x];
    }
  x = -1;
  while(board[0][++x])
    board[0][x] = -1;
  usleep(10000);
  return (1);
}

int     check_fulline(char **board)
{
  int   i;
  int   j;
  int	x;

  i = -1;
  x = 0;
  while (board[++i])
    {
      j = -1;
      while (board[i][++j] && x == 0)
	if (board[i][j] == -1)
	  ++x;
      if (j == my_strlen(board[0]))
	return (remove_line(board, i));
    }
  return (0);
}
  
