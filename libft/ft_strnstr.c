/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:37:19 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:27:53 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char*big, const char*small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (small[i] == '\0')
		return ((char *)(&big[i]));
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == small [j] && i + j < len)
		{
			j++;
			if (small[j] == '\0')
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main ()
{
	const char *big = "bonjour!";
	const char *small = "jour";
	size_t len = 10;

	printf("%s \n", ft_strnstr (big, small, len));
}
*/