/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:28:50 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 22:09:25 by Dugonzal         ###   ########.fr       */
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
	while (*str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	return (NULL);
}

void	free_error(t_game *game, char *str)
{
	free_array(game->map->map);
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
