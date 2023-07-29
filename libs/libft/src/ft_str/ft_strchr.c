/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:14:59 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/02 21:16:34 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Locates the first occurrence of c (converted to a char) in the string
/// pointed to by s. The terminating null character is considered to be part of
/// the string; therefore if c is `\0', the functions locate the terminating
///`\0'
/// @param s The string to be searched.
/// @param c The character to be searched.
/// @return A pointer to the located character, or NULL if the character
/// does not
/// appear in the string.
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
		if (*s++ == (char)c)
			return ((char *)(s - 1));
	if ((char)c == 0)
		return ((char *)s);
	return (0);
}
