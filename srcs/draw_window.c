/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:39:25 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/08 16:33:49 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"

char	*select_color(t_game g)
{
	if (g.r.side == 1)
		return (g.r.d > M_PI ? g.set.t_n : g.set.t_s);
	else
		return (g.r.d > M_PI_2 && g.r.d < 3 * M_PI_2 ? g.set.t_w : g.set.t_e);
}

void	draw_column(t_game g, double d, int x)
{
	double	wall_h;
	double	c;
	int		i;
	int		s_dist;

	s_dist = 260; //(g.set.res_x / 2) / tan(g.p.fov / 2);
	wall_h =  BLOCK_SIZE / d * s_dist;//BLOCK_SIZE * s_dist / d;
	c = (g.img.y - wall_h) / 2 >= 0 ? (g.img.y - wall_h) / 2 : 0;
	i = 0;
	while (i < c)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
	while (i < g.set.res_y && i < wall_h + c)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = (g.r.side == 0) ? g.set.c_f : g.set.c_f + 300;
	while (i < g.set.res_y)
		g.img.d_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
}

void	draw_line(t_img i, t_player p, double dir, int d)
{
	p.x *= 10;
	p.y *= 10;
	while (d--)
	{
		p.x += cos(dir);
		p.y += sin(dir);
		i.d_ptr[(int)(p.y) * (i.size_l / 4) + (int)(p.x)] = 0xffffff;
	}
}

void	draw_square(t_img img, int c, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < BLOCK_MAP)
	{
		i = 0;
		while (i < BLOCK_MAP)
			img.d_ptr[(j + y) * (img.size_l / 4) + x + i++] = c;
		j++;
	}
}

void	draw_player(t_img i, int c, int x, int y)
{
	int	k;
	int	j;

	j = 0;
	while (j < BLOCK_MAP / 2)
	{
		k = 0;
		while (k < BLOCK_MAP / 2)
			i.d_ptr[(j + y) * (i.size_l / 4) + x + k++] = c;
		j++;
	}
}

void	draw_window(t_img i)
{
	mlx_put_image_to_window(i.mlx_ptr, i.win_ptr, i.img_ptr, 0, 0);
}
