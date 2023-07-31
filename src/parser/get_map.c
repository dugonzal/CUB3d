/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:19:35 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/31 02:56:55 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	len_map(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map->buffer[i])
	{
		if (search(game->map->buffer[i], '1') \
		&& !search("NESWFC", game->map->buffer[i][0]))
			j++;
		else if (j > 0 && !search(game->map->buffer[i], '1'))
		{
			free_array(game->map->buffer);
			free_error(game, "Invalid file: No end");
		}
		i++;
	}
	return (j);
}

static void	len_x(t_game *game, int j)
{
	if ((int)ft_strlen(game->map->map[j]) > game->map->len_x)
		game->map->len_x = ft_strlen(game->map->map[j]);
}

static int	get(t_game *game, char *line, int iter)
{
	if (search("NESW", *line) && iter == 5)
		return (1);
	if (line[0] == 'N' && line[1] == 'O')
		game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
	else if (line[0] == 'S' && line[1] == 'O')
		game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
	else if (line[0] == 'E' && line[1] == 'A')
		game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
	else if (*line == 'W' && *(line + 1) == 'E')
		game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
	else if (*line == 'F')
	{
		if (get_rgb_tmp(game, 0, line) == true)
			return (1);
	}
	else if (*line == 'C')
	{
		if (get_rgb_tmp(game, 1, line) == true)
			return (1);
	}
	else
		return (1);
	return (0);
}

// j[0] = j, j[1] = i  j[2] = iter
int	get_map(t_game *game, int i)
{
	int	j[3];

	j[0] = 0;
	j[1] = 0;
	j[2] = -1;
	game->map->len_y = len_map(game);
	game->map->map = ft_calloc(sizeof(char *), game->map->len_y + 1);
	if (!game->map->map)
		free_error(game, "Invalid file: calloc");
	while (game->map->buffer[j[1]] && j[0] < game->map->len_y)
	{
		if (i == 1 && search("NESWFC", game->map->buffer[j[1]][0]))
			if (get(game, game->map->buffer[j[1]], ++j[2]))
				return (1);
		if (search(game->map->buffer[j[1]], '1') \
		&& !search("NESWFC", game->map->buffer[j[1]][0]))
		{
			game->map->map[j[0]] = ft_strdup(game->map->buffer[j[1]]);
			len_x(game, j[0]);
			j[0]++;
		}
		j[1]++;
	}
	game->map->map[j[0]] = NULL;
	return (0);
}
