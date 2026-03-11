/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:58:05 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/21 15:55:36 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print(const char c, va_list arg)
{
	if (c == 'c')
		return (ft_putcharpf_fd(va_arg(arg, int), 1));
	else if (c == 's')
		return (ft_putstrpf_fd(va_arg(arg, char *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbrpf_fd(va_arg(arg, int), 1, "0123456789"));
	else if (c == 'p')
		return (ft_printf_p(va_arg(arg, void *)));
	else if (c == 'x')
		return (ft_u_putnbr_fd(va_arg(arg, unsigned int),
				1, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_u_putnbr_fd(va_arg(arg, unsigned int),
				1, "0123456789ABCDEF"));
	else if (c == 'u')
		return (ft_u_putnbr_fd(va_arg(arg, unsigned int), 1, "0123456789"));
	else if (c == '%')
		return (ft_putcharpf_fd('%', 1));
	else
		return (0);
}

int	ft_param(const char c)
{
	if ((c == 'c' || c == 's' || c == 'd' || c == 'i')
		|| (c == 'p') || (c == 'u' || c == 'x' || c == 'X' || c == '%'))
		return (1);
	else
		return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	arg;
	int		i;

	if (!fmt)
		return (-1);
	va_start(arg, fmt);
	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			if (ft_param(fmt[i]) == 1)
				count += ft_print(fmt[i], arg);
			else
				count += ft_putcharpf_fd(fmt[i], 1);
		}
		else
			count += ft_putcharpf_fd(fmt[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
