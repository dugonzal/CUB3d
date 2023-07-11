/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:57 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/11 13:07:32 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int len_fd(int fd)
{
  int	i;
  char	*line;

  line = get_next_line(fd);
  if (!line)
	  return (err_ret("Error: Invalid file: No map"));
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
  
  game->map->buffer = ft_calloc(sizeof(char *), len_fd(fd) + 1);
  fd = ft_open(av, 0);
  if (fd < 0)
	return (err("Error: Invalid file: No such file or directory"));
  line = get_next_line(fd);
  if (!line)
	return (err("Error: Invalid file: No map"));
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

