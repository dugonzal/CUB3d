#include "../../include/cub3d.h"

void	printRay2(t_lch *lch, int start, int end, int x, int color)
{
	int	i;
	(void)color;

	i = start;
	while (i++ < end)
		my_mlx_pixel_put(lch->img, x, i, 0x33FF5B);
}

int		ryc(t_lch *lch)
{
	(void)lch;
	double	pa = 1.5;
	double	wa = 3;
	double	d = 6;

	double	pov = (60 * (M_PI / 180));
	double	r2 = (((pa / wa) * W) / (pov / 2));
	int hw = (int)((wa / d) * r2);

	//double	dib = (pa / wa) / 3;
	int	i = 250 - (hw / 2);
	int	z = 250 + (hw / 2);
	int	x = i;
	while (i < z)
	{
		printRay2(lch, x, z, i, 0xffffff);
		i++;
	}

	return (0);
}