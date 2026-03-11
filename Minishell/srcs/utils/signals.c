/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:36:58 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:20:59 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sigint_handler(int sig)
{
	(void)sig;
	_data()->exit_code = 130;
	g_signal_status = 130;
	if (write(1, "\n", 1) == -1)
		return ;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	close(0);
	open("/dev/stdin", O_RDONLY);
	g_signal_status = 133;
	_data()->exit_code = 133;
}

static void	child_sigquit_handler(int sig)
{
	(void)sig;
	last_free();
	g_signal_status = 131;
	exit(131);
}

static void	child_sigint_handler(int sig)
{
	(void)sig;
	last_free();
	g_signal_status = 130;
	exit(130);
}

/*
0 = Mode normal (shell principal)
1 = Mode heredoc (SIGINT uniquement)
2 = Mode processus enfant (SIGINT + SIGQUIT)
3 = Mode processus enfant dans pipe (signaux simples sans readline)
*/

void	signal_handler(int sig)
{
	if (sig == 0)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 1)
	{
		signal(SIGINT, heredoc_sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, heredoc_sigint_handler);
		signal(SIGQUIT, sigquit_handler);
	}
	if (sig == 3)
	{
		signal(SIGINT, child_sigint_handler);
		signal(SIGQUIT, child_sigquit_handler);
	}
	signal(SIGTSTP, SIG_IGN);
}
