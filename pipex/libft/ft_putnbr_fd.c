/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:50:40 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/08 13:59:05 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd ('-', fd);
		ft_putchar_fd ('2', fd);
		ft_putnbr_fd (147483648, fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		nb = -nb;
		ft_putnbr_fd (nb, fd);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd (nb % 10 + '0', fd);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
