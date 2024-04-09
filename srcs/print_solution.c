
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
