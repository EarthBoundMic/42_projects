/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:00:14 by mkass             #+#    #+#             */
/*   Updated: 2018/08/30 15:01:15 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	filetype(mode_t lft_mode)
{
	CHK1(ISFIF(lft_mode), 'p');
	CHK1(ISCHR(lft_mode), 'c');
	CHK1(ISDIR(lft_mode), 'd');
	CHK1(ISBLK(lft_mode), 'b');
	CHK1(ISREG(lft_mode), DASH);
	CHK1(ISLNK(lft_mode), 'l');
	CHK1(ISSOC(lft_mode), 's');
	return (NIL);
}

int		blockcount(int filecount, t_lsflag flags, t_sort *d_data)
{
	int	blocks;
	int	i;

	blocks = 0;
	i = -1;
	while (++i < filecount)
	{
		i = a_aa_flags(d_data, flags, i, filecount);
		if (i < filecount)
			blocks += d_data[i].ft_blocks;
	}
	return (blocks);
}

void	offsets(t_el *lflag, t_sort *d_data, t_lsflag flags, int filecount)
{
	int i;

	i = 0;
	while (i < filecount)
	{
		i = a_aa_flags(d_data, flags, i, filecount);
		if (i >= filecount)
			break ;
		lflag->off1 = CHKMAX(lflag->off1, ft_nlen(d_data[i].ft_nlink));
		lflag->off2 = CHKMAX(lflag->off2, (int)ft_strlen(d_data[i].pw_name));
		lflag->off3 = CHKMAX(lflag->off3, (int)ft_strlen(d_data[i].gr_name));
		lflag->off4 = CHKMAX(lflag->off4, llnlen(d_data[i].ft_size));
		lflag->off5 = 3;
		if (ISCHR(d_data[i].lft_mode))
			lflag->off4 = CHKMAX(lflag->off4, 5 + lflag->off5);
		i++;
	}
	lflag->off2 = -lflag->off2;
	lflag->off3 = -lflag->off3;
}
