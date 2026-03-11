/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:36 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/11 14:41:57 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	key_and_value_to_list(t_env *new_node, char **key_and_value)
{
	new_node->key = ft_strdup(key_and_value[0]);
	if (!new_node->key)
	{
		free(new_node);
		ft_free(key_and_value);
		error_malloc();
	}
	if (key_and_value[1])
	{
		new_node->value = ft_strdup(key_and_value[1]);
		if (!new_node->value)
		{
			free(new_node->key);
			free(new_node);
			ft_free(key_and_value);
			error_malloc();
		}
	}
	else
		new_node->value = NULL;
}

t_env	*env_to_list(char **envp)
{
	t_env	*env_list;
	t_env	*new_node;
	int		i;

	env_list = NULL;
	i = 0;
	while (envp[i])
	{
		new_node = env_to_node(envp[i]);
		if (new_node)
		{
			new_node->next = env_list;
			env_list = new_node;
		}
		i++;
	}
	return (env_list);
}

static t_env	*malloc_node(char **key_and_value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		error_malloc();
	key_and_value_to_list(new_node, key_and_value);
	new_node->next = NULL;
	return (new_node);
}

t_env	*env_to_node(char *env)
{
	t_env	*new_node;
	char	**key_and_value;

	key_and_value = ft_split(env, '=');
	if (!key_and_value || !key_and_value[0])
	{
		ft_free(key_and_value);
		return (NULL);
	}
	new_node = malloc_node(key_and_value);
	ft_free(key_and_value);
	return (new_node);
}
