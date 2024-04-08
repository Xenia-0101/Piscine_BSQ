/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:14 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/08 12:31:15 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

int	get_file_descriptor(char *filename)
{
	/*
		Open file and return unique file identifier.
		Returns -1 if file not found
	*/
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(MAP_ERROR);
		return (-1);
	}
	return (fd);
}

char	*get_file_buffer(int fd)
{
	char	*buff;
	int		buff_size;
	int		read_size;
	int		i;

	// allocate memory to the buffer
	buff_size = 300000;
	buff = (char *)malloc(buff_size * sizeof (char));
	// if buff is empty, return NULL
	if (buff == NULL)
		return (NULL);
	// initialise buffer
	i = 0;
	while (i < buff_size)
	{
		buff[i] = '\0';
		i++;
	}
	// read file and copy contents to the buffer
	read_size = read(fd, buff, buff_size);
	if (read_size == buff_size)
		return (NULL);
	// return pointer to the buffer
	return (buff);
}

char	*get_first_line(char *buff, t_map *map)
{
	char	row[1024];
	int		i;

	// write the first line to the row
	i = 0;
	while (*buff && *buff != '\n')
	{
		row[i++] = *buff;
		buff++;
	}
	row[i] = '\0';

	// last three chars describe the map symbols
	map->info.full = row[i - 1];
	map->info.obst = row[i - 2];
	map->info.empt = row[i - 3];
	row[i - 3] = '\0';
	// the beginning of the row determines the map size
	map->info.x = ft_atoi(row);
	buff++;
	// return pointer to the next row of the buffer
	return (buff);
}

int	read_file(char *filename, t_map *map)
{
	int		fd;
	char	*buff;
	char	*buff_start;

	fd = get_file_descriptor(filename);
	if (fd == -1)
		return (0);
	buff = get_file_buffer(fd);
	buff_start = buff;
	buff = get_first_line(buff, map);
	if (!is_valid_map(buff, map))
	{
		ft_putstr(MAP_ERROR);
		free(buff_start);
		return (0);
	}
	map->info.y = ft_strlen(buff);
	create_map(buff, map);
	free(buff_start);
	solve_matrix(map);
	return (1);
}
