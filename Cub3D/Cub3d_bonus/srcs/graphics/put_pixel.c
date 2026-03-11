/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:51:39 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/13 16:51:58 by ebenoist         ###   ########.fr       */
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
