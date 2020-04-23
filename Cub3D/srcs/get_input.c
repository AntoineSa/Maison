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
#include <mlx.h>

static int	key_press(int key, t_input *press)
{
	if (key == 13)
		press->w = 1;
	if (key == 2)
		press->d = 1;
	if (key == 1)
		press->s = 1;
	if (key == 0)
		press->a = 1;
	if (key == 124)
		press->right = 1;
	if (key == 123)
		press->left = 1;
	if (key == 257)
		press->run = 1;
	if (key == 49)
		press->aim = 1;
	return (0);
}

static int	key_release(int key, t_input *press)
{
	if (key == 13)
		press->w = 0;
	if (key == 2)
		press->d = 0;
	if (key == 1)
		press->s = 0;
	if (key == 0)
		press->a = 0;
	if (key == 124)
		press->right = 0;
	if (key == 123)
		press->left = 0;
	if (key < 0 || key == 53)
		press->pause = press->pause == 1 ? 0 : 1;
	if (key == 257)
		press->run = 0;
	if (key == 49)
		press->aim = 0;
	return (0);
}

static int exit_game(t_input *press)
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
	press->run = 0;
	press->aim = 0;
}

void	set_hooks(t_game *g)
{
	init_press(&g->press);
	mlx_hook(g->win_ptr, 2, 0, &key_press, &g->press);
	mlx_hook(g->win_ptr, 3, 0, &key_release, &g->press);
	mlx_hook(g->win_ptr, 17, 0, &exit_game, &g->press);
	mlx_loop_hook(g->mlx_ptr, &game_loop, g);
}
