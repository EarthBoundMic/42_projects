/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:21:55 by mkass             #+#    #+#             */
/*   Updated: 2018/09/10 15:22:10 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			d_data_switch(t_sort *d_data, int i, int cmp)
{
	t_sort	tmp;

	if (cmp)
	{
		tmp = d_data[i];
		d_data[i] = d_data[i + 1];
		d_data[i + 1] = tmp;
		return (-1);
	}
	return (i);
}

static inline void	sort_data_by_mtime(t_sort *d_data, t_lsflag flags, int *i)
{
	if (d_data[*i].ft_mtime == d_data[*i + 1].ft_mtime && d_data[*i].ft_nmtime
													!= d_data[*i + 1].ft_nmtime)
	{
		if (!flags.r)
			*i = d_data_switch(d_data, *i, d_data[*i].ft_nmtime <
				d_data[*i + 1].ft_nmtime);
		else
			*i = d_data_switch(d_data, *i, d_data[*i].ft_nmtime >
				d_data[*i + 1].ft_nmtime);
	}
	else
	{
		if (!flags.r)
			*i = d_data_switch(d_data, *i, d_data[*i].ft_mtime <
				d_data[*i + 1].ft_mtime);
		else
			*i = d_data_switch(d_data, *i, d_data[*i].ft_mtime >
				d_data[*i + 1].ft_mtime);
	}
}

static inline void	sort_data_by_ctime(t_sort *d_data, t_lsflag flags, int *i)
{
	if (d_data[*i].ft_ctime == d_data[*i + 1].ft_ctime && d_data[*i].ft_nctime
													!= d_data[*i + 1].ft_nctime)
	{
		if (!flags.r)
			*i = d_data_switch(d_data, *i, d_data[*i].ft_nctime <
				d_data[*i + 1].ft_nctime);
		else
			*i = d_data_switch(d_data, *i, d_data[*i].ft_nctime >
				d_data[*i + 1].ft_nctime);
	}
	else
	{
		if (!flags.r)
			*i = d_data_switch(d_data, *i, d_data[*i].ft_ctime <
				d_data[*i + 1].ft_ctime);
		else
			*i = d_data_switch(d_data, *i, d_data[*i].ft_ctime >
				d_data[*i + 1].ft_ctime);
	}
}

static inline void	sort_data_by_atime(t_sort *d_data, t_lsflag flags, int *i)
{
	if (d_data[*i].ft_atime == d_data[*i + 1].ft_atime && d_data[*i].ft_natime
													!= d_data[*i + 1].ft_natime)
	{
		if (!flags.r)
			*i = d_data_switch(d_data, *i, d_data[*i].ft_natime <
				d_data[*i + 1].ft_natime);
		else
			*i = d_data_switch(d_data, *i, d_data[*i].ft_natime >
				d_data[*i + 1].ft_natime);
	}
	else
	{
		if (!flags.r)
			*i = d_data_switch(d_data, *i, d_data[*i].ft_atime <
				d_data[*i + 1].ft_atime);
		else
			*i = d_data_switch(d_data, *i, d_data[*i].ft_atime >
				d_data[*i + 1].ft_atime);
	}
}

void				sort_data(t_sort *d_data, t_lsflag flags, int filecount)
{
	int	i;

	i = -1;
	while (++i < filecount - 1)
	{
		if (!flags.r)
			i = d_data_switch(d_data, i, ft_realstrcmp(d_data[i].d_name,
				d_data[i + 1].d_name) > 0);
		else
			i = d_data_switch(d_data, i, ft_realstrcmp(d_data[i].d_name,
				d_data[i + 1].d_name) < 0);
	}
	i = -1;
	while (flags.t && ++i < filecount - 1)
	{
		if (flags.c)
			sort_data_by_ctime(d_data, flags, &i);
		else if (flags.u)
			sort_data_by_atime(d_data, flags, &i);
		else
			sort_data_by_mtime(d_data, flags, &i);
	}
}
