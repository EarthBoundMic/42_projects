/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fndpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:09:52 by mkass             #+#    #+#             */
/*   Updated: 2018/09/11 15:10:05 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fndpath(char *file)
{
	int	i;
	int	j;

	i = ft_strlen(file);
	j = i;
	WHLE(file[j - 1] != '/' && j > 1, j--);
	if (j == 1 && file[0] != '/')
		return (NULL);
	return (ft_strsub(file, 0, j));
}
