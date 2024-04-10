/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:13 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/10 17:06:09 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_map.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*t_dest;

	t_dest = dest;
	while (*src)
	{
		*t_dest = *src;
		t_dest++;
		src++;
	}
	*t_dest = '\0';
	return (dest);
}
