/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:52:05 by mkass             #+#    #+#             */
/*   Updated: 2018/07/11 20:49:57 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wchar(wchar_t s)
{
	if (s <= 0x7f)
		ft_putchar(s);
	else if (s <= 0x7ff)
	{
		ft_putchar((s >> 6) + 0xc0);
		ft_putchar((s & 0x3f) + 0x80);
	}
	else if (s <= 0xffff)
	{
		ft_putchar((s >> 12) + 0xe0);
		ft_putchar(((s >> 6) & 0x3f) + 0x80);
		ft_putchar((s & 0x3f) + 0x80);
	}
	else if (s <= 0x10ffff)
	{
		ft_putchar((s >> 18) + 0xf0);
		ft_putchar(((s >> 12) & 0x3f) + 0x80);
		ft_putchar(((s >> 6) & 0x3f) + 0x80);
		ft_putchar((s & 0x3f) + 0x80);
	}
}

int		check_conv_percent(char **format, va_list *list, t_pfflag *f)
{
	int	ret;

	(void)format;
	(void)list;
	left_width1(1, f);
	ft_putchar('%');
	right_width(1, f);
	ret = CHKMAX(f->fldwidth, 1);
	return (CHKCE(f->wdth, ret, 1));
}

int		check_conv_char(char **format, va_list *list, t_pfflag *f)
{
	int	c;
	int	ret;

	if (f->length == l)
		return (check_conv_wchar(format, list, f));
	c = va_arg(*list, int);
	left_width1(1, f);
	ft_putchar(c);
	right_width(1, f);
	ret = CHKMAX(f->fldwidth, 1);
	return (CHKCE(f->wdth, ret, 1));
}

int		check_conv_wchar(char **format, va_list *list, t_pfflag *f)
{
	wchar_t	s;
	int		len;
	int		ret;

	(void)format;
	s = (wchar_t)va_arg(*list, wint_t);
	len = 0;
	if (s <= 0x10ffff)
		len = 4;
	if (s <= 0xffff)
		len = 3;
	if (s <= 0x7ff)
		len = 2;
	if (s <= 0x7f)
		len = 1;
	print_wchar(s);
	right_width(len, f);
	ret = CHKMAX(len, (int)f->fldwidth);
	return (CHKCE(f->wdth, ret, len));
}
