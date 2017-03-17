/*
** pause.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar 15 13:12:19 2017 Thibaut Cornolti
** Last update Fri Mar 17 12:21:55 2017 Thibaut Cornolti
*/

#include <time.h>
#include "tetris.h"

int		my_pause(t_game *game, int action)
{
  if (action == 6)
    if (game->pause.paused)
      {
	game->pause.duration += time(NULL) - game->pause.start_time;
	game->pause.paused = 0;
      }
    else
      {
	game->pause.paused = 1;
	game->pause.start_time = time(NULL);
      }
  else if (action == 5)
    return (1);
  else if (game->pause.paused)
    return (0);
  return (1);
}
