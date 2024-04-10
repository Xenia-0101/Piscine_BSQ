/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:00:39 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/10 18:07:59 by xvislock         ###   ########.fr       */
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

void clean(t_map *map)
{
	clean_input(map);
	clean_counts(map);
}
