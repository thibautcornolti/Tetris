/*
** setupterm.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 10 11:28:57 2017 Thibaut Cornolti
** Last update Fri Mar 10 11:30:07 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include <term.h>

void		my_setupterm()
{
  setupterm(NULL, 0, 0);
}
