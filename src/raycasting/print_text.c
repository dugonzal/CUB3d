#include "../../include/cub3d.h"

t_img	*select_text(t_lch *lch, int side)
{
	t_ry	*ry;

	ry = lch->ry;
	if (side)
	{
		if (ry->ray_dir_y < 0)
			return (lch->data);
		else
			return (lch->data2);
	}
	else
	{
		if (ry->ray_dir_x < 0)
			return (lch->data3);
		else
			return (lch->data4);
	}
}

int	get_text_color(int x, int y, void *ptr)
{
	if (x >= 0 && x < 64 && y >= 0 && y < 64)
		return (*(int *)(ptr + (4 * 64 * y) + (4 * x)));
	return (0x0);
}

int	text_side(t_ry *ry, int side)
{
	double	wall_x;

	if (side == 0)
		wall_x = ry->pos_y + ry->perp_wall_dist * ry->ray_dir_y;
	else
		wall_x = ry->pos_x + ry->perp_wall_dist * ry->ray_dir_x;
	wall_x -= floor(wall_x);
	return ((int)(wall_x * (double)64));
}

void	print_ray(t_lch *lch, int draw[2], int x, int side)
{
	t_ry	*ry;
	t_img	*text;
	int		y;
	int		tex_y;
	int		color;

	text = NULL;
	ry = lch->ry;
	ry->tex_x = text_side(lch->ry, side);
	if (side == 0 && ry->ray_dir_x > 0)
		ry->tex_x = 64 - ry->tex_x - 1;
	if (side == 1 && ry->ray_dir_y < 0)
		ry->tex_x = 64 - ry->tex_x - 1;
	y = draw[0];
	while (y++ < draw[1])
	{
		tex_y = ry->tex_x & (64 - 1);
		ry->tex_pos += ry->step;
		text = select_text(lch, side);
		color = get_text_color(tex_y, ry->tex_pos, text->addr);
		my_mlx_pixel_put(lch->img, x, y, color);
	}
}
