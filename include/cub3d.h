#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx_macos/mlx.h"

# include <stdbool.h>//

# define NO	0
# define SO	1
# define WE	2
# define EA	3
# define F	4
# define C	5

# define W 2000
# define H 1000

typedef struct s_game
{
	int				x;
	int				y;

	void			*mlx;
	void			*mlx_win;
	int				width;//tamaño de la ventana
	int				heigth;

	struct s_img	*img_temp[5];// NO, SO, WE, EA, IMGANE GLOBAL
	
	struct s_img	*img;
	struct s_img	*data;
	struct s_img	*data2;
	struct s_img	*data3;
	struct s_img	*data4;
	struct s_map	*map;
	struct s_ry		*ry;
}			t_game;

typedef struct	s_ry
{
	char	dir;//
	
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	step;
	int		tex_x;
	double	tex_pos;
}			t_ry;


typedef struct s_img
{
	char	*img;
	void	*img_w;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_map
{
	int		len_y;
	int		len_x;
	char	**buffer;
	char	**map;
	char	**DIRC;//6//iniciar el ** en 6
	int				f;
	int				c;
}			t_map;

//Error
int		ft_error_msg(char *str);

//Read_map
int		read_map(t_game *lch, char **av);

int		check_walls(t_map *map);

//Launch_MLX
int		init_mlx(t_game *lch);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

//--------------------------------------
int	RY(t_game *lch);
int	raycasting(t_game *lch);
void	init_ry(t_ry *ry);
int		ryc(t_game *lch);
void	print_screen(t_game *lch);
//--------------------------------------

//Print_Text
t_img	*select_text(t_game *lch, int side);
int		get_text_color(int x, int y, void *ptr);
int		text_side(t_ry *ry, int side);
void	print_ray(t_game *lch, int draw[2], int x, int side);

//KeyHooks
int	key_p(int key, t_game *lch);
int	key_rl(int key, t_game *lch);
int	keyhook(t_game *lch);

//Camera FT
void	rot_camera(t_ry *ry, double rot_speed);
void	move_camera_h(t_game *lch, double move_speed, int i);
void	move_camera_v(t_game *lch, double move_speed, int i);


//keyhook pruebas
int	keyhook3(t_game *lch);
int	keyhook2(int keycode, t_game *lch);

//
void	*free_array(char **str);
void	handler_flood_fill(t_game *game);
void	read_fd(t_game *game, int fd, char *av);
void	print(char **str);
int		parser(t_game *game, char **av);


int		get_int_color(int r, int g, int b);

#endif
