/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:05:42 by xvislock          #+#    #+#             */
/*   Updated: 2024/04/10 17:20:20 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_map.h"

int	min_value(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}
