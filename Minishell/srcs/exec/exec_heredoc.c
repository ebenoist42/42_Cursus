/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:53:30 by ebenoist          #+#    #+#             */
/*   Updated: 2025/09/29 15:18:42 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc_child(const char *limiter, int *tmp, int *p)
{
	char	*line;

	signal_handler(1);
	close(p[0]);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line || !ft_strcmp(line, limiter))
		{
			if (!line)
				print_eof_warning(limiter);
			free(line);
			break ;
		}
		write(p[1], line, ft_strlen(line));
		write(p[1], "\n", 1);
		free(line);
	}
	cleanup_and_exit(tmp, p[1]);
}

int	get_heredoc_fd(const char *limiter, int *tmp)
{
	int		p[2];
	pid_t	pid;

	if (pipe(p) < 0)
		return (-1);
	pid = fork();
	if (pid == 0)
		heredoc_child(limiter, tmp, p);
	else
		return (heredoc_parent(pid, p));
	return (-1);
}

static void	collect_all_heredocs(t_ast *node, char **eof_list, int *count,
		int max_count)
{
	if (!node || *count >= max_count)
		return ;
	if (node->left)
		collect_all_heredocs(node->left, eof_list, count, max_count);
	if (node->type == N_HEREDOC && node->target)
	{
		eof_list[*count] = node->target;
		(*count)++;
	}
}

int	open_file_heredoc_chain(t_ast *heredoc_root, int *tmp)
{
	int		count;
	char	*eof_list[10];
	int		last_fd;
	int		i;

	count = 0;
	collect_all_heredocs(heredoc_root, eof_list, &count, 10);
	last_fd = -1;
	i = 0;
	while (i < count)
	{
		if (last_fd != -1)
			close(last_fd);
		last_fd = get_heredoc_fd(eof_list[i], tmp);
		if (last_fd == -1)
			return (-1);
		i++;
	}
	return (last_fd);
}

int	open_file_heredoc(char *eof, int *tmp)
{
	return (get_heredoc_fd(eof, tmp));
}
