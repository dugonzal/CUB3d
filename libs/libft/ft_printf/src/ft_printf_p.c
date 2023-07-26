/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:01:22 by dugonzal          #+#    #+#             */
/*   Updated: 2022/10/14 14:04:38 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/// @brief
/// @param n
/// @return
size_t	ft_printf_p(unsigned long long n)
{
	size_t	i;

	i = 0;
	if (n > 15)
		i += ft_printf_p(n / 16);
	i += ft_putchar(HEXA[n % 16]);
	return (i);
}
