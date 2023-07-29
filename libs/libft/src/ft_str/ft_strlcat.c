/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:23:42 by ciclo             #+#    #+#             */
/*   Updated: 2023/05/02 21:10:24 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/// @brief Appends string src to the end of dst. It will append at most
/// dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
/// dstsize is 0 or the original dst string was longer than dstsize (in practice
/// this should not happen as it means that either dstsize is incorrect or that
/// dst is not a proper string).
/// @brief Appendea la cadena src al final de dst. Apendeará como
/// máximo dstsize - strlen(dst) - 1 caracteres. Luego terminará con NUL, a no
/// ser que dstsize sea 0 o que la cadena original de dst sea más larga que
/// dstsize (en la práctica esto no debería pasar ya que significa que o dstsize
/// es incorrecto o que dst no es una cadena correcta).
/// @param dst The destination string.
/// @param src The source string.
/// @param dstsize The size of the destination string.
/// @return The total length of the string it tried to create.
/// repasar funcion
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != 0 && c + 1 < dstsize)
		dst[c++] = src[d++];
	dst[c] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}
