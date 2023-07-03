#include "../../include/cub3d.h"

void	printRay(t_lch *lch, int start, int end, int x)//quitar color
{
	int	i;

	i = start;
	while (i++ < end)
		my_mlx_pixel_put(lch->img, x, i, 0x33FF5B);
}

void	wall_dist(t_lch *lch, t_ry *ry, int side, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	if (side == 0)
		ry->perpWallDist = (ry->sideDistX - ry->deltaDistX);
	else
		ry->perpWallDist = (ry->sideDistY - ry->deltaDistY);
	line_height = (int)(H / ry->perpWallDist);
	draw_start = -line_height / 2 + H / 2;
	draw_end = line_height / 2 + H / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= H)
		draw_end = H - 1;
	printRay(lch, draw_start, draw_end, x);
}

int	hit_wall(t_ry *ry, t_map *map)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (ry->sideDistX < ry->sideDistY)
		{
			ry->sideDistX += ry->deltaDistX;
			ry->mapX += ry->stepX;
			side = 0;
		}
		else
		{
			ry->sideDistY += ry->deltaDistY;
			ry->mapY += ry->stepY;
			side = 1;
		}
		if (map->map[ry->mapX][ry->mapY] == '1')
			hit = 1;
	}
	return (side);
}

void	set_step(t_ry *ry)
{
	if (ry->rayDirX < 0)
	{
		ry->stepX = -1;
		ry->sideDistX = (ry->posX - ry->mapX) * ry->deltaDistX;
	}
	else
	{
		ry->stepX = 1;
		ry->sideDistX = (ry->mapX + 1.0 - ry->posX) * ry->deltaDistX;
	}
	if (ry->rayDirY < 0)
	{
		ry->stepY = -1;
		ry->sideDistY = (ry->posY - ry->mapY) * ry->deltaDistY;
	}
	else
	{
		ry->stepY = 1;
		ry->sideDistY = (ry->mapY + 1.0 - ry->posY) * ry->deltaDistY;
	}
}

void	init_ry(t_ry *ry)
{
	ry->posX = 12;
	ry->posY = 26;
	ry->dirX = 1;
	ry->dirY = 0;
	ry->planeX = 0;
	ry->planeY = 0.66;
	ry->stepX = 1;
	ry->stepY = 1;
	/*ry->posX = 22;
	ry->posY = 12;
	ry->dirX = -1;
	ry->dirY = 0;
	ry->planeX = 0;
	ry->planeY = 0.66;
	ry->stepX = 1;
	ry->stepY = 1;*/
}

int	raycasting(t_lch *lch)
{
	t_map	*map;
	t_ry	*ry;
	int		x;
	int		side;

	map = lch->map;
	ry = lch->ry;
	x = 0;
	while (x++ < W)
	{
		ry->cameraX = 2 * x / (double)W - 1;
		ry->rayDirX = ry->dirX + ry->planeX * ry->cameraX;
		ry->rayDirY = ry->dirY + ry->planeY * ry->cameraX;
		ry->mapX = (int)ry->posX;
		ry->mapY = (int)ry->posY;
		ry->deltaDistX = fabs(1 / ry->rayDirX);
		ry->deltaDistY = fabs(1 / ry->rayDirY);
		if (1 / ry->deltaDistX == 0)
			ry->deltaDistX = 1e30;
		if (1 / ry->deltaDistY == 0)
			ry->deltaDistY = 1e30;
		set_step(ry);
		side = hit_wall(ry, map);
		wall_dist(lch, ry, side, x);
	}
	return (0);
}
