/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:55:09 by mkass             #+#    #+#             */
/*   Updated: 2018/08/30 15:38:07 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>

# define CDIR "./"
# define PRID '.'
# define DASH '-'
# define BRK break

# define MAJOR(a) ((a >> 24) & 0xff)
# define MINOR(a) (a & 0xff)

# define PRV(a) (a[0] == '.' && a[1] == '.')
# define CUR(a) (a[0] == '.' && a[1] == 0)

# ifndef NAME_MAX
#  define NAME_MAX (1 << 11)
# endif

# ifndef PATH_MAX
#  define PATH_MAX (1 << 17)
# endif

# define ISXOT(a) ((a & 1) == 1)
# define ISWOT(a) ((a & 2) == 2)
# define ISXGP(a) ((a & 8) == 8)
# define ISXSR(a) (((a >> 4) & 4) == 4)
# define ISSTX(a) (((a >> 8) & 2) == 2)
# define ISSTG(a) (((a >> 8) & 4) == 4)
# define ISSTU(a) (((a >> 8) & 8) == 8)
# define ISFIF(a) ((a >> 12) == 1)
# define ISCHR(a) ((a >> 12) == 2)
# define ISDIR(a) ((a >> 12) == 4)
# define ISBLK(a) ((a >> 12) == 6)
# define ISREG(a) ((a >> 12) == 8)
# define ISLNK(a) ((a >> 12) == 10)
# define ISSOC(a) ((a >> 12) == 12)
# define ISWHT(a) ((a >> 12) == 14)

# define RSTA "\033[0m"
# define BLKF "\033[30m"
# define REDF "\033[31m"
# define GRNF "\033[32m"
# define YLWF "\033[33m"
# define BLUF "\033[34m"
# define MGNF "\033[35m"
# define REDB "\033[41m"
# define GRNB "\033[42m"
# define YLWB "\033[43m"
# define CYNB "\033[46m"

typedef struct dirent	t_dir;
typedef struct stat		t_stt;
typedef struct passwd	t_usr;
typedef struct group	t_grp;

typedef struct			s_params
{
	t_stt				f_data;
	char				buf[NAME_MAX];
	char				*dir;
	char				*file;
	char				relpath[PATH_MAX];
}						t_params;

typedef struct			s_el
{
	char				fileperm[11];
	int					off1;
	int					links;
	int					off2;
	char				uname[NAME_MAX];
	int					off3;
	char				gname[NAME_MAX];
	int					off4;
	off_t				bytes;
	int					off5;
	int					major;
	int					minor;
	char				*month;
	char				*day;
	char				*time;
	char				d_name[NAME_MAX];
}						t_el;

typedef struct			s_lsflag
{
	int					aa : 1;
	int					ff : 1;
	int					gg : 1;
	int					rr : 1;
	int					a : 1;
	int					c : 1;
	int					f : 1;
	int					l : 1;
	int					r : 1;
	int					t : 1;
	int					u : 1;
	int					chk : 1;
}						t_lsflag;

typedef struct			s_sort
{
	t_dir				*dr_file;
	t_stt				f_data;
	t_stt				lf_data;
	t_usr				*usr;
	t_grp				*grp;
	char				**p_data;
	char				**p_time;
	char				d_name[NAME_MAX];
	char				relpath[PATH_MAX];
	char				lrelpath[PATH_MAX];
	mode_t				ft_mode;
	mode_t				lft_mode;
	nlink_t				ft_nlink;
	uid_t				ft_uid;
	gid_t				ft_gid;
	dev_t				ft_rdev;
	time_t				ft_atime;
	time_t				ft_mtime;
	time_t				ft_ctime;
	long				ft_natime;
	long				ft_nctime;
	long				ft_nmtime;
	time_t				fl_time;
	off_t				ft_size;
	blksize_t			ft_blocks;
	char				pw_name[NAME_MAX];
	char				gr_name[NAME_MAX];
}						t_sort;

typedef struct			s_ls
{
	DIR					*dr_strm;
	t_el				lflag;
	t_sort				*d_data;
	t_sort				tmp_data;
	t_dir				*dr_file;
	t_stt				f_data;
	char				relpath[PATH_MAX];
	int					filecount;
	int					blocks;
}						t_ls;

/*
**	ft_ls.c
*/

void					printfile(t_el lflag, t_sort d_data, t_lsflag flags);

/*
**	flags.c
*/

void					param_parse(int ac, char **av, char **params,
															t_lsflag *flags);

/*
**	checkstat.c
*/

char					*relpath(char *path, char *file);
char					*checkstat(char *d_name, t_stt *f_data, char *dir);
char					*checklstat(char *d_name, t_stt *f_data, char *dir);
t_stt					stat_select(char *dir, char *d_name, t_lsflag flags,
															char *relpath);

/*
**	checkparams.c
*/

void					paramcmp(char **params, t_lsflag flags);
int						file_param_count(int args, char **params,
															t_lsflag flags);

/*
**	wrongname.c
*/

int						wrongname(char *path, t_lsflag flags);

/*
**	data_alloc.c
*/

void					data_alloc(t_sort *d_data, t_sort tmp, t_lsflag flags);
time_t					time_helper3(t_sort d_data, t_lsflag flags);
char					*time_helper2(t_sort d_data, t_lsflag flags);
char					**time_helper1(t_sort d_data, t_lsflag flags);

/*
**	dsta_extract.c
*/

void					file_extraction(char *file, t_lsflag flags,
													t_sort *d_data, t_ls ls);
t_sort					*data_extraction(char *dir, t_lsflag flags,
																int filecount);

/*
**	errors.c
*/

char					*error_handling1(char *dir);
char					*error_handling2(char *dir);
int						no_file(char **dir, char *file);

/*
**	recursion.c
*/

void					rr_flag(char *dir, t_ls ls, t_lsflag flags);

/*
**	opendirs.c
*/

int						a_aa_flags(t_sort *d_data, t_lsflag flags, int i,
																int filecount);
void					ft_ls(char *dir, t_lsflag flags);

/*
**	sort.c
*/

void					sort_data(t_sort *d_data, t_lsflag flags,
																int filecount);

/*
**	lflag.c
*/

char					filetype(mode_t lft_mode);
int						blockcount(int filecount, t_lsflag flags,
															t_sort *d_data);
void					offsets(t_el *lflag, t_sort *d_data, t_lsflag flags,
																int filecount);

/*
**	lprintfile.c
*/

void					lprintfile(t_el lflag, t_sort d_data, t_lsflag flags);

/*
**	ls_color.c
*/

void					select_color(mode_t ft_mode);

/*
**	extras.c
*/

void					linkcheck(mode_t ft_mode, char *name);
int						llnlen(off_t n);
int						filecount(char *dir);
int						argcount(int ac, char **av);
void					print_status(t_sort d_data);

/*
**	delete.c
*/

void					d_data_del(t_sort *d_data);

/*
**	ex_attr.c
*/

void					ext_perm(const char *file, char *buf);

#endif
