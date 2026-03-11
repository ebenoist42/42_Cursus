/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:05:10 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/13 16:35:07 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_control_zero(char **map, int i, int j)
{
	if (!map || i <= 0 || !map[i])
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (!map[i - 1] || map[i - 1][j] == ' ' || !map[i - 1][j]
					|| map[i - 1][j] == '\n')
					return (0);
				if (!map[i + 1] || map[i + 1][j] == ' ' || !map[i + 1][j]
					|| map[i + 1][j] == '\n')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_good_char(char j)
{
	if (j == '1' || j == '0' || j == 'N' || j == 'S' || j == 'E' || j == 'W'
		|| j == 'D' || j == 'T')
		return (1);
	else if (ft_isspace(j))
		return (1);
	else
		return (0);
}

int	check_char_valide(char j)
{
	if (j == '0' || j == 'N' || j == 'S' || j == 'E' || j == 'W' || j == 'D'
		|| j == 'T')
		return (1);
	else
		return (0);
}
