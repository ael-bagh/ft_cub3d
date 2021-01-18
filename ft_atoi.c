/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:52:51 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/18 17:28:33 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_atoi(const char *str)
{
	long long	result;

	result = 0;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (result > 2560)
		result = 2560;
	return (result);
}
