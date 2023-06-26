#include "../include/cub3d.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen((char *)(src)) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != 00)
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] == str2[i])
		i++;
	if (i == (int)ft_strlen(str2))
		return (1);
	return (0);
}
