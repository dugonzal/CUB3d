/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:48 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 13:02:08 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void free_error(t_game *game, char *str)
{
	free(game->map);
	free(game->ry);
	free(game->img);
	free(game->color);
	err(str);
}

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
		  free_error(game, "Invalid file: No end");
		i++;
	}
	return (j);
}

void check_rgb(t_game *game, int i, int number)
{
  if (game->color[i].rgb[number] == NULL || !game->color[i].rgb[number])
	  game->color[i].rgb[number] = ft_strdup("0");
  else if (ft_atoi(game->color[i].rgb[number]) < 0)
	  game->color[i].rgb[number] = ft_strdup("0");
  else if (ft_atoi(game->color[i].rgb[number]) > 255)
	  game->color[i].rgb[number] = ft_strdup("255");
}

int get_rgb(t_game *game, int i)
{
  check_rgb(game, i, 0);
  game->color[i].r = ft_atoi(game->color[i].rgb[0]);
  check_rgb(game, i, 1);
  game->color[i].g = ft_atoi(game->color[i].rgb[1]);
  check_rgb(game, i, 2);
  game->color[i].b = ft_atoi(game->color[i].rgb[2]);
  return (0);
}

int check_commas(t_game *game, int i)
{
	int j;
	int k;

	j = -1;
	k = 0;
	while (game->color[i].buffer[++j])
		if (game->color[i].buffer[j] == ',')
		  k++;
	if (k != 2)
		return (1);
	return (0);
}

bool get_rgb_tmp(t_game *game, int i, char *line)
{
	game->color[i].buffer = ft_strtrim(&line[1], " \t\r\v\f\n", 0);
	game->color[i].rgb = ft_split(game->color[i].buffer, ',', 0);
	free(game->color[i].buffer);
	if (get_rgb(game, i))
	  return (true);
	free_array(game->color[i].rgb);
	return (false);
}

int _get(t_game *game, char *line, int iter)
{
	if (search("NESW", *line) && iter == 5)
		return (1);
  if (line[0] == 'N' && line[1] == 'O') {
	game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
  }
  else if (line[0] == 'S' && line[1] == 'O')
	game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
  else if (line[0] == 'E' && line[1] == 'A')
	game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
  else if (line[0] == 'W' && line[1] == 'E')
	game->img[iter].path = ft_strtrim(&line[2], " \t\r\v\f\n", 0);
  else if (line[0] == 'F')
  {
	if (get_rgb_tmp(game, 0, line) == true)
	  return (1);
  }
  else if (line[0] == 'C')
  {
	if (get_rgb_tmp(game, 1, line) == true)
	  return (1);
  }
  else
	  return (1);
  return (0);
}

int get_map(t_game *game)
{
  int i;
  int j;
  int iter;

  j = 0;
  i = 0;
  iter = -1;
  game->map->len_y = len_map(game);
  if (game->map->len_y < 3)// si el mapa es menor que 3 es que no hay mapa o es invalido hay que limpiar
	  return (err_ret("Invalid file: len map < 3"));
  game->map->map = ft_calloc(sizeof(char *), game->map->len_y + 1);
  if (!game->map->map)
	  return (1);
  while (game->map->buffer[i])
  {
	if (search("NESWFC",game->map->buffer[i][0]))
	{
		if (_get(game, game->map->buffer[i], ++iter))
		  return (1);
	}
	else if (search(game->map->buffer[i], '1') \
	&& !search("NESWFC", game->map->buffer[i][0]))
	{
		game->map->map[j] = ft_strdup(game->map->buffer[i]);
		if ((int)ft_strlen(game->map->map[j]) > game->map->len_x)
		  game->map->len_x = ft_strlen(game->map->map[j]);
		j++;
	}
	i++;
  }
  game->map->map[j] = NULL;
  free_array(game->map->buffer);
  return (0);
}

/*0. Excepto por el contenido del mapa, que debe estar siempre al final,
1. cada tipo de elemento puede estar establecido en cualquier orden en el archivo.:*/
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
		  game->ry->pos_y = x;
		  game->ry->pos_x = y;
		  game->ry->dir = game->map->map[y][x];
		  game->map->map[y][x] = '0';
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

  fd = ft_open(av[1], 0);
  if (fd < 0)
	free_error(game, "Invalid file: fd < 0 No such file or directory");
  read_fd(game, fd, av[1]);
  if (get_map(game) || check_map(game))
	  free_error(game, "Invalid file:  get map and check map not found");
  return  (0);
}
