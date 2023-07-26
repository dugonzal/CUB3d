/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:13:08 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/25 09:35:16 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief haya el numero minimo de un arry
/// @param tab arrray en el que buscamos el numero minimo
/// @param len longitud de busqueda
/// @return numero minirmo encontrado en el array
int	min(int *tab, int len)
{
	int	tmp;

	if (len <= 0 || !tab)
		return (0);
	tmp = tab[--len];
	while (len--)
		if (tab[len] < tmp)
			tmp = tab[len];
	return (tmp);
}
