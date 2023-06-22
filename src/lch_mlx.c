#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	img->img = "../img/chest.xpm";
	img->img_w = mlx_xpm_file_to_image(lch->mlx, img->img, &x, &y);
	return (img);
}

//incia mlx y la ventana
int	init_mlx(t_lch *lch)
{
	//t_img	*img2 = lch->img;

	lch->mlx = mlx_init();
	lch->mlx_win = mlx_new_window(lch->mlx, 30 * 64, 20 * 64, "");

	//RY(lch);
	//lch->img = init_img(lch);
	
	//img->addr = mlx_get_data_addr(img->img_w, &img->bits_per_pixel, &img->line_length, &img->endian);
	
	
	/*void *img = mlx_new_image(lch->mlx, 1920, 1080);
	img2->img_w = img;
	img2->addr = mlx_get_data_addr(img2->img_w, &img2->bits_per_pixel, &img2->line_length, &img2->endian);
	my_mlx_pixel_put(img2, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(lch->mlx, lch->mlx_win, img, 100, 100);*/


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