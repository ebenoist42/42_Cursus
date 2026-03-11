/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:02:31 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 16:05:12 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	setup_file_descriptors(int fd_in, int fd_out)
{
	if (fd_in != STDIN_FILENO)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != STDOUT_FILENO)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

static int	exec_builtin_cmd(t_ast *ast, int fd_in, int fd_out)
{
	setup_file_descriptors(fd_in, fd_out);
	return (exec_builtins(ast));
}

static int	exec_external_cmd(t_ast *ast, int fd_in, int fd_out)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		signal_handler(3);
		setup_file_descriptors(fd_in, fd_out);
		close_redirect_fds_in_child();
		exec(ast, _data()->env_tab);
		perror("execve");
		exit(126);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		if (write(2, "Quit: core dumped\n", 18) == -1)
			return (128 + WTERMSIG(status));
		return (128 + WTERMSIG(status));
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

int	exec_simple_cmd(t_ast *ast, int fd_in, int fd_out)
{
	struct stat	st;

	if (!ast || !ast->argv || !ast->argv[0])
		return (1);
	if (stat(ast->argv[0], &st) == 0 && S_ISDIR(st.st_mode))
	{
		write(2, "minishell: is a directory\n", 27);
		_data()->exit_code = 126;
		return (_data()->exit_code);
	}
	if (is_builtin(ast->argv[0]))
		return (exec_builtin_cmd(ast, fd_in, fd_out));
	return (exec_external_cmd(ast, fd_in, fd_out));
}

void	execute_recursive(t_ast *ast, int fd_in, int fd_out)
{
	t_data	*data;

	data = _data();
	if (!ast)
	{
		data->exit_code = 0;
		return ;
	}
	if (ast->type == N_CMD)
		data->exit_code = exec_simple_cmd(ast, fd_in, fd_out);
	else if (ast->type == N_PIPE)
		data->exit_code = execute_pipe(ast, fd_in, fd_out);
	else if (ast->type == N_REDIR_IN || ast->type == N_REDIR_OUT
		|| ast->type == N_APPEND || ast->type == N_HEREDOC)
		data->exit_code = execute_redirect(ast);
	else
		printf("Type non géré: %d\n", ast->type);
	return ;
}
