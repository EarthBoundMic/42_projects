/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprintfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:33:11 by mkass             #+#    #+#             */
/*   Updated: 2018/09/28 15:33:21 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define FILEPERM	lflag.fileperm
#define LINKS		lflag.links
#define USR			lflag.uname
#define GRP			lflag.gname
#define BYTES		lflag.bytes
#define LMAJOR		lflag.major
#define LMINOR		lflag.minor
#define MONTH		lflag.month
#define DAY			lflag.day
#define TME			lflag.time
#define W1			lflag.off1
#define W2			lflag.off2
#define W3			lflag.off3
#define W4			lflag.off4
#define W5			lflag.off5

static inline void	fileperm(mode_t lft_mode, char *buf)
{
	buf[1] = CHKCE(lft_mode & S_IRUSR, 'r', DASH);
	buf[2] = CHKCE(lft_mode & S_IWUSR, 'w', DASH);
	CHKE(ISSTU(lft_mode), buf[3] = CHKCE(ISXSR(lft_mode), 's', 'S'),
		buf[3] = CHKCE(ISXSR(lft_mode), 'x', DASH));
	buf[4] = CHKCE(lft_mode & S_IRGRP, 'r', DASH);
	buf[5] = CHKCE(lft_mode & S_IWGRP, 'w', DASH);
	CHKE(ISSTG(lft_mode), buf[6] = CHKCE(ISXGP(lft_mode), 's', 'S'),
		buf[6] = CHKCE(ISXGP(lft_mode), 'x', DASH));
	buf[7] = CHKCE(lft_mode & S_IROTH, 'r', DASH);
	buf[8] = CHKCE(lft_mode & S_IWOTH, 'w', DASH);
	CHKE(ISSTX(lft_mode), buf[9] = CHKCE(ISXOT(lft_mode), 't', 'T'),
		buf[9] = CHKCE(ISXOT(lft_mode), 'x', DASH));
}

static char			*time_select(t_sort d_data, const char *tstr)
{
	char	**curtime;
	char	*tmp;
	char	buf[8];
	int		b;
	time_t	cur;

	cur = time(NULL);
	curtime = ft_strsplit(ctime(&cur), ' ');
	if (cur - d_data.fl_time > 15767999)
	{
		b = -1;
		WHLE(curtime[++b], ft_strdel(&curtime[b]));
		free(curtime);
		tmp = ft_strsub(tstr, 19, 23);
		CHK3(1, ft_strbcpy(buf, tmp), ft_strdel(&tmp), ft_strdup(buf));
	}
	else
	{
		b = -1;
		WHLE(curtime[++b], ft_strdel(&curtime[b]));
		free(curtime);
		ft_strbcpy(buf, d_data.p_time[0]);
		ft_strcat(buf, ":");
		CHK2(1, ft_strcat(buf, d_data.p_time[1]), ft_strdup(buf));
	}
}

static inline void	time_data(t_el *lflag, t_sort d_data, t_lsflag flags)
{
	int		a;
	char	buf[25];
	char	*tmp;

	d_data.p_data = time_helper1(d_data, flags);
	d_data.p_time = ft_strsplit(d_data.p_data[3], ':');
	lflag->month = ft_strdup(d_data.p_data[1]);
	lflag->day = ft_strdup(d_data.p_data[2]);
	tmp = time_helper2(d_data, flags);
	tmp[24] = 0;
	ft_strbcpy(buf, tmp);
	d_data.fl_time = time_helper3(d_data, flags);
	lflag->time = time_select(d_data, buf);
	a = -1;
	while (d_data.p_data[++a])
		ft_strdel(&d_data.p_data[a]);
	a = -1;
	while (d_data.p_time[++a])
		ft_strdel(&d_data.p_time[a]);
	free(d_data.p_data);
	free(d_data.p_time);
}

static inline void	lflag_data(t_el *lflag, t_sort d_data, t_lsflag flags)
{
	ft_strcpy(lflag->d_name, d_data.d_name);
	ft_bzero(lflag->fileperm, 11);
	lflag->fileperm[0] = filetype(d_data.lft_mode);
	fileperm(d_data.lft_mode, lflag->fileperm);
	ext_perm(d_data.lrelpath, lflag->fileperm);
	lflag->links = d_data.ft_nlink;
	ft_strcpy(lflag->uname, d_data.pw_name);
	ft_strcpy(lflag->gname, d_data.gr_name);
	lflag->bytes = d_data.ft_size;
	lflag->major = MAJOR(d_data.ft_rdev);
	lflag->minor = MINOR(d_data.ft_rdev);
	time_data(lflag, d_data, flags);
}

void				lprintfile(t_el lflag, t_sort d_data, t_lsflag flags)
{
	lflag_data(&lflag, d_data, flags);
	if (ISCHR(d_data.lft_mode) || ISBLK(d_data.lft_mode))
		ft_printf("%-11s %*d %*s  %*s  %*d, %*d %s %2s %s ",
			FILEPERM, W1, LINKS, W2, USR, W3, GRP, W5, LMAJOR, W5,
			LMINOR, MONTH, DAY, TME);
	else
		ft_printf("%-11s %*d %*s  %*s  %*lld %s %2s %s ", FILEPERM,
			W1, LINKS, W2, USR, W3, GRP, W4, BYTES, MONTH, DAY, TME);
	ft_strdel(&lflag.month);
	ft_strdel(&lflag.day);
	ft_strdel(&lflag.time);
}
