/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:32:22 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/12 02:13:56 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Applies the function f to each character of the string s to create
/// a new string (with malloc(3)) resulting from successive applications of f.
///@param s The string on which to iterate.
///@param f The function to apply to each character.
///@return The string created from the successive applications of f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i++ < len)
		str[i] = f(i, s[i]);
	str[i] = 0;
	return (str);
}
