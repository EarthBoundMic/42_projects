/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:38:44 by mkass             #+#    #+#             */
/*   Updated: 2018/02/23 16:00:47 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *first;
	const unsigned char *second;

	if (s1 == s2 || n == 0)
		return (0);
	first = (const unsigned char *)s1;
	second = (const unsigned char *)s2;
	while (n)
	{
		if (*first != *second)
			return (*first - *second);
		first++;
		second++;
		n--;
	}
	return (0);
}
