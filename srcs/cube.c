/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:13:47 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/09 13:31:32 by asablayr         ###   ########.fr       */
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
		raycast(*game);
		draw_window(game);
	}
	return (0);
}

int	check_ext(char *str)
{
	char	*c;

	c = ft_strrchr(str, '\0');
	c--;
	while (*c == ' ')
		c--;
	if (*c == 'b' && *(c - 1) == 'u' && *(c - 2) == 'c' && *(c - 3) == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		err;

	if (ac < 2)
		clean_exit(1, &game);
	else if (check_ext(av[1]) == 0)
		clean_exit(2, &game);
	get_settings(&game.set, open(av[1], O_RDONLY));
	err = parse(&game.set);
	(err == 0) ? init_game(&game) : clean_exit(err, &game);
	game.set.map[(int)game.p.y][(int)game.p.x] = '0';
	game.img.x = game.set.res_x;
	game.img.y = game.set.res_y;
	if (ac == 3 && !ft_strncmp(av[2], "--save", 6))
	{
		raycast(game);
		screenshot(game.img);
		return (0);
	}
	mlx_loop(game.mlx_ptr);
	return (0);
}
