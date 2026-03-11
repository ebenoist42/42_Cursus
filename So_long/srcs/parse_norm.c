/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:52:08 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:43:15 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_squar(char **map)
{
	int	l;
	int	i;

	i = 0;
	l = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][l - 1] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_wall(char **map)
{
	int	l;
	int	c;
	int	i;

	l = 0;
	c = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[l])
		l++;
	while (i < c)
	{
		if (map[0][i] != '1' || map[l - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < l)
	{
		if (map[i][0] != '1' || map[i][c - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_norm(t_game *game)
{
	parse_map_char(game);
	if (ft_check_squar(game->map) == 0)
		ft_invalid_map(game->map);
	if (ft_check_wall(game->map) == 0)
		ft_invalid_map(game->map);
	if (ft_path(game->map) == 0)
		ft_invalid_map(game->map);
}
