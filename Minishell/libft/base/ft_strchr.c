/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:46:46 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/06 12:09:15 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		x;

	if (!s)
		return (NULL);
	str = (char *)s;
	x = ft_strlen(str) + 1;
	while (x-- > 0)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *s = "bonjour";
	char *res = ft_strchr(s, '\0');
	printf("%s", res);
}*/
