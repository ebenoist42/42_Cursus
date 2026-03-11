/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:40:32 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 16:05:12 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	fork_error(int ret, const char *msg, int *pipefd)
{
	perror(msg);
	if (pipefd)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	_data()->exit_code = 1;
	return (ret);
}

static void	pipe_left(int *pipefd, int in_fd, t_ast *ast)
{
	signal_handler(3);
	close(pipefd[0]);
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execute_recursive(ast->left, STDIN_FILENO, STDOUT_FILENO);
	last_free();
	exit(_data()->exit_code);
}

static void	pipe_right(int *pipefd, int out_fd, t_ast *ast)
{
	signal_handler(3);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	if (out_fd != STDOUT_FILENO)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	execute_recursive(ast->right, STDIN_FILENO, STDOUT_FILENO);
	last_free();
	exit(_data()->exit_code);
}

static int	wait_children(pid_t pid_left, pid_t pid_right)
{
	int	status_left;
	int	status_right;

	waitpid(pid_left, &status_left, 0);
	waitpid(pid_right, &status_right, 0);
	if (WIFSIGNALED(status_right) && WTERMSIG(status_right) == SIGQUIT)
	{
		if (write(2, "Quit: core dumped\n", 18) == -1)
			return (128 + WTERMSIG(status_right));
		return (128 + WTERMSIG(status_right));
	}
	if (WIFEXITED(status_right))
		return (WEXITSTATUS(status_right));
	else if (WIFSIGNALED(status_right))
		return (128 + WTERMSIG(status_right));
	return (1);
}

int	execute_pipe(t_ast *ast, int in_fd, int out_fd)
{
	int		pipefd[2];
	pid_t	pid_left;
	pid_t	pid_right;

	if (pipe(pipefd) < 0)
		return (pipe_error(-1, "pipe"));
	pid_left = fork();
	if (pid_left < 0)
		return (fork_error(-1, "fork", pipefd));
	if (pid_left == 0)
		pipe_left(pipefd, in_fd, ast);
	pid_right = fork();
	if (pid_right < 0)
		return (fork_error(-1, "fork", pipefd));
	if (pid_right == 0)
		pipe_right(pipefd, out_fd, ast);
	close(pipefd[0]);
	close(pipefd[1]);
	return (wait_children(pid_left, pid_right));
}
