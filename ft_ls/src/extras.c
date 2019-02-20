/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:28:34 by mkass             #+#    #+#             */
/*   Updated: 2018/09/07 15:28:48 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		linkcheck(mode_t ft_mode, char *name)
{
	char link[NAME_MAX];

	if (ISLNK(ft_mode))
	{
		ft_bzero(link, NAME_MAX);
		readlink(name, link, NAME_MAX);
		ft_printf(" -> %s\n", link);
	}
	else
		ft_putchar('\n');
}

int			llnlen(off_t n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

int			filecount(char *dir)
{
	DIR		*dr_strm;
	t_dir	*dr_file;
	int		count;

	count = 0;
	dr_strm = opendir(dir);
	while ((dr_file = readdir(dr_strm)))
		count++;
	closedir(dr_strm);
	return (count);
}

int			argcount(int ac, char **av)
{
	int ret;
	int i;

	if (ac > 1)
	{
		ret = 0;
		i = 1;
		while (av[i] && av[i][0] == DASH && av[i][1])
			i++;
		while (av[i++])
			ret++;
		if (ret)
			return (ret);
	}
	return (1);
}

inline void	print_status(t_sort d_data)
{
	if (ISFIF(d_data.lft_mode))
		ft_putchar('|');
	else if (ISDIR(d_data.lft_mode))
		ft_putchar('/');
	else if (ISLNK(d_data.lft_mode))
		ft_putchar('@');
	else if (ISSOC(d_data.lft_mode))
		ft_putchar('=');
	else if (ISWHT(d_data.lft_mode))
		ft_putchar('%');
	else if (ISXSR(d_data.lft_mode))
		ft_putchar('*');
}
