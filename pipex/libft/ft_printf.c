/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:28:23 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/22 14:27:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_case_p(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (count += ft_putstr("(nil)"));
	count += ft_putstr ("0x");
	count += ft_putnbr_hexa((long long int)ptr, "0123456789abcdef");
	return (count);
}

int	ft_check(const char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(ap, int));
	if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	if (c == 'x')
		count += ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	if (c == 'p')
	{
		if (!ap)
			return (count += ft_putstr("(nil)"));
		count += ft_case_p(va_arg (ap, void *));
	}
	return (count);
}

int	ft_params(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *tmp, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, tmp);
	if (!tmp)
		return (0);
	i = 0;
	count = 0;
	while (tmp[i])
	{
		if (tmp[i] == '%' && tmp[i + 1])
		{
			i++;
			if (ft_params(tmp[i]) == 1)
				count += ft_check(tmp[i], ap);
			else
				count += ft_putchar(tmp[i]);
		}
		else
			count += ft_putchar(tmp[i]);
		i++;
	}
	va_end (ap);
	return (count);
}

/*
int main ()
{
	//char *str = NULL;
	printf("%d" ,ft_printf()
	printf("%d", printf());
}*/
