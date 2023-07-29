/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:50:56 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/03 13:55:16 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Allocates (with malloc(3)) and returns a string representing the
/// integer received as an argument. Negative numbers must be handled.
/// @param n The integer to be converted to a string.
/// @return The string representing the integer. NULL if the allocation fails.
int	len_nbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		sign;

	if (nbr < 0)
		sign = -1;
	else
		sign = 1;
	len = len_nbr(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (!nbr)
		return (ft_strdup("0"));
	str[len] = 0;
	while (len--)
	{
		str[len] = ((nbr % 10) * sign) + 48;
		nbr /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
