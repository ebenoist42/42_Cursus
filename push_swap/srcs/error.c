/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:38:28 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/25 11:05:30 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_free_split(t_list **a, char **av, int sp)
{
	int	i;

	i = 1;
	write(2, "Error\n", 6);
	if (sp > 0 && av)
	{
		i = 0;
		if (!av)
			return ;
		while (av[i])
			free (av[i++]);
		free (av);
	}
	if (a && *a)
	{
		ft_lstclear(a);
	}
	exit(1);
}

void	free_programme(t_list **a, t_list **b, char **av, int sp)
{
	int	i;

	i = 1;
	if (sp > 0 && av)
	{
		i = 0;
		if (!av)
			return ;
		while (av[i])
			free(av[i++]);
		free(av);
	}
	if (a && *a)
		ft_lstclear(a);
	if (b && *b)
		ft_lstclear(b);
}
