/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:04:52 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/25 10:40:43 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Copies n bytes from memory area src to memory area dest.
/// @brief Copia n bytes de la zona de memoria src a la zona de memoria dest.
/// @param dest The destination memory area.
/// @param src The source memory area.
/// @param n The number of bytes to be copied.
/// @return The pointer to dest.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (src < dst)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
