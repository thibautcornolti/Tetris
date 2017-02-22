/*
** navy.h for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 09:51:51 2017 Thibaut Cornolti
** Last update Wed Feb 22 17:22:52 2017 Thibaut Cornolti
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "my.h"

typedef struct	s_shapes
{
  int		width;
  int		height;
  int		color;
  char		**map;
}		t_shapes;

void		free_tab(char ***);
void		debug(t_pars *);

#endif /* !TETRIS_H_ */
