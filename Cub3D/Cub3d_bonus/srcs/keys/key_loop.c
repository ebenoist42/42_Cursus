/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:57:50 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/13 16:56:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	draw_map_2d(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.w_ptr, game->ig, 0, 0);
	return (0);
}
