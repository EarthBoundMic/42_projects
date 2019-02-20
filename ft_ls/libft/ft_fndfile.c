/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fndfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:41:36 by mkass             #+#    #+#             */
/*   Updated: 2018/05/17 14:42:43 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fndfile(char *file)
{
	int		i;
	int		j;

	i = ft_strlen(file);
	if (!i)
		return ("");
	j = i;
	WHLE(file[j - 1] != '/' && j > 1, j--);
	if (j == 1 && file[0] != '/')
		return (ft_strdup(file));
	else if (j == i)
		return (NULL);
	return (ft_strsub(file, j, i));
}
