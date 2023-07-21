/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:17:09 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/21 10:38:27 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//126 arriba, 123 der, 124, iz, 125 abajo// 0 a, 1 s, 2 d, 12 w
int	keyhook(t_game *lch)
{
	if (lch->x == 1)
		move_camera_v(lch, 0.33, 1);
	else if (lch->x == 2)
		move_camera_v(lch, 0.33, -1);
	else if (lch->x == 3)
		move_camera_h(lch, 0.33, -1);
	else if (lch->x == 4)
		move_camera_h(lch, 0.33, 1);
	else if (lch->x == -1)
		rot_camera(lch->ry, (10 * (M_PI / 180)));
	else if (lch->x == -2)
		rot_camera(lch->ry, -(10 * (M_PI / 180)));
	if (lch->x != 0)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		print_screen(lch);
	}
	return (0);
}

int	key_p(int key, t_game *lch)
{
	if (key == 53)
		mlx_destroy_image(lch->mlx, lch->mlx_win);
		exit(1);//
	if (key == 13)
		lch->x = 1;
	else if (key == 1)
		lch->x = 2;
	else if (key == 0)
		lch->x = 3;
	else if (key == 2)
		lch->x = 4;
	else if (key == 123)
		lch->x = -1;
	else if (key == 124)
		lch->x = -2;
	return (0);
}

int	key_rl(int key, t_game *lch)
{
	if (key == 13)
		lch->x = 0;
	else if (key == 1)
		lch->x = 0;
	else if (key == 0)
		lch->x = 0;
	else if (key == 2)
		lch->x = 0;
	else if (key == 123)
		lch->x = 0;
	else if (key == 124)
		lch->x = 0;
	return (0);
}

int	close_window(int key, t_game *lch)
{
	(void)lch;
	if (key)
		printf("%d\n", key);//limpiar codigo, cerrar ventana
	return (0);
}
