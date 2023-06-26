/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:36 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/26 15:34:17 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int cub3d(t_game *game, char **av)
{
  t_img	img;
  t_map	map;

  if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		return  (err_ret("Error: Invalid file: extencion .cub;"));
  game->map = &map;
  game->img = &img;
  return  (0);
}
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (err_ret("Error: Invalid arguments"));
  ft_bzero(&game, sizeof(t_game));
  cub3d (&game, av);
   return (0);
}
