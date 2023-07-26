/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:45:03 by ciclo             #+#    #+#             */
/*   Updated: 2022/11/17 14:21:19 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Add the element new at the end of the list
/// @brief Añade el elemento new al final de la lista
/// @param lst list to which the element is added
///lista a la que se añade el elemento
/// @param new element to add / elemento a añadir
/// @return void
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}
