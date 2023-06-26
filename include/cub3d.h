/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:37:30 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/26 21:49:43 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx_macos/mlx.h"
# include <math.h>

//Nosé si es necesario
# define NO	0
# define SO	1
# define WE	2
# define EA	3
# define F	4
# define C	5
typedef struct s_map
{
	char	**buffer;
	char	**map;
	char	**DIRC;//6//iniciar el ** en 6
}			t_map;

typedef struct s_img
{
	char	*img;
	void	*img_w;
}			t_img;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	struct s_img	*img;
	struct s_map	*map;
}			t_game;


int		len_fd(int fd);
void	read_fd(t_game *game, int fd, char *av);
void	print(char **str);
int		parser(t_game *game, char **av);
#endif
