/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:15:39 by mkass             #+#    #+#             */
/*   Updated: 2019/02/22 19:15:40 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*store_decimal(double nbr, int prec)
{
	char	*str;
	double	tmp;
	int		i;

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
			tmp -= (double)((int)(tmp + 0.01));
		}
		else
			str[i] = 48;
	}
	tmp *= 10.0;
	if ((int)tmp > 4)
		str[i - 1] += 1;
	return (str);
}

static char	*is_inf_or_nan(double nbr, int cap)
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

static void	store_whole(char *str, double nbr, size_t i, int prec)
{
	int tmp;

	str[--i] = ((size_t)(nbr) % 10) + 48;
	tmp = (int)(nbr * 10.0) % 10;
	if (!prec && tmp > 4)
		str[i] += 1;
	while ((nbr /= 10) > 1)
		str[--i] = ((size_t)(nbr) % 10) + 48;
}

static char	*process(double nbr, size_t i, int prec, int neg)
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

char		*ft_dtoa(double nbr, int prec, int cap)
{
	size_t	i;
	int		neg;

	if ((nbr * 2 == nbr && nbr != 0) || nbr != nbr)
		return (is_inf_or_nan(nbr, cap));
	if ((neg = (nbr < 0)))
		nbr *= -1;
	i = ft_dlen(nbr, prec);
	if (neg)
		i++;
	return (process(nbr, i, prec, neg));
}
