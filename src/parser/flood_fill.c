/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:57:55 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/01 00:23:04 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void flood_fill(t_game *game,char **map, int x, int y, int len_x, int len_y)
{
	if (x < 0 || y < 0 || x > len_x || y > len_y)
		return ;
	if (map[y][x] == game->player->dir || map[y][x] == '0')
	{
	  map[y][x] = 'F';
	  flood_fill (game, map, x, y - 1, len_x, len_y);
	  flood_fill (game, map, x, y + 1, len_x, len_y);
	  flood_fill (game, map, x + 1, y, len_x, len_y);
	  flood_fill (game, map, x - 1, y, len_x, len_y);
  }
}

void handler_flood_fill(t_game *game)
{
  flood_fill(game, game->map->map, game->player->x, game->player->y, 	(int)ft_strlen(*game->map->map) ,(int)arr_size(game->map->map));

}

