/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:36 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/26 22:15:58 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_struct(t_game *game)
{
  t_img		img;
  t_map		map;
  
  game->map = &map;
  game->img = &img;
  ft_bzero(game->map, sizeof(t_map));
  ft_bzero(game->img, sizeof(t_img));
}

int	main(int ac, char **av)
{
  t_game	game;

  if (ac != 2)
	  return (err_ret("Error: Invalid arguments"));
  ft_bzero(&game, sizeof(t_game));
  init_struct(&game);
  parser (&game, av);
  print(game.map->map);
  return (0);
}
