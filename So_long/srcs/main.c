/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 08:22:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:37:39 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_mlx(game);
	x = ft_strlen(game->map[0]) - 1;
	while (game->map[y])
		y++;
	game->win = mlx_new_window(game->mlx, x * TILE_SIZE, y * TILE_SIZE,
			"so_long");
	if (!game->win)
		error_mlx(game);
	load_image(game);
	render_map(game);
}

static int	close_game(t_game *game)
{
	destroy_game(game);
	return (0);
}

int	game_loop(t_game *game)
{
	update_animation(game);
	render_map(game);
	return (0);
}

void	update_animation(t_game *game)
{
	game->frame_delay++;
	if (game->frame_delay >= 150)
	{
		game->current_frame = (game->current_frame + 1) % 2;
		game->frame_delay = 0;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_arg_error(ac, av[1]);
	game.map = read_file(av[1]);
	ft_check_norm(&game);
	game.moves = 0;
	init_game(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	destroy_game(&game);
	return (0);
}
