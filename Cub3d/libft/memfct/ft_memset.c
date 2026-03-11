/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:00:19 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/05 16:36:17 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    // Exemple 1 : Tester avec un tableau de char
    char str[20] = "Hello, World!";
    
    printf("Avant memset: %s\n", str);
    
    // Test de ft_memset
    ft_memset(str, 'x', 5); // Remplir les 5 premiers caractères avec 'x'
    printf("Après ft_memset: %s\n", str);
    
    // Test avec la fonction memset standard pour comparer
    char str2[20] = "Hello, World!";
    memset(str2, 'y', 5); // Remplir les 5 premiers caractères avec 'y'
    printf("Après memset: %s\n", str2);

    // Exemple 2 : Tester avec un tableau d'entiers
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Avant ft_memset (arr): ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // Remplir tout le tableau avec la valeur 0
    ft_memset(arr, 0, sizeof(arr));

    printf("Après ft_memset (arr): ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // Exemple 3 : Test avec malloc
    char *buffer = malloc(10);
    if (buffer == NULL) {
        return 1; // Gérer l'erreur de malloc
    }

    ft_memset(buffer, 'a', 9); // Remplir le buffer avec 'a'
    buffer[9] = '\0'; // Assurer que c'est une chaîne de caractères valide
    printf("Buffer après ft_memset: %s\n", buffer);
    
    free(buffer); // Libération de la mémoire allouée

    return 0;
}*/
