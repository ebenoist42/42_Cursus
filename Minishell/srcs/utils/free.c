/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:36:48 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 13:43:42 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_env_list(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		if (env->value)
			free(env->value);
		free(env);
		env = tmp;
	}
}

void	last_free(void)
{
	if (_data()->prompt)
	{
		free(_data()->prompt);
		_data()->prompt = NULL;
	}
	if (_data()->env_tab)
	{
		ft_free(_data()->env_tab);
		_data()->env_tab = NULL;
	}
	if (_data()->env_list)
	{
		free_env_list(_data()->env_list);
		_data()->env_list = NULL;
	}
	if (_data()->ast)
	{
		free_ast(_data()->ast);
		_data()->ast = NULL;
	}
	rl_clear_history();
}
