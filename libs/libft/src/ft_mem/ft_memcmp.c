/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:02:05 by ciclo             #+#    #+#             */
/*   Updated: 2022/10/24 12:56:31 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Compares byte string s1 against byte string s2.
/// Both strings are assumed to be n bytes long.
/// @brief Compara la cadena de bytes s1 contra la cadena de bytes s2.
/// @param s1 The first string to be compared.
/// @param s2 The second string to be compared.
/// @param n The number of bytes to be compared.
/// @return An integer greater than, equal to, or less than 0, according as the
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
