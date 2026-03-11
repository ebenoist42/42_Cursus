/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:01:21 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/14 16:48:00 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(unsigned long long nb, char *base)
{
	int	i;

	i = 0;
	if (nb > 0 && nb < 16)
	{
		ft_putchar(base[nb % 16]);
		i++;
	}
	else
	{
		if (nb >= 16)
			i += ft_putnbr_hexa(nb / 16, base);
		i += ft_putchar(base[nb % 16]);
	}
	return (i);
}
