/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:16:16 by mkass             #+#    #+#             */
/*   Updated: 2018/10/11 17:16:31 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	dir_color(mode_t ft_mode)
{
	if (ISWOT(ft_mode))
	{
		ft_putstr(BLKF);
		if (ISSTX(ft_mode))
			ft_putstr(GRNB);
		else
			ft_putstr(YLWB);
	}
	else
		ft_putstr(BLUF);
}

static inline void	special_color(mode_t ft_mode)
{
	if (ISBLK(ft_mode))
	{
		ft_putstr(BLUF);
		ft_putstr(CYNB);
	}
	else if (ISCHR(ft_mode))
	{
		ft_putstr(BLUF);
		ft_putstr(YLWB);
	}
	else if (ISXSR(ft_mode) && ISSTU(ft_mode))
	{
		ft_putstr(BLKF);
		ft_putstr(REDB);
	}
	else if (ISXGP(ft_mode) && ISSTG(ft_mode))
	{
		ft_putstr(BLKF);
		ft_putstr(CYNB);
	}
}

void				select_color(mode_t ft_mode)
{
	if (ISDIR(ft_mode))
		dir_color(ft_mode);
	else if (ISLNK(ft_mode))
		ft_putstr(MGNF);
	else if (ISSOC(ft_mode))
		ft_putstr(GRNF);
	else if (ISFIF(ft_mode))
		ft_putstr(YLWF);
	else if (ISXOT(ft_mode))
		ft_putstr(REDF);
	else
		special_color(ft_mode);
}
