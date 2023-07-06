#include "../include/cub3d.h"

int	ft_error_msg(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

//inicia las var de la struct map
int	init_lch_var(t_lch *lch)
{
	t_map	*map;
	t_img	*img;
	t_ry	*ry;//

	map = (t_map *)malloc(sizeof(t_map));
	img = (t_img *)malloc(sizeof(t_img));
	ry = (t_ry *)malloc(sizeof(t_ry));
	lch->map = map;
	lch->img = img;
	lch->ry = ry;
	map->DIRC = (char **)malloc(sizeof(char *) * 7);
	map->DIRC[6] = NULL;
	if (!map || !img)
		return (1);
	return (0);
}

//falta comprobar q fd exista o algo
int	main(int ac, char **av)
{
	t_lch	lch;

	if (ac != 2)
		return (ft_error_msg("Error: Invalid arguments"));
	if (init_lch_var(&lch) || read_map(&lch, av))
		return (1);
	if (check_walls(lch.map))
		return (printf("Error: "));
	if (init_mlx(&lch))
		return (1);
	return (0);
}
