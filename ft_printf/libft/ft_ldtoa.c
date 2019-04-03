/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:48:59 by mkass             #+#    #+#             */
/*   Updated: 2019/02/27 15:49:00 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*store_decimal(long double nbr, int prec)
{
	char		*str;
	long double	tmp;
	int			i;

	i = 0;
	if (!(str = ft_strnew(prec + 1)))
		return (NULL);
	str[i] = '.';
	tmp = (long long)nbr;
	tmp = nbr - tmp;
	while (++i <= prec)
	{
		tmp *= 10.0;
		if ((int)tmp > 0)
		{
			str[i] = (int)(tmp + 0.01) + 48;
			tmp -= (long double)((int)(tmp + 0.01));
		}
		else
			str[i] = 48;
	}
	tmp *= 10.0;
	if ((int)tmp > 4)
		str[i - 1] += 1;
	return (str);
}

static char	*is_inf_or_nan(long double nbr, int cap)
{
	if (!cap)
	{
		if (nbr * 2 == nbr && nbr != 0)
		{
			if (nbr > 0)
				return (ft_strdup("inf"));
			else
				return (ft_strdup("-inf"));
		}
		else
			return (ft_strdup("nan"));
	}
	else
	{
		if (nbr * 2 == nbr && nbr != 0)
		{
			if (nbr > 0)
				return (ft_strdup("INF"));
			else
				return (ft_strdup("-INF"));
		}
		else
			return (ft_strdup("NAN"));
	}
}

static void	store_whole(char *str, long double nbr, size_t i, int prec)
{
	int tmp;

	str[--i] = ((size_t)(nbr) % 10) + 48;
	tmp = (int)(nbr * 10.0) % 10;
	if (!prec && tmp > 4)
		str[i] += 1;
	while ((nbr /= 10) > 1)
		str[--i] = ((size_t)(nbr) % 10) + 48;
}

static char	*process(long double nbr, size_t i, int prec, int neg)
{
	char	*str;
	char	*dec;

	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	if (neg)
		str[0] = 45;
	if (prec)
	{
		store_whole(str, nbr, i - prec - 1, prec);
		if (!(dec = store_decimal(nbr, prec)))
			return (NULL);
		ft_strcat(str, dec);
		ft_strdel(&dec);
	}
	else
		store_whole(str, nbr, i, prec);
	return (str);
}

char		*ft_ldtoa(long double nbr, int prec, int cap)
{
	size_t	i;
	int		neg;

	if ((nbr * 2 == nbr && nbr != 0) || nbr != nbr)
		return (is_inf_or_nan(nbr, cap));
	if ((neg = (nbr < 0)))
		nbr *= -1;
	i = ft_ldlen(nbr, prec);
	if (neg)
		i++;
	return (process(nbr, i, prec, neg));
}
