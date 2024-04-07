/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:42:41 by vconesa-          #+#    #+#             */
/*   Updated: 2024/03/20 19:55:26 by vconesa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	init_input(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->info.x)
	{
		map->input[i] = '\0';
		i++;
	}
}

void	fill_rows(int i, int pos, t_map *map, char *row)
{
	row[pos] = '\0';
	map->input[i] = (char *)malloc(map->info.y * sizeof(char) + 1);
	if (!map->input[i])
		return ;
	map->input[i][0] = '\0';
	ft_strcpy(map->input[i], row);
}

int	create_map(char *buff, t_map *map)
{
	int		i;
	int		pos;
	char	row[1024];

	map->input = (char **)malloc(map->info.x * sizeof(char *) + 1);
	if (!map->input)
		return (0);
	map->input[0] = 0;
	init_input(map);
	i = 0;
	pos = 0;
	while (*buff)
	{
		row[pos] = *buff;
		if (*buff == '\n')
		{
			fill_rows(i, pos, map, row);
			pos = 0;
			i++;
		}
		else
			pos++;
		buff++;
	}
	return (1);
}
