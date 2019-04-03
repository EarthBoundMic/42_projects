/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:07:20 by mkass             #+#    #+#             */
/*   Updated: 2019/03/01 17:07:21 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlen(double nbr, int prec)
{
	size_t	i;

	if (nbr * 2 == nbr && nbr != 0)
		return (3);
	else if (nbr != nbr)
		return (3);
	i = 1;
	while ((nbr /= 10) > 1)
		i++;
	if (prec)
		return (i + prec + 1);
	else
		return (i);
}
