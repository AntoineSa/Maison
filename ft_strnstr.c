/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:44:52 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/10 10:47:28 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		if (*haystack != *needle)
			haystack++;
		while (haystack[i] == needle[i] && needle[i] != '\0' && len - i > 0)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		len--;
	}
	return (NULL);
}
