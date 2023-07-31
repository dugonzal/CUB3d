/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:00:48 by ciclo             #+#    #+#             */
/*   Updated: 2022/10/24 12:56:39 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Locates the first occurrence of c (converted to an unsigned char)
/// in string s.
/// @brief Busca la primera ocurrencia de c (convertido a un unsigned char)
/// @param s The string to be searched.
/// @param c The character to be searched.
/// @param n The number of bytes to be searched.
/// @return A pointer to the byte located, or NULL if no such byte exists
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		if (((unsigned char *)s)[i++] == (unsigned char)c)
			return ((void *)(s + i));
	return (0);
}
