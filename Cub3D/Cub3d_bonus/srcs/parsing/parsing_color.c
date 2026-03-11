/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:11:09 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/11/10 15:04:14 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing_color(char *str, t_rgb *color)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(str, ',');
	if (!tmp)
		return (1);
	while (tmp[i])
		i++;
	if (i != 3)
		return (ft_free(tmp), 1);
	i = 0;
	color->r = ft_atoi(tmp[i++]);
	color->g = ft_atoi(tmp[i++]);
	color->b = ft_atoi(tmp[i++]);
	ft_free(tmp);
	if (color->r < 0 || color->r > 255)
		return (1);
	if (color->g < 0 || color->g > 255)
		return (1);
	if (color->b < 0 || color->b > 255)
		return (1);
	return (0);
}
