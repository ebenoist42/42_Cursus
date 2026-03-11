/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:05:47 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/29 15:19:20 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	strip_eol(char *s)
{
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	while (l > 0 && (s[l - 1] == '\n' || s[l - 1] == '\r'))
	{
		s[l - 1] = '\0';
		l--;
	}
}

void	close_tmp_fds(int *tmp)
{
	int	j;

	j = 0;
	while (j < 1024)
	{
		if (tmp[j] > 2)
			close(tmp[j]);
		j++;
	}
}

int	heredoc_parent(pid_t pid, int *p)
{
	int	status;

	close(p[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		close(p[0]);
		_data()->exit_code = WTERMSIG(status) + 128;
		if (g_signal_status != 0)
		{
			_data()->exit_code = g_signal_status;
			g_signal_status = 0;
		}
		return (-1);
	}
	return (p[0]);
}

void	print_eof_warning(const char *limiter)
{
	write(2,
		"\nminishell: warning: here-document delimited by end-of-file (wanted `",
		70);
	write(2, limiter, ft_strlen(limiter));
	write(2, "')\n", 3);
}

void	cleanup_and_exit(int *tmp, int write_fd)
{
	close(write_fd);
	last_free();
	close(_data()->fd[0]);
	close(_data()->fd[1]);
	close_tmp_fds(tmp);
	exit(0);
}
