/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:54:42 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 12:02:39 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	free_ast(ast->left);
	free_ast(ast->right);
	if (ast->type == N_CMD && ast->argv)
		ft_free(ast->argv);
	if (ast->target)
		free(ast->target);
	free(ast);
}

static char	**allocate_argv_array(int size)
{
	char	**arg;

	if (size == 0)
		return (NULL);
	arg = malloc(sizeof(char *) * (size + 1));
	if (!arg)
		error_malloc();
	return (arg);
}

static void	fill_argv_array(char **arg, t_token *token, int size)
{
	t_token	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp && i < size)
	{
		arg[i] = ft_strdup(tmp->str);
		if (!arg[i])
		{
			ft_free(arg);
			error_malloc();
		}
		tmp = tmp->next;
		i++;
	}
	arg[i] = NULL;
}

char	**extract_argv(t_token *token)
{
	int		size;
	char	**arg;

	if (!token)
		return (NULL);
	size = count_args(token);
	arg = allocate_argv_array(size);
	if (!arg)
		return (NULL);
	fill_argv_array(arg, token, size);
	return (arg);
}

t_asttype	token_to_asttype(t_tokentype type)
{
	if (type == T_PIPE)
		return (N_PIPE);
	else if (type == T_REDIR_OUT)
		return (N_REDIR_OUT);
	else if (type == T_HEREDOC)
		return (N_HEREDOC);
	else if (type == T_REDIR_IN)
		return (N_REDIR_IN);
	else if (type == T_APPEND)
		return (N_APPEND);
	return (N_CMD);
}
