#include "../include/cub3d.h"

void	printRay(t_lch *lch, int start, int end, int x, int color)
{
	int	i;
	(void)color;

	i = start;
	printf("%d\n%d\n", start, end);
	while (i++ < end)
		my_mlx_pixel_put(lch->img, x, i, 0x33FF5B);
}

int	RY(t_lch *lch)
{
	int	x;
	t_map *map = lch->map;
	
	x = 0;

	//-------------------------
	
	lch->posX = 13;
	lch->posY = 27;
	lch->dirX = 1;
	lch->dirY = 0;
	lch->planeX = 0;
	lch->planeY = 0.66;

	/*lch->posX, lch->posY;
	lch->dirX, lch->dirY;
	lch->planeX, lch->planeY;*/

	//-------------------------

		while (x < W)
		{
			double	cameraX = 2 * x / (double)W / 1;
			
			double	rayDirX = lch->dirX + lch->planeX * cameraX;
			double	rayDirY = lch->dirY + lch->planeY * cameraX;

			int	mapX = (int)lch->posX;
			int	mapY = (int)lch->posY;

			double	sideDistX;
			double	sideDistY;

			unsigned int abs;

			abs = 1 / rayDirX;//
			double	deltaDistX = (rayDirX == 0) ? 1e30 : abs;
			abs = 1 / rayDirY;
			double	deltaDistY = (rayDirX == 0) ? 1e30 : abs;

			double perpWallDist;

			int	stepX;
			int	stepY;

			int	hit = 0;
			int	side;

			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (lch->posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - lch->posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (lch->posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - lch->posY) * deltaDistY;
			}

			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (map->map[mapX][mapY] != 0)
					hit = 1;
			}

			if (side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistX);
			
			int	lineHeight = (int)(H / perpWallDist);

			int	drawStart = -lineHeight / 2 + H / 2;
			if (drawStart < 0)
				drawStart = 0;
			int	drawEnd = lineHeight / 2 + H / 2;
			if (drawEnd >= H)
				drawEnd = H - 1;
			
			//ColorRGB color;
			//asig color
			int	color = 2;
			if (side == 1)
				color = color / 2;
			printRay(lch, drawStart, drawEnd, x, color);
			x++;
			//draw pixel of  sprite as a vertical line
		}
	return (0);
}
