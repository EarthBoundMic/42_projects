/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:11:01 by mkass             #+#    #+#             */
/*   Updated: 2018/08/25 16:14:43 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	print_mm(t_w3d *w, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i <= MMSIZE)
	{
		j = -1;
		while (++j <= MMSIZE)
			mlx_pixel_put(w->mlx, w->wd, x + i, y + j, color);
	}
}

void		minimap(t_w3d *w)
{
	int i;
	int j;

	i = -1;
	while (++i < w->b_size.rows)
	{
		j = -1;
		while (++j < w->b_size.cols)
		{
			if (w->map[j][i] == 'W')
				print_mm(w, i * MMSIZE, j * MMSIZE, 0x4040ff -
					((j + i) * 5));
			if ((int)w->draw.posx == j && (int)w->draw.posy == i)
				print_mm(w, i * MMSIZE, j * MMSIZE, 0xff0000);
		}
	}
}
