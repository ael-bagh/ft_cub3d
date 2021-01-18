/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:45:41 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/17 15:46:01 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (*s1 == '\0')
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (*s1 && i < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			i++;
			if (*s1 == '\0')
				return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
