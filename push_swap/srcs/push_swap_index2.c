/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:53:39 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/25 14:51:18 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*fill_tab(t_list **a, char **av, int sp)
{
	t_list	*tmp;
	int		*tab;
	int		i;
	int		size;

	size = ft_lstsize(*a);
	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		ft_error_free_split(a, av, sp);
	tmp = *a;
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

void	sort_int_tab(int *tab, t_list **a)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = 0;
	tmp = 0;
	size = ft_lstsize(*a);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				i = 0;
			}
			j++;
		}
		i++;
	}
}

void	index_for_list(int *tab, t_list **a)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	size = ft_lstsize(*a);
	tmp = *a;
	while (i < size)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->content == tab[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	free(tab);
}

void	index_creat(t_list **a, char **av, int sp)
{
	int		*tab;
	t_list	*tmp;

	tab = fill_tab(a, av, sp);
	sort_int_tab(tab, a);
	index_for_list(tab, a);
	tmp = *a;
	while (tmp)
	{
		tmp->content = tmp->index;
		tmp = tmp->next;
	}
}
