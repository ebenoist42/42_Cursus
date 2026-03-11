/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:49:09 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/31 11:35:05 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_arg(int ac, char **av)
{
	size_t	len;

	if (ac == 1)
	{
		ft_putstr_fd("Error\nNo Maps Provided\n", 2);
		exit(1);
	}
	if (ac == 2)
	{
		len = strlen(av[1]);
		if (ft_strncmp(av[1] + (len - 4), ".cub", 4))
		{
			ft_putstr_fd("Error\nWrong Maps Provided\n", 2);
			exit(1);
		}
	}
	if (ac > 2)
	{
		ft_putstr_fd("Error\nToo Much Arguments\n", 2);
		exit(1);
	}
}
