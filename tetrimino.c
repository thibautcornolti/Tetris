/*
** tetramino.c for tetris in /home/rectoria/delivery/Projets/CPE_2016_matchstick
** 
** Made by Bastien
** Login   <rectoria@epi%tech.net>
** 
** Started on  Mon Feb 20 13:24:10 2017 Bastien
** Last update Mon Feb 20 17:44:03 2017 Bastien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetris.h"

t_shapes	**put_structab(t_shapes **shapes, t_shapes *piece, int size)
{
  t_shapes	**tab;
  int		i;

  i = (!shapes) ? 0 : -1;
  if ((tab = malloc(sizeof(t_shapes *) * (size + 1))) == NULL)
    return (NULL);
  while (shapes && shapes[++i])
    tab[i] = shapes[i];
  tab[i] = piece;
  /* free (*shapes); */
  tab[i + 1] = NULL;
  return (tab);
}

void	get_size(t_shapes *shape, char *first_line)
{
  char	**tab;
  char	*str;

  tab = my_strsplit(first_line, ' ');
  shape->width = my_getnbr(tab[0]);
  shape->height = my_getnbr(tab[1]);
  shape->color = my_getnbr(tab[2]);
  /* free_tab(tab); */
}

t_shapes	**add_shape(t_shapes **shapes, int fd)
{
  t_shapes	*piece;
  char		*str;
  char		*temp;
  static int	size = 1;

  str = NULL;
  if ((piece = malloc(sizeof(t_shapes))) == NULL)
    return NULL;
  get_size(piece, get_next_line(fd));
  while ((temp = get_next_line(fd)) != NULL)
    str = my_strmcat(my_strmcat(str, "@"), temp);
  piece->map = my_strsplit(str, '@');
  shapes = put_structab(shapes, piece, size);
  size += 1;
  return (shapes);
}

t_shapes	**get_tetrimino()
{
  DIR		*directory;
  struct dirent	*file;
  int		fd;
  t_shapes	**shapes;

  shapes = NULL;
  directory = opendir("./tetriminoes");
  while ((file = readdir(directory)) != NULL)
    {
      if (file->d_name[0] != '.')
	{
	  if ((fd = open(my_strmcat("./tetriminoes/", file->d_name), O_RDONLY)) == -1)
	    return (NULL);
	  shapes = add_shape(shapes, fd);
	}
      close(fd);
    }
  closedir(directory);
  return (shapes);
}

int	main()
{
  t_shapes	**tab;
  int		i;
  int		k;

  i = -1;
  tab = get_tetrimino();
  while (tab && tab[++i])
    {
      k = -1;
      while (tab[i]->map[++k])
	printf("%s\n", tab[i]->map[k]);
    }
}
