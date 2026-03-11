/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:00:54 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/29 15:11:09 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_stdin_if_needed(int *saved_in, int *tmp)
{
	int	i;

	if (*saved_in != -1)
		return ;
	*saved_in = dup(STDIN_FILENO);
	i = 0;
	while (i < 1024 && tmp[i] != -1)
		i++;
	if (i < 1024)
		tmp[i] = *saved_in;
}

static int	redirect_heredoc_fd(int fd)
{
	if (fd < 0)
	{
		perror("heredoc chain");
		_data()->exit_code = 1;
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	if (fd != STDIN_FILENO)
		close(fd);
	return (0);
}

int	process_heredoc_chain(t_ast *node, int *saved_in, int *tmp)
{
	int	fd;

	save_stdin_if_needed(saved_in, tmp);
	fd = open_file_heredoc_chain(node, tmp);
	return (redirect_heredoc_fd(fd));
}

int	handle_redir_in(char *file, int *saved_in)
{
	int	fd;

	if (*saved_in == -1)
		*saved_in = dup(STDIN_FILENO);
	fd = open(file, O_RDONLY);
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

int	handle_redir_out(char *file, int *saved_out)
{
	int	fd;

	if (*saved_out == -1)
		*saved_out = dup(STDOUT_FILENO);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
