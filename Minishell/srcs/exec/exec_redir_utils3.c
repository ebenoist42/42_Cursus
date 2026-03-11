/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:10:49 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/29 15:12:22 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_heredoc_chain(t_ast *node)
{
	return (node && node->type == N_HEREDOC && node->left
		&& node->left->type == N_HEREDOC);
}

void	init_tmp_array(int *tmp)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		tmp[i] = -1;
		i++;
	}
}
