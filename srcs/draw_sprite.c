/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:16:53 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/06 12:57:41 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cube.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	put_sprite_to_img(t_sprite sp, t_game g)
{
	t_img	t;
	int		i;
	int		j;
	int		x_screen;
	int		x_txt;
	int		y_screen;
	int		y_txt;

	j = 0;
	t = g.txt[4];
	x_screen = g.set.res_x / 2 + ((sp.dir - g.p.dir) / (M_PI / 6)) * g.set.res_x / 2;
	x_screen -= t.x / 2;
	y_txt = t.y / (BLOCK_SIZE / sp.dist * 277);
	y_screen = g.set.res_y / 2 - y_txt;
	x_txt = t.x / (BLOCK_SIZE / sp.dist * 277);
	printf("before while\n\nt.x = %d\tx_screen = %d\tx_txt = %d\n", t.x, x_screen, x_txt);
	printf("\n\nt.y = %d\ty_screen = %d\ty_txt = %d\n", t.y, y_screen, y_txt);
	while (j * x_txt < t.x && j + x_screen < g.set.res_y)
	{
		i = 0;
		while (i * y_txt < t.y && i + y_screen < g.set.res_y)
		{
			g.img.d_ptr[(i + y_screen) * (g.img.size_l / 4) +  x_screen + j] = get_txt_color(t, j * x_txt, i * y_txt);
			i++;
		}
		j++;
	}
}

int		is_in_fov(t_player p, t_sprite sp, t_game *g)
{
	printf("fov : %f -- %f\n", p.dir - M_PI / 6, p.dir + M_PI / 6);
	if (sp.dir > p.dir - M_PI / 6 && sp.dir < p.dir + M_PI / 6)
		if (get_dist(*g, sp.dir, &g->r) > sp.dist)
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
	res = atan(x / y);//here
	if (res < 0)
		res += (2 * M_PI);
	else if (res > 2 * M_PI)
		res -= (2 * M_PI);
	return (res);
}

static float	sprite_dist(t_player p, t_sprite sp)
{
	float r;

	printf("in dist p.x = %f\t sp.x = %f\n", p.x, sp.x);
	r  = sqrt(pow(p.x - sp.x, 2) + pow(p.y - sp.y, 2));
	return (r);
}

void	draw_sprite(t_game g)
{
	int i;

	i = 0;
	while (i < g.sp_num)
	{
		g.sp[i].dir = sprite_dir(g.p, g.sp[i]);
		printf("\nsp.x : %f\tsp.y %f\tsp.dir %f\n", g.sp[i].x, g.sp[i].y, g.sp[i].dir);
		printf("p.x : %f\tp.y %f\tp.dir %f\n", g.p.x, g.p.y, g.p.dir);
		if (is_in_fov(g.p, g.sp[i], &g))
		{
			g.sp[i].dist = sprite_dist(g.p, g.sp[i]);
			printf("in fov at %f\n", g.sp[i].dist);
		}
		else
		{
			g.sp[i].dist = -1;
			printf("not in fov\n");
		}
		i++;
	}
	sort_sprite(g.sp, g.sp_num);
	printf("sprite[0].dist : %f\n", g.sp[0].dist);
//	printf("sprite[1].dist : %f\n", g.sp[1].dist);
	i = 0;
	while (i < g.sp_num && g.sp[i].dist >= 0)
		put_sprite_to_img(g.sp[i++], g);
}
