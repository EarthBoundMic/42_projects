/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:13:49 by mkass             #+#    #+#             */
/*   Updated: 2018/07/12 16:29:16 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		assign_check(t_conv_check *check)
{
	int i;

	i = -1;
	while (++i < 128)
		check[i] = NULL;
	check['%'] = &check_conv_percent;
	check['b'] = &check_conv_bin;
	check['c'] = &check_conv_char;
	check['C'] = &check_conv_wchar;
	check['d'] = &check_conv_int;
	check['D'] = &check_conv_long;
	check['f'] = &check_conv_fdbl;
	check['F'] = &check_conv_ffdbl;
	check['i'] = &check_conv_int;
	check['o'] = &check_conv_oct;
	check['O'] = &check_conv_long;
	check['p'] = &check_conv_void;
	check['s'] = &check_conv_str;
	check['S'] = &check_conv_wstr;
	check['k'] = &check_conv_time;
	check['u'] = &check_conv_uint;
	check['U'] = &check_conv_long;
	check['x'] = &check_conv_hex;
	check['X'] = &check_conv_hex;
}

t_conv_check	conv_init(int c)
{
	static t_conv_check	*check = NULL;

	if (check == NULL)
	{
		check = malloc(sizeof(check) * 128);
		if (check == NULL)
		{
			ft_putendl("error: malloc failed");
			ft_exit();
		}
		else
			assign_check(check);
	}
	return (CHKCE(check[c] != NULL, check[c], NULL));
}
