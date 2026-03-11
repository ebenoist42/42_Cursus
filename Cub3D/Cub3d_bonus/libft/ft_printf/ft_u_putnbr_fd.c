/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:54:13 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/14 11:54:08 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_u_putnbr_fd(unsigned int nb, int fd, char *base)
{
	unsigned int	taille;
	int				count;

	taille = 0;
	count = 0;
	while (base[taille])
		taille++;
	if (nb >= taille)
		count += ft_u_putnbr_fd(nb / taille, fd, base);
	count += ft_putcharpf_fd(base[nb % taille], fd);
	return (count);
}
/*
int	main(void)
{
	int x;
	x = ft_u_putnbr_fd(444, 1);
	printf("\nnb char: %d", x);
}*/
