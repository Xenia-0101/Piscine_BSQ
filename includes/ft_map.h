/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:57 by vconesa-          #+#    #+#             */
/*   Updated: 2024/04/10 19:43:23 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_atoi(char *str);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	ft_strlen(char *str, char stop);
int		is_digit(char c);
int		min_value(int a, int b, int c);
char	*get_filename(void);
# define MAP_ERROR "map error\n"
# define MSG_TO_USER "Please enter the path of the file:\n"

typedef struct s_map_info
{
	int		x; // row count
	int		y; // col count
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

void	clean(t_map *map);
int		create_map(char *buff, t_map *map);
int		is_valid_map(char *buff, t_map *map);
void	print_solution(t_map *map);
int		solve_file(char *filename, t_map *map);
void	solve_matrix(t_map *map);
#endif
