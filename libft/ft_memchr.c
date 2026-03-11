/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:00:01 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:46 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t size)
{
	size_t				j;
	unsigned char		i;
	const unsigned char	*p;

	p = (const unsigned char *)buf;
	i = (unsigned char) c;
	j = 0;
	while (j < size)
	{
		if (i == p[j])
			return ((void *)(&p[j]));
		j++;
	}
	return (NULL);
}
