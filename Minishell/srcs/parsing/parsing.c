/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:23:35 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:16:31 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_parsing_eof(char *input, int i)
{
	if (input[i] == '|')
		return (0);
	while (input[i])
		i++;
	if (input[i] == '\0' && i > 0)
		i--;
	if ((input[i] == '|') || input[i] == '<' || input[i] == '>')
		return (0);
	else
		return (1);
}

static char	*ft_skip_space(char *str)
{
	size_t	i;
	size_t	j;
	char	*input;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	input = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!input)
		return (NULL);
	while (str[i])
	{
		while (isspace((unsigned char)str[i]))
			i++;
		if (!str[i])
			break ;
		input[j++] = str[i++];
	}
	input[j] = '\0';
	return (input);
}

static char	*ft_parsing_close(char *str, int i)
{
	int	q;

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			q = str[i];
			i++;
			while (str[i] && str[i] != q)
				i++;
		}
		if (str[i] == '(' || str[i] == ';')
			return (NULL);
		if (str[i] == ')' || str[i] == '&')
			return (NULL);
		i++;
	}
	return (str);
}

static int	pre_parsing(char *str)
{
	int		i;
	int		r;
	char	*input;
	char	*line;
	char	c;

	r = 1;
	i = 0;
	c = 0;
	line = ft_strdup(str);
	input = ft_skip_space(str);
	if (!input || !line)
		return (0);
	if (!ft_quote_twins(input, i, c) || !ft_strlen(input)
		|| !ft_operateur(input, i) || !ft_parsing_quote(input, i)
		|| !double_operateur(input, i) || !ft_parsing_close(input, i)
		|| !ft_parsing_eof(input, i) || !check_redir_glue(line, i, 0,
			ft_strlen(line)))
		r = 0;
	free(input);
	free(line);
	if (r == 0)
		return (0);
	return (1);
}

int	parsing(char *str)
{
	char	*line;

	line = ft_skip_space(str);
	if (line[0] == '\0')
		return (free(line), 1);
	free(line);
	if (str[0] == '\0' || str[0] == ':')
		return (1);
	if (!pre_parsing(str))
		return (0);
	_data()->token = ft_creat_token_list();
	if (!_data()->token)
		return (0);
	_data()->ast = create_ast_node(_data()->token);
	tok_free_all(&_data()->token);
	return (1);
}
