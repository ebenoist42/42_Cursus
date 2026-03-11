/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:38:52 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/07 10:59:48 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malloc_line(void)
{
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_malloc_line());
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dest = malloc(sizeof (char) *(len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
	char *const s= "coucou";
    char *sub2 = ft_substr(s, 7, 9);
    printf("%s\n", sub2);
    free(sub2);
    return 0;
}*/