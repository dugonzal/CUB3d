/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:17:16 by ciclo             #+#    #+#             */
/*   Updated: 2023/07/26 11:20:22 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief  Allocates sufficient memory for a copy of the string s1, does the
/// copy, and returns a pointer to it.  The pointer may subsequently be used as
/// an argument to the function free(3).
/// @brief espacio suficiente para una copia de la cadena s1, hace la copia y
/// devuelve un puntero a ella. El puntero puede usarse posteriormente como
/// argumento de la función free(3).
/// @param s1 The string to be duplicated.
/// @return A pointer to the duplicated string.  It returns NULL if insufficient
/// memory was available.
char	*ft_strdup(const char *str)
{
	char		*tmp;
	size_t		len;

	len = ft_strlen(str) + 1;
	tmp = (char *)ft_calloc(sizeof(char), len);
	ft_strlcpy(tmp, (char *)str, len);
	tmp[len] = '\0';
	return (tmp);
}
