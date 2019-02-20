/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:06:04 by mkass             #+#    #+#             */
/*   Updated: 2018/02/23 14:14:42 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	while (len)
	{
		*str = (unsigned char)c;
		len--;
		str++;
	}
	return (b);
}
