/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:15:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 10:01:59 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	collectible_environent(t_game *game, int *x, int *y)
{
	void	*current;

	if (game->map[*y][*x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, *x
			* TILE_SIZE, *y * TILE_SIZE);
	else if (game->map[*y][*x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect, *x
			* TILE_SIZE, *y * TILE_SIZE);
	else if (game->map[*y][*x] == 'e')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit2, *x
			* TILE_SIZE, *y * TILE_SIZE);
	else if (game->map[*y][*x] == 'M')
	{
		current = NULL;
		if (game->current_frame == 0)
			current = game->img_enemy;
		else
			current = game->img_enemy2;
		mlx_put_image_to_window(game->mlx, game->win, current, *x * TILE_SIZE,
			*y * TILE_SIZE);
	}
}

static void	put_count(t_game *game)
{
	char	*tmp;

	tmp = ft_itoa(game->moves);
	if (!tmp)
		ft_error_malloc_2(game);
	mlx_string_put(game->mlx, game->win, 17, 40, 0xFFFFFF, tmp);
	free(tmp);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* TILE_SIZE, y * TILE_SIZE);
			else
				collectible_environent(game, &x, &y);
			x++;
		}
		y++;
	}
	put_count(game);
}

void	load_image(t_game *game)
{
	int	i;

	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./img/tile-floor.xpm",
			&i, &i);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./img/tile-wall.xpm", &i,
			&i);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./img/sprite-player.xpm", &i, &i);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./img/chest1.xpm", &i,
			&i);
	game->img_exit2 = mlx_xpm_file_to_image(game->mlx, "./img/chest2.xpm", &i,
			&i);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./img/sprite-enemy.xpm",
			&i, &i);
	game->img_enemy2 = mlx_xpm_file_to_image(game->mlx,
			"./img/sprite_enemy2.xpm", &i, &i);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm",
			&i, &i);
	if (!game->img_wall || !game->img_player || !game->img_floor
		|| !game->img_exit || !game->img_collect || !game->img_enemy
		|| !game->img_enemy2)
		error_load(game);
	game->frame_delay = 0;
	game->current_frame = 0;
}
