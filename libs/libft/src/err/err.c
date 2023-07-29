/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:10:26 by ciclo             #+#    #+#             */
/*   Updated: 2023/07/26 11:31:58 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief  mensaje  de  error mas  mensaje pesonalizadi
/// y salida con 1
/// @param str parametro de  mensaje presonalizado
void	err(char *str)
{
	ft_printf (RED"Error: %s\n"RESET, str);
	exit (1);
}

int	err_ret(char *str)
{
	ft_printf (RED"Error: %s\n"RESET, str);
	exit (1);
}
