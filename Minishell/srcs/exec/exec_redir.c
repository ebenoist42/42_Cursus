/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:10:03 by ebenoist          #+#    #+#             */
/*   Updated: 2025/09/29 15:29:02 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	process_redirections_recursive(t_ast *node, int *saved_in,
		int *saved_out, int *tmp)
{
	t_ast	*current;

	if (!node || !is_redirection(node))
		return (0);
	if (node->type == N_HEREDOC && is_heredoc_chain(node))
	{
		if (process_heredoc_chain(node, saved_in, tmp) < 0)
			return (-1);
		current = node;
		while (current && current->type == N_HEREDOC)
			current = current->left;
		return (process_redirections_recursive(current, saved_in, saved_out,
				tmp));
	}
	if (process_redirections_recursive(node->left, saved_in, saved_out,
			tmp) < 0)
		return (-1);
	return (apply_redirection(node, saved_in, saved_out, tmp));
}

static void	restore_saved_fds(int saved_in, int saved_out)
{
	if (saved_in >= 0)
	{
		dup2(saved_in, STDIN_FILENO);
		close(saved_in);
	}
	if (saved_out >= 0)
	{
		dup2(saved_out, STDOUT_FILENO);
		close(saved_out);
	}
}

static t_ast	*find_exec_node(t_ast *ast)
{
	t_ast	*node;

	node = ast;
	while (node && is_redirection(node))
	{
		if (node->right)
			node = node->right;
		else if (node->left)
			node = node->left;
		else
			break ;
	}
	return (node);
}

int	execute_redirect(t_ast *ast)
{
	int		saved_in;
	int		saved_out;
	int		tmp[1024];
	t_ast	*node;

	saved_in = -1;
	saved_out = -1;
	init_tmp_array(tmp);
	if (process_redirections_recursive(ast, &saved_in, &saved_out, tmp) < 0)
	{
		restore_saved_fds(saved_in, saved_out);
		return (_data()->exit_code);
	}
	node = find_exec_node(ast);
	execute_recursive(node, STDIN_FILENO, STDOUT_FILENO);
	restore_saved_fds(saved_in, saved_out);
	return (_data()->exit_code);
}
