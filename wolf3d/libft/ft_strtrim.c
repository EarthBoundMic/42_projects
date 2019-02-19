/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:53:49 by mkass             #+#    #+#             */
/*   Updated: 2018/03/08 11:41:37 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!(str = ft_strnew(j - i + 1)))
		return (NULL);
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
		j--;
	while (i <= j)
		str[k++] = s[i++];
	return (str);
}
