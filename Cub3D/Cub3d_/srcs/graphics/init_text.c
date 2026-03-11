/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:35:25 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/14 13:39:48 by ebenoist         ###   ########.fr       */
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
		ft_putstr_fd("Warning: failed to load alternative North texture\n", 2);
}

static void	init_north_texture(t_game *game)
{
	game->texture.no = mlx_xpm_file_to_image(game->mlx.mlx_ptr, game->var.no,
			&game->texture.tex_ptr[0].width, &game->texture.tex_ptr[0].height);
	if (!game->texture.no)
		msg_and_eof(game, "Warning: Failed to load North texture\n");
	else
	{
		game->texture.tex_ptr[0].data = (unsigned int *)mlx_get_data_addr
			(game->texture.no,
				&game->texture.tex_ptr[0].bpp,
				&game->texture.tex_ptr[0].size_line,
				&game->texture.tex_ptr[0].endian);
		if (!game->texture.tex_ptr[0].data)
			msg_and_eof(game, "Error: Failed to get North texture data\n");
	}
}

static void	init_south_texture(t_game *game)
{
	game->texture.so = mlx_xpm_file_to_image(game->mlx.mlx_ptr, game->var.so,
			&game->texture.tex_ptr[2].width, &game->texture.tex_ptr[2].height);
	if (!game->texture.so)
		msg_and_eof(game, "Warning: Failed to load South texture\n");
	else
	{
		game->texture.tex_ptr[2].data = (unsigned int *)mlx_get_data_addr
			(game->texture.so,
				&game->texture.tex_ptr[2].bpp,
				&game->texture.tex_ptr[2].size_line,
				&game->texture.tex_ptr[2].endian);
		if (!game->texture.tex_ptr[2].data)
			msg_and_eof(game, "Error: Failed to get South texture data\n");
	}
}

static void	init_east_texture(t_game *game)
{
	game->texture.ea = mlx_xpm_file_to_image(game->mlx.mlx_ptr, game->var.ea,
			&game->texture.tex_ptr[1].width, &game->texture.tex_ptr[1].height);
	if (!game->texture.ea)
		msg_and_eof(game, "Warning: Failed to load East texture\n");
	else
	{
		game->texture.tex_ptr[1].data = (unsigned int *)mlx_get_data_addr
			(game->texture.ea,
				&game->texture.tex_ptr[1].bpp,
				&game->texture.tex_ptr[1].size_line,
				&game->texture.tex_ptr[1].endian);
		if (!game->texture.tex_ptr[1].data)
			msg_and_eof(game, "Error: Failed to get East texture data\n");
	}
}

static void	init_west_texture(t_game *game)
{
	game->texture.we = mlx_xpm_file_to_image(game->mlx.mlx_ptr, game->var.we,
			&game->texture.tex_ptr[3].width, &game->texture.tex_ptr[3].height);
	if (!game->texture.we)
		msg_and_eof(game, "Warning: Failed to load West texture\n");
	else
	{
		game->texture.tex_ptr[3].data = (unsigned int *)mlx_get_data_addr
			(game->texture.we,
				&game->texture.tex_ptr[3].bpp,
				&game->texture.tex_ptr[3].size_line,
				&game->texture.tex_ptr[3].endian);
		if (!game->texture.tex_ptr[3].data)
			msg_and_eof(game, "Error: Failed to get West texture data\n");
	}
}

void	init_texture(t_game *game)
{
	init_north_texture(game);
	init_north2_texture(game);
	init_east_texture(game);
	init_south_texture(game);
	init_west_texture(game);
}
