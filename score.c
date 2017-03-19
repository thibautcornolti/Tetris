/*
** score.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 17 13:11:03 2017 Thibaut Cornolti
** Last update Sun Mar 19 15:08:18 2017 Thibaut Cornolti
*/

#include <fcntl.h>
#include <unistd.h>
#include "tetris.h"

void		get_high_score(t_game *game)
{
  int		fd;

  if ((fd = open(HIGH_SCORE_F, O_RDONLY)) <= 0)
    return ;
  read(fd, &(game->high_score), sizeof(int));
  close(fd);
}

void		set_high_score(t_game *game)
{
  int		fd;

  if (game->high_score >= game->score)
    return ;
  if ((fd = open(HIGH_SCORE_F, O_RDWR | O_CREAT | O_TRUNC, 0644)) <= 0)
    return ;
  write(fd, &(game->score), sizeof(int));
  close(fd);
}
