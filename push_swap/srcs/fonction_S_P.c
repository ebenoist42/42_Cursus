/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_S_P.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:51:25 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/25 11:08:14 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list *a)
{
	int	i;

	if (!a || !a -> next)
		return ;
	i = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = i;
	ft_printf("sa\n");
}

void	sb(t_list *b)
{
	int	i;

	if (!b || !b -> next)
		return ;
	i = b -> content;
	b -> content = b -> next -> content;
	b -> next -> content = i;
	ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	int	i;

	if (!a || !a -> next || !b || !b -> next)
		return ;
	i = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = i;
	i = b -> content;
	b -> content = b -> next -> content;
	b -> next -> content = i;
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!a)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_printf("pb\n");
}
