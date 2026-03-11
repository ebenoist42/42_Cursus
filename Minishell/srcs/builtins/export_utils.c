/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:44:17 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/29 10:33:29 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_export(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (current->value)
			printf("declare -x %s=\"%s\"\n", current->key, current->value);
		else
			printf("declare -x %s\n", current->key);
		current = current->next;
	}
}

int	is_valid_key(char *key)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!key || !ft_isalpha(key[0]))
		return (0);
	tmp = get_export_key(key);
	while (tmp[i])
	{
		if (!ft_isalnum(tmp[i]) && tmp[i] != '_')
			return (0);
		i++;
	}
	free(tmp);
	return (1);
}

char	*get_env_value(const char *key)
{
	t_env	*env;
	char	*value;

	env = _data()->env_list;
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			if (env->value)
			{
				value = ft_strdup(env->value);
				if (!value)
					error_malloc();
				return (value);
			}
			else
				return (NULL);
		}
		env = env->next;
	}
	return (NULL);
}

char	*get_export_key(char *argv)
{
	char	*key;
	int		i;

	i = 0;
	while (argv[i] && argv[i] != '=')
		i++;
	key = ft_substr(argv, 0, i);
	if (!key)
		error_malloc();
	return (key);
}

char	*get_value(char *argv)
{
	char	*value;
	int		i;

	i = 0;
	while (argv[i] && argv[i] != '=')
		i++;
	if (argv[i] == '=')
	{
		value = ft_substr(argv, i + 1, ft_strlen(argv) - i - 1);
		if (!value)
			error_malloc();
	}
	else
		value = NULL;
	return (value);
}
