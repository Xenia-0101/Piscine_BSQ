/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:57 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/08 09:08:56 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
int		is_digit(char c);
char	ft_strlen(char *str);
int		min_value(int a, int b, int c);
void	ft_putstr(char *str);
void	print_matrix_int(int **m);
char	*ft_strdup(char *src);
int		get_file_descriptor(char *filename);
char	*get_file_buffer(int fd);
# define MAP_ERROR "map error\n"
# define MSG_TO_USER "Please enter the path of the file:\n"

typedef struct s_map_info
{
	int		x;
	int		y;
	char	empt;
	char	obst;
	char	full;
	int		max_sq;
	int		coors[2];
}	t_info;

typedef struct s_map_str
{
	char	**input;
	int		**counts;
	t_info	info;
}	t_map;

int		read_file(char *filename, t_map *map);
void	loop_matrix(t_map *map);
void	print_solution(t_map *map);
char	*get_first_line(char *buff, t_map *map);
int		is_valid_map(char *buff, t_map *map);
int		create_map(char *buff, t_map *map);
void	allocate_counts(t_map *map);
void	calculate_counts(t_map *map, int i, int j);
int		correct_char(char *buff, t_map *map);
void	init_input(t_map *map);
void	fill_rows(int i, int pos, t_map *map, char *row);
void	clean_input(t_map *map);
void	clean_counts(t_map *map);
void	print_matrix(char **m, t_map *map);
#endif
