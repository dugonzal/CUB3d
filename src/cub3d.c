/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:12:28 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/16 12:24:43 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
  void *mlx;

  mlx = mlx_init();

  mlx_new_window(mlx, 500, 500, "Cub3D");
  mlx_loop(mlx);
}
