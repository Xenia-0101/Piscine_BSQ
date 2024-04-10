/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:49:03 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/10 19:36:15 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

void	init_map(t_map *map)
{
	map->counts = 0;
	map->input = 0;
	map->info.x = 0;
	map->info.y = 0;
	map->info.coors[0] = 0;
	map->info.coors[1] = 0;
	map->info.empt = 0;
	map->info.obst = 0;
	map->info.full = 0;
	map->info.max_sq = 0;
}

void	bsq_file(char *name, t_map *map)
{
	if (solve_file(name, map))
	{
		print_solution(map);
		clean(map);
	}
	write(1, "\n", 2);
}


void	bsq_input(t_map *map)
{
	char	*file;

	ft_putstr(MSG_TO_USER);
	file = get_filename();
	if (!solve_file(file, map))
	{
		free(file);
		free(map);
		exit (2);
	}
	free(file);
	print_solution(map);
	clean(map);
	write(1, "\n", 2);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit (1);
	init_map(map);
	if (ac > 1)
	{
		while (ac-- > 1)
			bsq_file(av[ac], map);
	}
	else
	{
		bsq_input(map);
	}
	free(map);
	return (0);
}
