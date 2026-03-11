/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:50:47 by ebenoist          #+#    #+#             */
/*   Updated: 2025/05/06 10:28:29 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character)
{
	if (character > 96 && character < 123)
	{
		character = character - 32 ;
	}
	return (character);
}
/*
#include <stdio.h>
#include <ctype.h>
int main ()
{
	int character = 97;
	printf("%c \n", ft_toupper(character));
	printf("%c \n", toupper(character));
}*/
