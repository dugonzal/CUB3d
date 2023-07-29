/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:13:10 by ciclo             #+#    #+#             */
/*   Updated: 2022/11/07 17:24:00 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Outputs the integer ’n’ to the given file descriptor.
/// @brief Escribe el entero ’n’ en el descriptor de archivo dado.
/// @param n The integer to output.
/// @param fd The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		n2 = (n2 * -1);
		write(fd, "-", 1);
	}
	if (n2 > 9)
		ft_putnbr_fd(n2 / 10, fd);
	ft_putchar_fd(n2 + '0', fd);
}
