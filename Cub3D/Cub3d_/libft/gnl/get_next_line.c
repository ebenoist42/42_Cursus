/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:53 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/07/11 14:38:59 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_line(char *gnl)
{
	int		i;
	char	*str;

	i = 0;
	if (!gnl[i])
		return (NULL);
	while (gnl[i] && gnl[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (gnl[i] && gnl[i] != '\n')
	{
		str[i] = gnl[i];
		i++;
	}
	if (gnl[i] == '\n')
	{
		str[i] = gnl[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *gnl)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (gnl[i] && gnl[i] != '\n')
		i++;
	if (!gnl[i])
	{
		free(gnl);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), (ft_strlen(gnl) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (gnl[i])
		str[j++] = gnl[i++];
	str[j] = '\0';
	free(gnl);
	return (str);
}

char	*ft_read_gnl(int fd, char *gnl)
{
	char	*buff;
	int		size;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_strchr(gnl, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		gnl = ft_strjoingnl(gnl, buff);
	}
	free(buff);
	return (gnl);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*gnl[1024];
	int			i;

	i = 0;
	if (fd < 0)
	{
		while (i < 1024)
		{
			free(gnl[i]);
			gnl[i++] = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl[fd] = ft_read_gnl(fd, gnl[fd]);
	if (!gnl[fd])
	{
		free(gnl[fd]);
		return (NULL);
	}
	res = ft_get_line(gnl[fd]);
	gnl[fd] = ft_new_line(gnl[fd]);
	return (res);
}
/*
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }

    char *line;
    int i = 1;
    while ((line = get_next_line(fd)))
    {
        printf("Ligne %d : %s", i, line);
        free(line);
        i++;
    }

    close(fd);
    return (0);
}*/
