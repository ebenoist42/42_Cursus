/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:58:41 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 11:58:01 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char*s)

{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (s[size])
		size++;
	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < size)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main ()
{
	const	char* s= "42 ecole Paris";
	printf("%s", ft_strdup(s));
	return (0);
}*/