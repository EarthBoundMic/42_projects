/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:27:53 by mkass             #+#    #+#             */
/*   Updated: 2018/10/10 15:30:04 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_colors.h"

static int	option_parse_settings(char *option)
{
	CHK2(!ft_realstrcmp(option, "RSTA"), ft_putstr(RSTA), 0);
	CHK2(!ft_realstrcmp(option, "BOLD"), ft_putstr(BOLD), 0);
	CHK2(!ft_realstrcmp(option, "FENT"), ft_putstr(FENT), 0);
	CHK2(!ft_realstrcmp(option, "ITLC"), ft_putstr(ITLC), 0);
	CHK2(!ft_realstrcmp(option, "UNDR"), ft_putstr(UNDR), 0);
	CHK2(!ft_realstrcmp(option, "SBLK"), ft_putstr(SBLK), 0);
	CHK2(!ft_realstrcmp(option, "FBLK"), ft_putstr(FBLK), 0);
	CHK2(!ft_realstrcmp(option, "CSWP"), ft_putstr(CSWP), 0);
	CHK2(!ft_realstrcmp(option, "CRSO"), ft_putstr(CRSO), 0);
	CHK2(!ft_realstrcmp(option, "NBOF"), ft_putstr(NBOF), 0);
	CHK2(!ft_realstrcmp(option, "NITL"), ft_putstr(NITL), 0);
	CHK2(!ft_realstrcmp(option, "NUND"), ft_putstr(NUND), 0);
	CHK2(!ft_realstrcmp(option, "NBLK"), ft_putstr(NBLK), 0);
	CHK2(!ft_realstrcmp(option, "NCRS"), ft_putstr(NCRS), 0);
	CHK2(!ft_realstrcmp(option, "DEFF"), ft_putstr(DEFF), 0);
	CHK2(!ft_realstrcmp(option, "DEFB"), ft_putstr(DEFB), 0);
	return (-1);
}

static int	option_parse_colors(char *option)
{
	CHK2(!ft_realstrcmp(option, "BLKF"), ft_putstr(BLKF), 0);
	CHK2(!ft_realstrcmp(option, "REDF"), ft_putstr(REDF), 0);
	CHK2(!ft_realstrcmp(option, "GRNF"), ft_putstr(GRNF), 0);
	CHK2(!ft_realstrcmp(option, "YLWF"), ft_putstr(YLWF), 0);
	CHK2(!ft_realstrcmp(option, "BLUF"), ft_putstr(BLUF), 0);
	CHK2(!ft_realstrcmp(option, "MGNF"), ft_putstr(MGNF), 0);
	CHK2(!ft_realstrcmp(option, "CYNF"), ft_putstr(CYNF), 0);
	CHK2(!ft_realstrcmp(option, "WHTF"), ft_putstr(WHTF), 0);
	CHK2(!ft_realstrcmp(option, "BLKB"), ft_putstr(BLKB), 0);
	CHK2(!ft_realstrcmp(option, "REDB"), ft_putstr(REDB), 0);
	CHK2(!ft_realstrcmp(option, "GRNB"), ft_putstr(GRNB), 0);
	CHK2(!ft_realstrcmp(option, "YLWB"), ft_putstr(YLWB), 0);
	CHK2(!ft_realstrcmp(option, "BLUB"), ft_putstr(BLUB), 0);
	CHK2(!ft_realstrcmp(option, "MGNB"), ft_putstr(MGNB), 0);
	CHK2(!ft_realstrcmp(option, "CYNB"), ft_putstr(CYNB), 0);
	CHK2(!ft_realstrcmp(option, "WHTB"), ft_putstr(WHTB), 0);
	return (-1);
}

static int	option_set(char *options)
{
	char	*seperator;
	char	*option;
	int		i;
	int		j;

	if ((seperator = ft_strchr(options, SPRT)) != NULL)
		option = ft_strsub(options, 0, seperator - options);
	else
		option = ft_strdup(options);
	i = option_parse_settings(option);
	j = option_parse_colors(option);
	ft_strdel(&option);
	if (seperator != NULL)
		option_set(seperator + 1);
	return (CHKCE(i && j, -1, 0));
}

static int	color_init(const char *format)
{
	char	*options;
	char	*start;
	char	*end;
	int		len;
	int		i;

	if ((start = ft_strchr(format, CBGN)) == NULL)
		return (-1);
	if ((end = ft_strchr(start, CEND)) == NULL || end - start < 0)
		return (-1);
	options = ft_strsub(format, start - format + 1, end - start - 1);
	if (pf_check_options(options))
	{
		ft_strclr(options);
		ft_strdel(&options);
		return (-1);
	}
	i = option_set(options);
	len = ft_strlen(options) + 2;
	ft_strclr(options);
	ft_strdel(&options);
	if (!i)
		return (len);
	else
		return (-1);
}

int			pf_color_parse(char **format)
{
	if (color_init(*format) < 0)
		return (0);
	while (**format != CEND)
		(*format)++;
	(*format)++;
	return (1);
}
