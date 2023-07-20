/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:11:47 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/20 12:58:55 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// tener en cuenta las reserbas de memoria y liberarlas
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

//falta comprobar q fd exista o algo
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
	init_mlx(&game);
	return (0);
}
