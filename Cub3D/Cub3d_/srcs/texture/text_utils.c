/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:49:03 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/11 11:53:36 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_floor_ceiling(t_game *game, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_hex(game->c.r, game->c.g, game->c.b);
	floor_color = rgb_to_hex(game->f.r, game->f.g, game->f.b);
	y = 0;
	while (y < game->ray.draw_start)
	{
		put_pixel(x, y, ceiling_color, game);
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		put_pixel(x, y, floor_color, game);
		y++;
	}
}

static void	clamp_texture_coords(double *tex_x, double *tex_y)
{
	if (*tex_x < 0.0)
		*tex_x = 0.0;
	if (*tex_x > 1.0)
		*tex_x = 1.0;
	if (*tex_y < 0.0)
		*tex_y = 0.0;
	if (*tex_y > 1.0)
		*tex_y = 1.0;
}

static void	clamp_pixel_coords(int *pixel_x, int *pixel_y, t_tex_data *tex_data)
{
	if (*pixel_x < 0)
		*pixel_x = 0;
	if (*pixel_x >= tex_data->width)
		*pixel_x = tex_data->width - 1;
	if (*pixel_y < 0)
		*pixel_y = 0;
	if (*pixel_y >= tex_data->height)
		*pixel_y = tex_data->height - 1;
}

int	get_texture_pixel(t_game *game, t_tex_data *tex_data, double tex_x,
		double tex_y)
{
	int	pixel_x;
	int	pixel_y;
	int	index;

	(void)game;
	if (!tex_data || !tex_data->data)
		return (0xFFFFFF);
	clamp_texture_coords(&tex_x, &tex_y);
	pixel_x = (int)(tex_x * (tex_data->width - 1));
	pixel_y = (int)(tex_y * (tex_data->height - 1));
	clamp_pixel_coords(&pixel_x, &pixel_y, tex_data);
	index = pixel_y * (tex_data->size_line / 4) + pixel_x;
	return (tex_data->data[index]);
}
