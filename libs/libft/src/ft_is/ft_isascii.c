/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:40:53 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/25 22:46:57 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief  Check if the character is ASCII
/// @brief  Comprueba si el caracter es ASCII
/// @param c character to check / caracter a comprobar
/// @return return 1 if the character is ASCII, 0 otherwise
/// @return devuelve 1 si el caracter es ASCII, 0 en caso contrario
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
