/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lch_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:12:04 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/20 22:12:14 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	print_f_c(t_game *lch, int x, int y, int color)
{
	int	z;

	z = H / 2;
	if (y >= H / 2)
		z = H;
	while (x++ < W)
	{
		my_mlx_pixel_put(&lch->img[4], x, y, color);
		if (x == W)
		{
			if (++y == z)
				break ;
			x = 0;
		}
	}
	return (y);
}

//uso del teclado
void	print_screen(t_game *lch)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	y = print_f_c(lch, x, y, lch->map->f);
	x = 0;
	print_f_c(lch, x, y, lch->map->c);
	raycasting(lch);
	mlx_put_image_to_window(lch->mlx, lch->mlx_win, lch->img[4].img_w, 0, 0);
}

void	open_img(t_game	*lch)
{
	int	i;
	int	z;

	i = 0;
	z = 64;
	while (i < 4)
	{
		lch->img[i].img_w = mlx_xpm_file_to_image(lch->mlx, \
		lch->img[i].path, &z, &z);
		if (!lch->img[i].img_w)
			free_error(lch, "No se ha podido abrir la imagen");
		lch->img[i].addr = mlx_get_data_addr(lch->img[i].img_w, &lch->img[i]. \
		bits_per_pixel, &lch->img[i].line_length, &lch->img[i].endian);
		i++;
	}
}

//incia mlx y la ventana
int	init_mlx(t_game *lch)
{
	lch->mlx = mlx_init();
	lch->mlx_win = mlx_new_window(lch->mlx, W + 1, H + 1, "");
	lch->map->f = get_int_color(lch->color[0].r, \
	lch->color[0].g, lch->color[0].b);
	lch->map->c = get_int_color(lch->color[1].r, \
	lch->color[1].g, lch->color[1].b);
	init_ry(lch->ry);
	open_img(lch);
	lch->img[4].img_w = mlx_new_image(lch->mlx, W + 1, H + 1);
	lch->img[4].addr = mlx_get_data_addr(\
	lch->img[4].img_w, &lch->img[4].bits_per_pixel, \
	&lch->img[4].line_length, &lch->img[4].endian);
	print_screen(lch);
	mlx_hook(lch->mlx_win, 17, 0, close_window, lch);
	mlx_hook(lch->mlx_win, 02, 0, key_p, lch);
	mlx_hook(lch->mlx_win, 03, 0, key_rl, lch);
	mlx_loop_hook(lch->mlx, keyhook, lch);
	mlx_loop(lch->mlx);
	return (0);
}
