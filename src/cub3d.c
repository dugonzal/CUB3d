#include "../include/cub3d.h"

//falta comprobar q fd exista o algo
int cub3d(t_game *game, char **av)
{
  if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		return  (err_ret("Error: Invalid file: extencion .cub;"));
  (void)game;
  return  (0);
}
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (err_ret("Error: Invalid arguments"));
  ft_bzero(&game, sizeof(t_game));
  cub3d (&game, av);
   return (0);
}
