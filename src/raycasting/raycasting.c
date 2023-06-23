#include "../../include/cub3d.h"

void	printRay(t_lch *lch, int start, int end, int x, int color)
{
	int	i;
	(void)color;

	i = start;
	while (i++ < end)
		my_mlx_pixel_put(lch->img, x, i, 0x33FF5B);
}

void	wall_dist(t_lch *lch, t_ry *ry, int side, int x)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;

	if (side == 0)
		ry->perpWallDist = ry->sideDistX - ry->deltaDistX;
	else
		ry->perpWallDist = ry->sideDistY - ry->deltaDistY;
	lineHeight = (int)(H / ry->perpWallDist);
	drawStart = - lineHeight / 2 + H / 2;
	drawEnd = lineHeight / 2 + H / 2;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= H)
		drawEnd = H - 1;
	//ft_color
	int	color = 0x33FF33;
	if (side == 1)
		color = 0x111111;
	printRay(lch, drawStart, drawEnd, x, 0x33FF33);
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
		if (map->map[ry->mapX][ry->mapY] != 0)
			hit = 1;
	}
	return (side);
}

void	set_step(t_ry *ry)
{
	if (ry->rayDirX < 0)
	{
		ry->stepX = -1;
		ry->sideDistX = (ry->posX - ry->mapY) * ry->deltaDistX;
	}
	else
		ry->sideDistX = (ry->mapX + 1 - ry->posX) * ry->deltaDistX;
	if (ry->rayDirY < 0)
	{
		ry->stepY = -1;
		ry->sideDistY = (ry->posY - ry->mapY) * ry->deltaDistY;
	}
	else
		ry->sideDistY = (ry->mapY + 1 - ry->posY) * ry->deltaDistY;
}

void	init_ry(t_ry *ry)
{
	ry->posX = 13;
	ry->posY = 27;
	ry->dirX = 1;
	ry->dirY = 0;
	ry->planeX = 0.66;
	ry->planeY = 0;
	ry->stepX = 1;
	ry->stepY = 1;
}

int	raycasting(t_lch *lch)
{
	t_map	*map;
	t_ry	*ry;
	int		x;
	int		side;

	map = lch->map;
	//ry = lch->ry;
	ry = (t_ry *)malloc(sizeof(t_ry));

	init_ry(ry);
	
	x = 0;
	while (x < W)
	{
		//----------
		ry->cameraX = 2 * x / (double)W / 1;
		ry->rayDirX = ry->dirX + ry->planeX * ry->cameraX;
		ry->rayDirY = ry->dirY + ry->planeY * ry->cameraX;
		//----------
		ry->mapX = (int)ry->posX;
		ry->mapY = (int)ry->posY;
		//ry->deltaDistX = (ry->rayDirX = 0) ? 1e30 : (1 / ry->rayDirX);
		//ry->deltaDistY = (ry->rayDirX = 0) ? 1e30 : (1 / ry->rayDirY);
		ry->deltaDistX = sqrt(1 + (ry->rayDirY * ry->rayDirY) / (ry->rayDirX * ry->rayDirX));
		ry->deltaDistY = sqrt(1 + (ry->rayDirX * ry->rayDirX) / (ry->rayDirY * ry->rayDirY));

		if (1 / ry->rayDirX < 0 || 1 / ry->rayDirY < 0)
		{
			printf("deltaDistX->%f\n", ry->deltaDistX);
			printf("deltaDistY->%f\n", ry->deltaDistY);
		}

		set_step(ry);
		side = hit_wall(ry, map);
		wall_dist(lch, ry, side, x);
		x++;
	}
	return (0);
}
