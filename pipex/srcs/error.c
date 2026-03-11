/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:07:45 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/29 10:27:01 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/wait.h>

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_end_programme(t_pipe *pipex)
{
	if (pipex->cmd1_arg)
		ft_free_tab(pipex->cmd1_arg);
	if (pipex->cmd2_arg)
		ft_free_tab(pipex->cmd2_arg);
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
}

int	ft_close_pipe_waitpid(pid_t pid1, pid_t pid2, t_pipe pipex, int i)
{
	int	st2;
	int	code;

	st2 = 0;
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	if (i > 0)
	{
		if (pid1 > 0)
			waitpid(pid1, NULL, 0);
		if (pid2 > 0)
			waitpid(pid2, &st2, 0);
	}
	code = WEXITSTATUS(st2);
	return (code);
}

void	ft_erreur127(t_pipe *pipex)
{
	ft_end_programme(pipex);
	exit(127);
}
