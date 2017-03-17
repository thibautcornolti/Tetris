/*
** navy.h for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 09:51:51 2017 Thibaut Cornolti
** Last update Fri Mar 17 12:58:50 2017 Thibaut Cornolti
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include "parser.h"
#include "game.h"
#include "my.h"

# define SPEED_COUNT 400

typedef struct	s_shapes
{
  char		*name;
  int		valide;
  int		width;
  int		height;
  int		color;
  char		**map;
  char		**map_left;
  char		**map_right;
  char		**map_down;
}		t_shapes;

int		my_shapeslen(t_shapes *);
int		my_tablen(char **);
int		my_intlen(int);
int		get_size(t_shapes *, char *);
char		*fill_str(char *, int);
void		free_tab(char ***);
void		debug(t_pars *, t_shapes *);
void		rotate_right(t_shapes *);
void		get_tetrimino(t_shapes **);
void		sort_tetri(t_shapes *);
void		check_map(t_shapes *, char *);
void		draw_stats(t_game *);
void		draw_title();
void		my_setupterm();
int		display(char **, t_pos *, t_game *, t_pars *);
void		draw_title_te(char *, int);
void		create_box(int, int, int, int);
void		create_box_sl(int, int, int, int);
int		get_action(t_pars *);
void		replace_space(char **);
void		del_final_space(char *);
int		my_pause(t_game *, int);
void		print_debug(char *);

#endif /* !TETRIS_H_ */
