/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:37:13 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:20:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*_data(void)
{
	static t_data	data;
	static int		init = 0;

	if (init == 0)
	{
		init = 1;
		ft_bzero(&data, sizeof(t_data));
	}
	return (&data);
}

void	sigquit_handler(int sig)
{
	(void)sig;
	last_free();
	g_signal_status = 131;
	rl_on_new_line();
	if (write(1, "\n", 1) == -1)
		return ;
	rl_replace_line("", 0);
	rl_redisplay();
}
