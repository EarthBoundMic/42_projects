/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:14:32 by mkass             #+#    #+#             */
/*   Updated: 2018/07/12 16:35:33 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_uint(uintmax_t n, int base, unsigned int len, t_pfflag *f)
{
	if (f->prec)
		width_padding(len, f->precision, '0');
	if (!(!n && f->prec && !f->precision))
		CHKCE(f->hex, print_ubase(n, base), print_lbase(n, base));
}

int			parse_uint(uintmax_t n, int base, char *sign, t_pfflag *f)
{
	int len;
	int tlen;

	if (f->prec)
		f->zero = 0;
	len = unlen(n, base);
	if (f->wdth && !f->dash && f->zero)
	{
		if (f->prec)
			f->precision = CHKMAX(f->fldwidth, f->precision);
		else
			f->precision = CHKMAX((int)f->fldwidth, len);
		if (f->hash && sign != NULL && n)
			f->precision -= ft_strlen(sign);
		f->prec = 1;
		f->wdth = 0;
	}
	tlen = nbrlen(n, base, sign, f);
	left_width2(tlen, f);
	if (f->hash && sign != NULL && n)
		ft_putstr(sign);
	print_uint(n, base, len, f);
	right_width(tlen, f);
	len = CHKMAX(tlen, (int)f->fldwidth);
	return (CHKCE(f->wdth, len, tlen));
}

int			check_conv_oct(char **format, va_list *list, t_pfflag *f)
{
	uintmax_t	n;
	int			ret;

	(void)format;
	n = unsigned_nbr(list, f);
	if (f->hash && !n && f->prec && !f->precision)
	{
		left_width1(n, f);
		ft_putchar(ZERO);
		right_width(n, f);
		ret = CHKMAX((int)f->fldwidth, 1);
		return (CHKCE(f->wdth, ret, 1));
	}
	if (f->hash && n)
	{
		f->prec = 1;
		f->precision = CHKMAX(f->precision, unlen(n, OCT) + 1);
	}
	return (parse_uint(n, OCT, NULL, f));
}

int			check_conv_hex(char **format, va_list *list, t_pfflag *f)
{
	uintmax_t	n;

	n = unsigned_nbr(list, f);
	f->hex = 0;
	if (**format == 'X')
	{
		f->hex = 1;
		return (parse_uint(n, HEX, "0X", f));
	}
	return (parse_uint(n, HEX, "0x", f));
}

int			check_conv_bin(char **format, va_list *list, t_pfflag *f)
{
	uintmax_t	n;

	(void)format;
	n = unsigned_nbr(list, f);
	return (parse_uint(n, BIN, "0b", f));
}
