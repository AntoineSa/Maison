/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:14:38 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 11:53:07 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "def.h"
#include <mlx.h>
#include <X11/Xlib.h>

static int	key_press(int key, t_input *press)
{
	if (key == MV_F)
		press->w = 1;
	if (key == MV_R)
		press->d = 1;
	if (key == MV_B)
		press->s = 1;
	if (key == MV_L)
		press->a = 1;
	if (key == LOOK_R)
		press->right = 1;
	if (key == LOOK_L)
		press->left = 1;
	return (0);
}

static int	key_release(int key, t_input *press)
{
	if (key == MV_F)
		press->w = 0;
	if (key == MV_R)
		press->d = 0;
	if (key == MV_B)
		press->s = 0;
	if (key == MV_L)
		press->a = 0;
	if (key == LOOK_R)
		press->right = 0;
	if (key == LOOK_L)
		press->left = 0;
	if (key < 0 || key == ESC)
		press->pause = press->pause == 1 ? 0 : 1;
	return (0);
}

static int	exit_game(t_input *press)
{
	press->pause = press->pause == 1 ? 0 : 1;
	return (0);
}

static void	init_press(t_input *press)
{
	press->w = 0;
	press->d = 0;
	press->s = 0;
	press->a = 0;
	press->right = 0;
	press->left = 0;
	press->pause = 0;
}

void		set_hooks(t_game *g)
{
	init_press(&g->press);
	mlx_hook(g->win_ptr, KeyPress, KeyPressMask, &key_press, &g->press);
	mlx_hook(g->win_ptr, KeyRelease, KeyReleaseMask, &key_release, &g->press);
	mlx_hook(g->win_ptr, 17, 0, &exit_game, &g->press);
	mlx_loop_hook(g->mlx_ptr, &game_loop, g);
}
