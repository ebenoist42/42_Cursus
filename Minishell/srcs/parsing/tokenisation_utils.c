/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:28:57 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/11 14:28:58 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tok_push_back(t_token **head, t_token *new)
{
	t_token	*end;

	if (!new || !head)
		return ;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	end = *head;
	while (end->next)
		end = end->next;
	end->next = new;
}

int	is_boundary(unsigned char c)
{
	if (c == '\0')
		return (1);
	if (c == '|' || c == '<' || c == '>' )
		return (1);
	return (0);
}

int	operator_erreur(const char *s, int i)
{
	if (s[i] == '&')
	{
		ft_putstr_fd("syntax error near unexpected token &\n", 2);
		return (0);
	}
	return (1);
}

void	free_token_list(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		if (tokens->str)
			free(tokens->str);
		free(tokens);
		tokens = tmp;
	}
}

void	tok_free_all(t_token **head)
{
	t_token	*p;
	t_token	*nxt;

	if (!head || !*head)
		return ;
	p = *head;
	while (p)
	{
		nxt = p->next;
		if (p->str)
			free(p->str);
		free(p);
		p = nxt;
	}
	*head = NULL;
}
