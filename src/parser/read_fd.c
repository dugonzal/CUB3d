/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:57 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/23 13:19:11 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	len_fd(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		free_error(game, "Invalid file: No line");
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

void	read_fd(t_game *game, int fd, char *av)
{
	char	*line;
	int		i;
	int		len;

	len = len_fd(fd, game) + 1;
	ft_printf("len = %d\n", len);
	fd = ft_open(av, 0);
	game->map->buffer = ft_calloc(sizeof(char *), len);
	if (!game->map->buffer || !fd)
	{
		free_array(game->map->buffer);
		free_error(game, "Invalid file: No buffer");
	}
	line = get_next_line(fd);
	i = -1;
	while (line && ++i < len)
	{
		game->map->buffer[i] = ft_strndup(line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
}
