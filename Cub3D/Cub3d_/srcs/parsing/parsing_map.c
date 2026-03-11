/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:15:18 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/10 15:01:16 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_token	process_texture_no_we(char *map, t_token token, int j,
		t_game *game)
{
	if (!strncmp(&map[j], "NO ", 3))
	{
		token.no++;
		game->var.no = extract_texture_path(map, j, 3);
		if (!game->var.no)
			token.error++;
	}
	else if (!strncmp(&map[j], "WE ", 3))
	{
		token.we++;
		game->var.we = extract_texture_path(map, j, 3);
		if (!game->var.we)
			token.error++;
	}
	return (token);
}

static t_token	process_texture_ea_so(char *map, t_token token, int j,
		t_game *game)
{
	if (!strncmp(&map[j], "EA ", 3))
	{
		token.ea++;
		game->var.ea = extract_texture_path(map, j, 3);
		if (!game->var.ea)
			token.error++;
	}
	else if (!strncmp(&map[j], "SO ", 3))
	{
		token.so++;
		game->var.so = extract_texture_path(map, j, 3);
		if (!game->var.so)
			token.error++;
	}
	return (token);
}

static t_token	check_texture_color(char *map, t_token token, int j,
		t_game *game)
{
	while (map[j] && !all_tokens_are_one(token))
	{
		while (map[j] && ft_isspace(map[j]))
			j++;
		if (token.error)
			break ;
		if (!map[j])
			return (token);
		token = process_texture_no_we(map, token, j, game);
		if (token.error > 0)
			break ;
		token = process_texture_ea_so(map, token, j, game);
		if (token.error > 0)
			break ;
		token = process_colors(map, token, j, game);
		if (token.error > 0)
			break ;
		break ;
	}
	return (token);
}

static int	check_texture(char **map, int i, t_game *game)
{
	t_token	token;

	memset(&token, 0, sizeof(t_token));
	while (map[i] && !all_tokens_are_one(token))
	{
		token = check_texture_color(map[i], token, 0, game);
		i++;
	}
	if (token.ea == 1 && token.we == 1 && token.so == 1 && token.no == 1
		&& token.c == 1 && token.f == 1 && token.error == 0)
		return (i);
	return (0);
}

int	check_map_valide(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	map = game->map;
	i = check_texture(map, i, game);
	if (i == 0)
	{
		free_end_of_programme(game);
		msg_and_quit("Error\nMap invalide, bad texture/colors\n");
	}
	if (!check_map(map, i, 0, 0))
	{
		free_end_of_programme(game);
		msg_and_quit("Error\nMap invalide\n");
	}
	game->var.map = extract_map(game->map, i);
	if (!game->var.map)
	{
		free_end_of_programme(game);
		msg_and_quit("Error\nExtract map failed\n");
	}
	return (1);
}
