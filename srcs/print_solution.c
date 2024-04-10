/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:39:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/10 19:39:29 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	print_matrix(char **m, t_map *map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map->info.x)
	{
		j = 0;
		while (m[i][j])
		{
			write(1, &m[i][j], 1);
			j++;
		}
		write(1, "\n", 2);
		i++;
	}
}

void	print_solution(t_map *map)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	// get the coordinates of the upper left corner
	x = map->info.coors[0];
	y = map->info.coors[1];
	// calculate the coordinates of the lower right corner
	max_x = map->info.max_sq + x;
	max_y = map->info.max_sq + y;
	// while x, y are within bounds, change char to full
	while (x++ < max_x)
	{
		while (y < max_y)
			map->input[x][y++] = map->info.full;
		y = map->info.coors[1];
	}
	print_matrix(map->input, map);
}
