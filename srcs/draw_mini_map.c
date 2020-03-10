/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:43:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:27 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

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

void	draw_fov(t_game g)
{
	double	dir;
	double	i;
	int		j;

	dir = g.p.dir - M_PI / 6;
	i = g.p.fov / g.set.res_x;
	j = 0;
	while (dir <= g.p.dir + M_PI / 6)
	{
		draw_ray(g.img, g.p, dir, 10 * g.z_buff[j++]);
		dir += i;
	}
}

void	draw_map(t_game g)
{
	int x;
	int y;
	int s;

	y = 0;
	s = BLOCK_MAP;
	while (y < g.set.map_y)
	{
		x = 0;
		while (x < g.set.map_x)
		{
			if (g.set.map[y][x] == '0')
				draw_square(g.img, 0, x * s, y * s);
			else if (g.set.map[y][x] == '1')
				draw_square(g.img, 12020, x * s, y * s);
			x++;
		}
		y++;
		draw_player(g.img, 55260, (int)(g.p.x * s), (int)(g.p.y * s));
		draw_fov(g);
	}
}
