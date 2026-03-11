/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:09:48 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/12 11:01:32 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_column(t_game *game, int x)
{
	game->ray.line_height = (int)(HEIGHT / (game->ray.distance + 0.0001));
	game->ray.draw_start = (HEIGHT - game->ray.line_height) / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.draw_start + game->ray.line_height;
	if (game->ray.draw_end > HEIGHT)
		game->ray.draw_end = HEIGHT;
	draw_floor_ceiling(game, x);
	draw_textured_column(game, x);
}

void	recast(t_game *game)
{
	double	camera_x;
	double	ray_angle;
	double	ray_dir_x;
	double	ray_dir_y;
	int		x;

	game->mlx.anim_frame++;
	x = 0;
	while (x < WIDTH)
	{
		camera_x = (2 * x / (double)WIDTH) - 1;
		ray_angle = atan2(game->player.dir_y, game->player.dir_x) + camera_x
			* (0.66 / 2.0);
		ray_dir_x = cos(ray_angle);
		ray_dir_y = sin(ray_angle);
		cast_ray(game, ray_dir_x, ray_dir_y);
		render_column(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.w_ptr, game->ig, 0, 0);
}
