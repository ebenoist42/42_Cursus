/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:24:00 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/13 16:08:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_player_backward(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * move_speed;
	new_y = game->player.pos_y - game->player.dir_y * move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

static void	move_player_right(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * move_speed;
	new_y = game->player.pos_y + game->player.dir_x * move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

static void	move_player_left(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * move_speed;
	new_y = game->player.pos_y - game->player.dir_x * move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

static void	move_player(t_game *game, int keycode)
{
	double	move_speed;

	move_speed = 0.08;
	if (keycode == KEY_W)
		move_player_forward(game, move_speed);
	else if (keycode == KEY_S)
		move_player_backward(game, move_speed);
	else if (keycode == KEY_A)
		move_player_left(game, move_speed);
	else if (keycode == KEY_D)
		move_player_right(game, move_speed);
}

void	handle_movement(t_game *game)
{
	if (game->keys.w)
		move_player(game, KEY_W);
	if (game->keys.s)
		move_player(game, KEY_S);
	if (game->keys.a)
		move_player(game, KEY_A);
	if (game->keys.d)
		move_player(game, KEY_D);
}
