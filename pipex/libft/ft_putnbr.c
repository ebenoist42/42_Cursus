/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:45:15 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/14 16:39:12 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_putchar ('-');
		i += ft_putchar ('2');
		i += ft_putnbr (147483648);
		return (11);
	}
	else if (nb < 0)
	{
		i += ft_putchar ('-');
		nb = -nb;
		i += ft_putnbr (nb);
	}
	else
	{
		if (nb >= 10)
			i += ft_putnbr(nb / 10);
		i += ft_putchar((nb % 10) + '0');
	}
	return (i);
}
