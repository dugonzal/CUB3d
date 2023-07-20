/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:44:23 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 13:47:00 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (key)
		free_error(lch, "");
	return (0);
}
