/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:53:06 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/11 13:50:30 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

const char	*ft_trimstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0' && *s1 != '\0')
	{
		if (set[i] == *s1)
		{
			s1++;
			i = 0;
		}
		else
			i++;
	}
	return (s1);
}

char	*ft_trimend(char const *s1, char const *set)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	j -= 1;
	while (set[i] != '\0' && j > 0)
	{
		if (set[i] == s1[j])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return ((char *)&s1[j + 1]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *str;
	char *end;
	int len;

	s1 = ft_trimstart(s1, set);
	end = ft_trimend(s1, set);
	len = end - s1;
	if(!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (s1 != end)
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (str - len);
}
