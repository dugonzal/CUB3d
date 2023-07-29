/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:50:15 by ciclo             #+#    #+#             */
/*   Updated: 2022/09/12 00:56:40 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Free the memory of the element given as a parameter
/// using the function del given as a parameter and free the element
/// @brief Libera la memoria del elemento dado como parametro
///usando la funcion del dada como parametro y libera el elemento
/// @param lst element to free / elemento a liberar
/// @param del function used to delete the content
/// funcion usada para borrar el contenido
/// @return void
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
