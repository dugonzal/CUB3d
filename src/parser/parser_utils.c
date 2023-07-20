/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:35:16 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 22:02:26 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_rgb(t_game *game, int i, int number)
{
	if (game->color[i].rgb[number] == NULL || !game->color[i].rgb[number])
		game->color[i].rgb[number] = ft_strdup("0");
	else if (ft_atoi(game->color[i].rgb[number]) < 0)
		game->color[i].rgb[number] = ft_strdup("0");
	else if (ft_atoi(game->color[i].rgb[number]) > 255)
		game->color[i].rgb[number] = ft_strdup("255");
}

int	get_rgb(t_game *game, int i)
{
	check_rgb(game, i, 0);
	game->color[i].r = ft_atoi(game->color[i].rgb[0]);
	check_rgb(game, i, 1);
	game->color[i].g = ft_atoi(game->color[i].rgb[1]);
	check_rgb(game, i, 2);
	game->color[i].b = ft_atoi(game->color[i].rgb[2]);
	return (0);
}

int	check_commas(t_game *game, int i)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (game->color[i].buffer[++j])
		if (game->color[i].buffer[j] == ',')
			k++;
	if (k != 2)
		return (1);
	return (0);
}

bool	get_rgb_tmp(t_game *game, int i, char *line)
{
	game->color[i].buffer = ft_strtrim(&line[1], " \t\r\v\f\n", 0);
	game->color[i].rgb = ft_split(game->color[i].buffer, ',', 0);
	free(game->color[i].buffer);
	game->color[i].buffer = NULL;
	if (get_rgb(game, i))
		return (true);
	free_array(game->color[i].rgb);
	game->color[i].rgb = NULL;
	return (false);
}
