/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:50:47 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/03 13:52:01 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Iterates the list lst and applies
///the function f to the content of each element
/// @brief Itera la lista lst y aplica la funcion f
/// al contenido de cada elemento
/// @param lst list to iterate / lista a iterar
/// @param f function to apply to the content of each element
/// funcion a aplicar al contenido de cada elemento
/// @return void
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
