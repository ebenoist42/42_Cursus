/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:21:02 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:16:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_priority(t_tokentype type)
{
	if (type == T_REDIR_IN || type == T_REDIR_OUT || type == T_APPEND
		|| type == T_HEREDOC)
		return (4);
	if (type == T_PIPE)
		return (3);
	return (0);
}

static int	read_operator(const char *s, int i, t_tokentype *type, int *len)
{
	if (strncmp(s + i, "<<", 2) == 0)
		return ((*type = T_HEREDOC), *len = 2, 1);
	if (strncmp(s + i, ">>", 2) == 0)
		return ((*type = T_APPEND), *len = 2, 1);
	if (s[i] == '|')
		return ((*type = T_PIPE), *len = 1, 1);
	if (s[i] == '<')
		return ((*type = T_REDIR_IN), *len = 1, 1);
	if (s[i] == '>')
		return ((*type = T_REDIR_OUT), *len = 1, 1);
	if (!operator_erreur(s, i))
		return ((*type = T_ERROR), *len = 1, -1);
	return (0);
}

char	*check_expand(char *str, int quote)
{
	int	i;

	i = 0;
	if (quote == 1)
		return (str);
	while (str[i])
	{
		if (str[i] == '$')
			return (replace_expand(str));
		i++;
	}
	return (str);
}

t_token	*tok_new(t_tokentype type)
{
	t_token	*n;
	char	*s;

	s = _data()->input;
	n = malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->type = type;
	n->str = NULL;
	n->quote = 0;
	if (type == T_ERROR)
		return (free(n), NULL);
	if (type == T_WORD)
	{
		n->str = strndup_token(s);
		if (!n->str)
			return (free(n), NULL);
	}
	n->priority = ms_priority(type);
	n->next = NULL;
	return (n);
}

t_token	*ft_creat_token_list(void)
{
	t_token		*a;
	t_token		*tmp;
	t_tokentype	type;
	int			len;

	tmp = NULL;
	a = NULL;
	_data()->i = 0;
	while (_data()->input[_data()->i])
	{
		if ((skip_space_break()) == 0)
			break ;
		len = 0;
		if (read_operator(_data()->input, _data()->i, &type, &len))
		{
			_data()->i += len;
			tmp = tok_new(type);
		}
		else
			tmp = tok_new(T_WORD);
		if (!tmp)
			return (tok_free_all(&a), NULL);
		tok_push_back(&a, tmp);
	}
	return (a);
}
