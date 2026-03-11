/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:06:11 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/29 14:28:15 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atoi(const char *s)
{
	size_t	i;
	long	res;
	long	sign;

	sign = 1;
	i = 0;
	res = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
				i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (sign * res);
}
/*
int	main(void)
{
	char str[19] = "     -123456";
	int	i = ft_atoi(str);
	printf("%d", i);
}*/
