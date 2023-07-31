/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:57:55 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/31 00:41:04 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void flood_fill(t_game *game,char **map, int x, int y, int len_x, int len_y)
{
	if (x < 0 || y < 0 || x > len_x || y > len_y)
		return ;
	if (map[y][x] == '0')
	{
	  map[y][x] = 'f';
	  flood_fill (game, map, x, y - 1, len_x, len_y);
	  flood_fill (game, map, x, y + 1, len_x, len_y);
	  flood_fill (game, map, x + 1, y, len_x, len_y);
	  flood_fill (game, map, x - 1, y, len_x, len_y);
  }
}

bool check_wall(t_game *game, int y, int x)
{
	if (game->map->map[y][x] != 'f' && game->map->map[y][x] != '1')
		return (true);
	return (false);
}

bool handler_flood_fill(t_game *game)
{
	int y;
	int x;

	flood_fill(game, game->map->map, game->x, game->y, game->map->len_x ,(int)arr_size(game->map->map));
	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'f')
			{
				if (check_wall(game, y + 1, x))
					return (true);
				else if (check_wall(game, y - 1, x))
					return (true);
				else if (check_wall(game, y, x - 1))
					return (true);
				else if (check_wall(game, y, x + 1))
					return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

