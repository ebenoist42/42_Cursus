/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:47:52 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/09/01 12:06:43 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putcharpf_fd(s[i], fd);
		i++;
	}
}

int	ft_putstr_safe(int fd, char const *s)
{
	int	i;
	int	tmp;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		i++;
	tmp = write(fd, s, i);
	if (tmp < 0)
		return (-1);
	return (i);
}
