/*
1;2802;0c** parser.h for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Feb 20 13:27:16 2017 Thibaut Cornolti
** Last update Mon Feb 27 13:03:35 2017 Thibaut Cornolti
*/

#ifndef PARSER_H_
# define PARSER_H_

#include <curses.h>

# define DEF_L		"1"
# define DEF_KL		"^[[D"
# define DEF_KR		"^[[C"
# define DEF_KT		"^[[A"
# define DEF_KD		"^[[B"
# define DEF_KQ		"q"
# define DEF_KP		" "
# define DEF_MAPSIZE	"20,10"
# define DEF_W		"0"
# define DEF_D		"false"

typedef struct	s_pars
{
  int		l;
  char		*kl;
  char		*kr;
  char		*kt;
  char		*kd;
  char		*kq;
  char		*kp;
  int		row;
  int		col;
  int		w;
  int		d;
}		t_pars;

typedef struct	s_pre_pars
{
  char		*l;
  char		*kl;
  char		*kr;
  char		*kt;
  char		*kd;
  char		*kq;
  char		*kp;
  char		*w;
  char		*d;
  char		*map_size;
}		t_pre_pars;

void		my_super_parser(t_pars *, char **);
char		***init_val(t_pre_pars *);
char		**init_arg_max();
char		**init_arg_min();
void		init_pars(t_pre_pars *);
void		set_pars(t_pre_pars *, t_pars *);
int		contains_tab(char *, char **);
int		contains_char(char *, char);
char		*spe_pure(char *);

#endif /* !PARSER_H_ */
