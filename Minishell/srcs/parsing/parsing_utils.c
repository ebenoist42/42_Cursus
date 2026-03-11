/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:28:02 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:40:14 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_quote_twins(char *str, int i, char q)
{
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			q = str[i];
			i++;
			if (!str[i])
				return (0);
			while (str[i])
			{
				if (str[i] == q)
				{
					q = 0;
					break ;
				}
				i++;
			}
		}
		if (str[i])
			i++;
	}
	if (q == 0)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	double_operateur(char *str, int i)
{
	if (!str)
		return (1);
	while (str[i])
	{
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i = passe_quote(str, i);
		if (!str[i])
			break ;
		if (str[i] == '|' && str[i + 1] && str[i + 1] == '|')
			return (0);
		if (str[i] == '<' && str[i + 1] && str[i + 2] && str[i + 1] == '<'
			&& str[i + 2] == '<')
			return (0);
		if (str[i] == '>' && str[i + 1] && str[i + 2] && str[i + 1] == '>'
			&& str[i + 2] == '>')
			return (0);
		i++;
	}
	return (1);
}

int	ft_operateur(char *str, int i)
{
	char	c;
	char	n;

	if (!str)
		return (1);
	while (str[i])
	{
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i = passe_quote(str, i);
		if (!str[i])
			break ;
		c = str[i];
		if ((c == '|' || c == '&' || c == '<' || c == '>') && str[i + 1])
		{
			n = str[i + 1];
			if ((n == '|' || n == '&' || n == '<' || n == '>') && c != n)
				return (0);
		}
		i++;
	}
	return (1);
}
