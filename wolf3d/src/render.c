/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:08:55 by mkass             #+#    #+#             */
/*   Updated: 2018/08/23 20:23:33 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_map(t_w3d *w)
{
	int i;
	int j;
	int check;

	i = -1;
	check = 0;
	WHLE(w->map[++i] != NULL, LST2(j = -1, WHLE(w->map[i][++j] != NIL,
			LST2(CHKV3(w->map[i][j] != 'W' && w->map[i][j] != '.'
					&& w->map[i][j] != 'P',
					ft_printf("Incorrect Character Use For Map\n"),
					ft_printf("Content: ./wolf3d %s invalid file\n", w->file),
					ft_exit()),
				CHKV3(w->map[i][j] == 'P',
					w->draw.posy = (double)j + 0.5,
					w->draw.posx = (double)i + 0.5,
					check++)))));
	CHKV3(check < 1, ft_printf("No Player Placement Detected\n"),
		ft_printf("Content: ./wolf3d %s invalid file\n", w->file), ft_exit());
	CHKV3(check > 1, ft_printf("Too Many Player Placements Detected\n"),
		ft_printf("Content: ./wolf3d %s invalid file\n", w->file), ft_exit());
}

static void	rays(t_w3d *w, int x)
{
	w->render.view = 2 * x / (double)WIN_X - 1;
	w->render.rayx = w->draw.dirx + w->draw.planex * w->render.view;
	w->render.rayy = w->draw.diry + w->draw.planey * w->render.view;
	w->curx = (int)w->draw.posx;
	w->cury = (int)w->draw.posy;
	w->render.ddistx = sqrt(1 + pow(w->render.rayy, 2) /
						(pow(w->render.rayx, 2)));
	w->render.ddisty = sqrt(1 + pow(w->render.rayx, 2) /
						(pow(w->render.rayy, 2)));
	w->hit = 0;
}

static void	step(t_w3d *w)
{
	if (w->render.rayx < 0)
	{
		w->stepx = -1;
		w->render.distx = (w->draw.posx - w->curx) * w->render.ddistx;
	}
	else
	{
		w->stepx = 1;
		w->render.distx = (w->curx + 1.0 - w->draw.posx) * w->render.ddistx;
	}
	if (w->render.rayy < 0)
	{
		w->stepy = -1;
		w->render.disty = (w->draw.posy - w->cury) * w->render.ddisty;
	}
	else
	{
		w->stepy = 1;
		w->render.disty = (w->cury + 1.0 - w->draw.posy) * w->render.ddisty;
	}
}

static void	insert_tex(t_w3d *w, int x, int y)
{
	if (x < WIN_X && y < WIN_Y)
	{
		w->texy = CHKABS((((y * 256 - WIN_Y * 128 + w->height * 128) * TEXCUBE)
			/ w->height) / 256);
		ft_memcpy(w->px + 4 * WIN_X * y + x * 4,
			w->wall[w->texpick].px + w->texy % 64 *
				w->wall[w->texpick].s_line + w->texx % 64 * 4, sizeof(int));
	}
}

void		render(t_w3d *w)
{
	int x;
	int y;

	x = -1;
	w->img = mlx_new_image(w->mlx, WIN_X, WIN_Y);
	w->px = mlx_get_data_addr(w->img, &w->bpp, &w->s_line, &w->en);
	make_sky(w);
	while (++x < WIN_X)
	{
		rays(w, x);
		step(w);
		collision(w);
		wall_dist(w);
		pretex(w);
		flr_render(w, x);
		select_tex(w);
		y = w->start - 1;
		while (++y < w->end)
			insert_tex(w, x, y);
	}
	mlx_put_image_to_window(w->mlx, w->wd, w->img, 0, 0);
	mlx_destroy_image(w->mlx, w->img);
}
