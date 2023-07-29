/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:03:34 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/12 16:18:30 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Copies n bytes from memory area src to memory area dest.
/// @brief Copia n bytes de la zona de memoria src a la zona de memoria dest.
/// @param dest The destination memory area.
/// @param src The source memory area.
/// @param n The number of bytes to be copied.
/// @return The pointer to dest.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
