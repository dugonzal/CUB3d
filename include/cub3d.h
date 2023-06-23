#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

//Nosé si es necesario
# define NO	0
# define SO	1
# define WE	2
# define EA	3
# define F	4
# define C	5

typedef struct s_lch
{
	void			*mlx;
	void			*mlx_win;
	struct s_img	*img;
	struct s_map	*map;
}			t_lch;

typedef struct s_img
{
	char	*img;
	void	*img_w;
}			t_img;

typedef struct s_map
{
	char	**map;
	char	**DIRC;//6//iniciar el ** en 6
}			t_map;

//Error
int		ft_error_msg(char *str);

//Read_map
int		read_map(t_lch *lch, char **av);

//Utils
char	*ft_strdup(const char *src);
int		ft_strcmp(char *str, char *str2);

int		check_walls(t_map *map);

//Launch_MLX
int		init_mlx(t_lch *lch);

#endif
