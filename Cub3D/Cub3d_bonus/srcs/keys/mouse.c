/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:15:29 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/13 16:43:12 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rotate_player_horizontal(t_game *game, int delta_x)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	if (delta_x == 0)
		return (0);
	rot_speed = 0.0005;
	angle = delta_x * rot_speed;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y
		* sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y
		* cos(angle);
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y
		* cos(angle);
	return (1);
}

static int	rotate_player_vertical(t_game *game, int delta_y)
{
	if (delta_y == 0)
		return (0);
	game->player.pitch -= delta_y;
	if (game->player.pitch > 400)
		game->player.pitch = 400;
	else if (game->player.pitch < -400)
		game->player.pitch = -400;
	return (1);
}

int	handle_mouse(t_game *game, int delta_x, int delta_y)
{
	int	rotated;

	rotated = 0;
	rotated |= rotate_player_horizontal(game, delta_x);
	rotated |= rotate_player_vertical(game, delta_y);
	return (rotated);
}

void	mouse_mlx(t_game *game, int x, int y)
{
	mlx_mouse_move(game->mlx.mlx_ptr, game->mlx.w_ptr, x, y);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	previous_x = WIDTH / 2;
	static int	previous_y = HEIGHT / 2;
	int			delta_x;
	int			delta_y;

	if (!game || !game->mlx.mlx_ptr || !game->mlx.w_ptr)
		return (1);
	delta_x = x - previous_x;
	previous_x = x;
	delta_y = y - previous_y;
	previous_y = y;
	handle_mouse(game, delta_x, delta_y);
	mouse_mlx(game, WIDTH / 2, y);
	previous_x = WIDTH / 2;
	return (0);
}
