/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:42:43 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/12 02:14:33 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Locates the last occurrence of c (converted to a char) in the string
/// pointed to by s. The terminating null character is considered to be part of
/// the string; therefore if c is `\0', the functions locate the terminating
///`\0'
/// @param s The string to be searched.
/// @param c The character to be searched.
/// @return A pointer to the located character, or NULL if the character
///does not appear in the string.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i--)
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (0);
}
