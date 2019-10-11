/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:34:53 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/10 16:00:05 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize < len)
		return (ft_strlen(src) + dstsize);
	while (*dst != '\0')
		dst++;
	while (dstsize - 1 - len > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
