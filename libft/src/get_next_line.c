/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:53:11 by mkass             #+#    #+#             */
/*   Updated: 2018/04/18 18:48:52 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str[5000];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	CHK1(fd < 0 || fd > 4999 || !line, -1);
	CHK1((!str[fd] && (str[fd] = ft_strnew(0)) == NULL), -1);
	tmp = ft_strchr(str[fd], '\n');
	while (tmp == NULL)
	{
		CHK1((ret = read(fd, buf, BUFF_SIZE)) < 0, -1);
		CHKV5(ret > 0, buf[ret] = '\0',
			tmp = ft_strjoin(str[fd], buf), ft_bzero(str[fd],
			ft_strlen(str[fd])), free(str[fd]), str[fd] = tmp);
		CHKV1(ret > 0, tmp = ft_strchr(str[fd], '\n'));
		CHKV1(ret == 0, CHK2((tmp = ft_strchr(str[fd], '\0')) == str[fd],
							*line = "", 0));
	}
	CHK1(!(*line = ft_strsub(str[fd], 0, tmp - str[fd])), -1);
	tmp = ft_strdup(tmp + 1);
	ft_bzero(str[fd], ft_strlen(str[fd]));
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}
