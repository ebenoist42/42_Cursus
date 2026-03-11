/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:53:31 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/13 17:02:22 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(game->mm.draw_x + j, game->mm.draw_y + i, color, game);
			j++;
		}
		i++;
	}
}

void	draw_square2(int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(game->mm.player_pixel_x + j, game->mm.player_pixel_y + i,
				color, game);
			j++;
		}
		i++;
	}
}
