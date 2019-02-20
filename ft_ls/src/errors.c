/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:50:06 by mkass             #+#    #+#             */
/*   Updated: 2018/09/28 15:50:17 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*error_handling1(char *dir)
{
	char str[NAME_MAX];

	ft_strcat(str, "./ft_ls: ");
	ft_strcat(str, dir);
	perror(str);
	ft_strdel(&dir);
	return (NULL);
}

char	*error_handling2(char *dir)
{
	char str[NAME_MAX];

	ft_strcat(str, "./ft_ls: ");
	ft_strcat(str, dir);
	perror(str);
	return (NULL);
}

int		no_file(char **dir, char *file)
{
	if (*dir && *dir[0])
		ft_strdel(dir);
	if (file == NULL)
		return (-1);
	return (1);
}
