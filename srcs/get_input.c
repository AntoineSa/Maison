/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:14:38 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/21 14:48:46 by asablayr         ###   ########.fr       */
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
	if (key == 53)
//		clean_exit(0, game); exit not ready
		return (0);
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
}

void	set_hooks(void *mlx_ptr, void *win_ptr, t_game *g)
{
	init_press(&g->press);
	mlx_loop_hook(mlx_ptr, &game_loop, g);
	mlx_hook(win_ptr, 2, 0, &key_press, &g->press);
	mlx_hook(win_ptr, 3, 0, &key_release, &g->press);
	//mlx_hook(win_ptr, 17, 0, &close_win, g->set); exit not ready
}
