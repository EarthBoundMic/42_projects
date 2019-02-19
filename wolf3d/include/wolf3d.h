/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:28:18 by mkass             #+#    #+#             */
/*   Updated: 2018/08/25 19:59:44 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_simple/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/*
**	WIN_X and WIN_Y are set for 16:9 aspect ratio
*/

# define WIN_X 1200
# define WIN_Y 675

/*
**	TEXCUBE is for textures...don't adjust
**	MMSIZE is minimap size...if too small can make the number bigger
*/

# define TEXCUBE 64
# define MMSIZE 5

/*
**	macros for keyboard mapping
*/

# define KTAB 48
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

/*
**	TEX is for maximum number of textures
*/

# define TEX 6

/*
**	X11 digits for masks
*/

# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK (1L << 17)
# define KEYPRESS 2
# define KEYMAPSTATEMASK (1L << 14)
# define KEYRELEASE 3
# define KEYRELEASEMASK (1L << 1)

/*
**	easier to call textures with
*/

# define WALL1 "textures/tile02.xpm"
# define WALL2 "textures/Seamless_Rainbow.xpm"
# define WALL3 "textures/Water-2.xpm"
# define WALL4 "textures/pattern___glowing_coal_by_n4pgamer-d4jqm5c.xpm"
# define FLR "textures/hay.xpm"
# define SKY "textures/new_sky.XPM"

typedef struct	s_txtr
{
	void		*img;
	char		*px;
	int			bpp;
	int			s_line;
	int			en;
}				t_txtr;

typedef struct	s_map
{
	int			rows;
	int			cols;
}				t_map;

typedef struct	s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		curtime;
	double		prvtime;
	double		m_speed;
	double		r_speed;
}				t_ray;

typedef struct	s_move
{
	double		view;
	double		rayx;
	double		rayy;
	double		distx;
	double		disty;
	double		ddistx;
	double		ddisty;
	double		walldist;
}				t_move;

typedef struct	s_floor
{
	double		x;
	double		y;
	double		dist;
	double		me;
	double		cur;
	int			texx;
	int			texy;
}				t_floor;

typedef struct	s_w3d
{
	t_txtr		wall[TEX];
	void		*mlx;
	void		*wd;
	void		*img;
	char		*px;
	int			bpp;
	int			s_line;
	int			en;
	char		*file;
	char		**map;
	int			fd;
	t_map		b_size;
	t_ray		draw;
	t_move		render;
	t_floor		flr;
	int			curx;
	int			cury;
	int			stepx;
	int			stepy;
	int			texx;
	int			texy;
	int			hit;
	int			side;
	int			height;
	int			start;
	int			end;
	int			up;
	int			down;
	int			left;
	int			right;
	int			legend;
	int			texpick;
}				t_w3d;

/*
**	variable names for enum are placeholders to hold texture names
*/

enum			e_txtrs
{
	wall1,
	wall2,
	wall3,
	wall4,
	flr,
	sky
};

/*
**	hooks.c
*/

int				presskey(int key, t_w3d *w);
int				releasekey(int key, t_w3d *w);
int				walk(t_w3d *w);

/*
**	parse.c
*/

int				parse_map(t_w3d *w);

/*
**	render.c
*/

void			check_map(t_w3d *w);
void			render(t_w3d *w);

/*
**	floor.c
*/

void			flr_step(t_w3d *w, double wall);
void			flr_render(t_w3d *w, int x);

/*
**	textures.c
*/

void			textures(t_w3d *w);
void			pretex(t_w3d *w);
void			select_tex(t_w3d *w);
void			make_sky(t_w3d *w);

/*
**	extras.c
*/

void			collision(t_w3d *w);
void			display_legend(t_w3d *w);
void			wall_dist(t_w3d *w);
int				prog_exit(void);

/*
**	minimap.c
*/

void			minimap(t_w3d *w);

/*
** error.c
*/

int				bounds_check(t_w3d *w);

#endif
