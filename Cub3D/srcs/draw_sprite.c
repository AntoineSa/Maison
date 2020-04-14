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
#include <stdio.h>

int	skip_pix(t_img t, int j, int i)
{
	if (get_txt_color(t, j * t.x_txt, i * t.y_txt) == 0)
		return (1);
	return (0);
}

int	set_xscreen(t_game g, t_img *t, t_sprite sp)
{
	int	x_screen;
	
	t->x_txt = t->x / (BLOCK_SIZE / sp.dist * g.s_dist);
	x_screen = g.set.res_x / 2;
	x_screen += (sp.dir - g.p.dir) / (g.p.fov / 2) * (g.set.res_x / 2);
	x_screen -= (t->x / t->x_txt) / 2;
	return (x_screen);
}

int	set_yscreen(t_game g, t_img *t, t_sprite sp)
{
	int	y_screen;
	
	t->y_txt = t->y / (BLOCK_SIZE / sp.dist * g.s_dist);
	y_screen = g.set.res_y / 2;
	y_screen -= (t->y / t->y_txt) / 2;
	return (y_screen);
}

void	put_sprite_to_img(t_sprite sp, t_game g)
{
	t_img	t;
	int		i;
	int		j;
	int		x_screen;
	int		y_screen;

	t = g.txt[4];
	j = ((x_screen = set_xscreen(g, &t, sp)) < 0) ? -x_screen : 0;
	i = ((y_screen = set_yscreen(g, &t, sp)) < 0) ? -y_screen : 0;
	while (j * t.x_txt < t.x && j + x_screen < g.set.res_x)//opti switch from line to column
	{
		while (i * t.y_txt < t.y && i + y_screen < g.set.res_y)
		{
			g.img.index = (i + y_screen) * g.img.size_l + x_screen + j;
			if (!(skip_pix(t, j, i)) && g.z_buff[j + x_screen] > sp.dist)
				g.img.d_ptr[g.img.index] = get_txt_color(t, j * t.x_txt, i * t.y_txt);
			i++;
		}
		j++;
		i = (y_screen < 0) ? -y_screen : 0;
	}
}

static float	sprite_dist(t_player p, t_sprite sp)
{
	float r;

	r  = sqrt(pow(p.x - sp.x, 2) + pow(p.y - sp.y, 2));
	return (cos(p.dir - sp.dir) * r);
}

static int		is_in_fov(t_player p, t_sprite sp)
{
	double	left;
	double	right;

	left = sp.dir - atan(sp.dist / (sp.x / 2));//waiting for test
	right = sp.dir + atan(sp.dist / (sp.x / 2));//waiting for test
	if (right > p.dir - M_PI / 6 && left < p.dir + M_PI / 6)
		return (1);
	return (0);
}

static double	sprite_dir(t_player p, t_sprite sp)
{
	float x;
	float y;
	double	res;

	x = sp.x - p.x;
	y = sp.y - p.y;
	if (x == 0)
		return (y >= 0 ? M_PI_2 : 3 * M_PI_2);
	else if (y == 0)
		return (x >= 0 ? 0 : M_PI);
	res = atan2(y, x);
	reset_dir(&res);
	return (res);
}

void	draw_sprite(t_game g)
{
	int i;

	i = 0;
	while (i < g.sp_num)
	{
		g.sp[i].dist = sprite_dist(g.p, g.sp[i]);
		g.sp[i].dir = sprite_dir(g.p, g.sp[i]);
		if (!is_in_fov(g.p, g.sp[i]))
			g.sp[i].dist = -1;
		i++;
	}
	sort_sprite(g.sp, g.sp_num);
	i = 0;
	while (i < g.sp_num && g.sp[i].dist >= 0)
		put_sprite_to_img(g.sp[i++], g);
}
