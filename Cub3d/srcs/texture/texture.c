/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:34:13 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/14 13:37:11 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_tex_data	*get_wall_texture(t_game *game)
{
	t_tex_data	*tex_data;
	int			frame_toggle;

	frame_toggle = (game->mlx.anim_frame / 30) % 2;
	tex_data = NULL;
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_y > 0)
			tex_data = &game->texture.tex_ptr[2];
		else
			if (frame_toggle && game->texture.alt_tex_ptr[0].data)
				tex_data = &game->texture.alt_tex_ptr[0];
		else
			tex_data = &game->texture.tex_ptr[0];
	}
	else
	{
		if (game->ray.ray_dir_x > 0)
			tex_data = &game->texture.tex_ptr[3];
		else
			tex_data = &game->texture.tex_ptr[1];
	}
	return (tex_data);
}

static void	draw_texture_pixels(t_game *game, t_tex_data *tex_data, int x)
{
	double	tex_y;
	double	tex_x;
	int		color;
	int		y;

	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		tex_y = (y - (HEIGHT - game->ray.line_height) / 2.0)
			/ (double)game->ray.line_height;
		tex_x = game->ray.wall_x;
		color = get_texture_pixel(game, tex_data, tex_x, tex_y);
		put_pixel(x, y, color, game);
		y++;
	}
}

void	draw_textured_column(t_game *game, int x)
{
	t_tex_data	*tex_data;
	t_tex_data	*alt_data;

	alt_data = NULL;
	tex_data = get_wall_texture(game);
	draw_texture_pixels(game, tex_data, x);
}
