/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:24 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/09 17:23:49 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_d;
	char	*str_s;

	str_d = (char *)dst;
	str_s = (char *)src;
	if (str_d > str_s)
	{
		while (len > 0)
		{
			len--;
			str_d[len] = str_s[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*str_d = *str_s;
			str_d++;
			str_s++;
			len--;
		}
	}
	return (dst);
}
