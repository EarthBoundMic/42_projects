/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:00:22 by mkass             #+#    #+#             */
/*   Updated: 2018/10/04 14:00:33 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*perm_check(char *path, char *relpath, t_ls *ls)
{
	char	*tmp;

	if (stat(path, &ls->f_data))
		return (error_handling2(path));
	tmp = ft_fndfile(path);
	if ((ls->dr_strm = opendir(path)) == NULL)
	{
		if (ISDIR(ls->f_data.st_mode))
			return (error_handling1(tmp));
		if ((ls->dr_strm = opendir(relpath)) == NULL)
			ls->dr_strm = opendir(".");
	}
	if (ISDIR(ls->f_data.st_mode))
	{
		if (tmp)
			ft_strdel(&tmp);
		closedir(ls->dr_strm);
		return ("");
	}
	return (tmp);
}

static int			filecheck(t_ls ls, t_lsflag *flags)
{
	flags->chk = 0;
	if (!ISDIR(ls.f_data.st_mode))
	{
		flags->chk = 1;
		return (0);
	}
	return (1);
}

int					wrongname(char *path, t_lsflag flags)
{
	char	buf[NAME_MAX];
	char	*dir;
	char	*file;
	int		chk;
	t_ls	ls;

	dir = ft_fndpath(path);
	file = perm_check(path, dir, &ls);
	if (file == NULL || !ft_realstrcmp(file, ""))
		return (no_file(&dir, file));
	while ((ls.dr_file = readdir(ls.dr_strm)))
	{
		ft_bzero(buf, NAME_MAX);
		CHKE(dir, ft_strcat(buf, dir), ft_strcat(buf, CDIR));
		ft_bzero(ls.relpath, PATH_MAX);
		ls.f_data = stat_select(buf, ls.dr_file->d_name, flags,
			ls.relpath);
		CHKV1(!ft_realstrcmp(ls.dr_file->d_name, file), BRK);
	}
	LST2(ft_strdel(&file), ft_strdel(&dir));
	chk = filecheck(ls, &flags);
	closedir(ls.dr_strm);
	return (chk);
}
