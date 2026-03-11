/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:18:55 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:36:13 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	find_player(t_game *game, int *y, int *x)
{
	int	o;
	int	p;

	o = 0;
	while (game->map[o])
	{
		p = 0;
		while (game->map[o][p])
		{
			if (game->map[o][p] == 'P')
			{
				*y = o;
				*x = p;
				return ;
			}
			p++;
		}
		o++;
	}
}

static void	move_player(t_game *game, int next_y, int next_x)
{
	int	pl_x;
	int	pl_y;
	int	new_x;
	int	new_y;

	find_player(game, &pl_y, &pl_x);
	new_y = pl_y + next_y;
	new_x = pl_x + next_x;
	if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E')
		return ;
	if (game->map[new_y][new_x] == 'e')
		sucess_game(game);
	if (game->map[new_y][new_x] == 'M')
		loose_game(game);
	if (game->map[new_y][new_x] == 'C')
		take_collectible(game, new_y, new_x);
	count_moves(game);
	game->map[new_y][new_x] = 'P';
	game->map[pl_y][pl_x] = '0';
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, -1, 0);
	if (keycode == 97)
		move_player(game, 0, -1);
	if (keycode == 115)
		move_player(game, 1, 0);
	if (keycode == 100)
		move_player(game, 0, 1);
	if (keycode == 65307)
	{
		destroy_game(game);
		exit(0);
	}
	return (0);
}
