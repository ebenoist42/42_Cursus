/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:32 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/07 11:02:50 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searched)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if ((unsigned char)string[i] == (unsigned char)searched)
			return ((char *)&(string[i]));
		i++;
	}
	if ((unsigned char)searched == '\0')
		return ((char *)&(string[i]));
	return (NULL);
}
/*
int main ()
{
	const char string[] = "teste";
	int	searched = 'a';
	printf("%s\n", strchr (string, searched));
	printf("%s\n", ft_strchr (string, searched));
}
*/