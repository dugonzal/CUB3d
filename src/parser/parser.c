/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:48 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 14:40:26 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*0. Excepto por el contenido del mapa, que debe estar siempre al final,
1. cada tipo de elemento puede estar establecido en cualquier orden en el archivo.:*/
static int ft_player(t_game *game, int y, int x, int count)
{
  game->ry->pos_y = x;
  game->ry->pos_x = y;
  game->ry->dir = game->map->map[y][x];
  game->map->map[y][x] = '0';
  return (count + 1);
}

static int check_map_aux(t_game *game, int y, int x)
{
  if (!y || !x || (game->map->len_x - 1) == x || (game->map->len_y - 1) == y \
	|| game->map->map[y][x + 1] == ' ' || game->map->map[y][x - 1] == ' ' \
	|| game->map->map[y][x] == ' ' || game->map->map[y][x] == ' ' )
	return (1);
  return (0);
} 

int	check_map(t_game *game)
{
  int x;
  int y;
  int count;

  count = 0;
  y = -1;
  while (game->map->map[++y])
  {
	  x = -1;
	  while (game->map->map[y][++x])
	  {
		if (!search("01NESW \n", game->map->map[y][x]))
		  return (1);
		if (game->map->map[y][x] == '\n' && game->map->map[y][x - 1] != '1')
			return (1);
		if (game->map->map[y][x] != ' ' && game->map->map[y][x] != '1' && game->map->map[y][x] != '\n')
			if (check_map_aux(game, y, x))
				return (1);
		if (search("NESW", game->map->map[y][x]))
			count = ft_player(game, y, x, count);
	  }
  }
  if (count != 1)
	return (1);
  return (0);
}

int parser(t_game *game, char **av)
{
  int		fd;

  fd = ft_open(av[1], 0);
  if (fd < 0)
	  free_error(game, NULL);
  read_fd(game, fd, av[1]);
 if (get_map(game) ||check_map(game))
	free_error(game, "Error\nMapa invalido\n");
  return  (0);
}
