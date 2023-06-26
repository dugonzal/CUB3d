/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:48 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/26 22:28:27 by Dugonzal         ###   ########.fr       */
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
  game->map->map[i] = NULL;
}

/*
 Excepto por el contenido del mapa, que debe estar siempre al final, cada tipo
de elemento puede estar establecido en cualquier orden en el archivo.
 */
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
  return  (0);
}
