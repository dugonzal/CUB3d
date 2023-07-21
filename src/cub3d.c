/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:11:47 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/21 11:09:57 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_struct(t_game *lch)
{
	lch->color = (t_color *)ft_calloc(sizeof(t_color), 2);
	lch->img = (t_img *)ft_calloc(sizeof(t_img), 5);
	lch->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	lch->ry = (t_ry *)ft_calloc(sizeof(t_ry), 1);
	if (!lch->map || !lch->ry || !lch->img || !lch->color)
	{
		free(lch->map);
		free(lch->ry);
		free(lch->img);
		free(lch->color);
		return (err("malloc"));
	}
}
void	ft_default(t_game *game)
{
	if (!game->img[0].path)
		game->img[0].path = ft_strdup("img/wood3.xpm");
	if (!game->img[1].path)
		game->img[1].path = ft_strdup("img/0.xpm");
	if (!game->img[2].path)
		game->img[2].path = ft_strdup("img/1.xpm");
	if (!game->img[3].path)
		game->img[3].path = ft_strdup("img/2.xpm");
}
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (err_ret("Error: Invalid arguments"));
	if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return (err_ret("Invalid file: extencion .cub;"));
	ft_bzero(&game, sizeof(t_game));
	init_struct(&game);
	parser (&game, av);
	if (game.map->map)
	{

		ft_default(&game);
		init_mlx(&game);
	}
	return (0);
}
