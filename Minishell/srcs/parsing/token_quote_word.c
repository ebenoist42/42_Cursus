/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:29:14 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/29 11:13:36 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
int	ft_check_quote_simple(char *str, int i)
{
	i++;
	while (str[i] != '\'' && str[i])
		i++;
	if (str[i] == '\'')
		return (1);
	return (-1);
}

int	ft_check_quote_double(char *str, int i)
{
	i++;
	while (str[i] != '\"' && str[i])
		i++;
	if (str[i] == '\"')
		return (2);
	return (-1);
}

int	ft_check_quote(char *str)
{
	int	quote;
	int	i;
	int	j;
	int	j;

	i = _data()->i;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (ft_check_quote_simple(str, i));
		if (str[i] == '\"')
			return (ft_check_quote_double(str, i));
		i++;
	}
	return (quote);
}*/
static int	parse_unquoted_segment(const char *s, int i, int *first_type,
		int seg_count)
{
	int	j;

	j = i;
	while (s[j] && !is_boundary(s[j]) && !ft_isspace(s[j]) && s[j] != '\''
		&& s[j] != '\"')
		j++;
	if (*first_type == -1)
		*first_type = 0;
	else if (seg_count > 0)
		*first_type = 0;
	return (j);
}

static int	parse_quoted_segment(const char *s, int i, int *first_type,
		int seg_count)
{
	int	j;
	int	type_seg;

	j = i + 1;
	type_seg = 0;
	while (s[j] && s[j] != s[i])
		j++;
	if (s[j] == s[i])
	{
		if (s[i] == '\'')
			type_seg = 1;
		else
			type_seg = 2;
		j++;
	}
	if (*first_type == -1)
		*first_type = type_seg;
	else if (seg_count > 0)
		*first_type = 0;
	return (j);
}

int	peek_token_quote(void)
{
	const char	*s;

	auto int i, seg_count, first_type;
	s = _data()->input;
	i = _data()->i;
	seg_count = 0;
	first_type = -1;
	if (!s || i < 0)
		return (0);
	while (s[i] && !is_boundary(s[i]) && !ft_isspace(s[i]))
	{
		if (s[i] == '\'' || s[i] == '\"')
			i = parse_quoted_segment(s, i, &first_type, seg_count);
		else
			i = parse_unquoted_segment(s, i, &first_type, seg_count);
		seg_count++;
		if (seg_count > 1 && first_type == 0)
			break ;
	}
	if (seg_count == 1 && first_type == 1)
		return (1);
	if (seg_count == 1 && first_type == 2)
		return (2);
	return (0);
}

int	ft_parsing_quote(char *input, int i)
{
	int	count;

	if (!input)
		return (1);
	count = 0;
	while (input[i])
	{
		while (input[i] && (input[i] == '\'' || input[i] == '\"'))
			i = passe_quote(input, i);
		if (!input[i])
			break ;
		if ((input[i] == '<' && input[i + 1] && input[i + 1] == '>')
			|| (input[i] == '>' && i > 0 && input[i - 1] == '|'))
			return (0);
		if ((input[i] == '>' && input[i + 1] && input[i + 1] == '<')
			|| ((input[i] == '<' || input[i] == '>') && input[i + 1] && input[i
					+ 1] == '|'))
			return (0);
		i++;
	}
	if ((count == 0) || (count > 0 && (count & 1) == 0))
		return (1);
	return (0);
}
