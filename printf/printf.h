/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:14:19 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/13 15:19:19 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
#endif