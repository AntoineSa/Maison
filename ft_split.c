/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:00:21 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/11 18:01:18 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s == c && *s != '\0')
		s++;
	if (*s != '\0')
			count++;
	while (*s != '\0')
	{
		s++;
		if (*s == c)
			count++;
	}
	return (count);
}

int	ft_wrdlen(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	printf("wrd len : %d\n", len);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char **tab;
	int count;
	int i;

	count = ft_count(s, c);
	printf("count : %d\n", count);
	i = 0;
	if(!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if(!(tab[i] = (char*)malloc(sizeof(char) * ft_wrdlen(s, c))))
			return (NULL);
		while (*s != c && *s != '\0')
		{
			*tab[i] = *s;
			s++;
		}
		printf("done righting word %c\n", tab[0][ft_wrdlen(tab[0], c) - 1]);
	}
	printf("\ndone first tab\n\n");
	tab[count] = NULL;
	printf("\ndone with the NULL\n\n");

	return(tab);
}
