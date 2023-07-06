#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# include <stdbool.h>//

# define NO	0
# define SO	1
# define WE	2
# define EA	3
# define F	4
# define C	5

# define W 2000
# define H 1000

typedef struct s_lch
{
	int				x;
	int				y;

	void			*mlx;
	void			*mlx_win;
	int				width;//tamaño de la ventana
	int				heigth;
	struct s_img	*img;
	struct s_img	*data;
	struct s_img	*data2;
	struct s_img	*data3;
	struct s_img	*data4;
	struct s_map	*map;
	struct s_ry		*ry;
}			t_lch;

typedef struct	s_ry
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;

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
	double		step;
	int		tex_x;
	double		tex_pos;
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
	char	**map;
	char	**DIRC;//NO, SO, WE, EA, F, C
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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

//--------------------------------------
int	RY(t_lch *lch);
int	raycasting(t_lch *lch);
void	init_ry(t_ry *ry);
int		ryc(t_lch *lch);
void	print_screen(t_lch *lch);

//Print_Text
t_img	*select_text(t_lch *lch, int side);
int		get_text_color(int x, int y, void *ptr);
int		text_side(t_ry *ry, int side);
void	print_ray(t_lch *lch, int draw[2], int x, int side);

//key prees and release
int	key_p(int key, t_lch *lch);
int	key_rl(int key, t_lch *lch);
int	keyhook(t_lch *lch);
void	rot_camera(t_ry *ry, double rot_speed);


//keyhook pruebas
int	keyhook3(t_lch *lch);
int	keyhook2(int keycode, t_lch *lch);

#endif
