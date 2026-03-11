/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:07:07 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/06 16:07:41 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_count(char const *s, char c)
{
	size_t	count;
	int		i;
	int		word;

	word = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (s[i] == c && word == 1)
			word = 0;
		i++;
	}
	return (count);
}

void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_write(char **split, const char *s, char c, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			split[k] = ft_substr(s, j, i - j);
			if (!split[k])
			{
				ft_free(split);
				return (NULL);
			}
			k++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!split)
		return (NULL);
	if (ft_count(s, c) == 0)
	{
		split[0] = NULL;
		return (split);
	}
	split = ft_write(split, s, c, j);
	if (!split)
		return (NULL);
	return (split);
}
/*
int	main(void)
{
	char const*s = "Hello\0zorld";
	char	c = '\0';
	//size_t	count = ft_count(s, c);
	char  **split = ft_split(s, c);
	int	i = 0;
	//printf("%zu\n", ft_count(s, c));
	while(split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return 0;
}*/
