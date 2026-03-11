/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:20:51 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/29 15:04:27 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_management_arg(char *av, char **envp)
{
	char	**cmd1;
	char	*cmd2;
	char	*path;

	cmd1 = ft_split(av, ' ');
	if (!cmd1)
		return (NULL);
	if (access(cmd1[0], X_OK) == 0)
		cmd2 = ft_strdup(cmd1[0]);
	else
	{
		path = ft_get_path(envp);
		cmd2 = find_path(cmd1[0], path);
		if (!cmd2)
			cmd2 = find_path(cmd1[0], "/usr/bin:/bin");
	}
	ft_free_tab(cmd1);
	return (cmd2);
}

char	*find_path_2(char *cmd, char *paths)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(paths, "/");
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	else
	{
		free(full_path);
		return (NULL);
	}
}

char	*find_path(char *cmd, char *envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	if (!envp)
		return (NULL);
	i = 0;
	paths = ft_split(envp, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = find_path_2(cmd, paths[i]);
		if (full_path != NULL)
		{
			ft_free_tab(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (ft_free_tab(paths), NULL);
}
