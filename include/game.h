/*
** game.h for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:08:20 2017 Thibaut Cornolti
** Last update Thu Mar 23 09:52:04 2017 Bastien
*/

#ifndef GAME_H_
# define GAME_H_

typedef struct	s_shapes t_shapes;
typedef struct	s_pars t_pars;

typedef struct	s_pause
{
  int		paused;
  int		duration;
  int		start_time;
}		t_pause;

typedef struct	s_game
{
  int		high_score;
  int		score;
  int		line;
  int		level;
  int		level_time;
  int		timer;
  int		start_time;
  t_pause	pause;
}		t_game;

typedef struct	s_pos
{
  int		x;
  int		y;
  int		index;
  int		orient;
  char		**map;
  int		color;
}		t_pos;

void		init_game(t_game *, t_pars *);
int		get_action(t_pars *);
void		game(t_shapes *, t_pars *, t_game *);
int		apply_action(int, char **, t_pos *, t_shapes *);
void		falling_shapes(char **, t_pos *);
int		check_fulline(char **, t_game *);
int		check_loss(char **);
t_pos		*rand_next(t_pos *, t_shapes *, t_pars *);
void		check_hit(char **, t_pos *);
void		apply_map(char **, t_pos *);

#endif /* !GAME_H_ */
