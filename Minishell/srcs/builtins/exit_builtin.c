/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:44:13 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:09:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_exit_arg(char *arg)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;
	if ((arg[0] == '-' || arg[0] == '+') && arg[1] != '\0')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			write(2, "minishell: exit: numeric argument required\n", 44);
			last_free();
			exit(exit_code);
		}
		i++;
	}
	return (ft_atoi(arg));
}

void	exit_builtin(t_ast *node)
{
	printf("exit\n");
	if (node->argv[1] == NULL)
	{
		last_free();
		exit(_data()->exit_code);
	}
	else
		_data()->exit_code = check_exit_arg(node->argv[1]);
	if (node->argv[1] && node->argv[1][0] == '\0')
	{
		_data()->exit_code = 2;
		write(2, "minishell: exit: numeric argument required\n", 44);
		last_free();
		exit(_data()->exit_code);
	}
	if (node->argv[2])
	{
		write(2, "minishell: exit: too many arguments\n", 37);
		_data()->exit_code = 1;
		return ;
	}
	last_free();
	exit(_data()->exit_code);
}
