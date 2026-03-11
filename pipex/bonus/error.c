/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:13:29 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/06 13:11:18 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab_bonus(char **tab, t_pipe *pipex)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < pipex->nb_cmd)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_tab_tab(char ***tab, t_pipe *pipex)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < pipex->nb_cmd)
	{
		if (tab[i])
			ft_free_tab(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_close_pipe_bonus(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_pipe)
	{
		if (pipex->fd[i][0] != -1)
			close(pipex->fd[i][0]);
		if (pipex->fd[i][1] != -1)
			close(pipex->fd[i][1]);
		i++;
	}
	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
}

void	ft_end_programme_bonus(t_pipe *pipex)
{
	if (pipex->cmdi_arg)
		ft_free_tab_tab(pipex->cmdi_arg, pipex);
	if (pipex->cmdi_path)
		ft_free_tab_bonus(pipex->cmdi_path, pipex);
	if (pipex->fd)
		free(pipex->fd);
}
