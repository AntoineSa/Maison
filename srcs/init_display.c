/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:23:21 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/08 20:33:19 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cube.h"
#include <stdio.h>

void	init_img(t_img *img, t_game *g)
{
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->x, img->y, "Cub3D");
	img->img_ptr = mlx_new_image(img->mlx_ptr, img->x, img->y);
	img->d_ptr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	mlx_do_key_autorepeatoff(img->mlx_ptr);
	set_hooks(img->mlx_ptr, img->win_ptr, g);
}
