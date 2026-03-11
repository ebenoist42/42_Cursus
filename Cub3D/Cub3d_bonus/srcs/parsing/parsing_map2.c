/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:45:52 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/04 14:49:23 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_char(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_good_char(map[i][j]))
				return (0);
			if (check_char_valide(map[i][j]) && (ft_isspace(map[i][j + 1])
					|| map[i][j + 1] == '\0'))
				return (0);
			if (check_char_valide(map[i][j]) && (ft_isspace(map[i][j - 1])
					|| map[i][j - 1] == '\0'))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	find_first_wall(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] && ft_isspace(map[i][j]))
				j++;
			if (!map[i][j])
				break ;
			if (check_good_char(map[i][j]))
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	check_wall_up_down(char **map, int i, int j)
{
	if (!map || i < 0 || !map[i])
		return (0);
	while (map[i][j] && map[i][j] != '\n')
	{
		while (map[i][j] && ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1' && map[i][j] != '\0')
			return (ft_putstr_fd("Error\nWall Up or Down Invalid\n", 2), 0);
		if (!map[i][j] || map[i][j] == '\n')
			break ;
		j++;
	}
	return (1);
}

static int	ft_check_one_player(char **map, int i, int j)
{
	int	player;

	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_player(map[i][j]))
				player++;
			j++;
		}
		i++;
	}
	if (player == 1)
		return (1);
	else
		return (0);
}

int	check_map(char **map, int i, int j, int x)
{
	j = i;
	x = check_char(map, i, 0);
	if (x < 0)
		return (0);
	i = find_first_wall(map, j, 0);
	if (i < 0)
		return (0);
	if (!ft_check_one_player(map, i, 0))
		return (ft_putstr_fd("Error\nNumber of player not good\n", 2), 0);
	if (!ft_control_zero(map, i, 0))
		return (0);
	if (!check_wall_up_down(map, i, 0))
		return (0);
	if (!check_wall_up_down(map, x - 1, 0))
		return (0);
	return (1);
}
