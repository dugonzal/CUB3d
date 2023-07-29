/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:40:24 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/12 01:42:23 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Locates the first occurrence of the null-terminated string needle in
/// the string haystack, where not more than len characters are searched
///Characters that appear after a `\0' character are not searched.
/// @param haystack The string to be searched.
/// @param needle The string to be searched for.
/// @param len The number of characters to be searched.
/// @return A pointer to the beginning of the located substring, or NULL if the
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (!needle[j + 1])
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (0);
}
