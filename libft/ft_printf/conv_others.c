/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:48:46 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:53:21 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				pf_check_conv_null(char **format, va_list *list, t_pfflag *f)
{
	int	ret;

	(void)list;
	(void)f;
	pf_left_width1(1, f);
	ft_putchar(**format);
	pf_right_width(1, f);
	ret = CHKMAX((int)f->fldwidth, 1);
	return (CHKCE(f->wdth, ret, 1));
}

int				pf_hash_nbr(uintmax_t n, int base, char *sign, t_pfflag *f)
{
	int	len;
	int	add;
	int	slen;

	slen = ft_strlen(sign);
	add = pf_nbrlen(n, base, NULL, f) + slen;
	len = slen;
	if (f->wdth && !f->dash && !f->zero)
	{
		pf_left_width2(add, f);
		len += CHKMAX((int)f->fldwidth - add, 0);
		f->wdth = 0;
	}
	else if (f->wdth)
		f->fldwidth -= slen;
	ft_putstr(sign);
	return (pf_parse_uint(n, base, NULL, f) + len);
}

uintmax_t		pf_unsigned_nbr(va_list *list, t_pfflag *f)
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

int				pf_check_conv_time(char **format, va_list *list, t_pfflag *f)
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
	pf_left_width2(len, f);
	ft_putstr(s);
	pf_right_width(len, f);
	ret = CHKMAX((int)f->fldwidth, len);
	return (CHKCE(f->wdth, ret, len));
}
