/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:43:52 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 15:43:43 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_path_cd(t_ast *node)
{
	char	*path;

	if (node->argv[1] && node->argv[2])
	{
		ft_putstr_safe(2, "cd : too many arguments\n");
		return (NULL);
	}
	else if (node->argv[1] == NULL)
	{
		path = getenv("HOME");
		if (!path)
		{
			ft_putstr_safe(2, "cd : HOME not set\n");
			return (NULL);
		}
		return (path);
	}
	path = node->argv[1];
	return (path);
}

void	cd_builtin(t_ast *node)
{
	char	*cd;
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		perror("cd");
		_data()->exit_code = 1;
		return ;
	}
	cd = get_path_cd(node);
	if (!cd)
	{
		free(oldpwd);
		_data()->exit_code = 1;
		return ;
	}
	apply_path(cd, oldpwd);
}
