/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:41:04 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/07 22:56:09 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

int	correct_char(char *buff, t_map *map)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (!(buff[i] == map->info.empt
				|| buff[i] == map->info.obst || buff[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map(char *buff, t_map *map)
{
	int		i;
	int		j;
	int		row_len;

	row_len = ft_strlen(buff);
	i = 0;
	j = 0;
	while (i < map->info.x)
	{
		while (buff[j] != '\n')
		{
			j++;
		}
		j++;
		i++;
		if (j != (row_len * i) + i)
			return (0);
	}
	if (!correct_char(buff, map))
		return (0);
	return (1);
}
