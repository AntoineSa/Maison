/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:20:16 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/12 20:12:52 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "def.h"
#include "libft.h"
#include <stdlib.h>

int			in_set(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}

static int	check_ends(char *s)
{
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != '1' && *s != '\0')
			return (1);
		while (*s == '1')
			s++;
		if (*s != ' ' && *s != '\0')
			return (1);
	}
	return (0);
}

static int	check_map_line(char *str, int *width)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1' && str[i] != '\0')
			return (1);
		while (str[i] && in_set(str[i], CHARSET))
			i++;
		if (str[i] != ' ' && str[i] != '\0')
		{
			return (1);
		}
		else if (str[i] == ' ' && str[i - 1] != '1')
			return (1);
	}
	*width = i;
	return (0);
}

static int	check_map_col(char **map, int *width, int x)
{
	int i;

	i = 0;
	while (map[i])
	{
		while (x > width[i] - 1)
			i++;
		while (map[i] && x < width[i] && map[i][x] == ' ')
			i++;
		if (map[i] && map[i][x] && map[i][x] != '1')
			return (1);
		while (map[i] && in_set(map[i][x], CHARSET))
			i++;
		if (map[i] && (map[i][x] != ' ' && map[i][x]))
			return (1);
		else if (map[i] && (map[i][x] == ' ' && map[i - 1][x] != '1'))
			return (1);
	}
	return (0);
}

int			check_map(char **map, int *map_x, int *map_y)
{
	int		i;
	int		*tmp;

	i = 0;
	*map_x = 0;
	*map_y = 0;
	while (map[*map_y])
		(*map_y)++;
	if (check_ends(map[0]) || check_ends(map[*map_y - 1]))
		return (INV_MAP);
	if (!(tmp = (int *)malloc(sizeof(int) * *map_y)))
		return (INV_MAP);
	while (i < *map_y)
	{
		if (check_map_line(map[i], &tmp[i]))
			return (INV_MAP);
		if (tmp[i++] > *map_x)
			*map_x = tmp[i - 1];
	}
	i = 0;
	while (i < *map_x)
		if (check_map_col(map, tmp, i++))
			return (INV_MAP);
	free(tmp);
	return (0);
}
