/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:25:59 by ebenoist          #+#    #+#             */
/*   Updated: 2025/06/26 07:20:27 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_liste
{
	t_list	*a;
	t_list	*b;
	int		size;
}			t_pile;

void		ft_error_free_split(t_list **a, char **av, int sp);
int			ft_atoi2(t_list *a, char *avi, char **av, int sp);
t_list		*ft_create_stack(int ac, char **av, int sp);
void		free_programme(t_list **a, t_list **b, char **av, int sp);
void		ft_check_twins(t_list *a, char **av, int sp);
void		sa(t_list *a);
void		sb(t_list *b);
void		ss(t_list *a, t_list *b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a, int silent);
void		rb(t_list **b, int silent);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a, int silent);
void		rrb(t_list **b, int silent);
void		rrr(t_list **a, t_list **b);
int			*fill_tab(t_list **a, char **av, int sp);
void		sort_int_tab(int *tab, t_list **a);
void		index_for_list(int *tab, t_list **a);
void		index_creat(t_list **a, char **av, int sp);
void		sort_stack(t_list **a, t_list **b);
void		sort_three(t_list **a);
int			ft_find_pos(t_list *a, int min);
void		sort_five(t_list **a, t_list **b);
void		radix_sort(t_list **a, t_list **b);
int			check_sort(t_list **a);
#endif
