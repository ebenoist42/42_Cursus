/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:34:07 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/13 15:53:45 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
	keys->esc = 0;
}

void	toggle_door(t_game *game)
{
	int	check_x;
	int	check_y;

	check_x = (int)(game->player.pos_x + game->player.dir_x * 1.5);
	check_y = (int)(game->player.pos_y + game->player.dir_y * 1.5);
	if (game->var.map[check_y][check_x] == 'D')
		game->var.map[check_y][check_x] = 'T';
	else if (game->var.map[check_y][check_x] == 'T')
		game->var.map[check_y][check_x] = 'D';
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	else if (keycode == KEY_ESC)
		game->keys.esc = 1;
	else if (keycode == KEY_SPACE)
		toggle_door(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	else if (keycode == KEY_ESC)
		game->keys.esc = 0;
	return (0);
}
