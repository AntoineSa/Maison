/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:28:03 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 15:20:27 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if (!(str = (char *)malloc(sizeof(str) * len + 1)))
		return (NULL);
	i = 0;
	while (*s && len > i)
	{
		str[i] = s[start];
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_subfstr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if (!(str = (char *)malloc(sizeof(str) * len + 1)))
		return (NULL);
	i = 0;
	while (*s && len > i)
		str[i++] = s[start++];
	str[i] = '\0';
	free(s);
	return (str);
}
