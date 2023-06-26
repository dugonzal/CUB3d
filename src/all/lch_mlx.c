#include "../include/cub3d.h"

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
	img = (t_img *)malloc(sizeof(t_img));
	img->img = "../img/chest.xpm";
	img->img_w = mlx_xpm_file_to_image(lch->mlx, img->img, &x, &y);
	return (img);
}

//incia mlx y la ventana
int	init_mlx(t_lch *lch)
{
	lch->mlx = mlx_init();
	lch->mlx_win = mlx_new_window(lch->mlx, 30 * 64, 20 * 64, "");
	lch->img = init_img(lch);
	
	
	mlx_key_hook(lch->mlx_win, keyhook, &lch);//ft provisional
	mlx_loop(lch->mlx);
	return (0);
}