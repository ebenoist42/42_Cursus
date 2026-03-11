/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:06:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/30 14:48:29 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/wait.h>

static void	ft_creat_arg_2(char **av, char **envp, t_pipe *pipex)
{
	pipex->cmd2_arg = ft_split(av[3], ' ');
	if (!pipex->cmd2_arg || !pipex->cmd2_arg[0])
		pipex->cmd2_path = NULL;
	else
	{
		pipex->cmd2_path = ft_management_arg(av[3], envp);
		if (!pipex->cmd2_path || access(pipex->cmd2_path, X_OK) != 0)
		{
			free(pipex->cmd2_path);
			pipex->cmd2_path = NULL;
		}
	}
	if (pipe(pipex->pipe) == -1)
		perror("Error\nPipe.Fd");
}

static void	ft_creat_arg_1(char **av, char **envp, t_pipe *pipex)
{
	pipex->cmd1_arg = ft_split(av[2], ' ');
	if (!pipex->cmd1_arg || !pipex->cmd1_arg[0])
		pipex->cmd1_path = NULL;
	else
	{
		pipex->cmd1_path = ft_management_arg(av[2], envp);
		if (!pipex->cmd1_path || access(pipex->cmd1_path, X_OK) != 0)
		{
			free(pipex->cmd1_path);
			pipex->cmd1_path = NULL;
		}
	}
	ft_creat_arg_2(av, envp, pipex);
}

static void	ft_child_1(char **av, char **envp, t_pipe pipex)
{
	pipex.fd_in = open(av[1], O_RDONLY);
	if (pipex.fd_in < 0)
	{
		perror("Error\nInfile.txt");
		ft_close_pipe_waitpid(0, 0, pipex, 0);
		ft_end_programme(&pipex);
		exit(1);
	}
	dup2(pipex.fd_in, STDIN_FILENO);
	dup2(pipex.pipe[1], STDOUT_FILENO);
	ft_close_pipe_waitpid(0, 0, pipex, 0);
	close(pipex.fd_in);
	if (!pipex.cmd1_arg || !pipex.cmd1_arg[0] || !pipex.cmd1_path)
		ft_erreur127(&pipex);
	execve(pipex.cmd1_path, pipex.cmd1_arg, envp);
	perror("execve cmd1 failed");
	ft_erreur127(&pipex);
}

static void	ft_child_2(char **av, char **envp, t_pipe pipex)
{
	pipex.fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd_out < 0)
	{
		perror("Error\nOutfile");
		ft_close_pipe_waitpid(0, 0, pipex, 0);
		ft_end_programme(&pipex);
		exit(1);
	}
	dup2(pipex.pipe[0], STDIN_FILENO);
	dup2(pipex.fd_out, STDOUT_FILENO);
	ft_close_pipe_waitpid(0, 0, pipex, 0);
	close(pipex.fd_out);
	if (!pipex.cmd2_arg || !pipex.cmd2_arg[0] || !pipex.cmd2_path)
		ft_erreur127(&pipex);
	execve(pipex.cmd2_path, pipex.cmd2_arg, envp);
	perror("execve cmd2 failed");
	ft_erreur127(&pipex);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;
	pid_t	pid1;
	pid_t	pid2;

	ft_init_pipex(&pipex);
	ft_test_arg(ac);
	ft_creat_arg_1(av, envp, &pipex);
	pid1 = fork();
	if (pid1 == -1)
		perror("Error\nfork1");
	if (pid1 == 0)
		ft_child_1(av, envp, pipex);
	pid2 = fork();
	if (pid2 == -1)
		perror("Error\nfork2");
	if (pid2 == 0)
		ft_child_2(av, envp, pipex);
	pipex.sortie = ft_close_pipe_waitpid(pid1, pid2, pipex, 1);
	ft_end_programme(&pipex);
	return (pipex.sortie);
}
