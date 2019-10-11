/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:28:55 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/09 12:34:38 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *str_d;
	char *str_s;

	str_d = (char *)dst;
	str_s = (char *)src;
	while (n > 0)
	{
		*str_d = *str_s;
		str_d++;
		str_s++;
		n--;
	}
	return (dst);
}
