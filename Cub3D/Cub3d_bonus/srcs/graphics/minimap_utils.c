/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:51:04 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/13 17:01:37 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_line_length(char *line)
{
	int	len;

	len = 0;
	if (!line)
		return (0);
	while (line[len])
		len++;
	return (len);
}

int	is_valid_tile(t_game *game)
{
	if (game->mm.i >= 0 && game->mm.i < game->mm.map_height && game->mm.j >= 0
		&& game->mm.j < get_line_length(game->var.map[game->mm.i]))
		return (1);
	return (0);
}

int	is_walkable_tile(char tile)
{
	if (tile == '0' || tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W')
		return (1);
	return (0);
}

void	draw_minimap_background(t_game *game, int mm_x, int mm_y, int mm_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < mm_size)
	{
		j = 0;
		while (j < mm_size)
		{
			put_pixel(mm_x + j, mm_y + i, 0x000000, game);
			j++;
		}
		i++;
	}
}
