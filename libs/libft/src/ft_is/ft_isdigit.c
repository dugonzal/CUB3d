/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:42:25 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/25 22:47:35 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/// @brief Check if the character is a digit
/// @brief Comprueba si el caracter es un digito
/// @param c character to check / caracter a comprobar
/// @return return 1 if the character is a digit, 0 otherwise
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
