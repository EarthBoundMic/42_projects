/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:38:50 by mkass             #+#    #+#             */
/*   Updated: 2019/02/26 14:38:51 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_pow(int n, int x)
{
	int	ret;
	int	hold;
	int	i;

	i = 0;
	ret = n;
	hold = n;
	while (++i < x)
		ret *= hold;
	return (ret);
}

long long	ft_llpow(int n, int x)
{
	long long	ret;
	int			hold;
	int			i;

	i = 0;
	ret = n;
	hold = n;
	while (++i < x)
		ret *= hold;
	return (ret);
}

double		ft_dpow(double n, double x)
{
	double	ret;
	double	hold;
	double	i;

	i = 0;
	ret = n;
	hold = n;
	while (++i < x)
		ret *= hold;
	return (ret);
}

long double	ft_ldpow(double n, double x)
{
	long double	ret;
	double		hold;
	double		i;

	i = 0;
	ret = n;
	hold = n;
	while (++i < x)
		ret *= hold;
	return (ret);
}
