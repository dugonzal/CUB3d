/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:48 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/06/26 21:55:52 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// ahora mismo leemos el archivo y lo guardamos en un buffer
int parser(t_game *game, char **av)
{
  int		fd;

  if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return  (err_ret("Error: Invalid file: extencion .cub;"));
  fd = ft_open(av[1], 0);
  if (fd < 0)
	return (err_ret("Error: Invalid file: No such file or directory"));
  read_fd(game, fd, av[1]);
  return  (0);
}
