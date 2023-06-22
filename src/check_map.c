#include "../include/cub3d.h"

int	check_space_y(t_map *map, int x, int y, int n)//orizontal
{
	int	i;

	i = 0;
	while (y + i > 0 && map->map[x][y] && map->map[x][y + i] == ' ')
		i += n;
	if (y + i >= 0 && y + i < 0 && map->map[x][y + i] != '\0' && map->map[x][y + i] != '1')
		return (1);
	return (0);
}

int	check_space_x(t_map *map, int x, int y, int n)//vertical
{
	int	i;

	i = 0;
	while (x + i > 0 && map->map[x + i] && map->map[x + i][y] == ' ')
		i += n;
	if (x + i < 0 && map->map[x + i] != NULL && map->map[x + i][y] != '1')
		return (1);
	return (0);
}

int	check_space(t_map *map)
{
	int	x;
	int	y;
	int	i;

	x = 1;
	i = 0;
	while (map->map[x] != NULL)
	{
		y = 0;
		while (map->map[x][y])
		{
			if (map->map[x][y] == ' ')
			{
				i += check_space_x(map, x, y, 1);
				i += check_space_x(map, x, y, -1);
				i += check_space_y(map, x, y, 1);
				i += check_space_y(map, x, y, -1);
			}
			y++;
		}
		x++;
	}
	if (i > 0)
		return (ft_error_msg("Error: "));//map sin cerrar
	return (0);
}

int	check_walls(t_map *map)
{
	int	i[3];//0: x, 1: y, 2: contador de jugadores
	
	i[0] = 0;
	i[2] = 0;
	while (map->map[i[0]++])
	{
		i[1] = 0;
		if (map->map[i[0]] != NULL && map->map[i[0]][ft_strlen(map->map[i[0]]) - 2] != '1')
			return (ft_error_msg("Error: 3"));//error de map sin cerrar
		while (map->map[i[0]] != NULL && map->map[i[0]][i[1]])
		{
			while (map->map[i[0]][i[1]] == ' ' && map->map[i[0]][i[1]] != '\0')
			{
				if (map->map[i[0]][i[1]] != ' ' && map->map[i[0]][i[1]] != '1')
					return (ft_error_msg("Error: 2"));//error de map sin cerrar
				i[1]++;
			}
			if (map->map[i[0]][i[1]] == 'N' || map->map[i[0]][i[1]] == 'S'\
			 || map->map[i[0]][i[1]] == 'E' || map->map[i[0]][i[1]] == 'W')
				i[2]++;
			i[1]++;
		}
	}
	if (i[2] != 1)
		return (ft_error_msg("Error: 1"));//mensaje de numero de jugadores invalido
	return (check_space(map));
}

//recorro todo el mapa, 
//1- compruebo los laterales ***
//2- compruebo q los espacios estan cerrados por muros ***///
//3- 1 solo jugador ***

//ck muros laterales ***
//ck muros laterales segun tamaño, para las rectas de muro
//ck espacions, si estan rodeados de nada, espacios o muros


//añadir tabulaciones ademas de espacios