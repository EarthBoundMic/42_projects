/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:38:20 by mkass             #+#    #+#             */
/*   Updated: 2018/03/06 16:00:05 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	clone;
	int		neg;

	i = ft_nlen(n);
	clone = n;
	neg = (n < 0);
	if (neg)
	{
		clone *= -1;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[--i] = clone % 10 + 48;
	while (clone /= 10)
		str[--i] = clone % 10 + 48;
	if (neg)
		str[0] = 45;
	return (str);
}
