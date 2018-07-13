/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:41:53 by mkass             #+#    #+#             */
/*   Updated: 2018/07/12 16:31:52 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_first_flags(char **format, t_flag *f)
{
	CHK2(**format == '#' || **format == '0' || **format == '-' ||
		**format == ' ' || **format == '+',
		LST3(LST5(CHKV1(**format == '#', f->hash = 1),
				CHKV1(**format == '0', f->zero = 1),
				CHKV1(**format == '-', f->dash = 1),
				CHKV1(**format == ' ', f->spce = 1),
				CHKV1(**format == '+', f->plus = 1)),
			(*format)++, CHKV1(f->dash, f->zero = 0)),
		check_first_flags(format, f));
	return (*format);
}

char	*check_field_width(char **format, t_flag *f)
{
	f->fldwidth = 0;
	CHKV2(ft_isdigit(**format), f->wdth = 1, WHLE(ft_isdigit(**format),
						f->fldwidth = f->fldwidth * 10 + (*(*format)++ - '0')));
	return (*format);
}

char	*check_precision(char **format, t_flag *f)
{
	f->precision = 0;
	CHKV3(**format == '.', f->prec = 1, (*format)++, WHLE(ft_isdigit(**format),
		LST2(f->precision = f->precision * 10 + **format - '0', (*format)++)));
	return (*format);
}

char	*check_length(char **format, t_flag *f)
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
