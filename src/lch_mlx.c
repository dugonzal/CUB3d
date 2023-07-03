#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	write_line(t_lch *lch, int x, int y, int color)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	printf("123\n");
	img->img_w = mlx_new_image(lch->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img_w, &img->bits_per_pixel, &img->line_length, &img->endian);
	my_mlx_pixel_put(img, 10, 10, color);
	mlx_put_image_to_window(lch->mlx, lch->mlx_win, img->img_w, x, y);
}

void	moveCamera(t_lch *lch, double moveSpeed, int i)
{
	t_ry *ry;

	ry = lch->ry;
	if (i == 1)
	{
		if (lch->map->map[(int)(ry->posX + ry->dirX * moveSpeed)][(int)(ry->posY)] != '2')
			ry->posX += ry->dirX * moveSpeed;
		if (lch->map->map[(int)(ry->posX)][(int)(ry->posY + ry->dirY * moveSpeed)] != '2')
			ry->posY += ry->dirY * moveSpeed;
	}
	else
	{
		if (lch->map->map[(int)(ry->posX - ry->dirX * moveSpeed)][(int)(ry->posY)] != '2')
			ry->posX -= ry->dirX * moveSpeed;
		if (lch->map->map[(int)(ry->posX)][(int)(ry->posY - ry->dirY * moveSpeed)] != '2')
			ry->posY -= ry->dirY * moveSpeed;
	}
}

void	rotCamera(t_ry *ry, double rotSpeed)
{
	double	oldDirX;
	double	oldPlanerX;

	oldDirX = ry->dirX;
	oldPlanerX = ry->planeX;
	ry->dirX = ry->dirX * cos(rotSpeed) - ry->dirY * sin(rotSpeed);
	ry->dirY = oldDirX * sin(rotSpeed) + ry->dirY * cos(rotSpeed);
	ry->planeX = ry->planeX * cos(rotSpeed) - ry->planeY * sin(rotSpeed);
	ry->planeY = oldPlanerX * sin(rotSpeed) + ry->planeY * cos(rotSpeed);
}

//uso del teclado
void	print_screen(t_lch *lch)
{
	int	y = 0;
	int x = 0;

	while(x++ < W)
	{
		my_mlx_pixel_put(lch->img, x, y, 0x000000);
		if (x == W)
		{
			y++;
			if (y == H / 2)
				break;
			x = 0;
		}
	}
	x = 0;
	while(x++ < W)
	{
		my_mlx_pixel_put(lch->img, x, y, 0x000000);
		if (x == W)
		{
			y++;
			if (y == H)
				break;
			x = 0;
		}
	}
	RY(lch);
	//raycasting(lch);
	//ryc(lch);
	mlx_put_image_to_window(lch->mlx, lch->mlx_win, lch->img->img_w, 0, 0);
}

int	keyhook(int keycode, t_lch *lch)
{
	if (keycode == 53)
		exit(1);
	//else
	//	printf("Keycode -> %d\n", keycode);
	//126 arriba, 123 der, 124, iz, 125 abajo
	if (keycode == 126)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		moveCamera(lch, 0.33, 1);
		print_screen(lch);
	}
	else if (keycode == 125)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		moveCamera(lch, 0.33, -1);
		print_screen(lch);
	}
	else if (keycode == 124)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		rotCamera(lch->ry, (10 * (M_PI / 180)));
		print_screen(lch);
	}
	else if (keycode == 123)
	{
		mlx_clear_window(lch->mlx, lch->mlx_win);
		rotCamera(lch->ry, -(10 * (M_PI / 180)));
		print_screen(lch);
	}
	return (0);
}

//lee las imagenes
t_img	*init_img(t_lch *lch)
{
	t_img	*img;
	int		x;
	int		y;

	x = 0;
	y = 0;
	img = lch->img;
	img->img = "../img/chest.xpm";
	img->img_w = mlx_xpm_file_to_image(lch->mlx, img->img, &x, &y);
	return (img);
}


//incia mlx y la ventana
int	init_mlx(t_lch *lch)
{
	lch->mlx = mlx_init();
	lch->mlx_win = mlx_new_window(lch->mlx, W + 1, H + 1, "");


	//----
	t_img	*data;
	int	z = 64;
	data = (t_img *)malloc(sizeof(t_img));
	data->img = "/Users/masla-la/Desktop/Cursus/P5/Cub3d/cub3d_2/img/123.xpm";
	data->img_w = mlx_xpm_file_to_image(lch->mlx, data->img, &z, &z);
	data->addr = mlx_get_data_addr(data->img_w, &data->bits_per_pixel, &data->line_length, &data->endian);
	lch->data = data;
	//----
	//RY(lch);
	//lch->img = init_img(lch);
	init_ry(lch->ry);
	
	
	
	//void *screm_img = mlx_new_image(lch->mlx, 2001, 1001);
	lch->img->img_w = mlx_new_image(lch->mlx, W + 1, H + 1);
	lch->img->addr = mlx_get_data_addr(lch->img->img_w, &lch->img->bits_per_pixel, &lch->img->line_length, &lch->img->endian);

	print_screen(lch);

	// crea una imagen
	// pone el pixel en la pantalla
	// pone la imagen en la pantalla


	// crear una imagen
	// poner TODS los pixeles
	// poner la imagen en la pantalla


	mlx_key_hook(lch->mlx_win, keyhook2, lch);//ft provisional
	mlx_loop(lch->mlx);
	return (0);
}