/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:24:24 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/25 09:44:45 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	print_bits(unsigned char octet)
{
	int		i;
	int		mask;
	char	byte;

	mask = 1;
	i = 7;
	while (i >= 0)
	{
		byte = (((octet >> i) & mask) + 48);
		write (1, &byte, 1);
		i--;
	}
}
