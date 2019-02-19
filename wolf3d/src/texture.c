/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:05:18 by mkass             #+#    #+#             */
/*   Updated: 2018/08/23 20:26:57 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	textures(t_w3d *w)
{
	int x;
	int y;

	x = 64;
	y = 64;
	w->wall[wall1].img = mlx_xpm_file_to_image(w->mlx, WALL1, &x, &y);
	w->wall[wall1].px = mlx_get_data_addr(w->wall[wall1].img,
		&w->wall[wall1].bpp, &w->wall[wall1].s_line, &w->wall[wall1].en);
	w->wall[wall2].img = mlx_xpm_file_to_image(w->mlx, WALL2, &x, &y);
	w->wall[wall2].px = mlx_get_data_addr(w->wall[wall2].img,
		&w->wall[wall2].bpp, &w->wall[wall2].s_line, &w->wall[wall2].en);
	w->wall[wall3].img = mlx_xpm_file_to_image(w->mlx, WALL3, &x, &y);
	w->wall[wall3].px = mlx_get_data_addr(w->wall[wall3].img,
		&w->wall[wall3].bpp, &w->wall[wall3].s_line,
		&w->wall[wall3].en);
	w->wall[wall4].img = mlx_xpm_file_to_image(w->mlx, WALL4, &x, &y);
	w->wall[wall4].px = mlx_get_data_addr(w->wall[wall4].img,
		&w->wall[wall4].bpp, &w->wall[wall4].s_line, &w->wall[wall4].en);
	w->wall[flr].img = mlx_xpm_file_to_image(w->mlx, FLR, &x, &y);
	w->wall[flr].px = mlx_get_data_addr(w->wall[flr].img,
		&w->wall[flr].bpp, &w->wall[flr].s_line, &w->wall[flr].en);
	w->wall[sky].img = mlx_xpm_file_to_image(w->mlx, SKY, &x, &y);
	w->wall[sky].px = mlx_get_data_addr(w->wall[sky].img,
		&w->wall[sky].bpp, &w->wall[sky].s_line, &w->wall[sky].en);
}

void	pretex(t_w3d *w)
{
	double	wall;

	if (!w->side)
		wall = w->draw.posy + w->render.walldist * w->render.rayy;
	else
		wall = w->draw.posx + w->render.walldist * w->render.rayx;
	wall -= floor(wall);
	w->texx = (int)(wall * (double)TEXCUBE);
	if ((!w->side && w->render.rayx > 0) || (w->side && w->render.rayy < 0))
		w->texx = TEXCUBE - w->texx - 1;
	w->texx = CHKABS(w->texx);
	flr_step(w, wall);
}

void	select_tex(t_w3d *w)
{
	if (!w->side && w->render.rayx >= 0)
		w->texpick = wall1;
	else if (!w->side && w->render.rayx < 0)
		w->texpick = wall2;
	else if (w->side && w->render.rayy >= 0)
		w->texpick = wall3;
	else
		w->texpick = wall4;
}

void	make_sky(t_w3d *w)
{
	int x;
	int y;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		w->texpick = sky;
		while (++y < WIN_Y / 2)
		{
			ft_memcpy(w->px + 4 * WIN_X * y + x * 4,
				w->wall[w->texpick].px + y % WIN_Y *
				w->wall[w->texpick].s_line + x % WIN_X * 4, sizeof(int));
		}
	}
}
