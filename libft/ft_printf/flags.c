/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:41:53 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:55:36 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_check_first_pfflags(char **format, t_pfflag *f)
{
	if (**format == HASH || **format == ZERO || **format == DASH ||
		**format == SPCE || **format == PLUS)
	{
		if (**format == HASH)
			f->hash = 1;
		if (**format == ZERO)
			f->zero = 1;
		if (**format == DASH)
			f->dash = 1;
		if (**format == SPCE)
			f->spce = 1;
		if (**format == PLUS)
			f->plus = 1;
		if (f->dash)
			f->zero = 0;
		(*format)++;
		return (pf_check_first_pfflags(format, f));
	}
	return (*format);
}

char	*pf_check_field_width(char **format, va_list *list, t_pfflag *f)
{
	int	chk;

	f->fldwidth = 0;
	while (**format == STAR || ft_isdigit(**format))
	{
		if (**format == STAR)
		{
			(*format)++;
			chk = va_arg(*list, int);
			if (chk < 0)
				f->dash = 1;
			f->fldwidth = CHKABS(chk);
			f->wdth = 1;
		}
		if (ft_isdigit(**format))
		{
			f->wdth = 1;
			f->fldwidth = 0;
			while (ft_isdigit(**format))
				f->fldwidth = f->fldwidth * 10 + (*(*format)++ - ZERO);
		}
	}
	return (*format);
}

char	*pf_check_precision(char **format, va_list *list, t_pfflag *f)
{
	int chk;

	f->precision = 0;
	if (**format == PRID)
	{
		f->prec = 1;
		(*format)++;
		if (**format == STAR)
		{
			(*format)++;
			chk = va_arg(*list, int);
			if (chk >= 0)
				f->precision = chk;
			else
				f->prec = 0;
		}
		while (ft_isdigit(**format))
			f->precision = f->precision * 10 + (*(*format)++ - ZERO);
	}
	return (*format);
}

char	*pf_check_length(char **format, t_pfflag *f)
{
	if ((**format == HALF && *(*format + 1) == HALF) ||
		((**format == LNGG && *(*format + 1) == LNGG)))
	{
		if (**format == HALF && *(*format + 1) == HALF)
			f->length = hh;
		else if ((**format == LNGG && *(*format + 1) == LNGG))
			f->length = ll;
		return (*format += 2);
	}
	if (**format == HALF || **format == LNGG || **format == INTM ||
		**format == SIZT || **format == LNGL)
	{
		if (**format == HALF)
			f->length = h;
		if (**format == LNGG)
			f->length = l;
		if (**format == INTM)
			f->length = j;
		if (**format == SIZT)
			f->length = z;
		if (**format == LNGL)
			f->length = lL;
		(*format)++;
	}
	return (*format);
}
