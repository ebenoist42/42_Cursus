/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_programme.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:06:29 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/11 13:32:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_end_of_programme3(t_game *game)
{
	if (game->mlx.w_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.w_ptr);
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}

static void	free_end_of_programme2(t_game *game)
{
	if (game->mlx.img_wall_we)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_we);
	if (game->mlx.mlx_ptr && game->ig)
		mlx_destroy_image(game->mlx.mlx_ptr, game->ig);
	if (game->mlx.mlx_ptr)
	{
		if (game->texture.no)
			mlx_destroy_image(game->mlx.mlx_ptr, game->texture.no);
		else if (game->mlx.img_wall_no)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_no);
		if (game->texture.ea)
			mlx_destroy_image(game->mlx.mlx_ptr, game->texture.ea);
		else if (game->mlx.img_wall_ea)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_ea);
		if (game->texture.so)
			mlx_destroy_image(game->mlx.mlx_ptr, game->texture.so);
		else if (game->mlx.img_wall_so)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_so);
		if (game->texture.we)
			mlx_destroy_image(game->mlx.mlx_ptr, game->texture.we);
		else if (game->mlx.img_wall_we)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_we);
	}
	free_end_of_programme3(game);
}

void	free_end_of_programme(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->var.map)
		free_map(game->var.map);
	if (game->var.c)
		free(game->var.c);
	if (game->var.f)
		free(game->var.f);
	if (game->var.so)
		free(game->var.so);
	if (game->var.no)
		free(game->var.no);
	if (game->var.ea)
		free(game->var.ea);
	if (game->var.we)
		free(game->var.we);
	if (game->mlx.img_wall_no)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_no);
	if (game->mlx.img_wall_ea)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_ea);
	if (game->mlx.img_wall_so)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_wall_so);
	free_end_of_programme2(game);
}
