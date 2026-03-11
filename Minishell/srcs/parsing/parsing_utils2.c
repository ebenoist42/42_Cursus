/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:11:43 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/02 10:37:23 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	passe_quote(char *str, int i)
{
	char	q;
	int		j;

	if (!str || !str[i])
		return (i);
	q = str[i];
	i++;
	j = i;
	while (str[j] && str[j] != q)
		j++;
	if (str[j] == q)
		return (j + 1);
	return (j);
}

int	check_redir_glue(char *str, int i, int count, int len)
{
	while (str && str[i] && i < len)
	{
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i = passe_quote(str, i);
		count = 0;
		if (str[i] == '<' || str[i] == '>')
		{
			i++;
			count = 1;
			if (str[i] && str[i + 1] && ((str[i] == '<' && str[i + 1] == '<')
					|| (str[i] == '>' && str[i + 1] == '>')))
				i++;
			if (str[i])
				i++;
			while (str[i] && ft_isspace(str[i]))
				i++;
			if (str[i] && (str[i] == '<' || str[i] == '>'))
				count = 2;
			if (count == 2)
				return (0);
		}
		else if (str[i])
			i++;
	}
	return (1);
}

int	skip_space_break(void)
{
	while (ft_isspace(_data()->input[_data()->i]))
		_data()->i++;
	if (!_data()->input[_data()->i])
		return (0);
	return (1);
}

int	append_buf(char **dst, size_t *dlen, const char *src, size_t len)
{
	char	*n;
	size_t	newlen;

	newlen = *dlen + len;
	n = realloc(*dst, newlen + 1);
	if (!n)
		return (0);
	memcpy(n + *dlen, src, len);
	n[newlen] = '\0';
	*dst = n;
	*dlen = newlen;
	return (1);
}
