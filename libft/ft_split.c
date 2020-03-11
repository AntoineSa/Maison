/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:00:21 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 12:22:28 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s && *s == c)
		s++;
	if (*s)
		count++;
	while (*s)
	{
		s++;
		if (*s && *(s - 1) == c && *s != c)
			count++;
	}
	return (count);
}

static int	ft_wrdlen(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void	ft_rollback(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	count = ft_count(s, c);
	i = -1;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (++i < count)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (ft_wrdlen(s, c) + 1))))
		{
			ft_rollback(tab, i - 1);
			return (NULL);
		}
		while (*s != c && *s != '\0')
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
	}
	tab[count] = NULL;
	return (tab);
}
