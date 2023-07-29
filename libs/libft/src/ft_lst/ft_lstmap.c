/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:52:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/12 00:57:42 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Iterates the list lst and applies the function f
///to the content of each element.
/// @brief Itera la lista lst y aplica la funcion f al contenido
/// de cada elemento.
/// @param lst list to iterate / lista a iterar
/// @param f function to apply to the content of each element
/// funcion a aplicar al contenido de cada elemento
/// @return void
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	aux = new;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		aux->next = temp;
		aux = temp;
		lst = lst->next;
	}
	return (new);
}
