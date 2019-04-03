/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:24:59 by mkass             #+#    #+#             */
/*   Updated: 2018/07/10 19:11:40 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		conversion_flag_check(char **format, va_list *list, t_pfflag *f)
{
	int				size;
	t_conv_check	check;

	if (**format == NIL)
		return (0);
	(*format)++;
	if (check_first_pfflags(format, f) == NULL)
		return (-1);
	if (check_field_width(format, list, f) == NULL)
		return (-1);
	if (check_precision(format, list, f) == NULL)
		return (-1);
	if (check_length(format, f) == NULL)
		return (-1);
	if (**format == NIL)
		return (0);
	if (conv_init(**format) == NULL)
		check = check_conv_null;
	else
		check = conv_init(**format);
	size = check(format, list, f);
	(*format)++;
	return (size);
}

static t_pfflag	flag_init(void)
{
	t_pfflag	flagcheck;

	flagcheck.hash = 0;
	flagcheck.zero = 0;
	flagcheck.dash = 0;
	flagcheck.spce = 0;
	flagcheck.plus = 0;
	flagcheck.wdth = 0;
	flagcheck.prec = 0;
	flagcheck.hex = 0;
	flagcheck.cap = 0;
	flagcheck.fldwidth = 0;
	flagcheck.precision = 0;
	flagcheck.length = 0;
	return (flagcheck);
}

static size_t	print_str(char **fmt, size_t len)
{
	if (**fmt == CBGN)
	{
		if (color_parse(fmt))
			return (len);
		else
		{
			ft_putchar(**fmt);
			(*fmt)++;
			return (len + 1);
		}
	}
	else if (**fmt != CONV)
	{
		ft_putchar(**fmt);
		(*fmt)++;
		return (len + 1);
	}
	return (len);
}

static int		check_args(const char *format, va_list *list, size_t len)
{
	t_pfflag	flagcheck;
	char		*fmt;
	size_t		list_len;

	CHK1(*format == NIL, len);
	fmt = (char *)format;
	while (*fmt)
	{
		if (*fmt == CBGN || *fmt != CONV)
			len = print_str(&fmt, len);
		else
		{
			flagcheck = flag_init();
			list_len = len;
			len += conversion_flag_check((char **)&fmt, list, &flagcheck);
			if (len < list_len)
				return (-1);
		}
	}
	return (len);
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
