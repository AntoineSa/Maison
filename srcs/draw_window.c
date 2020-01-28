/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:39:25 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/28 16:11:06 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"

void	draw_column(t_game g, double d, int x)
{
	double	wall_h;
	double	c;
	int		i;
	int		s_dist;

	s_dist = 260; //(g.set.res_x / 2) / tan(g.p.fov / 2);
//	printf("break 1.2, s_dist = %d\n", s_dist);
	wall_h =  BLOCK_SIZE / d * s_dist;//BLOCK_SIZE * s_dist / d;
//	printf("break 1.3, wall_h : %f\n", wall_h);
	c = (g.img.y - wall_h) / 2 >= 0 ? (g.img.y - wall_h) / 2 : 0;
//	printf("break 1.4, c = %f\n", c);
	i = 0;
	while (i < c)
		g.img.data_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
	while (i < g.set.res_y && i < wall_h + c)
		g.img.data_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_f;
	while (i < g.set.res_y)
		g.img.data_ptr[i++ * (g.img.size_l / 4) + x] = g.set.c_c;
}

void	draw_square(t_img img, int c, int x, int y)
{
	int	i;
	int	j;

	j = y;
	printf("c : %d\n", c);
	while (j < y + BLOCK_MAP)
	{
		i = x;
		while (i < x + BLOCK_MAP)
			img.data_ptr[(j + y) * (img.size_l / 4) + x + i++] = c;
		j++;
	}
}

void	draw_window(t_img i)
{
	mlx_put_image_to_window(i.mlx_ptr, i.win_ptr, i.img_ptr, 0, 0);
}
