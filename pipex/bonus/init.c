/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:08:01 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/06 13:24:54 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipes(t_pipe *pipex)
{
	int	i;

	pipex->nb_pipe = pipex->nb_cmd - 1;
	if (pipex->nb_pipe < 1)
		return ;
	pipex->fd = malloc(sizeof(int [2]) * pipex->nb_pipe);
	if (!pipex->fd)
	{
		perror("Error\n Malloc Pipe");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < pipex->nb_pipe)
	{
		if (pipe(pipex->fd[i]) == -1)
			perror("Error\nPipe");
		i++;
	}
}

void	ft_init_pipex_bonus(int ac, char **av, t_pipe *pipex)
{
	pipex->nb_cmd = ac - 3;
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		pipex->here_doc = 1;
		pipex->nb_cmd = ac - 4;
		pipex->fd_in = her_doc_fd(av[2]);
		pipex->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->fd_out == -1)
			perror(av[ac - 1]);
	}
	else
	{
		pipex->fd_in = open(av[1], O_RDONLY);
		if (pipex->fd_in == -1)
		{
			perror("Error\nOpen File");
			pipex->fd_in = open("/dev/null", O_RDONLY);
		}
		pipex->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->fd_out == -1)
			perror(av[ac - 1]);
		pipex->here_doc = 0;
	}
	init_pipes(pipex);
	creat_pipe(pipex);
}

static void	clear_cmd(t_pipe *pipex, size_t i)
{
	ft_free_tab(pipex->cmdi_arg[i]);
	pipex->cmdi_arg[i] = NULL;
	pipex->cmdi_path[i] = NULL;
}

void	ft_creat_path(int ac, char **av, char **envp, t_pipe *pipex)
{
	size_t	i;
	size_t	offset;

	if (pipex->here_doc)
		offset = 3;
	else
		offset = 2;
	i = offset - 1;
	while (++i < (size_t)ac - 1)
	{
		pipex->cmdi_arg[i - offset] = ft_split(av[i], ' ');
		if (!pipex->cmdi_arg[i - offset] || !pipex->cmdi_arg[i - offset][0]
			|| pipex->cmdi_arg[i - offset][0][0] == '\0')
			clear_cmd(pipex, i - offset);
		else
		{
			pipex->cmdi_path[i - offset] = ft_management_arg(&av[i][0], envp);
			if (!pipex->cmdi_path[i - offset] || access(pipex->cmdi_path[i
						- offset], X_OK) != 0)
			{
				free(pipex->cmdi_path[i - offset]);
				pipex->cmdi_path[i - offset] = NULL;
			}
		}
	}
}

void	ft_erreur127_bonus(t_pipe *pipex)
{
	int	i;

	if (pipex->cmdi_arg)
		ft_free_tab_tab(pipex->cmdi_arg, pipex);
	if (pipex->cmdi_path)
		ft_free_tab_bonus(pipex->cmdi_path, pipex);
	i = 0;
	while (i < pipex->nb_pipe)
	{
		if (pipex->fd[i][0] != -1)
			close(pipex->fd[i][0]);
		if (pipex->fd[i][1])
			close(pipex->fd[i][1]);
		i++;
	}
	if (pipex->fd)
		free(pipex->fd);
	exit(127);
}
