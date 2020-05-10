/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:13:47 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 12:04:01 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include "cube.h"
#include "def.h"
#include "libft.h"

static void	play(t_game *game)
{
	if (game->press.w)
		move_front(&game->p, game);
	if (game->press.d)
		move_right(&game->p, game);
	if (game->press.s)
		move_back(&game->p, game);
	if (game->press.a)
		move_left(&game->p, game);
	if (game->press.right)
		look_right(&game->p, 0);
	if (game->press.left)
		look_left(&game->p, 0);
	raycast(*game);
}

int			game_loop(t_game *game)
{
	if (game->press.pause)
		clean_exit(0, game);
	else
		play(game);
	draw_window(game);
	return (0);
}

int			check_ext(char *str)
{
	char	*c;

	c = ft_strrchr(str, '\0');
	c--;
	while (*c == ' ')
		c--;
	if (*c == 'b' && *(c - 1) == 'u' && *(c - 2) == 'c' && *(c - 3) == '.')
	{
		if (check_file(str))
			return (INV_CUB);
		else
			return (0);
	}
	return (NOT_CUB);
}

int			main(int ac, char **av)
{
	t_game	game;
	int		err;

	if (ac < 2)
		clean_exit(NO_ARG, &game);
	else if ((err = check_ext(av[1])))
		clean_exit(err, &game);
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
	}
	mlx_loop(game.mlx_ptr);
	return (0);
}
