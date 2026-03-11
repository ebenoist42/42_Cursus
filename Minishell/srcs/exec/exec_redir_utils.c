/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:48:04 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/29 15:05:12 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	handle_append(char *file, int *saved_out)
{
	int	fd;

	if (*saved_out == -1)
		*saved_out = dup(STDOUT_FILENO);
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd >= 0)
	{
		dup2(fd, STDOUT_FILENO);
		if (should_close_fd(fd))
			close(fd);
		return (0);
	}
	else
	{
		perror(file);
		_data()->exit_code = 1;
		return (-1);
	}
}

static void	save_stdin_to_tmp(int *saved_in, int *tmp)
{
	int	i;

	*saved_in = dup(STDIN_FILENO);
	i = 0;
	while (i < 1024 && tmp[i] != -1)
		i++;
	if (i < 1024)
		tmp[i] = *saved_in;
}

static int	setup_heredoc_fd(char *file, int *tmp)
{
	int	fd;

	fd = open_file_heredoc(file, tmp);
	if (fd >= 0)
	{
		dup2(fd, STDIN_FILENO);
		if (should_close_fd(fd))
			close(fd);
		return (0);
	}
	else
	{
		perror(file);
		_data()->exit_code = 1;
		return (-1);
	}
}

static int	handle_heredoc(char *file, int *saved_in, int *tmp)
{
	if (*saved_in == -1)
		save_stdin_to_tmp(saved_in, tmp);
	return (setup_heredoc_fd(file, tmp));
}

int	apply_redirection(t_ast *node, int *saved_in, int *saved_out, int *tmp)
{
	char	*file;

	file = node->target;
	if (!file)
		return (0);
	if (node->type == N_REDIR_IN)
		return (handle_redir_in(file, saved_in));
	else if (node->type == N_REDIR_OUT)
		return (handle_redir_out(file, saved_out));
	else if (node->type == N_APPEND)
		return (handle_append(file, saved_out));
	else if (node->type == N_HEREDOC)
		return (handle_heredoc(file, saved_in, tmp));
	return (0);
}
