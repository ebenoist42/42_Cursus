/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:47:06 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/06 10:08:33 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s_dest;
	const unsigned char	*s_src;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s_dest = (unsigned char *)dest;
	s_src = (const unsigned char *)src;
	while (i < n)
	{
		s_dest[i] = s_src[i];
		i++;
	}
	return (dest);
}
