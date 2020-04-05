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

void	put_sprite_to_img(t_sprite sp, t_game g)
{
	t_img	t;
	int		i;
	int		j;
	int		x_screen;
	int		y_screen;
	int		s_dist;

	s_dist = (g.set.res_x / 2) / tan(g.p.fov / 2);
	j = 0;
	t = g.txt[4];
	x_screen = g.set.res_x / 2 + ((sp.dir - g.p.dir) / (g.p.fov / 2)) * (g.set.res_x / 2);
	t.y_txt = t.y / (BLOCK_SIZE / sp.dist * s_dist);
	y_screen = g.set.res_y / 2;
	t.x_txt = t.x / (BLOCK_SIZE / sp.dist * s_dist);
	x_screen -= (t.x / t.x_txt) / 2;
	y_screen -= (t.y / t.y_txt) / 2;
//	printf("\n\ng.set.x = %d\tt.x = %d\tx_screen = %d\tx_txt = %f\n", g.set.res_x, t.x, x_screen, x_txt);
//	printf("g.set.y = %d\tt.y = %d\ty_screen = %d\ty_txt = %f\n", g.set.res_y, t.y, y_screen, y_txt);
	i = 0;
	if (x_screen < 0)
		j = -x_screen;
	if (y_screen < 0)
		i = -y_screen;
//	printf("before while\n");
	while (j * t.x_txt < t.x && j + x_screen < g.set.res_x)//opti switch from line to column
	{
		i = 0;
		while (i * t.y_txt < t.y && i + y_screen < g.set.res_y)
		{
			if (get_txt_color(t, j * t.x_txt, i * t.y_txt) != 0xff000000 && g.z_buff[j + x_screen] > sp.dist)
				g.img.d_ptr[(i + y_screen) * (g.img.size_l / 4) +  x_screen + j] = get_txt_color(t, j * t.x_txt, i * t.y_txt);
			i++;
		}
		j++;
	}
}

static float	sprite_dist(t_player p, t_sprite sp)
{
	float r;

	r  = sqrt(pow(p.x - sp.x, 2) + pow(p.y - sp.y, 2));
	return (r);
}

int		is_in_fov(t_player p, t_sprite sp, t_game *g)
{
	if (sp.dir > p.dir - M_PI / 6 && sp.dir < p.dir + M_PI / 6)
		if (get_dist(*g, sp.dir, &g->r) > sprite_dist(p, sp))
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
		g.sp[i].dir = sprite_dir(g.p, g.sp[i]);
//		printf("p.dir : %f - %f\tsp.dir : %f\n", g.p.dir-g.p.fov/2, g.p.dir+g.p.fov/2, g.sp[i].dir);

		if (is_in_fov(g.p, g.sp[i], &g))
		{
//			printf("sp[%i] in fov\n", i);
			g.sp[i].dist = sprite_dist(g.p, g.sp[i]);
		}
		else
			g.sp[i].dist = -1;
		i++;
	}
	sort_sprite(g.sp, g.sp_num);
	i = 0;
	while (i < g.sp_num && g.sp[i].dist >= 0)
		put_sprite_to_img(g.sp[i++], g);
}
