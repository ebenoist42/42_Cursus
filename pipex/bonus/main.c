/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:43:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/06 14:38:43 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd(t_pipe *pipex, int i)
{
	if (i > 0)
		close(pipex->fd[i - 1][0]);
	if (i < pipex->nb_pipe)
		close(pipex->fd[i][1]);
}

static void	child(t_pipe *pipex, int i, char **envp)
{
	if (i == 0)
		dup2(pipex->fd_in, STDIN_FILENO);
	else
		dup2(pipex->fd[i - 1][0], STDIN_FILENO);
	if (i == pipex->nb_cmd - 1)
	{
		if (pipex->fd_out == -1)
		{
			close_fd(pipex, i);
			close(pipex->fd_in);
			ft_end_programme_bonus(pipex);
			exit(1);
		}
		dup2(pipex->fd_out, STDOUT_FILENO);
	}
	else
		dup2(pipex->fd[i][1], STDOUT_FILENO);
	ft_close_pipe_bonus(pipex);
	if (!pipex->cmdi_arg[i] || !pipex->cmdi_arg[i][0] || !pipex->cmdi_path[i])
		ft_erreur127_bonus(pipex);
	execve(pipex->cmdi_path[i], pipex->cmdi_arg[i], envp);
	perror("Error\nChild Execve");
	ft_erreur127_bonus(pipex);
}

static int	wait_and_status(pid_t last_pid)
{
	int	status;

	status = 0;
	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	return (WEXITSTATUS(status));
}

static int	ft_exec(t_pipe *pipex, char **envp)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < pipex->nb_cmd)
	{
		pid = fork();
		if (pid == 0)
			child(pipex, i, envp);
		else if (pid < 0)
		{
			perror("Error\nPID");
			ft_end_programme_bonus(pipex);
			exit(127);
		}
		pipex->pid = pid;
		close_fd(pipex, i);
		i++;
	}
	return (wait_and_status(pipex->pid));
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;
	int		code;

	test_arg(ac);
	ft_init_pipex_bonus(ac, av, &pipex);
	ft_creat_path(ac, av, envp, &pipex);
	code = ft_exec(&pipex, envp);
	ft_close_pipe_bonus(&pipex);
	ft_end_programme_bonus(&pipex);
	return (code);
}
