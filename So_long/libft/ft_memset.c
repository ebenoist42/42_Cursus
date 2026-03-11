/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:36:16 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:26:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)pointer)[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}

/*
#include <string.h>
#include <stdio.h>

int	main ()
{
	char	pointeur[] = "Paris";
	int	value = '5';
	size_t size = 4;
	printf("%s \n", ft_memset(pointeur, value, size));
	printf ("%s \n", memset(pointeur, value, size));
}*/
