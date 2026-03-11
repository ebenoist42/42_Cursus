/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_R.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:51:41 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/25 14:50:42 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a, int silent)
{
	t_list	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = NULL;
	ft_lstlast(tmp)->next = *a;
	*a = tmp;
	if (!silent)
		ft_printf("ra\n");
}

void	rb(t_list **b, int silent)
{
	t_list	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = NULL;
	ft_lstlast(tmp)->next = *b;
	*b = tmp;
	if (!silent)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
}

void	rra(t_list **a, int silent)
{
	t_list	*tmp;
	t_list	*prev;

	if (!(*a) || !(*a)->next)
		return ;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	tmp = prev->next;
	prev->next = NULL;
	tmp->next = *a;
	*a = tmp;
	if (!silent)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int silent)
{
	t_list	*tmp;
	t_list	*prev;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	prev = tmp->next;
	tmp->next = NULL;
	prev->next = *b;
	*b = prev;
	if (!silent)
		ft_printf("rrb\n");
}
