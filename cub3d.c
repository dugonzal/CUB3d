#include "../include/cub3d.h"

//falta comprobar q fd exista o algo
void launcher(t_lch *lch, char **av)
{
  int i;

  i = map_len(av[1], 0);
  (void)lch;
  printf ("%d\n", i);
}
int	main(int ac, char **av)
{
	t_lch	lch;

	if (ac != 2)
		return (err_ret("Error: Invalid arguments"));
  ft_bzero(&lch, sizeof(t_lch));
  launcher(&lch, av);
   return (0);
}
