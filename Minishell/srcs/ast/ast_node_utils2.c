/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:49:17 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 12:02:52 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_regular_node(t_ast *node, t_token *rt)
{
	node->right = create_ast_node(rt);
	node->target = NULL;
}

int	count_args(t_token *token)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp && tmp->str)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
