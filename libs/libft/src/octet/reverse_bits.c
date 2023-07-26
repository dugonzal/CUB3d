/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:28:44 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/25 09:34:56 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	byte;
	int				i;

	i = 7;
	while (i >= 0)
	{
		byte = (byte * 2) + (octet % 2);
		octet /= 2;
		i--;
	}
	return (byte);
}
