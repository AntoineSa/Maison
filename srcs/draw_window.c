/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:39:25 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/23 12:44:22 by asablayr         ###   ########.fr       */
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
	int		j;
	float	rel_x;

	i = 0;
	t = select_text(g);
	y_txt = t.y / wall_h;
	rel_x = g.r.side == 1 ? g.r.h_x - (int)g.r.h_x : g.r.v_y - (int)g.r.v_y;
	while (i < wall_h && i + y < g.set.res_y)
	{
		j = x + (i + y) * (g.img.size_l / 4);
		g.img.d_ptr[j] = get_txt_color(t, rel_x * t.x, i * y_txt);
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
//	if (wall_h > g.set.res_y)
//		wall_h = g.set.res_y;
	c = (g.img.y - wall_h) / 2;
	i = 0;
	while (i < c)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
	draw_wall(g, wall_h, x, i);
	i += wall_h;
	while (i < g.set.res_y)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_f;
}

void	draw_window(t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.ptr, 0, 0);
}
