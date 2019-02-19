/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:33:19 by mkass             #+#    #+#             */
/*   Updated: 2018/08/23 20:21:37 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	flr_step(t_w3d *w, double wall)
{
	if (w->side == 0 && w->render.rayx > 0)
	{
		w->flr.x = (double)w->curx;
		w->flr.y = (double)w->cury + wall;
	}
	else if (w->side == 0 && w->render.rayx < 0)
	{
		w->flr.x = (double)w->curx + 1.0;
		w->flr.y = (double)w->cury + wall;
	}
	else if (w->side == 1 && w->render.rayy > 0)
	{
		w->flr.x = (double)w->curx + wall;
		w->flr.y = (double)w->cury;
	}
	else
	{
		w->flr.x = (double)w->curx + wall;
		w->flr.y = (double)w->cury + 1.0;
	}
}

void	flr_render(t_w3d *w, int x)
{
	int		y;
	double	weight;
	double	curx;
	double	cury;

	w->flr.dist = w->render.walldist;
	w->flr.me = 0.0;
	if (w->end < 0)
		w->end = WIN_Y;
	y = w->end + 1;
	w->texpick = flr;
	while (++y < WIN_Y)
	{
		w->flr.cur = WIN_Y / (2.0 * y - WIN_Y);
		weight = (w->flr.cur - w->flr.me) / (w->flr.dist - w->flr.me);
		curx = weight * w->flr.x + (1.0 - weight) * w->draw.posx;
		cury = weight * w->flr.y + (1.0 - weight) * w->draw.posy;
		w->flr.texx = (int)(curx * TEXCUBE) % TEXCUBE;
		w->flr.texy = (int)(cury * TEXCUBE) % TEXCUBE;
		ft_memcpy(w->px + 4 * WIN_X * y + x * 4,
			w->wall[w->texpick].px + w->flr.texy *
				w->wall[w->texpick].s_line + w->flr.texx * 4, sizeof(int));
	}
}
