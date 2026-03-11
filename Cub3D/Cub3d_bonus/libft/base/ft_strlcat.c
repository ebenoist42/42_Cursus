/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:47:11 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/08/18 14:49:09 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	i;

	i = 0;
	ldst = ft_strlen(dst);
	if (size <= ldst)
		return (ft_strlen(src) + size);
	while (ldst + i < size - 1 && src[i])
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ft_strlen(src) + ldst);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest + ft_strlen(dest);
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char *src = "world";
	char dest[50] = "hello";
	int c = ft_strlcat(dest, src, 50);
	printf("%d\n", c);
	printf("%s", dest);
}*/
