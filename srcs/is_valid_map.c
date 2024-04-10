/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:41:04 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/10 19:27:53 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

int	is_valid_map(char *buff, t_map *map)
{
	int		i;
	int		j;
	int		row_len;

	// get the length of the first row
	row_len = ft_strlen(buff, '\n');
	i = 0;
	j = 0;
	while (i < map->info.x)
	{
		while (buff[j] != '\n')
		{
			// if an incorrect char is found, return 0
			if (!(buff[j] == map->info.empt || buff[j] == map->info.obst))
				return (0);
			j++;
		}
		j++;
		i++;
		// return 0 if row length is inconsistent
		if (j != (row_len * i) + i)
			return (0);
	}
	return (1);
}
