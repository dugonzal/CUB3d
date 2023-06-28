#include "../include/cub3d.h"

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	printRay3(t_lch *lch, int start, int end, int x, int color)
{
	int	i;
	(void)color;

	i = start;
	//printf("%d\n%d\n", start, end);
	while (i++ < end)
		my_mlx_pixel_put(lch->img, x, i, color);
}

int	keyhook2(int keycode, t_lch *lch)
{
	t_ry *ry = lch->ry;
	double	moveSpeed = 1;
	double	rotSpeed = 10 * (M_PI / 180);

	if (keycode == 53)
		exit(1);
	//else
	//	printf("Keycode -> %d\n", keycode);
	//126 arriba, 123 der, 124, iz, 125 abajo
	if (keycode == 126)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		if(worldMap[(int)(ry->posX + ry->dirX * moveSpeed)][(int)(ry->posY)] == false) ry->posX += ry->dirX * moveSpeed;
    	if(worldMap[(int)(ry->posX)][(int)(ry->posY + ry->dirY * moveSpeed)] == false) ry->posY += ry->dirY * moveSpeed;
		print_screen(lch);
	}
	else if (keycode == 125)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		if(worldMap[(int)(ry->posX - ry->dirX * moveSpeed)][(int)(ry->posY)] == false) ry->posX -= ry->dirX * moveSpeed;
		if(worldMap[(int)(ry->posX)][(int)(ry->posY - ry->dirY * moveSpeed)] == false) ry->posY -= ry->dirY * moveSpeed;
		print_screen(lch);
	}
	else if (keycode == 124)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		double oldDirX = ry->dirX;
    	ry->dirX = ry->dirX * cos(-rotSpeed) - ry->dirY * sin(-rotSpeed);
    	ry->dirY = oldDirX * sin(-rotSpeed) + ry->dirY * cos(-rotSpeed);
    	double oldPlaneX = ry->planeX;
    	ry->planeX = ry->planeX * cos(-rotSpeed) - ry->planeY * sin(-rotSpeed);
    	ry->planeY = oldPlaneX * sin(-rotSpeed) + ry->planeY * cos(-rotSpeed);
		print_screen(lch);
	}
	else if (keycode == 123)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		double oldDirX = ry->dirX;
    	ry->dirX = ry->dirX * cos(rotSpeed) - ry->dirY * sin(rotSpeed);
    	ry->dirY = oldDirX * sin(rotSpeed) + ry->dirY * cos(rotSpeed);
    	double oldPlaneX = ry->planeX;
    	ry->planeX = ry->planeX * cos(rotSpeed) - ry->planeY * sin(rotSpeed);
    	ry->planeY = oldPlaneX * sin(rotSpeed) + ry->planeY * cos(rotSpeed);
		print_screen(lch);
	}
	return (0);
}

int	RY(t_lch *lch)
{
	int	x;
	//t_map *map = lch->map;
	t_ry *ry = lch->ry;
	
	x = 0;

	//-------------------------
	
	/*double posX = 22;
	double posY = 12;
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;*/

	//double time = 0;
	//double oldtime = 0;

	/*lch->posX, lch->posY;
	lch->dirX, lch->dirY;
	lch->planeX, lch->planeY;*/

	//-------------------------

		while (x++ < W)
		{
			ry->cameraX = 2 * x / (double)W - 1;
			
			ry->rayDirX = ry->dirX + ry->planeX * ry->cameraX;
			ry->rayDirY = ry->dirY + ry->planeY * ry->cameraX;

			ry->mapX = (int)ry->posX;
			ry->mapY = (int)ry->posY;


			ry->deltaDistX = (ry->rayDirX == 0) ? 1e30 : fabs(1 / ry->rayDirX);
			ry->deltaDistY = (ry->rayDirX == 0) ? 1e30 : fabs(1 / ry->rayDirY);

			int	hit = 0;
			int	side;

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
				if (worldMap[ry->mapX][ry->mapY] > 0)
					hit = 1;
			}

			if (side == 0)
				ry->perpWallDist = (ry->sideDistX - ry->deltaDistX);
			else
				ry->perpWallDist = (ry->sideDistY - ry->deltaDistY);
			
			int	lineHeight = (int)(H / ry->perpWallDist);

			int	drawStart = -lineHeight / 2 + H / 2;
			if (drawStart < 0)
				drawStart = 0;
			int	drawEnd = lineHeight / 2 + H / 2;
			if (drawEnd >= H)
				drawEnd = H - 1;
			
			//ColorRGB color;
			//asig color
			int	color = 2;
			switch(worldMap[ry->mapX][ry->mapY])
			{
				case 1: color = 0x335BFF;
					break;
				case 2: color = 0xFF3350;
					break;
				case 3: color = 0xEDFF33;
					break;
				case 4: color = 0x49FF33;
					break;
				default: color = 0x000000;
					break;
			}
			printRay3(lch, drawStart, drawEnd, x, color);
			//draw pixel of  sprite as a vertical line
		}
	return (0);
}
