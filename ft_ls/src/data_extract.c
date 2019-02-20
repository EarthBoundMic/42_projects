/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:44:00 by mkass             #+#    #+#             */
/*   Updated: 2018/08/30 15:44:15 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	single_data_extract(char *dir, t_lsflag flags,
													t_sort *d_data, t_sort tmp)
{
	ft_strcpy(d_data->relpath,
		checkstat(tmp.dr_file->d_name, &tmp.f_data, dir));
	ft_strcpy(d_data->lrelpath,
		checklstat(tmp.dr_file->d_name, &tmp.lf_data, dir));
	if (flags.l)
	{
		tmp.usr = getpwuid(tmp.lf_data.st_uid);
		tmp.grp = getgrgid(tmp.lf_data.st_gid);
	}
	data_alloc(d_data, tmp, flags);
}

void				file_extraction(char *file, t_lsflag flags, t_sort *d_data,
																	t_ls ls)
{
	char	*tmp_file;
	char	*tmp_dir;
	char	stmp[NAME_MAX];

	if ((tmp_dir = ft_fndpath(file)) == NULL)
		tmp_dir = ft_fndpath(CDIR);
	if ((tmp_file = ft_fndfile(file)) == NULL)
		tmp_file = ft_fndfile(CDIR);
	ft_strbcpy(stmp, tmp_dir);
	ls.dr_strm = opendir(tmp_dir);
	while ((ls.tmp_data.dr_file = readdir(ls.dr_strm)))
	{
		if (!ft_realstrcmp(ls.tmp_data.dr_file->d_name, tmp_file))
		{
			single_data_extract(stmp, flags, d_data, ls.tmp_data);
			break ;
		}
	}
	ft_strdel(&tmp_file);
	ft_strdel(&tmp_dir);
	closedir(ls.dr_strm);
}

t_sort				*data_extraction(char *dir, t_lsflag flags, int filecount)
{
	DIR		*dr_strm;
	t_sort	*d_data;
	t_sort	tmp;
	char	stmp[NAME_MAX];
	int		i;

	d_data = ft_memalloc(sizeof(t_sort) * filecount);
	dr_strm = opendir(dir);
	i = 0;
	while (i < filecount && (tmp.dr_file = readdir(dr_strm)))
	{
		ft_strbcpy(stmp, dir);
		single_data_extract(stmp, flags, &d_data[i], tmp);
		i++;
	}
	closedir(dr_strm);
	return (d_data);
}
