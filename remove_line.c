/*
** remove_line.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Mar  7 18:30:07 2017 Bastien
** Last update Fri Mar 17 12:30:48 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "game.h"
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
  while (board[0][++x])
    board[0][x] = -1;
  usleep(100000);
  return (1);
}

int	check_fulline(char **board, t_game *game)
{
  int	i;
  int	xj;
  int	x;

  i = -1;
  while (board[++i])
    {
      x = 0;
      j = -1;
      while (board[i][++j] && !x)
	if (board[i][j] == -1)
	  ++x;
      if (!x && j == my_strlen(board[0]))
	{
	  game->score += game->level*100;
	  return (remove_line(board, i));
	}
    }
  return (0);
}
