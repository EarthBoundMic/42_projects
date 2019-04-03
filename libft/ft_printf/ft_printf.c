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

#include "libft.h"

static int		conversion_flag_check(char **format, va_list *list, t_pfflag *f)
{
	int				size;
	t_conv_check	check;

	if (**format == NIL)
		return (0);
	(*format)++;
	if (pf_check_first_pfflags(format, f) == NULL)
		return (-1);
	if (pf_check_field_width(format, list, f) == NULL)
		return (-1);
	if (pf_check_precision(format, list, f) == NULL)
		return (-1);
	if (pf_check_length(format, f) == NULL)
		return (-1);
	if (**format == NIL)
		return (0);
	if (pf_conv_init(**format) == NULL)
		check = pf_check_conv_null;
	else
		check = pf_conv_init(**format);
	size = check(format, list, f);
	(*format)++;
	return (size);
}

static size_t	print_str(char **fmt, size_t len)
{
	if (**fmt == CBGN)
	{
		if (pf_color_parse(fmt))
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
			ft_bzero(&flagcheck, sizeof(t_pfflag));
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
