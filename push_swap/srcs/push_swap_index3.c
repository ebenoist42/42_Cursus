/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:08:52 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/26 07:50:38 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (!check_sort(a))
		return ;
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(*a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size > 1 && size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

static int	ft_find_min(t_list *a)
{
	int		i;
	t_list	*tmp;

	tmp = a;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->content < i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_find_pos(t_list *a, int min)
{
	int	find;

	find = 0;
	while (a)
	{
		if (a->content == min)
			return (find);
		a = a->next;
		find++;
	}
	return (-1);
}

void	sort_five(t_list **a, t_list **b)
{
	int	size;
	int	min;
	int	find;

	size = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3)
	{
		min = ft_find_min(*a);
		find = ft_find_pos(*a, min);
		if (find == 0)
			pb(a, b);
		else if (find <= size / 2)
			ra(a, 0);
		else
			rra(a, 0);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_three(t_list **a)
{
	int	wa;
	int	b;
	int	c;

	wa = (*a)->content;
	b = (*a)->next->content;
	c = (*a)->next->next->content;
	if (wa > b && b < c && wa < c)
		sa(*a);
	else if (wa > b && b > c)
	{
		sa(*a);
		rra(a, 0);
	}
	else if (wa > b && b < c && wa > c)
		ra(a, 0);
	else if (wa < b && b > c && wa < c)
	{
		sa(*a);
		ra(a, 0);
	}
	else if (wa < b && b > c && wa > c)
		rra(a, 0);
}
