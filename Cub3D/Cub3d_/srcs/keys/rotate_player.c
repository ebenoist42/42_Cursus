/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:27:48 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/11 15:26:20 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_rotation(t_game *game)
{
	double	old_dirx;
	double	rotation_speed;

	rotation_speed = 0.0100;
	if (game->keys.left)
	{
		old_dirx = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-rotation_speed)
			- game->player.dir_y * sin(-rotation_speed);
		game->player.dir_y = old_dirx * sin(-rotation_speed)
			+ game->player.dir_y * cos(-rotation_speed);
	}
	if (game->keys.right)
	{
		old_dirx = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rotation_speed)
			- game->player.dir_y * sin(rotation_speed);
		game->player.dir_y = old_dirx * sin(rotation_speed) + game->player.dir_y
			* cos(rotation_speed);
	}
}
