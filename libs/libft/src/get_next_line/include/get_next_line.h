/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:59:17 by dugonzal          #+#    #+#             */
/*   Updated: 2023/07/20 12:36:47 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 400
# endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../../include/libft.h"

char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
