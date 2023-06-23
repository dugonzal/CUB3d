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

//uso del teclado
int	keyhook(int keycode, t_lch *lch)
{
	(void)lch;
	if (keycode == 53)
		exit(1);
	else
		printf("Keycode -> %d\n", keycode);
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
	//t_img	*img = lch->img;

	lch->mlx = mlx_init();
	lch->mlx_win = mlx_new_window(lch->mlx, 2001, 1001, "");

	//RY(lch);
	//lch->img = init_img(lch);
	
	
	
	//void *screm_img = mlx_new_image(lch->mlx, 2001, 1001);
	lch->img->img_w = mlx_new_image(lch->mlx, 2001, 1001);
	lch->img->addr = mlx_get_data_addr(lch->img->img_w, &lch->img->bits_per_pixel, &lch->img->line_length, &lch->img->endian);
	int	y = 0;
	int x = 0;
	while(x++ < 2000)
	{
		my_mlx_pixel_put(lch->img, x, y, 0x00FF0000);
		if (x == 2000)
		{
			y++;
			if (y == 500)
				break;
			x = 0;
		}
	}
	x = 0;
	while(x++ < 2000)
	{
		my_mlx_pixel_put(lch->img, x, y, 0x339CFF);
		if (x == 2000)
		{
			y++;
			if (y == 1000)
				break;
			x = 0;
		}
	}
	//RY(lch);
	raycasting(lch);
	mlx_put_image_to_window(lch->mlx, lch->mlx_win, lch->img->img_w, 0, 0);


	// crea una imagen
	// pone el pixel en la pantalla
	// pone la imagen en la pantalla


	// crear una imagen
	// poner TODS los pixeles
	// poner la imagen en la pantalla


	mlx_key_hook(lch->mlx_win, keyhook, &lch);//ft provisional
	mlx_loop(lch->mlx);
	return (0);
}