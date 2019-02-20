/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparams.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:22:16 by mkass             #+#    #+#             */
/*   Updated: 2018/09/28 15:22:26 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	filechecks1(t_params *pr_data, t_lsflag flags, char *param)
{
	if ((pr_data->dir = ft_fndpath(param)) == NULL)
		pr_data->dir = ft_strdup(CDIR);
	if ((pr_data->file = ft_fndfile(param)) == NULL)
		pr_data->file = ft_strdup(".");
	ft_bzero(pr_data->buf, sizeof(pr_data->buf));
	ft_strcpy(pr_data->buf, pr_data->dir);
	ft_bzero(pr_data->relpath, PATH_MAX);
	pr_data->f_data = stat_select(pr_data->buf, pr_data->file, flags,
		pr_data->relpath);
}

static inline void	filechecks2(t_params *pr_data1, t_params *pr_data2)
{
	if (pr_data1->dir && pr_data1->dir[0])
		ft_strdel(&pr_data1->dir);
	if (pr_data1->file[0])
		ft_strdel(&pr_data1->file);
	if (pr_data2->dir && pr_data2->dir[0])
		ft_strdel(&pr_data2->dir);
	if (pr_data2->file[0])
		ft_strdel(&pr_data2->file);
}

void				paramcmp(char **params, t_lsflag flags)
{
	t_params	pr_data[2];
	int			i;

	if (flags.r)
		ft_revsort(params, ft_realstrcmp, NULL);
	else
		ft_sort(params, ft_realstrcmp, NULL);
	i = 0;
	while (params[i] && params[i + 1])
	{
		filechecks1(&pr_data[0], flags, params[i]);
		filechecks1(&pr_data[1], flags, params[i + 1]);
		if (ISDIR(pr_data[0].f_data.st_mode) &&
				!ISDIR(pr_data[1].f_data.st_mode))
			i = ft_strswch(&params[i], &params[i + 1]);
		else
			i++;
		filechecks2(&pr_data[0], &pr_data[1]);
	}
}

int					file_param_count(int args, char **params, t_lsflag flags)
{
	t_params	pr_data;
	int			count;
	int			i;

	count = 0;
	i = -1;
	while (++i < args)
	{
		ft_bzero(&pr_data, sizeof(t_params));
		filechecks1(&pr_data, flags, params[i]);
		if (!ISDIR(pr_data.f_data.st_mode))
			count++;
		if (pr_data.dir && pr_data.dir[0])
			ft_strdel(&pr_data.dir);
		if (pr_data.file && pr_data.file[0])
			ft_strdel(&pr_data.file);
	}
	return (count);
}
