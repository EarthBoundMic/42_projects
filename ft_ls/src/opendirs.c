/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:31:21 by mkass             #+#    #+#             */
/*   Updated: 2018/09/05 16:31:37 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	print_blocks(t_ls *ls, t_lsflag flags)
{
	if (flags.l)
	{
		ls->blocks = blockcount(ls->filecount, flags, ls->d_data);
		ft_printf("total %d\n", ls->blocks);
		offsets(&ls->lflag, ls->d_data, flags, ls->filecount);
	}
}

static void			sort_cur_and_prv(t_sort *d_data, int filecount)
{
	int		i;
	t_sort	tmp;

	i = -1;
	while (++i < filecount)
	{
		if ((i > 0 && CUR(d_data[i].d_name)) ||
			(i > 1 && PRV(d_data[i].d_name)))
		{
			tmp = d_data[i];
			d_data[i] = d_data[i - 1];
			d_data[i - 1] = tmp;
			i = -1;
		}
		if (CUR(d_data[0].d_name) && PRV(d_data[1].d_name))
			break ;
	}
}

inline int			a_aa_flags(t_sort *d_data, t_lsflag flags, int i,
																int filecount)
{
	while (!flags.a && i < filecount && d_data[i].d_name[0] == PRID)
	{
		if (flags.aa && (CUR(d_data[i].d_name) || PRV(d_data[i].d_name)))
			i++;
		else if (!flags.aa)
			i++;
		else
			break ;
	}
	return (i);
}

void				ft_ls(char *dir, t_lsflag flags)
{
	t_ls	ls;
	int		i;

	ls.filecount = filecount(dir);
	ls.d_data = data_extraction(dir, flags, ls.filecount);
	if (!flags.f)
		sort_data(ls.d_data, flags, ls.filecount);
	else
		sort_cur_and_prv(ls.d_data, ls.filecount);
	ft_bzero(&ls.lflag, sizeof(ls.lflag));
	print_blocks(&ls, flags);
	i = -1;
	while (++i < ls.filecount)
	{
		i = a_aa_flags(ls.d_data, flags, i, ls.filecount);
		if (i >= ls.filecount)
			break ;
		printfile(ls.lflag, ls.d_data[i], flags);
	}
	if (flags.rr)
		rr_flag(dir, ls, flags);
	d_data_del(ls.d_data);
}
