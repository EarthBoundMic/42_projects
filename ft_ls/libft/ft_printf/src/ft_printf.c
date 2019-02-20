/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:24:59 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:57:09 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		conversion_flag_check(char **format, va_list *list, t_flag *f)
{
	int				size;
	t_conv_check	check;

	CHK1(**format == '\0', 0);
	(*format)++;
	CHK1(pf_check_first_flags(format, f) == NULL, -1);
	CHK1(check_field_width(format, list, f) == NULL, -1);
	CHK1(check_precision(format, list, f) == NULL, -1);
	CHK1(pf_check_length(format, f) == NULL, -1);
	CHK1(**format == '\0', 0);
	CHKE(pf_conv_init(**format) == NULL, check = pf_check_conv_null,
		check = pf_conv_init(**format));
	size = check(format, list, f);
	(*format)++;
	return (size);
}

static t_flag	flag_init(void)
{
	t_flag	flagcheck;

	flagcheck.hash = 0;
	flagcheck.zero = 0;
	flagcheck.dash = 0;
	flagcheck.spce = 0;
	flagcheck.plus = 0;
	flagcheck.wdth = 0;
	flagcheck.prec = 0;
	flagcheck.hex = 0;
	flagcheck.fldwidth = 0;
	flagcheck.precision = 0;
	flagcheck.length = 0;
	return (flagcheck);
}

static int		check_args(const char *format, va_list *list, size_t len)
{
	char	*find_arg;
	t_flag	flagcheck;
	size_t	list_len;

	CHK1(*format == '\0', len);
	find_arg = ft_strchr(format, '%');
	CHK2(find_arg == NULL, ft_putstr(format), len + ft_strlen(format));
	CHK2(find_arg > format, ft_putnstr(format, find_arg - format),
		check_args(find_arg, list, len + (find_arg - format)));
	flagcheck = flag_init();
	return (CHKCE((list_len = conversion_flag_check((char **)&format, list,
													&flagcheck)) < 0, -1,
				check_args(format, list, len + list_len)));
}

int				ft_printf(const char *format, ...)
{
	va_list	list;
	int		length;

	va_start(list, format);
	length = check_args(format, &list, 0);
	va_end(list);
	return (length);
}
