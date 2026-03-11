/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:59:43 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/26 07:50:34 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_find_max(t_list *a)
{
	int	max;

	max = a->content;
	a = a->next;
	while (a != NULL)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	return (max);
}

static int	ft_how_many_bits(int max)
{
	int	count;

	count = 0;
	while (max)
	{
		count++;
		max = max >> 1;
	}
	return (count);
}

static void	while_radix_sort(t_list **a, t_list **b, int bits)
{
	int	size;
	int	j;
	int	value;
	int	current_bit;

	j = 0;
	size = ft_lstsize(*a);
	while (j < size)
	{
		value = (*a)->content;
		current_bit = (value >> bits) & 1;
		if (current_bit == 0)
			pb(a, b);
		else
			ra(a, 0);
		j++;
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	max;
	int	max_bits;

	i = 0;
	max = ft_find_max(*a);
	max_bits = ft_how_many_bits(max);
	while (i < max_bits)
	{
		while_radix_sort(a, b, i);
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}
