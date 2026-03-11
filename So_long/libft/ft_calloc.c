/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:21:23 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:24:54 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ecount, size_t size)
{
	unsigned char	*tab;
	size_t			total;
	size_t			i;

	total = ecount * size;
	tab = malloc(ecount * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < total)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int main(void)
{
    int *tab;
    size_t i;
    size_t size = 5;

    tab = ft_calloc(size, sizeof(int));

    if (!tab)
    {
        printf("Allocation échouée\n");
        return (1);
    }
    printf("Contenu du tableau initialisé :\n");
    for (i = 0; i < size; i++)
    {
        printf("tab[%zu] = %d\n", i, tab[i]);
    }
    free(tab);
    return (0);
}*/