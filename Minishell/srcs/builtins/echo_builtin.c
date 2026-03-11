/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:44:04 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 15:43:43 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_valid_opt(char *arg)
{
	int	i;

	i = 0;
	if (arg == NULL || arg[0] != '-')
		return (0);
	i++;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	skip_opt(char **args, int *newline)
{
	int	i;

	i = 1;
	*newline = 1;
	while (args[i] && is_valid_opt(args[i]))
	{
		*newline = 0;
		i++;
	}
	return (i);
}

void	echo_builtin(t_ast *node)
{
	int	i;
	int	newline;

	i = skip_opt(node->argv, &newline);
	while (node->argv[i])
	{
		ft_putstr_safe(1, node->argv[i]);
		if (node->argv[i + 1])
			ft_putchar_safe(1, ' ');
		i++;
	}
	if (newline)
		ft_putchar_safe(1, '\n');
	_data()->exit_code = 0;
}
