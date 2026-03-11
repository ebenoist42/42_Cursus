/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:25:42 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/25 14:45:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_ajust_ac(t_list *a, char **av, int sp)
{
	int	i;

	if (!av[0])
		ft_error_free_split(&a, av, sp);
	i = 0;
	while (av[i])
		i++;
	return (i);
}

static int	check_av(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		count++;
	}
	if (str[i] || !count)
		return (1);
	return (0);
}

static void	ft_control(t_list *a, int ac, char **av, int sp)
{
	int	i;

	i = 1;
	if (sp == 1)
		i = 0;
	while (i < ac)
	{
		if (check_av(av[i]) != 0)
			ft_error_free_split(&a, av, sp);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		sp;

	a = NULL;
	b = NULL;
	sp = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
			ft_error_free_split(&a, av, sp);
		sp = 1;
		ac = ft_ajust_ac(a, av, sp);
	}
	ft_control(a, ac, av, sp);
	a = ft_create_stack(ac, av, sp);
	ft_check_twins(a, av, sp);
	index_creat(&a, av, sp);
	sort_stack(&a, &b);
	free_programme(&a, &b, av, sp);
}
