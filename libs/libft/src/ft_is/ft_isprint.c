/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:42:49 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/25 22:49:05 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if the character is printable
/// @brief Comprueba si el caracter es imprimible
/// @param c character to check / caracter a comprobar
/// @return return 1 if the character is printable, 0 otherwise
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
