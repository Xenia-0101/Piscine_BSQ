/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:49:03 by vconesa-          #+#    #+#             */
/*   Updated: 2024/03/20 21:56:18 by vconesa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

char	*get_filename(void)
{
	int		pos;
	char	c;
	char	buffer[1024];
	char	*name;

	buffer[0] = '\0';
	pos = 0;
	while (read(0, &c, 1) > 0 && c != '\n')
		buffer[pos++] = c;
	buffer[pos] = '\0';
	name = ft_strdup(buffer);
	return (name);
}

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

void	print_and_free(t_map *map)
{
	print_solution(map);
	clean_input(map);
	clean_counts(map);
}

void	read_from_input(t_map *map)
{
	char	*file;

	ft_putstr(MSG_TO_USER);
	file = get_filename();
	if (!read_file(file, map))
	{
		free(file);
		free(map);
		exit (2);
	}
	free(file);
	print_and_free(map);
	write(1, "\n", 2);
}

int	main(int ac, char **av)
{
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit (1);
	init_map(map);
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (read_file(av[i], map))
				print_and_free(map);
			write(1, "\n", 2);
			i++;
		}
	}
	else
	{
		read_from_input(map);
	}
	free(map);
	return (0);
}
