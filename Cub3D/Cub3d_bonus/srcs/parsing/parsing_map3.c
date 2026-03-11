/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:49:25 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/10 15:01:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	all_tokens_are_one(t_token token)
{
	if (token.no != 1)
		return (0);
	if (token.so != 1)
		return (0);
	if (token.we != 1)
		return (0);
	if (token.ea != 1)
		return (0);
	if (token.f != 1)
		return (0);
	if (token.c != 1)
		return (0);
	return (1);
}

t_token	process_colors(char *map, t_token token, int j, t_game *game)
{
	if (!strncmp(&map[j], "C ", 2))
	{
		token.c++;
		game->var.c = extract_color_line(map, j, 2);
		if (!game->var.c)
			token.error++;
		else if (parsing_color(game->var.c, &game->c))
			token.error++;
	}
	else if (!strncmp(&map[j], "F ", 2))
	{
		token.f++;
		game->var.f = extract_color_line(map, j, 2);
		if (!game->var.f)
			token.error++;
		else if (parsing_color(game->var.f, &game->f))
			token.error++;
	}
	return (token);
}
