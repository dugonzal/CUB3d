/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:52:16 by ciclo             #+#    #+#             */
/*   Updated: 2023/07/20 12:34:50 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_formats(va_list arg, char c)
{
	size_t	x;

	x = 0;
	if (c == '%')
		x += ft_putchar('%');
	else if (c == 'c')
		x += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		x += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		x += ft_putnbr(va_arg(arg, int));
	else if (c == 'x')
		x += ft_printf_hex(va_arg(arg, unsigned int));
	else if (c == 'X')
		x += ft_printf_hex_maj(va_arg(arg, unsigned int));
	else if (c == 'p')
		x += ft_putstr("0x") + ft_printf_p(va_arg(arg, size_t));
	else if (c == 'u')
		x += ft_print_u(va_arg(arg, unsigned int));
	return (x);
}

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)"));
	if (!str[0])
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen3(str)));
}

size_t	ft_print_u(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 9)
	{
		i += ft_print_u(n / 10);
		i += ft_print_u(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}
