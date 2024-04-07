/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:14 by xvislock          #+#    #+#             */
/*   Updated: 2024/03/20 20:04:09 by vconesa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

int	get_file_descriptor(char *filename)
{
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

	buff_size = 300000;
	buff = (char *)malloc(buff_size * sizeof (char));
	if (buff == NULL)
	{
		write(2, "Can't allocate memory.", 20);
		return (NULL);
	}
	i = 0;
	while (i < buff_size)
	{
		buff[i] = '\0';
		i++;
	}
	read_size = read(fd, buff, buff_size);
	if (read_size == buff_size)
	{
		write(2, "Maximum map size exceeded.", 18);
		return (NULL);
	}
	return (buff);
}

char	*get_first_line(char *buff, t_map *map)
{
	char	row[1024];
	int		i;

	i = 0;
	while (*buff && *buff != '\n')
	{
		row[i++] = *buff;
		buff++;
	}
	row[i] = '\0';
	map->info.full = row[i - 1];
	map->info.obst = row[i - 2];
	map->info.empt = row[i - 3];
	row[i - 3] = '\0';
	map->info.x = ft_atoi(row);
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
	buff++;
	if (!is_valid_map(buff, map))
	{
		ft_putstr(MAP_ERROR);
		free(buff_start);
		return (0);
	}
	map->info.y = ft_strlen(buff);
	create_map(buff, map);
	free(buff_start);
	loop_matrix(map);
	return (1);
}
