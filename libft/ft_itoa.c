/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:57:43 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intsterlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*dest;	
	long int	nb;

	nb = n;
	len = ft_intsterlen(n);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[len] = 0 + '0';
	while (nb)
	{
		dest[len] = nb % 10 + '0';
		len --;
		nb = nb / 10;
	}
	return (dest);
}
/*
int main ()
{
	printf("%s" ,ft_itoa(-2147483648));
}*/