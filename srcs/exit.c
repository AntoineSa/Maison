/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:11:43 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/12 18:30:00 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdlib.h>

static void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
}

static char	**init_err_msg(void)
{
	char	**msg;

	msg = NULL;
	msg[0] = NULL; //segfault
	msg[1] = "No .cub file.";
	msg[2] = "Wrong texture path.";
	msg[3] = "Invalid map.";
	msg[4] = "No player starting point.";
	return (msg);
}


int 		clean_exit(int err, t_game *game)
{
	char	**msg;

	msg = init_err_msg();
	ft_putstr_fd("Error\n", 1);
	if (err >= 1)
	{
		map_free(game->set.map);
		ft_putstr_fd(msg[err], 1);
		return (0);
	}
	return (0);
}
