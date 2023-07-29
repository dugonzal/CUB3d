/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:00:56 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/25 07:49:43 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/// @brief Check if the character is alphanumeric
/// @brief Comprueba si el caracter es alfanumerico
/// @param c character to check / caracter a comprobar
/// @return return 1 if the character is alphanumeric, 0 otherwise
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
