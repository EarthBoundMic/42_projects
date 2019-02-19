/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:23:40 by mkass             #+#    #+#             */
/*   Updated: 2018/03/06 16:48:13 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str_ar;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	k = ft_word_count(s, c);
	if (!(str_ar = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	str_ar[k] = NULL;
	i = 0;
	while (i < k)
	{
		while (*s == c)
			s++;
		if (!(str_ar[i] = (char *)malloc(sizeof(char) *
										(ft_word_len(s, c) + 1))))
			return (NULL);
		ft_word_cpy(str_ar[i], s, c);
		while (*s && *s != c)
			s++;
		i++;
	}
	return (str_ar);
}
