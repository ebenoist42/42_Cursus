/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:47:39 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/14 14:13:44 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	memset(&game, 0, sizeof(t_game));
	check_arg(ac, av);
	game.map = malloc_maps(av[1]);
	check_map_valide(&game);
	init_keys(&game.keys);
	init_player(&game);
	init_window(&game);
	mlx_hook(game.mlx.w_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.w_ptr, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx.w_ptr, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
	free_end_of_programme(&game);
}
