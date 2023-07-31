/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:02:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/01 17:02:03 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/// @brief Check if the character is alphabetic
/// @brief Comprueba si el caracter es alfabetico
/// @param c character to check / caracter a comprobar
/// @return return 1 if the character is alphabetic, 0 otherwise
/// @return devuelve 1 si el caracter es alfabetico, 0 en caso contrario
int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}
