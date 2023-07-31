/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:09:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/12 01:10:30 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Outputs the character c to the given file descriptor.
/// @brief / Escribe el caracter c en el descriptor de archivo dado.
/// @param c The character to output.
/// @param fd The file descriptor on which to write.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
