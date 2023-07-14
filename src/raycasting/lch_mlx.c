#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//uso del teclado
void	print_screen(t_game *lch)
{
	int	y = 0;
	int x = 0;

	while(x++ < W)
	{
		my_mlx_pixel_put(lch->img, x, y, 0x000000);//cambiar por el color del mapa
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
		my_mlx_pixel_put(lch->img, x, y, 0x000000);//cambiar por el color del mapa
		if (x == W)
		{
			y++;
			if (y == H)
				break;
			x = 0;
		}
	}
	//RY(lch);
	raycasting(lch);
	mlx_put_image_to_window(lch->mlx, lch->mlx_win, lch->img->img_w, 0, 0);
}

//incia mlx y la ventana
int	init_mlx(t_game *lch)
{
	lch->mlx = mlx_init();
	lch->mlx_win = mlx_new_window(lch->mlx, W + 1, H + 1, "");

	//----
	t_img	*data;
	t_img	*data2;
	t_img	*data3;
	t_img	*data4;
	int	z = 64;
	data = (t_img *)malloc(sizeof(t_img));
	data->img = "./img/123.xpm";//WE
	data->img_w = mlx_xpm_file_to_image(lch->mlx, data->img, &z, &z);
	data->addr = mlx_get_data_addr(data->img_w, &data->bits_per_pixel, &data->line_length, &data->endian);
	lch->data = data;
	data2 = (t_img *)malloc(sizeof(t_img));
	data2->img = "./img/bookshelf.xpm";//EA
	data2->img_w = mlx_xpm_file_to_image(lch->mlx, data2->img, &z, &z);
	data2->addr = mlx_get_data_addr(data2->img_w, &data2->bits_per_pixel, &data2->line_length, &data2->endian);
	lch->data2 = data2;
	data3 = (t_img *)malloc(sizeof(t_img));
	data3->img = "./img/wood3.xpm";//NO
	data3->img_w = mlx_xpm_file_to_image(lch->mlx, data3->img, &z, &z);
	data3->addr = mlx_get_data_addr(data3->img_w, &data3->bits_per_pixel, &data3->line_length, &data3->endian);
	lch->data3 = data3;
	data4 = (t_img *)malloc(sizeof(t_img));
	data4->img = "./img/bricksx64.xpm";//SO
	data4->img_w = mlx_xpm_file_to_image(lch->mlx, data4->img, &z, &z);
	data4->addr = mlx_get_data_addr(data4->img_w, &data4->bits_per_pixel, &data4->line_length, &data4->endian);
	lch->data4 = data4;
	//----

	init_ry(lch->ry);
	
	
	lch->img->img_w = mlx_new_image(lch->mlx, W + 1, H + 1);
	lch->img->addr = mlx_get_data_addr(lch->img->img_w, &lch->img->bits_per_pixel, &lch->img->line_length, &lch->img->endian);

	print_screen(lch);

	mlx_hook(lch->mlx_win, 02, 0, key_p, lch);
	mlx_hook(lch->mlx_win, 03, 0, key_rl, lch);
	mlx_loop_hook(lch->mlx, keyhook, lch);
	mlx_loop(lch->mlx);
	return (0);
}