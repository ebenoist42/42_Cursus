/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:59:22 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:42:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_exit(char **map)
{
	int	l;
	int	i;
	int	count;

	i = 0;
	count = 0;
	l = 0;
	while (map[l])
	{
		i = 0;
		while (map[l][i])
		{
			if (map[l][i] == 'E')
				count++;
			i++;
		}
		l++;
	}
	if (count != 1)
	{
		write(2, "Error\nProblem Exit\n", 20);
		free_map(map);
		exit(1);
	}
}

static int	ft_check_item(char **map)
{
	int	l;
	int	i;
	int	count;

	l = 0;
	count = 0;
	i = 0;
	while (map[l])
	{
		i = 0;
		while (map[l][i])
		{
			if (map[l][i] == 'C')
				count++;
			i++;
		}
		l++;
	}
	if (count == 0)
	{
		write(2, "Error\nNo Item\n", 15);
		free_map(map);
		exit(1);
	}
	return (count);
}

static void	ft_check_depart(char **map)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	l = 0;
	count = 0;
	while (map[l])
	{
		i = 0;
		while (map[l][i])
		{
			if (map[l][i] == 'P')
				count++;
			i++;
		}
		l++;
	}
	if (count != 1)
	{
		write(2, "Error\nProblem Depart\n", 22);
		free_map(map);
		exit(1);
	}
}

static void	ft_check_char(char **map)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (map[l])
	{
		i = 0;
		while (map[l][i])
		{
			if (map[l][i] != 'C' && map[l][i] != 'P' && map[l][i] != '0'
				&& map[l][i] != '1' && map[l][i] != 'E' && map[l][i] != '\n'
				&& map[l][i] != 'M')
				ft_invalid_map(map);
			i++;
		}
		l++;
	}
}

void	parse_map_char(t_game *game)
{
	ft_check_exit(game->map);
	game->collect_count = ft_check_item(game->map);
	ft_check_depart(game->map);
	ft_check_char(game->map);
}
