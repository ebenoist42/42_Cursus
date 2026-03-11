/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:20:41 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/11 14:20:47 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env(char *path, char **envp)
{
	int	i;
	int	len;

	len = ft_strlen(path);
	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], path, len) == 0)
			return (envp[i] + len);
		i++;
	}
	return (NULL);
}
