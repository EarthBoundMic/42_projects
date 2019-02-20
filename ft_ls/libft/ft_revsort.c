/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:19:45 by mkass             #+#    #+#             */
/*   Updated: 2018/08/31 16:20:25 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revsort(char **buf, int (cmp)(), void *option)
{
	int		i;
	int		size;

	i = 0;
	size = ft_splitlen(buf);
	while (i < size - 1)
	{
		if (option && cmp(buf[i], buf[i + 1], option) < 0)
			i = ft_strswch(&buf[i], &buf[i + 1]);
		else if (cmp(buf[i], buf[i + 1]) < 0)
			i = ft_strswch(&buf[i], &buf[i + 1]);
		else
			i++;
	}
}
