/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:49:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/13 17:01:00 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mm_data(t_game *game)
{
	game->mm.tile_size = 10;
	game->mm.mm_size = 200;
	game->mm.mm_x = WIDTH - game->mm.mm_size;
	game->mm.mm_y = HEIGHT - game->mm.mm_size - 68;
	game->mm.tiles_to_show = (game->mm.mm_size + game->mm.tile_size - 1)
		/ game->mm.tile_size;
	game->mm.map_height = get_map_height(game->var.map);
	draw_minimap_background(game, game->mm.mm_x, game->mm.mm_y,
		game->mm.mm_size);
	game->mm.i_min = (int)game->player.pos_y - game->mm.tiles_to_show / 2;
	game->mm.i_max = (int)game->player.pos_y + game->mm.tiles_to_show / 2;
	game->mm.j_min = (int)game->player.pos_x - game->mm.tiles_to_show / 2;
	game->mm.j_max = (int)game->player.pos_x + game->mm.tiles_to_show / 2;
	game->mm.i = game->mm.i_min;
}

void	draw_minimap_tile(t_game *game)
{
	char	tile;

	if (!is_valid_tile(game))
		return ;
	tile = game->var.map[game->mm.i][game->mm.j];
	if (tile == '1')
		draw_square(game->mm.tile_size, 0x333333, game);
	else if (is_walkable_tile(tile))
		draw_square(game->mm.tile_size, 0xFFFFFF, game);
}

void	draw_minimap_tiles(t_game *game)
{
	while (game->mm.i < game->mm.i_max)
	{
		game->mm.j = game->mm.j_min;
		while (game->mm.j < game->mm.j_max)
		{
			game->mm.draw_x = game->mm.mm_x + (game->mm.j - game->mm.j_min)
				* game->mm.tile_size;
			game->mm.draw_y = game->mm.mm_y + (game->mm.i - game->mm.i_min)
				* game->mm.tile_size;
			draw_minimap_tile(game);
			game->mm.j++;
		}
		game->mm.i++;
	}
}

void	draw_minimap_player(t_game *game)
{
	game->mm.player_pixel_x = game->mm.mm_x + (game->player.pos_x
			- game->mm.j_min) * game->mm.tile_size - 2;
	game->mm.player_pixel_y = game->mm.mm_y + (game->player.pos_y
			- game->mm.i_min) * game->mm.tile_size - 2;
	draw_square2(4, 0xFF0000, game);
}

void	draw_map_2d(t_game *game)
{
	init_mm_data(game);
	draw_minimap_tiles(game);
	draw_minimap_player(game);
}
