/*
** tetramino.c for tetris in /home/rectoria/delivery/Projets/CPE_2016_matchstick
** 
** Made by Bastien
** Login   <rectoria@epi%tech.net>
** 
** Started on  Mon Feb 20 13:24:10 2017 Bastien
** Last update Sun Mar 19 16:47:02 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetris.h"

void		put_structab(t_shapes **shapes, t_shapes *piece, int size)
{
  t_shapes	*tab;
  int		i;

  i = (!*shapes) ? 0 : -1;
  if ((tab = malloc(sizeof(t_shapes) * (size + 1))) == NULL)
    return ;
  while ((*shapes) && (*shapes)[++i].name)
    tab[i] = (*shapes)[i];
  tab[i] = *piece;
  tab[i + 1].name= NULL;
  free(*shapes);
  *shapes = tab;
}

void	add_map(int fd, t_shapes *piece)
{
  char          *str;
  char          *temp;
  char          *antileak;

  str = (char *) (piece->map = NULL);
  if (piece->width == 0 && piece->height == 0 && piece->color == 0)
    {
      while (get_next_line(fd));
      return ;
    }
  while ((temp = get_next_line(fd)) != NULL)
    {
      del_final_space(temp);
      antileak = my_strmcat(str, "@");
      free(str);
      temp = fill_str(temp, piece->width);
      str = my_strmcat(antileak, temp);
      free(temp);
      free(antileak);
    }
  if (!str)
    return ;
  piece->map = my_strsplit(str, '@');
  check_map(piece, str);
  free(str);
}


void	add_shape(t_shapes **shapes, int fd, char *name)
{
  t_shapes	*piece;
  static int	size = 1;

  if ((piece = malloc(sizeof(t_shapes))) == NULL)
    return ;
  if (get_size(piece, get_next_line(fd)))
    while (get_next_line(fd));
  add_map(fd, piece);
  if (piece->map == NULL)
    piece->valide = 0;
  else
    piece->valide = 1;
  rotate_right(piece);
  if (piece->map)
    {
      replace_space(piece->map);
      replace_space(piece->map_right);
      replace_space(piece->map_down);
      replace_space(piece->map_left);
    }
  piece->name = my_strmcat(name, NULL);
  put_structab(shapes, piece, size);
  size += 1;
}

int	check_name(char *str)
{
  char	*witness;
  int	i;
  int	j;

  j = 10;
  i = my_strlen(str);
  witness = ".tetrimino";
  while (--j >= 0 && --i >= 0)
    if (witness[j] != str[i])
      return (0);
  if (i == -1 && j > -1)
    return (0);
  else if (j == -1 && i > -1)
    return (1);
  else
    return (0);
}

void		get_tetrimino(t_shapes **shapes)
{
  DIR		*directory;
  struct dirent	*file;
  int		fd;

  *shapes = NULL;
  if ((directory = opendir("./tetriminos")) == NULL)
    return ;
  fd = 0;
  while ((file = readdir(directory)) != NULL)
    {
      if (check_name(file->d_name))
	{
	  if ((fd = open(my_strmcat("./tetriminos/",
				    file->d_name), O_RDONLY)) == -1)
	    return ;
	  add_shape(shapes, fd, file->d_name);
	}
      if (fd)
	close(fd);
    }
  closedir(directory);
  sort_tetri(*shapes);
}
