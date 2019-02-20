/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 20:10:39 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:54:49 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	widestr_precision(wchar_t *s, int prec, int ret)
{
	CHK1(*s == '\0' || prec == 0, ret);
	CHK1(*s <= 0x7f, widestr_precision(s + 1, prec - 1, ret + 1));
	CHK1(*s <= 0x7ff, widestr_precision(s + 1, prec - 2, ret + 2));
	CHK1(*s <= 0xffff, widestr_precision(s + 1, prec - 3, ret + 3));
	CHK1(*s <= 0x10ffff, widestr_precision(s + 1, prec - 4, ret + 4));
	return (ret);
}

static int	wide_strlen(wchar_t *s)
{
	int ret;

	ret = 0;
	WHLE(*s, LST2(CHKE(*s <= 0x7f, ret++,
					CHKE(*s <= 0x7ff, ret += 2,
						CHKE(*s <= 0xffff, ret += 3,
							CHKV1(*s <= 0x10ffff, ret += 4)))), s++));
	return (ret);
}

static int	nstrlen(char *s, int n)
{
	int i;

	i = 0;
	WHLE(s[i] && i < n, i++);
	return (i);
}

int			pf_check_conv_wstr(char **format, va_list *list, t_flag *f)
{
	wchar_t	*s;
	int		len;
	int		i;

	(void)format;
	i = 0;
	s = va_arg(*list, wchar_t*);
	CHKV1(s == NULL, s = L"(null)");
	len = CHKCE(f->prec, widestr_precision(s, f->precision, 0), wide_strlen(s));
	CHKV1(f->wdth && !f->dash, width_padding(len, f->fldwidth,
											CHKCE(f->zero, '0', ' ')));
	CHKV1((f->prec && f->precision) || !f->prec,
		WHLE(s[i] && i < len, print_wchar(s[i++])));
	CHKV1(f->wdth && f->dash, width_padding(len, f->fldwidth, ' '));
	return (CHKCE(f->wdth, CHKMAX((int)f->fldwidth, len), len));
}

int			pf_check_conv_str(char **format, va_list *list, t_flag *f)
{
	char	*s;
	int		len;

	CHK1(f->length == l, pf_check_conv_wstr(format, list, f));
	s = va_arg(*list, char*);
	CHKV1(s == NULL, s = "(null)");
	len = CHKCE(f->prec, nstrlen(s, f->precision), ft_strlen(s));
	CHKV1(f->wdth && !f->dash, width_padding(len, f->fldwidth,
											CHKCE(f->zero, '0', ' ')));
	ft_putnstr(s, len);
	CHKV1(f->wdth && f->dash, width_padding(len, f->fldwidth, ' '));
	return (CHKCE(f->wdth, CHKMAX((int)f->fldwidth, len), len));
}
