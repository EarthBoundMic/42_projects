/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:40:19 by mkass             #+#    #+#             */
/*   Updated: 2018/03/08 11:42:18 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_realstrcmp(const char *s1, const char *s2)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	int				i;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	i = 0;
	while (sc1[i] == sc2[i] && sc1[i] && sc2[i])
		i++;
	if (sc1[i] < sc2[i])
		return (-1);
	return (!(sc1[i] == sc2[i]));
}
