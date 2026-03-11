/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:40:40 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/04 14:41:37 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_forward(t_game *game, double move_speed)
{
	if (game->var.map[(int)(game->player.pos_y + game->player.dir_y
			* move_speed)][(int)game->player.pos_x] != '1')
		game->player.pos_y += game->player.dir_y * move_speed;
	if (game->var.map[(int)game->player.pos_y][(int)(game->player.pos_x
		+ game->player.dir_x * move_speed)] != '1')
		game->player.pos_x += game->player.dir_x * move_speed;
}
