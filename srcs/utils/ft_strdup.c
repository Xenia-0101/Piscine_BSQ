/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:14:32 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/10 19:29:13 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_map.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = (char *) malloc(ft_strlen(src, '\0') * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
