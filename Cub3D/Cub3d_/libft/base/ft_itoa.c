/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:50:59 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/06 10:05:31 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		i;
	long	a;

	a = n;
	i = ft_len(a);
	if (a == 0)
		return (ft_strdup("0"));
	itoa = malloc(sizeof(char) * (i + 1));
	if (!itoa)
		return (NULL);
	itoa[i] = '\0';
	if (a < 0)
	{
		a = a * -1;
		itoa[0] = '-';
	}
	while (a > 0)
	{
		itoa[--i] = (a % 10) + '0' ;
		a = a / 10;
	}
	return (itoa);
}
/*
int	main(void)
{
	int n = 2147483647;
	char *str;
	str = ft_itoa(n);
	printf("%s", str);
}*/
