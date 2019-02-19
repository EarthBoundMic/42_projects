/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:30:51 by mkass             #+#    #+#             */
/*   Updated: 2018/08/22 14:46:01 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	collision(t_w3d *w)
{
	while (!w->hit)
	{
		if (w->render.distx < w->render.disty)
		{
			w->render.distx += w->render.ddistx;
			w->curx += w->stepx;
			w->side = 0;
		}
		else
		{
			w->render.disty += w->render.ddisty;
			w->cury += w->stepy;
			w->side = 1;
		}
		if (w->map[w->curx][w->cury] == 'W')
			w->hit = 1;
	}
}

void	display_legend(t_w3d *w)
{
	if (w->legend == 1)
	{
		mlx_string_put(w->mlx, w->wd, 10, 14, 0xffffff,
			"Arrow up and down moves forward and backward");
		mlx_string_put(w->mlx, w->wd, 10, 30, 0xffffbf,
			"Arrow left and right rotates camera");
		mlx_string_put(w->mlx, w->wd, 10, 46, 0xffff8f,
			"Hold left-shift to sprint and spin faster");
		mlx_string_put(w->mlx, w->wd, 10, 62, 0xffff4f,
			"Tab button toggles between legend, minimap, and blank");
		mlx_string_put(w->mlx, w->wd, 10, 78, 0xffff0f,
			"ESC button or closing window quits");
	}
}

void	wall_dist(t_w3d *w)
{
	if (!w->side)
		w->render.walldist = (w->curx - w->draw.posx +
							(1 - w->stepx) / 2) / w->render.rayx;
	else
		w->render.walldist = (w->cury - w->draw.posy +
							(1 - w->stepy) / 2) / w->render.rayy;
	w->height = (int)(WIN_Y / w->render.walldist);
	if ((w->start = -w->height / 2 + WIN_Y / 2) < 0)
		w->start = 0;
	if ((w->end = w->height / 2 + WIN_Y / 2) >= WIN_Y)
		w->end = WIN_Y - 1;
}

int		prog_exit(void)
{
	ft_printf("\nEnded wolf3d on %k\n");
	ft_exit();
	return (0);
}
