/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:28:50 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/26 11:27:53 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_printf("%s", str[i]);
}

void	*free_array(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < (int)arr_size(str))
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	free_all(t_game *game)
{
	int	i;

	i = -1;
	free_array(game->map->map);
	free(game->map);
	free(game->ry);
	free(game->color);
	while (++i < 5)
		if (game->img[i].path)
			free(game->img[i].path);
	free(game->img);
}

void	free_error(t_game *game, char *str)
{
	free_all(game);
	err(str);
}

int	get_int_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
