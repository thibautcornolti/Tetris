/*
** game.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Feb 28 16:42:04 2017 Bastien
** Last update Wed Mar  1 13:39:15 2017 Bastien
*/

int	check_loss(char **board)
{
  int	i;

  i = -1;
  while (tab && tab[0][++i])
    if ((int)tab[0][i] > 0)
      return (0);
  return (1);
}

void	init_board(char ***board)
{
  int	i;
  int	j;

  i = -1;
  if ((*board = malloc(sizeof(char *) * (pars->row + 1))) == NULL)
    return ;
  while (++i < pars->row)
    {
      j = -1;
      if ((*board[i] = malloc(sizeof(char) * (pars->col + 1))) == NULL)
	return ;
      while (++j < pars->col)
	(*board)[i][j] = -1;
      (*board)[i][j] = 0;
    }
  (*board)[pars->row] = NULL;
}

void	rand_next(t_pos *pos, t_shapes *shapes, t_pars *pars;)
{
  int	i;

  srand(time(NULL));
  i = (int)rand()%my_shapeslen;
  while (shapes[i].map == NULL)
    i = (int)rand()%my_shapeslen;
  pos->index = i;
  pos->y = (pars->row - my_strlen(shapes[i])) / 2;
  pos->x = 0;
  pos->orient = 0;
  pos->map = shapes[i].map;
}

void	falling_shapes(char **board, t_pos *pos)
{
  int	i;
  int	j;


  i = -1;
  while (pos->map[++i])
    {
      j = -1;
      while (pos->map[i][++j])
	if (pos->map[i][j] > 0 && board[pos->y + 1 + i][pos->x + j] > 0)
	  {
	    pos->index = -1;
	    return ;
	  }
    }
  pos->y += 1;
}

void	game(t_shapes *shapes, t_pars *pars)
{
  char	**board;
  t_pos	*pos;
  int	action;

  init_board(&board);
  while (check_loss(board))
    {
      rand_next(pos, shapes, pars);
      while (t_pos->index != -1)
	{
	  if (action = get_action(pars))
	    apply_action(action, board, pos, shapes);
	  falling_shape(board, &shapes[pos->index], pos);
	  display(board, pos, pars);
	}
    }
  //TODO : Loss fct
}
