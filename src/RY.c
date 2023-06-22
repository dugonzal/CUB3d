#include "../include/cub3d.h"

void	printRay(t_lch *lch, int start, int end, int color)
{
	int	i;
	t_img	*img = lch->img;
	
	i = start;
	if (color == 1)
		color = 0x00FF0000;
	else
		color = 0x00FF0000;
	img->img_w = mlx_new_image(lch->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img_w, &img->bits_per_pixel, &img->line_length, &img->endian);
	my_mlx_pixel_put(img, 10, 10, 0x00FF0000);
	//mlx_put_image_to_window(lch->mlx, lch->mlx_win, img, 100, 100);
	while (i++ < end)
		mlx_put_image_to_window(lch->mlx, lch->mlx_win, img, 100, 100);
}

int	RY(t_lch *lch)
{
	int	x;
	t_map *map = lch->map;
	int		w = 30;
	int		h = 14;

	x = 0;

	lch->posX = 13;
	lch->posY = 27;
	lch->dirX = 1;
	lch->dirY = 0;
	lch->planeX = 0;
	lch->planeY = 0.66;

	/*lch->posX, lch->posY;
	lch->dirX, lch->dirY;
	lch->planeX, lch->planeY;

	lch->time;
	lch->oldTime;*/

	while (x < 1)
	{
		while (x++ < w)
		{
			double	cameraX = 2 * x / (double)w / 1;
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
			
			int	lineHeight = (int)(h / perpWallDist);

			int	drawStart = -lineHeight / 2 + h / 2;
			if (drawStart < 0)
				drawStart = 0;
			int	drawEnd = lineHeight / 2 + h / 2;
			if (drawEnd >= h)
				drawEnd = h - 1;
			
			//ColorRGB color;
			//asig color
			int	color = 2;
			if (side == 1)
				color = color / 2;
			printRay(lch, drawStart, drawEnd, color);
			//draw pixel of  sprite as a vertical line
		}
		/*lch->oldTime = lch->time;
		lch->time = getTicks();
		double	frameTime = (lch->time - lch->oldTime) / 1000.0;
		//contador de fps

		lch->moveSpeed = frameTime * 5.0;
		lch->rotSpeed = frameTime * 3.0;*/
		
	}
	return (0);
}
