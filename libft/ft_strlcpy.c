/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:09:01 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/14 17:17:56 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (dstsize - 1 > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize >= 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
