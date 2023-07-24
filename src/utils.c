/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:28:50 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/24 12:32:22 by Dugonzal         ###   ########.fr       */
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

void	*free_array(char **str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	return (NULL);
}

void	free_all(t_game *game)
{
	int	i;

	i = 4;
	free_array(game->map->map, arr_size(game->map->map));
	free_array(game->map->buffer, arr_size(game->map->buffer));
	free(game->map);
	free(game->ry);
	free(game->color);
	while (i < 5)
	{
		free(game->img[i].path);
		//free(game->img[i].img_w);
		//free(game->img[i].addr);
		//mlx_destroy_image(game->mlx, game->img[i].img_w);
		i++;
	}
	free(game->img);
}

void	free_error(t_game *game, char *str)
{
	(void)str;
	free_array(game->map->map, arr_size(game->map->map));
	free(game->map);
	free(game->ry);
	free(game->img);
	free(game->color);
	err(str);
}

int	get_int_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
