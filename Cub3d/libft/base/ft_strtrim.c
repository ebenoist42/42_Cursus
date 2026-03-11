/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:44:51 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/02 14:15:51 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end -1]))
		end--;
	len = end - start;
	trim = ft_substr(s1, start, len);
	return (trim);
}
/*
int main(void)
{
    char *result;

    result = ft_strtrim("   ---Hello World---   ", " -");
    printf("Résultat : \"%s\"\n", result);  // Doit afficher : "Hello World"

    free(result); // toujours libérer la mémoire allouée

    return 0;
}*/
