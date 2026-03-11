/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:22:03 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 14:52:03 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (first[i] && second[i] && i < size - 1)
	{
		if ((unsigned char) first[i] != (unsigned char) second[i])
			return ((unsigned char) first[i] - (unsigned char) second[i]);
		i++;
	}
	return ((unsigned char) first[i] - (unsigned char) second[i]);
}
/*
int main ()
{
	const char *first =  "abcdefgh";
	const char *second = "abcdwxyz";
	size_t size = 5;

	printf("%d \n", ft_strncmp(first, second, size));
	printf("%d \n", strncmp(first, second, size));
}*/