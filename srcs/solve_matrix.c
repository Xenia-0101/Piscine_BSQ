/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:16:06 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/09 10:00:40 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	init_counts(t_map *map)
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
	// if obstacle on the position, counts = 0
	if (map->input[i][j] == map->info.obst)
		current_count = 0;
	// if position is far right column or lowest row, counts = 1;
	else if (j == (map->info.y - 1))
		current_count = 1;
	else if (i == (map->info.x - 1))
		current_count = 1;
	// calculate counts
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

void	solve_matrix(t_map *map)
{
	int	i;
	int	j;

	map->info.max_sq = 0;
	init_counts(map);
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
