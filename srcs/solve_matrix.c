/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:16:06 by vconesa-          #+#    #+#             */
/*   Updated: 2024/03/20 21:50:50 by vconesa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	allocate_counts(t_map *map)
{
	int	i;

	map->counts = (int **)malloc((map->info.x) * sizeof(int *));
	if (!map->counts)
		return ;
	i = 0;
	while (i < map->info.x)
	{
		map->counts[i] = (int *)malloc(map->info.y * sizeof(int));
		if (!map->counts[i])
			return ;
		i++;
	}
}

void	calculate_counts(t_map *map, int i, int j)
{
	int	current_count;
	int	**m_counts;

	m_counts = map->counts;
	if (map->input[i][j] == 'o')
	{
		current_count = 0;
	}
	else if (j == (map->info.y - 1))
		current_count = 1;
	else if (i == (map->info.x - 1))
		current_count = 1;
	else
	{
		current_count = 1 + min_value(
				m_counts[i + 1][j], m_counts[i][j + 1], m_counts[i + 1][j + 1]);
	}
	map->counts[i][j] = current_count;
	if (map->info.max_sq <= current_count)
	{
		map->info.max_sq = current_count;
		map->info.coors[0] = i;
		map->info.coors[1] = j;
	}
}

void	loop_matrix(t_map *map)
{
	int	i;
	int	j;

	map->info.max_sq = 0;
	allocate_counts(map);
	i = map->info.x - 1;
	while (i >= 0)
	{
		j = map->info.y - 1;
		while (j >= 0)
		{
			calculate_counts(map, i, j);
			j--;
		}
		i--;
	}
}

void	print_solution(t_map *map)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	t_y;

	x = map->info.coors[0];
	y = map->info.coors[1];
	max_x = map->info.max_sq + x;
	max_y = map->info.max_sq + y;
	t_y = y;
	while (x < max_x)
	{
		while (y < max_y)
			map->input[x][y++] = map->info.full;
		x++;
		y = t_y;
	}
	print_matrix(map->input, map);
}
