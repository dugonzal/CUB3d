/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:57:51 by ciclo             #+#    #+#             */
/*   Updated: 2022/11/17 14:20:10 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Allocates (with malloc(3)) and returns a new element.
/// The variable ’content’ is initialized with the value of the
/// parameter ’content’. The variable ’next’ is initialized to NULL.
/// @param content The content to create the new element with.
/// @return The new element.
t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	tmp->next = NULL;
	tmp->content = content;
	return (tmp);
}
