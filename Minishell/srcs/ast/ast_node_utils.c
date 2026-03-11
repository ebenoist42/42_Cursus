/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:55:18 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 12:04:04 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*find_highest_priority_operator(t_token *tokens)
{
	t_token	*current;
	t_token	*highest;
	int		min_priority;

	current = tokens;
	highest = NULL;
	min_priority = 100;
	while (current)
	{
		if (current->type != T_WORD && current->priority < min_priority)
		{
			min_priority = current->priority;
			highest = current;
		}
		else if (current->type != T_WORD && current->priority == min_priority)
		{
			if (current->type == T_REDIR_IN || current->type == T_REDIR_OUT
				|| current->type == T_APPEND || current->type == T_HEREDOC)
				highest = current;
		}
		current = current->next;
	}
	return (highest);
}

t_token	*tokens_gauche(t_token *tokens, t_token *op)
{
	t_token	*head;
	t_token	*tail;
	t_token	*current;
	t_token	*new;

	head = NULL;
	tail = NULL;
	current = tokens;
	while (current && current != op)
	{
		new = malloc(sizeof(t_token));
		*new = *current;
		if (current->str)
			new->str = ft_strdup(current->str);
		else
			new->str = NULL;
		new->next = NULL;
		if (!head)
			head = new;
		else
			tail->next = new;
		tail = new;
		current = current->next;
	}
	return (head);
}

static t_token	*dup_token(t_token *src)
{
	t_token	*dst;

	dst = malloc(sizeof * dst);
	if (!dst)
		return (NULL);
	*dst = *src;
	if (src->str)
		dst->str = ft_strdup(src->str);
	else
		dst->str = NULL;
	dst->next = NULL;
	return (dst);
}

t_token	*tokens_droite(t_token *op)
{
	t_token	*head;
	t_token	*tail;
	t_token	*copy;

	if (!op || !op->next)
		return (NULL);
	head = NULL;
	op = op->next;
	while (op)
	{
		copy = dup_token(op);
		if (!copy)
		{
			free_token_list(head);
			return (NULL);
		}
		if (!head)
			head = copy;
		else
			tail->next = copy;
		tail = copy;
		op = op->next;
	}
	return (head);
}

int	is_redirection_token(t_token *jeton)
{
	if (!jeton)
		return (0);
	return (jeton->type == T_REDIR_IN || jeton->type == T_REDIR_OUT
		|| jeton->type == T_APPEND);
}
