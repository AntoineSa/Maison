/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:19:34 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/25 12:09:51 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count <= 0 || size <= 0)
	{
		count = 1;
		size = 1;
	}
	if (!(mem = malloc(count * size)))
		return (NULL);
	ft_bzero(mem, (count * size));
	return (mem);
}

void	*ft_realloc(void *ptr, size_t count, size_t size)
{
	void	*mem;

	if (count <= 0 || size <= 0)
	{
		count = 1;
		size = 1;
	}
	if (!(mem = malloc(count * size)))
		return (NULL);
	if (ptr)
		free(ptr);
	return (mem);
}
