/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:48:46 by mkass             #+#    #+#             */
/*   Updated: 2018/07/12 17:08:19 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_conv_null(char **format, va_list *list, t_pfflag *f)
{
	int	ret;

	(void)list;
	(void)f;
	left_width1(1, f);
	ft_putchar(**format);
	right_width(1, f);
	ret = CHKMAX((int)f->fldwidth, 1);
	return (CHKCE(f->wdth, ret, 1));
}

int				hash_nbr(uintmax_t n, int base, char *sign, t_pfflag *f)
{
	int	len;
	int	add;
	int	slen;

	slen = ft_strlen(sign);
	add = nbrlen(n, base, NULL, f) + slen;
	len = slen;
	if (f->wdth && !f->dash && !f->zero)
	{
		left_width2(add, f);
		len += CHKMAX((int)f->fldwidth - add, 0);
		f->wdth = 0;
	}
	else if (f->wdth)
		f->fldwidth -= slen;
	ft_putstr(sign);
	return (parse_uint(n, base, NULL, f) + len);
}

uintmax_t		unsigned_nbr(va_list *list, t_pfflag *f)
{
	uintmax_t conv_n;

	conv_n = va_arg(*list, uintmax_t);
	if (f->length == h)
		conv_n = (unsigned short)conv_n;
	else if (f->length == hh)
		conv_n = (unsigned char)conv_n;
	else if (f->length == l)
		conv_n = (unsigned long)conv_n;
	else if (f->length == ll)
		conv_n = (unsigned long long)conv_n;
	else if (f->length == j)
		conv_n = (uintmax_t)conv_n;
	else if (f->length == z)
		conv_n = (size_t)conv_n;
	else
		conv_n = (unsigned int)conv_n;
	return (conv_n);
}

int				check_conv_time(char **format, va_list *list, t_pfflag *f)
{
	int			len;
	time_t		clock;
	char		*s;
	int			ret;

	(void)format;
	(void)list;
	time(&clock);
	s = ctime(&clock);
	len = ft_strlen(s);
	s[--len] = NIL;
	left_width2(len, f);
	ft_putstr(s);
	right_width(len, f);
	ret = CHKMAX((int)f->fldwidth, len);
	return (CHKCE(f->wdth, ret, len));
}
