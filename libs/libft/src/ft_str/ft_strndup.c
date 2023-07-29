/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:06:57 by Dugonzal          #+#    #+#             */
/*   Updated: 2023/07/17 17:04:52 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*tmp;

	if (!n)
		return ((char *)str);
	else if (str == NULL)
		return (NULL);
	tmp = ft_calloc((n + 1), sizeof(char));
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, (char *)str, n + 1);
	return (tmp);
}
