/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:35:14 by ebenoist          #+#    #+#             */
/*   Updated: 2025/09/29 10:33:29 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_existing_env(t_env *current, char *value)
{
	free(current->value);
	if (value)
	{
		current->value = ft_strdup(value);
		if (!current->value)
			error_malloc();
	}
	else
		current->value = NULL;
}
