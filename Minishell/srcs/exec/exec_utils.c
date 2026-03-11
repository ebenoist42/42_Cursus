/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/25 11:41:08 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 11:41:08 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec(t_ast *ast, char **envp)
{
	char	*path;

	path = get_path(ast->argv[0]);
	if (!path)
	{
		perror("Error\nCommand not found\n");
		last_free();
		exit(127);
	}
	execve(path, ast->argv, envp);
	perror("error command ");
	free(path);
	last_free();
	exit(127);
}

void	close_redirect_fds_in_child(void)
{
	int	fd;

	fd = 3;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

bool	is_redirection(t_ast *node)
{
	return (node->type == N_REDIR_IN || node->type == N_REDIR_OUT
		|| node->type == N_APPEND || node->type == N_HEREDOC);
}

char	*get_filename(t_ast *node)
{
	if (!node)
		return (NULL);
	if (node->target)
		return (node->target);
	if (node->type == N_CMD && node->argv && node->argv[0])
		return (node->argv[0]);
	return (get_filename(node->right));
}

bool	should_close_fd(int fd)
{
	return (fd >= 0 && fd != STDIN_FILENO && fd != STDOUT_FILENO
		&& fd != STDERR_FILENO);
}
