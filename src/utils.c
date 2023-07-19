/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:28:50 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/17 11:50:29 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void print(char **str)
{
  int i;

  i = -1;
  while (str[++i])
	ft_printf("%s", str[i]);
}
void *free_array(char **str)
{
  int i;

  i = 0;
  while (str[i])
  {
	if (str[i])
	  free(str[i]);
	i++;
  }
  free(str);
  return (NULL);
}

int	get_int_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
