/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:37:59 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/04 10:45:06 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	if (!av || av[0] == '\0')
		return (NULL);
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

void	test_arg(int ac)
{
	if (ac < 5)
	{
		ft_printf("Error\nWrong number argument\n");
		exit(1);
	}
}
