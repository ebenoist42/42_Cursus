/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:17:37 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/03 14:04:55 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_ligne(char *av)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFile", 11);
		exit(1);
	}
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**read_file(char *av, int fd)
{
	char	**maps;
	int		count;
	int		i;

	i = 0;
	count = count_ligne(av);
	maps = malloc(sizeof(char *) * (count + 2));
	if (!maps)
		ft_error_malloc(maps);
	maps[i] = get_next_line(fd);
	while (maps[i])
	{
		i++;
		maps[i] = get_next_line(fd);
	}
	maps[++i] = "\0";
	return (maps);
}

char	**malloc_maps(char *av)
{
	char	**maps;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error_file();
	maps = read_file(av, fd);
	if (!maps)
	{
		write(2, "Error\nReading Maps\n", 20);
		exit(1);
	}
	close(fd);
	return (maps);
}
