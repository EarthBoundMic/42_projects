/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:47:06 by mkass             #+#    #+#             */
/*   Updated: 2018/07/10 18:46:15 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	signed_nbr(va_list *list, t_pfflag *f)
{
	intmax_t	conv_n;

	conv_n = va_arg(*list, intmax_t);
	if (f->length == h)
		conv_n = (short)conv_n;
	else if (f->length == hh)
		conv_n = (char)conv_n;
	else if (f->length == l)
		conv_n = (long)conv_n;
	else if (f->length == ll)
		conv_n = (long long)conv_n;
	else if (f->length == j)
		conv_n = (intmax_t)conv_n;
	else if (f->length == z)
		conv_n = (ssize_t)conv_n;
	else
		conv_n = (int)conv_n;
	return (conv_n);
}

int				check_conv_int(char **format, va_list *list, t_pfflag *f)
{
	intmax_t	n;

	(void)format;
	if (f->prec)
		f->zero = 0;
	n = signed_nbr(list, f);
	if (n < 0)
	{
		n *= -1;
		return (hash_nbr(n, DEC, "-", f));
	}
	if (f->plus)
		return (hash_nbr(n, DEC, "+", f));
	if (f->spce)
		return (hash_nbr(n, DEC, " ", f));
	return (parse_uint(n, DEC, NULL, f));
}

int				check_conv_long(char **format, va_list *list, t_pfflag *f)
{
	f->length = l;
	return (conv_init(ft_tolower(**format))(format, list, f));
}

int				check_conv_uint(char **format, va_list *list, t_pfflag *f)
{
	uintmax_t	n;

	(void)format;
	n = unsigned_nbr(list, f);
	return (parse_uint(n, DEC, NULL, f));
}

int				check_conv_void(char **format, va_list *list, t_pfflag *f)
{
	uintmax_t	n;

	(void)format;
	f->length = z;
	f->hex = 0;
	if (f->prec)
		f->zero = 0;
	n = unsigned_nbr(list, f);
	return (hash_nbr(n, HEX, "0x", f));
}
