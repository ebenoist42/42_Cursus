/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:17:06 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/02 11:50:35 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	total;

	dest = NULL;
	total = count * size;
	if (total == 0 || count <= SIZE_MAX / size)
		dest = (void *)malloc(total);
	if (!dest)
		return (NULL);
	ft_bzero(dest, total);
	return (dest);
}
/*
int main() 
{
    int n = 5;
    int *tab = (int *)calloc(n, sizeof(int));  // alloue un tableau de 5 int

    if (tab == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    // Vérification : tous les éléments doivent être initialisés à 0
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (tab[i] != 0) {
            ok = 0;
            break;
        }
    }

    if (ok) {
        printf("Test réussi : tous les éléments sont à 0.\n");
    } else {
        printf("Échec : un ou plusieurs éléments ne sont pas à 0.\n");
    }

    free(tab);  // ne pas oublier de libérer la mémoire
    return 0;
}*/
