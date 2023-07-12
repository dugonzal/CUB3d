/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:48 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/12 12:42:16 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// ahora mismo leemos el archivo y lo guardamos en un buffer
int	len_map(t_game *game)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (game->map->buffer[i])
	{
		if (search(game->map->buffer[i], '1') \
		&& !search("NESWFC", game->map->buffer[i][0]))
		  j++;
		else if (j && !search(game->map->buffer[i], '1'))
		{
		  free(game->player);
		  free_array(game->map->buffer);
		  free_array(game->map->map);
		  return (err_ret("Invalid file: map not end file"));
		}
	  i++;
	}
	return (j);
}

void get_map(t_game *game)
{
  int i;
  int j;

  j = 0;
  i = 0;
  game->map->len_y = len_map(game);
  game->map->map = ft_calloc(sizeof(char *), game->map->len_y + 1);
  while (game->map->buffer[i])
  {
	if (search(game->map->buffer[i], '1') \
	&& !search("NESWFC", game->map->buffer[i][0]))
	{
		game->map->map[j] = ft_strdup(game->map->buffer[i]);
		if ((int)ft_strlen(game->map->map[j]) > game->map->len_x)
		  game->map->len_x = ft_strlen(game->map->map[j]);
		j++;
	}
	i++;
  }
}

/*
0. Excepto por el contenido del mapa, que debe estar siempre al final, 
1. cada tipo de elemento puede estar establecido en cualquier orden en el archivo.
*/

// deberia buscar la ubicacion del jugador en el mapa 
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
			if (!y || !x || (game->map->len_x - 1) == x || (game->map->len_y - 1) == y \
			|| game->map->map[y][x] == '\n' || game->map->map[y][x] == '\n' \
			|| game->map->map[y][x + 1] == ' ' || game->map->map[y][x - 1] == ' ' \
			|| game->map->map[y][x] == ' ' || game->map->map[y][x] == ' ' )
			  return (1);
		if (search("NESW", game->map->map[y][x]))
		{
		  count++;
		  game->player->y = y;
		  game->player->x = x;
		  game->player->dir = game->map->map[y][x];
		}
	  }
  }
  if (count != 1)
	return (1);
  return (0);
}

int parser(t_game *game, char **av)
{
  int		fd;

  if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return  (err_ret("Error: Invalid file: extencion .cub;"));
  fd = ft_open(av[1], 0);
  if (fd < 0)
	return (err_ret("Error: Invalid file: No such file or directory"));
  read_fd(game, fd, av[1]);
  get_map(game);
  print (game->map->map);
  if (check_map(game))
  {
	ft_printf ("habra que liberar en algun momento xd\n");
	return (err_ret("Error: Invalid file: Map"));
  }
  printf ("x: %d\ny: %d\ndir: %c\n", game->player->x, game->player->y, game->player->dir);
 // handler_flood_fill(game);
  //print (game->map->map);
  return  (0);
}
