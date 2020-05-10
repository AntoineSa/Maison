/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:16:53 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 12:42:27 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cube.h"
#include <math.h>
#include <stdlib.h>

int			skip_pix(t_img t, int j, int i)
{
	if (get_txt_color(t, j * t.x_txt, i * t.y_txt) == 0)
		return (1);
	return (0);
}

static int	set_xscreen(t_game g, t_img *t, t_sprite sp)
{
	int	x_screen;

	t->x_txt = t->x / (BLOCK_SIZE / sp.dist * g.s_dist);
	x_screen = g.set.res_x / 2;
	x_screen += (sp.dir - g.p.dir) / (g.p.fov / 2) * (g.set.res_x / 2);
	x_screen -= (t->x / t->x_txt) / 2;
	return (x_screen);
}

static int	set_yscreen(t_game g, t_img *t, t_sprite sp)
{
	int	y_screen;

	t->y_txt = t->y / (BLOCK_SIZE / sp.dist * g.s_dist);
	y_screen = g.set.res_y / 2;
	y_screen -= (t->y / t->y_txt) / 2;
	return (y_screen);
}

static void	put_sprite_to_img(t_sprite sp, t_game g)
{
	t_img	t;
	int		i;
	int		j;
	int		*k;
	int		x[2];

	t = g.txt[4];
	i = 0;
	j = 0;
	if ((x[0] = set_xscreen(g, &t, sp)) < 0)
		j = -x[0];
	x[1] = set_yscreen(g, &t, sp);
	while (j * t.x_txt < t.x && j + x[0] < g.set.res_x)
	{
		i = (x[1] < 0) ? -x[1] : 0;
		while (i * t.y_txt < t.y && i + x[1] < g.set.res_y)
		{
			g.img.index = (i + x[1]) * g.img.size_l + x[0] + j;
			if (!(skip_pix(t, j, i)) && g.z_buff[j + x[0]] > sp.dist &&
				(k = g.img.d_ptr + g.img.index))
				*k = get_txt_color(t, j * t.x_txt, i * t.y_txt);
			i++;
		}
		j++;
	}
}

void		draw_sprite(t_game *g)
{
	int			i;
	t_sprite	*s;

	i = 0;
	while (i < g->sp_num)
	{
		s = &(g->sp[i++]);
		if (s->dist != -2)
		{
			s->dir = sprite_dir(g->p, *s);
			if (!sp_in_fov(g->p, *s))
				s->dist = -1;
			else
				s->dist = sprite_dist(&g->p, s);
		}
	}
	sort_sprite(g->sp, g->sp_num);
	i = 0;
	while (i < g->sp_num && g->sp[i].dist >= 0)
		put_sprite_to_img(g->sp[i++], *g);
}
