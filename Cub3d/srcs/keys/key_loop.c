/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:57:50 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/12 11:01:06 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}
/*
void	draw_map_2d(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;
	int	map_x;
	int	map_y;

	tile_size = 32;
	i = 0;
	while (game->var.map[i])
	{
		j = 0;
		while (game->var.map[i][j])
		{
			if (game->var.map[i][j] == '1')
				draw_square(j * tile_size, i * tile_size, tile_size, 0xFFFFFF,
					game);
			else if (game->var.map[i][j] == '0' || game->var.map[i][j] == 'N'
				|| game->var.map[i][j] == 'S' || game->var.map[i][j] == 'E'
				|| game->var.map[i][j] == 'W')
				draw_square(j * tile_size, i * tile_size, tile_size, 0x333333,
					game);
			j++;
		}
		i++;
	}
}
bool	touch(double px, double py, t_game *game)
{
	map_x = (int)px;
	map_y = (int)py;
	if (map_y < 0 || map_x < 0)
		return (true);
	if (!game->var.map[map_y] || !game->var.map[map_y][map_x])
		return (true);
	if (game->var.map[map_y][map_x] == '1')
		return (true);
	return (false);
}*/

int	game_loop(t_game *game)
{
	if (game->keys.esc)
	{
		free_end_of_programme(game);
		exit(0);
	}
	handle_movement(game);
	handle_rotation(game);
	clear_image(game);
	recast(game);
	return (0);
}
