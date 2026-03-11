/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:42 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/19 14:02:16 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoingnl(char *gnl, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!gnl)
	{
		gnl = ft_calloc(1, sizeof(char));
		if (!gnl)
			return (NULL);
		gnl[0] = '\0';
	}
	if (!gnl || !buff)
		return (NULL);
	str = ft_calloc(sizeof(char), ((ft_strlen(gnl) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (gnl)
		while (gnl[++i] != '\0')
			str[i] = gnl[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	free(gnl);
	return (str);
}
