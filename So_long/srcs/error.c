/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:04:55 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:38:49 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_arg_error(int ac, char *file)
{
	int	len;

	if (ac == 1)
	{
		write(2, "Error\nNo Maps Detected\n", 24);
		exit(1);
	}
	if (ac > 2)
	{
		write(2, "Error\nToo Much Argument Provided\n", 34);
		exit(1);
	}
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + (len - 4), ".ber", 4) != 0)
	{
		write(2, "Error\nWrong Map Format Provided\n", 33);
		exit(1);
	}
}

void	ft_error_file(void)
{
	write(2, "Error\nWrong File", 17);
	exit(1);
}

void	ft_error_malloc(char **map)
{
	if (map)
		free_map(map);
	write(2, "Error\nMemory Allocation Error\n", 31);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_invalid_map(char **map)
{
	write(2, "Error\nWrong Map\n", 17);
	free_map(map);
	exit(1);
}
