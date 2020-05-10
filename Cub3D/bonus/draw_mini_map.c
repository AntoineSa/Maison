/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:43:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 09:56:55 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

float		scale_up_map(float s, int x, int y)
{
	if (x < y)
		return ((float)BLOCK_SIZE * (s / y));
	else
		return ((float)BLOCK_SIZE * (s / x));
}

float		scale_down_map(float s, int x, int y)
{
	if (x < y)
		return (s * (s / y));
	else
		return (s * (x / s));
}

static void	draw_player(t_img i, int x, int y)
{
	int	k;
	int	j;
	int	c;

	j = 0;
	c = 55260;
	while (j < i.index)
	{
		k = 0;
		while (k < i.index)
			i.d_ptr[(j + y) * i.size_l + x + k++] = c;
		j++;
	}
}

static void	draw_fov(t_game g, float s)
{
	double	dir;
	double	i;
	int		j;

	dir = g.p.dir - g.p.fov / 2;
	i = g.p.fov / g.set.res_x;
	j = 0;
	g.p.x *= s;
	g.p.x += s / 4;
	g.p.y *= s;
	g.p.y += s / 4;
	while (dir <= g.p.dir + g.p.fov / 2)
	{
		if (!(g.press.aim))
			draw_ray(g.img, g.p, dir, s * g.z_buff[j++]);
		else
			draw_ray(g.img, g.p, dir, 2 * s * g.z_buff[j++]);
		dir += i;
	}
}

void		draw_map(t_game *g)
{
	int		x;
	int		y;
	float	s;

	y = 0;
	s = (g->img.x > g->img.y) ? g->img.y / 4 : g->img.x / 4;
	if (g->set.map_y > s || g->set.map_x > s)
		s = scale_down_map(s, g->set.map_x, g->set.map_y);
	else if (g->set.map_y < s || g->set.map_x < s)
		s = scale_up_map(s, g->set.map_x, g->set.map_y);
	g->img.index = s;
	while (y < g->set.map_y && !(x = 0))
	{
		while (g->set.map[y][x] && x < g->set.map_x)
		{
			if (g->set.map[y][x] == '0')
				draw_square(g->img, 0, x * s, y * s);
			else if (g->set.map[y][x] == '1')
				draw_square(g->img, 12020, x * s, y * s);
			x++;
		}
		y++;
	}
	draw_fov(*g, s);
	draw_player(g->img, g->p.x * s, g->p.y * s);
}
