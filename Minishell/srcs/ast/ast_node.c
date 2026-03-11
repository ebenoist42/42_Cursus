/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:18 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 11:50:42 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_ast	*init_ast_node(t_token *op, t_token *lt, t_token *rt)
{
	t_ast	*node;

	node = malloc(sizeof * node);
	if (!node)
	{
		free_token_list(lt);
		free_token_list(rt);
		return (NULL);
	}
	node->type = token_to_asttype(op->type);
	node->left = create_ast_node(lt);
	node->argv = NULL;
	return (node);
}

static void	handle_redirection_node(t_ast *node, t_token *rt)
{
	if (rt && rt->str)
	{
		node->target = ft_strdup(rt->str);
		if (rt->next)
			node->right = create_ast_node(rt->next);
		else
			node->right = NULL;
	}
	else
	{
		node->target = NULL;
		node->right = NULL;
	}
}

static t_ast	*ast_from_operator(t_token *tokens)
{
	t_token	*op;
	t_token	*lt;
	t_token	*rt;
	t_ast	*node;

	op = find_highest_priority_operator(tokens);
	if (!op)
		return (NULL);
	lt = tokens_gauche(tokens, op);
	rt = tokens_droite(op);
	node = init_ast_node(op, lt, rt);
	if (!node)
		return (NULL);
	free_token_list(lt);
	if (node->type == N_REDIR_IN || node->type == N_REDIR_OUT
		|| node->type == N_APPEND || node->type == N_HEREDOC)
		handle_redirection_node(node, rt);
	else
		handle_regular_node(node, rt);
	free_token_list(rt);
	return (node);
}

static t_ast	*ast_from_simple(t_token *tokens)
{
	t_ast	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->type = N_CMD;
	node->argv = extract_argv(tokens);
	node->left = NULL;
	node->right = NULL;
	node->target = NULL;
	return (node);
}

t_ast	*create_ast_node(t_token *tokens)
{
	t_ast	*node;

	node = ast_from_operator(tokens);
	if (node)
		return (node);
	return (ast_from_simple(tokens));
}
