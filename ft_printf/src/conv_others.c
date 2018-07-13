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

int				check_conv_null(char **format, va_list *list, t_flag *f)
{
	(void)list;
	(void)f;
	CHKV1(f->wdth && !f->dash, width_padding(1, f->fldwidth,
											CHKCE(f->zero, '0', ' ')));
	ft_putchar(**format);
	CHKV1(f->wdth && f->dash, width_padding(1, f->fldwidth, ' '));
	return (CHKCE(f->wdth, CHKMAX((int)f->fldwidth, 1), 1));
}

int				hash_nbr(uintmax_t n, int base, char *sign, t_flag *f)
{
	int	len;
	int	add;
	int	slen;

	slen = ft_strlen(sign);
	add = nbrlen(n, base, NULL, f) + slen;
	len = slen;
	CHKE(f->wdth && !f->dash && !f->zero,
		LST3(width_padding(add, f->fldwidth, ' '),
			len += CHKMAX((int)f->fldwidth - add, 0),
			f->wdth = 0),
		CHKV1(f->wdth, f->fldwidth -= slen));
	ft_putstr(sign);
	return (parse_uint(n, base, NULL, f) + len);
}

uintmax_t		unsigned_nbr(va_list *list, t_flag *f)
{
	uintmax_t conv_n;

	conv_n = va_arg(*list, uintmax_t);
	CHK2(f->length == h, conv_n = (unsigned short)conv_n, conv_n);
	CHK2(f->length == hh, conv_n = (unsigned char)conv_n, conv_n);
	CHK2(f->length == l, conv_n = (unsigned long)conv_n, conv_n);
	CHK2(f->length == ll, conv_n = (unsigned long long)conv_n, conv_n);
	CHK2(f->length == j, conv_n = (uintmax_t)conv_n, conv_n);
	CHK2(f->length == z, conv_n = (size_t)conv_n, conv_n);
	conv_n = (unsigned int)conv_n;
	return (conv_n);
}

int				check_conv_time(char **format, va_list *list, t_flag *f)
{
	int			i;
	time_t		clock;
	char		*s;

	(void)format;
	(void)list;
	time(&clock);
	s = ctime(&clock);
	i = ft_strlen(s);
	s[--i] = '\0';
	CHKV1(f->wdth && !f->dash, width_padding(i, f->fldwidth, ' '));
	ft_putstr(s);
	CHKV1(f->wdth && f->dash, width_padding(i, f->fldwidth, ' '));
	return (CHKCE(f->wdth, CHKMAX((int)f->fldwidth, i), i));
}
