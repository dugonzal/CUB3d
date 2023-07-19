/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:11:56 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/19 13:11:59 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	wall_dist(t_game *lch, t_ry *ry, int side, int x)
{
	int	line_height;
	int	draw[2];

	if (side == 0)
		ry->perp_wall_dist = (ry->side_dist_x - ry->delta_dist_x);
	else
		ry->perp_wall_dist = (ry->side_dist_y - ry->delta_dist_y);
	line_height = (int)(H / ry->perp_wall_dist);
	draw[0] = -line_height / 2 + H / 2;
	draw[1] = line_height / 2 + H / 2;
	if (draw[0] < 0)
		draw[0] = 0;
	if (draw[1] >= H)
		draw[1] = H - 1;
	ry->step = 1.0 * 64 / line_height;
	ry->tex_pos = (draw[0] - H / 2 + line_height / 2) * ry->step;
	print_ray(lch, draw, x, side);
}

int	hit_wall(t_ry *ry, t_map *map)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (ry->side_dist_x < ry->side_dist_y)
		{
			ry->side_dist_x += ry->delta_dist_x;
			ry->map_x += ry->step_x;
			side = 0;
		}
		else
		{
			ry->side_dist_y += ry->delta_dist_y;
			ry->map_y += ry->step_y;
			side = 1;
		}
		if (map->map[ry->map_x][ry->map_y] == '1')
			hit = 1;
	}
	return (side);
}

void	set_step(t_ry *ry)
{
	if (ry->ray_dir_x < 0)
	{
		ry->step_x = -1;
		ry->side_dist_x = (ry->pos_x - ry->map_x) * ry->delta_dist_x;
	}
	else
	{
		ry->step_x = 1;
		ry->side_dist_x = (ry->map_x + 1.0 - ry->pos_x) * ry->delta_dist_x;
	}
	if (ry->ray_dir_y < 0)
	{
		ry->step_y = -1;
		ry->side_dist_y = (ry->pos_y - ry->map_y) * ry->delta_dist_y;
	}
	else
	{
		ry->step_y = 1;
		ry->side_dist_y = (ry->map_y + 1.0 - ry->pos_y) * ry->delta_dist_y;
	}
}

void	init_ry(t_ry *ry)
{
	ry->dir_x = -1;
	ry->dir_y = 0;
	ry->plane_x = 0;
	ry->plane_y = 0.66;
	if (ry->dir == 'N')
		rot_camera(ry, -(0 * (M_PI / 180)));
	else if (ry->dir == 'W')
		rot_camera(ry, -(90 * (M_PI / 180)));
	else if (ry->dir == 'E')
		rot_camera(ry, (90 * (M_PI / 180)));
	else if (ry->dir == 'S')
		rot_camera(ry, -(180 * (M_PI / 180)));
}

int	raycasting(t_game *lch)
{
	t_ry	*ry;
	int		x;
	int		side;

	ry = lch->ry;
	x = 0;
	while (x++ < W)
	{
		ry->camera_x = 2 * x / (double)W - 1;
		ry->ray_dir_x = ry->dir_x + ry->plane_x * ry->camera_x;
		ry->ray_dir_y = ry->dir_y + ry->plane_y * ry->camera_x;
		ry->map_x = (int)ry->pos_x;
		ry->map_y = (int)ry->pos_y;
		ry->delta_dist_x = fabs(1 / ry->ray_dir_x);
		ry->delta_dist_y = fabs(1 / ry->ray_dir_y);
		if (1 / ry->delta_dist_x == 0)
			ry->delta_dist_x = 1e30;
		if (1 / ry->delta_dist_y == 0)
			ry->delta_dist_y = 1e30;
		set_step(ry);
		side = hit_wall(ry, lch->map);
		wall_dist(lch, ry, side, x);
	}
	return (0);
}
