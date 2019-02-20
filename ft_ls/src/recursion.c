/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:15:49 by mkass             #+#    #+#             */
/*   Updated: 2018/09/11 19:16:03 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	rec_a_flag(t_sort *d_data, t_lsflag flags, int i, int filecount)
{
	while (i < filecount && (CUR(d_data[i].d_name) || PRV(d_data[i].d_name)))
		i++;
	while (!flags.aa && !flags.a && i < filecount && d_data[i].d_name[0] == '.')
		i++;
	return (i);
}

static char	*new_dir(char *dir, char *d_name)
{
	char	rpath[PATH_MAX];

	ft_bzero(rpath, PATH_MAX);
	ft_strcpy(rpath, dir);
	return (ft_strdup(relpath(rpath, d_name)));
}

void		rr_flag(char *dir, t_ls ls, t_lsflag flags)
{
	char	*path;
	int		i;

	i = -1;
	while (++i < ls.filecount)
	{
		i = rec_a_flag(ls.d_data, flags, i, ls.filecount);
		if (i < ls.filecount && (ISDIR(ls.d_data[i].ft_mode) ||
												ISDIR(ls.d_data[i].lft_mode)))
		{
			ft_printf("\n%s:\n", (path = new_dir(dir, ls.d_data[i].d_name)));
			if (wrongname(path, flags) < 0)
				continue ;
			ft_ls(path, flags);
			ft_strdel(&path);
		}
	}
}
