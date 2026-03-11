/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:20:26 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 11:41:30 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_cmd(char **env_split, char *cmd)
{
	char	*env_join;
	char	*cmd_exec;
	int		i;

	i = 0;
	while (env_split[i])
	{
		env_join = ft_strjoin(env_split[i], "/");
		if (!env_join)
			return (NULL);
		cmd_exec = ft_strjoin(env_join, cmd);
		free(env_join);
		if (!cmd_exec)
			return (NULL);
		if (access(cmd_exec, X_OK) == 0)
			return (cmd_exec);
		free(cmd_exec);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd)
{
	char	**env_split;
	char	*cmd_exec;
	char	*getenv;
	t_data	*data;

	data = _data();
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	getenv = get_env("PATH=", data->env_tab);
	if (!getenv)
		return (NULL);
	env_split = ft_split(getenv, ':');
	if (!env_split)
		return (NULL);
	cmd_exec = get_cmd(env_split, cmd);
	ft_free(env_split);
	return (cmd_exec);
}
