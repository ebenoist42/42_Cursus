/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:25:03 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/30 14:47:13 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_test_arg(int ac)
{
	if (ac != 5)
	{
		ft_printf("Error\nWrong number argument\n");
		exit(1);
	}
}

void	ft_init_pipex(t_pipe *pipex)
{
	pipex->pipe[0] = -1;
	pipex->pipe[1] = -1;
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->cmd1_arg = NULL;
	pipex->cmd2_arg = NULL;
	pipex->cmd1_path = NULL;
	pipex->cmd2_path = NULL;
}
