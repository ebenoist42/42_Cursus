/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:43:58 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/12 13:23:28 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	update_bis(char *oldpwd)
{
	t_env	*update;

	update = malloc(sizeof(t_env));
	if (!update)
		error_malloc();
	update->key = ft_strdup("OLDPWD");
	if (!update->key)
		error_malloc();
	update->value = ft_strdup(oldpwd);
	if (!update->value)
	{
		free(update->key);
		error_malloc();
	}
	update->next = _data()->env_list;
	_data()->env_list = update;
}

static void	update_pwd(char *oldpwd)
{
	t_env	*env;

	env = _data()->env_list;
	while (env)
	{
		if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			free(env->value);
			env->value = ft_strdup(oldpwd);
			if (!env->value)
				error_malloc();
			return ;
		}
		env = env->next;
	}
	if (!env)
		update_bis(oldpwd);
}

char	apply_path(char *cd, char *oldpwd)
{
	if (chdir(cd) != 0)
	{
		perror("cd");
		_data()->exit_code = 1;
		free(oldpwd);
		return (1);
	}
	update_pwd(oldpwd);
	free(oldpwd);
	_data()->exit_code = 0;
	return (0);
}
