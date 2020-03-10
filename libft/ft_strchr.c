/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:56:43 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 12:42:33 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c && *s != '\0')
		s++;
	if (c != '\0' && *s == '\0')
		return (NULL);
	else
		return ((char *)s);
}

char	*ft_strnchr(const char *s, int c, int n)
{
	if (!s)
		return (NULL);
	while (*s != c && *s != '\0' && n--)
		s++;
	if (c != '\0' && *s == '\0')
		return (NULL);
	else
		return ((char *)s);
}
