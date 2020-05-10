/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:23:21 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 10:43:10 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "cube.h"

static void	init_img(t_img *i, t_game *g)
{
	int		x;
	int		y;
	void	*p;

	g->mlx_ptr = mlx_init();
	mlx_get_screen_size(g->mlx_ptr, &x, &y);
	if (g->set.res_x > x)
		g->set.res_x = x;
	else
		x = g->set.res_x;
	if (g->set.res_y > y)
		g->set.res_y = y;
	else
		y = g->set.res_y;
	g->win_ptr = mlx_new_window(g->mlx_ptr, x, y, "Cub3D");
	i->ptr = mlx_new_image(g->mlx_ptr, x, y);
	p = i->ptr;
	i->d_ptr = (int *)mlx_get_data_addr(p, &i->bpp, &i->size_l, &i->endian);
	i->size_l /= 4;
	set_hooks(g);
}

void		load_txt(t_img *t, t_game g, char *path)
{
	int	*p;

	t->ptr = mlx_xpm_file_to_image(g.mlx_ptr, path, &t->x, &t->y);
	p = (int *)mlx_get_data_addr(t->ptr, &t->bpp, &t->size_l, &t->endian);
	t->d_ptr = p;
	t->size_l /= 4;
}

static void	init_text(t_game *g)
{
	load_txt(&(g->txt[0]), *g, g->set.t_n);
	load_txt(&(g->txt[1]), *g, g->set.t_e);
	load_txt(&(g->txt[2]), *g, g->set.t_s);
	load_txt(&(g->txt[3]), *g, g->set.t_w);
	load_txt(&(g->txt[4]), *g, g->set.t_sp);
	load_txt(&(g->txt[5]), *g, "./textures/sniper.xpm");
	load_txt(&(g->txt[6]), *g, "./textures/sniper_aim.xpm");
	load_txt(&(g->txt[7]), *g, "./textures/red_cross.xpm");
	load_txt(&(g->txt[8]), *g, "./textures/blue_light.xpm");
	load_txt(&(g->txt[9]), *g, "./textures/dead_screen.xpm");
}

void		init_game(t_game *g)
{
	init_player(g);
	init_img(&(g->img), g);
	init_text(g);
	init_sprite(g, g->set);
	init_hud(g);
	g->z_buff = (float *)malloc(sizeof(float) * g->set.res_x);
	g->s_dist = (g->set.res_x / 2) / tan(g->p.fov / 2);
}
