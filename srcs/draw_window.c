/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:39:25 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/22 10:59:18 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"

void	draw_wall(t_game g, double wall_h, int x, int y)
{
	t_img	t;
	float	y_txt;
	int		i;

	i = 0;
	y_txt = t.y / wall_h;
	printf("t.y = %d y_text : %f", t.y, y_txt);
	while (i < wall_h)
	{
		t = select_text(g);
		g.img.d_ptr[x + (i + y) * (g.img.size_l / 4)] = get_txt_color(t, x % t.x, i * y_txt);
		i++;
	}
}

void	draw_column(t_game g, double d, int x)
{
	double	wall_h;
	double	c;
	int		i;
	int		s_dist;

	s_dist = (g.set.res_x / 2) / tan(g.p.fov / 2); //277; //(g.set.res_x / 2) / tan(g.p.fov / 2);
	wall_h = BLOCK_SIZE / d * s_dist;
	if (wall_h > g.set.res_y)
		wall_h = g.set.res_y;
//	c = (g.img.y - wall_h) / 2 >= 0 ? (g.img.y - wall_h) / 2 : 0;
	c = (g.img.y - wall_h) / 2;
	i = 0;
	while (i < c)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
	draw_wall(g, wall_h, x, i);
//	while (i < g.set.res_y && i < wall_h + c)
//		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = (g.r.side == 0) ? g.set.c_f : g.set.c_f + 300;
	while (i < g.set.res_y)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
}

void	draw_window(t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.ptr, 0, 0);
}
