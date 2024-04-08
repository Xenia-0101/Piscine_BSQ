/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:42:41 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/08 12:21:11 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	init_input(t_map *map)
{
	int	i;

	//insert terminal char to each row
	i = 0;
	while (i < map->info.x)
	{
		map->input[i] = '\0';
		i++;
	}
}

void init_rows(int i, int pos, t_map *map, char *row)
{
	row[pos] = '\0';
	map->input[i] = (char *)malloc(map->info.y * sizeof(char) + 1);
	if (!map->input[i])
		return ;
	map->input[i][0] = '\0';
}

void fill_map(char *buff, t_map *map)
{
	int		i;
	int		pos;
	char	row[1024];

	i = 0;
	pos = 0;
	while (*buff)
	{
		row[pos] = *buff;
		if (*buff == '\n')
		{
			init_rows(i, pos, map, row);
			// insert char at given position
			ft_strcpy(map->input[i], row);
			pos = 0;
			i++;
		}
		else
			pos++;
		buff++;
	}
}

int	create_map(char *buff, t_map *map)
{
	// allocate memory for *input
	map->input = (char **)malloc(map->info.x * sizeof(char *) + 1);
	if (!map->input)
		return (0);
	// initialize input
	map->input[0] = 0;
	init_input(map);
	fill_map(buff, map);
	return (1);
}
