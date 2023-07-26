/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:45:53 by ciclo             #+#    #+#             */
/*   Updated: 2023/07/17 17:20:45 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Allocates (with malloc(3)) and returns a substring from the
///string ’s’ The substring begins at index ’start’ and is of maximum size len
/// @brief aloja (con malloc (3)) y devuelve una subcadena de la cadena 's'.
/// La subcadena comienza en el índice 'start' y tiene un tamaño máximo de len
/// @param s The string from which to create the substring.
/// @param start The start index of the substring in the string ’s’.
/// @param len The maximum length of the substring.
/// @return The substring. NULL if the allocation fails.
char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*tmp;

	if (src == NULL)
		return (NULL);
	slen = ft_strlen(src);
	if (start > slen)
		return (NULL);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < len)
		tmp[i] = src[start + i];
	tmp[i] = 0;
	return (tmp);
}
