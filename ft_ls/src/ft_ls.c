/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:42:18 by mkass             #+#    #+#             */
/*   Updated: 2018/08/30 15:42:28 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_param_files(int file_end, char **params, t_lsflag flags)
{
	t_ls	ls;
	int		i;

	i = -1;
	ls.d_data = ft_memalloc(sizeof(t_sort) * file_end);
	while (++i < file_end)
	{
		if (wrongname(params[i], flags))
			continue ;
		file_extraction(params[i], flags, &ls.d_data[i], ls);
	}
	ft_bzero(&ls.lflag, sizeof(t_el));
	if (flags.l)
		offsets(&ls.lflag, ls.d_data, flags, file_end);
	i = -1;
	while (++i < file_end)
	{
		if (ls.d_data[i].ft_mode)
			printfile(ls.lflag, ls.d_data[i], flags);
	}
	d_data_del(ls.d_data);
	if (params[i])
		ft_putchar('\n');
}

static void	print_param_dirs(int args, int dirstart, char **params,
																t_lsflag flags)
{
	int i;

	while (dirstart < args)
	{
		i = wrongname(params[dirstart], flags);
		if (i == -1 && args == 1)
			return ;
		if (args > 1 && i == 1)
			ft_printf("%s:\n", params[dirstart]);
		if (i == 1)
		{
			ft_ls(params[dirstart], flags);
			if (args > 1 && params[dirstart + 1])
				ft_putchar('\n');
		}
		dirstart++;
	}
}

void		printfile(t_el lflag, t_sort d_data, t_lsflag flags)
{
	char name[NAME_MAX];

	ft_bzero(name, NAME_MAX);
	if (flags.chk)
	{
		if (flags.l)
			ft_strcpy(name, d_data.lrelpath);
		else
			ft_strcpy(name, d_data.relpath);
	}
	else
		ft_strcpy(name, d_data.d_name);
	if (flags.l)
		lprintfile(lflag, d_data, flags);
	if (flags.gg)
		select_color(d_data.lft_mode);
	ft_printf("%s", name);
	if (flags.gg)
		ft_putstr(RSTA);
	if (flags.ff)
		print_status(d_data);
	if (flags.l)
		linkcheck(d_data.lft_mode, d_data.lrelpath);
	else
		ft_putchar('\n');
}

int			main(int ac, char **av)
{
	t_lsflag	flags;
	char		**params;
	int			file_p_count;
	int			args;
	int			del;

	ft_bzero(&flags, sizeof(t_lsflag));
	args = argcount(ac, av);
	params = malloc(sizeof(char*) * (args + 1));
	params[args] = NULL;
	param_parse(ac, av, params, &flags);
	if (args > 1)
		paramcmp(params, flags);
	file_p_count = file_param_count(args, params, flags);
	if (file_p_count > 0)
		print_param_files(file_p_count, params, flags);
	if (file_p_count != args)
		print_param_dirs(args, file_p_count, params, flags);
	del = -1;
	while (++del < args)
		ft_strdel(&params[del]);
	free(params);
	return (0);
}
