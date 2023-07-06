#include "../include/cub3d.h"

void	move_camera(t_lch *lch, double move_speed, int i)
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

//126 arriba, 123 der, 124, iz, 125 abajo
int	keyhook(t_lch *lch)
{
	if (lch->x == 1)
		move_camera(lch, 0.33, 1);
	else if (lch->x == 2)
		move_camera(lch, 0.33, -1);
	else if (lch->x == -1)
		rot_camera(lch->ry, -(10 * (M_PI / 180)));
	else if (lch->x == -2)
		rot_camera(lch->ry, (10 * (M_PI / 180)));
	if (lch->x != 0)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		print_screen(lch);
	}
	return (0);
}

int	key_p(int key, t_lch *lch)
{
	if (key == 53)
		exit(1);
	if (key == 126)
		lch->x = 1;
	else if (key == 125)
		lch->x = 2;
	else if (key == 123)
		lch->x = -1;
	else if (key == 124)
		lch->x = -2;
	return (0);
}

int	key_rl(int key, t_lch *lch)
{
	if (key == 126)
		lch->x = 0;
	else if (key == 125)
		lch->x = 0;
	else if (key == 123)
		lch->x = 0;
	else if (key == 124)
		lch->x = 0;
	return (0);
}
