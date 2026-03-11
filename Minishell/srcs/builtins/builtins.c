/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:43:46 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 15:43:43 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	if (ft_strcmp(str, "pwd") == 0)
		return (1);
	if (ft_strcmp(str, "env") == 0)
		return (1);
	if (ft_strcmp(str, "export") == 0)
		return (1);
	if (ft_strcmp(str, "unset") == 0)
		return (1);
	return (0);
}

int	exec_builtins(t_ast *node)
{
	if (ft_strcmp(node->argv[0], "env") == 0)
	{
		_data()->exit_code = env_builtin();
		return (_data()->exit_code);
	}
	else if (ft_strcmp(node->argv[0], "exit") == 0)
		return (exit_builtin(node), _data()->exit_code);
	else if (ft_strcmp(node->argv[0], "pwd") == 0)
	{
		_data()->exit_code = pwd_builtin();
		return (_data()->exit_code);
	}
	else if (ft_strcmp(node->argv[0], "cd") == 0)
		return (cd_builtin(node), _data()->exit_code);
	else if (ft_strcmp(node->argv[0], "unset") == 0)
		return (unset_builtin(node), _data()->exit_code);
	else if (ft_strcmp(node->argv[0], "export") == 0)
		return (export_builtin(node), _data()->exit_code);
	else if (ft_strcmp(node->argv[0], "echo") == 0)
		return (echo_builtin(node), _data()->exit_code);
	return (0);
}
