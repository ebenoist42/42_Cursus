/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:14:19 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/14 17:37:46 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_hexa(unsigned long long nb, char *base);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_printf(const char *tmp, ...);
int	ft_params(const char c);
int	ft_check(const char c, va_list ap);
int	ft_case_p(void *ptr);

#endif /* FT_PRINTF_H */