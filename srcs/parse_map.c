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
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	in_set(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}

int	check_ends(char *s)
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
		while (str[i] && in_set(str[i], "012NESW"))
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
	printf("x : %d\n", x);
	while (map[i])
	{
		printf("1yo %d\n", i);
		while (x < width[i] && map[i][x] == ' ')
			i++;
		printf("2yo %d\n", i);
		if (map[i] && map[i][x] && map[i][x] != '1')
		{
			printf("map[i][x] : %d\n", (int)map[i][x]);
			return (1);
		}
		printf("3yo %d\n", i);
		while (map[i] && in_set(map[i][x], "012NSEW"))
			i++;
		printf("4yo %d\n", i);
		if (map[i] && map[i][x] != ' ')
			return (1);
		else if (map[i] && (map[i][x] == ' ' && map[i - 1][x] != '1'))
			return (1);
		printf("5yo %d\n", i);
	}
	return (0);
}

int	check_map(char **map, int *map_x, int *map_y)
{
	int		i;
	int		length;
	int		width;
	int		*tmp;

	i = 0;
	length = 0;
	width = 0;
	while (map[length])
		length++;
	printf("length : %d\nmap[0] : %s\nmap[length - 1] %s\n", length, map[0], map[length - 1]);
	if (check_ends(map[0]) || check_ends(map[length - 1]))
		return (7);
	if (!(tmp = (int *)malloc(sizeof(int) * length)))
		return (1);
	while (i < length)
	{
		if (check_map_line(map[i], &tmp[i]))
			return (8);
		if (tmp[i++] > width)
			width = tmp[i - 1];
	}
	i = 0;
	while (i < width)
	{
		printf("before check\n");
		if (check_map_col(map, tmp, i++))
			return (9);
		printf("after check\n");
	}
//	format_char_map(map);
//	format_width_map(map, width);
	*map_x = width;
	*map_y = length;
	return (0);
}
