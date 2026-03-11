/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:17:28 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/07 10:26:12 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int search)
{
	int			i;

	i = 0;
	while (string[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char )string[i] == (unsigned char) search)
			return ((char *)&(string[i]));
		i--;
	}
	return (NULL);
}

/*
int main ()
{
	const char *str = "dfsd";
	int s = '\0';

	printf("%s \n", ft_strrchr(str, s));
	printf("%s \n", strrchr(str, s));
}
*/