/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:46:08 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 13:37:03 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			g_signal_status = 0;

static void	main_init(char **envp)
{
	_data()->env_list = env_to_list(envp);
	_data()->env_tab = env_to_array(_data()->env_list);
	signal_handler(0);
}

static void	free_loop(void)
{
	t_data	*data;

	data = _data();
	free(data->input);
	data->input = NULL;
	ft_free(data->env_tab);
	data->env_tab = env_to_array(data->env_list);
	free_ast(_data()->ast);
	_data()->ast = NULL;
}

static int	main_loop(void)
{
	_data()->input = readline("minishell$ ");
	if (!_data()->input)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		return (0);
	}
	if (_data()->input)
		add_history(_data()->input);
	if (!parsing(_data()->input))
	{
		ft_putstr_fd("syntax error \n", 2);
		_data()->exit_code = 2;
		free_loop();
		return (1);
	}
	execute_recursive(_data()->ast, STDIN_FILENO, STDOUT_FILENO);
	free_loop();
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)(ac);
	(void)(av);
	main_init(envp);
	while (1)
	{
		if (!main_loop())
			break ;
	}
	last_free();
	return (0);
}
