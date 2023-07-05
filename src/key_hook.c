#include "../include/cub3d.h"

int	key_p(int key, t_lch *lch)
{
	if (key == 53)
		exit(1);
	if (key == 126)
		lch->x = 1;
	else if (key == 125)
		lch->x = 2;
	else if (key == 123)
		lch->x = -1;
	else if (key == 124)
		lch->x = -2;
	return (0);
}

int	key_rl(int key, t_lch *lch)
{
	if (key == 126)
		lch->x = 0;
	else if (key == 125)
		lch->x = 0;
	else if (key == 123)
		lch->x = 0;
	else if (key == 124)
		lch->x = 0;
	return (0);
}