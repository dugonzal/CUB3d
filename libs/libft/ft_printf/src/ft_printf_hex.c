/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:42:21 by ciclo             #+#    #+#             */
/*   Updated: 2022/10/14 08:56:10 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_len_hex(unsigned int n)
{
	size_t	length;

	length = 1;
	while (n > 15)
	{
		n /= 16;
		length++;
	}
	return (length);
}

size_t	ft_printf_hex(unsigned int n)
{
	size_t	length;

	length = 0;
	length += ft_len_hex(n);
	if (n > 15)
		ft_printf_hex(n / 16);
	ft_putchar(HEXA[n % 16]);
	return (length);
}

size_t	ft_printf_hex_maj(unsigned int n)
{
	size_t	length;

	length = 0;
	length += ft_len_hex(n);
	if (n > 15)
		ft_printf_hex_maj(n / 16);
	ft_putchar(HEXA_M[n % 16]);
	return (length);
}
