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

#include "libft.h"

static int	widestr_precision(wchar_t *s, int prec, int ret)
{
	if (*s == NIL || prec <= 0)
		return (ret);
	if (*s <= 0x7f)
		return (widestr_precision(s + 1, prec - 1, ret + 1));
	if (*s <= 0x7ff)
		return (widestr_precision(s + 2, prec - 2, ret + 2));
	if (*s <= 0xffff)
		return (widestr_precision(s + 3, prec - 3, ret + 3));
	if (*s <= 0x10ffff)
		return (widestr_precision(s + 4, prec - 4, ret + 4));
	return (ret);
}

static int	wide_strlen(wchar_t *s)
{
	int ret;

	ret = 0;
	while (*s)
	{
		if (*s <= 0x7f)
			ret += 1;
		else if (*s <= 0x7ff)
			ret += 2;
		else if (*s <= 0xffff)
			ret += 3;
		else if (*s <= 0x10ffff)
			ret += 4;
		s++;
	}
	return (ret);
}

static int	nstrlen(char *s, int n)
{
	int i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

int			pf_check_conv_wstr(char **format, va_list *list, t_pfflag *f)
{
	wchar_t	*s;
	int		len;
	int		i;
	int		ret;
	int		tlen;

	(void)format;
	i = 0;
	s = va_arg(*list, wchar_t*);
	if (s == NULL)
		s = L"(null)";
	len = CHKCE(f->prec, pf_wide_strlen_precision(s, f->precision, 0),
													wide_strlen(s));
	pf_left_width1(len, f);
	if ((f->prec && f->precision) || !f->prec)
		while (s[i] && i < len)
			pf_print_wchar(s[i++]);
	pf_right_width(len, f);
	tlen = CHKCE(f->prec, widestr_precision(s, f->precision, 0), len);
	ret = CHKMAX((int)f->fldwidth, tlen);
	return (CHKCE(f->wdth, ret, tlen));
}

int			pf_check_conv_str(char **format, va_list *list, t_pfflag *f)
{
	char	*s;
	int		len;
	int		ret;

	if (f->length == l)
		return (pf_check_conv_wstr(format, list, f));
	s = va_arg(*list, char*);
	if (s == NULL)
		s = "(null)";
	len = CHKCE(f->prec, nstrlen(s, f->precision), ft_strlen(s));
	pf_left_width1(len, f);
	ft_putnstr(s, len);
	pf_right_width(len, f);
	ret = CHKMAX((int)f->fldwidth, len);
	return (CHKCE(f->wdth, ret, len));
}
