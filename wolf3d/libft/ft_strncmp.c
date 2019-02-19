/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:33:24 by mkass             #+#    #+#             */
/*   Updated: 2018/03/08 11:49:48 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	size_t			i;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	i = 0;
	if (n < 1)
		return (0);
	while (sc1[i] == sc2[i] && sc1[i] && sc2[i] && i < n - 1)
		i++;
	return (sc1[i] - sc2[i]);
}
