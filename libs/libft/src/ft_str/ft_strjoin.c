/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:23:06 by ciclo             #+#    #+#             */
/*   Updated: 2023/07/20 12:41:37 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Allocates (with malloc(3)) and returns a new string, which is the
/// result of the concatenation of ’s1’ and ’s2’.
/// @param s1 The prefix string.
/// @param s2 The suffix string.
/// @return The new string. NULL if the allocation fails.
char	*ft_strjoin(const char *s1, char const *s2, int f)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	if (!s2)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	if (s1)
		while (s1 && s1[++i] != 0)
			tmp[i] = s1[i];
	j = 0;
	while (s2 && s2[j] != 0)
		tmp[i++] = s2[j++];
	tmp[i] = 0;
	if (f)
		free((char *)s1);
	return (tmp);
}
