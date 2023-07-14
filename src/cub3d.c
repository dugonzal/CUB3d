#include "../include/cub3d.h"

//inicia las var de la struct map
void	init_struct(t_game *lch)
{
	t_map	*map;
	t_img	*img;
	t_ry	*ry;

	ry = (t_ry *)ft_calloc(sizeof(t_ry), 1);
 	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	img = (t_img *)ft_calloc(sizeof(t_img), 1);
	lch->map = map;
	lch->img = img;
	lch->ry = ry;
}

//falta comprobar q fd exista o algo
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (err_ret("Error: Invalid arguments"));
 	ft_bzero(&game, sizeof(t_game));
	init_struct(&game);
	parser (&game, av);
	if (init_mlx(&game))
		return (1);
	return (0);
}
