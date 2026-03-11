/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:57:06 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/25 16:41:48 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi2(t_list *a, char *avi, char **av, int sp)
{
	long	nb;

	nb = ft_atoi(avi);
	if (ft_strlen(avi) > 11 || nb < -2147483648 || nb > 2147483647)
		ft_error_free_split(&a, av, sp);
	return ((int)nb);
}

t_list	*ft_create_stack(int ac, char **av, int sp)
{
	t_list	*tmp;
	t_list	*a;
	int		i;

	i = 1;
	tmp = NULL;
	a = NULL;
	if (sp > 0)
		i = 0;
	a = ft_lstnew(ft_atoi2(a, av[i++], av, sp));
	if (!a)
		ft_error_free_split(&a, av, sp);
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi2(a, av[i++], av, sp));
		if (!tmp)
			ft_error_free_split(&a, av, sp);
		ft_lstadd_back(&a, tmp);
	}
	return (a);
}

void	ft_check_twins(t_list *a, char **av, int sp)
{
	t_list	*tmp;
	t_list	*check;

	tmp = a;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->content == check->content)
				ft_error_free_split(&a, av, sp);
			check = check->next;
		}
		tmp = tmp->next;
	}
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 1);
	rrb(b, 1);
	ft_printf("rrr\n");
}
