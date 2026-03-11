/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:49:29 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:36:24 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_moves(t_game *game)
{
	game->moves = game->moves + 1;
	ft_printf("Mouvement No %d ! \n", game->moves);
}

void	loose_game(t_game *game)
{
	ft_printf("Perdu ! Browser ta tuer !\n");
	destroy_game(game);
}

void	sucess_game(t_game *game)
{
	count_moves(game);
	ft_printf("SUCESS CONGRAT !\n");
	destroy_game(game);
}

static void	change_exit(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				map[y][x] = 'e';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	take_collectible(t_game *game, int y, int x)
{
	game->map[y][x] = '0';
	game->collect_count = game->collect_count - 1;
	if (game->collect_count == 0)
		change_exit(game->map);
}
