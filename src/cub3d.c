/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:36 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/26 16:47:05 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int len_map(int fd, t_game *game)
{
  int	i;
  char	*line;

  i = 0;
  (void)game;
  (void)i;
  line = get_next_line(fd);
  if (!line)
	  return (err_ret("Error: Invalid file: No map"));
  while (line)
  {
	i++;
	free(line);
	line = get_next_line(fd);
  }
  printf("%d\n", i);
  return (i);
}


int cub3d(t_game *game, char **av)
{
  int		fd;
  t_img		img;
  t_map		map;

  if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return  (err_ret("Error: Invalid file: extencion .cub;"));
  game->map = &map;
  game->img = &img;
  ft_bzero(game->map, sizeof(t_map));
  ft_bzero(game->img, sizeof(t_img));
 
  fd = ft_open(av[1], 0);
  if (fd == -1)
	return (err_ret("Error: Invalid file: No such file or directory"));
  else 
	  ft_printf("File: %d\n", fd);
  len_map(fd, game);
  return  (0);
}
int	main(int ac, char **av)
{
  t_game	game;

  if (ac != 2)
	  return (err_ret("Error: Invalid arguments"));
  ft_bzero(&game, sizeof(t_game));
  cub3d (&game, av);
  return (0);
}
