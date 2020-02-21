/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:23:21 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/21 12:06:30 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cube.h"
#include <stdio.h>

static void	init_img(t_img *img, t_game *g)
{
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, img->x, img->y, "Cub3D");
	img->ptr = mlx_new_image(g->mlx_ptr, img->x, img->y);
	img->d_ptr = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian);
	mlx_do_key_autorepeatoff(g->mlx_ptr);
	set_hooks(g->mlx_ptr, g->win_ptr, g);
}

static void	load_txt(t_img *t, t_game g, char *path)
{
	
	t->ptr = mlx_new_image(g.mlx_ptr, t->x, t->y);
	t->d_ptr = mlx_xpm_file_to_image(g.mlx_ptr, path, &t->x, &t->y);
}

static void	init_text(t_game *g)
{
	int	i;

	i = 0;
	load_txt(&(g->txt[0]), *g, g->set.t_n);
	load_txt(&(g->txt[1]), *g, g->set.t_e);
	load_txt(&(g->txt[2]), *g, g->set.t_s);
	load_txt(&(g->txt[3]), *g, g->set.t_w);
}

void	init_game(t_game *g)
{
	init_player(g);
	init_img(&(g->img), g);
	init_text(g);
}
