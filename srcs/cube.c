/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:13:47 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/16 12:35:33 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

int		game_loop(t_game *game)
{
	if (!game->press.pause)
	{
		if (game->press.w)
			move_front(&game->p, *game);
		if (game->press.d)
			move_right(&game->p, *game);
		if (game->press.s)
			move_back(&game->p, *game);
		if (game->press.a)
			move_left(&game->p, *game);
		if (game->press.right)
			look_right(&game->p);
		if (game->press.left)
			look_left(&game->p);
		reset_dir(&game->p.dir);
		printf(">>\n");
		raycast(*game);
		printf(">>\n");
		draw_window(game->img);
	}
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
		clean_exit(1, &game);
	get_settings(&game.set, open(av[1], O_RDONLY));
	if (parse(&game.set))
		clean_exit(3, &game);
	init_player(&game);
	game.set.map[(int)game.p.y][(int)game.p.x] = '0';
	game.img.x = game.set.res_x;
	game.img.y = game.set.res_y;
	init_img(&game.img, &game);
	if (ac == 3 && !ft_strncmp(av[2], "-save", ft_strlen(av[2])))
	{
		game.img.win_ptr = NULL;
		raycast(game);
		screenshot(game.img);
		return (0);
	}
	mlx_loop(game.img.mlx_ptr);
	return (0);
}
