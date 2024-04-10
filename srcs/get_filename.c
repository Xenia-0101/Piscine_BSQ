/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:39:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/10 19:39:55 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

char	*get_filename(void)
{
	int		pos;
	char	c;
	char	buffer[1024];
	char	*name;

	buffer[0] = '\0';
	pos = 0;
	while (read(0, &c, 1) > 0 && c != '\n')
		buffer[pos++] = c;
	buffer[pos] = '\0';
	name = ft_strdup(buffer);
	return (name);
}
