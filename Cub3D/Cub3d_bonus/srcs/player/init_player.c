/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:46:35 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/10 15:05:32 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->var.map[i])
	{
		j = 0;
		while (game->var.map[i][j])
		{
			if (game->var.map[i][j] == 'N' || game->var.map[i][j] == 'S'
				|| game->var.map[i][j] == 'E' || game->var.map[i][j] == 'W')
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	init_player_direction(t_game *game)
{
	if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
}

static void	init_player_plane(t_game *game)
{
	if (game->var.map[(int)game->player.pos_y][(int)game->player.pos_x] == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'E')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->var.map[(int)game->player.pos_y]
		[(int)game->player.pos_x] == 'W')
	{
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	init_player(t_game *game)
{
	init_player_pos(game);
	init_player_direction(game);
	init_player_plane(game);
}
