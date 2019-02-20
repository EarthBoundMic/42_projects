/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:04:33 by mkass             #+#    #+#             */
/*   Updated: 2018/10/04 13:04:46 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	time_alloc(t_sort *d_data, t_stt f_data)
{
	d_data->ft_atime = f_data.st_atimespec.tv_sec;
	d_data->ft_ctime = f_data.st_ctimespec.tv_sec;
	d_data->ft_mtime = f_data.st_mtimespec.tv_sec;
	d_data->ft_natime = f_data.st_atimespec.tv_nsec;
	d_data->ft_nctime = f_data.st_ctimespec.tv_nsec;
	d_data->ft_nmtime = f_data.st_mtimespec.tv_nsec;
}

inline void			data_alloc(t_sort *d_data, t_sort tmp, t_lsflag flags)
{
	ft_strbcpy(d_data->d_name, tmp.dr_file->d_name);
	d_data->ft_mode = tmp.f_data.st_mode;
	d_data->lft_mode = tmp.lf_data.st_mode;
	if (flags.l)
	{
		time_alloc(d_data, tmp.lf_data);
		d_data->ft_nlink = tmp.lf_data.st_nlink;
		d_data->ft_uid = tmp.lf_data.st_uid;
		d_data->ft_gid = tmp.lf_data.st_gid;
		d_data->ft_rdev = tmp.lf_data.st_rdev;
		d_data->ft_size = tmp.lf_data.st_size;
		d_data->ft_blocks = tmp.lf_data.st_blocks;
		ft_strcpy(d_data->pw_name, tmp.usr->pw_name);
		ft_strcpy(d_data->gr_name, tmp.grp->gr_name);
	}
	else
	{
		if (!flags.t)
			time_alloc(d_data, tmp.f_data);
		else
			time_alloc(d_data, tmp.lf_data);
	}
}

time_t				time_helper3(t_sort d_data, t_lsflag flags)
{
	if (flags.c)
		return (d_data.ft_ctime);
	else if (flags.u)
		return (d_data.ft_atime);
	else
		return (d_data.ft_mtime);
}

char				*time_helper2(t_sort d_data, t_lsflag flags)
{
	if (flags.c)
		return (ctime(&d_data.ft_ctime));
	else if (flags.u)
		return (ctime(&d_data.ft_atime));
	else
		return (ctime(&d_data.ft_mtime));
}

char				**time_helper1(t_sort d_data, t_lsflag flags)
{
	if (flags.c)
		return (ft_strsplit(ctime(&d_data.ft_ctime), ' '));
	else if (flags.u)
		return (ft_strsplit(ctime(&d_data.ft_atime), ' '));
	else
		return (ft_strsplit(ctime(&d_data.ft_mtime), ' '));
}
