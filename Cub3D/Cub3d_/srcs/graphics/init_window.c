/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:39:26 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/14 13:40:13 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->mlx.line_len + x * game->mlx.bpp / 8;
	game->mlx.img_data[index] = color & 0xFF;
	game->mlx.img_data[index + 1] = (color >> 8) & 0xFF;
	game->mlx.img_data[index + 2] = (color >> 16) & 0xFF;
}

void	init_window(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
	{
		ft_putstr_fd("Error: Failed to initialize MLX.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mlx.w_ptr = mlx_new_window(game->mlx.mlx_ptr, WIDTH, HEIGHT, "cub3d");
	if (!game->mlx.w_ptr)
	{
		ft_putstr_fd("Error: Failed to create a new window.\n", 2);
		free(game->mlx.mlx_ptr);
		exit(EXIT_FAILURE);
	}
	game->ig = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
	game->mlx.img_data = mlx_get_data_addr(game->ig, &game->mlx.bpp,
			&game->mlx.line_len, &game->mlx.endian);
	init_texture(game);
}
