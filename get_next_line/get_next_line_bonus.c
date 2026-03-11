/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:37:55 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/21 12:04:06 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_join(int fd, char *stach)
{
	char	*buffer;
	ssize_t	by_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	by_read = 1;
	while (by_read > 0 && !ft_strchr(stach, '\n'))
	{
		by_read = read(fd, buffer, BUFFER_SIZE);
		if (by_read == 0)
			break ;
		if (by_read < 0)
		{
			free (stach);
			stach = NULL;
			break ;
		}
		buffer[by_read] = '\0';
		stach = ft_strjoin(stach, buffer);
		if (!stach)
			return (free(buffer), NULL);
	}
	return (free(buffer), stach);
}

static char	*return_and_clean(char **stach)
{
	char	*line;

	if (*stach && **stach)
	{
		line = ft_line(*stach);
		*stach = ft_save(*stach);
		return (line);
	}
	free(*stach);
	*stach = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stach[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	stach[fd] = read_and_join(fd, stach[fd]);
	if (!stach[fd])
		return (NULL);
	return (return_and_clean(&stach[fd]));
}

char	*ft_save(char *str)
{
	int		i;
	char	*dest;
	int		j;
	int		k;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = ft_strlen(str);
	dest = ft_calloc((j - i) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	k = 0;
	while (i < j)
		dest[k++] = str[i++];
	dest[k] = '\0';
	free (str);
	return (dest);
}

char	*ft_line(char	*str)
{
	int		i;
	char	*s;
	int		j;

	j = 0;
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = ft_calloc ((i) + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (j < i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}
