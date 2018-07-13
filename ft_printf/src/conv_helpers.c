/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:48:23 by mkass             #+#    #+#             */
/*   Updated: 2018/07/12 16:38:58 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			width_padding(int start, int width, char pad)
{
	WHLE(start < width, LST2(ft_putchar(pad), start++));
}

void			print_lbase(uintmax_t n, size_t base)
{
	char		*s;

	s = "0123456789abcdef";
	CHKE(n >= base, LST2(print_lbase(n / base, base),
						print_lbase(n % base, base)), ft_putchar(s[n]));
}

void			print_ubase(uintmax_t n, size_t base)
{
	char		*s;

	s = "0123456789ABCDEF";
	CHKE(n >= base, LST2(print_ubase(n / base, base),
						print_ubase(n % base, base)), ft_putchar(s[n]));
}

unsigned int	unlen(uintmax_t n, int base)
{
	int	i;

	i = 0;
	CHK1(!n, 1);
	WHLE(n, LST2(n /= base, i++));
	return (i);
}

unsigned int	nbrlen(uintmax_t n, int base, char *sign, t_flag *f)
{
	unsigned int	nlen;
	unsigned int	tlen;

	nlen = unlen(n, base);
	CHKE(!n && f->prec && !f->precision, tlen = 0,
		CHKE(f->prec, tlen = CHKMAX(nlen, f->precision),
			tlen = nlen));
	CHKV1(f->hash && sign != NULL && n,
		tlen += ft_strlen(sign));
	return (tlen);
}
