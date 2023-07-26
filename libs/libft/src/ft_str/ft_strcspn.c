/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:04:07 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/02 21:16:02 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	idx;

	idx = -1;
	while (s[++idx] != 0)
		if (ft_strchr(reject, s[idx]))
			break ;
	return (idx);
}
