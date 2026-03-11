/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:47:46 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/23 14:03:34 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_tab(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		count++;
	return (count);
}

void	ft_free_split(char **dest, int j)
{
	while (--j >= 0)
		free(dest[j]);
	free(dest);
}

int	ft_fill_split(char **tab, char const *s, char c, int j)
{
	int	i;
	int	start;
	int	k;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = malloc(i - start + 1);
		if (!tab[j])
			return (ft_free_split(tab, j), 0);
		k = 0;
		while (start < i)
			tab[j][k++] = s[start++];
		tab[j++][k] = '\0';
	}
	tab[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	count = ft_count_tab(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	if (count == 0)
	{
		tab[0] = NULL;
		return (tab);
	}
	if (!ft_fill_split(tab, s, c, j))
		return (NULL);
	return (tab);
}
/*
int	main(void)
{
	char	**res;
	int		i;

	res = ft_split("hello \0 world", '\0');
	if (!res)
		return (1);
	i = 0;
	while (res[i])
	{
		printf("mot[%d] = \"%s\"\n", i, res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}*/
