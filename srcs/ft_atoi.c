/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vconesa- <vconesa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:00:50 by vconesa-          #+#    #+#             */
/*   Updated: 2024/03/20 18:44:06 by vconesa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_map.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	sign = 1;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	nb = 0;
	while (*str != '\0' && is_digit(*str))
	{
		nb *= 10;
		nb += *str - 48;
		++str;
	}
	return (nb * sign);
}
