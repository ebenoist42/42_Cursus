/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:59:41 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/13 16:40:02 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_north2_texture(t_game *game)
{
	game->texture.img_alt[0] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./img/blue_planks2.xpm", &game->texture.alt_tex_ptr[0].width,
			&game->texture.alt_tex_ptr[0].height);
	if (game->texture.img_alt[0])
	{
		game->texture.alt_tex_ptr[0].data = (unsigned int *)mlx_get_data_addr
			(game->texture.img_alt[0],
				&game->texture.alt_tex_ptr[0].bpp,
				&game->texture.alt_tex_ptr[0].size_line,
				&game->texture.alt_tex_ptr[0].endian);
	}
	else
		msg_and_eof(game, "Error: Failed to get North texture data\n");
}

void	init_door_open_texture(t_game *game)
{
	game->texture.img_alt[1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./img/door.xpm", &game->texture.alt_tex_ptr[1].width,
			&game->texture.alt_tex_ptr[1].height);
	if (game->texture.img_alt[1])
	{
		game->texture.alt_tex_ptr[1].data = (unsigned int *)mlx_get_data_addr
			(game->texture.img_alt[1],
				&game->texture.alt_tex_ptr[1].bpp,
				&game->texture.alt_tex_ptr[1].size_line,
				&game->texture.alt_tex_ptr[1].endian);
	}
	else
		msg_and_eof(game, "Error: Failed to get Door Open texture data\n");
}

void	init_door_close_texture(t_game *game)
{
	game->texture.img_alt[2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./img/door_2.xpm", &game->texture.alt_tex_ptr[2].width,
			&game->texture.alt_tex_ptr[2].height);
	if (game->texture.img_alt[2])
	{
		game->texture.alt_tex_ptr[2].data = (unsigned int *)mlx_get_data_addr
			(game->texture.img_alt[2],
				&game->texture.alt_tex_ptr[2].bpp,
				&game->texture.alt_tex_ptr[2].size_line,
				&game->texture.alt_tex_ptr[2].endian);
	}
	else
		msg_and_eof(game, "Error: Failed to get Door Close texture data\n");
}
