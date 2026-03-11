/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:30:04 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:42:48 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_ligne(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	count = 0;
	if (fd == -1)
	{
		write(2, "Error\nUnread File", 18);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**read_file_map(char *file, int fd)
{
	char	**map;
	int		count;
	char	*line;
	int		i;

	i = 0;
	count = count_ligne(file);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		ft_error_malloc(map);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[count] = NULL;
	return (map);
}

char	**read_file(char *file)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_file();
	map = read_file_map(file, fd);
	if (!map)
	{
		write(2, "Error\nReading Failed", 21);
		exit(1);
	}
	close(fd);
	return (map);
}
