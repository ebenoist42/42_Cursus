/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:54:13 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/14 11:06:07 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbrpf_fd(int nb, int fd, char *base)
{
	int		count;
	long	n;
	long	taille;

	count = 0;
	taille = 0;
	n = nb;
	while (base[taille])
		taille++;
	if (n < 0)
	{
		count += ft_putcharpf_fd('-', fd);
		n = n * -1;
	}
	if (n >= taille)
		count += ft_putnbrpf_fd(n / taille, fd, base);
	count += ft_putcharpf_fd(base[n % taille], fd);
	return (count);
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1, "0123456789abcdef");
	ft_putnbr_fd(-1,1, "0123456789abcdef");
	ft_putnbr_fd(0,1, "0123456789abcdef");
}*/
