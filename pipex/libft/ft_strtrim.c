/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:16:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/03 13:16:49 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

int	ft_search_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	i--;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	int			len;
	char		*dest;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_search_start(s1, set);
	end = ft_search_end(s1, set);
	len = end - start;
	if (start > end)
		return (ft_strdup(""));
	dest = malloc (len + 2);
	if (!dest)
		return (NULL);
	len = 0;
	while (start < end + 1)
		dest[len++] = s1[start++];
	dest[len] = '\0';
	return (dest);
}
/*
int main ()
{
	char const *s1 = "aaaaaaaa";
	char const *set = "a";

	printf("%s\n", ft_strtrim(s1, set));
	//printf("%s \n", strtrim(s1, set));
}*/