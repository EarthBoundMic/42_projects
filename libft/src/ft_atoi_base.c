/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:43:04 by mkass             #+#    #+#             */
/*   Updated: 2018/09/22 12:48:07 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define NBR(a) (a >= '0' && a <= '9')
#define UPL(a) (a >= 'A' && a <= 'F')
#define LWL(a) (a >= 'a' && a <= 'f')
#define N 48
#define U 55
#define L 87

static int	negcheck(char c, int *i)
{
	int neg;

	neg = 0;
	if (c == '-')
	{
		neg = 1;
		*i += 1;
	}
	return (neg);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int ret;
	int i;
	int neg;

	if (str_base >= 2 && str_base <= 16)
	{
		i = 0;
		ret = 0;
		neg = negcheck(str[0], &i);
		while (str[i] && (NBR(str[i]) || UPL(str[i]) || LWL(str[i])))
		{
			ret *= str_base;
			if (NBR(str[i]))
				ret += (str[i] - N);
			else if (UPL(str[i]))
				ret += (str[i] - U);
			else if (LWL(str[i]))
				ret += (str[i] - L);
			i++;
		}
	}
	else
		return (0);
	return (neg ? -ret : ret);
}
