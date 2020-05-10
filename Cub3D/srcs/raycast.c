/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:51:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/10 13:35:47 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"
#include "libft.h"

int		check_w(t_game *g, float x, float y)
{
	if (g->r.d > M_PI && g->r.d <= 2 * M_PI)
		y = (int)y - 1;
	else
		y = (int)y;
	if (g->r.d > M_PI_2 && g->r.d < 3 * M_PI_2)
		x = (int)x - 1;
	else
		x = (int)x;
	return (g->set.map[(int)y][(int)x] - '0');
}

float	get_dist(t_game *g, double d, t_ray *r)
{
	r->d = d;
	r->h = get_wall_h(g, r);
	r->v = get_wall_v(g, r);
	r->side = r->h >= r->v ? 0 : 1;
	if (!g->press.aim)
		return (r->side == 0 ? r->v : r->h);
	else
		return (r->side == 0 ? r->v / 2 : r->h / 2);
}

void	raycast(t_game g)
{
	int		j;
	double	i;
	double	d;
	float	dist;

	if (g.press.aim)
		g.p.fov /= 2;
	j = 0;
	i = g.p.fov / g.set.res_x;
	d = g.p.dir - g.p.fov / 2;
	while (j < g.set.res_x)
	{
		reset_dir(&d);
		dist = get_dist(&g, d, &g.r);
		draw_column(g, dist, j);
		g.z_buff[j++] = dist;
		d += i;
	}
	draw_sprite(&g);
}
