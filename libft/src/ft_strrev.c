/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:52:12 by mkass             #+#    #+#             */
/*   Updated: 2018/03/02 14:02:58 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	chr;

	i = -1;
	if (!str)
		return ("");
	len = ft_strlen(str);
	while (i++ < --len)
	{
		chr = str[i];
		str[i] = str[len];
		str[len] = chr;
	}
	return (str);
}
