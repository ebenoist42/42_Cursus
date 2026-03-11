/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:38:38 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/13 16:41:23 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	perform_dda(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 1;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 0;
		}
		if (game->ray.map_y < 0 || game->ray.map_x < 0)
			game->ray.hit = 1;
		else if (!game->var.map[game->ray.map_y]
			|| !game->var.map[game->ray.map_y][game->ray.map_x])
			game->ray.hit = 1;
		else if (game->var.map[game->ray.map_y][game->ray.map_x] == '1' ||
				game->var.map[game->ray.map_y][game->ray.map_x] == 'D' ||
				game->var.map[game->ray.map_y][game->ray.map_x] == 'T')
			game->ray.hit = 1;
	}
}

static void	calc_wall_distance(t_game *game, double ray_dir_x, double ray_dir_y)
{
	double	wall_x_pos;

	if (game->ray.side == 0)
		game->ray.distance = (game->ray.map_y - game->player.pos_y + (1
					- game->ray.step_y) / 2) / ray_dir_y;
	else
		game->ray.distance = (game->ray.map_x - game->player.pos_x + (1
					- game->ray.step_x) / 2) / ray_dir_x;
	if (game->ray.side == 0)
		wall_x_pos = game->player.pos_x + game->ray.distance * ray_dir_x;
	else
		wall_x_pos = game->player.pos_y + game->ray.distance * ray_dir_y;
	game->ray.wall_x = wall_x_pos - floor(wall_x_pos);
}

void	cast_ray(t_game *game, double ray_dir_x, double ray_dir_y)
{
	init_ray_params(game, ray_dir_x, ray_dir_y);
	calc_step_x(game, ray_dir_x);
	calc_step_y(game, ray_dir_y);
	perform_dda(game);
	calc_wall_distance(game, ray_dir_x, ray_dir_y);
}
