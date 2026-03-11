/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:40:55 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/11 14:41:20 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_key(char **str, char *temp)
{
	*str = (char *)(temp + 1);
	while (ft_isalnum(**str) || **str == '_')
		(*str)++;
	if (*str == temp + 1)
		return (NULL);
	return (ft_substr(temp + 1, 0, *str - (temp + 1)));
}

static char	*special_case(char *result, char **str, char *temp, char *key)
{
	if (temp[1] == '?')
	{
		free(key);
		result = ft_strjoin_free(result, ft_itoa(_data()->exit_code), 1, 1);
		if (!result)
			error_malloc();
		*str = temp + 2;
		return (result);
	}
	else if (!key)
	{
		result = ft_strjoin_free(result, ft_strdup("$"), 1, 1);
		if (!result)
			error_malloc();
		*str = temp + 1;
		return (result);
	}
	return (NULL);
}

static char	*replace_var(char *result, char **str, char *temp)
{
	char	*env_value;
	char	*end_var;
	char	*key;
	char	*special_result;

	key = get_key(&end_var, temp);
	special_result = special_case(result, str, temp, key);
	if (special_result)
		return (special_result);
	env_value = get_env_value(key);
	free(key);
	if (env_value)
	{
		result = ft_strjoin_free(result, env_value, 1, 1);
		if (!result)
			error_malloc();
	}
	*str = end_var;
	return (result);
}

static char	*expand_in_str(char *result, char **str)
{
	char	*temp;

	temp = ft_strchr(*str, '$');
	while (temp)
	{
		result = ft_strjoin_free(result, ft_substr(*str, 0, temp - *str), 1, 1);
		if (!result)
			error_malloc();
		result = replace_var(result, str, temp);
		temp = ft_strchr(*str, '$');
	}
	return (result);
}

char	*replace_expand(char *str)
{
	char	*result;
	char	*temp;

	temp = str;
	result = ft_strdup("");
	if (!result)
		error_malloc();
	result = expand_in_str(result, &str);
	result = ft_strjoin_free(result, str, 1, 0);
	if (!result)
		error_malloc();
	free(temp);
	return (result);
}
