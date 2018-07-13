/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:46:34 by mkass             #+#    #+#             */
/*   Updated: 2018/02/24 14:52:56 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *data;

	data = malloc(size);
	if (data != NULL)
	{
		ft_memset(data, '\0', size);
		return (data);
	}
	return (NULL);
}
