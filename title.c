/*
** title.c for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  1 10:58:07 2017 Thibaut Cornolti
** Last update Wed Mar  1 11:16:58 2017 Thibaut Cornolti
*/

#include <ncurses.h>

void		draw_title_is(char *buff, int i)
{
  char		tmp;

  attron(COLOR_PAIR(5));
  tmp = buff[68];
  buff[64] = 0;
  mvprintw(i, 53, buff + 52);
  attroff(COLOR_PAIR(5));
  buff[64] = tmp;
  attron(COLOR_PAIR(6));
  mvprintw(i, 66, buff + 65);
  attroff(COLOR_PAIR(6));
}

void		draw_title_tr(char *buff, int i)
{
  char		tmp;

  attron(COLOR_PAIR(3));
  tmp = buff[40];
  buff[38] = 0;
  mvprintw(i, 27, buff + 26);
  attroff(COLOR_PAIR(3));
  buff[38] = tmp;
  attron(COLOR_PAIR(4));
  tmp = buff[52];
  buff[52] = 0;
  mvprintw(i, 40, buff + 39);
  attroff(COLOR_PAIR(4));
  buff[52] = tmp;
  draw_title_is(buff, i);
}

void		draw_title_te(char *buff, int i)
{
  char		tmp;

  attron(COLOR_PAIR(1));
  tmp = buff[13];
  buff[13] = 0;
  mvprintw(i, 0, buff);
  attroff(COLOR_PAIR(1));
  buff[13] = tmp;
  attron(COLOR_PAIR(2));
  tmp = buff[27];
  buff[27] = 0;
  mvprintw(i, 13, buff + 12);
  attroff(COLOR_PAIR(2));
  buff[27] = tmp;
  draw_title_tr(buff, i);
}
