/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:23:46 by mkass             #+#    #+#             */
/*   Updated: 2018/11/12 15:24:12 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	option_check_settings(char *option)
{
	CHK1(!ft_realstrcmp(option, "RSTA"), 0);
	CHK1(!ft_realstrcmp(option, "BOLD"), 0);
	CHK1(!ft_realstrcmp(option, "FENT"), 0);
	CHK1(!ft_realstrcmp(option, "ITLC"), 0);
	CHK1(!ft_realstrcmp(option, "UNDR"), 0);
	CHK1(!ft_realstrcmp(option, "SBLK"), 0);
	CHK1(!ft_realstrcmp(option, "FBLK"), 0);
	CHK1(!ft_realstrcmp(option, "CSWP"), 0);
	CHK1(!ft_realstrcmp(option, "CRSO"), 0);
	CHK1(!ft_realstrcmp(option, "NBOF"), 0);
	CHK1(!ft_realstrcmp(option, "NITL"), 0);
	CHK1(!ft_realstrcmp(option, "NUND"), 0);
	CHK1(!ft_realstrcmp(option, "NBLK"), 0);
	CHK1(!ft_realstrcmp(option, "NCRS"), 0);
	CHK1(!ft_realstrcmp(option, "DEFF"), 0);
	CHK1(!ft_realstrcmp(option, "DEFB"), 0);
	return (-1);
}

static int	option_check_colors(char *option)
{
	CHK1(!ft_realstrcmp(option, "BLKF"), 0);
	CHK1(!ft_realstrcmp(option, "REDF"), 0);
	CHK1(!ft_realstrcmp(option, "GRNF"), 0);
	CHK1(!ft_realstrcmp(option, "YLWF"), 0);
	CHK1(!ft_realstrcmp(option, "BLUF"), 0);
	CHK1(!ft_realstrcmp(option, "MGNF"), 0);
	CHK1(!ft_realstrcmp(option, "CYNF"), 0);
	CHK1(!ft_realstrcmp(option, "WHTF"), 0);
	CHK1(!ft_realstrcmp(option, "BLKB"), 0);
	CHK1(!ft_realstrcmp(option, "REDB"), 0);
	CHK1(!ft_realstrcmp(option, "GRNB"), 0);
	CHK1(!ft_realstrcmp(option, "YLWB"), 0);
	CHK1(!ft_realstrcmp(option, "BLUB"), 0);
	CHK1(!ft_realstrcmp(option, "MGNB"), 0);
	CHK1(!ft_realstrcmp(option, "CYNB"), 0);
	CHK1(!ft_realstrcmp(option, "WHTB"), 0);
	return (-1);
}

static void	free_split(char **del)
{
	size_t len;
	size_t i;

	i = -1;
	len = ft_splitlen(del);
	while (++i < len)
		ft_strdel(&del[i]);
	free(del);
}

int			check_options(char *options)
{
	char	**check;
	size_t	len;
	size_t	i;

	check = ft_strsplit(options, SPRT);
	len = ft_splitlen(check);
	i = -1;
	while (++i < len)
	{
		if (option_check_settings(check[i]) && option_check_colors(check[i]))
		{
			free_split(check);
			return (-1);
		}
	}
	free_split(check);
	return (0);
}
