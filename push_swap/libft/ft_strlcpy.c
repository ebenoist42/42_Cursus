/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:12:14 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:27:31 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
	{
		while (src[j])
			j++;
		return (j);
	}
	while (i < size -1 && src[j])
	{
		dst[j] = src[j];
		i++;
		j++;
	}
	dst[j] = '\0';
	while (src[j])
		j++;
	return (j);
}
