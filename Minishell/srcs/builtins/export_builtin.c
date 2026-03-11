/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:07:32 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/25 14:07:32 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*find_env_node(t_env *env_list, char *key)
{
	t_env	*current;

	current = env_list;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	create_new_env_node(t_env **env_list, char *key, char *value)
{
	t_env	*new_node;

	new_node = env_to_node(key);
	if (!new_node)
		error_malloc();
	if (value)
	{
		new_node->value = ft_strdup(value);
		if (!new_node->value)
			error_malloc();
	}
	new_node->next = *env_list;
	*env_list = new_node;
}

static void	add_or_update_env(t_env **env_list, char *key, char *value)
{
	t_env	*existing_node;

	existing_node = find_env_node(*env_list, key);
	if (existing_node)
	{
		update_existing_env(existing_node, value);
		return ;
	}
	create_new_env_node(env_list, key, value);
}

static void	export_arg(char *argv)
{
	char	*key;
	char	*value;

	key = get_export_key(argv);
	value = get_value(argv);
	if (value == NULL)
		value = get_env_value(key);
	add_or_update_env(&(_data()->env_list), key, value);
	free(key);
	free(value);
	_data()->exit_code = 0;
}

void	export_builtin(t_ast *node)
{
	int	i;

	i = 1;
	if (node->argv[1] == NULL)
	{
		print_export(_data()->env_list);
		_data()->exit_code = 0;
		return ;
	}
	while (node->argv[i])
	{
		if (!is_valid_key(node->argv[i]))
		{
			ft_putstr_safe(2, "minishell: export: `");
			ft_putstr_safe(2, node->argv[i]);
			ft_putstr_safe(2, "': not a valid identifier\n");
			_data()->exit_code = 1;
		}
		else
			export_arg(node->argv[i]);
		i++;
	}
}
