/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:02:23 by mweir             #+#    #+#             */
/*   Updated: 2018/08/25 19:58:19 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	is_valid(t_w3d w)
{
	int rows;
	int cols;

	rows = w.b_size.rows;
	cols = w.b_size.cols;
	if (rows < cols)
	{
		ft_printf("Rows must be equal to or greater than columns\n");
		return (0);
	}
	if (rows <= 2 || cols <= 2)
	{
		ft_printf("Too Small; Minimum 2x2\n");
		return (-1);
	}
	if (rows >= 50 || cols >= 50)
	{
		ft_printf("Too Large; Maximum 50x50\n");
		return (-1);
	}
	return (1);
}

static int	find_map_size(t_w3d *w, char *file)
{
	char	*line_data;
	int		i;
	char	**temp_map;
	int		t_r;

	t_r = 0;
	w->fd = open(file, O_RDONLY);
	while ((get_next_line(w->fd, &line_data)) > 0)
	{
		w->b_size.cols++;
		i = 0;
		t_r = 0;
		temp_map = ft_strsplit(line_data, SPCE);
		while (temp_map[i] != NIL)
		{
			free(temp_map[i]);
			t_r++;
			i++;
		}
		free(temp_map);
		free(line_data);
	}
	w->b_size.rows = t_r;
	close(w->fd);
	return ((is_valid(*w) ? 1 : -1));
}

static void	create_map(t_w3d *w)
{
	int i;

	i = 0;
	if (w->b_size.rows >= w->b_size.cols)
	{
		w->map = (char**)ft_memalloc(sizeof(char*) * (w->b_size.rows + 1));
		while (i < w->b_size.rows)
		{
			w->map[i] = (char*)ft_memalloc(sizeof(char) * (w->b_size.cols + 1));
			ft_bzero(w->map[i], sizeof(w->map));
			i++;
		}
	}
	else
	{
		w->map = (char**)ft_memalloc(sizeof(char*) * (w->b_size.cols + 1));
		while (i < w->b_size.cols)
		{
			w->map[i] = (char*)ft_memalloc(sizeof(char) * (w->b_size.rows + 1));
			ft_bzero(w->map[i], sizeof(w->map));
			i++;
		}
	}
}

static void	populate_map(t_w3d *w, char *file)
{
	int		i;
	int		j;
	char	**temp_map;
	char	*line;

	j = 0;
	create_map(w);
	w->fd = open(file, O_RDONLY);
	while ((get_next_line(w->fd, &line)) > 0)
	{
		temp_map = ft_strsplit(line, SPCE);
		i = 0;
		while (temp_map[i] != NIL)
		{
			w->map[j][i] = *temp_map[i];
			free(temp_map[i]);
			i++;
		}
		w->map[j][i] = NIL;
		j++;
		free(temp_map);
		free(line);
	}
	w->map[i] = NULL;
	close(w->fd);
}

int			parse_map(t_w3d *w)
{
	CHK2(find_map_size(w, w->file) < 0,
		ft_printf("Content: ./wolf3d %s invalid map", w->file), -1);
	populate_map(w, w->file);
	if (bounds_check(w) == 0)
	{
		ft_printf("Improper Map! Please Verify Map Boundaries\n");
		ft_printf("Content: ./wolf3d %s invalid map\n", w->file);
		return (-1);
	}
	return (1);
}
