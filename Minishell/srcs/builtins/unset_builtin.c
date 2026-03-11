/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:44:27 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 15:43:43 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	delete_key(char *args)
{
	t_env	*current;
	t_env	*prev;

	current = _data()->env_list;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, args) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				_data()->env_list = current->next;
			free(current->key);
			if (current->value)
				free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	unset_builtin(t_ast *node)
{
	int	i;

	i = 1;
	if (node->argv == NULL)
	{
		_data()->exit_code = 0;
		return ;
	}
	while (node->argv[i])
	{
		delete_key(node->argv[i]);
		ft_free(_data()->env_tab);
		_data()->env_tab = env_to_array(_data()->env_list);
		i++;
	}
	_data()->exit_code = 0;
}
