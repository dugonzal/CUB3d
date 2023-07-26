/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:19:19 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/02 21:13:47 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Applies the function f to each character of the string passed as
/// argument, and passing its index as first argument. Each character is passed
/// by address to f to be modified if necessary.
/// @brief Aplica la función f a cada carácter de la cadena pasada como
/// argumento, y pasa su índice como primer argumento. Cada carácter se pasa por
/// dirección a f para ser modificado si es necesario.
/// @param s The string on which to iterate.
/// @param f The function to apply to each character of s and its index.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	if (s != 0 && f != 0)
		while (s[++i] != 0)
			f(i, s + i);
}
