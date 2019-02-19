/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:50:41 by mkass             #+#    #+#             */
/*   Updated: 2018/08/25 20:00:11 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		invalid(int c)
{
	CHKE(c == 1, ft_printf("Usage: ./wolf3d [file] file not found\n"),
		ft_printf("Usage: ./wolf3d [file] too many inputs\n"));
}

static void		begin_render(t_w3d w)
{
	check_map(&w);
	textures(&w);
	ft_printf("Began wolf3d on %k\n");
	w.wd = mlx_new_window(w.mlx, WIN_X, WIN_Y, "WOLF3D");
	w.draw.dirx = -1.0;
	w.draw.diry = 0.0;
	w.draw.planex = 0.0;
	w.draw.planey = 0.66;
	render(&w);
	mlx_hook(w.wd, KEYPRESS, KEYMAPSTATEMASK, presskey, &w);
	mlx_hook(w.wd, KEYRELEASE, KEYRELEASEMASK, releasekey, &w);
	mlx_hook(w.wd, DESTROYNOTIFY, STRUCTURENOTIFYMASK, prog_exit, &w);
	mlx_loop_hook(w.mlx, walk, &w);
	mlx_loop(w.mlx);
}

static void		w3d_init2(t_w3d *w)
{
	w->height = 0;
	w->start = 0;
	w->end = 0;
	w->up = 0;
	w->down = 0;
	w->left = 0;
	w->right = 0;
	w->legend = 1;
	w->texpick = 0;
	w->render.view = 0;
	w->render.rayx = 0;
	w->render.rayy = 0;
	w->render.distx = 0;
	w->render.disty = 0;
	w->render.ddistx = 0;
	w->render.ddisty = 0;
	w->render.walldist = 0;
	w->flr.x = 0;
	w->flr.y = 0;
	w->flr.dist = 0;
	w->flr.me = 0.0;
	w->flr.cur = 0;
	w->flr.texx = 0;
	w->flr.texy = 0;
}

static t_w3d	w3d_init(void)
{
	t_w3d	w;

	w.mlx = mlx_init();
	w.stepx = 0;
	w.stepy = 0;
	w.curx = 0;
	w.cury = 0;
	w.texx = 0;
	w.texy = 0;
	w.hit = 0;
	w.side = 0;
	w.draw.posx = 0;
	w.draw.posy = 0;
	w.draw.dirx = 0;
	w.draw.diry = 0;
	w.draw.planex = 0;
	w.draw.planey = 0;
	w.draw.curtime = 0;
	w.draw.prvtime = 0;
	w.draw.m_speed = 0.08;
	w.draw.r_speed = 0.07;
	w.b_size.rows = 0;
	w.b_size.cols = 0;
	w3d_init2(&w);
	return (w);
}

int				main(int ac, char **av)
{
	t_w3d	w;

	CHKE(ac == 2, LST4(w = w3d_init(),
				w.file = av[1], CHK1(parse_map(&w) < 0, 0), begin_render(w)),
		invalid(ac));
	return (0);
}
