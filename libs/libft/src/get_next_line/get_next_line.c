/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masla-la <masla-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:55:36 by masla-la          #+#    #+#             */
/*   Updated: 2023/07/26 10:57:48 by masla-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*cpy(char *g)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (g[i] && g[i] != '\n')
		i++;
	if (!g[i])
	{
		free (g);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(g) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (g[i])
		s[c++] = g[i++];
	s[c] = '\0';
	free(g);
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_line(char *g)
{
	char	*str;
	int		i;

	i = 0;
	if (!g[i])
		return (NULL);
	while (g[i] && g[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (g[i] && g[i] != '\n')
	{
		str[i] = g[i];
		i++;
	}
	if (g[i] == '\n')
	{
		str[i] = g[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_line(int fd, char *g)
{
	char	*buff;
	int		i;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while ((!g || !search(g, '\n')) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		g = ft_strjoin2(g, buff);
	}
	free(buff);
	return (g);
}

char	*get_next_line(int fd)
{
	static char	*g;
	char		*line;

	if (fd < 0)
		return (NULL);
	g = read_line(fd, g);
	if (!g)
		return (NULL);
	line = ft_line(g);
	if (!line)
		return (NULL);
	g = cpy(g);
	return (line);
}
