/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:29:49 by mkass             #+#    #+#             */
/*   Updated: 2018/02/24 12:53:47 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	chr;
	int				i;

	i = 0;
	src = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n)
	{
		if (src[i] == chr)
			return (src + i);
		i++;
		n--;
	}
	return (NULL);
}
