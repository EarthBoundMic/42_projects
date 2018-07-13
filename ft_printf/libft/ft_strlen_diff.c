/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_diff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:51:41 by mkass             #+#    #+#             */
/*   Updated: 2018/04/05 14:25:34 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_diff(const char *s1, const char *s2)
{
	long diff;

	if (s1[0] && s2[0])
	{
		diff = ft_strlen(s1) - ft_strlen(s2);
		if (diff < 0)
			diff *= -1;
		return (diff);
	}
	else if (s1[0] || s2[0])
	{
		diff = ft_strlen(s1) | ft_strlen(s2);
		return (diff);
	}
	return (0);
}
