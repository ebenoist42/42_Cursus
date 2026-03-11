/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:27:48 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/11 14:10:02 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/cub3d.h"

void	msg_and_eof(t_game *game, char *str)
{
	ft_putstr_fd(str, 2);
	free_end_of_programme(game);
	exit(1);
}

void	msg_and_quit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error_file(void)
{
	ft_putstr_fd("Error\nWrong File\n", 2);
	exit(1);
}

void	ft_error_malloc(char **map)
{
	if (map)
		free_map(map);
	ft_putstr_fd("Error\nMemory Allocation Error\n", 2);
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
