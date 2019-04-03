/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:13:44 by mkass             #+#    #+#             */
/*   Updated: 2018/10/09 15:13:57 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_is_inf_or_nan(long double nbr, t_pfflag *f)
{
	char	*str;
	int		len;
	int		ret;

	str = ft_ldtoa(nbr, f->precision, f->cap);
	len = ft_strlen(str);
	pf_left_width2(len, f);
	ft_putstr(str);
	pf_right_width(len, f);
	ret = CHKMAX((int)f->fldwidth, len);
	ft_strdel(&str);
	return (CHKCE(f->wdth, ret, len));
}

static int	parse_double(long double nbr, t_pfflag *f)
{
	int		len;
	int		tlen;
	char	*str;

	if ((nbr * 2 == nbr && nbr != 0) || nbr != nbr)
		return (pf_is_inf_or_nan(nbr, f));
	str = ft_ldtoa(nbr, f->precision, 0);
	len = ft_strlen(str);
	tlen = pf_ldnbrlen(nbr, f);
	pf_left_width1(tlen, f);
	ft_putstr(str);
	if (f->hash && !f->precision)
		ft_putchar(PRID);
	pf_right_width(tlen, f);
	len = CHKMAX(tlen, (int)f->fldwidth);
	ft_strdel(&str);
	return (CHKCE(f->wdth, len, tlen));
}

static int	hash_ldnbr(long double nbr, char sign, t_pfflag *f)
{
	int	len;
	int	add;
	int	slen;

	if ((nbr * 2 == nbr && nbr != 0) || nbr != nbr)
		f->zero = 0;
	if (nbr != nbr)
		sign = SPCE;
	slen = CHKCE(sign, 1, 0);
	add = pf_ldnbrlen(nbr, f) + slen;
	len = slen;
	if (f->wdth && !f->dash && !f->zero)
	{
		pf_left_width2(add, f);
		len += CHKMAX((int)f->fldwidth - add, 0);
		f->wdth = 0;
	}
	else if (f->wdth)
		f->fldwidth -= slen;
	ft_putchar(sign);
	return (parse_double(nbr, f) + len);
}

int			pf_check_conv_fdbl(char **format, va_list *list, t_pfflag *f)
{
	long double	nbr;

	(void)format;
	if (!f->prec)
	{
		f->precision = 6;
		f->prec = 1;
	}
	if (f->length != lL)
		nbr = va_arg(*list, double);
	else
		nbr = va_arg(*list, long double);
	if (nbr < 0)
	{
		nbr *= -1;
		return (hash_ldnbr(nbr, DASH, f));
	}
	if (f->plus)
		return (hash_ldnbr(nbr, PLUS, f));
	if (f->spce)
		return (hash_ldnbr(nbr, SPCE, f));
	return (parse_double(nbr, f));
}

int			pf_check_conv_ffdbl(char **format, va_list *list, t_pfflag *f)
{
	f->cap = 1;
	return (pf_conv_init(ft_tolower(**format))(format, list, f));
}
