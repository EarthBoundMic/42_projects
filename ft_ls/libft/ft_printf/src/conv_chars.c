/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:52:05 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:48:08 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wchar(wchar_t s)
{
	CHKV2(s <= 0x7f, ft_putchar(s), RET);
	CHKV3(s <= 0x7ff, ft_putchar((s >> 6) + 0xc0),
		ft_putchar((s & 0x3f) + 0x80), RET);
	CHKV4(s <= 0xffff, ft_putchar((s >> 12) + 0xe0),
		ft_putchar(((s >> 6) & 0x3f) + 0x80),
		ft_putchar((s & 0x3f) + 0x80), RET);
	CHKV5(s <= 0x10ffff, ft_putchar((s >> 18) + 0xf0),
		ft_putchar(((s >> 12) & 0x3f) + 0x80),
		ft_putchar(((s >> 6) & 0x3f) + 0x80),
		ft_putchar((s & 0x3f) + 0x80), RET);
}

int		pf_check_conv_percent(char **format, va_list *list, t_flag *f)
{
	(void)format;
	(void)list;
	CHKV1(f->wdth && !f->dash, width_padding(1, f->fldwidth,
											CHKCE(f->zero, '0', ' ')));
	ft_putchar('%');
	CHKV1(f->wdth && f->dash, width_padding(1, f->fldwidth, ' '));
	return (CHKCE(f->wdth, CHKMAX(f->fldwidth, 1), 1));
}

int		pf_check_conv_char(char **format, va_list *list, t_flag *f)
{
	int	c;

	CHK1(f->length == l, pf_check_conv_wchar(format, list, f));
	c = va_arg(*list, int);
	CHKV1(f->wdth && !f->dash, width_padding(1, f->fldwidth,
											CHKCE(f->zero, '0', ' ')));
	ft_putchar(c);
	CHKV1(f->wdth && f->dash, width_padding(1, f->fldwidth, ' '));
	return (f->wdth ? CHKMAX(f->fldwidth, 1) : 1);
}

int		pf_check_conv_wchar(char **format, va_list *list, t_flag *f)
{
	wchar_t	s;
	int		len;

	(void)format;
	s = (wchar_t)va_arg(*list, wint_t);
	len = 0;
	CHKV1(s <= 0x10ffff, len = 4);
	CHKV1(s <= 0xffff, len = 3);
	CHKV1(s <= 0x7ff, len = 2);
	CHKV1(s <= 0x7f, len = 1);
	CHKV1(f->wdth && !f->dash, width_padding(len, f->fldwidth,
											CHKCE(f->zero, '0', ' ')));
	print_wchar(s);
	CHKV1(f->wdth && f->dash, width_padding(len, f->fldwidth, ' '));
	return (f->wdth ? CHKMAX(len, (int)f->fldwidth) : len);
}
