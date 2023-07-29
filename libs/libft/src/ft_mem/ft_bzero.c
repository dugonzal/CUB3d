/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:58:42 by ciclo             #+#    #+#             */
/*   Updated: 2022/10/24 12:56:12 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Writes n zeroed bytes to the string s.
/// @param s The string to be zeroed.
/// @param n The number of bytes to be zeroed.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
