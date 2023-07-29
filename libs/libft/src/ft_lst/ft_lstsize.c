/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:58:21 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/02 21:03:06 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Counts the number of elements in a list.
/// @param lst The beginning of the list.
/// @return The number of elements in a list.
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = -1;
	while (++lst)
		lst = lst->next;
	return (size);
}
