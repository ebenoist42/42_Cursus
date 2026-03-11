/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:31:51 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/06 13:24:42 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	her_doc_fd(char *limiter)
{
	char	*line;
	int		pipefd[2];
	size_t	len;

	if (pipe(pipefd) == -1)
	{
		perror("Error\nPipe, here_doc\n");
		return (-1);
	}
	len = ft_strlen(limiter);
	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (!strncmp(line, limiter, len) && line[len] == '\n')
			return (free(line), close(pipefd[1]), pipefd[0]);
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

void	creat_pipe(t_pipe *pipex)
{
	pipex->cmdi_arg = calloc(pipex->nb_cmd, sizeof(char **));
	pipex->cmdi_path = calloc(pipex->nb_cmd + 1, sizeof(char *));
	if (!pipex->cmdi_arg || !pipex->cmdi_path)
		perror("malloc pipex");
}
