/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:57 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 14:04:07 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int len_fd(int fd, t_game *game)
{
  int	i;
  char	*line;

  line = get_next_line(fd);
  if (!line)
  {
 	free_error(game, "Invalid file: No line");
  }
  i = 0;
  while (line)
  {
	i++;
	free(line);
	line = get_next_line(fd);
  }
  close(fd);
  return (i);
}

void read_fd(t_game *game, int fd, char *av)
{
  int	i;
  char	*line;
  int	len;

  len = len_fd(fd, game);
  game->map->buffer = ft_calloc(sizeof(char *), len + 1);
  if (!game->map->buffer)
	free_error(game, "Invalid file: No buffer");
  fd = ft_open(av, 0);
  if (fd < 0)
	  free_error(game, "Invalid file: fd < 0");
  line = get_next_line(fd);
  i = 0;
  while (line)
  {
	game->map->buffer[i] = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	i++;
  }
  free (line);
  close(fd);
}

