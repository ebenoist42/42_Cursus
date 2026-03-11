/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:11:36 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/14 16:47:33 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_hex(unsigned long long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
		count += ft_putnbr_hex(n / 16);
	count += ft_putcharpf_fd(hex[n % 16], 1);
	return (count);
}

int	ft_printf_p(void *nb)
{
	int			count;

	count = 0;
	if (!nb)
		return (ft_putstrpf_fd("(nil)", 1));
	count += ft_putstrpf_fd("0x", 1);
	count += ft_putnbr_hex((unsigned long long)nb);
	return (count);
}
/*
int main()
{
    int x = -1;
    int count = ft_printf_p(&x);
    printf("\nCharacters printed: %d\n", count);
    printf("%p", &x);
    return 0;
}*/
