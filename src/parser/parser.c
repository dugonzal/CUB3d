/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:48 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/02 13:05:15 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// ahora mismo leemos el archivo y lo guardamos en un buffer
int	len_map(t_game *game)
{
	int	i;
	int j;

	j = 0;
	i = -1;
	while (game->map->buffer[++i])
		if (search(game->map->buffer[i], '1') \
		&& !search("NESWFC", game->map->buffer[i][0]))
		  j++;
	return (j);
}

void get_map(t_game *game)
{
  int i;
  int j;

  j = -1;
  i = -1;
  game->map->map = ft_calloc(sizeof(char *), len_map(game) + 1);
  while (game->map->buffer[++i])
	if (search(game->map->buffer[i], '1') \
	&& !search("NESWFC", game->map->buffer[i][0]))
		game->map->map[++j] = ft_strdup(game->map->buffer[i]);
}

/*
0. Excepto por el contenido del mapa, que debe estar siempre al final, 
1. cada tipo de elemento puede estar establecido en cualquier orden en el archivo.
*/

// deberia buscar la ubicacion del jugador en el mapa 
int	check_map(t_game *game)
{
  int i;
  int j;
  int count;

  count = 0;
  i = -1;
  while (game->map->map[++i])
  {
	  j = -1;
	  while (game->map->map[i][++j])
	  {
		if (search("NESW", game->map->map[i][j]))
		{
		  count++;
		  game->player->x = j;
		  game->player->y = i;
		  game->player->dir = game->map->map[i][j];
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
//  handler_flood_fill(game);
//  print (game->map->map);
  return  (0);
}
