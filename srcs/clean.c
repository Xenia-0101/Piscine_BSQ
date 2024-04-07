/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:00:39 by vconesa-          #+#    #+#             */
/*   Updated: 2024/03/20 19:04:53 by vconesa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	clean_input(t_map *map)
{
	int	x;
	int	i;

	x = map->info.x;
	i = 0;
	while (i < x)
	{
		free(map->input[i]);
		i++;
	}
	free(map->input);
}

void	clean_counts(t_map *map)
{
	int	x;
	int	i;

	x = map->info.x;
	i = 0;
	while (i < x)
	{
		free(map->counts[i]);
		i++;
	}
	free(map->counts);
}
