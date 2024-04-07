/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:50 by xvislock          #+#    #+#             */
/*   Updated: 2024/03/20 21:50:17 by vconesa-         ###   ########.fr       */
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
