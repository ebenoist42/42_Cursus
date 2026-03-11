/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:37:01 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:27:21 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		dest[i] = s2[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main ()
{
	char const *s1 = "coucou";
	char const *s2 = "lesloulous ";
	printf("%s", ft_strjoin(s1, s2));
}*/