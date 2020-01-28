/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:13:47 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/28 15:04:56 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

int		game_loop(t_game *game)
{
	if (game->press.w)
		move_front(&game->p, game->set);
	if (game->press.d)
		move_right(&game->p, game->set);
	if (game->press.s)
		move_back(&game->p, game->set);
	if (game->press.a)
		move_left(&game->p, game->set);
	if (game->press.right)
		look_right(&game->p);
	if (game->press.left)
		look_left(&game->p);
	reset_dir(&game->p.dir);
	raycast(*game);
//	draw_map(*game);
	return (0);
}

int	check_ext(char *str)//absolutely not finished
{
	char	*c;

	c = ft_strrchr(str, '\0');
	c--;
	while (*c == ' ')
		c--;
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2 || check_ext(av[1]) == 0)
	{
	//	clean_exit(1, game);
		return (0);
	}
	get_settings(&game.set, open(av[1], O_RDONLY));
	if (parse(&game.set))
	{
	//	clean_exit(error, game);
		return (0);
	}
	init_player(&game.p, game.set);
	game.img.x = game.set.res_x;
	game.img.y = game.set.res_y;
	init_img(&game.img, &game);
	printf("game.player pos : %f, %f\n", game.p.x, game.p.y);
	mlx_loop(game.img.mlx_ptr);
	return (0);
}
