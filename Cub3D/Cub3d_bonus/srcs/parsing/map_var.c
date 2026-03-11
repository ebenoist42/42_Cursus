/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:48:21 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/04 10:14:12 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*extract_texture_path(char *map, int j, int offset)
{
	int	start;
	int	end;

	j += offset;
	j = skip_space(map, j);
	if (!map[j] || map[j] == '\n')
		return (NULL);
	start = j;
	end = start;
	while (map[end] && map[end] != ' ' && map[end] != '\t' && map[end] != '\n')
		end++;
	return (ft_substr(map, start, end - start));
}

char	*extract_color_line(char *map, int j, int offset)
{
	int	start;
	int	end;

	j += offset;
	j = skip_space(map, j);
	if (!map[j] || map[j] == '\n')
		return (NULL);
	start = j;
	end = start;
	while (map[end] && map[end] != '\n')
		end++;
	return (ft_substr(map, start, end - start));
}

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	count_map_lines(char **full_file, int start)
{
	int	count;

	count = 0;
	while (full_file[start + count])
		count++;
	return (count);
}

char	**extract_map(char **full_file, int start)
{
	char	**map;
	int		nb_lines;
	int		i;

	while (full_file[start] && is_empty_line(full_file[start]))
		start++;
	nb_lines = count_map_lines(full_file, start);
	if (nb_lines == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < nb_lines)
	{
		map[i] = ft_strdup(full_file[start + i]);
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}
