/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:25:04 by mkass             #+#    #+#             */
/*   Updated: 2018/09/28 15:25:17 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	wrongflag(char c)
{
	if (c != '1' && c != 'A' && c != 'F' && c != 'G' && c != 'R' && c != 'a' &&
		c != 'c' && c != 'f' && c != 'l' && c != 'r' && c != 't' && c != 'u')
	{
		ft_printf("./ft_ls: illegal option -- %c\n", c);
		ft_printf("usage: ./ft_ls [-AFGRacflrtu] [file ...]\n");
		exit(1);
	}
}

static void			flagcheck(t_lsflag *flags, char *s)
{
	int i;

	i = 0;
	while (s[++i])
	{
		CHKV1(s[i] == 'A' && !flags->a, flags->aa = 1);
		CHKV1(s[i] == 'F', flags->ff = 1);
		CHKV1(s[i] == 'G', flags->gg = 1);
		CHKV1(s[i] == 'R', flags->rr = 1);
		CHKV2(s[i] == 'a', flags->a = 1,
							flags->aa = 0);
		CHKV2(s[i] == 'c', flags->c = 1,
							flags->u = 0);
		CHKV1(s[i] == 'l', flags->l = 1);
		CHKV1(s[i] == 'r', flags->r = 1);
		CHKV1(s[i] == 't', flags->t = 1);
		CHKV2(s[i] == 'u', flags->u = 1,
							flags->c = 0);
		CHKV5(s[i] == 'f', flags->f = 1,
							flags->a = 1,
							flags->aa = 0,
							flags->t = 0,
							flags->r = 0);
		wrongflag(s[i]);
	}
}

void				param_parse(int ac, char **av, char **params,
															t_lsflag *flags)
{
	int i;
	int j;

	if (ac == 1)
		params[0] = ft_strdup(CDIR);
	else
	{
		i = 1;
		while (av[i] && av[i][0] == DASH && av[i][1])
			flagcheck(flags, av[i++]);
		if (ac == i)
			params[0] = ft_strdup(CDIR);
		else
		{
			j = 0;
			while (av[i])
				params[j++] = ft_strdup(av[i++]);
		}
	}
}
