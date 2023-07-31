/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:39:36 by ciclo             #+#    #+#             */
/*   Updated: 2022/11/13 15:51:08 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

# define HEXA "0123456789abcdef"
# define HEXA_M "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
size_t	ft_formats(va_list arg, char c);
size_t	ft_putnbr(int n);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
size_t	ft_printf_hex(unsigned int n);
size_t	ft_printf_hex_maj(unsigned int n);
size_t	ft_printf_p(unsigned long long n);
size_t	ft_print_u(unsigned int n);

#endif
