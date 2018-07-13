/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:32:57 by mkass             #+#    #+#             */
/*   Updated: 2018/03/06 13:12:40 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(const char *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			j++;
		i++;
		if (!*s || s[j - 1] == c)
			i--;
	}
	return (i);
}
