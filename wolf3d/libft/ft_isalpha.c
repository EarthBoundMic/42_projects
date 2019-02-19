/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:17:22 by mkass             #+#    #+#             */
/*   Updated: 2018/02/21 16:01:25 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

static int	ft_islower(int c)
{
	return ((c >= 'a') && (c <= 'z'));
}

int			ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
