/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:17:03 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/26 10:44:43 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_camera_v(t_game *lch, double move_speed, int i)
{
	t_ry	*ry;
	int		x;
	int		y;

	ry = lch->ry;
	if (i == 1)
	{
		x = (int)(ry->pos_x + ry->dir_x * move_speed);
		y = (int)(ry->pos_y + ry->dir_y * move_speed);
		if (lch->map->map[x][(int)(ry->pos_y)] != '1')
			ry->pos_x += ry->dir_x * move_speed;
		if (lch->map->map[(int)(ry->pos_x)][y] != '1')
			ry->pos_y += ry->dir_y * move_speed;
	}
	else
	{
		x = (int)(ry->pos_x - ry->dir_x * move_speed);
		y = (int)(ry->pos_y - ry->dir_y * move_speed);
		if (lch->map->map[x][(int)(ry->pos_y)] != '1')
			ry->pos_x -= ry->dir_x * move_speed;
		if (lch->map->map[(int)(ry->pos_x)][y] != '1')
			ry->pos_y -= ry->dir_y * move_speed;
	}
}

void	move_camera_h(t_game *lch, double mov_speed, int i)
{
	if (i == 1)
	{
		rot_camera(lch->ry, -(90 * (M_PI / 180)));
		move_camera_v(lch, mov_speed / 2, 1);
		rot_camera(lch->ry, (90 * (M_PI / 180)));
	}
	else
	{
		rot_camera(lch->ry, (90 * (M_PI / 180)));
		move_camera_v(lch, mov_speed / 2, 1);
		rot_camera(lch->ry, -(90 * (M_PI / 180)));
	}
}

void	rot_camera(t_ry *ry, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ry->dir_x;
	old_plane_x = ry->plane_x;
	ry->dir_x = ry->dir_x * cos(rot_speed) - ry->dir_y * sin(rot_speed);
	ry->dir_y = old_dir_x * sin(rot_speed) + ry->dir_y * cos(rot_speed);
	ry->plane_x = ry->plane_x * cos(rot_speed) - ry->plane_y * sin(rot_speed);
	ry->plane_y = old_plane_x * sin(rot_speed) + ry->plane_y * cos(rot_speed);
}
