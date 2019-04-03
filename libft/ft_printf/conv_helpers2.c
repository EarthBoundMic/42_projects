/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_helpers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:40:02 by mkass             #+#    #+#             */
/*   Updated: 2018/10/09 16:40:17 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			pf_left_width1(int len, t_pfflag *f)
{
	if (f->wdth && !f->dash)
		pf_width_padding(len, f->fldwidth, CHKCE(f->zero, ZERO, SPCE));
}

void			pf_left_width2(int len, t_pfflag *f)
{
	if (f->wdth && !f->dash)
		pf_width_padding(len, f->fldwidth, SPCE);
}

void			pf_right_width(int len, t_pfflag *f)
{
	if (f->wdth && f->dash)
		pf_width_padding(len, f->fldwidth, SPCE);
}

unsigned int	pf_ldnbrlen(long double nbr, t_pfflag *f)
{
	unsigned int	nlen;
	unsigned int	tlen;

	nlen = ft_ldlen(nbr, f->precision);
	if (!nbr && f->prec && !f->precision)
		tlen = 0;
	else
		tlen = nlen;
	if (f->hash && !f->precision)
		tlen += 1;
	return (tlen);
}

int				pf_wide_strlen_precision(wchar_t *s, int prec, int ret)
{
	if (*s == NIL || prec <= 0)
		return (ret);
	if (*s <= 0x7f)
		return (pf_wide_strlen_precision(s + 1, prec - 1, ret + 1));
	if (*s <= 0x7ff)
		return (pf_wide_strlen_precision(s + 2, prec - 2, ret + 1));
	if (*s <= 0xffff)
		return (pf_wide_strlen_precision(s + 3, prec - 3, ret + 1));
	if (*s <= 0x10ffff)
		return (pf_wide_strlen_precision(s + 4, prec - 4, ret + 1));
	return (ret);
}
