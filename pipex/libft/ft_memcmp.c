/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:39:29 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:49 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *S1, const void *S2, size_t size)
{
	size_t				c;
	const unsigned char	*s1;
	const unsigned char	*s2;

	c = 0;
	s1 = (const unsigned char *) S1;
	s2 = (const unsigned char *) S2;
	while (c < size)
	{
		if (s1[c] == s2[c])
			c++;
		else
			return (s1[c] - s2[c]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main ()
{
	int array1 [] = { 54, 85, 20, 63, 21 };
    	int array2 [] = { 54, 85, 19, 63, 21 };
    	size_t size = sizeof( int ) * 5;

	printf("%d \n", ft_memcmp(array1, array2, size));
	printf("%d \n", memcmp(array1, array2, size));

}*/
