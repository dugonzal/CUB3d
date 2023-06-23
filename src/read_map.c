#include "../include/cub3d.h"

//devuelve el tamaño del mapa
int	map_len(char *file, int i)
{
	int	n;
	int fd;
	char *line;

	n = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		n++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (n - i + 1);
}

//copia el mapa
int	cpy_map(int	fd, int i, char *file, t_map *map)
{
	int		n;
	char	*line;

	n = 0;
	map->map = (char **)malloc(sizeof(char *) * map_len(file, i));
	if (!map->map)
		return (1);
	line = get_next_line(fd);//LINE SE QUEDA EN NULL, EL DIRC 5 (C) NOS E COPA CORRECTAMENTE
	while (line)
	{
		if (line[0] != '\n')
			map->map[n] = ft_strdup(line);
		if (!map->map[n])
			return (1);
		free(line);
		line = get_next_line(fd);
		n++;
	}
	free(line);
	map->map[n] = NULL;
	close(fd);
	return (0);
}

//reserva memoria y copiar el dirc correspondiente
int	malloc_dirc(char *line, t_map *map, int	dirc)
{
	while (*line != ' ')
		line++;
	line++;
	map->DIRC[dirc] = ft_strdup(line);
	if (!map->DIRC[dirc])
		return (1);
	return (0);
}

//devuelve la linea q deve de copiar en su posición correspondiente
int	check_dirc(char *line)
{
	char	*dirc[] = { "NO", "SO", "WE", "EA", "F", "C" };//
	int		i;

	i = 0;
	while (ft_strcmp(line, dirc[i]))
		i++;
	if (i == 6)
		return (0);
	return(i + 1);
}

//CAMBIAR LOS FD, NO PUEDOS ARRASTRAR LOS FD, ES PREFERIBLE CERRAR EL ARCHIVO
int	read_map(t_lch *lch, char **av)
{
	int 	fd;
	int		i[3];//linea a copiar = 0 , linea del archivo = 1, numero de lineas de dirc recorridas = 2
	char	*line;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	i[1] = 0;
	i[2] = 0;
	while (line && i[1]++ <= 6)
	{
		i[0] = check_dirc(line);
		if (line[0] != '\n')
		{
			if (malloc_dirc(line, lch->map, i[0]))
				return (ft_error_msg("Error: Malloc error"));
			i[2]++;
		}
		if (i[2] == 6)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (cpy_map(fd, i[1], av[1], lch->map));
}
