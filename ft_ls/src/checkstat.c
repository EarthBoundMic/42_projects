/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:16:23 by mkass             #+#    #+#             */
/*   Updated: 2018/09/10 17:16:34 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*relpath(char *path, char *file)
{
	char	*a;
	int		size;

	a = path;
	size = ft_strlen(path);
	if (a[size - 1] != '/' && size > 0)
		a = ft_strcat(a, "/");
	a = ft_strcat(a, file);
	return (a);
}

char	*checkstat(char *d_name, t_stt *f_data, char *dir)
{
	char	*path;
	char	tmp[NAME_MAX];
	int		chk;

	if (ft_realstrcmp(dir, CDIR))
	{
		ft_strcpy(tmp, dir);
		path = relpath(tmp, d_name);
		chk = stat(path, f_data);
	}
	else
	{
		path = d_name;
		chk = stat(d_name, f_data);
	}
	return (!chk ? path : " ");
}

char	*checklstat(char *d_name, t_stt *f_data, char *dir)
{
	char	*path;
	char	tmp[NAME_MAX];
	int		chk;

	if (ft_realstrcmp(dir, CDIR))
	{
		ft_strcpy(tmp, dir);
		path = relpath(tmp, d_name);
		chk = lstat(path, f_data);
	}
	else
	{
		path = d_name;
		chk = lstat(d_name, f_data);
	}
	return (!chk ? path : " ");
}

t_stt	stat_select(char *dir, char *d_name, t_lsflag flags, char *relpath)
{
	t_stt	f_data;

	if (flags.l || flags.ff)
		ft_strcpy(relpath, checklstat(d_name, &f_data, dir));
	else
		ft_strcpy(relpath, checkstat(d_name, &f_data, dir));
	return (f_data);
}
