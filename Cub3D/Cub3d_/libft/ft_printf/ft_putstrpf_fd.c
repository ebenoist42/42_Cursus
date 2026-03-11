/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:47:52 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/14 12:12:13 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstrpf_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstrpf_fd("(null)", 1));
	while (s[i])
	{
		ft_putcharpf_fd(s[i], fd);
		i++;
	}
	return (i);
}
