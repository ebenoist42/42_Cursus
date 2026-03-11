/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:38:01 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/12 10:48:44 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_lstsize_env(t_env *env_list)
{
	int	i;

	i = 0;
	while (env_list)
	{
		if (env_list->key && env_list->value)
			i++;
		env_list = env_list->next;
	}
	return (i);
}

static char	*array_line(t_env *env)
{
	char	*line;

	line = malloc(sizeof(char) * (ft_strlen(env->key) + ft_strlen(env->value))
			+ 2);
	if (!line)
		error_malloc();
	ft_strcpy(line, env->key);
	ft_strcat(line, "=");
	ft_strcat(line, env->value);
	return (line);
}

char	**env_to_array(t_env *env_list)
{
	char	**array;
	int		size;
	int		i;

	size = ft_lstsize_env(env_list);
	array = malloc(sizeof * array * (size + 1));
	if (!array)
		error_malloc();
	i = 0;
	while (env_list)
	{
		if (env_list->key && env_list->value)
		{
			array[i] = array_line(env_list);
			if (!array[i])
			{
				ft_free(array);
				error_malloc();
			}
			i++;
		}
		env_list = env_list->next;
	}
	array[i] = NULL;
	return (array);
}
