/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:13:49 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:51:30 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		assign_check(t_conv_check *check)
{
	int i;

	i = -1;
	while (++i < 128)
		check[i] = NULL;
	check['%'] = &pf_check_conv_percent;
	check['b'] = &pf_check_conv_bin;
	check['c'] = &pf_check_conv_char;
	check['C'] = &pf_check_conv_wchar;
	check['d'] = &pf_check_conv_int;
	check['D'] = &pf_check_conv_long;
	check['f'] = &pf_check_conv_fdbl;
	check['F'] = &pf_check_conv_ffdbl;
	check['i'] = &pf_check_conv_int;
	check['o'] = &pf_check_conv_oct;
	check['O'] = &pf_check_conv_long;
	check['p'] = &pf_check_conv_void;
	check['s'] = &pf_check_conv_str;
	check['S'] = &pf_check_conv_wstr;
	check['k'] = &pf_check_conv_time;
	check['u'] = &pf_check_conv_uint;
	check['U'] = &pf_check_conv_long;
	check['x'] = &pf_check_conv_hex;
	check['X'] = &pf_check_conv_hex;
}

t_conv_check	pf_conv_init(int c)
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
