/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:50:08 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/06 10:16:46 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s_dest;
	const unsigned char	*s_src;

	if (!dest && !src)
		return (NULL);
	s_dest = (unsigned char *)dest;
	s_src = (const unsigned char *)src;
	if ((char *)dest > (char *)src && (char *)dest < (char *)src + n)
	{
		while (n-- > 0)
		{
			s_dest[n] = s_src[n];
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int main(void)
{
    // Initialisation d’un buffer avec une chaîne simple
    char buffer[20] = "123456789";

    printf("Avant memmove : %s\n", buffer);

    // Exemple 1 : chevauchement — on déplace "12345" 2 cases plus loin
    ft_memmove(buffer + 2, buffer, 5);

    printf("Après memmove : %s\n", buffer); // Doit être "121234589"

    // Exemple 2 : dans l’autre sens (de droite vers gauche)
    char buffer2[20] = "abcdef";
    ft_memmove(buffer2, buffer2 + 2, 4); // déplace "cdef" au début
    buffer2[4] = '\0'; // couper la chaîne proprement
    printf("memmove sens inverse : %s\n", buffer2); // Devrait afficher "cdef"

    return 0;
}*/
