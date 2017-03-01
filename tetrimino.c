/*
** tetramino.c for tetris in /home/rectoria/delivery/Projets/CPE_2016_matchstick
** 
** Made by Bastien
** Login   <rectoria@epi%tech.net>
** 
** Started on  Mon Feb 20 13:24:10 2017 Bastien
** Last update Tue Feb 28 18:20:29 2017 Thibaut Cornolti
*/

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
  while ((*shapes) && (*shapes)[++i].map)
    tab[i] = (*shapes)[i];
  tab[i] = *piece;
  tab[i + 1].map = NULL;
  free(*shapes);
  *shapes = tab;
}

void	add_map(int fd, t_shapes *piece)
{
  char          *str;
  char          *temp;
  char          *antileak;

  str = NULL;
  while ((temp = get_next_line(fd)) != NULL)
    {
      antileak = my_strmcat(str, "@");
      free(str);
      temp = fill_str(temp, piece->width);
      str = my_strmcat(antileak, temp);
      free(temp);
      free(antileak);
    }
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
    {
      while (get_next_line(fd));
      return ;
    }
  add_map(fd, piece);
  if (piece->map == NULL)
    return ;
  rotate_right(piece);
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
  directory = opendir("./tetriminoes");
  while ((file = readdir(directory)) != NULL)
    {
      if (check_name(file->d_name))
	{
	  if ((fd = open(my_strmcat("./tetriminoes/", file->d_name), O_RDONLY)) == -1)
	    return ;
	  add_shape(shapes, fd, file->d_name);
	}
      if (fd)
	close(fd);
    }
  closedir(directory);
  sort_tetri(*shapes);
}
