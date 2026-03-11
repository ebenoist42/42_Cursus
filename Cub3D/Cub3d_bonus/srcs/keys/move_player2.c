/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:40:40 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/13 16:41:59 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_obstacle(char cell)
{
	return (cell == '1' || cell == 'D');
}

int	can_move_to(t_game *game, double x, double y)
{
	if (is_obstacle(game->var.map[(int)(y - COLLISION_BUFFER)][(int)(x
		- COLLISION_BUFFER)]))
		return (0);
	if (is_obstacle(game->var.map[(int)(y - COLLISION_BUFFER)][(int)(x
		+ COLLISION_BUFFER)]))
		return (0);
	if (is_obstacle(game->var.map[(int)(y + COLLISION_BUFFER)][(int)(x
		- COLLISION_BUFFER)]))
		return (0);
	if (is_obstacle(game->var.map[(int)(y + COLLISION_BUFFER)][(int)(x
		+ COLLISION_BUFFER)]))
		return (0);
	return (1);
}

void	move_player_forward(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * move_speed;
	new_y = game->player.pos_y + game->player.dir_y * move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}
