/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:14:32 by mkass             #+#    #+#             */
/*   Updated: 2018/08/10 14:37:42 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_uint(uintmax_t n, int base, unsigned int len, t_flag *f)
{
	CHKV1(f->prec, width_padding(len, f->precision, '0'));
	CHK1(!(!n && f->prec && !f->precision),
		CHKCE(f->hex, print_ubase(n, base), print_lbase(n, base)));
}

int			pf_parse_uint(uintmax_t n, int base, char *sign, t_flag *f)
{
	int len;
	int tlen;

	CHKV1(f->prec, f->zero = 0);
	len = unlen(n, base);
	CHKV4(f->wdth && !f->dash && f->zero,
		CHKE(f->prec, f->precision = CHKMAX(f->fldwidth, f->precision),
			f->precision = CHKMAX((int)f->fldwidth, len)),
		CHKV1(f->hash && sign != NULL && n, f->precision -= ft_strlen(sign)),
		f->prec = 1,
		f->wdth = 0);
	tlen = pf_nbrlen(n, base, sign, f);
	CHKV1(f->wdth && !f->dash, width_padding(tlen, f->fldwidth, ' '));
	CHKV1(f->hash && sign != NULL && n, ft_putstr(sign));
	print_uint(n, base, len, f);
	CHKV1(f->wdth && f->dash, width_padding(tlen, f->fldwidth, ' '));
	return (CHKCE(f->wdth, CHKMAX(tlen, (int)f->fldwidth), tlen));
}

int			pf_check_conv_oct(char **format, va_list *list, t_flag *f)
{
	uintmax_t	n;

	(void)format;
	n = pf_unsigned_nbr(list, f);
	CHK4(f->hash && !n && f->prec && !f->precision,
		CHKV1(f->wdth && !f->dash, width_padding(n, f->fldwidth,
									CHKCE(f->zero, '0', ' '))), ft_putchar('0'),
		CHKV1(f->wdth && f->dash, width_padding(n, f->fldwidth, ' ')),
		CHKCE(f->wdth, CHKMAX((int)f->fldwidth, 1), 1));
	CHKV2(f->hash && n, f->prec = 1,
		f->precision = CHKMAX(f->precision, unlen(n, OCT) + 1));
	return (pf_parse_uint(n, OCT, NULL, f));
}

int			pf_check_conv_hex(char **format, va_list *list, t_flag *f)
{
	uintmax_t	n;

	n = pf_unsigned_nbr(list, f);
	f->hex = 0;
	CHK2(**format == 'X', f->hex = 1, pf_parse_uint(n, HEX, "0X", f));
	return (pf_parse_uint(n, HEX, "0x", f));
}

int			pf_check_conv_bin(char **format, va_list *list, t_flag *f)
{
	uintmax_t	n;

	(void)format;
	n = pf_unsigned_nbr(list, f);
	return (pf_parse_uint(n, BIN, "0b", f));
}
