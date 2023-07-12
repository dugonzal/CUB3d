/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:57:55 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/12 08:27:47 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int flood_fill(int i, t_game *game,char **map, int x, int y, int len_x, int len_y)
{
	if (x < 0 || y < 0 || x > len_x || y > len_y)
		return (i);
	if (map[y][x] == game->player->dir || map[y][x] == '0')
	{
	  map[y][x] = 'F';
	  i++;
	  flood_fill (i, game, map, x, y - 1, len_x, len_y);
	  flood_fill (i, game, map, x, y + 1, len_x, len_y);
	  flood_fill (i, game, map, x + 1, y, len_x, len_y);
	  flood_fill (i, game, map, x - 1, y, len_x, len_y);
  }
  return (i);
}

void handler_flood_fill(t_game *game)
{
  int i;

  i = 0;
  i += flood_fill(i, game, game->map->map, game->player->x, game->player->y, game->map->len_x, game->map->len_y);
  printf ("--[%d]---\n", i);
}

