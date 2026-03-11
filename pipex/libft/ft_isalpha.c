/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:16:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:03 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 96 && c < 123) || (c > 64 && c < 91))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main ()
{
	int character = 'l';
	
	printf("%d, \n", isalpha (character));
	printf("%d, \n", ft_isalpha(character));
}*/
