/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:27:14 by mkass             #+#    #+#             */
/*   Updated: 2018/08/23 20:26:24 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			presskey(int key, t_w3d *w)
{
	CHKV1(key == ESC, prog_exit());
	if (key == LEFT)
		w->left = 1;
	else if (key == RIGHT)
		w->right = 1;
	else if (key == UP)
		w->up = 1;
	else if (key == DOWN)
		w->down = 1;
	else if (key == KTAB)
	{
		if (w->legend < 2)
			w->legend++;
		else
			w->legend = 0;
	}
	if (key == 257)
	{
		w->draw.m_speed = 0.13;
		w->draw.r_speed = 0.1;
	}
	return (0);
}

int			releasekey(int key, t_w3d *w)
{
	if (key == LEFT)
		w->left = 0;
	else if (key == RIGHT)
		w->right = 0;
	else if (key == UP)
		w->up = 0;
	else if (key == DOWN)
		w->down = 0;
	if (key == 257)
	{
		w->draw.m_speed = 0.08;
		w->draw.r_speed = 0.07;
	}
	return (0);
}

static void	rotate_right(t_w3d *w)
{
	double	prvdir;
	double	prvplane;

	if (w->right)
	{
		prvdir = w->draw.dirx;
		w->draw.dirx = w->draw.dirx * cos(-w->draw.r_speed) - w->draw.diry *
			sin(-w->draw.r_speed);
		w->draw.diry = prvdir * sin(-w->draw.r_speed) + w->draw.diry *
			cos(-w->draw.r_speed);
		prvplane = w->draw.planex;
		w->draw.planex = w->draw.planex * cos(-w->draw.r_speed) -
			w->draw.planey * sin(-w->draw.r_speed);
		w->draw.planey = prvplane * sin(-w->draw.r_speed) + w->draw.planey *
			cos(-w->draw.r_speed);
	}
}

static void	rotate_left(t_w3d *w)
{
	double	prvdir;
	double	prvplane;

	if (w->left)
	{
		prvdir = w->draw.dirx;
		w->draw.dirx = w->draw.dirx * cos(w->draw.r_speed) - w->draw.diry *
			sin(w->draw.r_speed);
		w->draw.diry = prvdir * sin(w->draw.r_speed) + w->draw.diry *
			cos(w->draw.r_speed);
		prvplane = w->draw.planex;
		w->draw.planex = w->draw.planex * cos(w->draw.r_speed) -
			w->draw.planey * sin(w->draw.r_speed);
		w->draw.planey = prvplane * sin(w->draw.r_speed) + w->draw.planey *
			cos(w->draw.r_speed);
	}
}

int			walk(t_w3d *w)
{
	if (w->up)
	{
		if (w->map[(int)(w->draw.posx + w->draw.dirx *
						w->draw.m_speed)][(int)w->draw.posy] != 'W')
			w->draw.posx += w->draw.dirx * w->draw.m_speed;
		if (w->map[(int)w->draw.posx][(int)(w->draw.posy + w->draw.diry *
											w->draw.m_speed)] != 'W')
			w->draw.posy += w->draw.diry * w->draw.m_speed;
	}
	if (w->down)
	{
		if (w->map[(int)(w->draw.posx - w->draw.dirx *
						w->draw.m_speed)][(int)w->draw.posy] != 'W')
			w->draw.posx -= w->draw.dirx * w->draw.m_speed;
		if (w->map[(int)w->draw.posx][(int)(w->draw.posy - w->draw.diry *
											w->draw.m_speed)] != 'W')
			w->draw.posy -= w->draw.diry * w->draw.m_speed;
	}
	rotate_right(w);
	rotate_left(w);
	render(w);
	CHKV1(w->legend == 1, display_legend(w));
	CHKV1(w->legend == 2, minimap(w));
	return (0);
}
