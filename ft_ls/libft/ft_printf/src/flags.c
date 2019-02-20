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

#include "ft_printf.h"

char	*pf_check_first_flags(char **format, t_flag *f)
{
	CHK2(**format == '#' || **format == '0' || **format == '-' ||
		**format == ' ' || **format == '+',
		LST3(LST5(CHKV1(**format == '#', f->hash = 1),
				CHKV1(**format == '0', f->zero = 1),
				CHKV1(**format == '-', f->dash = 1),
				CHKV1(**format == ' ', f->spce = 1),
				CHKV1(**format == '+', f->plus = 1)),
			(*format)++, CHKV1(f->dash, f->zero = 0)),
		pf_check_first_flags(format, f));
	return (*format);
}

char	*check_field_width(char **format, va_list *list, t_flag *f)
{
	int	chk;

	f->fldwidth = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		CHKV5(**format == '*', (*format)++, chk = va_arg(*list, int),
			CHKV1(chk < 0, f->dash = 1),
			f->fldwidth = CHKABS(chk),
			f->wdth = 1);
		CHKV3(ft_isdigit(**format), f->wdth = 1,
			f->fldwidth = 0, WHLE(ft_isdigit(**format),
			f->fldwidth = f->fldwidth * 10 + (*(*format)++ - '0')));
	}
	return (*format);
}

char	*check_precision(char **format, va_list *list, t_flag *f)
{
	int chk;

	f->precision = 0;
	CHKV3(**format == '.', f->prec = 1, (*format)++, CHKE(**format == '*',
		LST3((*format)++, chk = va_arg(*list, int),
			CHKE(chk >= 0, f->precision = chk,
				f->prec = 0)), WHLE(ft_isdigit(**format),
		LST2(f->precision = f->precision * 10 + **format - '0',
			(*format)++))));
	return (*format);
}

char	*pf_check_length(char **format, t_flag *f)
{
	CHK2(**format == 'h' && *(*format + 1) == 'h', f->length = hh,
		*format += 2);
	CHK2(**format == 'l' && *(*format + 1) == 'l', f->length = ll,
		*format += 2);
	CHK5(**format == 'h' || **format == 'l' || **format == 'j' ||
		**format == 'z',
		CHKV1(**format == 'h', f->length = h),
		CHKV1(**format == 'l', f->length = l),
		CHKV1(**format == 'j', f->length = j),
		CHKV1(**format == 'z', f->length = z), (*format)++);
	return (*format);
}
